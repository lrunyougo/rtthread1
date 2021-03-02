/**
  **************************************************************************************
  * @file    reg_AD16C4T.h
  * @brief   AD16C4T Head File
  *
  * @version V0.01
  * @date    3/12/2018
  * @author  Eastsoft MCU Software Team
  * @note
  *
  * Copyright (C) 2018 Shanghai Eastsoft Microelectronics Co., Ltd. ALL rights reserved.
  *
  **************************************************************************************
  */

#ifndef __REG_AD16C4T_H__
#define __REG_AD16C4T_H__


/******************************************************************************/
/*                              设备特殊寄存器结构定义                        */
/******************************************************************************/

/*   允许匿名结构和匿名联合    */
/* #pragma anon_unions */

/****************** Bit definition for AD16C4T_CON1 register ************************/

#define  AD16C4T_CON1_DBGSEL_POS  15U
#define  AD16C4T_CON1_DBGSEL_MSK  BIT(AD16C4T_CON1_DBGSEL_POS)

#define  AD16C4T_CON1_CMPSEL_POSS  11U
#define  AD16C4T_CON1_CMPSEL_POSE  13U
#define  AD16C4T_CON1_CMPSEL_MSK  BITS(AD16C4T_CON1_CMPSEL_POSS,AD16C4T_CON1_CMPSEL_POSE)

#define  AD16C4T_CON1_CMPSELP_POS  10U
#define  AD16C4T_CON1_CMPSELP_MSK  BIT(AD16C4T_CON1_CMPSELP_POS)

#define  AD16C4T_CON1_DFCKSEL_POSS  8U
#define  AD16C4T_CON1_DFCKSEL_POSE  9U
#define  AD16C4T_CON1_DFCKSEL_MSK  BITS(AD16C4T_CON1_DFCKSEL_POSS,AD16C4T_CON1_DFCKSEL_POSE)

#define  AD16C4T_CON1_ARPEN_POS  7U
#define  AD16C4T_CON1_ARPEN_MSK  BIT(AD16C4T_CON1_ARPEN_POS)

#define  AD16C4T_CON1_CMSEL_POSS  5U
#define  AD16C4T_CON1_CMSEL_POSE  6U
#define  AD16C4T_CON1_CMSEL_MSK  BITS(AD16C4T_CON1_CMSEL_POSS,AD16C4T_CON1_CMSEL_POSE)

#define  AD16C4T_CON1_DIRSEL_POS  4U
#define  AD16C4T_CON1_DIRSEL_MSK  BIT(AD16C4T_CON1_DIRSEL_POS)

#define  AD16C4T_CON1_SPMEN_POS  3U
#define  AD16C4T_CON1_SPMEN_MSK  BIT(AD16C4T_CON1_SPMEN_POS)

#define  AD16C4T_CON1_UERSEL_POS  2U
#define  AD16C4T_CON1_UERSEL_MSK  BIT(AD16C4T_CON1_UERSEL_POS)

#define  AD16C4T_CON1_DISUE_POS  1U
#define  AD16C4T_CON1_DISUE_MSK  BIT(AD16C4T_CON1_DISUE_POS)

#define  AD16C4T_CON1_CNTEN_POS  0U
#define  AD16C4T_CON1_CNTEN_MSK  BIT(AD16C4T_CON1_CNTEN_POS)

/****************** Bit definition for AD16C4T_CON2 register ************************/

#define  AD16C4T_CON2_OISS4_POS  14U
#define  AD16C4T_CON2_OISS4_MSK  BIT(AD16C4T_CON2_OISS4_POS)

#define  AD16C4T_CON2_OISS3N_POS  13U
#define  AD16C4T_CON2_OISS3N_MSK  BIT(AD16C4T_CON2_OISS3N_POS)

#define  AD16C4T_CON2_OISS3_POS  12U
#define  AD16C4T_CON2_OISS3_MSK  BIT(AD16C4T_CON2_OISS3_POS)

#define  AD16C4T_CON2_OISS2N_POS  11U
#define  AD16C4T_CON2_OISS2N_MSK  BIT(AD16C4T_CON2_OISS2N_POS)

#define  AD16C4T_CON2_OISS2_POS  10U
#define  AD16C4T_CON2_OISS2_MSK  BIT(AD16C4T_CON2_OISS2_POS)

#define  AD16C4T_CON2_OISS1N_POS  9U
#define  AD16C4T_CON2_OISS1N_MSK  BIT(AD16C4T_CON2_OISS1N_POS)

#define  AD16C4T_CON2_OISS1_POS  8U
#define  AD16C4T_CON2_OISS1_MSK  BIT(AD16C4T_CON2_OISS1_POS)

#define  AD16C4T_CON2_I1SEL_POS  7U
#define  AD16C4T_CON2_I1SEL_MSK  BIT(AD16C4T_CON2_I1SEL_POS)

#define  AD16C4T_CON2_MMSEL_POSS  4U
#define  AD16C4T_CON2_MMSEL_POSE  6U
#define  AD16C4T_CON2_MMSEL_MSK  BITS(AD16C4T_CON2_MMSEL_POSS,AD16C4T_CON2_MMSEL_POSE)

#define  AD16C4T_CON2_CCDMASEL_POS  3U
#define  AD16C4T_CON2_CCDMASEL_MSK  BIT(AD16C4T_CON2_CCDMASEL_POS)

#define  AD16C4T_CON2_CCUSEL_POS  2U
#define  AD16C4T_CON2_CCUSEL_MSK  BIT(AD16C4T_CON2_CCUSEL_POS)

#define  AD16C4T_CON2_CCPCEN_POS  0U
#define  AD16C4T_CON2_CCPCEN_MSK  BIT(AD16C4T_CON2_CCPCEN_POS)

/****************** Bit definition for AD16C4T_SMCON register ************************/

