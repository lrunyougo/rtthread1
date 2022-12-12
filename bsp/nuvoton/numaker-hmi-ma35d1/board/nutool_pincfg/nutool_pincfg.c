/****************************************************************************
 * @file     nutool_pincfg.c
 * @version  V1.24
 * @Date     2021/08/03-14:56:47
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:MA35D16A887C(BGA312)
Pin Configuration:
PinA2:I2C2_SCL
PinA3:EADC0_CH7
PinA4:EADC0_CH3
PinA5:RGMII1_TXCLK
PinA6:RGMII1_RXCLK
PinA7:RGMII1_RXCTL
PinA8:RGMII1_MDIO
PinA9:RGMII0_TXCLK
PinA10:RGMII0_RXD1
PinA11:RGMII0_RXCLK
PinA12:RGMII0_TXCTL
PinA13:I2S0_DI
PinA14:VCAP1_SFIELD
PinA15:VCAP1_HSYNC
PinA16:VCAP1_PIXCLK
PinA17:VCAP1_DATA5
PinB1:ADC0_CH4
PinB2:I2C1_SCL
PinB3:EADC0_CH5
PinB4:EADC0_CH4
PinB5:EADC0_CH1
PinB6:RGMII1_TXD3
PinB7:RGMII1_RXD0
PinB8:RGMII1_TXCTL
PinB9:RGMII0_TXD2
PinB10:RGMII0_RXD2
PinB11:RGMII0_RXCTL
PinB12:RGMII0_MDIO
PinB13:I2S0_BCLK
PinB14:VCAP1_VSYNC
PinB15:VCAP1_SCLK
PinB16:VCAP1_DATA7
PinB17:VCAP1_DATA0
PinB18:VCAP1_DATA2
PinC1:ADC0_CH7
PinC2:ADC0_CH5
PinC3:I2C2_SDA
PinC4:EADC0_CH2
PinC5:EADC0_CH0
PinC6:RGMII1_TXD2
PinC7:RGMII1_RXD2
PinC8:RGMII1_TXD0
PinC9:RGMII0_TXD3
PinC10:RGMII0_RXD0
PinC11:RGMII0_TXD1
PinC12:RGMII0_MDC
PinC13:I2S0_LRCK
PinC14:VCAP1_DATA8
PinC15:VCAP1_DATA6
PinC16:VCAP1_DATA4
PinC17:VCAP1_DATA1
PinC18:VCAP1_DATA3
PinD1:ADC0_CH6
PinD2:I2C1_SDA
PinD3:EADC0_CH6
PinD6:RGMII1_RXD3
PinD7:RGMII1_RXD1
PinD8:RGMII1_TXD1
PinD9:RGMII1_MDC
PinD10:RGMII0_RXD3
PinD11:RGMII0_TXD0
PinD12:I2S0_DO
PinD13:I2S0_MCLK
PinD14:VCAP1_DATA9
PinD16:UART10_nCTS
PinD17:UART10_TXD
PinD18:SD0_CLK
PinE1:HSUSBH_PWREN
PinE2:CAN1_RXD
PinE3:HSUSBH_OVC
PinE4:HSUSB0_VBUSVLD
PinE15:UART10_nRTS
PinE16:UART10_RXD
PinE17:SD0_WP
PinE18:SD0_DAT0
PinF3:CAN1_TXD
PinF4:NAND_DATA3
PinF16:UART14_RXD
PinF17:SD0_nCD
PinF18:SD0_CMD
PinG3:NAND_DATA0
PinG4:NAND_DATA5
PinG16:UART16_nRTS
PinG17:SD0_DAT3
PinG18:SD0_DAT1
PinH3:NAND_DATA1
PinH4:NAND_DATA7
PinH15:UART12_nRTS
PinH16:UART16_nCTS
PinH18:SD0_DAT2
PinJ3:NAND_DATA6
PinJ4:NAND_RDY
PinJ15:UART12_RXD
PinJ16:UART16_TXD
PinJ18:I2C4_SCL
PinK1:NAND_DATA2
PinK2:NAND_DATA4
PinK3:NAND_nRE
PinK4:NAND_ALE
PinK5:NAND_nWE
PinK16:UART16_RXD
PinK18:I2C4_SDA
PinL1:NAND_nCS
PinL2:NAND_CLE
PinL15:UART12_TXD
PinL16:I2C5_SDA
PinM5:NAND_nWP
PinM15:UART14_nRTS
PinM16:I2C5_SCL
PinM17:CAN3_RXD
PinN1:EPWM1_CH5
PinN2:I2C3_SDA
PinN17:CAN3_TXD
PinP1:I2C3_SCL
PinP7:VCAP0_SFIELD
PinP8:SD1_nCD
PinP9:SD1_WP
PinP15:UART14_TXD
PinR5:VCAP0_DATA9
PinR6:VCAP0_DATA7
PinR9:SD1_DAT1
PinR10:LCM_DEN
PinR11:LCM_DATA1
PinR12:LCM_DATA6
PinR13:LCM_DATA11
PinR14:LCM_DATA15
PinR16:LCM_DATA18
PinR17:LCM_DATA20
PinR18:LCM_DATA22
PinT1:UART0_TXD
PinT2:UART0_RXD
PinT4:VCAP0_HSYNC
PinT5:VCAP0_DATA1
PinT6:VCAP0_DATA5
PinT7:VCAP0_DATA6
PinT9:SD1_CMD
PinT10:LCM_VSYNC
PinT11:LCM_DATA0
PinT12:LCM_DATA5
PinT13:LCM_DATA10
PinT14:LCM_DATA14
PinT15:QSPI0_MISO1
PinT16:LCM_DATA16
PinT17:LCM_DATA17
PinT18:LCM_DATA23
PinU4:VCAP0_VSYNC
PinU5:VCAP0_DATA2
PinU6:VCAP0_DATA3
PinU7:VCAP0_DATA8
PinU8:SD1_DAT3
PinU9:SD1_DAT0
PinU10:LCM_HSYNC
PinU11:LCM_DATA7
PinU12:LCM_DATA4
PinU13:LCM_DATA9
PinU14:LCM_DATA13
PinU15:QSPI0_MISO0
PinU16:QSPI0_SS0
PinU17:LCM_DATA19
PinU18:LCM_DATA21
PinV3:VCAP0_SCLK
PinV4:VCAP0_PIXCLK
PinV5:VCAP0_DATA0
PinV6:VCAP0_DATA4
PinV8:SD1_CLK
PinV9:SD1_DAT2
PinV10:LCM_CLK
PinV11:LCM_DATA2
PinV12:LCM_DATA3
PinV13:LCM_DATA8
PinV14:LCM_DATA12
PinV15:QSPI0_MOSI1
PinV16:QSPI0_MOSI0
PinV17:QSPI0_CLK
********************/

#include "ma35d1.h"

