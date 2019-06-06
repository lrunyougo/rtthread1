/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      first implementation
 */

// <<< Use Configuration Wizard in Context Menu >>>
#ifndef __BOARD_H__
#define __BOARD_H__

#include <fsl_common.h>
#include <fsl_lpuart.h>
#include <fsl_iomuxc.h>

#ifdef __CC_ARM
extern int Image$$RTT_HEAP$$ZI$$Base;
extern int Image$$RTT_HEAP$$ZI$$Limit;
#define HEAP_BEGIN          (&Image$$RTT_HEAP$$ZI$$Base)
#define HEAP_END            (&Image$$RTT_HEAP$$ZI$$Limit)

#elif __ICCARM__
#pragma section="HEAP"
#define HEAP_BEGIN          (__segment_end("HEAP"))
extern void __RTT_HEAP_END;
#define HEAP_END            (&__RTT_HEAP_END)

#else
extern int heap_start;
extern int heap_end;
#define HEAP_BEGIN          (&heap_start)
#define HEAP_END            (&heap_end)
#endif

#define HEAP_SIZE           ((uint32_t)HEAP_END - (uint32_t)HEAP_BEGIN)

#define SDRAM_MPU_INIT
#define SDRAM_BEGIN         (0x80000000u)
#define SDRAM_END           (0x81E00000u)

void rt_hw_board_init(void);

#endif

//*** <<< end of configuration section >>>    ***
