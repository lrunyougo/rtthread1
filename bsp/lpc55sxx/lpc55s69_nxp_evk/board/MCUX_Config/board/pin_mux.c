/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 6.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '92', peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI_DATA/SD1_D2/CTIMER2_MAT3/SCT0_OUT8/CMP0_OUT/PLU_OUT2/SECURE_GPIO0_29,
    mode: inactive, slew_rate: standard, invert: disabled, open_drain: disabled}
  - {pin_num: '94', peripheral: FLEXCOMM0, signal: TXD_SCL_MISO_WS, pin_signal: PIO0_30/FC0_TXD_SCL_MISO_WS/SD1_D3/CTIMER0_MAT0/SCT0_OUT9/SECURE_GPIO0_30, mode: inactive,
    slew_rate: standard, invert: disabled, open_drain: disabled}
  - {pin_num: '20', peripheral: ADC0, signal: 'CH, 0', pin_signal: PIO0_23/MCLK/CTIMER1_MAT2/CTIMER3_MAT3/SCT0_OUT4/FC0_CTS_SDA_SSEL0/SD1_D1/SECURE_GPIO0_23/ADC0_0}
  - {pin_num: '8', peripheral: SDIF, signal: SD0_CARD_DET, pin_signal: PIO0_17/FC4_SSEL2/SD0_CARD_DET_N/SCT_GPI7/SCT0_OUT0/SD0_CARD_INT_N/PLU_IN2/SECURE_GPIO0_17}
  - {pin_num: '70', peripheral: SDIF, signal: 'SD0_D, 0', pin_signal: PIO0_24/FC0_RXD_SDA_MOSI_DATA/SD0_D0/CT_INP8/SCT_GPI0/SECURE_GPIO0_24}
  - {pin_num: '79', peripheral: SDIF, signal: 'SD0_D, 1', pin_signal: PIO0_25/FC0_TXD_SCL_MISO_WS/SD0_D1/CT_INP9/SCT_GPI1/SECURE_GPIO0_25}
  - {pin_num: '23', peripheral: SDIF, signal: 'SD0_D, 2', pin_signal: PIO0_31/FC0_CTS_SDA_SSEL0/SD0_D2/CTIMER0_MAT1/SCT0_OUT3/SECURE_GPIO0_31/ADC0_3}
  - {pin_num: '6', peripheral: SDIF, signal: SD0_CLK, pin_signal: PIO0_7/FC3_RTS_SCL_SSEL1/SD0_CLK/FC5_SCK/FC1_SCK/SECURE_GPIO0_7}
  - {pin_num: '26', peripheral: SDIF, signal: SD0_CMD, pin_signal: PIO0_8/FC3_SSEL3/SD0_CMD/FC5_RXD_SDA_MOSI_DATA/SWO/SECURE_GPIO0_8}
  - {pin_num: '55', peripheral: SDIF, signal: SD0_POW_EN, pin_signal: PIO0_9/FC3_SSEL2/SD0_POW_EN/FC5_TXD_SCL_MISO_WS/SECURE_GPIO0_9/ACMP0_B}
  - {pin_num: '11', peripheral: SDIF, signal: 'SD0_D, 3', pin_signal: PIO1_0/FC0_RTS_SCL_SSEL1/SD0_D3/CT_INP2/SCT_GPI4/PLU_OUT3/ADC0_11}
  - {pin_num: '61', peripheral: FLEXCOMM8, signal: HS_SPI_SCK, pin_signal: PIO1_2/CTIMER0_MAT3/SCT_GPI6/HS_SPI_SCK/USB1_PORTPWRN/PLU_OUT5}
  - {pin_num: '62', peripheral: FLEXCOMM8, signal: HS_SPI_MISO, pin_signal: PIO1_3/SCT0_OUT4/HS_SPI_MISO/USB0_PORTPWRN/PLU_OUT6}
  - {pin_num: '60', peripheral: FLEXCOMM8, signal: HS_SPI_MOSI, pin_signal: PIO0_26/FC2_RXD_SDA_MOSI_DATA/CLKOUT/CT_INP14/SCT0_OUT5/USB0_IDVALUE/FC0_SCK/HS_SPI_MOSI/SECURE_GPIO0_26}
  - {pin_num: '9', peripheral: GPIO, signal: 'PIO1, 7', pin_signal: PIO1_7/FC0_RTS_SCL_SSEL1/SD0_D1/CTIMER2_MAT2/SCT_GPI4}
  - {pin_num: '5', peripheral: GPIO, signal: 'PIO1, 6', pin_signal: PIO1_6/FC0_TXD_SCL_MISO_WS/SD0_D3/CTIMER2_MAT1/SCT_GPI3}
  - {pin_num: '1', peripheral: CTIMER2, signal: 'MATCH, 1', pin_signal: PIO1_4/FC0_SCK/SD0_D0/CTIMER2_MAT1/SCT0_OUT0/FREQME_GPIO_CLK_A}
  - {pin_num: '27', peripheral: FLEXCOMM2, signal: TXD_SCL_MISO_WS, pin_signal: PIO0_27/FC2_TXD_SCL_MISO_WS/CTIMER3_MAT2/SCT0_OUT6/FC7_RXD_SDA_MOSI_DATA/PLU_OUT0/SECURE_GPIO0_27}
  - {pin_num: '3', peripheral: FLEXCOMM2, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO1_24/FC2_RXD_SDA_MOSI_DATA/SCT0_OUT1/SD1_D1/FC3_SSEL3/PLU_OUT6}
  - {pin_num: '4', peripheral: FLEXCOMM4, signal: TXD_SCL_MISO_WS, pin_signal: PIO1_20/FC7_RTS_SCL_SSEL1/CT_INP14/FC4_TXD_SCL_MISO_WS/PLU_OUT2}
  - {pin_num: '30', peripheral: FLEXCOMM4, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO1_21/FC7_CTS_SDA_SSEL0/CTIMER3_MAT2/FC4_RXD_SDA_MOSI_DATA/PLU_OUT3}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M33 (Core #0) */
void BOARD_InitPins(void)
{
    /* Enables the clock for the I/O controller.: Enable Clock. */
    CLOCK_EnableClock(kCLOCK_Iocon);

    IOCON->PIO[0][13] = ((IOCON->PIO[0][13] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT013 (pin 71) is configured as FC1_RXD_SDA_MOSI_DATA. */
                         | IOCON_PIO_FUNC(PIO0_13_FUNC_ALT5)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_13_DIGIMODE_DIGITAL));

    IOCON->PIO[0][14] = ((IOCON->PIO[0][14] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT014 (pin 72) is configured as FC1_TXD_SCL_MISO_WS. */
                         | IOCON_PIO_FUNC(PIO0_14_FUNC_ALT6)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_14_DIGIMODE_DIGITAL));

    IOCON->PIO[0][17] = ((IOCON->PIO[0][17] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT017 (pin 8) is configured as SD0_CARD_DET_N. */
                         | IOCON_PIO_FUNC(PIO0_17_FUNC_ALT2)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_17_DIGIMODE_DIGITAL));

    IOCON->PIO[0][23] = ((IOCON->PIO[0][23] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT023 (pin 20) is configured as ADC0_0. */
                         | IOCON_PIO_FUNC(PIO0_23_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_23_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Analog mode, digital input is disabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_23_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * Usable only if DIGIMODE = 0b0: Analog switch is closed. */
                         | IOCON_PIO_ASW(PIO0_23_ASW_ENABLE));

    IOCON->PIO[0][24] = ((IOCON->PIO[0][24] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT024 (pin 70) is configured as SD0_D0. */
                         | IOCON_PIO_FUNC(PIO0_24_FUNC_ALT2)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_24_DIGIMODE_DIGITAL));

    IOCON->PIO[0][25] = ((IOCON->PIO[0][25] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT025 (pin 79) is configured as SD0_D1. */
                         | IOCON_PIO_FUNC(PIO0_25_FUNC_ALT2)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_25_DIGIMODE_DIGITAL));

    IOCON->PIO[0][26] = ((IOCON->PIO[0][26] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT026 (pin 60) is configured as HS_SPI_MOSI. */
                         | IOCON_PIO_FUNC(0x09u)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_26_DIGIMODE_DIGITAL));

    IOCON->PIO[0][27] = ((IOCON->PIO[0][27] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT027 (pin 27) is configured as FC2_TXD_SCL_MISO_WS. */
                         | IOCON_PIO_FUNC(PIO0_27_FUNC_ALT1)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_27_DIGIMODE_DIGITAL));

    const uint32_t port0_pin29_config = (/* Pin is configured as FC0_RXD_SDA_MOSI_DATA */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: 92) is configured as FC0_RXD_SDA_MOSI_DATA */
    IOCON_PinMuxSet(IOCON, 0U, 29U, port0_pin29_config);

    const uint32_t port0_pin30_config = (/* Pin is configured as FC0_TXD_SCL_MISO_WS */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN30 (coords: 94) is configured as FC0_TXD_SCL_MISO_WS */
    IOCON_PinMuxSet(IOCON, 0U, 30U, port0_pin30_config);

    IOCON->PIO[0][31] = ((IOCON->PIO[0][31] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT031 (pin 23) is configured as SD0_D2. */
                         | IOCON_PIO_FUNC(PIO0_31_FUNC_ALT2)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_31_DIGIMODE_DIGITAL));

    IOCON->PIO[0][7] = ((IOCON->PIO[0][7] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT07 (pin 6) is configured as SD0_CLK. */
                        | IOCON_PIO_FUNC(PIO0_7_FUNC_ALT2)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_7_DIGIMODE_DIGITAL));

    IOCON->PIO[0][8] = ((IOCON->PIO[0][8] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT08 (pin 26) is configured as SD0_CMD. */
                        | IOCON_PIO_FUNC(PIO0_8_FUNC_ALT2)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_8_DIGIMODE_DIGITAL));

    IOCON->PIO[0][9] = ((IOCON->PIO[0][9] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT09 (pin 55) is configured as SD0_POW_EN. */
                        | IOCON_PIO_FUNC(PIO0_9_FUNC_ALT2)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_9_DIGIMODE_DIGITAL));

    IOCON->PIO[1][0] = ((IOCON->PIO[1][0] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT10 (pin 11) is configured as SD0_D3. */
                        | IOCON_PIO_FUNC(PIO1_0_FUNC_ALT2)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_0_DIGIMODE_DIGITAL));

    IOCON->PIO[1][2] = ((IOCON->PIO[1][2] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT12 (pin 61) is configured as HS_SPI_SCK. */
                        | IOCON_PIO_FUNC(PIO1_2_FUNC_ALT6)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_2_DIGIMODE_DIGITAL));

    IOCON->PIO[1][24] = ((IOCON->PIO[1][24] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT124 (pin 3) is configured as FC2_RXD_SDA_MOSI_DATA. */
                         | IOCON_PIO_FUNC(PIO1_24_FUNC_ALT1)

                         /* Select Digital mode.
                          * : Digital mode, digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO1_24_DIGIMODE_DIGITAL));

    IOCON->PIO[1][3] = ((IOCON->PIO[1][3] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT13 (pin 62) is configured as HS_SPI_MISO. */
                        | IOCON_PIO_FUNC(PIO1_3_FUNC_ALT6)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_3_DIGIMODE_DIGITAL));

    IOCON->PIO[1][4] = ((IOCON->PIO[1][4] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT14 (pin 1) is configured as CTIMER2_MAT1. */
                        | IOCON_PIO_FUNC(PIO1_4_FUNC_ALT3)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_4_DIGIMODE_DIGITAL));

    IOCON->PIO[1][6] = ((IOCON->PIO[1][6] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT16 (pin 5) is configured as PIO1_6. */
                        | IOCON_PIO_FUNC(PIO1_6_FUNC_ALT0)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_6_DIGIMODE_DIGITAL));

    IOCON->PIO[1][7] = ((IOCON->PIO[1][7] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT17 (pin 9) is configured as CTIMER2_MAT2. */
                        | IOCON_PIO_FUNC(PIO1_7_FUNC_ALT3)

                        /* Select Digital mode.
                         * : Digital mode, digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_7_DIGIMODE_DIGITAL));

    IOCON->PIO[1][10] = ((IOCON->PIO[1][10] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT110 (pin 40) is configured as CTIMER1_MAT0. */
                        | IOCON_PIO_FUNC(PIO1_10_FUNC_ALT3)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_10_DIGIMODE_DIGITAL));

    /* I2C4 */
    IOCON_PinMuxSet(IOCON, 1U, 20, 5 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI);
    IOCON_PinMuxSet(IOCON, 1U, 21, 5 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI);

    /* FC3 SPI */
    IOCON_PinMuxSet(IOCON, 0, 2, 1 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* MISO */
    IOCON_PinMuxSet(IOCON, 0, 3, 1 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* MOSI */
   // IOCON_PinMuxSet(IOCON, 0, 4, 8 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* CS */
    IOCON_PinMuxSet(IOCON, 0, 6, 1 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* SCK */


    /* FC8 SPI */
    IOCON_PinMuxSet(IOCON, 1, 3,  6 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* MISO */
    IOCON_PinMuxSet(IOCON, 0, 26, 9 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* MOSI */
    IOCON_PinMuxSet(IOCON, 1, 2,  6 | IOCON_PIO_MODE_INACT | IOCON_PIO_SLEW_STANDARD | IOCON_PIO_INV_DI | IOCON_PIO_DIGITAL_EN | IOCON_PIO_OPENDRAIN_DI); /* SCK */
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