void nutool_pincfg_init_adc0(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB15MFP_Msk | SYS_GPB_MFPH_PB14MFP_Msk | SYS_GPB_MFPH_PB13MFP_Msk | SYS_GPB_MFPH_PB12MFP_Msk);
    SYS->GPB_MFPH |= (SYS_GPB_MFPH_PB15MFP_ADC0_CH7 | SYS_GPB_MFPH_PB14MFP_ADC0_CH6 | SYS_GPB_MFPH_PB13MFP_ADC0_CH5 | SYS_GPB_MFPH_PB12MFP_ADC0_CH4);

    PB->MODE &= ~(GPIO_MODE_MODE12_Msk | GPIO_MODE_MODE13_Msk | GPIO_MODE_MODE14_Msk | GPIO_MODE_MODE15_Msk);
    GPIO_DISABLE_DIGITAL_PATH(PB, BIT12 | BIT13 | BIT14 | BIT15);

    return;
}

void nutool_pincfg_deinit_adc0(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB15MFP_Msk | SYS_GPB_MFPH_PB14MFP_Msk | SYS_GPB_MFPH_PB13MFP_Msk | SYS_GPB_MFPH_PB12MFP_Msk);

    return;
}

void nutool_pincfg_init_can1(void)
{
    SYS->GPL_MFPH &= ~(SYS_GPL_MFPH_PL15MFP_Msk | SYS_GPL_MFPH_PL14MFP_Msk);
    SYS->GPL_MFPH |= (SYS_GPL_MFPH_PL15MFP_CAN1_TXD | SYS_GPL_MFPH_PL14MFP_CAN1_RXD);

    return;
}

void nutool_pincfg_deinit_can1(void)
{
    SYS->GPL_MFPH &= ~(SYS_GPL_MFPH_PL15MFP_Msk | SYS_GPL_MFPH_PL14MFP_Msk);

    return;
}

void nutool_pincfg_init_can3(void)
{
    SYS->GPL_MFPH &= ~(SYS_GPL_MFPH_PL11MFP_Msk | SYS_GPL_MFPH_PL10MFP_Msk);
    SYS->GPL_MFPH |= (SYS_GPL_MFPH_PL11MFP_CAN3_TXD | SYS_GPL_MFPH_PL10MFP_CAN3_RXD);

    return;
}

void nutool_pincfg_deinit_can3(void)
{
    SYS->GPL_MFPH &= ~(SYS_GPL_MFPH_PL11MFP_Msk | SYS_GPL_MFPH_PL10MFP_Msk);

    return;
}

void nutool_pincfg_init_eadc0(void)
{
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB7MFP_Msk | SYS_GPB_MFPL_PB6MFP_Msk | SYS_GPB_MFPL_PB5MFP_Msk | SYS_GPB_MFPL_PB4MFP_Msk | SYS_GPB_MFPL_PB3MFP_Msk | SYS_GPB_MFPL_PB2MFP_Msk | SYS_GPB_MFPL_PB1MFP_Msk | SYS_GPB_MFPL_PB0MFP_Msk);
    SYS->GPB_MFPL |= (SYS_GPB_MFPL_PB7MFP_EADC0_CH7 | SYS_GPB_MFPL_PB6MFP_EADC0_CH6 | SYS_GPB_MFPL_PB5MFP_EADC0_CH5 | SYS_GPB_MFPL_PB4MFP_EADC0_CH4 | SYS_GPB_MFPL_PB3MFP_EADC0_CH3 | SYS_GPB_MFPL_PB2MFP_EADC0_CH2 | SYS_GPB_MFPL_PB1MFP_EADC0_CH1 | SYS_GPB_MFPL_PB0MFP_EADC0_CH0);

    GPIO_DISABLE_DIGITAL_PATH(PB, BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);

    return;
}

void nutool_pincfg_deinit_eadc0(void)
{
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB7MFP_Msk | SYS_GPB_MFPL_PB6MFP_Msk | SYS_GPB_MFPL_PB5MFP_Msk | SYS_GPB_MFPL_PB4MFP_Msk | SYS_GPB_MFPL_PB3MFP_Msk | SYS_GPB_MFPL_PB2MFP_Msk | SYS_GPB_MFPL_PB1MFP_Msk | SYS_GPB_MFPL_PB0MFP_Msk);

    return;
}

void nutool_pincfg_init_epwm1(void)
{
    SYS->GPM_MFPH &= ~(SYS_GPM_MFPH_PM13MFP_Msk);
    SYS->GPM_MFPH |= (SYS_GPM_MFPH_PM13MFP_EPWM1_CH5);

    SYS->GPK_MFPL &= ~(SYS_GPK_MFPL_PK5MFP_Msk);
    SYS->GPK_MFPL |= (SYS_GPK_MFPL_PK5MFP_EPWM1_CH1);

    return;
}

void nutool_pincfg_deinit_epwm1(void)
{
    SYS->GPM_MFPH &= ~(SYS_GPM_MFPH_PM13MFP_Msk);

    SYS->GPK_MFPL &= ~(SYS_GPK_MFPL_PK5MFP_Msk);
    return;
}

void nutool_pincfg_init_hsusb0(void)
{
    SYS->GPF_MFPH &= ~(SYS_GPF_MFPH_PF15MFP_Msk);
    SYS->GPF_MFPH |= (SYS_GPF_MFPH_PF15MFP_HSUSB0_VBUSVLD);

    return;
}

void nutool_pincfg_deinit_hsusb0(void)
{
    SYS->GPF_MFPH &= ~(SYS_GPF_MFPH_PF15MFP_Msk);

    return;
}

void nutool_pincfg_init_hsusbh(void)
{
    SYS->GPL_MFPH &= ~(SYS_GPL_MFPH_PL13MFP_Msk | SYS_GPL_MFPH_PL12MFP_Msk);
    SYS->GPL_MFPH |= (SYS_GPL_MFPH_PL13MFP_HSUSBH_OVC | SYS_GPL_MFPH_PL12MFP_HSUSBH_PWREN);

    return;
}

void nutool_pincfg_deinit_hsusbh(void)
{
    SYS->GPL_MFPH &= ~(SYS_GPL_MFPH_PL13MFP_Msk | SYS_GPL_MFPH_PL12MFP_Msk);

    return;
}

void nutool_pincfg_init_i2c1(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB11MFP_Msk | SYS_GPB_MFPH_PB10MFP_Msk);
    SYS->GPB_MFPH |= (SYS_GPB_MFPH_PB11MFP_I2C1_SCL | SYS_GPB_MFPH_PB10MFP_I2C1_SDA);

    return;
}

void nutool_pincfg_deinit_i2c1(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB11MFP_Msk | SYS_GPB_MFPH_PB10MFP_Msk);

    return;
}

void nutool_pincfg_init_i2c2(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB9MFP_Msk | SYS_GPB_MFPH_PB8MFP_Msk);
    SYS->GPB_MFPH |= (SYS_GPB_MFPH_PB9MFP_I2C2_SCL | SYS_GPB_MFPH_PB8MFP_I2C2_SDA);

    return;
}

void nutool_pincfg_deinit_i2c2(void)
{
    SYS->GPB_MFPH &= ~(SYS_GPB_MFPH_PB9MFP_Msk | SYS_GPB_MFPH_PB8MFP_Msk);

    return;
}

