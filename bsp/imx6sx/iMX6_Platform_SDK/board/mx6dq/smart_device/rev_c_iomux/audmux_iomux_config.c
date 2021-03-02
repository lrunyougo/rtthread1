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

// File: audmux_iomux_config.c

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

// Function to configure IOMUXC for audmux module.
void audmux_iomux_config(void)
{
    // Config audmux.AUD3_RXD to pad CSI0_DATA07(N3)
    // HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA07_WR(0x00000004);
    // HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA07(0x020E0274)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_CSI0_DATA07
    //     ALT1 (1) - Select instance: eim signal: EIM_DATA05
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_SS0
    //     ALT3 (3) - Select instance: kpp signal: KEY_ROW6
    //     ALT4 (4) - Select instance: audmux signal: AUD3_RXD
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO25
    //     ALT7 (7) - Select instance: arm signal: ARM_TRACE04
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA07_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA07_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA07_MUX_MODE_V(ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07(0x020E0644)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA07_SRE_V(SLOW));

    // Config audmux.AUD3_TXC to pad CSI0_DATA04(N1)
    // HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA04_WR(0x00000004);
    // HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA04(0x020E0268)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_CSI0_DATA04
    //     ALT1 (1) - Select instance: eim signal: EIM_DATA02
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_SCLK
    //     ALT3 (3) - Select instance: kpp signal: KEY_COL5
    //     ALT4 (4) - Select instance: audmux signal: AUD3_TXC
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO22
    //     ALT7 (7) - Select instance: arm signal: ARM_TRACE01
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA04_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA04_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA04_MUX_MODE_V(ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04(0x020E0638)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA04_SRE_V(SLOW));

    // Config audmux.AUD3_TXD to pad CSI0_DATA05(P2)
    // HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA05_WR(0x00000004);
    // HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA05(0x020E026C)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_CSI0_DATA05
    //     ALT1 (1) - Select instance: eim signal: EIM_DATA03
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_MOSI
    //     ALT3 (3) - Select instance: kpp signal: KEY_ROW5
    //     ALT4 (4) - Select instance: audmux signal: AUD3_TXD
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO23
    //     ALT7 (7) - Select instance: arm signal: ARM_TRACE02
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA05_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA05_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA05_MUX_MODE_V(ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05(0x020E063C)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA05_SRE_V(SLOW));

    // Config audmux.AUD3_TXFS to pad CSI0_DATA06(N4)
    // HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA06_WR(0x00000004);
    // HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA06(0x020E0270)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ipu1 signal: IPU1_CSI0_DATA06
    //     ALT1 (1) - Select instance: eim signal: EIM_DATA04
    //     ALT2 (2) - Select instance: ecspi1 signal: ECSPI1_MISO
    //     ALT3 (3) - Select instance: kpp signal: KEY_COL6
    //     ALT4 (4) - Select instance: audmux signal: AUD3_TXFS
    //     ALT5 (5) - Select instance: gpio5 signal: GPIO5_IO24
    //     ALT7 (7) - Select instance: arm signal: ARM_TRACE03
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA06_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA06_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA06_MUX_MODE_V(ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06(0x020E0640)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA06_SRE_V(SLOW));
}
