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

// File: mlb_iomux_config.c

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

// Function to configure IOMUXC for mlb module.
void mlb_iomux_config(void)
{
    // Config mlb.MLB_CLK to pad GPIO03(R7)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO03_WR(0x00000007);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO03_WR(0x0001B0B0);
    // HW_IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO03(0x020E0228)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_RX_HF_CLK
    //     ALT2 (2) - Select instance: i2c3 signal: I2C3_SCL
    //     ALT3 (3) - Select instance: xtalosc signal: XTALOSC_REF_CLK_24M
    //     ALT4 (4) - Select instance: ccm signal: CCM_CLKO2
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO03
    //     ALT6 (6) - Select instance: usb signal: USB_H1_OC
    //     ALT7 (7) - Select instance: mlb signal: MLB_CLK
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO03_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO03_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO03_MUX_MODE_V(ALT7));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO03(0x020E05F8)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO03_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO03_SRE_V(SLOW));
    // Pad GPIO03 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT(0x020E08DC)
    //   DAISY [0] - MUX Mode Select Field Reset: ENET_TX_DATA1_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //     ENET_TX_DATA1_ALT0 (0) - Select signal mlb MLB_CLK as input from pad ENET_TX_DATA1(ALT0).
    //     GPIO03_ALT7 (1) - Select signal mlb MLB_CLK as input from pad GPIO03(ALT7).
    HW_IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT_WR(
            BF_IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT_DAISY_V(ENET_TX_DATA1_ALT0));

    // Config mlb.MLB_DATA to pad GPIO02(T1)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO02_WR(0x00000007);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO02_WR(0x0001B0B0);
    // HW_IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO02(0x020E0224)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_TX_FS
    //     ALT2 (2) - Select instance: kpp signal: KEY_ROW6
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO02
    //     ALT6 (6) - Select instance: usdhc2 signal: SD2_WP
    //     ALT7 (7) - Select instance: mlb signal: MLB_DATA
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO02_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO02_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO02_MUX_MODE_V(ALT7));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO02(0x020E05F4)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO02_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO02_SRE_V(SLOW));
    // Pad GPIO02 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT(0x020E08E0)
    //   DAISY [0] - MUX Mode Select Field Reset: ENET_MDC_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //     ENET_MDC_ALT0 (0) - Select signal mlb MLB_DATA as input from pad ENET_MDC(ALT0).
    //     GPIO02_ALT7 (1) - Select signal mlb MLB_DATA as input from pad GPIO02(ALT7).
    HW_IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT_WR(
            BF_IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT_DAISY_V(ENET_MDC_ALT0));

    // Config mlb.MLB_SIG to pad GPIO06(T3)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO06_WR(0x00000007);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO06_WR(0x0001B0B0);
    // HW_IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT_WR(0x00000000);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO06(0x020E0234)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_TX_CLK
    //     ALT2 (2) - Select instance: i2c3 signal: I2C3_SDA
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO06
    //     ALT6 (6) - Select instance: usdhc2 signal: SD2_LCTL
    //     ALT7 (7) - Select instance: mlb signal: MLB_SIG
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO06_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO06_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO06_MUX_MODE_V(ALT7));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO06(0x020E0604)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO06_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_SRE_V(SLOW));
    // Pad GPIO06 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT(0x020E08E4)
    //   DAISY [0] - MUX Mode Select Field Reset: ENET_RX_DATA1_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //     ENET_RX_DATA1_ALT0 (0) - Select signal mlb MLB_SIG as input from pad ENET_RX_DATA1(ALT0).
    //     GPIO06_ALT7 (1) - Select signal mlb MLB_SIG as input from pad GPIO06(ALT7).
    HW_IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT_WR(
            BF_IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT_DAISY_V(ENET_RX_DATA1_ALT0));
}