void nutool_pincfg_init_i2c3(void)
{
    SYS->GPM_MFPH &= ~(SYS_GPM_MFPH_PM15MFP_Msk | SYS_GPM_MFPH_PM14MFP_Msk);
    SYS->GPM_MFPH |= (SYS_GPM_MFPH_PM15MFP_I2C3_SCL | SYS_GPM_MFPH_PM14MFP_I2C3_SDA);

    return;
}

void nutool_pincfg_deinit_i2c3(void)
{
    SYS->GPM_MFPH &= ~(SYS_GPM_MFPH_PM15MFP_Msk | SYS_GPM_MFPH_PM14MFP_Msk);

    return;
}

void nutool_pincfg_init_i2c4(void)
{
    SYS->GPL_MFPL &= ~(SYS_GPL_MFPL_PL5MFP_Msk | SYS_GPL_MFPL_PL4MFP_Msk);
    SYS->GPL_MFPL |= (SYS_GPL_MFPL_PL5MFP_I2C4_SCL | SYS_GPL_MFPL_PL4MFP_I2C4_SDA);

    return;
}

void nutool_pincfg_deinit_i2c4(void)
{
    SYS->GPL_MFPL &= ~(SYS_GPL_MFPL_PL5MFP_Msk | SYS_GPL_MFPL_PL4MFP_Msk);

    return;
}

void nutool_pincfg_init_i2c5(void)
{
    SYS->GPJ_MFPH &= ~(SYS_GPJ_MFPH_PJ13MFP_Msk | SYS_GPJ_MFPH_PJ12MFP_Msk);
    SYS->GPJ_MFPH |= (SYS_GPJ_MFPH_PJ13MFP_I2C5_SCL | SYS_GPJ_MFPH_PJ12MFP_I2C5_SDA);

    return;
}

void nutool_pincfg_deinit_i2c5(void)
{
    SYS->GPJ_MFPH &= ~(SYS_GPJ_MFPH_PJ13MFP_Msk | SYS_GPJ_MFPH_PJ12MFP_Msk);

    return;
}

void nutool_pincfg_init_i2s0(void)
{
    SYS->GPK_MFPH &= ~(SYS_GPK_MFPH_PK15MFP_Msk | SYS_GPK_MFPH_PK14MFP_Msk | SYS_GPK_MFPH_PK13MFP_Msk | SYS_GPK_MFPH_PK12MFP_Msk);
    SYS->GPK_MFPH |= (SYS_GPK_MFPH_PK15MFP_I2S0_DO | SYS_GPK_MFPH_PK14MFP_I2S0_DI | SYS_GPK_MFPH_PK13MFP_I2S0_BCLK | SYS_GPK_MFPH_PK12MFP_I2S0_LRCK);
    SYS->GPN_MFPH &= ~(SYS_GPN_MFPH_PN15MFP_Msk);
    SYS->GPN_MFPH |= (SYS_GPN_MFPH_PN15MFP_I2S0_MCLK);

    return;
}

void nutool_pincfg_deinit_i2s0(void)
{
    SYS->GPK_MFPH &= ~(SYS_GPK_MFPH_PK15MFP_Msk | SYS_GPK_MFPH_PK14MFP_Msk | SYS_GPK_MFPH_PK13MFP_Msk | SYS_GPK_MFPH_PK12MFP_Msk);
    SYS->GPN_MFPH &= ~(SYS_GPN_MFPH_PN15MFP_Msk);

    return;
}

void nutool_pincfg_init_lcm(void)
{
    SYS->GPC_MFPH &= ~(SYS_GPC_MFPH_PC15MFP_Msk | SYS_GPC_MFPH_PC14MFP_Msk | SYS_GPC_MFPH_PC13MFP_Msk | SYS_GPC_MFPH_PC12MFP_Msk);
    SYS->GPC_MFPH |= (SYS_GPC_MFPH_PC15MFP_LCM_DATA19 | SYS_GPC_MFPH_PC14MFP_LCM_DATA18 | SYS_GPC_MFPH_PC13MFP_LCM_DATA17 | SYS_GPC_MFPH_PC12MFP_LCM_DATA16);
    SYS->GPG_MFPH &= ~(SYS_GPG_MFPH_PG10MFP_Msk | SYS_GPG_MFPH_PG9MFP_Msk | SYS_GPG_MFPH_PG8MFP_Msk);
    SYS->GPG_MFPH |= (SYS_GPG_MFPH_PG10MFP_LCM_CLK | SYS_GPG_MFPH_PG9MFP_LCM_HSYNC | SYS_GPG_MFPH_PG8MFP_LCM_VSYNC);
    SYS->GPH_MFPH &= ~(SYS_GPH_MFPH_PH15MFP_Msk | SYS_GPH_MFPH_PH14MFP_Msk | SYS_GPH_MFPH_PH13MFP_Msk | SYS_GPH_MFPH_PH12MFP_Msk);
    SYS->GPH_MFPH |= (SYS_GPH_MFPH_PH15MFP_LCM_DATA23 | SYS_GPH_MFPH_PH14MFP_LCM_DATA22 | SYS_GPH_MFPH_PH13MFP_LCM_DATA21 | SYS_GPH_MFPH_PH12MFP_LCM_DATA20);
    SYS->GPH_MFPL &= ~(SYS_GPH_MFPL_PH7MFP_Msk | SYS_GPH_MFPL_PH6MFP_Msk | SYS_GPH_MFPL_PH5MFP_Msk | SYS_GPH_MFPL_PH4MFP_Msk | SYS_GPH_MFPL_PH3MFP_Msk | SYS_GPH_MFPL_PH2MFP_Msk | SYS_GPH_MFPL_PH1MFP_Msk | SYS_GPH_MFPL_PH0MFP_Msk);
    SYS->GPH_MFPL |= (SYS_GPH_MFPL_PH7MFP_LCM_DATA15 | SYS_GPH_MFPL_PH6MFP_LCM_DATA14 | SYS_GPH_MFPL_PH5MFP_LCM_DATA13 | SYS_GPH_MFPL_PH4MFP_LCM_DATA12 | SYS_GPH_MFPL_PH3MFP_LCM_DATA11 | SYS_GPH_MFPL_PH2MFP_LCM_DATA10 | SYS_GPH_MFPL_PH1MFP_LCM_DATA9 | SYS_GPH_MFPL_PH0MFP_LCM_DATA8);
    SYS->GPI_MFPH &= ~(SYS_GPI_MFPH_PI15MFP_Msk | SYS_GPI_MFPH_PI14MFP_Msk | SYS_GPI_MFPH_PI13MFP_Msk | SYS_GPI_MFPH_PI12MFP_Msk | SYS_GPI_MFPH_PI11MFP_Msk | SYS_GPI_MFPH_PI10MFP_Msk | SYS_GPI_MFPH_PI9MFP_Msk | SYS_GPI_MFPH_PI8MFP_Msk);
    SYS->GPI_MFPH |= (SYS_GPI_MFPH_PI15MFP_LCM_DATA7 | SYS_GPI_MFPH_PI14MFP_LCM_DATA6 | SYS_GPI_MFPH_PI13MFP_LCM_DATA5 | SYS_GPI_MFPH_PI12MFP_LCM_DATA4 | SYS_GPI_MFPH_PI11MFP_LCM_DATA3 | SYS_GPI_MFPH_PI10MFP_LCM_DATA2 | SYS_GPI_MFPH_PI9MFP_LCM_DATA1 | SYS_GPI_MFPH_PI8MFP_LCM_DATA0);
    SYS->GPK_MFPL &= ~(SYS_GPK_MFPL_PK4MFP_Msk);
    SYS->GPK_MFPL |= (SYS_GPK_MFPL_PK4MFP_LCM_DEN);

    return;
}

