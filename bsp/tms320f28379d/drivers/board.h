/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-09-22     Bernard      add board.h to this bsp
 * 2018-09-02     xuzhuoyi     modify for TMS320F28379D version
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtthread.h>


extern int __Heap_start;
extern int __Heap_end;

extern void rt_hw_board_init(void);

#endif

