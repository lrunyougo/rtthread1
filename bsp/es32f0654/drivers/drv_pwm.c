/*
 * Copyright (C) 2018 Shanghai Eastsoft Microelectronics Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-11     wangyq       the first version
 */

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <ald_timer.h>
#include <ald_gpio.h>

static rt_err_t es32f0_pwm_control(struct rt_device_pwm *device, int cmd, void *arg)
{
    rt_err_t ret = RT_EOK;
    timer_channel_t pwm_channel;
    timer_oc_init_t tim_ocinit;
    timer_handle_t *timer_initstruct = (timer_handle_t *)device->parent.user_data;
    struct rt_pwm_configuration *cfg = (struct rt_pwm_configuration *)arg;

    RT_ASSERT(timer_initstruct != RT_NULL);

    tim_ocinit.oc_mode      = TIMER_OC_MODE_PWM1;
    tim_ocinit.oc_polarity  = TIMER_OC_POLARITY_HIGH;
    tim_ocinit.oc_fast_en   = DISABLE;
    tim_ocinit.ocn_polarity = TIMER_OCN_POLARITY_HIGH;
    tim_ocinit.ocn_idle     = TIMER_OCN_IDLE_RESET;
    tim_ocinit.oc_idle      = TIMER_OC_IDLE_RESET;

    /* select pwm output channel */
    if (0 == cfg->channel)
    {
        pwm_channel = TIMER_CHANNEL_1;
    }
    else if (1 == cfg->channel)
    {
        pwm_channel = TIMER_CHANNEL_2;
    }
    else if (2 == cfg->channel)
    {
        if (timer_initstruct->perh == GP16C2T0 || timer_initstruct->perh == GP16C2T1)
            return RT_EINVAL;
        pwm_channel = TIMER_CHANNEL_3;
    }
    else if (3 == cfg->channel)
    {
        if (timer_initstruct->perh == GP16C2T0 || timer_initstruct->perh == GP16C2T1)
            return RT_EINVAL;
        pwm_channel = TIMER_CHANNEL_4;
    }
    else
    {
        return RT_EINVAL;
    }

    switch (cmd)
    {
    case PWM_CMD_ENABLE:
        timer_pwm_start(timer_initstruct, pwm_channel);
        break;

    case PWM_CMD_DISABLE:
        timer_pwm_stop(timer_initstruct, pwm_channel);
        break;

    case PWM_CMD_SET:
        /* count registers max 0xFFFF, auto adjust prescaler*/
        do
        {
            timer_pwm_set_freq(timer_initstruct, 1000000000 / cfg->period);
            timer_initstruct->init.prescaler ++;
        }
        while (timer_initstruct->init.period > 0xFFFF);
        /* update prescaler */
        WRITE_REG(timer_initstruct->perh->PRES, -- timer_initstruct->init.prescaler);
        timer_oc_config_channel(timer_initstruct, &tim_ocinit, pwm_channel);
        timer_pwm_set_duty(timer_initstruct, pwm_channel, cfg->pulse * 100 / cfg->period);
        break;

    case PWM_CMD_GET:
        cfg->pulse = timer_read_capture_value(timer_initstruct, pwm_channel) * 100 / READ_REG(timer_initstruct->perh->AR);
        break;

    default:
        break;
    }
    return ret;
}

const static struct rt_pwm_ops es32f0_pwm_ops =
{
    es32f0_pwm_control
};

int rt_hw_pwm_init(void)
{
    rt_err_t ret = RT_EOK;
    gpio_init_t gpio_initstructure;

    gpio_initstructure.mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.odos = GPIO_PUSH_PULL;
    gpio_initstructure.pupd = GPIO_PUSH_UP;
    gpio_initstructure.odrv = GPIO_OUT_DRIVE_NORMAL;
    gpio_initstructure.flt  = GPIO_FILTER_DISABLE;
    gpio_initstructure.type = GPIO_TYPE_TTL;

#ifdef BSP_USING_PWM0 /* 4 channels */
    static struct rt_device_pwm pwm_dev0;
    static timer_handle_t timer_initstruct0;

    timer_initstruct0.perh = AD16C4T0;
    timer_pwm_init(&timer_initstruct0);

    /* gpio initialization */
    gpio_initstructure.func = GPIO_FUNC_2;
    gpio_init(GPIOA, GPIO_PIN_8, &gpio_initstructure);
    gpio_init(GPIOA, GPIO_PIN_9, &gpio_initstructure);
    gpio_init(GPIOA, GPIO_PIN_10, &gpio_initstructure);
    gpio_init(GPIOA, GPIO_PIN_11, &gpio_initstructure);

    ret = rt_device_pwm_register(&pwm_dev0, "pwm0", &es32f0_pwm_ops, &timer_initstruct0);
#endif

#ifdef BSP_USING_PWM1 /* 4 channels */
    static struct rt_device_pwm pwm_dev1;
    static timer_handle_t timer_initstruct1;

    timer_initstruct1.perh = GP16C4T0;
    timer_pwm_init(&timer_initstruct1);

    /* gpio initialization */
    gpio_initstructure.func = GPIO_FUNC_2;
    gpio_init(GPIOB, GPIO_PIN_6, &gpio_initstructure);
    gpio_init(GPIOB, GPIO_PIN_7, &gpio_initstructure);
    gpio_init(GPIOB, GPIO_PIN_8, &gpio_initstructure);
    gpio_init(GPIOB, GPIO_PIN_9, &gpio_initstructure);

    ret = rt_device_pwm_register(&pwm_dev1, "pwm1", &es32f0_pwm_ops, &timer_initstruct1);
#endif

#ifdef BSP_USING_PWM2 /* 2 channels */
    static struct rt_device_pwm pwm_dev2;
    static timer_handle_t timer_initstruct2;

    timer_initstruct2.perh = GP16C2T0;
    timer_pwm_init(&timer_initstruct2);

    /* gpio initialization */
    gpio_initstructure.func = GPIO_FUNC_2;
    gpio_init(GPIOA, GPIO_PIN_0, &gpio_initstructure);
    gpio_init(GPIOA, GPIO_PIN_1, &gpio_initstructure);

    ret = rt_device_pwm_register(&pwm_dev2, "pwm2", &es32f0_pwm_ops, &timer_initstruct2);
#endif

#ifdef BSP_USING_PWM3 /* 2 channels */
    static struct rt_device_pwm pwm_dev3;
    static timer_handle_t timer_initstruct3;

    timer_initstruct3.perh = GP16C2T1;
    timer_pwm_init(&timer_initstruct3);

    /* gpio initialization */
    gpio_initstructure.func = GPIO_FUNC_3;
    gpio_init(GPIOC, GPIO_PIN_6, &gpio_initstructure);
    gpio_init(GPIOC, GPIO_PIN_7, &gpio_initstructure);

    ret = rt_device_pwm_register(&pwm_dev3, "pwm3", &es32f0_pwm_ops, &timer_initstruct3);
#endif

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_pwm_init);