void nutool_pincfg_deinit_lcm(void)
{
    SYS->GPC_MFPH &= ~(SYS_GPC_MFPH_PC15MFP_Msk | SYS_GPC_MFPH_PC14MFP_Msk | SYS_GPC_MFPH_PC13MFP_Msk | SYS_GPC_MFPH_PC12MFP_Msk);
    SYS->GPG_MFPH &= ~(SYS_GPG_MFPH_PG10MFP_Msk | SYS_GPG_MFPH_PG9MFP_Msk | SYS_GPG_MFPH_PG8MFP_Msk);
    SYS->GPH_MFPH &= ~(SYS_GPH_MFPH_PH15MFP_Msk | SYS_GPH_MFPH_PH14MFP_Msk | SYS_GPH_MFPH_PH13MFP_Msk | SYS_GPH_MFPH_PH12MFP_Msk);
    SYS->GPH_MFPL &= ~(SYS_GPH_MFPL_PH7MFP_Msk | SYS_GPH_MFPL_PH6MFP_Msk | SYS_GPH_MFPL_PH5MFP_Msk | SYS_GPH_MFPL_PH4MFP_Msk | SYS_GPH_MFPL_PH3MFP_Msk | SYS_GPH_MFPL_PH2MFP_Msk | SYS_GPH_MFPL_PH1MFP_Msk | SYS_GPH_MFPL_PH0MFP_Msk);
    SYS->GPI_MFPH &= ~(SYS_GPI_MFPH_PI15MFP_Msk | SYS_GPI_MFPH_PI14MFP_Msk | SYS_GPI_MFPH_PI13MFP_Msk | SYS_GPI_MFPH_PI12MFP_Msk | SYS_GPI_MFPH_PI11MFP_Msk | SYS_GPI_MFPH_PI10MFP_Msk | SYS_GPI_MFPH_PI9MFP_Msk | SYS_GPI_MFPH_PI8MFP_Msk);
    SYS->GPK_MFPL &= ~(SYS_GPK_MFPL_PK4MFP_Msk);

    return;
}

void nutool_pincfg_init_nand(void)
{
    SYS->GPA_MFPH &= ~(SYS_GPA_MFPH_PA14MFP_Msk | SYS_GPA_MFPH_PA13MFP_Msk | SYS_GPA_MFPH_PA12MFP_Msk | SYS_GPA_MFPH_PA11MFP_Msk | SYS_GPA_MFPH_PA10MFP_Msk | SYS_GPA_MFPH_PA9MFP_Msk | SYS_GPA_MFPH_PA8MFP_Msk);
    SYS->GPA_MFPH |= (SYS_GPA_MFPH_PA14MFP_NAND_nWP | SYS_GPA_MFPH_PA13MFP_NAND_nCS | SYS_GPA_MFPH_PA12MFP_NAND_ALE | SYS_GPA_MFPH_PA11MFP_NAND_CLE | SYS_GPA_MFPH_PA10MFP_NAND_nWE | SYS_GPA_MFPH_PA9MFP_NAND_nRE | SYS_GPA_MFPH_PA8MFP_NAND_RDY);
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA7MFP_Msk | SYS_GPA_MFPL_PA6MFP_Msk | SYS_GPA_MFPL_PA5MFP_Msk | SYS_GPA_MFPL_PA4MFP_Msk | SYS_GPA_MFPL_PA3MFP_Msk | SYS_GPA_MFPL_PA2MFP_Msk | SYS_GPA_MFPL_PA1MFP_Msk | SYS_GPA_MFPL_PA0MFP_Msk);
    SYS->GPA_MFPL |= (SYS_GPA_MFPL_PA7MFP_NAND_DATA7 | SYS_GPA_MFPL_PA6MFP_NAND_DATA6 | SYS_GPA_MFPL_PA5MFP_NAND_DATA5 | SYS_GPA_MFPL_PA4MFP_NAND_DATA4 | SYS_GPA_MFPL_PA3MFP_NAND_DATA3 | SYS_GPA_MFPL_PA2MFP_NAND_DATA2 | SYS_GPA_MFPL_PA1MFP_NAND_DATA1 | SYS_GPA_MFPL_PA0MFP_NAND_DATA0);

    return;
}

void nutool_pincfg_deinit_nand(void)
{
    SYS->GPA_MFPH &= ~(SYS_GPA_MFPH_PA14MFP_Msk | SYS_GPA_MFPH_PA13MFP_Msk | SYS_GPA_MFPH_PA12MFP_Msk | SYS_GPA_MFPH_PA11MFP_Msk | SYS_GPA_MFPH_PA10MFP_Msk | SYS_GPA_MFPH_PA9MFP_Msk | SYS_GPA_MFPH_PA8MFP_Msk);
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA7MFP_Msk | SYS_GPA_MFPL_PA6MFP_Msk | SYS_GPA_MFPL_PA5MFP_Msk | SYS_GPA_MFPL_PA4MFP_Msk | SYS_GPA_MFPL_PA3MFP_Msk | SYS_GPA_MFPL_PA2MFP_Msk | SYS_GPA_MFPL_PA1MFP_Msk | SYS_GPA_MFPL_PA0MFP_Msk);

    return;
}

void nutool_pincfg_init_qspi0(void)
{
    SYS->GPD_MFPL &= ~(SYS_GPD_MFPL_PD5MFP_Msk | SYS_GPD_MFPL_PD4MFP_Msk | SYS_GPD_MFPL_PD3MFP_Msk | SYS_GPD_MFPL_PD2MFP_Msk | SYS_GPD_MFPL_PD1MFP_Msk | SYS_GPD_MFPL_PD0MFP_Msk);
    SYS->GPD_MFPL |= (SYS_GPD_MFPL_PD5MFP_QSPI0_MISO1 | SYS_GPD_MFPL_PD4MFP_QSPI0_MOSI1 | SYS_GPD_MFPL_PD3MFP_QSPI0_MISO0 | SYS_GPD_MFPL_PD2MFP_QSPI0_MOSI0 | SYS_GPD_MFPL_PD1MFP_QSPI0_CLK | SYS_GPD_MFPL_PD0MFP_QSPI0_SS0);

    GPIO_SetDrivingCtl(PD, (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5), 4);

    return;
}

void nutool_pincfg_deinit_qspi0(void)
{
    SYS->GPD_MFPL &= ~(SYS_GPD_MFPL_PD5MFP_Msk | SYS_GPD_MFPL_PD4MFP_Msk | SYS_GPD_MFPL_PD3MFP_Msk | SYS_GPD_MFPL_PD2MFP_Msk | SYS_GPD_MFPL_PD1MFP_Msk | SYS_GPD_MFPL_PD0MFP_Msk);

    return;
}

