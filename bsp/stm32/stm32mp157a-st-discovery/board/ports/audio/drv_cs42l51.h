/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Date           Author       Notes
 * 2020-07-02     thread-liu   first version
 */

#ifndef __DRV_CS42L51_H__
#define __DRV_CS42L51_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  rt_err_t  (*init)(uint16_t , const char *, uint8_t);
  void      (*deinit)(void);
  uint32_t  (*read_id)(void);
  uint32_t  (*play)(void);
  uint32_t  (*pause)(void);
  uint32_t  (*resume)(void);
  uint32_t  (*stop)(void);
  uint32_t  (*set_frequency)(uint32_t);
  uint32_t  (*set_volume)(uint8_t);
  uint32_t  (*get_volume)(void);
  uint32_t  (*set_mute)(uint32_t);
  uint32_t  (*set_output_mode)(uint8_t);
  uint32_t  (*reset)(void);
}AUDIO_DrvTypeDef;

extern AUDIO_DrvTypeDef cs42l51_drv;

/* CS42L51 register space */
#define CS42L51_CHIP_ID                     0x1B
#define CS42L51_CHIP_REV_A                  0x00
#define CS42L51_CHIP_REV_B                  0x01

#define CS42L51_CHIP_REV_ID                 0x01
#define CS42L51_MK_CHIP_REV(a, b)           ((a)<<3|(b))

#define CS42L51_POWER_CTL1                  0x02
#define CS42L51_POWER_CTL1_PDN_DACB         (1<<6)
#define CS42L51_POWER_CTL1_PDN_DACA         (1<<5)
#define CS42L51_POWER_CTL1_PDN_PGAB         (1<<4)
#define CS42L51_POWER_CTL1_PDN_PGAA         (1<<3)
#define CS42L51_POWER_CTL1_PDN_ADCB         (1<<2)
#define CS42L51_POWER_CTL1_PDN_ADCA         (1<<1)
#define CS42L51_POWER_CTL1_PDN              (1<<0)

#define CS42L51_MIC_POWER_CTL               0x03
#define CS42L51_MIC_POWER_CTL_AUTO          (1<<7)
#define CS42L51_MIC_POWER_CTL_SPEED(x)      (((x)&3)<<5)
#define CS42L51_QSM_MODE                    3
#define CS42L51_HSM_MODE                    2
#define CS42L51_SSM_MODE                    1
#define CS42L51_DSM_MODE                    0
#define CS42L51_MIC_POWER_CTL_3ST_SP        (1<<4)
#define CS42L51_MIC_POWER_CTL_PDN_MICB      (1<<3)
#define CS42L51_MIC_POWER_CTL_PDN_MICA      (1<<2)
#define CS42L51_MIC_POWER_CTL_PDN_BIAS      (1<<1)
#define CS42L51_MIC_POWER_CTL_MCLK_DIV2     (1<<0)

#define CS42L51_INTF_CTL                    0x04
#define CS42L51_INTF_CTL_LOOPBACK           (1<<7)
#define CS42L51_INTF_CTL_MASTER             (1<<6)
#define CS42L51_INTF_CTL_DAC_FORMAT(x)      (((x)&7)<<3)
#define CS42L51_DAC_DIF_LJ24                0x00
#define CS42L51_DAC_DIF_I2S                 0x01
#define CS42L51_DAC_DIF_RJ24                0x02
#define CS42L51_DAC_DIF_RJ20                0x03
#define CS42L51_DAC_DIF_RJ18                0x04
#define CS42L51_DAC_DIF_RJ16                0x05
#define CS42L51_INTF_CTL_ADC_I2S            (1<<2)
#define CS42L51_INTF_CTL_DIGMIX             (1<<1)
#define CS42L51_INTF_CTL_MICMIX             (1<<0)

#define CS42L51_MIC_CTL                     0x05
#define CS42L51_MIC_CTL_ADC_SNGVOL          (1<<7)
#define CS42L51_MIC_CTL_ADCD_DBOOST         (1<<6)
#define CS42L51_MIC_CTL_ADCA_DBOOST         (1<<5)
#define CS42L51_MIC_CTL_MICBIAS_SEL         (1<<4)
#define CS42L51_MIC_CTL_MICBIAS_LVL(x)      (((x)&3)<<2)
#define CS42L51_MIC_CTL_MICB_BOOST          (1<<1)
#define CS42L51_MIC_CTL_MICA_BOOST          (1<<0)

#define CS42L51_ADC_CTL                     0x06
#define CS42L51_ADC_CTL_ADCB_HPFEN          (1<<7)
#define CS42L51_ADC_CTL_ADCB_HPFRZ          (1<<6)
#define CS42L51_ADC_CTL_ADCA_HPFEN          (1<<5)
#define CS42L51_ADC_CTL_ADCA_HPFRZ          (1<<4)
#define CS42L51_ADC_CTL_SOFTB               (1<<3)
#define CS42L51_ADC_CTL_ZCROSSB             (1<<2)
#define CS42L51_ADC_CTL_SOFTA               (1<<1)
#define CS42L51_ADC_CTL_ZCROSSA             (1<<0)

