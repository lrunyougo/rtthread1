/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-20   zmq810150896   first version
 */

#include <rtthread.h>
#include <fcntl.h>
#include <rtdevice.h>
#include <stdint.h>
#include <unistd.h>
#include <dfs_file.h>
#include "poll.h"
#include "eventfd.h"

#define EFD_SEMAPHORE (1 << 0)
#define EFD_CLOEXEC O_CLOEXEC
#define EFD_NONBLOCK O_NONBLOCK

#define EFD_SHARED_FCNTL_FLAGS (O_CLOEXEC | O_NONBLOCK)
#define EFD_FLAGS_SET (EFD_SHARED_FCNTL_FLAGS | EFD_SEMAPHORE)

#define ULLONG_MAX  (~0ULL)

#define EVENTFD_MUTEX_NAME "eventfd"

struct eventfd_ctx {
    rt_wqueue_t reader_queue;
    rt_wqueue_t writer_queue;
    rt_uint64_t count;
    unsigned int flags;
    struct rt_mutex lock;
    rt_thread_t id;
};

#ifndef RT_USING_DFS_V2
static int eventfd_close(struct dfs_file *file);
static int eventfd_poll(struct dfs_file *file, struct rt_pollreq *req);
static int eventfd_read(struct dfs_file *file, void *buf, size_t count);
static int eventfd_write(struct dfs_file *file, const void *buf, size_t count);
static int noop_lseek(struct dfs_file *file, off_t offset);
#else
static int eventfd_close(struct dfs_file *file);
static int eventfd_poll(struct dfs_file *file, struct rt_pollreq *req);
static int eventfd_read(struct dfs_file *file, void *buf, size_t count, off_t *pos);
static int eventfd_write(struct dfs_file *file, const void *buf, size_t count, off_t *pos);
static int noop_lseek(struct dfs_file *file, off_t offset, int wherece);
#endif

static const struct dfs_file_ops eventfd_fops =
{
    .close      = eventfd_close,
    .poll       = eventfd_poll,
    .read       = eventfd_read,
    .write      = eventfd_write,
    .lseek      = noop_lseek,
};

static int eventfd_close(struct dfs_file *file)
{
    struct eventfd_ctx *ctx = file->vnode->data;

    rt_mutex_detach(&ctx->lock);
    rt_free(ctx);

    return 0;
}

static int eventfd_poll(struct dfs_file *file, struct rt_pollreq *req)
{
    struct eventfd_ctx *ctx = (struct eventfd_ctx *)file->vnode->data;
    int events = 0;
    rt_ubase_t count;

    count = ctx->count;

    rt_poll_add(&ctx->reader_queue, req);
    rt_poll_add(&ctx->writer_queue, req);

    if (count > 0)
        events |= POLLIN;

    if (count == ULLONG_MAX)
        events |= POLLERR;

    if (ULLONG_MAX -1 > count)
        events |= POLLOUT;

    return events;
}

#ifndef RT_USING_DFS_V2
static int eventfd_read(struct dfs_file *file, void *buf, size_t count)
#else
static int eventfd_read(struct dfs_file *file, void *buf, size_t count, off_t *pos)
#endif
{
    struct eventfd_ctx *ctx = (struct eventfd_ctx *)file->vnode->data;
    rt_ubase_t ucnt = 0;
    rt_ubase_t *buffer = (rt_ubase_t *)buf;

    rt_mutex_take(&ctx->lock, RT_WAITING_FOREVER);

    if (ctx->count == 0)
    {
        if (file->flags & O_NONBLOCK)
        {
            rt_wqueue_wakeup(&ctx->writer_queue, (void*)POLLOUT);
            rt_mutex_release(&ctx->lock);
            return -EAGAIN;
        }
        else
        {
            /* In this case, when the data is read in blocked mode, when ctx->count is 0, the mutex needs to be released and wait for writing */
            rt_mutex_release(&ctx->lock);
            rt_wqueue_wakeup(&ctx->writer_queue, (void*)POLLOUT);
            rt_wqueue_wait(&ctx->reader_queue, 0, RT_WAITING_FOREVER);
            rt_mutex_take(&ctx->lock, RT_WAITING_FOREVER);
        }
    }

    if (ctx->flags & EFD_SEMAPHORE)
    {
        ucnt = 1;
    }
    else
    {
        ucnt = ctx->count;
    }

    ctx->count -= ucnt;

    (*buffer) = ucnt;

    rt_mutex_release(&ctx->lock);

    return sizeof(ucnt);
}