void nutool_pincfg_init_rgmii0(void)
{
    SYS->GPE_MFPH &= ~(SYS_GPE_MFPH_PE13MFP_Msk | SYS_GPE_MFPH_PE12MFP_Msk | SYS_GPE_MFPH_PE11MFP_Msk | SYS_GPE_MFPH_PE10MFP_Msk | SYS_GPE_MFPH_PE9MFP_Msk | SYS_GPE_MFPH_PE8MFP_Msk);
    SYS->GPE_MFPH |= (SYS_GPE_MFPH_PE13MFP_RGMII0_TXD3 | SYS_GPE_MFPH_PE12MFP_RGMII0_TXD2 | SYS_GPE_MFPH_PE11MFP_RGMII0_TXCLK | SYS_GPE_MFPH_PE10MFP_RGMII0_RXD3 | SYS_GPE_MFPH_PE9MFP_RGMII0_RXD2 | SYS_GPE_MFPH_PE8MFP_RGMII0_RXD1);
    SYS->GPE_MFPL &= ~(SYS_GPE_MFPL_PE7MFP_Msk | SYS_GPE_MFPL_PE6MFP_Msk | SYS_GPE_MFPL_PE5MFP_Msk | SYS_GPE_MFPL_PE4MFP_Msk | SYS_GPE_MFPL_PE3MFP_Msk | SYS_GPE_MFPL_PE2MFP_Msk | SYS_GPE_MFPL_PE1MFP_Msk | SYS_GPE_MFPL_PE0MFP_Msk);
    SYS->GPE_MFPL |= (SYS_GPE_MFPL_PE7MFP_RGMII0_RXD0 | SYS_GPE_MFPL_PE6MFP_RGMII0_RXCTL | SYS_GPE_MFPL_PE5MFP_RGMII0_RXCLK | SYS_GPE_MFPL_PE4MFP_RGMII0_TXD1 | SYS_GPE_MFPL_PE3MFP_RGMII0_TXD0 | SYS_GPE_MFPL_PE2MFP_RGMII0_TXCTL | SYS_GPE_MFPL_PE1MFP_RGMII0_MDIO | SYS_GPE_MFPL_PE0MFP_RGMII0_MDC);

    /* RGMII Mode */
    SYS->GMAC0MISCR &= ~1;

    /* Set 1.8v */
    GPIO_SetPowerMode(PE, 0x3FFF, 0);

    GPIO_SetPullCtl(PE, 0x3FFF, GPIO_PUSEL_DISABLE);

    GPIO_SetSchmittTriggere(PE, 0x3FDF, 1);   //except clk

    GPIO_SetSlewCtl(PE, 0x3FFF, GPIO_SLEWCTL_NORMAL);

    GPIO_SetDrivingCtl(PE, 0x3FFF, 1);

    return;
}

void nutool_pincfg_deinit_rgmii0(void)
{
    SYS->GPE_MFPH &= ~(SYS_GPE_MFPH_PE13MFP_Msk | SYS_GPE_MFPH_PE12MFP_Msk | SYS_GPE_MFPH_PE11MFP_Msk | SYS_GPE_MFPH_PE10MFP_Msk | SYS_GPE_MFPH_PE9MFP_Msk | SYS_GPE_MFPH_PE8MFP_Msk);
    SYS->GPE_MFPL &= ~(SYS_GPE_MFPL_PE7MFP_Msk | SYS_GPE_MFPL_PE6MFP_Msk | SYS_GPE_MFPL_PE5MFP_Msk | SYS_GPE_MFPL_PE4MFP_Msk | SYS_GPE_MFPL_PE3MFP_Msk | SYS_GPE_MFPL_PE2MFP_Msk | SYS_GPE_MFPL_PE1MFP_Msk | SYS_GPE_MFPL_PE0MFP_Msk);

    return;
}

void nutool_pincfg_init_rgmii1(void)
{
    SYS->GPF_MFPH &= ~(SYS_GPF_MFPH_PF13MFP_Msk | SYS_GPF_MFPH_PF12MFP_Msk | SYS_GPF_MFPH_PF11MFP_Msk | SYS_GPF_MFPH_PF10MFP_Msk | SYS_GPF_MFPH_PF9MFP_Msk | SYS_GPF_MFPH_PF8MFP_Msk);
    SYS->GPF_MFPH |= (SYS_GPF_MFPH_PF13MFP_RGMII1_TXD3 | SYS_GPF_MFPH_PF12MFP_RGMII1_TXD2 | SYS_GPF_MFPH_PF11MFP_RGMII1_TXCLK | SYS_GPF_MFPH_PF10MFP_RGMII1_RXD3 | SYS_GPF_MFPH_PF9MFP_RGMII1_RXD2 | SYS_GPF_MFPH_PF8MFP_RGMII1_RXD1);
    SYS->GPF_MFPL &= ~(SYS_GPF_MFPL_PF7MFP_Msk | SYS_GPF_MFPL_PF6MFP_Msk | SYS_GPF_MFPL_PF5MFP_Msk | SYS_GPF_MFPL_PF4MFP_Msk | SYS_GPF_MFPL_PF3MFP_Msk | SYS_GPF_MFPL_PF2MFP_Msk | SYS_GPF_MFPL_PF1MFP_Msk | SYS_GPF_MFPL_PF0MFP_Msk);
    SYS->GPF_MFPL |= (SYS_GPF_MFPL_PF7MFP_RGMII1_RXD0 | SYS_GPF_MFPL_PF6MFP_RGMII1_RXCTL | SYS_GPF_MFPL_PF5MFP_RGMII1_RXCLK | SYS_GPF_MFPL_PF4MFP_RGMII1_TXD1 | SYS_GPF_MFPL_PF3MFP_RGMII1_TXD0 | SYS_GPF_MFPL_PF2MFP_RGMII1_TXCTL | SYS_GPF_MFPL_PF1MFP_RGMII1_MDIO | SYS_GPF_MFPL_PF0MFP_RGMII1_MDC);

    /* RGMII Mode */
    SYS->GMAC1MISCR &= ~1;

    /* Set 1.8v */
    GPIO_SetPowerMode(PF, 0x3FFF, 0);

    GPIO_SetPullCtl(PF, 0x3FFF, GPIO_PUSEL_DISABLE);

    GPIO_SetSchmittTriggere(PF, 0x3FDF, 1);   //except clk

    GPIO_SetSlewCtl(PF, 0x3FFF, GPIO_SLEWCTL_NORMAL);

    GPIO_SetDrivingCtl(PF, 0x3FFF, 1);

    return;
}

