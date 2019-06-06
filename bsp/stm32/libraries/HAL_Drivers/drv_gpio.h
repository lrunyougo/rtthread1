/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
<<<<<<< HEAD
 * 2018-11-06     balanceTWK        change to new framework
=======
 * 2018-11-06     balanceTWK        first version
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
 */

#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__

#include <drv_common.h>
<<<<<<< HEAD
=======
#include <board.h>
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

#define __STM32_PORT(port)  GPIO##port

#define GET_PIN(PORTx,PIN) (rt_base_t)((16 * ( ((rt_base_t)__STM32_PORT(PORTx) - (rt_base_t)GPIOA)/(0x0400UL) )) + PIN)

#define __STM32_PIN(index, gpio, gpio_index)                                \
    {                                                                       \
        index, GPIO##gpio, GPIO_PIN_##gpio_index                            \
    }

#define __STM32_PIN_RESERVE                                                 \
    {                                                                       \
        -1, 0, 0                                                            \
    }

/* STM32 GPIO driver */
struct pin_index
{
    int index;
    GPIO_TypeDef *gpio;
    uint32_t pin;
};

struct pin_irq_map
{
    rt_uint16_t pinbit;
    IRQn_Type irqno;
};

int rt_hw_pin_init(void);

#endif /* __DRV_GPIO_H__ */