#define  AD16C4T_SMCON_ETPOL_POS  15U
#define  AD16C4T_SMCON_ETPOL_MSK  BIT(AD16C4T_SMCON_ETPOL_POS)

#define  AD16C4T_SMCON_ECM2EN_POS  14U
#define  AD16C4T_SMCON_ECM2EN_MSK  BIT(AD16C4T_SMCON_ECM2EN_POS)

#define  AD16C4T_SMCON_ETFLT_POSS  8U
#define  AD16C4T_SMCON_ETFLT_POSE  11U
#define  AD16C4T_SMCON_ETFLT_MSK  BITS(AD16C4T_SMCON_ETFLT_POSS,AD16C4T_SMCON_ETFLT_POSE)

#define  AD16C4T_SMCON_MSCFG_POS  7U
#define  AD16C4T_SMCON_MSCFG_MSK  BIT(AD16C4T_SMCON_MSCFG_POS)

#define  AD16C4T_SMCON_TSSEL_POSS  4U
#define  AD16C4T_SMCON_TSSEL_POSE  6U
#define  AD16C4T_SMCON_TSSEL_MSK  BITS(AD16C4T_SMCON_TSSEL_POSS,AD16C4T_SMCON_TSSEL_POSE)

#define  AD16C4T_SMCON_CHCSEL_POS  3U
#define  AD16C4T_SMCON_CHCSEL_MSK  BIT(AD16C4T_SMCON_CHCSEL_POS)

#define  AD16C4T_SMCON_SMODS_POSS  0U
#define  AD16C4T_SMCON_SMODS_POSE  2U
#define  AD16C4T_SMCON_SMODS_MSK  BITS(AD16C4T_SMCON_SMODS_POSS,AD16C4T_SMCON_SMODS_POSE)

/****************** Bit definition for AD16C4T_IER register ************************/

#define  AD16C4T_IER_CH4OVI_POS  12U
#define  AD16C4T_IER_CH4OVI_MSK  BIT(AD16C4T_IER_CH4OVI_POS)

#define  AD16C4T_IER_CH3OVI_POS  11U
#define  AD16C4T_IER_CH3OVI_MSK  BIT(AD16C4T_IER_CH3OVI_POS)

#define  AD16C4T_IER_CH2OVI_POS  10U
#define  AD16C4T_IER_CH2OVI_MSK  BIT(AD16C4T_IER_CH2OVI_POS)

#define  AD16C4T_IER_CH1OVI_POS  9U
#define  AD16C4T_IER_CH1OVI_MSK  BIT(AD16C4T_IER_CH1OVI_POS)

#define  AD16C4T_IER_BRKI_POS  7U
#define  AD16C4T_IER_BRKI_MSK  BIT(AD16C4T_IER_BRKI_POS)

#define  AD16C4T_IER_TRGI_POS  6U
#define  AD16C4T_IER_TRGI_MSK  BIT(AD16C4T_IER_TRGI_POS)

#define  AD16C4T_IER_COMI_POS  5U
#define  AD16C4T_IER_COMI_MSK  BIT(AD16C4T_IER_COMI_POS)

#define  AD16C4T_IER_CH4I_POS  4U
#define  AD16C4T_IER_CH4I_MSK  BIT(AD16C4T_IER_CH4I_POS)

#define  AD16C4T_IER_CH3I_POS  3U
#define  AD16C4T_IER_CH3I_MSK  BIT(AD16C4T_IER_CH3I_POS)

#define  AD16C4T_IER_CH2I_POS  2U
#define  AD16C4T_IER_CH2I_MSK  BIT(AD16C4T_IER_CH2I_POS)

#define  AD16C4T_IER_CH1I_POS  1U
#define  AD16C4T_IER_CH1I_MSK  BIT(AD16C4T_IER_CH1I_POS)

#define  AD16C4T_IER_UI_POS  0U
#define  AD16C4T_IER_UI_MSK  BIT(AD16C4T_IER_UI_POS)

/****************** Bit definition for AD16C4T_IDR register ************************/

#define  AD16C4T_IDR_CH4OVI_POS  12U
#define  AD16C4T_IDR_CH4OVI_MSK  BIT(AD16C4T_IDR_CH4OVI_POS)

#define  AD16C4T_IDR_CH3OVI_POS  11U
#define  AD16C4T_IDR_CH3OVI_MSK  BIT(AD16C4T_IDR_CH3OVI_POS)

#define  AD16C4T_IDR_CH2OVI_POS  10U
#define  AD16C4T_IDR_CH2OVI_MSK  BIT(AD16C4T_IDR_CH2OVI_POS)

#define  AD16C4T_IDR_CH1OVI_POS  9U
#define  AD16C4T_IDR_CH1OVI_MSK  BIT(AD16C4T_IDR_CH1OVI_POS)

#define  AD16C4T_IDR_BRKI_POS  7U
#define  AD16C4T_IDR_BRKI_MSK  BIT(AD16C4T_IDR_BRKI_POS)

#define  AD16C4T_IDR_TRGI_POS  6U
#define  AD16C4T_IDR_TRGI_MSK  BIT(AD16C4T_IDR_TRGI_POS)

#define  AD16C4T_IDR_COMI_POS  5U
#define  AD16C4T_IDR_COMI_MSK  BIT(AD16C4T_IDR_COMI_POS)

#define  AD16C4T_IDR_CH4I_POS  4U
#define  AD16C4T_IDR_CH4I_MSK  BIT(AD16C4T_IDR_CH4I_POS)

#define  AD16C4T_IDR_CH3I_POS  3U
#define  AD16C4T_IDR_CH3I_MSK  BIT(AD16C4T_IDR_CH3I_POS)

#define  AD16C4T_IDR_CH2I_POS  2U
#define  AD16C4T_IDR_CH2I_MSK  BIT(AD16C4T_IDR_CH2I_POS)