void nutool_pincfg_deinit_rgmii1(void)
{
    SYS->GPF_MFPH &= ~(SYS_GPF_MFPH_PF13MFP_Msk | SYS_GPF_MFPH_PF12MFP_Msk | SYS_GPF_MFPH_PF11MFP_Msk | SYS_GPF_MFPH_PF10MFP_Msk | SYS_GPF_MFPH_PF9MFP_Msk | SYS_GPF_MFPH_PF8MFP_Msk);
    SYS->GPF_MFPL &= ~(SYS_GPF_MFPL_PF7MFP_Msk | SYS_GPF_MFPL_PF6MFP_Msk | SYS_GPF_MFPL_PF5MFP_Msk | SYS_GPF_MFPL_PF4MFP_Msk | SYS_GPF_MFPL_PF3MFP_Msk | SYS_GPF_MFPL_PF2MFP_Msk | SYS_GPF_MFPL_PF1MFP_Msk | SYS_GPF_MFPL_PF0MFP_Msk);

    return;
}

void nutool_pincfg_init_sd0(void)
{
    SYS->GPC_MFPL &= ~(SYS_GPC_MFPL_PC7MFP_Msk | SYS_GPC_MFPL_PC6MFP_Msk | SYS_GPC_MFPL_PC5MFP_Msk | SYS_GPC_MFPL_PC4MFP_Msk | SYS_GPC_MFPL_PC3MFP_Msk | SYS_GPC_MFPL_PC2MFP_Msk | SYS_GPC_MFPL_PC1MFP_Msk | SYS_GPC_MFPL_PC0MFP_Msk);
    SYS->GPC_MFPL |= (SYS_GPC_MFPL_PC7MFP_SD0_WP | SYS_GPC_MFPL_PC6MFP_SD0_nCD | SYS_GPC_MFPL_PC5MFP_SD0_DAT3 | SYS_GPC_MFPL_PC4MFP_SD0_DAT2 | SYS_GPC_MFPL_PC3MFP_SD0_DAT1 | SYS_GPC_MFPL_PC2MFP_SD0_DAT0 | SYS_GPC_MFPL_PC1MFP_SD0_CLK | SYS_GPC_MFPL_PC0MFP_SD0_CMD);

    return;
}

void nutool_pincfg_deinit_sd0(void)
{
    SYS->GPC_MFPL &= ~(SYS_GPC_MFPL_PC7MFP_Msk | SYS_GPC_MFPL_PC6MFP_Msk | SYS_GPC_MFPL_PC5MFP_Msk | SYS_GPC_MFPL_PC4MFP_Msk | SYS_GPC_MFPL_PC3MFP_Msk | SYS_GPC_MFPL_PC2MFP_Msk | SYS_GPC_MFPL_PC1MFP_Msk | SYS_GPC_MFPL_PC0MFP_Msk);

    return;
}

void nutool_pincfg_init_sd1(void)
{
    SYS->GPJ_MFPH &= ~(SYS_GPJ_MFPH_PJ11MFP_Msk | SYS_GPJ_MFPH_PJ10MFP_Msk | SYS_GPJ_MFPH_PJ9MFP_Msk | SYS_GPJ_MFPH_PJ8MFP_Msk);
    SYS->GPJ_MFPH |= (SYS_GPJ_MFPH_PJ11MFP_SD1_DAT3 | SYS_GPJ_MFPH_PJ10MFP_SD1_DAT2 | SYS_GPJ_MFPH_PJ9MFP_SD1_DAT1 | SYS_GPJ_MFPH_PJ8MFP_SD1_DAT0);
    SYS->GPJ_MFPL &= ~(SYS_GPJ_MFPL_PJ7MFP_Msk | SYS_GPJ_MFPL_PJ6MFP_Msk | SYS_GPJ_MFPL_PJ5MFP_Msk | SYS_GPJ_MFPL_PJ4MFP_Msk);
    SYS->GPJ_MFPL |= (SYS_GPJ_MFPL_PJ7MFP_SD1_CLK | SYS_GPJ_MFPL_PJ6MFP_SD1_CMD | SYS_GPJ_MFPL_PJ5MFP_SD1_nCD | SYS_GPJ_MFPL_PJ4MFP_SD1_WP);
    SYS->GPJ_MFPL &= ~(SYS_GPJ_MFPL_PJ0MFP_Msk | SYS_GPJ_MFPL_PJ1MFP_Msk | SYS_GPJ_MFPL_PJ2MFP_Msk | SYS_GPJ_MFPL_PJ3MFP_Msk);
    SYS->GPJ_MFPL |= (SYS_GPJ_MFPL_PJ0MFP_eMMC1_DAT4 | SYS_GPJ_MFPL_PJ1MFP_eMMC1_DAT5 | SYS_GPJ_MFPL_PJ2MFP_eMMC1_DAT6 | SYS_GPJ_MFPL_PJ3MFP_eMMC1_DAT7);

    return;
}

void nutool_pincfg_deinit_sd1(void)
{
    SYS->GPJ_MFPH &= ~(SYS_GPJ_MFPH_PJ11MFP_Msk | SYS_GPJ_MFPH_PJ10MFP_Msk | SYS_GPJ_MFPH_PJ9MFP_Msk | SYS_GPJ_MFPH_PJ8MFP_Msk);
    SYS->GPJ_MFPL &= ~(SYS_GPJ_MFPL_PJ7MFP_Msk | SYS_GPJ_MFPL_PJ6MFP_Msk | SYS_GPJ_MFPL_PJ5MFP_Msk | SYS_GPJ_MFPL_PJ4MFP_Msk);
    SYS->GPJ_MFPL &= ~(SYS_GPJ_MFPL_PJ0MFP_Msk | SYS_GPJ_MFPL_PJ1MFP_Msk | SYS_GPJ_MFPL_PJ2MFP_Msk | SYS_GPJ_MFPL_PJ3MFP_Msk);

    return;
}

void nutool_pincfg_init_uart0(void)
{
    SYS->GPE_MFPH &= ~(SYS_GPE_MFPH_PE15MFP_Msk | SYS_GPE_MFPH_PE14MFP_Msk);
    SYS->GPE_MFPH |= (SYS_GPE_MFPH_PE15MFP_UART0_RXD | SYS_GPE_MFPH_PE14MFP_UART0_TXD);

    return;
}

void nutool_pincfg_deinit_uart0(void)
{
    SYS->GPE_MFPH &= ~(SYS_GPE_MFPH_PE15MFP_Msk | SYS_GPE_MFPH_PE14MFP_Msk);

    return;
}

void nutool_pincfg_init_uart11(void)
{
    SYS->GPL_MFPL &= ~(SYS_GPL_MFPL_PL0MFP_Msk | SYS_GPL_MFPL_PL1MFP_Msk | SYS_GPL_MFPL_PL2MFP_Msk | SYS_GPL_MFPL_PL3MFP_Msk);
    SYS->GPL_MFPL |= (SYS_GPL_MFPL_PL3MFP_UART11_TXD | SYS_GPL_MFPL_PL2MFP_UART11_RXD | SYS_GPL_MFPL_PL1MFP_UART11_nRTS | SYS_GPL_MFPL_PL0MFP_UART11_nCTS);

    return;
}

void nutool_pincfg_deinit_uart11(void)
{
    SYS->GPL_MFPL &= ~(SYS_GPL_MFPL_PL0MFP_Msk | SYS_GPL_MFPL_PL1MFP_Msk | SYS_GPL_MFPL_PL2MFP_Msk | SYS_GPL_MFPL_PL3MFP_Msk);

    return;
}

