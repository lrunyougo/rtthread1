/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-08-23     liYony       first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "ch32v30x.h"
// void rt_trigger_software_interrupt(void)
// {
//     SysTick->CTLR |= (1<<31);
// }

// __attribute__((naked)) void rt_hw_do_before_save_above(void)
// {
//     __asm volatile ("li t0, %0" : : "i" (0x20) );
//     __asm volatile ("csrs 0x804," "t0");
// }

// void rt_hw_do_after_save_above(void)
// {
//     SysTick->CTLR &= ~(1<<31);
// }
/* defined the LED0 pin: PB5 */
#define LED0_PIN              rt_pin_get("PB.5")

int main(void)
{
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}