#define CS42L51_ADC_INPUT                   0x07
#define CS42L51_ADC_INPUT_AINB_MUX(x)       (((x)&3)<<6)
#define CS42L51_ADC_INPUT_AINA_MUX(x)       (((x)&3)<<4)
#define CS42L51_ADC_INPUT_INV_ADCB          (1<<3)
#define CS42L51_ADC_INPUT_INV_ADCA          (1<<2)
#define CS42L51_ADC_INPUT_ADCB_MUTE         (1<<1)
#define CS42L51_ADC_INPUT_ADCA_MUTE         (1<<0)

#define CS42L51_DAC_OUT_CTL                 0x08
#define CS42L51_DAC_OUT_CTL_HP_GAIN(x)      (((x)&7)<<5)
#define CS42L51_DAC_OUT_CTL_DAC_SNGVOL      (1<<4)
#define CS42L51_DAC_OUT_CTL_INV_PCMB        (1<<3)
#define CS42L51_DAC_OUT_CTL_INV_PCMA        (1<<2)
#define CS42L51_DAC_OUT_CTL_DACB_MUTE       (1<<1)
#define CS42L51_DAC_OUT_CTL_DACA_MUTE       (1<<0)

#define CS42L51_DAC_CTL                     0x09
#define CS42L51_DAC_CTL_DATA_SEL(x)         (((x)&3)<<6)
#define CS42L51_DAC_CTL_FREEZE              (1<<5)
#define CS42L51_DAC_CTL_DEEMPH              (1<<3)
#define CS42L51_DAC_CTL_AMUTE               (1<<2)
#define CS42L51_DAC_CTL_DACSZ(x)            (((x)&3)<<0)

#define CS42L51_ALC_PGA_CTL                 0x0A
#define CS42L51_ALC_PGB_CTL                 0x0B
#define CS42L51_ALC_PGX_ALCX_SRDIS          (1<<7)
#define CS42L51_ALC_PGX_ALCX_ZCDIS          (1<<6)
#define CS42L51_ALC_PGX_PGX_VOL(x)          (((x)&0x1f)<<0)

#define CS42L51_ADCA_ATT                    0x0C
#define CS42L51_ADCB_ATT                    0x0D

#define CS42L51_ADCA_VOL                    0x0E
#define CS42L51_ADCB_VOL                    0x0F
#define CS42L51_PCMA_VOL                    0x10
#define CS42L51_PCMB_VOL                    0x11
#define CS42L51_MIX_MUTE_ADCMIX             (1<<7)
#define CS42L51_MIX_VOLUME(x)               (((x)&0x7f)<<0)

#define CS42L51_BEEP_FREQ                   0x12
#define CS42L51_BEEP_VOL                    0x13
#define CS42L51_BEEP_CONF                   0x14

#define CS42L51_TONE_CTL                    0x15
#define CS42L51_TONE_CTL_TREB(x)            (((x)&0xf)<<4)
#define CS42L51_TONE_CTL_BASS(x)            (((x)&0xf)<<0)

#define CS42L51_AOUTA_VOL                   0x16
#define CS42L51_AOUTB_VOL                   0x17
#define CS42L51_PCM_MIXER                   0x18
#define CS42L51_LIMIT_THRES_DIS             0x19
#define CS42L51_LIMIT_REL                   0x1A
#define CS42L51_LIMIT_ATT                   0x1B
#define CS42L51_ALC_EN                      0x1C
#define CS42L51_ALC_REL                     0x1D
#define CS42L51_ALC_THRES                   0x1E
#define CS42L51_NOISE_CONF                  0x1F

#define CS42L51_STATUS                      0x20
#define CS42L51_STATUS_SP_CLKERR            (1<<6)
#define CS42L51_STATUS_SPEA_OVFL            (1<<5)
#define CS42L51_STATUS_SPEB_OVFL            (1<<4)
#define CS42L51_STATUS_PCMA_OVFL            (1<<3)
#define CS42L51_STATUS_PCMB_OVFL            (1<<2)
#define CS42L51_STATUS_ADCA_OVFL            (1<<1)
#define CS42L51_STATUS_ADCB_OVFL            (1<<0)

#define CS42L51_CHARGE_FREQ                 0x21
#define CS42L51_FIRSTREG                    0x01

enum play_type {
    NONE,
    OUT_HEADPHONE,
    IN_MIC1,
    IN_MIC2,
    IN_LINE1,
    IN_LINE2,
    IN_LINE3,
};

/*
 * Hack: with register 0x21, it makes 33 registers. Looks like someone in the
 * i2c layer doesn't like i2c smbus block read of 33 regs. Workaround by using
 * 32 regs
 */
#define CS42L51_LASTREG                     0x20
#define CS42L51_NUMREGS                     (CS42L51_LASTREG - CS42L51_FIRSTREG + 1)

#define VOLUME_CONVERT(Volume)              ((Volume >= 100) ? 0 : ((uint8_t)(((Volume * 2) + 56))))
#define VOLUME_INVERT(Volume)               (((Volume) == 0U) ? 100U : ((uint8_t)(((Volume) - 56U) / 2U)))

/* MUTE commands */
#define AUDIO_MUTE_ON                       1
#define AUDIO_MUTE_OFF                      0

#ifdef __cplusplus
}
#endif

#endif
