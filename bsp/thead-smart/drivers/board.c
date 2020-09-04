/*
 * File      : board.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:i
 * Date           Author       Notes
 * 2020-08-20     zx.chen      add T-HEAD header file csi_core.h
 * 2017-08-10     Urey         first implementation
 */

#include <rthw.h>
#include <rtthread.h>

#include "board.h"
#include "csi_core.h"
#include "drv_usart.h"

extern int __bss_end__;
#define SYS_HEAP_BEGIN    (&__bss_end__)

#include "core_rv32.h"


extern usart_handle_t console_handle;
extern void ioreuse_initial(void);


/**
 * This function will initial smartl-evb(e906) board.
 */
void rt_hw_board_init(void)
{
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
    /* initialize hardware usart */
    rt_hw_usart_init();

#ifdef RT_USING_CONSOLE
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif

#ifdef RT_USING_HEAP
    rt_system_heap_init((void *)SYS_HEAP_BEGIN, (void *)E906FD_IRAM_END);
#endif
}

/*@}*/
