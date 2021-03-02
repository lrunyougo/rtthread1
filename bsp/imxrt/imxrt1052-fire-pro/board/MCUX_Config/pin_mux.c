/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: MIMXRT1052xxxxB
package_id: MIMXRT1052DVL6B
mcu_data: ksdk2_0
processor_version: 5.0.2
board: IMXRT1050-EVKB
pin_labels:
- {pin_num: G11, pin_signal: GPIO_AD_B0_03, label: BSP_BEEP}
- {pin_num: L13, pin_signal: GPIO_AD_B1_10, label: BSP_RS485_RE, identifier: CSI_D7}
- {pin_num: J13, pin_signal: GPIO_AD_B1_11, label: BSP_DS18B20, identifier: CSI_D6}
- {pin_num: K12, pin_signal: GPIO_AD_B1_05, label: BSP_AP3216C_INT, identifier: CSI_MCLK}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12}
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13}
  - {pin_num: L11, peripheral: LPUART2, signal: TX, pin_signal: GPIO_AD_B1_02}
  - {pin_num: M12, peripheral: LPUART2, signal: RX, pin_signal: GPIO_AD_B1_03}
  - {pin_num: D13, peripheral: LPUART5, signal: TX, pin_signal: GPIO_B1_12}
  - {pin_num: D14, peripheral: LPUART5, signal: RX, pin_signal: GPIO_B1_13}
  - {pin_num: H13, peripheral: PWM4, signal: 'A, 0', pin_signal: GPIO_AD_B1_08}
  - {pin_num: M13, peripheral: PWM4, signal: 'A, 1', pin_signal: GPIO_AD_B1_09}
  - {pin_num: G13, peripheral: PWM1, signal: 'A, 3', pin_signal: GPIO_AD_B0_10}
  - {pin_num: J11, peripheral: LPI2C1, signal: SCL, pin_signal: GPIO_AD_B1_00, software_input_on: Enable}
  - {pin_num: K11, peripheral: LPI2C1, signal: SDA, pin_signal: GPIO_AD_B1_01, software_input_on: Enable}
  - {pin_num: L13, peripheral: GPIO1, signal: 'gpio_io, 26', pin_signal: GPIO_AD_B1_10}
  - {pin_num: G11, peripheral: GPIO1, signal: 'gpio_io, 03', pin_signal: GPIO_AD_B0_03}
  - {pin_num: J13, peripheral: GPIO1, signal: 'gpio_io, 27', pin_signal: GPIO_AD_B1_11}
  - {pin_num: K12, peripheral: GPIO1, signal: 'gpio_io, 21', pin_signal: GPIO_AD_B1_05}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03U */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_03_GPIO1_IO03,        /* GPIO_AD_B0_03 is configured as GPIO1_IO03 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_10_FLEXPWM1_PWMA03,   /* GPIO_AD_B0_10 is configured as FLEXPWM1_PWMA03 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 is configured as LPUART1_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 is configured as LPUART1_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL,        /* GPIO_AD_B1_00 is configured as LPI2C1_SCL */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_B1_00 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA,        /* GPIO_AD_B1_01 is configured as LPI2C1_SDA */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_B1_01 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_02_LPUART2_TX,        /* GPIO_AD_B1_02 is configured as LPUART2_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_03_LPUART2_RX,        /* GPIO_AD_B1_03 is configured as LPUART2_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_05_GPIO1_IO21,        /* GPIO_AD_B1_05 is configured as GPIO1_IO21 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_08_FLEXPWM4_PWMA00,   /* GPIO_AD_B1_08 is configured as FLEXPWM4_PWMA00 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_09_FLEXPWM4_PWMA01,   /* GPIO_AD_B1_09 is configured as FLEXPWM4_PWMA01 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_10_GPIO1_IO26,        /* GPIO_AD_B1_10 is configured as GPIO1_IO26 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B1_11_GPIO1_IO27,        /* GPIO_AD_B1_11 is configured as GPIO1_IO27 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_B1_12_LPUART5_TX,           /* GPIO_B1_12 is configured as LPUART5_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_B1_13_LPUART5_RX,           /* GPIO_B1_13 is configured as LPUART5_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_14_FLEXCAN2_TX,       /* GPIO_AD_B0_14 is configured as FLEXCAN2_TX */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_B0_14 */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_15_FLEXCAN2_RX,       /* GPIO_AD_B0_15 is configured as FLEXCAN2_RX */
      1U);                                    /* Software Input On Field: Force input path of pad GPIO_AD_B0_15 */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_14_FLEXCAN2_TX,       /* GPIO_AD_B0_14 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_15_FLEXCAN2_RX,       /* GPIO_AD_B0_15 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
