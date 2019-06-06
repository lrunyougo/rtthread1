/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-12     zylx         first version
 */

#ifndef __TIM_CONFIG_H__
#define __TIM_CONFIG_H__

#include <rtthread.h>

<<<<<<< HEAD
=======
#ifdef __cplusplus
extern "C" {
#endif

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
#ifndef TIM_DEV_INFO_CONFIG
#define TIM_DEV_INFO_CONFIG                     \
    {                                           \
        .maxfreq = 1000000,                     \
        .minfreq = 2000,                        \
        .maxcnt  = 0xFFFF,                      \
        .cntmode = HWTIMER_CNTMODE_UP,          \
    }
#endif /* TIM_DEV_INFO_CONFIG */

#ifdef BSP_USING_TIM15
#ifndef TIM15_CONFIG
#define TIM15_CONFIG                                        \
    {                                                       \
       .tim_handle.Instance     = TIM15,                    \
       .tim_irqn                = TIM1_BRK_TIM15_IRQn,      \
       .name                    = "timer15",                \
    }
#endif /* TIM15_CONFIG */
#endif /* BSP_USING_TIM15 */

#ifdef BSP_USING_TIM16
#ifndef TIM16_CONFIG
#define TIM16_CONFIG                                        \
    {                                                       \
       .tim_handle.Instance     = TIM16,                    \
       .tim_irqn                = TIM1_UP_TIM16_IRQn,       \
       .name                    = "timer16",                \
    }
#endif /* TIM16_CONFIG */
#endif /* BSP_USING_TIM16 */

#ifdef BSP_USING_TIM17
#ifndef TIM17_CONFIG
#define TIM17_CONFIG                                        \
    {                                                       \
       .tim_handle.Instance     = TIM17,                    \
       .tim_irqn                = TIM1_TRG_COM_TIM17_IRQn,  \
       .name                    = "timer17",                \
    }
#endif /* TIM17_CONFIG */
#endif /* BSP_USING_TIM17 */

<<<<<<< HEAD
=======
#ifdef __cplusplus
}
#endif

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
#endif /* __TIM_CONFIG_H__ */