#define  AD16C4T_IDR_CH1I_POS  1U
#define  AD16C4T_IDR_CH1I_MSK  BIT(AD16C4T_IDR_CH1I_POS)

#define  AD16C4T_IDR_UI_POS  0U
#define  AD16C4T_IDR_UI_MSK  BIT(AD16C4T_IDR_UI_POS)

/****************** Bit definition for AD16C4T_IVS register ************************/

#define  AD16C4T_IVS_CH4OVI_POS  12U
#define  AD16C4T_IVS_CH4OVI_MSK  BIT(AD16C4T_IVS_CH4OVI_POS)

#define  AD16C4T_IVS_CH3OVI_POS  11U
#define  AD16C4T_IVS_CH3OVI_MSK  BIT(AD16C4T_IVS_CH3OVI_POS)

#define  AD16C4T_IVS_CH2OVI_POS  10U
#define  AD16C4T_IVS_CH2OVI_MSK  BIT(AD16C4T_IVS_CH2OVI_POS)

#define  AD16C4T_IVS_CH1OVI_POS  9U
#define  AD16C4T_IVS_CH1OVI_MSK  BIT(AD16C4T_IVS_CH1OVI_POS)

#define  AD16C4T_IVS_BRKI_POS  7U
#define  AD16C4T_IVS_BRKI_MSK  BIT(AD16C4T_IVS_BRKI_POS)

#define  AD16C4T_IVS_TRGI_POS  6U
#define  AD16C4T_IVS_TRGI_MSK  BIT(AD16C4T_IVS_TRGI_POS)

#define  AD16C4T_IVS_COMI_POS  5U
#define  AD16C4T_IVS_COMI_MSK  BIT(AD16C4T_IVS_COMI_POS)

#define  AD16C4T_IVS_CH4I_POS  4U
#define  AD16C4T_IVS_CH4I_MSK  BIT(AD16C4T_IVS_CH4I_POS)

#define  AD16C4T_IVS_CH3I_POS  3U
#define  AD16C4T_IVS_CH3I_MSK  BIT(AD16C4T_IVS_CH3I_POS)

#define  AD16C4T_IVS_CH2I_POS  2U
#define  AD16C4T_IVS_CH2I_MSK  BIT(AD16C4T_IVS_CH2I_POS)

#define  AD16C4T_IVS_CH1I_POS  1U
#define  AD16C4T_IVS_CH1I_MSK  BIT(AD16C4T_IVS_CH1I_POS)

#define  AD16C4T_IVS_UI_POS  0U
#define  AD16C4T_IVS_UI_MSK  BIT(AD16C4T_IVS_UI_POS)

/****************** Bit definition for AD16C4T_RIF register ************************/

#define  AD16C4T_RIF_CH4OVI_POS  12U
#define  AD16C4T_RIF_CH4OVI_MSK  BIT(AD16C4T_RIF_CH4OVI_POS)

#define  AD16C4T_RIF_CH3OVI_POS  11U
#define  AD16C4T_RIF_CH3OVI_MSK  BIT(AD16C4T_RIF_CH3OVI_POS)

#define  AD16C4T_RIF_CH2OVI_POS  10U
#define  AD16C4T_RIF_CH2OVI_MSK  BIT(AD16C4T_RIF_CH2OVI_POS)

#define  AD16C4T_RIF_CH1OVI_POS  9U
#define  AD16C4T_RIF_CH1OVI_MSK  BIT(AD16C4T_RIF_CH1OVI_POS)

#define  AD16C4T_RIF_BRKI_POS  7U
#define  AD16C4T_RIF_BRKI_MSK  BIT(AD16C4T_RIF_BRKI_POS)

#define  AD16C4T_RIF_TRGI_POS  6U
#define  AD16C4T_RIF_TRGI_MSK  BIT(AD16C4T_RIF_TRGI_POS)

#define  AD16C4T_RIF_COMI_POS  5U
#define  AD16C4T_RIF_COMI_MSK  BIT(AD16C4T_RIF_COMI_POS)

#define  AD16C4T_RIF_CH4I_POS  4U
#define  AD16C4T_RIF_CH4I_MSK  BIT(AD16C4T_RIF_CH4I_POS)

#define  AD16C4T_RIF_CH3I_POS  3U
#define  AD16C4T_RIF_CH3I_MSK  BIT(AD16C4T_RIF_CH3I_POS)

#define  AD16C4T_RIF_CH2I_POS  2U
#define  AD16C4T_RIF_CH2I_MSK  BIT(AD16C4T_RIF_CH2I_POS)

#define  AD16C4T_RIF_CH1I_POS  1U
#define  AD16C4T_RIF_CH1I_MSK  BIT(AD16C4T_RIF_CH1I_POS)

#define  AD16C4T_RIF_UI_POS  0U
#define  AD16C4T_RIF_UI_MSK  BIT(AD16C4T_RIF_UI_POS)

/****************** Bit definition for AD16C4T_IFM register ************************/

#define  AD16C4T_IFM_CH4OVI_POS  12U
#define  AD16C4T_IFM_CH4OVI_MSK  BIT(AD16C4T_IFM_CH4OVI_POS)

#define  AD16C4T_IFM_CH3OVI_POS  11U
#define  AD16C4T_IFM_CH3OVI_MSK  BIT(AD16C4T_IFM_CH3OVI_POS)

#define  AD16C4T_IFM_CH2OVI_POS  10U
#define  AD16C4T_IFM_CH2OVI_MSK  BIT(AD16C4T_IFM_CH2OVI_POS)

#define  AD16C4T_IFM_CH1OVI_POS  9U
#define  AD16C4T_IFM_CH1OVI_MSK  BIT(AD16C4T_IFM_CH1OVI_POS)

#define  AD16C4T_IFM_BRKI_POS  7U
#define  AD16C4T_IFM_BRKI_MSK  BIT(AD16C4T_IFM_BRKI_POS)

