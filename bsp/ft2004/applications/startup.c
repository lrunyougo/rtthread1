/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2012-12-05     Bernard      the first version
 */

#include <rthw.h>
#include <rtthread.h>
#include "ft_cpu.h"
#include "ft_generic_timer.h"

#include <board.h>

#ifdef RT_USING_SMP

struct rt_thread test_core[RT_CPUS_NR];
static char *core_thread_name[RT_CPUS_NR] = {
    "core0_test",
    "core1_test",
    "core2_test",
    "core3_test"};
static rt_uint8_t core_stack[RT_CPUS_NR][1024];

static void demo_core_thread(void *parameter)
{
    while (1)
    {
        /* code */
        FCpu_SpinLock();
        rt_kprintf("Hi, core%d \r\n", FCpu_IdGet());
        FCpu_SpinUnlock();
        rt_thread_mdelay(20000);
    }
}

void demo_core(void)
{
    rt_ubase_t i;
    rt_uint8_t cpu_id = 0;
    for (i = 0; i < RT_CPUS_NR; i++)
    {
        cpu_id = i;
        rt_thread_init(&test_core[i],
                       core_thread_name[i],
                       demo_core_thread,
                       RT_NULL,
                       &core_stack[i],
                       1024,
                       20,
                       32);

        rt_thread_control(&test_core[i], RT_THREAD_CTRL_BIND_CPU, (void *)cpu_id);
        rt_thread_startup(&test_core[i]);
    }
}
#endif

extern long gic_dis_dump(void);

int main(void)
{
    int count = 1;

#ifdef RT_USING_SMP
    demo_core();
#endif

    while (count++)
    {
        rt_thread_mdelay(2000);
    }

    return RT_EOK;
}
