/*
 * Copyright (c) 2023, lepustse@gmail.com
 *
 * License-Identifier: MIT
 *
 * Change Logs:
 * Date         Author		Notes
 * 2023-05-03   lepustse	the first version
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtconfig.h>
#include "zynqmp_r5.h"

#if defined(__CC_ARM)
extern int Image$$RW_IRAM1$$ZI$$Limit;
#define HEAP_BEGIN      ((void*)&Image$$RW_IRAM1$$ZI$$Limit)
#elif defined(__GNUC__)
extern int __bss_end;
#define HEAP_BEGIN      ((void*)&__bss_end)
#endif

#define HEAP_END        (void*)(0x80000000)

void rt_hw_board_init(void);

#endif
