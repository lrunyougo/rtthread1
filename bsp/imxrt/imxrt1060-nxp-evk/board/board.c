/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      first implementation
 */

#include <rthw.h>
#include <rtthread.h>
#include "board.h"
#include "pin_mux.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"

#ifdef BSP_USING_DMA
#include "fsl_dmamux.h"
#include "fsl_edma.h"
#endif

#define NVIC_PRIORITYGROUP_0         0x00000007U /*!< 0 bits for pre-emption priority
                                                      4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         0x00000006U /*!< 1 bits for pre-emption priority
                                                      3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         0x00000005U /*!< 2 bits for pre-emption priority
                                                      2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         0x00000004U /*!< 3 bits for pre-emption priority
                                                      1 bits for subpriority */
#define NVIC_PRIORITYGROUP_4         0x00000003U /*!< 4 bits for pre-emption priority
                                                      0 bits for subpriority */

/* MPU configuration. */
static void BOARD_ConfigMPU(void)
{
    /* Disable I cache and D cache */
    SCB_DisableICache();
    SCB_DisableDCache();

    /* Disable MPU */
    ARM_MPU_Disable();

    /* Region 0 setting */
    MPU->RBAR = ARM_MPU_RBAR(0, 0xC0000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_512MB);

    /* Region 1 setting */
    MPU->RBAR = ARM_MPU_RBAR(1, 0x80000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1GB);

    /* Region 2 setting */
    // spi flash: normal type, cacheable, no bufferable, no shareable
    MPU->RBAR = ARM_MPU_RBAR(2, 0x60000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 0, 0, ARM_MPU_REGION_SIZE_512MB);

    /* Region 3 setting */
    MPU->RBAR = ARM_MPU_RBAR(3, 0x00000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1GB);

    /* Region 4 setting */
    MPU->RBAR = ARM_MPU_RBAR(4, 0x00000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_128KB);

    /* Region 5 setting */
    MPU->RBAR = ARM_MPU_RBAR(5, 0x20000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_128KB);

    /* Region 6 setting */
    MPU->RBAR = ARM_MPU_RBAR(6, 0x20200000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_256KB);

#if defined(BSP_USING_SDRAM)
    /* Region 7 setting */
    MPU->RBAR = ARM_MPU_RBAR(7, 0x80000000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_32MB);

    /* Region 8 setting */
    MPU->RBAR = ARM_MPU_RBAR(8, 0x81E00000U);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 1, 1, 0, 0, 0, ARM_MPU_REGION_SIZE_2MB);
#endif

    /* Enable MPU */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

    /* Enable I cache and D cache */
    SCB_EnableDCache();
    SCB_EnableICache();
}


/* This is the timer interrupt service routine. */
void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

#ifdef BSP_USING_DMA
void imxrt_dma_init(void)
{
    edma_config_t config;

    DMAMUX_Init(DMAMUX);
    EDMA_GetDefaultConfig(&config);
    EDMA_Init(DMA0, &config);
}
#endif

#ifdef BSP_USING_LPUART
void imxrt_uart_pins_init(void)
{
#ifdef BSP_USING_LPUART1

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_12_LPUART1_TX, /* GPIO_AD_B0_12 is configured as LPUART1_TX */
        0U);                             /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_13_LPUART1_RX, /* GPIO_AD_B0_13 is configured as LPUART1_RX */
        0U);                             /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_12_LPUART1_TX, /* GPIO_AD_B0_12 PAD functional properties : */
        0x10B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                     Drive Strength Field: R0/6
                                                     Speed Field: medium(100MHz)
                                                     Open Drain Enable Field: Open Drain Disabled
                                                     Pull / Keep Enable Field: Pull/Keeper Enabled
                                                     Pull / Keep Select Field: Keeper
                                                     Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                     Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_13_LPUART1_RX, /* GPIO_AD_B0_13 PAD functional properties : */
        0x10B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                     Drive Strength Field: R0/6
                                                     Speed Field: medium(100MHz)
                                                     Open Drain Enable Field: Open Drain Disabled
                                                     Pull / Keep Enable Field: Pull/Keeper Enabled
                                                     Pull / Keep Select Field: Keeper
                                                     Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                     Hyst. Enable Field: Hysteresis Disabled */