#define  AD16C4T_IFM_TRGI_POS  6U
#define  AD16C4T_IFM_TRGI_MSK  BIT(AD16C4T_IFM_TRGI_POS)

#define  AD16C4T_IFM_COMI_POS  5U
#define  AD16C4T_IFM_COMI_MSK  BIT(AD16C4T_IFM_COMI_POS)

#define  AD16C4T_IFM_CH4I_POS  4U
#define  AD16C4T_IFM_CH4I_MSK  BIT(AD16C4T_IFM_CH4I_POS)

#define  AD16C4T_IFM_CH3I_POS  3U
#define  AD16C4T_IFM_CH3I_MSK  BIT(AD16C4T_IFM_CH3I_POS)

#define  AD16C4T_IFM_CH2I_POS  2U
#define  AD16C4T_IFM_CH2I_MSK  BIT(AD16C4T_IFM_CH2I_POS)

#define  AD16C4T_IFM_CH1I_POS  1U
#define  AD16C4T_IFM_CH1I_MSK  BIT(AD16C4T_IFM_CH1I_POS)

#define  AD16C4T_IFM_UI_POS  0U
#define  AD16C4T_IFM_UI_MSK  BIT(AD16C4T_IFM_UI_POS)

/****************** Bit definition for AD16C4T_ICR register ************************/

#define  AD16C4T_ICR_CH4OVI_POS  12U
#define  AD16C4T_ICR_CH4OVI_MSK  BIT(AD16C4T_ICR_CH4OVI_POS)

#define  AD16C4T_ICR_CH3OVI_POS  11U
#define  AD16C4T_ICR_CH3OVI_MSK  BIT(AD16C4T_ICR_CH3OVI_POS)

#define  AD16C4T_ICR_CH2OVI_POS  10U
#define  AD16C4T_ICR_CH2OVI_MSK  BIT(AD16C4T_ICR_CH2OVI_POS)

#define  AD16C4T_ICR_CH1OVI_POS  9U
#define  AD16C4T_ICR_CH1OVI_MSK  BIT(AD16C4T_ICR_CH1OVI_POS)

#define  AD16C4T_ICR_BRKI_POS  7U
#define  AD16C4T_ICR_BRKI_MSK  BIT(AD16C4T_ICR_BRKI_POS)

#define  AD16C4T_ICR_TRGI_POS  6U
#define  AD16C4T_ICR_TRGI_MSK  BIT(AD16C4T_ICR_TRGI_POS)

#define  AD16C4T_ICR_COMI_POS  5U
#define  AD16C4T_ICR_COMI_MSK  BIT(AD16C4T_ICR_COMI_POS)

#define  AD16C4T_ICR_CH4I_POS  4U
#define  AD16C4T_ICR_CH4I_MSK  BIT(AD16C4T_ICR_CH4I_POS)

#define  AD16C4T_ICR_CH3I_POS  3U
#define  AD16C4T_ICR_CH3I_MSK  BIT(AD16C4T_ICR_CH3I_POS)

#define  AD16C4T_ICR_CH2I_POS  2U
#define  AD16C4T_ICR_CH2I_MSK  BIT(AD16C4T_ICR_CH2I_POS)

#define  AD16C4T_ICR_CH1I_POS  1U
#define  AD16C4T_ICR_CH1I_MSK  BIT(AD16C4T_ICR_CH1I_POS)

#define  AD16C4T_ICR_UI_POS  0U
#define  AD16C4T_ICR_UI_MSK  BIT(AD16C4T_ICR_UI_POS)

/****************** Bit definition for AD16C4T_SGE register ************************/

#define  AD16C4T_SGE_SGBRK_POS  7U
#define  AD16C4T_SGE_SGBRK_MSK  BIT(AD16C4T_SGE_SGBRK_POS)

#define  AD16C4T_SGE_SGTRG_POS  6U
#define  AD16C4T_SGE_SGTRG_MSK  BIT(AD16C4T_SGE_SGTRG_POS)

#define  AD16C4T_SGE_SGCOM_POS  5U
#define  AD16C4T_SGE_SGCOM_MSK  BIT(AD16C4T_SGE_SGCOM_POS)

#define  AD16C4T_SGE_SGCH4_POS  4U
#define  AD16C4T_SGE_SGCH4_MSK  BIT(AD16C4T_SGE_SGCH4_POS)

#define  AD16C4T_SGE_SGCH3_POS  3U
#define  AD16C4T_SGE_SGCH3_MSK  BIT(AD16C4T_SGE_SGCH3_POS)

#define  AD16C4T_SGE_SGCH2_POS  2U
#define  AD16C4T_SGE_SGCH2_MSK  BIT(AD16C4T_SGE_SGCH2_POS)

#define  AD16C4T_SGE_SGCH1_POS  1U
#define  AD16C4T_SGE_SGCH1_MSK  BIT(AD16C4T_SGE_SGCH1_POS)

#define  AD16C4T_SGE_SGU_POS  0U
#define  AD16C4T_SGE_SGU_MSK  BIT(AD16C4T_SGE_SGU_POS)

/****************** Bit definition for AD16C4T_CHMR1_OUTPUT register ************************/

#define AD16C4T_CHMR1_OUTPUT_CH2OCLREN_POS 15U
#define AD16C4T_CHMR1_OUTPUT_CH2OCLREN_MSK BIT(AD16C4T_CHMR1_OUTPUT_CH2OCLREN_POS)

#define AD16C4T_CHMR1_OUTPUT_CH2MOD_POSS 12U
#define AD16C4T_CHMR1_OUTPUT_CH2MOD_POSE 14U
#define AD16C4T_CHMR1_OUTPUT_CH2MOD_MSK BITS(AD16C4T_CHMR1_OUTPUT_CH2MOD_POSS,AD16C4T_CHMR1_OUTPUT_CH2MOD_POSE)

