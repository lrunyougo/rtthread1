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
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12}
  - {pin_num: M14, peripheral: LPSPI3, signal: SCK, pin_signal: GPIO_AD_B0_00}
  - {pin_num: M11, peripheral: LPSPI3, signal: SDI, pin_signal: GPIO_AD_B0_02}
  - {pin_num: H10, peripheral: LPSPI3, signal: SDO, pin_signal: GPIO_AD_B0_01}
  - {pin_num: M5, peripheral: LPUART4, signal: RX, pin_signal: GPIO_SD_B1_01}
  - {pin_num: L5, peripheral: LPUART4, signal: TX, pin_signal: GPIO_SD_B1_00}
  - {pin_num: F11, peripheral: GPIO1, signal: 'gpio_io, 04', pin_signal: GPIO_AD_B0_04}
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
      IOMUXC_GPIO_AD_B0_00_LPSPI3_SCK,        /* GPIO_AD_B0_00 is configured as LPSPI3_SCK */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_01_LPSPI3_SDO,        /* GPIO_AD_B0_01 is configured as LPSPI3_SDO */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_02_LPSPI3_SDI,        /* GPIO_AD_B0_02 is configured as LPSPI3_SDI */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 is configured as LPUART1_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 is configured as LPUART1_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_00_LPUART4_TX,        /* GPIO_SD_B1_00 is configured as LPUART4_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_SD_B1_01_LPUART4_RX,        /* GPIO_SD_B1_01 is configured as LPUART4_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
