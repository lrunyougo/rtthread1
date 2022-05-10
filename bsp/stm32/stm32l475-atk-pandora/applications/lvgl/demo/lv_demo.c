/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-17     Meco Man      First version
 */
#include <lvgl.h>

extern void lv_demo_calendar(void);

void lv_user_gui_init(void)
{
    /* display demo */
    lv_demo_calendar();
}
