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

// File: gpio4_iomux_config.c

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

// Function to configure IOMUXC for gpio4 module.
void gpio4_iomux_config(void)
{
    // Config gpio4.GPIO4_IO05 to pad GPIO19(P5)
    // CAN1_STBY
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO19_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO19_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO19(0x020E0220)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: kpp signal: KEY_COL5
    //     ALT1 (1) - Select instance: enet signal: ENET_1588_EVENT0_OUT
    //     ALT2 (2) - Select instance: spdif signal: SPDIF_OUT
    //     ALT3 (3) - Select instance: ccm signal: CCM_CLKO1
    //     ALT4 (4) - Select instance: ecspi1 signal: ECSPI1_RDY
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO05
    //     ALT6 (6) - Select instance: enet signal: ENET_TX_ER
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO19_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO19_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO19_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO19(0x020E05F0)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO19_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO19_SRE_V(SLOW));

    // Config gpio4.GPIO4_IO10 to pad KEY_COL2(W6)
    // CODEC_PWR_EN
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL2_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL2(0x020E024C)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ecspi1 signal: ECSPI1_SS1
    //     ALT1 (1) - Select instance: enet signal: ENET_RX_DATA2
    //     ALT2 (2) - Select instance: flexcan1 signal: FLEXCAN1_TX
    //     ALT3 (3) - Select instance: kpp signal: KEY_COL2
    //     ALT4 (4) - Select instance: enet signal: ENET_MDC
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO10
    //     ALT6 (6) - Select instance: usb signal: USB_H1_PWR_CTL_WAKE
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL2_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL2_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL2(0x020E0634)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL2_SRE_V(SLOW));

    // Config gpio4.GPIO4_IO11 to pad KEY_ROW2(W4)
    // HDMI_CEC_IN
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2(0x020E0260)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: ecspi1 signal: ECSPI1_SS2
    //     ALT1 (1) - Select instance: enet signal: ENET_TX_DATA2
    //     ALT2 (2) - Select instance: flexcan1 signal: FLEXCAN1_RX
    //     ALT3 (3) - Select instance: kpp signal: KEY_ROW2
    //     ALT4 (4) - Select instance: usdhc2 signal: SD2_VSELECT
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO11
    //     ALT6 (6) - Select instance: hdmi signal: HDMI_TX_CEC_LINE
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW2_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2(0x020E0648)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW2_SRE_V(SLOW));

    // Config gpio4.GPIO4_IO14 to pad KEY_COL4(T6)
    // PCIE_DIS_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL4(0x020E0254)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: flexcan2 signal: FLEXCAN2_TX
    //     ALT1 (1) - Select instance: ipu1 signal: IPU1_SISG4
    //     ALT2 (2) - Select instance: usb signal: USB_OTG_OC
    //     ALT3 (3) - Select instance: kpp signal: KEY_COL4
    //     ALT4 (4) - Select instance: uart5 signal: UART5_RTS_B
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO14
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL4(0x020E063C)
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
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_SRE_V(SLOW));

    // Config gpio4.GPIO4_IO15 to pad KEY_ROW4(V5)
    // SATA_DEVSLP
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4(0x020E0268)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: flexcan2 signal: FLEXCAN2_RX
    //     ALT1 (1) - Select instance: ipu1 signal: IPU1_SISG5
    //     ALT2 (2) - Select instance: usb signal: USB_OTG_PWR
    //     ALT3 (3) - Select instance: kpp signal: KEY_ROW4
    //     ALT4 (4) - Select instance: uart5 signal: UART5_CTS_B
    //     ALT5 (5) - Select instance: gpio4 signal: GPIO4_IO15
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_SION_V(DISABLED) |
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4(0x020E0650)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PD
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
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_HYS_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_PUS_V(100K_OHM_PU) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_PUE_V(PULL) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_PKE_V(ENABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_ODE_V(DISABLED) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_SPEED_V(100MHZ) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_DSE_V(40_OHM) |
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_SRE_V(SLOW));
}
