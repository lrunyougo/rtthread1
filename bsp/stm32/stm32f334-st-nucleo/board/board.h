/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-06-05     tangzz98     first version
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtthread.h>
#include <stm32f3xx.h>
#include "drv_common.h"
#include "drv_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STM32_FLASH_START_ADRESS        ((uint32_t)0x08000000)
#define STM32_FLASH_SIZE                (64 * 1024)
#define STM32_FLASH_END_ADDRESS         ((uint32_t)(STM32_FLASH_START_ADRESS + STM32_FLASH_SIZE))

#define STM32_SRAM_START_ADDRESS        ((uint32_t)0x20000000)
#define STM32_SRAM_SIZE                 (12 * 1024)
#define STM32_SRAM_END_ADDRESS          ((uint32_t)(STM32_SRAM_START_ADDRESS + STM32_SRAM_SIZE))

#if defined(__ARMCC_VERSION)
extern int Image$$RW_IRAM1$$ZI$$Limit;
#define HEAP_BEGIN      (&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
#pragma section="CSTACK"
#define HEAP_BEGIN      (__segment_end("CSTACK"))
#else
extern int __bss_end;
#define HEAP_BEGIN      (&__bss_end)
#endif

#define HEAP_END        STM32_SRAM_END_ADDRESS

#ifdef RT_USING_MEM_PROTECTION
#define NUM_STATIC_REGIONS 2
#endif

void SystemClock_Config(void);

#ifdef __cplusplus
}
#endif

#endif