#define AD16C4T_CHMR1_OUTPUT_CH2PEN_POS 11U
#define AD16C4T_CHMR1_OUTPUT_CH2PEN_MSK BIT(AD16C4T_CHMR1_OUTPUT_CH2PEN_POS)

#define AD16C4T_CHMR1_OUTPUT_CH2FEN_POS 10U
#define AD16C4T_CHMR1_OUTPUT_CH2FEN_MSK BIT(AD16C4T_CHMR1_OUTPUT_CH2FEN_POS)

#define AD16C4T_CHMR1_OUTPUT_CC2SSEL_POSS 8U
#define AD16C4T_CHMR1_OUTPUT_CC2SSEL_POSE 9U
#define AD16C4T_CHMR1_OUTPUT_CC2SSEL_MSK BITS(AD16C4T_CHMR1_OUTPUT_CC2SSEL_POSS,AD16C4T_CHMR1_OUTPUT_CC2SSEL_POSE)

#define AD16C4T_CHMR1_OUTPUT_CH1OCLREN_POS 7U
#define AD16C4T_CHMR1_OUTPUT_CH1OCLREN_MSK BIT(AD16C4T_CHMR1_OUTPUT_CH1OCLREN_POS)

#define AD16C4T_CHMR1_OUTPUT_CH1MOD_POSS 4U
#define AD16C4T_CHMR1_OUTPUT_CH1MOD_POSE 6U
#define AD16C4T_CHMR1_OUTPUT_CH1MOD_MSK BITS(AD16C4T_CHMR1_OUTPUT_CH1MOD_POSS,AD16C4T_CHMR1_OUTPUT_CH1MOD_POSE)

#define AD16C4T_CHMR1_OUTPUT_CH1PEN_POS 3U
#define AD16C4T_CHMR1_OUTPUT_CH1PEN_MSK BIT(AD16C4T_CHMR1_OUTPUT_CH1PEN_POS)

#define AD16C4T_CHMR1_OUTPUT_CH1FEN_POS 2U
#define AD16C4T_CHMR1_OUTPUT_CH1FEN_MSK BIT(AD16C4T_CHMR1_OUTPUT_CH1FEN_POS)

#define AD16C4T_CHMR1_OUTPUT_CC1SSEL_POSS 0U
#define AD16C4T_CHMR1_OUTPUT_CC1SSEL_POSE 1U
#define AD16C4T_CHMR1_OUTPUT_CC1SSEL_MSK BITS(AD16C4T_CHMR1_OUTPUT_CC1SSEL_POSS,AD16C4T_CHMR1_OUTPUT_CC1SSEL_POSE)

/****************** Bit definition for AD16C4T_CHMR1_INPUT register ************************/

#define AD16C4T_CHMR1_INPUT_I2FLT_POSS 12U
#define AD16C4T_CHMR1_INPUT_I2FLT_POSE 15U
#define AD16C4T_CHMR1_INPUT_I2FLT_MSK BITS(AD16C4T_CHMR1_INPUT_I2FLT_POSS,AD16C4T_CHMR1_INPUT_I2FLT_POSE)

#define AD16C4T_CHMR1_INPUT_I2PRES_POSS 10U
#define AD16C4T_CHMR1_INPUT_I2PRES_POSE 11U
#define AD16C4T_CHMR1_INPUT_I2PRES_MSK BITS(AD16C4T_CHMR1_INPUT_I2PRES_POSS,AD16C4T_CHMR1_INPUT_I2PRES_POSE)

#define AD16C4T_CHMR1_INPUT_CC2SSEL_POSS 8U
#define AD16C4T_CHMR1_INPUT_CC2SSEL_POSE 9U
#define AD16C4T_CHMR1_INPUT_CC2SSEL_MSK BITS(AD16C4T_CHMR1_INPUT_CC2SSEL_POSS,AD16C4T_CHMR1_INPUT_CC2SSEL_POSE)

#define AD16C4T_CHMR1_INPUT_I1FLT_POSS 4U
#define AD16C4T_CHMR1_INPUT_I1FLT_POSE 7U
#define AD16C4T_CHMR1_INPUT_I1FLT_MSK BITS(AD16C4T_CHMR1_INPUT_I1FLT_POSS,AD16C4T_CHMR1_INPUT_I1FLT_POSE)

#define AD16C4T_CHMR1_INPUT_I1PRES_POSS 2U
#define AD16C4T_CHMR1_INPUT_I1PRES_POSE 3U
#define AD16C4T_CHMR1_INPUT_I1PRES_MSK BITS(AD16C4T_CHMR1_INPUT_I1PRES_POSS,AD16C4T_CHMR1_INPUT_I1PRES_POSE)

#define AD16C4T_CHMR1_INPUT_CC1SSEL_POSS 0U
#define AD16C4T_CHMR1_INPUT_CC1SSEL_POSE 1U
#define AD16C4T_CHMR1_INPUT_CC1SSEL_MSK BITS(AD16C4T_CHMR1_INPUT_CC1SSEL_POSS,AD16C4T_CHMR1_INPUT_CC1SSEL_POSE)

/****************** Bit definition for AD16C4T_CHMR2_OUTPUT register ************************/

#define AD16C4T_CHMR2_OUTPUT_CH4OCLREN_POS 15U
#define AD16C4T_CHMR2_OUTPUT_CH4OCLREN_MSK BIT(AD16C4T_CHMR2_OUTPUT_CH4OCLREN_POS)

#define AD16C4T_CHMR2_OUTPUT_CH4MOD_POSS 12U
#define AD16C4T_CHMR2_OUTPUT_CH4MOD_POSE 14U
#define AD16C4T_CHMR2_OUTPUT_CH4MOD_MSK BITS(AD16C4T_CHMR2_OUTPUT_CH4MOD_POSS,AD16C4T_CHMR2_OUTPUT_CH4MOD_POSE)

