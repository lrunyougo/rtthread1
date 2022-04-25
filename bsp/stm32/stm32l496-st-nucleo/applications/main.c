/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-03-14     super_mcu    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED2 pin: PB7 */
#define LED2_PIN    GET_PIN(B, 7)

#ifdef RT_USING_USER_MAIN
int main(void)
#else
int rtt_main(void)
#endif
{
    /* set LED2 pin mode to output */
    rt_pin_mode(LED2_PIN, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED2_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED2_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

#ifndef RT_USING_USER_MAIN
int main(void)
{
    rtthread_startup();
}
#endif
