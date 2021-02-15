/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-11     supperthomas first version
 *
 */

#include <rtthread.h>
#include <rtdevice.h>

int main(void)
{
    int count = 1;
    while (count++)
    {
        rt_thread_mdelay(500);
    }
    return RT_EOK;
}