void nutool_pincfg_init_uart12(void)
{
    SYS->GPI_MFPL &= ~(SYS_GPI_MFPL_PI3MFP_Msk | SYS_GPI_MFPL_PI2MFP_Msk | SYS_GPI_MFPL_PI1MFP_Msk);
    SYS->GPI_MFPL |= (SYS_GPI_MFPL_PI3MFP_UART12_TXD | SYS_GPI_MFPL_PI2MFP_UART12_RXD | SYS_GPI_MFPL_PI1MFP_UART12_nRTS);

    return;
}

void nutool_pincfg_deinit_uart12(void)
{
    SYS->GPI_MFPL &= ~(SYS_GPI_MFPL_PI3MFP_Msk | SYS_GPI_MFPL_PI2MFP_Msk | SYS_GPI_MFPL_PI1MFP_Msk);

    return;
}

void nutool_pincfg_init_uart14(void)
{
    SYS->GPI_MFPL &= ~(SYS_GPI_MFPL_PI7MFP_Msk | SYS_GPI_MFPL_PI6MFP_Msk | SYS_GPI_MFPL_PI5MFP_Msk);
    SYS->GPI_MFPL |= (SYS_GPI_MFPL_PI7MFP_UART14_TXD | SYS_GPI_MFPL_PI6MFP_UART14_RXD | SYS_GPI_MFPL_PI5MFP_UART14_nRTS);

    return;
}

void nutool_pincfg_deinit_uart14(void)
{
    SYS->GPI_MFPL &= ~(SYS_GPI_MFPL_PI7MFP_Msk | SYS_GPI_MFPL_PI6MFP_Msk | SYS_GPI_MFPL_PI5MFP_Msk);

    return;
}

void nutool_pincfg_init_uart16(void)
{
    SYS->GPK_MFPL &= ~(SYS_GPK_MFPL_PK3MFP_Msk | SYS_GPK_MFPL_PK2MFP_Msk | SYS_GPK_MFPL_PK1MFP_Msk | SYS_GPK_MFPL_PK0MFP_Msk);
    SYS->GPK_MFPL |= (SYS_GPK_MFPL_PK3MFP_UART16_TXD | SYS_GPK_MFPL_PK2MFP_UART16_RXD | SYS_GPK_MFPL_PK1MFP_UART16_nRTS | SYS_GPK_MFPL_PK0MFP_UART16_nCTS);

    return;
}

void nutool_pincfg_deinit_uart16(void)
{
    SYS->GPK_MFPL &= ~(SYS_GPK_MFPL_PK3MFP_Msk | SYS_GPK_MFPL_PK2MFP_Msk | SYS_GPK_MFPL_PK1MFP_Msk | SYS_GPK_MFPL_PK0MFP_Msk);

    return;
}

void nutool_pincfg_init_vcap0(void)
{
    SYS->GPK_MFPH &= ~(SYS_GPK_MFPH_PK11MFP_Msk | SYS_GPK_MFPH_PK10MFP_Msk | SYS_GPK_MFPH_PK9MFP_Msk);
    SYS->GPK_MFPH |= (SYS_GPK_MFPH_PK11MFP_VCAP0_HSYNC | SYS_GPK_MFPH_PK10MFP_VCAP0_PIXCLK | SYS_GPK_MFPH_PK9MFP_VCAP0_SCLK);
    SYS->GPM_MFPH &= ~(SYS_GPM_MFPH_PM11MFP_Msk | SYS_GPM_MFPH_PM10MFP_Msk | SYS_GPM_MFPH_PM9MFP_Msk | SYS_GPM_MFPH_PM8MFP_Msk);
    SYS->GPM_MFPH |= (SYS_GPM_MFPH_PM11MFP_VCAP0_DATA9 | SYS_GPM_MFPH_PM10MFP_VCAP0_DATA8 | SYS_GPM_MFPH_PM9MFP_VCAP0_DATA7 | SYS_GPM_MFPH_PM8MFP_VCAP0_DATA6);
    SYS->GPM_MFPL &= ~(SYS_GPM_MFPL_PM7MFP_Msk | SYS_GPM_MFPL_PM6MFP_Msk | SYS_GPM_MFPL_PM5MFP_Msk | SYS_GPM_MFPL_PM4MFP_Msk | SYS_GPM_MFPL_PM3MFP_Msk | SYS_GPM_MFPL_PM2MFP_Msk | SYS_GPM_MFPL_PM1MFP_Msk | SYS_GPM_MFPL_PM0MFP_Msk);
    SYS->GPM_MFPL |= (SYS_GPM_MFPL_PM7MFP_VCAP0_DATA5 | SYS_GPM_MFPL_PM6MFP_VCAP0_DATA4 | SYS_GPM_MFPL_PM5MFP_VCAP0_DATA3 | SYS_GPM_MFPL_PM4MFP_VCAP0_DATA2 | SYS_GPM_MFPL_PM3MFP_VCAP0_DATA1 | SYS_GPM_MFPL_PM2MFP_VCAP0_DATA0 | SYS_GPM_MFPL_PM1MFP_VCAP0_SFIELD | SYS_GPM_MFPL_PM0MFP_VCAP0_VSYNC);

    return;
}

void nutool_pincfg_deinit_vcap0(void)
{
    SYS->GPK_MFPH &= ~(SYS_GPK_MFPH_PK11MFP_Msk | SYS_GPK_MFPH_PK10MFP_Msk | SYS_GPK_MFPH_PK9MFP_Msk);
    SYS->GPM_MFPH &= ~(SYS_GPM_MFPH_PM11MFP_Msk | SYS_GPM_MFPH_PM10MFP_Msk | SYS_GPM_MFPH_PM9MFP_Msk | SYS_GPM_MFPH_PM8MFP_Msk);
    SYS->GPM_MFPL &= ~(SYS_GPM_MFPL_PM7MFP_Msk | SYS_GPM_MFPL_PM6MFP_Msk | SYS_GPM_MFPL_PM5MFP_Msk | SYS_GPM_MFPL_PM4MFP_Msk | SYS_GPM_MFPL_PM3MFP_Msk | SYS_GPM_MFPL_PM2MFP_Msk | SYS_GPM_MFPL_PM1MFP_Msk | SYS_GPM_MFPL_PM0MFP_Msk);

    return;
}

