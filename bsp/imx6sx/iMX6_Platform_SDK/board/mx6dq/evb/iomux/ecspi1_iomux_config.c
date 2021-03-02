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

// File: ecspi1_iomux_config.c

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

// Function to configure IOMUXC for ecspi1 module.
void ecspi1_iomux_config(void)
{
    // Config ecspi1.ECSPI1_MISO to pad EIM_DATA17(F21)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_WR(0x0001B0B0);
    // HW_IOMUXC_ECSPI1_MISO_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17(0x020E0094)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: eim signal: EIM_DATA17
    //     ALT1 (1) - Select instance: ecspi1 signal: ECSPI1_MISO
    //     ALT2 (2) - Select instance: ipu1 signal: IPU1_DI0_PIN06
    //     ALT3 (3) - Select instance: ipu2 signal: IPU2_CSI1_PIXCLK
    //     ALT4 (4) - Select instance: dcic1 signal: DCIC1_OUT
    //     ALT5 (5) - Select instance: gpio3 signal: GPIO3_IO17
    //     ALT6 (6) - Select instance: i2c3 signal: I2C3_SCL
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17_MUX_MODE_V(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17(0x020E03A8)
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
    //     TBD (0) - TBD
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
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA17_SRE_V(SLOW));
    // Pad EIM_DATA17 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_MISO_SELECT_INPUT(0x020E07F8)
    //   DAISY [1:0] - MUX Mode Select Field Reset: EIM_DATA17_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //     EIM_DATA17_ALT1 (0) - Select signal ecspi1 ECSPI1_MISO as input from pad EIM_DATA17(ALT1).
    //     DISP0_DATA22_ALT2 (1) - Select signal ecspi1 ECSPI1_MISO as input from pad DISP0_DATA22(ALT2).
    //     KEY_COL1_ALT0 (2) - Select signal ecspi1 ECSPI1_MISO as input from pad KEY_COL1(ALT0).
    //     CSI0_DATA06_ALT2 (3) - Select signal ecspi1 ECSPI1_MISO as input from pad CSI0_DATA06(ALT2).
    HW_IOMUXC_ECSPI1_MISO_SELECT_INPUT_WR(
            BF_IOMUXC_ECSPI1_MISO_SELECT_INPUT_DAISY_V(EIM_DATA17_ALT1));

    // Config ecspi1.ECSPI1_MOSI to pad EIM_DATA18(D24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA18_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_WR(0x0001B0B0);
    // HW_IOMUXC_ECSPI1_MOSI_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DATA18(0x020E0098)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: eim signal: EIM_DATA18
    //     ALT1 (1) - Select instance: ecspi1 signal: ECSPI1_MOSI
    //     ALT2 (2) - Select instance: ipu1 signal: IPU1_DI0_PIN07
    //     ALT3 (3) - Select instance: ipu2 signal: IPU2_CSI1_DATA17
    //     ALT4 (4) - Select instance: ipu1 signal: IPU1_DI1_D0_CS
    //     ALT5 (5) - Select instance: gpio3 signal: GPIO3_IO18
    //     ALT6 (6) - Select instance: i2c3 signal: I2C3_SDA
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA18_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA18_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA18_MUX_MODE_V(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18(0x020E03AC)
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
    //     TBD (0) - TBD
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
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA18_SRE_V(SLOW));
    // Pad EIM_DATA18 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_MOSI_SELECT_INPUT(0x020E07FC)
    //   DAISY [1:0] - MUX Mode Select Field Reset: EIM_DATA18_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //     EIM_DATA18_ALT1 (0) - Select signal ecspi1 ECSPI1_MOSI as input from pad EIM_DATA18(ALT1).
    //     DISP0_DATA21_ALT2 (1) - Select signal ecspi1 ECSPI1_MOSI as input from pad DISP0_DATA21(ALT2).
    //     KEY_ROW0_ALT0 (2) - Select signal ecspi1 ECSPI1_MOSI as input from pad KEY_ROW0(ALT0).
    //     CSI0_DATA05_ALT2 (3) - Select signal ecspi1 ECSPI1_MOSI as input from pad CSI0_DATA05(ALT2).
    HW_IOMUXC_ECSPI1_MOSI_SELECT_INPUT_WR(
            BF_IOMUXC_ECSPI1_MOSI_SELECT_INPUT_DAISY_V(EIM_DATA18_ALT1));

    // Config ecspi1.ECSPI1_SCLK to pad EIM_DATA16(C25)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA16_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_WR(0x0001B0B0);
    // HW_IOMUXC_ECSPI1_CSPI_CLK_IN_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DATA16(0x020E0090)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: eim signal: EIM_DATA16
    //     ALT1 (1) - Select instance: ecspi1 signal: ECSPI1_SCLK
    //     ALT2 (2) - Select instance: ipu1 signal: IPU1_DI0_PIN05
    //     ALT3 (3) - Select instance: ipu2 signal: IPU2_CSI1_DATA18
    //     ALT4 (4) - Select instance: hdmi signal: HDMI_TX_DDC_SDA
    //     ALT5 (5) - Select instance: gpio3 signal: GPIO3_IO16
    //     ALT6 (6) - Select instance: i2c2 signal: I2C2_SDA
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA16_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA16_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA16_MUX_MODE_V(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16(0x020E03A4)
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
    //     TBD (0) - TBD
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
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA16_SRE_V(SLOW));
    // Pad EIM_DATA16 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_CSPI_CLK_IN_SELECT_INPUT(0x020E07F4)
    //   DAISY [1:0] - MUX Mode Select Field Reset: EIM_DATA16_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //     EIM_DATA16_ALT1 (0) - Select signal ecspi1 ECSPI1_SCLK as input from pad EIM_DATA16(ALT1).
    //     DISP0_DATA20_ALT2 (1) - Select signal ecspi1 ECSPI1_SCLK as input from pad DISP0_DATA20(ALT2).
    //     KEY_COL0_ALT0 (2) - Select signal ecspi1 ECSPI1_SCLK as input from pad KEY_COL0(ALT0).
    //     CSI0_DATA04_ALT2 (3) - Select signal ecspi1 ECSPI1_SCLK as input from pad CSI0_DATA04(ALT2).
    HW_IOMUXC_ECSPI1_CSPI_CLK_IN_SELECT_INPUT_WR(
            BF_IOMUXC_ECSPI1_CSPI_CLK_IN_SELECT_INPUT_DAISY_V(EIM_DATA16_ALT1));

    // Config ecspi1.ECSPI1_SS0 to pad EIM_EB2(E22)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_EB2_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_WR(0x0001B0B0);
    // HW_IOMUXC_ECSPI1_SS0_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_EB2(0x020E008C)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: eim signal: EIM_EB2
    //     ALT1 (1) - Select instance: ecspi1 signal: ECSPI1_SS0
    //     ALT3 (3) - Select instance: ipu2 signal: IPU2_CSI1_DATA19
    //     ALT4 (4) - Select instance: hdmi signal: HDMI_TX_DDC_SCL
    //     ALT5 (5) - Select instance: gpio2 signal: GPIO2_IO30
    //     ALT6 (6) - Select instance: i2c2 signal: I2C2_SCL
    //     ALT7 (7) - Select instance: src signal: SRC_BOOT_CFG30
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_EB2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_EB2_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_EB2_MUX_MODE_V(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_EB2(0x020E03A0)
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
    //     TBD (0) - TBD
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
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_EB2_SRE_V(SLOW));
    // Pad EIM_EB2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_SS0_SELECT_INPUT(0x020E0800)
    //   DAISY [1:0] - MUX Mode Select Field Reset: EIM_EB2_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //     EIM_EB2_ALT1 (0) - Select signal ecspi1 ECSPI1_SS0 as input from pad EIM_EB2(ALT1).
    //     DISP0_DATA23_ALT2 (1) - Select signal ecspi1 ECSPI1_SS0 as input from pad DISP0_DATA23(ALT2).
    //     KEY_ROW1_ALT0 (2) - Select signal ecspi1 ECSPI1_SS0 as input from pad KEY_ROW1(ALT0).
    //     CSI0_DATA07_ALT2 (3) - Select signal ecspi1 ECSPI1_SS0 as input from pad CSI0_DATA07(ALT2).
    HW_IOMUXC_ECSPI1_SS0_SELECT_INPUT_WR(
            BF_IOMUXC_ECSPI1_SS0_SELECT_INPUT_DAISY_V(EIM_EB2_ALT1));

    // Config ecspi1.ECSPI1_SS1 to pad EIM_DATA19(G21)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA19_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_WR(0x0001B0B0);
    // HW_IOMUXC_ECSPI1_SS1_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DATA19(0x020E009C)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: eim signal: EIM_DATA19
    //     ALT1 (1) - Select instance: ecspi1 signal: ECSPI1_SS1
    //     ALT2 (2) - Select instance: ipu1 signal: IPU1_DI0_PIN08
    //     ALT3 (3) - Select instance: ipu2 signal: IPU2_CSI1_DATA16
    //     ALT4 (4) - Select instance: uart1 signal: UART1_CTS_B
    //     ALT5 (5) - Select instance: gpio3 signal: GPIO3_IO19
    //     ALT6 (6) - Select instance: epit1 signal: EPIT1_OUT
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA19_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA19_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA19_MUX_MODE_V(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19(0x020E03B0)
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
    //     TBD (0) - TBD
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
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DATA19_SRE_V(SLOW));
    // Pad EIM_DATA19 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ECSPI1_SS1_SELECT_INPUT(0x020E0804)
    //   DAISY [1:0] - MUX Mode Select Field Reset: EIM_DATA19_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //     EIM_DATA19_ALT1 (0) - Select signal ecspi1 ECSPI1_SS1 as input from pad EIM_DATA19(ALT1).
    //     DISP0_DATA15_ALT2 (1) - Select signal ecspi1 ECSPI1_SS1 as input from pad DISP0_DATA15(ALT2).
    //     KEY_COL2_ALT0 (2) - Select signal ecspi1 ECSPI1_SS1 as input from pad KEY_COL2(ALT0).
    HW_IOMUXC_ECSPI1_SS1_SELECT_INPUT_WR(
            BF_IOMUXC_ECSPI1_SS1_SELECT_INPUT_DAISY_V(EIM_DATA19_ALT1));
}
