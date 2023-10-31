/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2016-12-28     Bernard      first version
 * 2018-03-09     Bernard      Add protection for pt->triggered.
 */

#include <stdint.h>
#include <rthw.h>
#include <rtthread.h>
#include <dfs_file.h>
#include "poll.h"

struct rt_poll_node;

struct rt_poll_table
{
    rt_pollreq_t req;
    rt_uint32_t triggered; /* the waited thread whether triggered */
    rt_thread_t polling_thread;
    struct rt_poll_node *nodes;
};

struct rt_poll_node
{
    struct rt_wqueue_node wqn;
    struct rt_poll_table *pt;
    struct rt_poll_node *next;
};

static RT_DEFINE_SPINLOCK(_spinlock);

/**
 * @brief Callback to wake up a waiting thread in the poll table.
 *
 * This function is called when a waiting thread is woken up. It sets the 'triggered' flag
 * in the associated poll table to indicate that the thread has been triggered.
 *
 * @param wait The wait queue node of the waiting thread.
 * @param key  A key used for matching (ignored in this implementation).
 *
 * @return 0 on success, -1 on failure.
 */
static int __wqueue_pollwake(struct rt_wqueue_node *wait, void *key)
{
    struct rt_poll_node *pn;

    if (key && !((rt_ubase_t)key & wait->key))
        return -1;

    pn = rt_container_of(wait, struct rt_poll_node, wqn);
    pn->pt->triggered = 1;

    return __wqueue_default_wake(wait, key);
}

/**
 * @brief Add a node to the poll table's list.
 *
 * This function adds a new node to the list of nodes in the poll table. Each node
 * represents a file descriptor to be polled.
 *
 * @param wq  The wait queue for the polling thread.
 * @param req The poll request structure.
 */
static void _poll_add(rt_wqueue_t *wq, rt_pollreq_t *req)
{
    struct rt_poll_table *pt;
    struct rt_poll_node *node;

    node = (struct rt_poll_node *)rt_malloc(sizeof(struct rt_poll_node));
    if (node == RT_NULL)
        return;

    pt = rt_container_of(req, struct rt_poll_table, req);

    node->wqn.key = req->_key;
    rt_list_init(&(node->wqn.list));
    node->wqn.polling_thread = pt->polling_thread;
    node->wqn.wakeup = __wqueue_pollwake;
    node->next = pt->nodes;
    node->pt = pt;
    pt->nodes = node;
    rt_wqueue_add(wq, &node->wqn);
}

/**
 * @brief Initialize a poll table.
 *
 * This function initializes a poll table structure.
 *
 * @param pt The poll table to initialize.
 */
static void poll_table_init(struct rt_poll_table *pt)
{
    pt->req._proc = _poll_add;
    pt->triggered = 0;
    pt->nodes = RT_NULL;
    pt->polling_thread = rt_thread_self();
}

/**
 * @brief Wait for polling with a timeout.
 *
 * This function waits for the polling to complete or a specified timeout to occur.
 *
 * @param pt   The poll table to wait on.
 * @param msec The timeout in milliseconds.
 *
 * @return 0 if the polling is successful, -1 if the polling times out.
 */
static int poll_wait_timeout(struct rt_poll_table *pt, int msec)
{
    rt_int32_t timeout;
    int ret = 0;
    struct rt_thread *thread;
    rt_base_t level;

    thread = pt->polling_thread;

    timeout = rt_tick_from_millisecond(msec);

    level = rt_spin_lock_irqsave(&_spinlock);

    if (timeout != 0 && !pt->triggered)
    {
        if (rt_thread_suspend_with_flag(thread, RT_INTERRUPTIBLE) == RT_EOK)
        {
            if (timeout > 0)
            {
                rt_timer_control(&(thread->thread_timer),
                                 RT_TIMER_CTRL_SET_TIME,
                                 &timeout);
                rt_timer_start(&(thread->thread_timer));
            }

            rt_spin_unlock_irqrestore(&_spinlock, level);

            rt_schedule();

            level = rt_spin_lock_irqsave(&_spinlock);
        }
    }

    ret = !pt->triggered;
    rt_spin_unlock_irqrestore(&_spinlock, level);

    return ret;
}

