/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-3-08      GuEe-GUI     the first version
 */

#ifndef __ROCKCHIP_CLK_H__
#define __ROCKCHIP_CLK_H__

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>

#include <stdlib.h>
#include "../../soc/rockchip/rockchip.h"

#define HZ      100
#define KHZ     1000
#define MHZ     1000000
#define OSC_HZ  (24 * MHZ)

struct rk_cpu_rate_table
{
    rt_ubase_t rate;
    rt_uint32_t aclk_div;
    rt_uint32_t pclk_div;
};

struct rk_pll_rate_table
{
    rt_ubase_t rate;
    rt_uint32_t nr;
    rt_uint32_t nf;
    rt_uint32_t no;
    rt_uint32_t nb;

    rt_uint32_t fbdiv;
    rt_uint32_t postdiv1;
    rt_uint32_t refdiv;
    rt_uint32_t postdiv2;
    rt_uint32_t dsmpd;
    rt_uint32_t frac;
};

struct rk_pll_clock
{
    rt_uint32_t id;
    rt_uint32_t con_offset;
    rt_uint32_t mode_offset;
    rt_uint32_t mode_shift;
    rt_uint32_t lock_shift;
    rt_uint32_t pll_flags;
    struct rk_pll_rate_table *rate_table;
    rt_uint32_t mode_mask;
};

struct rk_clk_gate
{
    const char *name;
    const char *parent_name;

    int con_idx;
    int con_bit;
};

#define GATE(_id, _name,    \
_pname, _con_idx, _con_bit) \
[_id] =                     \
{                           \
    .name = _name,          \
    .parent_name = _pname,  \
    .con_idx = _con_idx,    \
    .con_bit = _con_bit,    \
}


#define CPUCLK_RATE(_rate,  \
    _aclk_div, _pclk_div)   \
{                           \
    .rate     = _rate##U,   \
    .aclk_div = _aclk_div,  \
    .pclk_div = _pclk_div,  \
}

#define PLL_RATE(_rate, _refdiv, _fbdiv,    \
    _postdiv1, _postdiv2, _dsmpd, _frac)    \
{                                           \
    .rate     = _rate##U,                   \
    .fbdiv    = _fbdiv,                     \
    .postdiv1 = _postdiv1,                  \
    .refdiv   = _refdiv,                    \
    .postdiv2 = _postdiv2,                  \
    .dsmpd    = _dsmpd,                     \
    .frac     = _frac,                      \
}

#define PLL(_id, _con, _mode, _mshift,  \
    _lshift, _pflags, _rtable)          \
{                                       \
    .id          = _id,                 \
    .con_offset  = _con,                \
    .mode_offset = _mode,               \
    .mode_shift  = _mshift,             \
    .lock_shift  = _lshift,             \
    .pll_flags   = _pflags,             \
    .rate_table  = _rtable,             \
}

#define DIV_TO_RATE(input_rate, div)    ((input_rate) / ((div) + 1))

#define ROCKCHIP_SOFTRST_HIWORD_MASK    RT_BIT(0)

#endif /* __ROCKCHIP_CLK_H__ */