#define AD16C4T_CHMR2_OUTPUT_CH4PEN_POS 11U
#define AD16C4T_CHMR2_OUTPUT_CH4PEN_MSK BIT(AD16C4T_CHMR2_OUTPUT_CH4PEN_POS)

#define AD16C4T_CHMR2_OUTPUT_CH4FEN_POS 10U
#define AD16C4T_CHMR2_OUTPUT_CH4FEN_MSK BIT(AD16C4T_CHMR2_OUTPUT_CH4FEN_POS)

#define AD16C4T_CHMR2_OUTPUT_CC4SSEL_POSS 8U
#define AD16C4T_CHMR2_OUTPUT_CC4SSEL_POSE 9U
#define AD16C4T_CHMR2_OUTPUT_CC4SSEL_MSK BITS(AD16C4T_CHMR2_OUTPUT_CC4SSEL_POSS,AD16C4T_CHMR2_OUTPUT_CC4SSEL_POSE)

#define AD16C4T_CHMR2_OUTPUT_CH3OCLREN_POS 7U
#define AD16C4T_CHMR2_OUTPUT_CH3OCLREN_MSK BIT(AD16C4T_CHMR2_OUTPUT_CH3OCLREN_POS)

#define AD16C4T_CHMR2_OUTPUT_CH3MOD_POSS 4U
#define AD16C4T_CHMR2_OUTPUT_CH3MOD_POSE 6U
#define AD16C4T_CHMR2_OUTPUT_CH3MOD_MSK BITS(AD16C4T_CHMR2_OUTPUT_CH3MOD_POSS,AD16C4T_CHMR2_OUTPUT_CH3MOD_POSE)

#define AD16C4T_CHMR2_OUTPUT_CH3PEN_POS 3U
#define AD16C4T_CHMR2_OUTPUT_CH3PEN_MSK BIT(AD16C4T_CHMR2_OUTPUT_CH3PEN_POS)

#define AD16C4T_CHMR2_OUTPUT_CH3FEN_POS 2U
#define AD16C4T_CHMR2_OUTPUT_CH3FEN_MSK BIT(AD16C4T_CHMR2_OUTPUT_CH3FEN_POS)

#define AD16C4T_CHMR2_OUTPUT_CC3SSEL_POSS 0U
#define AD16C4T_CHMR2_OUTPUT_CC3SSEL_POSE 1U
#define AD16C4T_CHMR2_OUTPUT_CC3SSEL_MSK BITS(AD16C4T_CHMR2_OUTPUT_CC3SSEL_POSS,AD16C4T_CHMR2_OUTPUT_CC3SSEL_POSE)

/****************** Bit definition for AD16C4T_CHMR2_INPUT register ************************/

#define AD16C4T_CHMR2_INPUT_I4FLT_POSS 12U
#define AD16C4T_CHMR2_INPUT_I4FLT_POSE 15U
#define AD16C4T_CHMR2_INPUT_I4FLT_MSK BITS(AD16C4T_CHMR2_INPUT_I4FLT_POSS,AD16C4T_CHMR2_INPUT_I4FLT_POSE)

#define AD16C4T_CHMR2_INPUT_I4PRES_POSS 10U
#define AD16C4T_CHMR2_INPUT_I4PRES_POSE 11U
#define AD16C4T_CHMR2_INPUT_I4PRES_MSK BITS(AD16C4T_CHMR2_INPUT_I4PRES_POSS,AD16C4T_CHMR2_INPUT_I4PRES_POSE)

#define AD16C4T_CHMR2_INPUT_CC4SSEL_POSS 8U
#define AD16C4T_CHMR2_INPUT_CC4SSEL_POSE 9U
#define AD16C4T_CHMR2_INPUT_CC4SSEL_MSK BITS(AD16C4T_CHMR2_INPUT_CC4SSEL_POSS,AD16C4T_CHMR2_INPUT_CC4SSEL_POSE)

#define AD16C4T_CHMR2_INPUT_I3FLT_POSS 4U
#define AD16C4T_CHMR2_INPUT_I3FLT_POSE 7U
#define AD16C4T_CHMR2_INPUT_I3FLT_MSK BITS(AD16C4T_CHMR2_INPUT_I3FLT_POSS,AD16C4T_CHMR2_INPUT_I3FLT_POSE)

#define AD16C4T_CHMR2_INPUT_I3PRES_POSS 2U
#define AD16C4T_CHMR2_INPUT_I3PRES_POSE 3U
#define AD16C4T_CHMR2_INPUT_I3PRES_MSK BITS(AD16C4T_CHMR2_INPUT_I3PRES_POSS,AD16C4T_CHMR2_INPUT_I3PRES_POSE)

#define AD16C4T_CHMR2_INPUT_CC3SSEL_POSS 0U
#define AD16C4T_CHMR2_INPUT_CC3SSEL_POSE 1U
#define AD16C4T_CHMR2_INPUT_CC3SSEL_MSK BITS(AD16C4T_CHMR2_INPUT_CC3SSEL_POSS,AD16C4T_CHMR2_INPUT_CC3SSEL_POSE)

/****************** Bit definition for AD16C4T_CCEP register ************************/

#define  AD16C4T_CCEP_CC4NPOL_POS  15U
#define  AD16C4T_CCEP_CC4NPOL_MSK  BIT(AD16C4T_CCEP_CC4NPOL_POS)

#define  AD16C4T_CCEP_CC4POL_POS  13U
#define  AD16C4T_CCEP_CC4POL_MSK  BIT(AD16C4T_CCEP_CC4POL_POS)

#define  AD16C4T_CCEP_CC4EN_POS  12U
#define  AD16C4T_CCEP_CC4EN_MSK  BIT(AD16C4T_CCEP_CC4EN_POS)