#endif
#ifdef BSP_USING_LPUART2

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_02_LPUART2_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_03_LPUART2_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_02_LPUART2_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_03_LPUART2_RX,
        0x10B0u);

#endif
#ifdef BSP_USING_LPUART3

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_06_LPUART3_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_07_LPUART3_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_06_LPUART3_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_07_LPUART3_RX,
        0x10B0u);
#endif
#ifdef BSP_USING_LPUART4

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_00_LPUART4_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_01_LPUART4_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_00_LPUART4_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_01_LPUART4_RX,
        0x10B0u);
#endif
#ifdef BSP_USING_LPUART5

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_12_LPUART5_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_13_LPUART5_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_12_LPUART5_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_13_LPUART5_RX,
        0x10B0u);
#endif
#ifdef BSP_USING_LPUART6

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_02_LPUART6_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_03_LPUART6_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_02_LPUART6_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_03_LPUART6_RX,
        0x10B0u);
#endif
#ifdef BSP_USING_LPUART7

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_EMC_31_LPUART7_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_EMC_32_LPUART7_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_EMC_31_LPUART7_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_EMC_32_LPUART7_RX,
        0x10B0u);
#endif
#ifdef BSP_USING_LPUART8

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_10_LPUART8_TX,
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_11_LPUART8_RX,
        0U);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_10_LPUART8_TX,
        0x10B0u);
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_11_LPUART8_RX,
        0x10B0u);
#endif
}
#endif /* BSP_USING_LPUART */

#ifdef BSP_USING_I2C
static void imxrt_i2c_pins_init(void)
{
#ifdef BSP_USING_I2C1
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL, /* GPIO_AD_B1_00 is configured as LPI2C1_SCL */
        1U);                             /* Software Input On Field: Force input path of pad GPIO_AD_B1_00 */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA, /* GPIO_AD_B1_01 is configured as LPI2C1_SDA */
        1U);                             /* Software Input On Field: Force input path of pad GPIO_AD_B1_01 */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL, /* GPIO_AD_B1_00 PAD functional properties : */
        0xD8B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                    Drive Strength Field: R0/6
                                                    Speed Field: medium(100MHz)
                                                    Open Drain Enable Field: Open Drain Enabled
                                                    Pull / Keep Enable Field: Pull/Keeper Enabled
                                                    Pull / Keep Select Field: Keeper
                                                    Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                    Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA, /* GPIO_AD_B1_01 PAD functional properties : */
        0xD8B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                    Drive Strength Field: R0/6
                                                    Speed Field: medium(100MHz)
                                                    Open Drain Enable Field: Open Drain Enabled
                                                    Pull / Keep Enable Field: Pull/Keeper Enabled
                                                    Pull / Keep Select Field: Keeper
                                                    Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                    Hyst. Enable Field: Hysteresis Disabled */
#endif

#ifdef BSP_USING_I2C3
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_07_LPI2C3_SCL, /* GPIO_AD_B1_00 is configured as LPI2C1_SCL */
        1U);                             /* Software Input On Field: Force input path of pad GPIO_AD_B1_00 */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B1_06_LPI2C3_SDA, /* GPIO_AD_B1_01 is configured as LPI2C1_SDA */
        1U);                             /* Software Input On Field: Force input path of pad GPIO_AD_B1_01 */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_07_LPI2C3_SCL, /* GPIO_AD_B1_00 PAD functional properties : */
        0xD8B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                    Drive Strength Field: R0/6
                                                    Speed Field: medium(100MHz)
                                                    Open Drain Enable Field: Open Drain Enabled
                                                    Pull / Keep Enable Field: Pull/Keeper Enabled
                                                    Pull / Keep Select Field: Keeper
                                                    Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                    Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B1_06_LPI2C3_SDA, /* GPIO_AD_B1_01 PAD functional properties : */
        0xD8B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                    Drive Strength Field: R0/6
                                                    Speed Field: medium(100MHz)
                                                    Open Drain Enable Field: Open Drain Enabled
                                                    Pull / Keep Enable Field: Pull/Keeper Enabled
                                                    Pull / Keep Select Field: Keeper
                                                    Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                    Hyst. Enable Field: Hysteresis Disabled */
