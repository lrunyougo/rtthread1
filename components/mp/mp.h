/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-25     tangzz98     the first version
 */

#ifndef __MP_H__
#define __MP_H__

#include <rtdef.h>
#include <mpporttype.h>

#define ADDR_IN_REGION(addr, region) (((rt_size_t)(addr) >= (rt_size_t)((region)->start)) && ((rt_size_t)(addr) < (rt_size_t)((region)->start) + (region)->size))

typedef struct
{
    void *start;
    rt_size_t size;
    rt_mem_attr_t attr;
} rt_mem_region_t;

#include <mpport.h>

typedef struct
{
    rt_mem_region_t region;
    rt_thread_t owner;
} rt_mem_exclusive_region_t;

int rt_mem_protection_init(void);
rt_err_t rt_mem_protection_add_region(rt_thread_t thread, rt_mem_region_t *region);
rt_err_t rt_mem_protection_delete_region(rt_thread_t thread, rt_mem_region_t *region);
rt_err_t rt_mem_protection_update_region(rt_thread_t thread, rt_mem_region_t *region);
rt_err_t rt_mem_protection_add_exclusive_region(void *start, rt_size_t size);
rt_err_t rt_mem_protection_delete_exclusive_region(void *start, rt_size_t size);

#endif /* __MP_H__ */
