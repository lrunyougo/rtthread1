/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-06-29     Rbb666       first version
 */

#include <rtthread.h>
#include <rtdevice.h>

#include "drv_gpio.h"

#define LED_PIN     GET_PIN(13, 7)

int main(void)
{
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

    for (;;)
    {
        rt_pin_write(CYBSP_USER_LED, PIN_HIGH);
        rt_thread_mdelay(1000);
        rt_pin_write(CYBSP_USER_LED, PIN_LOW);
        rt_thread_mdelay(1000);
    }
}
