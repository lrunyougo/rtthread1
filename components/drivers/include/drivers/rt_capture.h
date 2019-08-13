/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-08-13     balanceTWK   first version.
 */

#ifndef __RT_CAPTURE_H__
#define __RT_CAPTURE_H__

#include <rtthread.h>
#include <rtdevice.h>

#ifdef __cplusplus
extern "C" {
#endif

/* capture control command */
#define CAPTURE_CMD_CLEAR_BUF        (128 + 0)    /* clear capture buf */
#define CAPTURE_CMD_SET_WATERMARK    (128 + 1)    /* Set the callback threshold */

struct capture_data_struct
{
    rt_bool_t   is_high;
    rt_uint32_t pulsewidth_us;
};

struct rt_capture_device
{
    struct rt_device          parent;

    const struct rt_capture_ops *ops;
    struct rt_ringbuffer *ringbuff;
    rt_size_t watermark;
};

/**
 * capture operators
 */
struct rt_capture_ops
{
    rt_err_t (*init)(struct rt_capture_device *capture);
    rt_err_t (*open)(struct rt_capture_device *capture);
    rt_err_t (*close)(struct rt_capture_device *capture);
    rt_err_t (*get_pulsewidth)(struct rt_capture_device *capture, rt_uint32_t *pulsewidth_us);
};

void rt_hw_capture_isr(struct rt_capture_device *capture, rt_bool_t level);

rt_err_t rt_hw_capture_register(struct rt_capture_device *capture,
                               const char              *name,
                               rt_uint32_t              flag,
                               void                    *data);
#ifdef __cplusplus
}
#endif

#endif /* __RT_CAPTURE_H__ */
