/*
 * File      : cputime.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2017, RT-Thread Development Team
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
 * Change Logs:
 * Date           Author            Notes
 * 2017-12-23     Bernard           first version
 */

#include <rtdevice.h>
#include <rtthread.h>

static const struct rt_clock_cputime_ops *_cputime_ops  = RT_NULL;

/**
 * The clock_cpu_getres() function shall return the resolution of CPU time, the 
 * number of nanosecond per tick.
 *
 * @return the number of nanosecond per tick
 */
float clock_cpu_getres(void)
{
    if (_cputime_ops)
        return _cputime_ops->cputime_getres();

    rt_set_errno(-ENOSYS);
    return 0;
}

/**
 * The clock_cpu_gettime() function shall return the current value of cpu time tick.
 *
 * @return the cpu tick
 */
rt_uint32_t clock_cpu_gettime(void)
{
    if (_cputime_ops)
        return _cputime_ops->cputime_gettime();

    rt_set_errno(-ENOSYS);
    return 0;
}

/**
 * The clock_cpu_microsecond() fucntion shall return the microsecond according to 
 * cpu_tick parameter.
 *
 * @param cpu_tick the cpu tick
 *
 * @return the microsecond
 */
rt_uint32_t clock_cpu_microsecond(rt_uint32_t cpu_tick)
{
    float unit = clock_cpu_getres();

    return (cpu_tick * unit) / 1000;
}

/**
 * The clock_cpu_microsecond() fucntion shall return the millisecond according to 
 * cpu_tick parameter.
 *
 * @param cpu_tick the cpu tick
 *
 * @return the millisecond
 */
rt_uint32_t clock_cpu_millisecond(rt_uint32_t cpu_tick)
{
    float unit = clock_cpu_getres();

    return (cpu_tick * unit) / (1000 * 1000);
}

/**
 * The clock_cpu_seops() function shall set the ops of cpu time.
 * 
 * @return always return 0.
 */
int clock_cpu_setops(const struct rt_clock_cputime_ops *ops)
{
    _cputime_ops = ops;
    if (ops)
    {
        RT_ASSERT(ops->cputime_getres  != RT_NULL);
        RT_ASSERT(ops->cputime_gettime != RT_NULL);
    }

    return 0;
}
