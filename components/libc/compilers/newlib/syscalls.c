/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-11     Meco Man     remove _gettimeofday_r() and _times_r()
 */

#include <reent.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>

#include <rtthread.h>

#ifdef RT_USING_DFS
#include <dfs_posix.h>
#endif

#ifdef RT_USING_MODULE
#include <dlmodule.h>
#endif

/* Reentrant versions of system calls.  */

#ifndef _REENT_ONLY
int *
__errno ()
{
  return _rt_errno();
}
#endif

int
_close_r(struct _reent *ptr, int fd)
{
#ifndef RT_USING_DFS
    return 0;
#else
    return close(fd);
#endif
}

int
_execve_r(struct _reent *ptr, const char * name, char *const *argv, char *const *env)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

int
_fcntl_r(struct _reent *ptr, int fd, int cmd, int arg)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

int
_fork_r(struct _reent *ptr)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

int
_fstat_r(struct _reent *ptr, int fd, struct stat *pstat)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

int
_getpid_r(struct _reent *ptr)
{
    return 0;
}

int
_isatty_r(struct _reent *ptr, int fd)
{
    if (fd >=0 && fd < 3) return 1;

    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

int
_kill_r(struct _reent *ptr, int pid, int sig)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

int
_link_r(struct _reent *ptr, const char *old, const char *new)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

_off_t
_lseek_r(struct _reent *ptr, int fd, _off_t pos, int whence)
{
#ifndef RT_USING_DFS
    return 0;
#else
    _off_t rc;

    rc = lseek(fd, pos, whence);
    return rc;
#endif
}

int
_mkdir_r(struct _reent *ptr, const char *name, int mode)
{
#ifndef RT_USING_DFS
    return 0;
#else
    int rc;

    rc = mkdir(name, mode);
    return rc;
#endif
}

int
_open_r(struct _reent *ptr, const char *file, int flags, int mode)
{
#ifndef RT_USING_DFS
    return 0;
#else
    int rc;

    rc = open(file, flags, mode);
    return rc;
#endif
}

_ssize_t
_read_r(struct _reent *ptr, int fd, void *buf, size_t nbytes)
{
#ifndef RT_USING_DFS
    return 0;
#else
    _ssize_t rc;

    rc = read(fd, buf, nbytes);
    return rc;
#endif
}

int
_rename_r(struct _reent *ptr, const char *old, const char *new)
{
#ifndef RT_USING_DFS
    return 0;
#else
    int rc;

    rc = rename(old, new);
    return rc;
#endif
}

void *
_sbrk_r(struct _reent *ptr, ptrdiff_t incr)
{
    /* no use this routine to get memory */
    return RT_NULL;
}

int
_stat_r(struct _reent *ptr, const char *file, struct stat *pstat)
{
#ifndef RT_USING_DFS
    return 0;
#else
    int rc;

    rc = stat(file, pstat);
    return rc;
#endif
}

int
_unlink_r(struct _reent *ptr, const char *file)
{
#ifndef RT_USING_DFS
    return 0;
#else
    int rc;

    rc = unlink(file);
    return rc;
#endif
}

int
_wait_r(struct _reent *ptr, int *status)
{
    /* return "not supported" */
    ptr->_errno = ENOTSUP;
    return -1;
}

#ifdef RT_USING_DEVICE
_ssize_t
_write_r(struct _reent *ptr, int fd, const void *buf, size_t nbytes)
{
#ifndef RT_USING_DFS
    if (fileno(stdout) == fd)
    {
        rt_device_t console;

        console = rt_console_get_device();
        if (console) return rt_device_write(console, -1, buf, nbytes);
    }

    return 0;

#else
    _ssize_t rc;

    rc = write(fd, buf, nbytes);
    return rc;
#endif
}
#endif

/* Memory routine */
void *
_malloc_r (struct _reent *ptr, size_t size)
{
    void* result;

    result = (void*)rt_malloc (size);
    if (result == RT_NULL)
    {
        ptr->_errno = ENOMEM;
    }

    return result;
}

void *
_realloc_r (struct _reent *ptr, void *old, size_t newlen)
{
    void* result;

    result = (void*)rt_realloc (old, newlen);
    if (result == RT_NULL)
    {
        ptr->_errno = ENOMEM;
    }

    return result;
}

void *_calloc_r (struct _reent *ptr, size_t size, size_t len)
{
    void* result;

    result = (void*)rt_calloc (size, len);
    if (result == RT_NULL)
    {
        ptr->_errno = ENOMEM;
    }

    return result;
}

void
_free_r (struct _reent *ptr, void *addr)
{
    rt_free (addr);
}

void
exit (int status)
{
    rt_thread_t self = rt_thread_self();

#ifdef RT_USING_MODULE
    if (dlmodule_self())
    {
        dlmodule_exit(status);
    }
#endif

    if (self != RT_NULL)
    {
        rt_kprintf("thread:%-8.*s exit:%d!\n", RT_NAME_MAX, self->name, status);
        rt_thread_suspend(self);
        rt_schedule();
    }
}

void
_system(const char *s)
{
    /* not support this call */
    return;
}

void __libc_init_array(void)
{
    /* we not use __libc init_aray to initialize C++ objects */
}

void abort(void)
{
    rt_thread_t self = rt_thread_self();

#ifdef RT_USING_MODULE
    if (dlmodule_self())
    {
        dlmodule_exit(-1);
    }
#endif

    if (self != RT_NULL)
    {
        rt_kprintf("thread:%-8.*s abort!\n", RT_NAME_MAX, self->name);
        rt_thread_suspend(self);
        rt_schedule();
    }
}

uid_t getuid(void)
{
    return 0;
}

mode_t umask(mode_t mask)
{
    return 022;
}

int flock(int fd, int operation)
{
    return 0;
}

/*
These functions will be implemented and replaced by the 'common/time.c' file
int _gettimeofday_r(struct _reent *ptr, struct timeval *__tp, void *__tzp);
_CLOCK_T_  _times_r(struct _reent *ptr, struct tms *ptms);
*/
