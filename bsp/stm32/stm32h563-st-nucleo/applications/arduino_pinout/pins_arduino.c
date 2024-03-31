/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author         Notes
 * 2023-12-30     ChuShicheng    first version
 */

#include <Arduino.h>
#include "pins_arduino.h"

#define DBG_TAG    "RTduino.pins_arduino"
#define DBG_LVL    DBG_INFO
#include <rtdbg.h>

/*
 * {Arduino Pin, RT-Thread Pin [, Device Name, Channel]}
 * [] means optional
 * Digital pins must NOT give the device name and channel.
 * Analog pins MUST give the device name and channel(ADC, PWM or DAC).
 * Arduino Pin must keep in sequence.
 */
const pin_map_t pin_map_table[]=
{
    {D0, GET_PIN(B, 7), "lpuart1"},         /* Serial-RX */
    {D1, GET_PIN(B, 6), "lpuart1"},         /* Serial-TX */
    {D2, GET_PIN(G, 14)},
    {D3, GET_PIN(E, 13), "pwm1", 3},        /* PWM */
    {D4, GET_PIN(E, 14)},
    {D5, GET_PIN(E, 11), "pwm1", 2},        /* PWM */
    {D6, GET_PIN(E, 9), "pwm1", 1},         /* PWM */
    {D7, GET_PIN(G, 12)},
    {D8, GET_PIN(F, 3)},
    {D9, GET_PIN(D, 15), "pwm4", 4},        /* PWM */
    {D10, GET_PIN(D, 14), "pwm4", 3},       /* PWM */
    {D11, GET_PIN(B, 5), "pwm3", 2},        /* PWM */
    {D12, GET_PIN(G, 9)},
    {D13, GET_PIN(A, 5)},                   /* LED_BUILTIN */
    {D14, GET_PIN(B, 9), "i2c1"},           /* I2C-SDA (Wire) */
    {D15, GET_PIN(B, 8), "i2c1"},           /* I2C-SCL (Wire) */
    {A0, GET_PIN(A, 6), "adc2", 3},         /* ADC */
    {A1, GET_PIN(C, 0), "adc2", 10},        /* ADC */
    {A2, GET_PIN(C, 3), "adc2", 13},        /* ADC */
    {A3, GET_PIN(B, 1), "adc2", 5},         /* ADC */
    {A4, GET_PIN(C, 2), "adc2", 12},        /* ADC */
    {A5, GET_PIN(F, 11), "adc1", 2},        /* ADC */
};

#ifdef RTDUINO_USING_SPI
void switchToSPI(const char *bus_name)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    if(!rt_strcmp(bus_name, "spi1"))
    {
        __HAL_RCC_SPI1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_GPIOG_CLK_ENABLE();

        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5);
        HAL_GPIO_DeInit(GPIOG, GPIO_PIN_9);
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5);

        /**SPI1 GPIO Configuration
        PA5     ------> SPI1_SCK
        PG9     ------> SPI1_MISO
        PB5     ------> SPI1_MOSI
        */
        GPIO_InitStruct.Pin = GPIO_PIN_5;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        GPIO_InitStruct.Pin = GPIO_PIN_9;
        HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
        GPIO_InitStruct.Pin = GPIO_PIN_5;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        LOG_W("D11, D12 and D13 will switch from PWM to SPI");
    }
}
#endif /* RTDUINO_USING_SPI */