#ifndef RT_USING_DFS_V2
static int eventfd_write(struct dfs_file *file, const void *buf, size_t count)
#else
static int eventfd_write(struct dfs_file *file, const void *buf, size_t count, off_t *pos)
#endif
{
    struct eventfd_ctx *ctx = (struct eventfd_ctx *)file->vnode->data;
    rt_ssize_t res;
    /*
    ucnt: unsigned count
    Adds a value to the counter
    */
    rt_ubase_t ucnt = *(rt_ubase_t *)buf;

    if (count < sizeof(ucnt))
        return -EINVAL;

    if (ucnt == ULLONG_MAX)
        return -EINVAL;

    res = -EAGAIN;

    rt_mutex_take(&ctx->lock, RT_WAITING_FOREVER);

    if ((ULLONG_MAX - ctx->count) > ucnt)
    {
        res = sizeof(ucnt);
    }
    else if (!(file->flags & O_NONBLOCK))
    {
        for (res = 0;;)
        {
            if ((ULLONG_MAX - ctx->count) >= ucnt)
            {
                res = sizeof(ucnt);
                break;
            }
            /* Release the mutex to avoid a deadlock */
            rt_mutex_release(&ctx->lock);
            rt_wqueue_wait(&ctx->writer_queue, 0, RT_WAITING_FOREVER);
            rt_wqueue_wakeup(&ctx->reader_queue, (void *)POLLIN);
            rt_mutex_take(&ctx->lock, RT_WAITING_FOREVER);
        }
    }

    if (res > 0)
    {
        ctx->count += ucnt;
        rt_wqueue_wakeup(&ctx->reader_queue, (void *)POLLIN);
    }

    rt_mutex_release(&ctx->lock);

    return res;
}

#ifndef RT_USING_DFS_V2
static int noop_lseek(struct dfs_file *file, off_t offset)
#else
static int noop_lseek(struct dfs_file *file, off_t offset, int wherece)
#endif
{
    return 0;
}

static int rt_eventfd_create(struct dfs_file *df, unsigned int count, int flags)
{
    struct eventfd_ctx *ctx = RT_NULL;
    rt_err_t ret = 0;

    ctx = (struct eventfd_ctx *)rt_malloc(sizeof(struct eventfd_ctx));
    if (ctx == RT_NULL)
    {
        ret = -ENOMEM;
    }
    else
    {
        ctx->count = count;
        ctx->flags = flags;
        ctx->id = rt_thread_self();
        flags &= EFD_SHARED_FCNTL_FLAGS;
        flags |= O_RDWR;

        rt_mutex_init(&ctx->lock, EVENTFD_MUTEX_NAME, RT_IPC_FLAG_FIFO);
        rt_wqueue_init(&ctx->reader_queue);
        rt_wqueue_init(&ctx->writer_queue);

        df->vnode = (struct dfs_vnode *)rt_malloc(sizeof(struct dfs_vnode));
        if (df->vnode)
        {
            dfs_vnode_init(df->vnode, FT_REGULAR, &eventfd_fops);
            df->vnode->data = ctx;
            df->flags = flags;
        }
        else
        {
            rt_mutex_detach(&ctx->lock);
            rt_free(ctx);
            ret = -ENOMEM;
        }
    }

    return ret;
}

static int do_eventfd(unsigned int count, int flags)
{
    struct dfs_file *file;
    int fd;
    int status;
    rt_ssize_t res = 0;

    if (flags & ~EFD_FLAGS_SET)
        return -RT_EINVAL;

    fd = fd_new();
    if (fd >= 0)
    {
        res = fd;
        file = fd_get(fd);

        status = rt_eventfd_create(file, count, flags);
        if (status < 0)
        {
            fd_release(fd);
            res = status;
        }
    }
    else
    {
        res = fd;
    }

    return res;
}

int eventfd(unsigned int count, int flags)
{
    return do_eventfd(count, flags);
}
