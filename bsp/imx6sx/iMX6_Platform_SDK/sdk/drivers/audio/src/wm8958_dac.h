/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
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

#ifndef __WM8958_DAC_H__
#define __WM8958_DAC_H__

#define WM8958_REG_RESET_ID         0x00
#define WM8958_DEVICE_ID        0x8958
#define WM8958_REG_POWER_MANAGEMENT0    0x01
#define WM8958_REG_POWER_MANAGEMENT1    0x02
#define WM8958_REG_POWER_MANAGEMENT2    0x03
#define WM8958_REG_POWER_MANAGEMENT3    0x04
#define WM8958_REG_POWER_MANAGEMENT4    0x05
#define WM8958_REG_POWER_MANAGEMENT5    0x06
#define WM8958_REG_POWER_MANAGEMENT6    0x07

#define WM8959_REG_INPUT_MIXER1     0x15
#define WM8959_REG_ANTIPOP_1        0x38
#define WM8959_REG_ANTIPOP_2        0x39

#define WM8958_REG_OUTPUT_MIXER_1   0x2D
#define WM8958_REG_OUTPUT_MIXER_2   0x2E
#define WM8958_REG_OUTPUT_MIXER_3   0x2F
#define WM8958_REG_OUTPUT_MIXER_4   0x30
#define WM8958_REG_OUTPUT_MIXER_5   0x31
#define WM8958_REG_OUTPUT_MIXER_6   0x32
#define WM8958_REG_HPOUT2_MIXER     0x33
#define WM8958_REG_LINE_MIXER_1     0x34
#define WM8958_REG_LINE_MIXER_2     0x35
#define WM8958_REG_SPEAKER_MIXER    0x36

#define WM8958_REG_CHARGE_PUMP_1    0x4C
#define WM8958_REG_CHARGE_PUMP_2    0x4D

#define WM8958_REG_CLASE_W      0x51

#define WM8958_REG_DC_SERVO_1       0x54
#define WM8958_REG_DC_SERVO_2       0x55
#define WM8958_REG_DC_SERVO_4       0x57

#define WM8958_REG_ANALOG_HP        0x60

#define WM8958_REG_CHIP_VERSION     0x100

#define WM8958_REG_WRITE_SEQUENCER_CTRL_1   0x110
#define WM8958_REG_WRITE_SEQUENCER_CTRL_2   0x111
#define WM8958_DEFAULT_SEQ_HP_COLD_START_UP 0x8100
#define WM8958_DEFAULT_SEQ_HP_WARM_START_UP 0x8108

#define WM8958_REG_AIF1_CLOCKING_1  0x200
#define WM8958_REG_AIF1_CLOCKING_2  0x201
#define WM8958_REG_AIF2_CLOCKING_1  0x204
#define WM8958_REG_AIF2_CLOCKING_2  0x205

#define WM8958_REG_CLOCKING_1       0x208
#define WM8958_REG_CLOCKING_2       0x209
#define WM8958_REG_AIF1_RATE        0x210
#define WM8958_REG_AIF2_RATE        0x211

#define WM8958_REG_FLL1_CTRL1       0x220
#define WM8958_REG_FLL1_CTRL2       0x221
#define WM8958_REG_FLL1_CTRL3       0x222
#define WM8958_REG_FLL1_CTRL4       0x223
#define WM8958_REG_FLL1_CTRL5       0x224

#define WM8958_REG_FLL2_CTRL1       0x240
#define WM8958_REG_FLL2_CTRL2       0x241
#define WM8958_REG_FLL2_CTRL3       0x242
#define WM8958_REG_FLL2_CTRL4       0x243
#define WM8958_REG_FLL2_CTRL5       0x244

typedef enum {
    MCLK1 = 0,
    MCLK2,
    LRCLK,
    BCLK,
} fll_refclk_src_e;

typedef enum {
    FLL_REFCLK_DIV_1 = 0,
    FLL_REFCLK_DIV_2 = 1,
    FLL_REFCLK_DIV_4 = 2,
    FLL_REFCLK_DIV_8 = 3,
} fll_refclk_div_e;

#define WM8958_REG_FLL_CTRL1_OSC_EN         (0x01 << 1)
#define WM8958_REG_FLL_CTRL1_FLL_EN         (0x01 << 0)
#define WM8958_REG_FLL_CTRL2_OUTDIV(x)      ((((x)  - 1)& 0x1F) << 8)
#define WM8958_REG_FLL_CTRL2_FRATIO(x)      (((x) -1)  & 0x07)
#define WM8958_REG_FLL_CTRL3_K(x)           ((unsigned short)(x*65535.0f))
#define WM8958_REG_FLL_CTRL4_N(x)           (((x) & 0x3FF) << 5)
#define WM8958_REG_FLL_CTRL5_BYPASS         (0x01 << 15)
#define WM8958_REG_FLL_CTRL5_FRC_NCO_VAL(x) (((x) & 0x3F) << 7)
#define WM8958_REG_FLL_CTRL5_FRC_NCO        (0x01 << 6)
#define WM8958_REG_FLL_CTRL5_REF_DIV(x)     (((x) & 0x03) << 3)
#define WM8958_REG_FLL_CTRL5_REF_SRC(x)     (x)

#define WM8958_REG_AIF1_CTRL_1      0x300
#define WM8958_REG_AIF1_CTRL_2      0x301
#define WM8958_REG_AIF1_MASTER_SLAVE    0x302
#define WM8958_REG_AIF1_BCLK        0x303
#define WM8958_REG_AIF1ADC_LRCLK    0x304
#define WM8958_REG_AIF1DAC_LRCLK    0x305

#define WM8958_REG_AIF2_CTRL_1      0x310
#define WM8958_REG_AIF2_CTRL_2      0x311
#define WM8958_REG_AIF2_MASTER_SLAVE    0x312

#define WM8958_REG_AIF1_DAC1_FILTER_1   0x420

#define WM8958_REG_DAC1_MIXER_VOLUMES       0x600
#define WM8958_REG_DAC1_LEFT_MIXER_ROUTING  0x601
#define WM8958_REG_DAC1_RIGHT_MIXER_ROUTING 0x602
#define WM8958_REG_DAC2_MIXER_VOLUMES       0x603
#define WM8958_REG_DAC2_LEFT_MIXER_ROUTING  0x604
#define WM8958_REG_DAC2_RIGHT_MIXER_ROUTING 0x605

#define WM8958_REG_DAC1_LEFT_VOLUME 0x610
#define WM8958_REG_DAC1_RIGHT_VOLUME    0x611
#define WM8958_REG_DAC2_LEFT_VOLUME 0x612
#define WM8958_REG_DAC2_RIGHT_VOLUME    0x613

#define WM8958_REG_INT_STATUS1      0x730
#define WM8958_REG_INT_STATUS2      0x731
#define WM8958_REG_INT_RAW_STATUS2      0x732
#define WM8958_REG_INT_RAW_STATUS2_FLL1_LOCK        (0x01 << 5)

#define WM8958_REG_WR_SEQ_0         0x3000
#define WM8958_REG_WR_SEQ_1         0x3001
#define WM8958_REG_WR_SEQ_2         0x3002
#define WM8958_REG_WR_SEQ_3         0x3003
#define WM8958_REG_WR_SEQ_4         0x3004
#define WM8958_REG_WR_SEQ_5         0x3005
#define WM8958_REG_WR_SEQ_6         0x3006
#define WM8958_REG_WR_SEQ_7         0x3007

#endif