void nutool_pincfg_init_vcap1(void)
{
    SYS->GPN_MFPH &= ~(SYS_GPN_MFPH_PN14MFP_Msk | SYS_GPN_MFPH_PN13MFP_Msk | SYS_GPN_MFPH_PN12MFP_Msk | SYS_GPN_MFPH_PN11MFP_Msk | SYS_GPN_MFPH_PN10MFP_Msk | SYS_GPN_MFPH_PN9MFP_Msk | SYS_GPN_MFPH_PN8MFP_Msk);
    SYS->GPN_MFPH |= (SYS_GPN_MFPH_PN14MFP_VCAP1_SFIELD | SYS_GPN_MFPH_PN13MFP_VCAP1_VSYNC | SYS_GPN_MFPH_PN12MFP_VCAP1_HSYNC | SYS_GPN_MFPH_PN11MFP_VCAP1_PIXCLK | SYS_GPN_MFPH_PN10MFP_VCAP1_SCLK | SYS_GPN_MFPH_PN9MFP_VCAP1_DATA9 | SYS_GPN_MFPH_PN8MFP_VCAP1_DATA8);
    SYS->GPN_MFPL &= ~(SYS_GPN_MFPL_PN7MFP_Msk | SYS_GPN_MFPL_PN6MFP_Msk | SYS_GPN_MFPL_PN5MFP_Msk | SYS_GPN_MFPL_PN4MFP_Msk | SYS_GPN_MFPL_PN3MFP_Msk | SYS_GPN_MFPL_PN2MFP_Msk | SYS_GPN_MFPL_PN1MFP_Msk | SYS_GPN_MFPL_PN0MFP_Msk);
    SYS->GPN_MFPL |= (SYS_GPN_MFPL_PN7MFP_VCAP1_DATA7 | SYS_GPN_MFPL_PN6MFP_VCAP1_DATA6 | SYS_GPN_MFPL_PN5MFP_VCAP1_DATA5 | SYS_GPN_MFPL_PN4MFP_VCAP1_DATA4 | SYS_GPN_MFPL_PN3MFP_VCAP1_DATA3 | SYS_GPN_MFPL_PN2MFP_VCAP1_DATA2 | SYS_GPN_MFPL_PN1MFP_VCAP1_DATA1 | SYS_GPN_MFPL_PN0MFP_VCAP1_DATA0);

    return;
}

void nutool_pincfg_deinit_vcap1(void)
{
    SYS->GPN_MFPH &= ~(SYS_GPN_MFPH_PN14MFP_Msk | SYS_GPN_MFPH_PN13MFP_Msk | SYS_GPN_MFPH_PN12MFP_Msk | SYS_GPN_MFPH_PN11MFP_Msk | SYS_GPN_MFPH_PN10MFP_Msk | SYS_GPN_MFPH_PN9MFP_Msk | SYS_GPN_MFPH_PN8MFP_Msk);
    SYS->GPN_MFPL &= ~(SYS_GPN_MFPL_PN7MFP_Msk | SYS_GPN_MFPL_PN6MFP_Msk | SYS_GPN_MFPL_PN5MFP_Msk | SYS_GPN_MFPL_PN4MFP_Msk | SYS_GPN_MFPL_PN3MFP_Msk | SYS_GPN_MFPL_PN2MFP_Msk | SYS_GPN_MFPL_PN1MFP_Msk | SYS_GPN_MFPL_PN0MFP_Msk);

    return;
}

void nutool_pincfg_init(void)
{
    //SYS->GPA_MFPH = 0x06666666UL;
    //SYS->GPA_MFPL = 0x66666666UL;
    //SYS->GPB_MFPH = 0x8888CC44UL;
    //SYS->GPB_MFPL = 0x88888888UL;
    //SYS->GPC_MFPH = 0x66662222UL;
    //SYS->GPC_MFPL = 0x66666666UL;
    //SYS->GPD_MFPH = 0x00000000UL;
    //SYS->GPD_MFPL = 0x00555555UL;
    //SYS->GPE_MFPH = 0x11888888UL;
    //SYS->GPE_MFPL = 0x88888888UL;
    //SYS->GPF_MFPH = 0x10888888UL;
    //SYS->GPF_MFPL = 0x88888888UL;
    //SYS->GPG_MFPH = 0x00000666UL;
    //SYS->GPG_MFPL = 0x00000000UL;
    //SYS->GPH_MFPH = 0x66660000UL;
    //SYS->GPH_MFPL = 0x66666666UL;
    //SYS->GPI_MFPH = 0x66666666UL;
    //SYS->GPI_MFPL = 0x22202220UL;
    //SYS->GPJ_MFPH = 0x00446666UL;
    //SYS->GPJ_MFPL = 0x66660000UL;
    //SYS->GPK_MFPH = 0x55556660UL;
    //SYS->GPK_MFPL = 0x00062222UL;
    //SYS->GPL_MFPH = 0x44993300UL;
    //SYS->GPL_MFPL = 0x00440000UL;
    //SYS->GPM_MFPH = 0x66106666UL;
    //SYS->GPM_MFPL = 0x66666666UL;
    //SYS->GPN_MFPH = 0x56666666UL;
    //SYS->GPN_MFPL = 0x66666666UL;

    nutool_pincfg_init_adc0();
    nutool_pincfg_init_can1();
    nutool_pincfg_init_can3();
    nutool_pincfg_init_eadc0();
    nutool_pincfg_init_epwm1();
    nutool_pincfg_init_hsusb0();
    nutool_pincfg_init_hsusbh();
    nutool_pincfg_init_i2c1();
    nutool_pincfg_init_i2c2();
    nutool_pincfg_init_i2c3();
    nutool_pincfg_init_i2c4();
    nutool_pincfg_init_i2c5();
    nutool_pincfg_init_i2s0();
    nutool_pincfg_init_lcm();
    nutool_pincfg_init_nand();
    nutool_pincfg_init_qspi0();
    nutool_pincfg_init_rgmii0();
    nutool_pincfg_init_rgmii1();
    nutool_pincfg_init_sd0();
    nutool_pincfg_init_sd1();
    nutool_pincfg_init_uart0();
    nutool_pincfg_init_uart11();
    nutool_pincfg_init_uart12();
    nutool_pincfg_init_uart14();
    nutool_pincfg_init_uart16();
    nutool_pincfg_init_vcap0();
    nutool_pincfg_init_vcap1();

    return;
}

void nutool_pincfg_deinit(void)
{
    nutool_pincfg_deinit_adc0();
    nutool_pincfg_deinit_can1();
    nutool_pincfg_deinit_can3();
    nutool_pincfg_deinit_eadc0();
    nutool_pincfg_deinit_epwm1();
    nutool_pincfg_deinit_hsusb0();
    nutool_pincfg_deinit_hsusbh();
    nutool_pincfg_deinit_i2c1();
    nutool_pincfg_deinit_i2c2();
    nutool_pincfg_deinit_i2c3();
    nutool_pincfg_deinit_i2c4();
    nutool_pincfg_deinit_i2c5();
    nutool_pincfg_deinit_i2s0();
    nutool_pincfg_deinit_lcm();
    nutool_pincfg_deinit_nand();
    nutool_pincfg_deinit_qspi0();
    nutool_pincfg_deinit_rgmii0();
    nutool_pincfg_deinit_rgmii1();
    nutool_pincfg_deinit_sd0();
    nutool_pincfg_deinit_sd1();
    nutool_pincfg_deinit_uart0();
    nutool_pincfg_deinit_uart11();
    nutool_pincfg_deinit_uart12();
    nutool_pincfg_deinit_uart14();
    nutool_pincfg_deinit_uart16();
    nutool_pincfg_deinit_vcap0();
    nutool_pincfg_deinit_vcap1();

    return;
}

/*** (C) COPYRIGHT 2013-2021 Nuvoton Technology Corp. ***/