#define  AD16C4T_CCEP_CC3NPOL_POS  11U
#define  AD16C4T_CCEP_CC3NPOL_MSK  BIT(AD16C4T_CCEP_CC3NPOL_POS)

#define  AD16C4T_CCEP_CC3NEN_POS  10U
#define  AD16C4T_CCEP_CC3NEN_MSK  BIT(AD16C4T_CCEP_CC3NEN_POS)

#define  AD16C4T_CCEP_CC3POL_POS  9U
#define  AD16C4T_CCEP_CC3POL_MSK  BIT(AD16C4T_CCEP_CC3POL_POS)

#define  AD16C4T_CCEP_CC3EN_POS  8U
#define  AD16C4T_CCEP_CC3EN_MSK  BIT(AD16C4T_CCEP_CC3EN_POS)

#define  AD16C4T_CCEP_CC2NPOL_POS  7U
#define  AD16C4T_CCEP_CC2NPOL_MSK  BIT(AD16C4T_CCEP_CC2NPOL_POS)

#define  AD16C4T_CCEP_CC2NEN_POS  6U
#define  AD16C4T_CCEP_CC2NEN_MSK  BIT(AD16C4T_CCEP_CC2NEN_POS)

#define  AD16C4T_CCEP_CC2POL_POS  5U
#define  AD16C4T_CCEP_CC2POL_MSK  BIT(AD16C4T_CCEP_CC2POL_POS)

#define  AD16C4T_CCEP_CC2EN_POS  4U
#define  AD16C4T_CCEP_CC2EN_MSK  BIT(AD16C4T_CCEP_CC2EN_POS)

#define  AD16C4T_CCEP_CC1NPOL_POS  3U
#define  AD16C4T_CCEP_CC1NPOL_MSK  BIT(AD16C4T_CCEP_CC1NPOL_POS)

#define  AD16C4T_CCEP_CC1NEN_POS  2U
#define  AD16C4T_CCEP_CC1NEN_MSK  BIT(AD16C4T_CCEP_CC1NEN_POS)

#define  AD16C4T_CCEP_CC1POL_POS  1U
#define  AD16C4T_CCEP_CC1POL_MSK  BIT(AD16C4T_CCEP_CC1POL_POS)

#define  AD16C4T_CCEP_CC1EN_POS  0U
#define  AD16C4T_CCEP_CC1EN_MSK  BIT(AD16C4T_CCEP_CC1EN_POS)

/****************** Bit definition for AD16C4T_COUNT register ************************/

#define  AD16C4T_COUNT_CNTV_POSS  0U
#define  AD16C4T_COUNT_CNTV_POSE  15U
#define  AD16C4T_COUNT_CNTV_MSK  BITS(AD16C4T_COUNT_CNTV_POSS,AD16C4T_COUNT_CNTV_POSE)

/****************** Bit definition for AD16C4T_PRES register ************************/

#define  AD16C4T_PRES_PSCV_POSS  0U
#define  AD16C4T_PRES_PSCV_POSE  15U
#define  AD16C4T_PRES_PSCV_MSK  BITS(AD16C4T_PRES_PSCV_POSS,AD16C4T_PRES_PSCV_POSE)

/****************** Bit definition for AD16C4T_AR register ************************/

#define  AD16C4T_AR_ARV_POSS  0U
#define  AD16C4T_AR_ARV_POSE  15U
#define  AD16C4T_AR_ARV_MSK  BITS(AD16C4T_AR_ARV_POSS,AD16C4T_AR_ARV_POSE)

/****************** Bit definition for AD16C4T_REPAR register ************************/

#define  AD16C4T_REPAR_REPV_POSS  0U
#define  AD16C4T_REPAR_REPV_POSE  7U
#define  AD16C4T_REPAR_REPV_MSK  BITS(AD16C4T_REPAR_REPV_POSS,AD16C4T_REPAR_REPV_POSE)

/****************** Bit definition for AD16C4T_CCVAL1 register ************************/

#define  AD16C4T_CCVAL1_CCRV1_POSS  0U
#define  AD16C4T_CCVAL1_CCRV1_POSE  15U
#define  AD16C4T_CCVAL1_CCRV1_MSK  BITS(AD16C4T_CCVAL1_CCRV1_POSS,AD16C4T_CCVAL1_CCRV1_POSE)

/****************** Bit definition for AD16C4T_CCVAL2 register ************************/

#define  AD16C4T_CCVAL2_CCRV2_POSS  0U
#define  AD16C4T_CCVAL2_CCRV2_POSE  15U
#define  AD16C4T_CCVAL2_CCRV2_MSK  BITS(AD16C4T_CCVAL2_CCRV2_POSS,AD16C4T_CCVAL2_CCRV2_POSE)

/****************** Bit definition for AD16C4T_CCVAL3 register ************************/

#define  AD16C4T_CCVAL3_CCRV3_POSS  0U
#define  AD16C4T_CCVAL3_CCRV3_POSE  15U
#define  AD16C4T_CCVAL3_CCRV3_MSK  BITS(AD16C4T_CCVAL3_CCRV3_POSS,AD16C4T_CCVAL3_CCRV3_POSE)

/****************** Bit definition for AD16C4T_CCVAL4 register ************************/

#define  AD16C4T_CCVAL4_CCRV4_POSS  0U
#define  AD16C4T_CCVAL4_CCRV4_POSE  15U
#define  AD16C4T_CCVAL4_CCRV4_MSK  BITS(AD16C4T_CCVAL4_CCRV4_POSS,AD16C4T_CCVAL4_CCRV4_POSE)

/****************** Bit definition for AD16C4T_BDCFG register ************************/

#define  AD16C4T_BDCFG_GOEN_POS  15U
#define  AD16C4T_BDCFG_GOEN_MSK  BIT(AD16C4T_BDCFG_GOEN_POS)