/**
 * @brief Perform polling for a single file descriptor.
 *
 * This function performs polling for a single file descriptor and sets the
 * revents field in the pollfd structure with the events that have occurred.
 *
 * @param pollfd The pollfd structure to store results.
 * @param req    The poll request structure.
 *
 * @return The number of events detected, -1 on error.
 */
static int do_pollfd(struct pollfd *pollfd, rt_pollreq_t *req)
{
    int mask = 0;
    int fd;

    fd = pollfd->fd;

    if (fd >= 0)
    {
        struct dfs_file *f = fd_get(fd);
        mask = POLLNVAL;

        if (f)
        {
            mask = POLLMASK_DEFAULT;
            if (f->vnode->fops->poll)
            {
                req->_key = pollfd->events | POLLERR | POLLHUP;

                mask = f->vnode->fops->poll(f, req);

                /* dealwith the device return error -1*/
                if (mask < 0)
                {
                    pollfd->revents = 0;
                    return mask;
                }
            }
            /* Mask out unneeded events. */
            mask &= pollfd->events | POLLERR | POLLHUP;
        }
    }
    pollfd->revents = mask;

    return mask;
}

/**
 * @brief Perform polling on multiple file descriptors.
 *
 * This function performs polling for multiple file descriptors and sets the
 * revents field in the pollfd structures with the events that have occurred.
 *
 * @param fds    Array of pollfd structures to be polled.
 * @param nfds   The number of file descriptors in the array.
 * @param pt     The poll table to use for polling.
 * @param msec   The polling timeout in milliseconds.
 *
 * @return The number of file descriptors with events detected, -1 on error.
 */
static int poll_do(struct pollfd *fds, nfds_t nfds, struct rt_poll_table *pt, int msec)
{
    int num;
    int istimeout = 0;
    nfds_t n;
    struct pollfd *pf;
    int ret = 0;

    if (msec == 0)
    {
        pt->req._proc = RT_NULL;
        istimeout = 1;
    }

    while (1)
    {
        pf = fds;
        num = 0;
        pt->triggered = 0;

        for (n = 0; n < nfds; n++)
        {
            ret = do_pollfd(pf, &pt->req);
            if (ret < 0)
            {
                /*dealwith the device return error -1  */
                pt->req._proc = RT_NULL;
                return ret;
            }
            else if (ret > 0)
            {
                num++;
                pt->req._proc = RT_NULL;
            }
            pf++;
        }

        pt->req._proc = RT_NULL;

        if (num || istimeout)
            break;

        if (poll_wait_timeout(pt, msec))
            istimeout = 1;
    }

    return num;
}
/**
 * @brief Cleanup and release resources associated with the poll table.
 *
 * This function releases the resources associated with the poll table, including
 * deallocating memory used for poll nodes and removing them from the wait queue.
 *
 * @param pt Pointer to the poll table structure to clean up.
 */
static void poll_teardown(struct rt_poll_table *pt)
{
    struct rt_poll_node *node, *next;

    next = pt->nodes;
    while (next)
    {
        node = next;
        rt_wqueue_remove(&node->wqn);
        next = node->next;
        rt_free(node);
    }
}

/**
 * @brief Poll a set of file descriptors.
 *
 * This function performs polling on a set of file descriptors and returns the number of events.
 * It initializes a poll table, performs the polling, and then cleans up the table.
 *
 * @param fds    An array of pollfd structures representing file descriptors to poll.
 * @param nfds   The number of file descriptors in the 'fds' array.
 * @param timeout The maximum time to wait for an event in milliseconds.
 *
 * @return The number of file descriptors with available events, or 0 on timeout, or -1 on error.
 */
int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    int num;
    struct rt_poll_table table;

    poll_table_init(&table);

    num = poll_do(fds, nfds, &table, timeout);

    poll_teardown(&table);

    return num;
}
