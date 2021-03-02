/*
 * Copyright (c) 2010-2012 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _EPDC_REGS_H_
#define _EPDC_REGS_H_

//! @addtogroup diag_epdc
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#if defined(CHIP_MX6SL)
#define EPDC_PIGEON_16_0        (EPDC_BASE_ADDR + 0xC00)
#define EPDC_PIGEON_16_1        (EPDC_BASE_ADDR + 0xC10)
#define EPDC_PIGEON_16_2        (EPDC_BASE_ADDR + 0xC20)
#endif

/* EPDC_CTRL field values */
#define    EPDC_CTRL_SFTRST   0x80000000
#define    EPDC_CTRL_CLKGATE   0x40000000
#define    EPDC_CTRL_SRAM_POWERDOWN   0x100
#define    EPDC_CTRL_UPD_DATA_SWIZZLE_MASK   0xC0
#define    EPDC_CTRL_UPD_DATA_SWIZZLE_NO_SWAP   0
#define    EPDC_CTRL_UPD_DATA_SWIZZLE_ALL_BYTES_SWAP   0x40
#define    EPDC_CTRL_UPD_DATA_SWIZZLE_HWD_SWAP   0x80
#define    EPDC_CTRL_UPD_DATA_SWIZZLE_HWD_BYTE_SWAP   0xC0
#define    EPDC_CTRL_LUT_DATA_SWIZZLE_MASK   0x30
#define    EPDC_CTRL_LUT_DATA_SWIZZLE_NO_SWAP   0
#define    EPDC_CTRL_LUT_DATA_SWIZZLE_ALL_BYTES_SWAP   0x10
#define    EPDC_CTRL_LUT_DATA_SWIZZLE_HWD_SWAP   0x20
#define    EPDC_CTRL_LUT_DATA_SWIZZLE_HWD_BYTE_SWAP   0x30
#define    EPDC_CTRL_BURST_LEN_8_8   0x1
#define    EPDC_CTRL_BURST_LEN_8_16   0

/* EPDC_RES field values */
#define    EPDC_RES_VERTICAL_MASK   0x1FFF0000
#define    EPDC_RES_VERTICAL_OFFSET   16
#define    EPDC_RES_HORIZONTAL_MASK   0x1FFF
#define    EPDC_RES_HORIZONTAL_OFFSET   0

/* EPDC_FORMAT field values */
#define    EPDC_FORMAT_BUF_PIXEL_SCALE_ROUND   0x1000000
#define    EPDC_FORMAT_DEFAULT_TFT_PIXEL_MASK   0xFF0000
#define    EPDC_FORMAT_DEFAULT_TFT_PIXEL_OFFSET   16
#define    EPDC_FORMAT_BUF_PIXEL_FORMAT_P2N   0x200
#define    EPDC_FORMAT_BUF_PIXEL_FORMAT_P3N   0x300
#define    EPDC_FORMAT_BUF_PIXEL_FORMAT_P4N   0x400
#define    EPDC_FORMAT_BUF_PIXEL_FORMAT_P5N   0x500
#define    EPDC_FORMAT_TFT_PIXEL_FORMAT_2BIT   0x0
#define    EPDC_FORMAT_TFT_PIXEL_FORMAT_2BIT_VCOM   0x1
#define    EPDC_FORMAT_TFT_PIXEL_FORMAT_4BIT   0x2
#define    EPDC_FORMAT_TFT_PIXEL_FORMAT_4BIT_VCOM   0x3

/* EPDC_FIFOCTRL field values */
#define    EPDC_FIFOCTRL_ENABLE_PRIORITY   0x80000000
#define    EPDC_FIFOCTRL_FIFO_INIT_LEVEL_MASK   0xFF0000
#define    EPDC_FIFOCTRL_FIFO_INIT_LEVEL_OFFSET   16
#define    EPDC_FIFOCTRL_FIFO_H_LEVEL_MASK   0xFF00
#define    EPDC_FIFOCTRL_FIFO_H_LEVEL_OFFSET   8
#define    EPDC_FIFOCTRL_FIFO_L_LEVEL_MASK   0xFF
#define    EPDC_FIFOCTRL_FIFO_L_LEVEL_OFFSET   0

/* EPDC_UPD_CORD field values */
#define    EPDC_UPD_CORD_YCORD_MASK   0x1FFF0000
#define    EPDC_UPD_CORD_YCORD_OFFSET   16
#define    EPDC_UPD_CORD_XCORD_MASK   0x1FFF
#define    EPDC_UPD_CORD_XCORD_OFFSET   0

/* EPDC_UPD_SIZE field values */
#define    EPDC_UPD_SIZE_HEIGHT_MASK   0x1FFF0000
#define    EPDC_UPD_SIZE_HEIGHT_OFFSET   16
#define    EPDC_UPD_SIZE_WIDTH_MASK   0x1FFF
#define    EPDC_UPD_SIZE_WIDTH_OFFSET   0