#endif

#ifdef BSP_USING_I2C4
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_12_LPI2C4_SCL, /* GPIO_AD_B1_00 is configured as LPI2C1_SCL */
        1U);                             /* Software Input On Field: Force input path of pad GPIO_AD_B1_00 */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_13_LPI2C4_SDA, /* GPIO_AD_B1_01 is configured as LPI2C1_SDA */
        1U);                             /* Software Input On Field: Force input path of pad GPIO_AD_B1_01 */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_12_LPI2C4_SCL, /* GPIO_AD_B1_00 PAD functional properties : */
        0xD8B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                    Drive Strength Field: R0/6
                                                    Speed Field: medium(100MHz)
                                                    Open Drain Enable Field: Open Drain Enabled
                                                    Pull / Keep Enable Field: Pull/Keeper Enabled
                                                    Pull / Keep Select Field: Keeper
                                                    Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                    Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_13_LPI2C4_SDA, /* GPIO_AD_B1_01 PAD functional properties : */
        0xD8B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                    Drive Strength Field: R0/6
                                                    Speed Field: medium(100MHz)
                                                    Open Drain Enable Field: Open Drain Enabled
                                                    Pull / Keep Enable Field: Pull/Keeper Enabled
                                                    Pull / Keep Select Field: Keeper
                                                    Pull Up / Down Config. Field: 22K Ohm Pull Up
                                                    Hyst. Enable Field: Hysteresis Disabled */
#endif
}
#endif /* BSP_USING_I2C */

