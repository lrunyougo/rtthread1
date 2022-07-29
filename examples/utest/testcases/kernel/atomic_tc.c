/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-27     flybreak     the first version
 */

#include <rtthread.h>
#include "utest.h"

#include <rthw.h>

#define THREAD_PRIORITY         25
#define THREAD_TIMESLICE        1
#define THREAD_STACKSIZE        1024

/* convenience macro - return either 64-bit or 32-bit value */
#define ATOMIC_WORD(val_if_64, val_if_32)                                           \
    ((rt_atomic_t)((sizeof(void *) == sizeof(uint64_t)) ? (val_if_64) : (val_if_32)))

static rt_atomic_t count = 0;
static rt_sem_t sem_t;

static void test_atomic_api(void)
{
    rt_atomic_t base;

    /* rt_atomic_t */
    uassert_true(sizeof(rt_atomic_t) == ATOMIC_WORD(sizeof(uint64_t), sizeof(uint32_t)));

    /* rt_atomic_add */
    base = 0;
    rt_atomic_add(&base, 10);
    uassert_true(base == 10);
    /* rt_atomic_add negative */
    base = 2;
    rt_atomic_add(&base, -4);
    uassert_true(base == -2);

    /* rt_atomic_sub */
    base = 11;
    rt_atomic_sub(&base, 10);
    uassert_true(base == 1);
    /* rt_atomic_sub negative */
    base = 2;
    rt_atomic_sub(&base, -5);
    uassert_true(base == 7);

    /* rt_atomic_or */
    base = 0xFF00;
    rt_atomic_or(&base, 0x0F0F);
    uassert_true(base == 0xFF0F);

    /* rt_atomic_xor */
    base = 0xFF00;
    rt_atomic_xor(&base, 0x0F0F);
    uassert_true(base == 0xF00F);

    /* rt_atomic_and */
    base = 0xFF00;
    rt_atomic_and(&base, 0x0F0F);
    uassert_true(base == 0x0F00);

    /* rt_atomic_nand */
    base = 0xFF00;
    rt_atomic_nand(&base, 0x0F0F);
    uassert_true(base == ATOMIC_WORD(0xFFFFFFFFFFFFF0FF, 0xFFFFF0FF));

    /* rt_atomic_cas */
    base = 10;
    uassert_true(rt_atomic_cas(&base, 10, 11) == 10);
    uassert_true(base == 11);
}

static void ture_entry(void *parameter)
{
    int i;
    for(i = 0; i < 1000000; i++)
    {
        rt_atomic_add(&count, 1);
    }
    rt_sem_release(sem_t);
}

static void test_atomic_add(void)
{
    rt_thread_t thread;
    int i;
    sem_t = rt_sem_create("atomic_sem", 0, RT_IPC_FLAG_PRIO);

    count = 0;
    thread = rt_thread_create("t1", ture_entry, RT_NULL, THREAD_STACKSIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(thread);
    thread = rt_thread_create("t2", ture_entry, RT_NULL, THREAD_STACKSIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(thread);
    thread = rt_thread_create("t3", ture_entry, RT_NULL, THREAD_STACKSIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(thread);

    for(i = 0; i < 3; i++)
    {
        rt_sem_take(sem_t, RT_WAITING_FOREVER);
    }
    uassert_true(count == 3000000);
}

static rt_err_t utest_tc_init(void)
{
    return RT_EOK;
}

static rt_err_t utest_tc_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_atomic_api);
    UTEST_UNIT_RUN(test_atomic_add);
}
UTEST_TC_EXPORT(testcase, "testcases.kernel.atomic_tc", utest_tc_init, utest_tc_cleanup, 10);