/* EPDC_UPD_CTRL field values */
#define    EPDC_UPD_CTRL_USE_FIXED   0x80000000
#define    EPDC_UPD_CTRL_LUT_SEL_MASK   0xF0000
#define    EPDC_UPD_CTRL_LUT_SEL_OFFSET   16
#define    EPDC_UPD_CTRL_WAVEFORM_MODE_MASK   0xFF00
#define    EPDC_UPD_CTRL_WAVEFORM_MODE_OFFSET   8
#define    EPDC_UPD_CTRL_UPDATE_MODE_FULL   0x1

/* EPDC_UPD_FIXED field values */
#define    EPDC_UPD_FIXED_FIXNP_EN   0x80000000
#define    EPDC_UPD_FIXED_FIXCP_EN   0x40000000
#define    EPDC_UPD_FIXED_FIXNP_MASK   0xFF00
#define    EPDC_UPD_FIXED_FIXNP_OFFSET   8
#define    EPDC_UPD_FIXED_FIXCP_MASK   0xFF
#define    EPDC_UPD_FIXED_FIXCP_OFFSET   0

/* EPDC_TCE_CTRL field values */
#define    EPDC_TCE_CTRL_VSCAN_HOLDOFF_MASK   0x1FF0000
#define    EPDC_TCE_CTRL_VSCAN_HOLDOFF_OFFSET   16
#define    EPDC_TCE_CTRL_VCOM_VAL_MASK   0xC00
#define    EPDC_TCE_CTRL_VCOM_VAL_OFFSET   10
#define    EPDC_TCE_CTRL_VCOM_MODE_AUTO   0x200
#define    EPDC_TCE_CTRL_VCOM_MODE_MANUAL   0x000
#define    EPDC_TCE_CTRL_DDR_MODE_ENABLE   0x100
#define    EPDC_TCE_CTRL_LVDS_MODE_CE_ENABLE   0x80
#define    EPDC_TCE_CTRL_LVDS_MODE_ENABLE   0x40
#define    EPDC_TCE_CTRL_SCAN_DIR_1_UP   0x20
#define    EPDC_TCE_CTRL_SCAN_DIR_0_UP   0x10
#define    EPDC_TCE_CTRL_DUAL_SCAN_ENABLE   0x8
#define    EPDC_TCE_CTRL_SDDO_WIDTH_16BIT   0x4
#define    EPDC_TCE_CTRL_PIXELS_PER_SDCLK_2   1
#define    EPDC_TCE_CTRL_PIXELS_PER_SDCLK_4   2
#define    EPDC_TCE_CTRL_PIXELS_PER_SDCLK_8   3

/* EPDC_TCE_SDCFG field values */
#define    EPDC_TCE_SDCFG_SDCLK_HOLD   0x200000
#define    EPDC_TCE_SDCFG_SDSHR   0x100000
#define    EPDC_TCE_SDCFG_NUM_CE_MASK   0xF0000
#define    EPDC_TCE_SDCFG_NUM_CE_OFFSET   16
#define    EPDC_TCE_SDCFG_SDDO_REFORMAT_STANDARD   0
#define    EPDC_TCE_SDCFG_SDDO_REFORMAT_FLIP_PIXELS   0x4000
#define    EPDC_TCE_SDCFG_SDDO_INVERT_ENABLE   0x2000
#define    EPDC_TCE_SDCFG_PIXELS_PER_CE_MASK   0x1FFF
#define    EPDC_TCE_SDCFG_PIXELS_PER_CE_OFFSET   0

/* EPDC_TCE_GDCFG field values */
#define    EPDC_TCE_SDCFG_GDRL   0x10
#define    EPDC_TCE_SDCFG_GDOE_MODE_DELAYED_GDCLK   0x2
#define    EPDC_TCE_SDCFG_GDSP_MODE_FRAME_SYNC   0x1
#define    EPDC_TCE_SDCFG_GDSP_MODE_ONE_LINE   0x0

/* EPDC_TCE_HSCAN1 field values */
#define    EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_MASK   0xFFF0000
#define    EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_OFFSET   16
#define    EPDC_TCE_HSCAN1_LINE_SYNC_MASK   0xFFF
#define    EPDC_TCE_HSCAN1_LINE_SYNC_OFFSET   0

/* EPDC_TCE_HSCAN2 field values */
#define    EPDC_TCE_HSCAN2_LINE_END_MASK   0xFFF0000
#define    EPDC_TCE_HSCAN2_LINE_END_OFFSET   16
#define    EPDC_TCE_HSCAN2_LINE_BEGIN_MASK   0xFFF
#define    EPDC_TCE_HSCAN2_LINE_BEGIN_OFFSET   0

/* EPDC_TCE_VSCAN field values */
#define    EPDC_TCE_VSCAN_FRAME_END_MASK   0xFF0000
#define    EPDC_TCE_VSCAN_FRAME_END_OFFSET   16
#define    EPDC_TCE_VSCAN_FRAME_BEGIN_MASK   0xFF00
#define    EPDC_TCE_VSCAN_FRAME_BEGIN_OFFSET   8
#define    EPDC_TCE_VSCAN_FRAME_SYNC_MASK   0xFF
#define    EPDC_TCE_VSCAN_FRAME_SYNC_OFFSET   0

