/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// File: gpio5_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.4.0.0
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for gpio5 module.
void gpio5_iomux_config(void)
{
    // Config gpio5.GPIO5_IO04 to pad EIM_ADDR24(F25)
    // EIMD18_I2C3_STEER
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR24_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_WR(0x0000B0B1);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR24(0x020E0130)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [3:0] - MUX Mode Select Field Reset: ALT0
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: eim signal: EIM_ADDR24
    //     ALT1 (1) - Select instance: ipu1 signal: IPU1_DISP1_DATA19
    //     ALT2 (2) - Select instance: ipu1 signal: IPU1_CSI1_DATA19
    //     ALT4 (4) - Select instance: ipu1 signal: IPU1_SISG2
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO04
    //     ALT7 (7) - Select instance: src signal: SRC_BOOT_CFG24
    //     ALT8 (8) - Select instance: epdc signal: EPDC_GDRL
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR24_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR24_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_ADDR24_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24(0x020E0500)
    //   HYS [16] - Hysteresis Enable Field Reset: DISABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     RESERVED0 (0) - Reserved
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: FAST
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_HYS_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_ADDR24_SRE_V(FAST));

    // Config gpio5.GPIO5_IO14 to pad DISP0_DATA20(U22)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA20_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA20(0x020E00E4)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA20
    //     ALT1 (1) - Select instance: lcd signal: LCD_DATA20
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_SCLK
    //     ALT3 (3) - Select instance: audmux signal: AUD4_TXC
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO14
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA20_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA20_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA20_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20(0x020E03F8)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     RESERVED0 (0) - Reserved
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA20_SRE_V(SLOW));

    // Config gpio5.GPIO5_IO15 to pad DISP0_DATA21(T20)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA21_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA21(0x020E00E8)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA21
    //     ALT1 (1) - Select instance: lcd signal: LCD_DATA21
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_MOSI
    //     ALT3 (3) - Select instance: audmux signal: AUD4_TXD
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO15
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA21_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA21_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA21_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21(0x020E03FC)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     RESERVED0 (0) - Reserved
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA21_SRE_V(SLOW));

    // Config gpio5.GPIO5_IO16 to pad DISP0_DATA22(V24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA22_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA22(0x020E00EC)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA22
    //     ALT1 (1) - Select instance: lcd signal: LCD_DATA22
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_MISO
    //     ALT3 (3) - Select instance: audmux signal: AUD4_TXFS
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO16
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA22_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA22_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA22_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22(0x020E0400)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     RESERVED0 (0) - Reserved
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA22_SRE_V(SLOW));

    // Config gpio5.GPIO5_IO17 to pad DISP0_DATA23(W24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA23_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA23(0x020E00F0)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_DISP0_DATA23
    //     ALT1 (1) - Select instance: lcd signal: LCD_DATA23
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_SS0
    //     ALT3 (3) - Select instance: audmux signal: AUD4_RXD
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO17
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA23_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA23_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DATA23_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23(0x020E0404)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     RESERVED0 (0) - Reserved
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DATA23_SRE_V(SLOW));

    // Config gpio5.GPIO5_IO20 to pad CSI0_DATA_EN(P3)
    // HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN(0x020E008C)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_CSI0_DATA_EN
    //     ALT1 (1) - Select instance: eim signal: EIM_DATA00
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO20
    //     ALT7 (7) - Select instance: arm signal: ARM_TRACE_CLK
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN(0x020E03A0)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     RESERVED0 (0) - Reserved
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_SRE_V(SLOW));
}
