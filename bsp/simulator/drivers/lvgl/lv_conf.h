/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-18     Meco Man      First version
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#define LV_USE_PERF_MONITOR         1
#define LV_COLOR_DEPTH              32

# define USE_WIN32DRV               1
# define WIN32DRV_MONITOR_ZOOM      1

/* music player demo */
#include <rtconfig.h>
#define LV_DISP_DEF_REFR_PERIOD     10
#define LV_HOR_RES_MAX          BSP_LCD_WIDTH
#define LV_VER_RES_MAX          BSP_LCD_HEIGHT
#define LV_USE_DEMO_RTT_MUSIC       1
#define LV_DEMO_RTT_MUSIC_AUTO_PLAY 1
#define LV_FONT_MONTSERRAT_12       1
#define LV_FONT_MONTSERRAT_16       1

#endif