/* EPDC_TCE_OE field values */
#define    EPDC_TCE_OE_SDOED_WIDTH_MASK   0xFF000000
#define    EPDC_TCE_OE_SDOED_WIDTH_OFFSET   24
#define    EPDC_TCE_OE_SDOED_DLY_MASK   0xFF0000
#define    EPDC_TCE_OE_SDOED_DLY_OFFSET   16
#define    EPDC_TCE_OE_SDOEZ_WIDTH_MASK   0xFF00
#define    EPDC_TCE_OE_SDOEZ_WIDTH_OFFSET   8
#define    EPDC_TCE_OE_SDOEZ_DLY_MASK   0xFF
#define    EPDC_TCE_OE_SDOEZ_DLY_OFFSET   0

/* EPDC_TCE_POLARITY field values */
#define    EPDC_TCE_POLARITY_GDSP_POL_ACTIVE_HIGH   0x10
#define    EPDC_TCE_POLARITY_GDOE_POL_ACTIVE_HIGH   0x8
#define    EPDC_TCE_POLARITY_SDOE_POL_ACTIVE_HIGH   0x4
#define    EPDC_TCE_POLARITY_SDLE_POL_ACTIVE_HIGH   0x2
#define    EPDC_TCE_POLARITY_SDCE_POL_ACTIVE_HIGH   0x1

/* EPDC_TCE_TIMING1 field values */
#define    EPDC_TCE_TIMING1_SDLE_SHIFT_NONE   0x00
#define    EPDC_TCE_TIMING1_SDLE_SHIFT_1   0x10
#define    EPDC_TCE_TIMING1_SDLE_SHIFT_2   0x20
#define    EPDC_TCE_TIMING1_SDLE_SHIFT_3   0x30
#define    EPDC_TCE_TIMING1_SDCLK_INVERT   0x8
#define    EPDC_TCE_TIMING1_SDCLK_SHIFT_NONE   0
#define    EPDC_TCE_TIMING1_SDCLK_SHIFT_1CYCLE   1
#define    EPDC_TCE_TIMING1_SDCLK_SHIFT_2CYCLES   2
#define    EPDC_TCE_TIMING1_SDCLK_SHIFT_3CYCLES   3

/* EPDC_TCE_TIMING2 field values */
#define    EPDC_TCE_TIMING2_GDCLK_HP_MASK   0xFFFF0000
#define    EPDC_TCE_TIMING2_GDCLK_HP_OFFSET   16
#define    EPDC_TCE_TIMING2_GDSP_OFFSET_MASK   0xFFFF
#define    EPDC_TCE_TIMING2_GDSP_OFFSET_OFFSET   0

/* EPDC_TCE_TIMING3 field values */
#define    EPDC_TCE_TIMING3_GDOE_OFFSET_MASK   0xFFFF0000
#define    EPDC_TCE_TIMING3_GDOE_OFFSET_OFFSET   16
#define    EPDC_TCE_TIMING3_GDCLK_OFFSET_MASK   0xFFFF
#define    EPDC_TCE_TIMING3_GDCLK_OFFSET_OFFSET   0

/* EPDC_IRQ_MASK/EPDC_IRQ field values */
#define    EPDC_IRQ_WB_CMPLT_IRQ   0x10000
#define    EPDC_IRQ_LUT_COL_IRQ   0x20000
#define    EPDC_IRQ_TCE_UNDERRUN_IRQ   0x40000
#define    EPDC_IRQ_FRAME_END_IRQ   0x80000
#define    EPDC_IRQ_BUS_ERROR_IRQ   0x100000
#define    EPDC_IRQ_TCE_IDLE_IRQ   0x200000

/* EPDC_STATUS_NEXTLUT field values */
#define    EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID   0x100
#define    EPDC_STATUS_NEXTLUT_NEXT_LUT_MASK   0xF
#define    EPDC_STATUS_NEXTLUT_NEXT_LUT_OFFSET   0

/* EPDC_STATUS field values */
#define    EPDC_STATUS_LUTS_UNDERRUN   0x4
#define    EPDC_STATUS_LUTS_BUSY   0x2
#define    EPDC_STATUS_WB_BUSY   0x1

/* EPDC_DEBUG field values */
#define    EPDC_DEBUG_UNDERRUN_RECOVER   0x2
#define    EPDC_DEBUG_COLLISION_OFF   0x1

/* EPDC_GPIO field values */
#define    EPDC_GPIO_PWRCOM   0x40
#define    EPDC_GPIO_PWRCTRL_MASK   0x3C
#define    EPDC_GPIO_PWRCTRL_OFFSET   2
#define    EPDC_GPIO_BDR_MASK   0x3
#define    EPDC_GPIO_BDR_OFFSET   0

/* EPDC_VERSION field values */
#define EPDC_VERSION_MAJOR_MASK   0xFF000000
#define EPDC_VERSION_MAJOR_OFFSET   24
#define EPDC_VERSION_MINOR_MASK   0xFF0000
#define EPDC_VERSION_MINOR_OFFSET   16
#define EPDC_VERSION_STEP_MASK   0xFFFF
#define EPDC_VERSION_STEP_OFFSET   0

//! @}

#endif // _EPDC_REGS_H_

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