#ifdef BSP_USING_LCD
static void imxrt_lcd_pins_init(void)
{
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_02_GPIO1_IO02, /* GPIO_AD_B0_02 is configured as GPIO1_IO02 */
        0U);                             /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_15_GPIO2_IO31, /* GPIO_B1_15 is configured as GPIO2_IO31 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_00_LCD_CLK, /* GPIO_B0_00 is configured as LCD_CLK */
        0U);                       /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_01_LCD_ENABLE, /* GPIO_B0_01 is configured as LCD_ENABLE */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_02_LCD_HSYNC, /* GPIO_B0_02 is configured as LCD_HSYNC */
        0U);                         /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_03_LCD_VSYNC, /* GPIO_B0_03 is configured as LCD_VSYNC */
        0U);                         /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_04_LCD_DATA00, /* GPIO_B0_04 is configured as LCD_DATA00 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_05_LCD_DATA01, /* GPIO_B0_05 is configured as LCD_DATA01 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_06_LCD_DATA02, /* GPIO_B0_06 is configured as LCD_DATA02 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_07_LCD_DATA03, /* GPIO_B0_07 is configured as LCD_DATA03 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_08_LCD_DATA04, /* GPIO_B0_08 is configured as LCD_DATA04 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_09_LCD_DATA05, /* GPIO_B0_09 is configured as LCD_DATA05 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_10_LCD_DATA06, /* GPIO_B0_10 is configured as LCD_DATA06 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_11_LCD_DATA07, /* GPIO_B0_11 is configured as LCD_DATA07 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_12_LCD_DATA08, /* GPIO_B0_12 is configured as LCD_DATA08 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_13_LCD_DATA09, /* GPIO_B0_13 is configured as LCD_DATA09 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_14_LCD_DATA10, /* GPIO_B0_14 is configured as LCD_DATA10 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B0_15_LCD_DATA11, /* GPIO_B0_15 is configured as LCD_DATA11 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_00_LCD_DATA12, /* GPIO_B1_00 is configured as LCD_DATA12 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_01_LCD_DATA13, /* GPIO_B1_01 is configured as LCD_DATA13 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_02_LCD_DATA14, /* GPIO_B1_02 is configured as LCD_DATA14 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_03_LCD_DATA15, /* GPIO_B1_03 is configured as LCD_DATA15 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_02_GPIO1_IO02, /* GPIO_AD_B0_02 PAD functional properties : */
        0x10B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_15_GPIO2_IO31, /* GPIO_B1_15 PAD functional properties : */
        0x10B0u);                     /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_12_LPUART1_TX, /* GPIO_AD_B0_12 PAD functional properties : */
        0x10B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_13_LPUART1_RX, /* GPIO_AD_B0_13 PAD functional properties : */
        0x10B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_00_LCD_CLK, /* GPIO_B0_00 PAD functional properties : */
        0x01B0B0u);                /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_01_LCD_ENABLE, /* GPIO_B0_01 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_02_LCD_HSYNC, /* GPIO_B0_02 PAD functional properties : */
        0x01B0B0u);                  /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_03_LCD_VSYNC, /* GPIO_B0_03 PAD functional properties : */
        0x01B0B0u);                  /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_04_LCD_DATA00, /* GPIO_B0_04 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_05_LCD_DATA01, /* GPIO_B0_05 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_06_LCD_DATA02, /* GPIO_B0_06 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_07_LCD_DATA03, /* GPIO_B0_07 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_08_LCD_DATA04, /* GPIO_B0_08 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_09_LCD_DATA05, /* GPIO_B0_09 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_10_LCD_DATA06, /* GPIO_B0_10 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_11_LCD_DATA07, /* GPIO_B0_11 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_12_LCD_DATA08, /* GPIO_B0_12 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_13_LCD_DATA09, /* GPIO_B0_13 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_14_LCD_DATA10, /* GPIO_B0_14 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B0_15_LCD_DATA11, /* GPIO_B0_15 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_00_LCD_DATA12, /* GPIO_B1_00 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_01_LCD_DATA13, /* GPIO_B1_01 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_02_LCD_DATA14, /* GPIO_B1_02 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_03_LCD_DATA15, /* GPIO_B1_03 PAD functional properties : */
        0x01B0B0u);                   /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Enabled */
}

#endif

