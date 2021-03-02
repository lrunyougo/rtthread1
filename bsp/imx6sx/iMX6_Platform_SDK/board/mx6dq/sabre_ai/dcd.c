/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
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

#include "hab_defines.h"
#include "soc_memory_map.h"

//! @brief dcd data, list of (register, value) pairs to initialize ddr
uint8_t input_dcd[] __attribute__ ((section (".dcd_data")))= {
/*
 * The DDR init commands below are based on MX6_series_boards/Auto_Infotainment/RevC_and_RevB/MX6Q_ARD_DDR3_register_programming_aid_v1.6.inc.
 * This file can be found at ddr-script-rel git with commit dfde48ed72f0d43bff72bd372df54d5043b855c8
 */
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x798), EXPAND_UINT32(0x000C0000),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x758), EXPAND_UINT32(0x00000000),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x588), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x594), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x56c), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x578), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x74c), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x57c), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x58c), EXPAND_UINT32(0x00000000),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x59c), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5a0), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x78c), EXPAND_UINT32(0x00000030),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x750), EXPAND_UINT32(0x00020000),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5a8), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5b0), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x524), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x51c), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x518), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x50c), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5b8), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5c0), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x774), EXPAND_UINT32(0x00020000),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x784), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x788), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x794), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x79c), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x7a0), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x7a4), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x7a8), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x748), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5ac), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5b4), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x528), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x520), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x514), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x510), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5bc), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(IOMUXC_BASE_ADDR + 0x5c4), EXPAND_UINT32(0x00000028),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x800), EXPAND_UINT32(0xa1390003),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x80c), EXPAND_UINT32(0x001F001F),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x810), EXPAND_UINT32(0x001F001F),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x80c), EXPAND_UINT32(0x001F001F),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x810), EXPAND_UINT32(0x001F001F),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x83c), EXPAND_UINT32(0x43260335),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x840), EXPAND_UINT32(0x031A030B),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x83c), EXPAND_UINT32(0x4323033B),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x840), EXPAND_UINT32(0x0323026F),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x848), EXPAND_UINT32(0x483D4545),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x848), EXPAND_UINT32(0x44433E48),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x850), EXPAND_UINT32(0x41444840),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x850), EXPAND_UINT32(0x4835483E),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x81c), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x820), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x824), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x828), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x81c), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x820), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x824), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x828), EXPAND_UINT32(0x33333333),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x8b8), EXPAND_UINT32(0x00000800),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x8b8), EXPAND_UINT32(0x00000800),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x004), EXPAND_UINT32(0x00020036),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x008), EXPAND_UINT32(0x09444040),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x00c), EXPAND_UINT32(0x8A8F7955),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x010), EXPAND_UINT32(0xFF328F64),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x014), EXPAND_UINT32(0x01FF00DB),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x018), EXPAND_UINT32(0x00001740),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x00008000),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x02c), EXPAND_UINT32(0x000026d2),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x030), EXPAND_UINT32(0x008F1023),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x040), EXPAND_UINT32(0x00000047),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x000), EXPAND_UINT32(0x841A0000),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x04088032),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x00008033),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x00048031),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x09408030),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x04008040),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x020), EXPAND_UINT32(0x00005800),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x818), EXPAND_UINT32(0x00011117),
    EXPAND_UINT32(MMDC_P1_BASE_ADDR + 0x818), EXPAND_UINT32(0x00011117),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x004), EXPAND_UINT32(0x00025576),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x404), EXPAND_UINT32(0x00011006),
    EXPAND_UINT32(MMDC_P0_BASE_ADDR + 0x01c), EXPAND_UINT32(0x00000000),
};

//! @brief HAB command write data header, with tag,
//!        size of dcd data with hdr,
//!        parameter field (size of register value and flag)
uint8_t input_dcd_wrt_cmd[] __attribute__ ((section (".dcd_wrt_cmd")))= {
    HAB_CMD_WRT_DAT,
    EXPAND_UINT16(sizeof(input_dcd) + HDR_BYTES),
    WRT_DAT_PAR(0, HAB_DATA_WIDTH_WORD) //!< flag 0, width 4
};

//! @brief HAB dcd header with dcd tag, size of entire dcd and version.
uint8_t input_dcd_hdr[] __attribute__ ((section (".dcd_hdr")))= {
    HAB_TAG_DCD,
    EXPAND_UINT16(sizeof(input_dcd) + sizeof(input_dcd_wrt_cmd) + HDR_BYTES),
    HAB_VER(4,0)
};