#define  AD16C4T_BDCFG_AOEN_POS  14U
#define  AD16C4T_BDCFG_AOEN_MSK  BIT(AD16C4T_BDCFG_AOEN_POS)

#define  AD16C4T_BDCFG_BRKP_POS  13U
#define  AD16C4T_BDCFG_BRKP_MSK  BIT(AD16C4T_BDCFG_BRKP_POS)

#define  AD16C4T_BDCFG_BRKEN_POS  12U
#define  AD16C4T_BDCFG_BRKEN_MSK  BIT(AD16C4T_BDCFG_BRKEN_POS)

#define  AD16C4T_BDCFG_OFFSSR_POS  11U
#define  AD16C4T_BDCFG_OFFSSR_MSK  BIT(AD16C4T_BDCFG_OFFSSR_POS)

#define  AD16C4T_BDCFG_OFFSSI_POS  10U
#define  AD16C4T_BDCFG_OFFSSI_MSK  BIT(AD16C4T_BDCFG_OFFSSI_POS)

#define  AD16C4T_BDCFG_LOCKLVL_POSS  8U
#define  AD16C4T_BDCFG_LOCKLVL_POSE  9U
#define  AD16C4T_BDCFG_LOCKLVL_MSK  BITS(AD16C4T_BDCFG_LOCKLVL_POSS,AD16C4T_BDCFG_LOCKLVL_POSE)

#define  AD16C4T_BDCFG_DT_POSS  0U
#define  AD16C4T_BDCFG_DT_POSE  7U
#define  AD16C4T_BDCFG_DT_MSK  BITS(AD16C4T_BDCFG_DT_POSS,AD16C4T_BDCFG_DT_POSE)

/****************** Bit definition for AD16C4T_DMAEN register ************************/

#define  AD16C4T_DMAEN_TRGIDE_POS  6U
#define  AD16C4T_DMAEN_TRGIDE_MSK  BIT(AD16C4T_DMAEN_TRGIDE_POS)

#define  AD16C4T_DMAEN_COMDE_POS  5U
#define  AD16C4T_DMAEN_COMDE_MSK  BIT(AD16C4T_DMAEN_COMDE_POS)

#define  AD16C4T_DMAEN_CH4DE_POS  4U
#define  AD16C4T_DMAEN_CH4DE_MSK  BIT(AD16C4T_DMAEN_CH4DE_POS)

#define  AD16C4T_DMAEN_CH3DE_POS  3U
#define  AD16C4T_DMAEN_CH3DE_MSK  BIT(AD16C4T_DMAEN_CH3DE_POS)

#define  AD16C4T_DMAEN_CH2DE_POS  2U
#define  AD16C4T_DMAEN_CH2DE_MSK  BIT(AD16C4T_DMAEN_CH2DE_POS)

#define  AD16C4T_DMAEN_CH1DE_POS  1U
#define  AD16C4T_DMAEN_CH1DE_MSK  BIT(AD16C4T_DMAEN_CH1DE_POS)

#define  AD16C4T_DMAEN_UDE_POS  0U
#define  AD16C4T_DMAEN_UDE_MSK  BIT(AD16C4T_DMAEN_UDE_POS)

typedef struct
{
  __IO uint32_t CON1;         /* 0x000 AD16C4T_CON1   Control register 1                */
  __IO uint32_t CON2;         /* 0x004 AD16C4T_CON2   Control register 2                */
  __IO uint32_t SMCON;        /* 0x008 AD16C4T_SMCON  Slave mode control register       */
  __O uint32_t IER;           /* 0x00C AD16C4T_IER    Interrupt Enable register         */
  __O uint32_t IDR;           /* 0x010 AD16C4T_IDR    Interrupt Disable register        */
  __I uint32_t IVS;           /* 0x014 AD16C4T_IVS    Interrupt Valid status register   */
  __I uint32_t RIF;           /* 0x018 AD16C4T_RIF    Interrupt Raw interrupt Flag      */
  __I uint32_t IFM;           /* 0x01C AD16C4T_IFM    Interrupt Masked interrupt Flag   */
  __O uint32_t ICR;           /* 0x020 AD16C4T_ICR    Interrupt Clear status register   */
  __O uint32_t SGE;           /* 0x024 AD16C4T_SGE    Event generation register         */
    __IO uint32_t CHMR1;        /* 0x028 AD16C4T_CHMR1  Capture/compare mode register 1   */
    __IO uint32_t CHMR2;        /* 0x02C AD16C4T_CHMR2  Capture/compare mode register 2   */
  __IO uint32_t CCEP;         /* 0x030 AD16C4T_CCEP   Capture/compare enable register   */
  __IO uint32_t COUNT;        /* 0x034 AD16C4T_COUNT  Timer Counter                     */
  __IO uint32_t PRES;         /* 0x038 AD16C4T_PRES   Prescaler                         */
  __IO uint32_t AR;           /* 0x03C AD16C4T_AR     Auto-reload register              */
  __IO uint32_t REPAR;        /* 0x040 AD16C4T_REPAR  Repetition counter register       */
  __IO uint32_t CCVAL1;       /* 0x044 AD16C4T_CCVAL1 Capture/compare register 1        */
  __IO uint32_t CCVAL2;       /* 0x048 AD16C4T_CCVAL2 Capture/compare register 2        */
  __IO uint32_t CCVAL3;       /* 0x04C AD16C4T_CCVAL3 Capture/compare register 3        */
  __IO uint32_t CCVAL4;       /* 0x050 AD16C4T_CCVAL4 Capture/compare register 4        */
  __IO uint32_t BDCFG;        /* 0x054 AD16C4T_BDCFG  Break and dead-time register      */
  __IO uint32_t DMAEN;        /* 0x058 AD16C4T_DMAEN  DMA trigger event enable          */
} AD16C4T_TypeDef;

#endif
/******************* (C) COPYRIGHT Eastsoft Microelectronics END OF REG_AD16C4T.H****/