#ifdef BSP_USING_ETH
void imxrt_enet_pins_init(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc); /* iomuxc clock (iomuxc_clk_enable): 0x03u */

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, /* GPIO_AD_B0_09 is configured as GPIO1_IO09 */
        0U);                             /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_10_GPIO1_IO10, /* GPIO_AD_B0_10 is configured as GPIO1_IO10 */
        0U);
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_04_ENET_RX_DATA00, /* GPIO_B1_04 is configured as ENET_RX_DATA00 */
        0U);                              /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_05_ENET_RX_DATA01, /* GPIO_B1_05 is configured as ENET_RX_DATA01 */
        0U);                              /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_06_ENET_RX_EN, /* GPIO_B1_06 is configured as ENET_RX_EN */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_07_ENET_TX_DATA00, /* GPIO_B1_07 is configured as ENET_TX_DATA00 */
        0U);                              /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_08_ENET_TX_DATA01, /* GPIO_B1_08 is configured as ENET_TX_DATA01 */
        0U);                              /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_09_ENET_TX_EN, /* GPIO_B1_09 is configured as ENET_TX_EN */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_10_ENET_REF_CLK, /* GPIO_B1_10 is configured as ENET_REF_CLK */
        1U);                            /* Software Input On Field: Force input path of pad GPIO_B1_10 */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_B1_11_ENET_RX_ER, /* GPIO_B1_11 is configured as ENET_RX_ER */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_EMC_40_ENET_MDC, /* GPIO_EMC_40 is configured as ENET_MDC */
        0U);                         /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_EMC_41_ENET_MDIO, /* GPIO_EMC_41 is configured as ENET_MDIO */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, /* GPIO_AD_B0_09 PAD functional properties : */
        0xB0A9u);                        /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_10_GPIO1_IO10, /* GPIO_AD_B0_10 PAD functional properties : */
        0xB0A9u);                        /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_04_ENET_RX_DATA00, /* GPIO_B1_04 PAD functional properties : */
        0xB0E9u);                         /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_05_ENET_RX_DATA01, /* GPIO_B1_05 PAD functional properties : */
        0xB0E9u);                         /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_06_ENET_RX_EN, /* GPIO_B1_06 PAD functional properties : */
        0xB0E9u);                     /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_07_ENET_TX_DATA00, /* GPIO_B1_07 PAD functional properties : */
        0xB0E9u);                         /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_08_ENET_TX_DATA01, /* GPIO_B1_08 PAD functional properties : */
        0xB0E9u);                         /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_09_ENET_TX_EN, /* GPIO_B1_09 PAD functional properties : */
        0xB0E9u);                     /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_10_ENET_REF_CLK, /* GPIO_B1_10 PAD functional properties : */
        0x31u);                         /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: low(50MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_B1_11_ENET_RX_ER, /* GPIO_B1_11 PAD functional properties : */
        0xB0E9u);                     /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_EMC_40_ENET_MDC, /* GPIO_EMC_40 PAD functional properties : */
        0xB0E9u);                    /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_EMC_41_ENET_MDIO, /* GPIO_EMC_41 PAD functional properties : */
        0xB829u);                     /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/5
                                                 Speed Field: low(50MHz)
                                                 Open Drain Enable Field: Open Drain Enabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Pull
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Up
                                                 Hyst. Enable Field: Hysteresis Disabled */
}

#ifndef BSP_USING_PHY
void imxrt_enet_phy_reset_by_gpio(void)
{
    gpio_pin_config_t gpio_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};

    GPIO_PinInit(GPIO1, 9, &gpio_config);
    GPIO_PinInit(GPIO1, 10, &gpio_config);
    /* pull up the ENET_INT before RESET. */
    GPIO_WritePinOutput(GPIO1, 10, 1);
    GPIO_WritePinOutput(GPIO1, 9, 0);
    rt_thread_delay(100);
    GPIO_WritePinOutput(GPIO1, 9, 1);
}
#endif /* BSP_USING_PHY */

#endif /* BSP_USING_ETH */

#ifdef BSP_USING_PHY
void imxrt_phy_pins_init( void )
{
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, /* GPIO_AD_B0_09 is configured as GPIO1_IO09 */
        0U);                             /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, /* GPIO_B0_00 PAD functional properties : */
        0x10B0u);                        /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}
#endif /* BSP_USING_PHY */

rt_uint8_t heap_buf[1024 * 16];

/**
 * This function will initial rt1050 board.
 */
void rt_hw_board_init()
{
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();

    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);

#ifdef BSP_USING_LPUART
    imxrt_uart_pins_init();
#endif

#ifdef BSP_USING_I2C
    imxrt_i2c_pins_init();
#endif

#ifdef BSP_USING_ETH
    imxrt_enet_pins_init();
#endif

#ifdef BSP_USING_PHY
    imxrt_phy_pins_init();
#endif

#ifdef BSP_USING_LCD
    imxrt_lcd_pins_init();
#endif

#ifdef BSP_USING_DMA
    imxrt_dma_init();
#endif

#ifdef RT_USING_HEAP
    rt_system_heap_init((void *)HEAP_BEGIN, (void *)HEAP_END);
#endif

#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#if defined(RT_USING_CONSOLE) && defined(RT_USING_DEVICE)
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif
}
