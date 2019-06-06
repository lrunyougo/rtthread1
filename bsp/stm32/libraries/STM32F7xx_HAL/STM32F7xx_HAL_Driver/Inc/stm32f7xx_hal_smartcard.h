/**
  ******************************************************************************
  * @file    stm32f7xx_hal_smartcard.h
  * @author  MCD Application Team
  * @brief   Header file of SMARTCARD HAL module.
  ******************************************************************************
  * @attention
  *
<<<<<<< HEAD
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=======
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
<<<<<<< HEAD
#ifndef __STM32F7xx_HAL_SMARTCARD_H
#define __STM32F7xx_HAL_SMARTCARD_H

#ifdef __cplusplus
 extern "C" {
=======
#ifndef STM32F7xx_HAL_SMARTCARD_H
#define STM32F7xx_HAL_SMARTCARD_H

#ifdef __cplusplus
extern "C" {
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal_def.h"

/** @addtogroup STM32F7xx_HAL_Driver
  * @{
  */

/** @addtogroup SMARTCARD
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup SMARTCARD_Exported_Types SMARTCARD Exported Types
  * @{
  */

/**
  * @brief SMARTCARD Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< Configures the SmartCard communication baud rate.
                                           The baud rate register is computed using the following formula:
<<<<<<< HEAD
                                              Baud Rate Register = ((PCLKx) / ((hsmartcard->Init.BaudRate))) */
=======
                                              Baud Rate Register = ((usart_ker_ckpres) / ((hsmartcard->Init.BaudRate)))
                                           where usart_ker_ckpres is the USART input clock divided by a prescaler */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter @ref SMARTCARD_Word_Length can only be set to 9 (8 data + 1 parity bits). */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits.
                                           This parameter can be a value of @ref SMARTCARD_Stop_Bits. */

<<<<<<< HEAD
  uint32_t Parity;                    /*!< Specifies the parity mode.
=======
  uint16_t Parity;                    /*!< Specifies the parity mode.
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
                                           This parameter can be a value of @ref SMARTCARD_Parity
                                           @note The parity is enabled by default (PCE is forced to 1).
                                                 Since the WordLength is forced to 8 bits + parity, M is
                                                 forced to 1 and the parity bit is the 9th bit. */
<<<<<<< HEAD
 
  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref SMARTCARD_Mode */

  uint32_t CLKPolarity;               /*!< Specifies the steady state of the serial clock.
                                           This parameter can be a value of @ref SMARTCARD_Clock_Polarity */

  uint32_t CLKPhase;                  /*!< Specifies the clock transition on which the bit capture is made.
                                           This parameter can be a value of @ref SMARTCARD_Clock_Phase */

  uint32_t CLKLastBit;                /*!< Specifies whether the clock pulse corresponding to the last transmitted
                                           data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                                           This parameter can be a value of @ref SMARTCARD_Last_Bit */
                                             
  uint32_t OneBitSampling;            /*!< Specifies  whether a single sample or three samples' majority vote is selected.
                                           Selecting the single sample method increases the receiver tolerance to clock
                                           deviations. This parameter can be a value of @ref SMARTCARD_OneBit_Sampling */

  uint32_t  Prescaler;                 /*!< Specifies the SmartCard Prescaler */
  
  uint32_t  GuardTime;                 /*!< Specifies the SmartCard Guard Time */
  
  uint16_t NACKEnable;                /*!< Specifies whether the SmartCard NACK transmission is enabled
                                           in case of parity error.
                                           This parameter can be a value of @ref SMARTCARD_NACK_State */
                                           
  uint32_t TimeOutEnable;              /*!< Specifies whether the receiver timeout is enabled. 
                                            This parameter can be a value of @ref SMARTCARD_Timeout_Enable*/
  
  uint32_t TimeOutValue;               /*!< Specifies the receiver time out value in number of baud blocks: 
                                            it is used to implement the Character Wait Time (CWT) and 
                                            Block Wait Time (BWT). It is coded over 24 bits. */ 
                                           
  uint32_t BlockLength;                /*!< Specifies the SmartCard Block Length in T=1 Reception mode.
                                            This parameter can be any value from 0x0 to 0xFF */ 
                                           
  uint32_t AutoRetryCount;              /*!< Specifies the SmartCard auto-retry count (number of retries in
                                             receive and transmit mode). When set to 0, retransmission is 
                                             disabled. Otherwise, its maximum value is 7 (before signalling
                                             an error) */  

}SMARTCARD_InitTypeDef;
=======

  uint16_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref SMARTCARD_Mode */

  uint16_t CLKPolarity;               /*!< Specifies the steady state of the serial clock.
                                           This parameter can be a value of @ref SMARTCARD_Clock_Polarity */

  uint16_t CLKPhase;                  /*!< Specifies the clock transition on which the bit capture is made.
                                           This parameter can be a value of @ref SMARTCARD_Clock_Phase */

  uint16_t CLKLastBit;                /*!< Specifies whether the clock pulse corresponding to the last transmitted
                                           data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                                           This parameter can be a value of @ref SMARTCARD_Last_Bit */

  uint16_t OneBitSampling;            /*!< Specifies whether a single sample or three samples' majority vote is selected.
                                           Selecting the single sample method increases the receiver tolerance to clock
                                           deviations. This parameter can be a value of @ref SMARTCARD_OneBit_Sampling. */

  uint8_t  Prescaler;                 /*!< Specifies the SmartCard Prescaler.
                                           This parameter can be any value from 0x01 to 0x1F. Prescaler value is multiplied
                                           by 2 to give the division factor of the source clock frequency */

  uint8_t  GuardTime;                 /*!< Specifies the SmartCard Guard Time applied after stop bits. */

  uint16_t NACKEnable;                /*!< Specifies whether the SmartCard NACK transmission is enabled
                                           in case of parity error.
                                           This parameter can be a value of @ref SMARTCARD_NACK_Enable */

  uint32_t TimeOutEnable;             /*!< Specifies whether the receiver timeout is enabled.
                                            This parameter can be a value of @ref SMARTCARD_Timeout_Enable*/

  uint32_t TimeOutValue;              /*!< Specifies the receiver time out value in number of baud blocks:
                                           it is used to implement the Character Wait Time (CWT) and
                                           Block Wait Time (BWT). It is coded over 24 bits. */

  uint8_t BlockLength;                /*!< Specifies the SmartCard Block Length in T=1 Reception mode.
                                           This parameter can be any value from 0x0 to 0xFF */

  uint8_t AutoRetryCount;             /*!< Specifies the SmartCard auto-retry count (number of retries in
                                            receive and transmit mode). When set to 0, retransmission is
                                            disabled. Otherwise, its maximum value is 7 (before signalling
                                            an error) */

} SMARTCARD_InitTypeDef;
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/**
  * @brief  SMARTCARD advanced features initalization structure definition
  */
typedef struct
{
  uint32_t AdvFeatureInit;            /*!< Specifies which advanced SMARTCARD features is initialized. Several
                                           advanced features may be initialized at the same time. This parameter
                                           can be a value of @ref SMARTCARDEx_Advanced_Features_Initialization_Type */

  uint32_t TxPinLevelInvert;          /*!< Specifies whether the TX pin active level is inverted.
                                           This parameter can be a value of @ref SMARTCARD_Tx_Inv  */

  uint32_t RxPinLevelInvert;          /*!< Specifies whether the RX pin active level is inverted.
                                           This parameter can be a value of @ref SMARTCARD_Rx_Inv  */

  uint32_t DataInvert;                /*!< Specifies whether data are inverted (positive/direct logic
                                           vs negative/inverted logic).
                                           This parameter can be a value of @ref SMARTCARD_Data_Inv */

  uint32_t Swap;                      /*!< Specifies whether TX and RX pins are swapped.
                                           This parameter can be a value of @ref SMARTCARD_Rx_Tx_Swap */

  uint32_t OverrunDisable;            /*!< Specifies whether the reception overrun detection is disabled.
                                           This parameter can be a value of @ref SMARTCARD_Overrun_Disable */

  uint32_t DMADisableonRxError;       /*!< Specifies whether the DMA is disabled in case of reception error.
                                           This parameter can be a value of @ref SMARTCARD_DMA_Disable_on_Rx_Error */

  uint32_t MSBFirst;                  /*!< Specifies whether MSB is sent first on UART line.
                                           This parameter can be a value of @ref SMARTCARD_MSB_First */
<<<<<<< HEAD
                                           
  uint16_t TxCompletionIndication;     /*!< Specifies which transmission completion indication is used: before (when 
                                            relevant flag is available) or once guard time period has elapsed.
                                           This parameter can be a value of @ref SMARTCARDEx_Transmission_Completion_Indication. */                                            
}SMARTCARD_AdvFeatureInitTypeDef;

/**
  * @brief HAL SMARTCARD State structures definition
  * @note  HAL SMARTCARD State value is a combination of 2 different substates: gState and RxState.
  *        - gState contains SMARTCARD state information related to global Handle management 
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information 
=======

  uint16_t TxCompletionIndication;     /*!< Specifies which transmission completion indication is used: before (when
                                            relevant flag is available) or once guard time period has elapsed.
                                           This parameter can be a value of @ref SMARTCARDEx_Transmission_Completion_Indication. */
} SMARTCARD_AdvFeatureInitTypeDef;

/**
  * @brief HAL SMARTCARD State definition
  * @note  HAL SMARTCARD State value is a combination of 2 different substates: gState and RxState (see @ref SMARTCARD_State_Definition).
  *        - gState contains SMARTCARD state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
<<<<<<< HEAD
  *          b5     IP initilisation status
  *             0  : Reset (IP not initialized)
  *             1  : Init done (IP not initialized. HAL SMARTCARD Init function already called)
=======
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized. HAL SMARTCARD Init function already called)
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  *          b4-b3  (not used)
  *             xx : Should be set to 00
  *          b2     Intrinsic process state
  *             0  : Ready
<<<<<<< HEAD
  *             1  : Busy (IP busy with some configuration or internal operations)
=======
  *             1  : Busy (Peripheral busy with some configuration or internal operations)
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  *          b1     (not used)
  *             x  : Should be set to 0
  *          b0     Tx state
  *             0  : Ready (no Tx operation ongoing)
  *             1  : Busy (Tx operation ongoing)
  *        - RxState contains information related to Rx operations.
  *          RxState value coding follow below described bitmap :
  *          b7-b6  (not used)
  *             xx : Should be set to 00
<<<<<<< HEAD
  *          b5     IP initilisation status
  *             0  : Reset (IP not initialized)
  *             1  : Init done (IP not initialized)
=======
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral not initialized)
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  *          b4-b2  (not used)
  *            xxx : Should be set to 000
  *          b1     Rx state
  *             0  : Ready (no Rx operation ongoing)
  *             1  : Busy (Rx operation ongoing)
  *          b0     (not used)
  *             x  : Should be set to 0.
  */
<<<<<<< HEAD
typedef enum
{
  HAL_SMARTCARD_STATE_RESET             = 0x00U,   /*!< Peripheral is not initialized
                                                        Value is allowed for gState and RxState */
  HAL_SMARTCARD_STATE_READY             = 0x20U,   /*!< Peripheral Initialized and ready for use
                                                        Value is allowed for gState and RxState */
  HAL_SMARTCARD_STATE_BUSY              = 0x24U,   /*!< an internal process is ongoing 
                                                        Value is allowed for gState only */
  HAL_SMARTCARD_STATE_BUSY_TX           = 0x21U,   /*!< Data Transmission process is ongoing
                                                        Value is allowed for gState only */
  HAL_SMARTCARD_STATE_BUSY_RX           = 0x22U,   /*!< Data Reception process is ongoing
                                                        Value is allowed for RxState only */
  HAL_SMARTCARD_STATE_BUSY_TX_RX        = 0x23U,   /*!< Data Transmission and Reception process is ongoing
                                                        Not to be used for neither gState nor RxState.
                                                        Value is result of combination (Or) between gState and RxState values */
  HAL_SMARTCARD_STATE_TIMEOUT           = 0xA0U,   /*!< Timeout state
                                                        Value is allowed for gState only */
  HAL_SMARTCARD_STATE_ERROR             = 0xE0U    /*!< Error
                                                        Value is allowed for gState only */
}HAL_SMARTCARD_StateTypeDef;

/**
  * @brief  SMARTCARD clock sources definition
  */
typedef enum
{
  SMARTCARD_CLOCKSOURCE_PCLK1      = 0x00U,    /*!< PCLK1 clock source  */
  SMARTCARD_CLOCKSOURCE_PCLK2      = 0x01U,    /*!< PCLK2 clock source  */
  SMARTCARD_CLOCKSOURCE_HSI        = 0x02U,    /*!< HSI clock source    */
  SMARTCARD_CLOCKSOURCE_SYSCLK     = 0x04U,    /*!< SYSCLK clock source */
  SMARTCARD_CLOCKSOURCE_LSE        = 0x08U,    /*!< LSE clock source    */
  SMARTCARD_CLOCKSOURCE_UNDEFINED = 0x10  /*!< undefined clock source */
}SMARTCARD_ClockSourceTypeDef;
=======
typedef uint32_t HAL_SMARTCARD_StateTypeDef;
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/**
  * @brief  SMARTCARD handle Structure definition
  */
<<<<<<< HEAD
typedef struct
{
  USART_TypeDef                   *Instance;        /*!< USART registers base address                          */

  SMARTCARD_InitTypeDef           Init;             /*!< SmartCard communication parameters                    */

  SMARTCARD_AdvFeatureInitTypeDef AdvancedInit;     /*!< SmartCard advanced features initialization parameters */

  uint8_t                         *pTxBuffPtr;      /*!< Pointer to SmartCard Tx transfer Buffer               */

  uint16_t                        TxXferSize;       /*!< SmartCard Tx Transfer size                            */

  __IO uint16_t                   TxXferCount;      /*!< SmartCard Tx Transfer Counter                         */

  uint8_t                         *pRxBuffPtr;      /*!< Pointer to SmartCard Rx transfer Buffer               */

  uint16_t                        RxXferSize;       /*!< SmartCard Rx Transfer size                            */

  __IO uint16_t                   RxXferCount;      /*!< SmartCard Rx Transfer Counter                         */

  DMA_HandleTypeDef               *hdmatx;          /*!< SmartCard Tx DMA Handle parameters                    */

  DMA_HandleTypeDef               *hdmarx;          /*!< SmartCard Rx DMA Handle parameters                    */

  HAL_LockTypeDef                 Lock;             /*!< Locking object                                        */

  __IO HAL_SMARTCARD_StateTypeDef    gState;        /*!< SmartCard state information related to global Handle management 
                                                         and also related to Tx operations.
                                                         This parameter can be a value of @ref HAL_SMARTCARD_StateTypeDef */

  __IO HAL_SMARTCARD_StateTypeDef    RxState;       /*!< SmartCard state information related to Rx operations.
                                                         This parameter can be a value of @ref HAL_SMARTCARD_StateTypeDef */

  __IO uint32_t                       ErrorCode;        /* SmartCard Error code                           */

}SMARTCARD_HandleTypeDef;

/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/** @defgroup SMARTCARD_Exported_Constants  SMARTCARD Exported constants
  * @{
  */
/** @defgroup SMARTCARD_Error_Code SMARTCARD Error Code
  * @brief    SMARTCARD Error Code 
  * @{
  */ 
#define HAL_SMARTCARD_ERROR_NONE      ((uint32_t)0x00U)    /*!< No error                */
#define HAL_SMARTCARD_ERROR_PE        ((uint32_t)0x01U)    /*!< Parity error            */
#define HAL_SMARTCARD_ERROR_NE        ((uint32_t)0x02U)    /*!< Noise error             */
#define HAL_SMARTCARD_ERROR_FE        ((uint32_t)0x04U)    /*!< frame error             */
#define HAL_SMARTCARD_ERROR_ORE       ((uint32_t)0x08U)    /*!< Overrun error           */
#define HAL_SMARTCARD_ERROR_DMA       ((uint32_t)0x10U)    /*!< DMA transfer error      */
#define HAL_SMARTCARD_ERROR_RTO       ((uint32_t)0x20U)    /*!< Receiver TimeOut error  */
/**
  * @}
  */

/** @defgroup SMARTCARD_Word_Length SMARTCARD Word Length
  * @{
  */
#define SMARTCARD_WORDLENGTH_9B                  ((uint32_t)USART_CR1_M_0)
=======
typedef struct __SMARTCARD_HandleTypeDef
{
  USART_TypeDef                     *Instance;             /*!< USART registers base address                          */

  SMARTCARD_InitTypeDef             Init;                  /*!< SmartCard communication parameters                    */

  SMARTCARD_AdvFeatureInitTypeDef   AdvancedInit;          /*!< SmartCard advanced features initialization parameters */

  uint8_t                           *pTxBuffPtr;           /*!< Pointer to SmartCard Tx transfer Buffer               */

  uint16_t                          TxXferSize;            /*!< SmartCard Tx Transfer size                            */

  __IO uint16_t                     TxXferCount;           /*!< SmartCard Tx Transfer Counter                         */

  uint8_t                           *pRxBuffPtr;           /*!< Pointer to SmartCard Rx transfer Buffer               */

  uint16_t                          RxXferSize;            /*!< SmartCard Rx Transfer size                            */

  __IO uint16_t                     RxXferCount;           /*!< SmartCard Rx Transfer Counter                         */


  void (*RxISR)(struct __SMARTCARD_HandleTypeDef *huart);  /*!< Function pointer on Rx IRQ handler                    */

  void (*TxISR)(struct __SMARTCARD_HandleTypeDef *huart);  /*!< Function pointer on Tx IRQ handler                    */

  DMA_HandleTypeDef                 *hdmatx;               /*!< SmartCard Tx DMA Handle parameters                    */

  DMA_HandleTypeDef                 *hdmarx;               /*!< SmartCard Rx DMA Handle parameters                    */

  HAL_LockTypeDef                   Lock;                  /*!< Locking object                                        */

  __IO HAL_SMARTCARD_StateTypeDef   gState;                /*!< SmartCard state information related to global Handle management
                                                                and also related to Tx operations.
                                                                This parameter can be a value of @ref HAL_SMARTCARD_StateTypeDef */

  __IO HAL_SMARTCARD_StateTypeDef   RxState;               /*!< SmartCard state information related to Rx operations.
                                                                This parameter can be a value of @ref HAL_SMARTCARD_StateTypeDef */

  __IO uint32_t                     ErrorCode;             /*!< SmartCard Error code                                  */

#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
  void (* TxCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);            /*!< SMARTCARD Tx Complete Callback             */

  void (* RxCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);            /*!< SMARTCARD Rx Complete Callback             */

  void (* ErrorCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);             /*!< SMARTCARD Error Callback                   */

  void (* AbortCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);         /*!< SMARTCARD Abort Complete Callback          */

  void (* AbortTransmitCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard); /*!< SMARTCARD Abort Transmit Complete Callback */

  void (* AbortReceiveCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);  /*!< SMARTCARD Abort Receive Complete Callback  */

  void (* MspInitCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);           /*!< SMARTCARD Msp Init callback                */

  void (* MspDeInitCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);         /*!< SMARTCARD Msp DeInit callback              */
#endif  /* USE_HAL_SMARTCARD_REGISTER_CALLBACKS */

} SMARTCARD_HandleTypeDef;

#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL SMARTCARD Callback ID enumeration definition
  */
typedef enum
{
  HAL_SMARTCARD_TX_COMPLETE_CB_ID             = 0x00U,    /*!< SMARTCARD Tx Complete Callback ID             */
  HAL_SMARTCARD_RX_COMPLETE_CB_ID             = 0x01U,    /*!< SMARTCARD Rx Complete Callback ID             */
  HAL_SMARTCARD_ERROR_CB_ID                   = 0x02U,    /*!< SMARTCARD Error Callback ID                   */
  HAL_SMARTCARD_ABORT_COMPLETE_CB_ID          = 0x03U,    /*!< SMARTCARD Abort Complete Callback ID          */
  HAL_SMARTCARD_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x04U,    /*!< SMARTCARD Abort Transmit Complete Callback ID */
  HAL_SMARTCARD_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x05U,    /*!< SMARTCARD Abort Receive Complete Callback ID  */

  HAL_SMARTCARD_MSPINIT_CB_ID                 = 0x08U,    /*!< SMARTCARD MspInit callback ID                 */
  HAL_SMARTCARD_MSPDEINIT_CB_ID               = 0x09U     /*!< SMARTCARD MspDeInit callback ID               */

} HAL_SMARTCARD_CallbackIDTypeDef;

/**
  * @brief  HAL SMARTCARD Callback pointer definition
  */
typedef  void (*pSMARTCARD_CallbackTypeDef)(SMARTCARD_HandleTypeDef *hsmartcard);  /*!< pointer to an SMARTCARD callback function */

#endif /* USE_HAL_SMARTCARD_REGISTER_CALLBACKS */

/**
  * @brief  SMARTCARD clock sources
  */
typedef enum
{
  SMARTCARD_CLOCKSOURCE_PCLK1     = 0x00U, /*!< PCLK1 clock source         */
  SMARTCARD_CLOCKSOURCE_PCLK2     = 0x01U, /*!< PCLK2 clock source         */
  SMARTCARD_CLOCKSOURCE_HSI       = 0x02U, /*!< HSI clock source           */
  SMARTCARD_CLOCKSOURCE_SYSCLK    = 0x04U, /*!< SYSCLK clock source        */
  SMARTCARD_CLOCKSOURCE_LSE       = 0x08U, /*!< LSE clock source           */
  SMARTCARD_CLOCKSOURCE_UNDEFINED = 0x10U  /*!< undefined clock source     */
} SMARTCARD_ClockSourceTypeDef;

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Stop_Bits SMARTCARD Number of Stop Bits
  * @{
  */
#define SMARTCARD_STOPBITS_1_5                   ((uint32_t)(USART_CR2_STOP))
/**
  * @}
  */

/** @defgroup SMARTCARD_Parity SMARTCARD Parity
  * @{
  */
#define SMARTCARD_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)
#define SMARTCARD_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS)) 
=======
/* Exported constants --------------------------------------------------------*/
/** @defgroup SMARTCARD_Exported_Constants  SMARTCARD Exported Constants
  * @{
  */

/** @defgroup SMARTCARD_State_Definition SMARTCARD State Code Definition
  * @{
  */
#define HAL_SMARTCARD_STATE_RESET            0x00000000U                     /*!< Peripheral is not initialized
                                                                                  Value is allowed for gState and RxState */
#define HAL_SMARTCARD_STATE_READY            0x00000020U                     /*!< Peripheral Initialized and ready for use
                                                                                  Value is allowed for gState and RxState */
#define HAL_SMARTCARD_STATE_BUSY             0x00000024U                     /*!< an internal process is ongoing
                                                                                  Value is allowed for gState only */
#define HAL_SMARTCARD_STATE_BUSY_TX          0x00000021U                     /*!< Data Transmission process is ongoing
                                                                                  Value is allowed for gState only */
#define HAL_SMARTCARD_STATE_BUSY_RX          0x00000022U                     /*!< Data Reception process is ongoing
                                                                                  Value is allowed for RxState only */
#define HAL_SMARTCARD_STATE_BUSY_TX_RX       0x00000023U                     /*!< Data Transmission and Reception process is ongoing
                                                                                  Not to be used for neither gState nor RxState.
                                                                                  Value is result of combination (Or) between gState and RxState values */
#define HAL_SMARTCARD_STATE_TIMEOUT          0x000000A0U                     /*!< Timeout state
                                                                                  Value is allowed for gState only */
#define HAL_SMARTCARD_STATE_ERROR            0x000000E0U                     /*!< Error
                                                                                  Value is allowed for gState only */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Mode SMARTCARD Mode
  * @{
  */
#define SMARTCARD_MODE_RX                        ((uint32_t)USART_CR1_RE)
#define SMARTCARD_MODE_TX                        ((uint32_t)USART_CR1_TE)
#define SMARTCARD_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE |USART_CR1_RE))
=======
/** @defgroup SMARTCARD_Error_Definition SMARTCARD Error Code Definition
  * @{
  */
#define HAL_SMARTCARD_ERROR_NONE             ((uint32_t)0x00000000U)         /*!< No error                */
#define HAL_SMARTCARD_ERROR_PE               ((uint32_t)0x00000001U)         /*!< Parity error            */
#define HAL_SMARTCARD_ERROR_NE               ((uint32_t)0x00000002U)         /*!< Noise error             */
#define HAL_SMARTCARD_ERROR_FE               ((uint32_t)0x00000004U)         /*!< frame error             */
#define HAL_SMARTCARD_ERROR_ORE              ((uint32_t)0x00000008U)         /*!< Overrun error           */
#define HAL_SMARTCARD_ERROR_DMA              ((uint32_t)0x00000010U)         /*!< DMA transfer error      */
#define HAL_SMARTCARD_ERROR_RTO              ((uint32_t)0x00000020U)         /*!< Receiver TimeOut error  */
#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
#define HAL_SMARTCARD_ERROR_INVALID_CALLBACK ((uint32_t)0x00000040U)         /*!< Invalid Callback error  */
#endif /* USE_HAL_SMARTCARD_REGISTER_CALLBACKS */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Clock_Polarity SMARTCARD Clock Polarity
  * @{
  */
#define SMARTCARD_POLARITY_LOW                   ((uint32_t)0x0000U)
#define SMARTCARD_POLARITY_HIGH                  ((uint32_t)USART_CR2_CPOL)
/**
  * @}
  */ 

/** @defgroup SMARTCARD_Clock_Phase  SMARTCARD Clock Phase
  * @{
  */
#define SMARTCARD_PHASE_1EDGE                    ((uint32_t)0x0000U)
#define SMARTCARD_PHASE_2EDGE                    ((uint32_t)USART_CR2_CPHA)
=======
/** @defgroup SMARTCARD_Word_Length SMARTCARD Word Length
  * @{
  */
#define SMARTCARD_WORDLENGTH_9B             USART_CR1_M0                    /*!< SMARTCARD frame length */
/**
  * @}
  */

/** @defgroup SMARTCARD_Stop_Bits SMARTCARD Number of Stop Bits
  * @{
  */
#define SMARTCARD_STOPBITS_0_5              USART_CR2_STOP_0                /*!< SMARTCARD frame with 0.5 stop bit  */
#define SMARTCARD_STOPBITS_1_5              USART_CR2_STOP                  /*!< SMARTCARD frame with 1.5 stop bits */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Last_Bit  SMARTCARD Last Bit
  * @{
  */
#define SMARTCARD_LASTBIT_DISABLE                ((uint32_t)0x0000U)
#define SMARTCARD_LASTBIT_ENABLE                 ((uint32_t)USART_CR2_LBCL)
=======
/** @defgroup SMARTCARD_Parity SMARTCARD Parity
  * @{
  */
#define SMARTCARD_PARITY_EVEN               USART_CR1_PCE                   /*!< SMARTCARD frame even parity */
#define SMARTCARD_PARITY_ODD                (USART_CR1_PCE | USART_CR1_PS)  /*!< SMARTCARD frame odd parity  */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_OneBit_Sampling SMARTCARD OneBit Sampling
  * @{
  */
#define SMARTCARD_ONE_BIT_SAMPLE_DISABLE   ((uint32_t)0x0000U)
#define SMARTCARD_ONE_BIT_SAMPLE_ENABLE    ((uint32_t)USART_CR3_ONEBIT)
/**
  * @}
  */  


/** @defgroup SMARTCARD_NACK_State  SMARTCARD NACK State
  * @{
  */
#define SMARTCARD_NACK_ENABLE           ((uint32_t)USART_CR3_NACK)
#define SMARTCARD_NACK_DISABLE          ((uint32_t)0x0000U)
=======
/** @defgroup SMARTCARD_Mode SMARTCARD Transfer Mode
  * @{
  */
#define SMARTCARD_MODE_RX                   USART_CR1_RE                    /*!< SMARTCARD RX mode        */
#define SMARTCARD_MODE_TX                   USART_CR1_TE                    /*!< SMARTCARD TX mode        */
#define SMARTCARD_MODE_TX_RX                (USART_CR1_TE |USART_CR1_RE)    /*!< SMARTCARD RX and TX mode */
/**
  * @}
  */

/** @defgroup SMARTCARD_Clock_Polarity SMARTCARD Clock Polarity
  * @{
  */
#define SMARTCARD_POLARITY_LOW              0x00000000U                     /*!< SMARTCARD frame low polarity  */
#define SMARTCARD_POLARITY_HIGH             USART_CR2_CPOL                  /*!< SMARTCARD frame high polarity */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Timeout_Enable SMARTCARD Timeout Enable
  * @{
  */
#define SMARTCARD_TIMEOUT_DISABLE      ((uint32_t)0x00000000U)
#define SMARTCARD_TIMEOUT_ENABLE       ((uint32_t)USART_CR2_RTOEN)
/**
  * @}
  */
  
/** @defgroup SMARTCARD_DMA_Requests   SMARTCARD DMA requests
  * @{
  */

#define SMARTCARD_DMAREQ_TX                    ((uint32_t)USART_CR3_DMAT)
#define SMARTCARD_DMAREQ_RX                    ((uint32_t)USART_CR3_DMAR)

=======
/** @defgroup SMARTCARD_Clock_Phase SMARTCARD Clock Phase
  * @{
  */
#define SMARTCARD_PHASE_1EDGE               0x00000000U                     /*!< SMARTCARD frame phase on first clock transition  */
#define SMARTCARD_PHASE_2EDGE               USART_CR2_CPHA                  /*!< SMARTCARD frame phase on second clock transition */
/**
  * @}
  */

/** @defgroup SMARTCARD_Last_Bit SMARTCARD Last Bit
  * @{
  */
#define SMARTCARD_LASTBIT_DISABLE           0x00000000U                     /*!< SMARTCARD frame last data bit clock pulse not output to SCLK pin */
#define SMARTCARD_LASTBIT_ENABLE            USART_CR2_LBCL                  /*!< SMARTCARD frame last data bit clock pulse output to SCLK pin     */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Advanced_Features_Initialization_Type SMARTCARD Advanced Features Initialization Type
  * @{
  */
#define SMARTCARD_ADVFEATURE_NO_INIT                 ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_TXINVERT_INIT           ((uint32_t)0x00000001U)
#define SMARTCARD_ADVFEATURE_RXINVERT_INIT           ((uint32_t)0x00000002U)
#define SMARTCARD_ADVFEATURE_DATAINVERT_INIT         ((uint32_t)0x00000004U)
#define SMARTCARD_ADVFEATURE_SWAP_INIT               ((uint32_t)0x00000008U)
#define SMARTCARD_ADVFEATURE_RXOVERRUNDISABLE_INIT   ((uint32_t)0x00000010U)
#define SMARTCARD_ADVFEATURE_DMADISABLEONERROR_INIT  ((uint32_t)0x00000020U)
#define SMARTCARD_ADVFEATURE_MSBFIRST_INIT           ((uint32_t)0x00000080U)
=======
/** @defgroup SMARTCARD_OneBit_Sampling SMARTCARD One Bit Sampling Method
  * @{
  */
#define SMARTCARD_ONE_BIT_SAMPLE_DISABLE    0x00000000U                     /*!< SMARTCARD frame one-bit sample disabled */
#define SMARTCARD_ONE_BIT_SAMPLE_ENABLE     USART_CR3_ONEBIT                /*!< SMARTCARD frame one-bit sample enabled  */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Tx_Inv SMARTCARD Tx Inv
  * @{
  */
#define SMARTCARD_ADVFEATURE_TXINV_DISABLE   ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_TXINV_ENABLE    ((uint32_t)USART_CR2_TXINV)
=======
/** @defgroup SMARTCARD_NACK_Enable SMARTCARD NACK Enable
  * @{
  */
#define SMARTCARD_NACK_DISABLE              0x00000000U                     /*!< SMARTCARD NACK transmission disabled  */
#define SMARTCARD_NACK_ENABLE               USART_CR3_NACK                  /*!< SMARTCARD NACK transmission enabled */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Rx_Inv SMARTCARD Rx Inv
  * @{
  */
#define SMARTCARD_ADVFEATURE_RXINV_DISABLE   ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_RXINV_ENABLE    ((uint32_t)USART_CR2_RXINV)
=======
/** @defgroup SMARTCARD_Timeout_Enable SMARTCARD Timeout Enable
  * @{
  */
#define SMARTCARD_TIMEOUT_DISABLE           0x00000000U                     /*!< SMARTCARD receiver timeout disabled */
#define SMARTCARD_TIMEOUT_ENABLE            USART_CR2_RTOEN                 /*!< SMARTCARD receiver timeout enabled  */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Data_Inv SMARTCARD Data Inv
  * @{
  */
#define SMARTCARD_ADVFEATURE_DATAINV_DISABLE     ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_DATAINV_ENABLE      ((uint32_t)USART_CR2_DATAINV)
/**
  * @}
  */ 
  
/** @defgroup SMARTCARD_Rx_Tx_Swap SMARTCARD Rx Tx Swap
  * @{
  */
#define SMARTCARD_ADVFEATURE_SWAP_DISABLE   ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_SWAP_ENABLE    ((uint32_t)USART_CR2_SWAP)
/**
  * @}
  */ 

/** @defgroup SMARTCARD_Overrun_Disable SMARTCARD Overrun Disable
  * @{
  */
#define SMARTCARD_ADVFEATURE_OVERRUN_ENABLE   ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_OVERRUN_DISABLE  ((uint32_t)USART_CR3_OVRDIS)
/**
  * @}
  */  

/** @defgroup SMARTCARD_DMA_Disable_on_Rx_Error SMARTCARD DMA Disable on Rx Error
  * @{
  */
#define SMARTCARD_ADVFEATURE_DMA_ENABLEONRXERROR       ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_DMA_DISABLEONRXERROR      ((uint32_t)USART_CR3_DDRE)
/**
  * @}
  */  

/** @defgroup SMARTCARD_MSB_First SMARTCARD MSB First
  * @{
  */
#define SMARTCARD_ADVFEATURE_MSBFIRST_DISABLE      ((uint32_t)0x00000000U)
#define SMARTCARD_ADVFEATURE_MSBFIRST_ENABLE       ((uint32_t)USART_CR2_MSBFIRST)
/**
  * @}
  */  

/** @defgroup SmartCard_Flags SMARTCARD Flags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the ISR register
  * @{
  */
#define SMARTCARD_FLAG_REACK                     ((uint32_t)0x00400000U)
#define SMARTCARD_FLAG_TEACK                     ((uint32_t)0x00200000U)
#define SMARTCARD_FLAG_BUSY                      ((uint32_t)0x00010000U)
#define SMARTCARD_FLAG_EOBF                      ((uint32_t)0x00001000U)
#define SMARTCARD_FLAG_RTOF                      ((uint32_t)0x00000800U)
#define SMARTCARD_FLAG_TXE                       ((uint32_t)0x00000080U)
#define SMARTCARD_FLAG_TC                        ((uint32_t)0x00000040U)
#define SMARTCARD_FLAG_RXNE                      ((uint32_t)0x00000020U)
#define SMARTCARD_FLAG_IDLE                      ((uint32_t)0x00000010U)
#define SMARTCARD_FLAG_ORE                       ((uint32_t)0x00000008U)
#define SMARTCARD_FLAG_NE                        ((uint32_t)0x00000004U)
#define SMARTCARD_FLAG_FE                        ((uint32_t)0x00000002U)
#define SMARTCARD_FLAG_PE                        ((uint32_t)0x00000001U)
=======
/** @defgroup SMARTCARD_Tx_Inv SMARTCARD advanced feature TX pin active level inversion
  * @{
  */
#define SMARTCARD_ADVFEATURE_TXINV_DISABLE  0x00000000U                  /*!< TX pin active level inversion disable */
#define SMARTCARD_ADVFEATURE_TXINV_ENABLE   USART_CR2_TXINV              /*!< TX pin active level inversion enable  */
/**
  * @}
  */

/** @defgroup SMARTCARD_Rx_Inv SMARTCARD advanced feature RX pin active level inversion
  * @{
  */
#define SMARTCARD_ADVFEATURE_RXINV_DISABLE  0x00000000U                  /*!< RX pin active level inversion disable */
#define SMARTCARD_ADVFEATURE_RXINV_ENABLE   USART_CR2_RXINV              /*!< RX pin active level inversion enable  */
/**
  * @}
  */

/** @defgroup SMARTCARD_Data_Inv SMARTCARD advanced feature Binary Data inversion
  * @{
  */
#define SMARTCARD_ADVFEATURE_DATAINV_DISABLE  0x00000000U                /*!< Binary data inversion disable */
#define SMARTCARD_ADVFEATURE_DATAINV_ENABLE   USART_CR2_DATAINV          /*!< Binary data inversion enable  */
/**
  * @}
  */

/** @defgroup SMARTCARD_Rx_Tx_Swap SMARTCARD advanced feature RX TX pins swap
  * @{
  */
#define SMARTCARD_ADVFEATURE_SWAP_DISABLE   0x00000000U                  /*!< TX/RX pins swap disable */
#define SMARTCARD_ADVFEATURE_SWAP_ENABLE    USART_CR2_SWAP               /*!< TX/RX pins swap enable  */
/**
  * @}
  */

/** @defgroup SMARTCARD_Overrun_Disable SMARTCARD advanced feature Overrun Disable
  * @{
  */
#define SMARTCARD_ADVFEATURE_OVERRUN_ENABLE   0x00000000U                /*!< RX overrun enable  */
#define SMARTCARD_ADVFEATURE_OVERRUN_DISABLE  USART_CR3_OVRDIS           /*!< RX overrun disable */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @defgroup SMARTCARD_Interrupt_definition SMARTCARD Interrupt definition
  *        Elements values convention: 0000ZZZZ0XXYYYYYb
  *           - YYYYY  : Interrupt source position in the XX register (5bits)
  *           - XX  : Interrupt source register (2bits)
  *                 - 01: CR1 register
  *                 - 10: CR2 register
  *                 - 11: CR3 register
  *           - ZZZZ  : Flag position in the ISR register(4bits)
  * @{
  */
  
#define SMARTCARD_IT_PE                          ((uint16_t)0x0028U)
#define SMARTCARD_IT_TXE                         ((uint16_t)0x0727U)
#define SMARTCARD_IT_TC                          ((uint16_t)0x0626U)
#define SMARTCARD_IT_RXNE                        ((uint16_t)0x0525U)
#define SMARTCARD_IT_IDLE                        ((uint16_t)0x0424U)
#define SMARTCARD_IT_ERR                         ((uint16_t)0x0060U)
#define SMARTCARD_IT_ORE                         ((uint16_t)0x0300U)
#define SMARTCARD_IT_NE                          ((uint16_t)0x0200U)
#define SMARTCARD_IT_FE                          ((uint16_t)0x0100U)

#define SMARTCARD_IT_EOB                         ((uint16_t)0x0C3BU)
#define SMARTCARD_IT_RTO                         ((uint16_t)0x0B3AU)
/**
  * @}
  */ 


/** @defgroup SMARTCARD_IT_CLEAR_Flags SMARTCARD IT CLEAR Flags
  * @{
  */
#define SMARTCARD_CLEAR_PEF                       USART_ICR_PECF            /*!< Parity Error Clear Flag */          
#define SMARTCARD_CLEAR_FEF                       USART_ICR_FECF            /*!< Framing Error Clear Flag */         
#define SMARTCARD_CLEAR_NEF                       USART_ICR_NCF             /*!< Noise detected Clear Flag */        
#define SMARTCARD_CLEAR_OREF                      USART_ICR_ORECF           /*!< OverRun Error Clear Flag */         
#define SMARTCARD_CLEAR_IDLEF                     USART_ICR_IDLECF          /*!< Idle line detected clear Flag */
#define SMARTCARD_CLEAR_TCF                       USART_ICR_TCCF            /*!< Transmission Complete Clear Flag */ 
#define SMARTCARD_CLEAR_RTOF                      USART_ICR_RTOCF           /*!< Receiver Time Out Clear Flag */     
#define SMARTCARD_CLEAR_EOBF                      USART_ICR_EOBCF           /*!< End Of Block Clear Flag */          
=======
/** @defgroup SMARTCARD_DMA_Disable_on_Rx_Error SMARTCARD advanced feature DMA Disable on Rx Error
  * @{
  */
#define SMARTCARD_ADVFEATURE_DMA_ENABLEONRXERROR   0x00000000U           /*!< DMA enable on Reception Error  */
#define SMARTCARD_ADVFEATURE_DMA_DISABLEONRXERROR  USART_CR3_DDRE        /*!< DMA disable on Reception Error */
/**
  * @}
  */

/** @defgroup SMARTCARD_MSB_First   SMARTCARD advanced feature MSB first
  * @{
  */
#define SMARTCARD_ADVFEATURE_MSBFIRST_DISABLE      0x00000000U           /*!< Most significant bit sent/received first disable */
#define SMARTCARD_ADVFEATURE_MSBFIRST_ENABLE       USART_CR2_MSBFIRST    /*!< Most significant bit sent/received first enable  */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

/** @defgroup SMARTCARD_Request_Parameters SMARTCARD Request Parameters
  * @{
<<<<<<< HEAD
  */        
#define SMARTCARD_RXDATA_FLUSH_REQUEST        ((uint32_t)USART_RQR_RXFRQ)        /*!< Receive Data flush Request */ 
#define SMARTCARD_TXDATA_FLUSH_REQUEST        ((uint32_t)USART_RQR_TXFRQ)        /*!< Transmit data flush Request */
/**
  * @}
  */
  
  
/** @defgroup SMARTCARD_CR3_SCAR_CNT_LSB_POS SMARTCARD CR3 SCAR CNT LSB POS
  * @{
  */
#define SMARTCARD_CR3_SCARCNT_LSB_POS            ((uint32_t) 17U)
/**
  * @}
  */
  
/** @defgroup SMARTCARD_GTPR_GT_LSBPOS SMARTCARD GTPR GT LSBPOS
  * @{
  */
#define SMARTCARD_GTPR_GT_LSB_POS            ((uint32_t) 8U)
/**
  * @}
  */ 
  
/** @defgroup SMARTCARD_RTOR_BLEN_LSBPOS SMARTCARD RTOR BLEN LSBPOS
  * @{
  */
#define SMARTCARD_RTOR_BLEN_LSB_POS          ((uint32_t) 24U)
/**
  * @}
  */    
 
/** @defgroup SMARTCARD_Interruption_Mask SMARTCARD Interruption Mask
  * @{
  */ 
#define SMARTCARD_IT_MASK  ((uint16_t)0x001FU)  
/**
  * @}
  */
    
/**
  * @}
  */    
    
/* Exported macro ------------------------------------------------------------*/
/** @defgroup SMARTCARD_Exported_Macros SMARTCARD Exported Macros
  * @{
  */

/** @brief Reset SMARTCARD handle state
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2
  * @retval None
  */
#define __HAL_SMARTCARD_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_SMARTCARD_STATE_RESET)

/** @brief  Flush the Smartcard DR register 
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @retval None
  */
#define __HAL_SMARTCARD_FLUSH_DRREGISTER(__HANDLE__) (__HAL_SMARTCARD_SEND_REQ((__HANDLE__), SMARTCARD_RXDATA_FLUSH_REQUEST))

/** @brief  Checks whether the specified Smartcard flag is set or not.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg SMARTCARD_FLAG_REACK: Receive enable acknowledge flag
  *            @arg SMARTCARD_FLAG_TEACK: Transmit enable acknowledge flag
  *            @arg SMARTCARD_FLAG_BUSY:  Busy flag
  *            @arg SMARTCARD_FLAG_EOBF:  End of block flag   
  *            @arg SMARTCARD_FLAG_RTOF:  Receiver timeout flag
  *            @arg SMARTCARD_FLAG_TXE:   Transmit data register empty flag
  *            @arg SMARTCARD_FLAG_TC:    Transmission Complete flag
  *            @arg SMARTCARD_FLAG_RXNE:  Receive data register not empty flag
  *            @arg SMARTCARD_FLAG_ORE:   OverRun Error flag
  *            @arg SMARTCARD_FLAG_NE:    Noise Error flag
  *            @arg SMARTCARD_FLAG_FE:    Framing Error flag
  *            @arg SMARTCARD_FLAG_PE:    Parity Error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SMARTCARD_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))
=======
  */
#define SMARTCARD_RXDATA_FLUSH_REQUEST      USART_RQR_RXFRQ              /*!< Receive data flush request */
#define SMARTCARD_TXDATA_FLUSH_REQUEST      USART_RQR_TXFRQ              /*!< Transmit data flush request */
/**
  * @}
  */

/** @defgroup SMARTCARD_Interruption_Mask SMARTCARD interruptions flags mask
  * @{
  */
#define SMARTCARD_IT_MASK                   0x001FU   /*!< SMARTCARD interruptions flags mask  */
#define SMARTCARD_CR_MASK                   0x00E0U   /*!< SMARTCARD control register mask     */
#define SMARTCARD_CR_POS                    5U        /*!< SMARTCARD control register position */
#define SMARTCARD_ISR_MASK                  0x1F00U   /*!< SMARTCARD ISR register mask         */
#define SMARTCARD_ISR_POS                   8U        /*!< SMARTCARD ISR register position     */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup SMARTCARD_Exported_Macros  SMARTCARD Exported Macros
  * @{
  */

/** @brief  Reset SMARTCARD handle states.
  * @param  __HANDLE__ SMARTCARD handle.
  * @retval None
  */
#if USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1
#define __HAL_SMARTCARD_RESET_HANDLE_STATE(__HANDLE__)  do{                                                       \
                                                           (__HANDLE__)->gState = HAL_SMARTCARD_STATE_RESET;      \
                                                           (__HANDLE__)->RxState = HAL_SMARTCARD_STATE_RESET;     \
                                                           (__HANDLE__)->MspInitCallback = NULL;                  \
                                                           (__HANDLE__)->MspDeInitCallback = NULL;                \
                                                          } while(0U)
#else
#define __HAL_SMARTCARD_RESET_HANDLE_STATE(__HANDLE__)  do{                                                       \
                                                           (__HANDLE__)->gState = HAL_SMARTCARD_STATE_RESET;      \
                                                           (__HANDLE__)->RxState = HAL_SMARTCARD_STATE_RESET;     \
                                                          } while(0U)
#endif /*USE_HAL_SMARTCARD_REGISTER_CALLBACKS  */

/** @brief  Flush the Smartcard Data registers.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_FLUSH_DRREGISTER(__HANDLE__)                        \
    do{                                                                     \
      SET_BIT((__HANDLE__)->Instance->RQR, SMARTCARD_RXDATA_FLUSH_REQUEST); \
      SET_BIT((__HANDLE__)->Instance->RQR, SMARTCARD_TXDATA_FLUSH_REQUEST); \
      } while(0U)
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/** @brief  Clear the specified SMARTCARD pending flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg @ref SMARTCARD_CLEAR_PEF    Parity error clear flag
  *            @arg @ref SMARTCARD_CLEAR_FEF    Framing error clear flag
  *            @arg @ref SMARTCARD_CLEAR_NEF    Noise detected clear flag
  *            @arg @ref SMARTCARD_CLEAR_OREF   OverRun error clear flag
  *            @arg @ref SMARTCARD_CLEAR_IDLEF  Idle line detected clear flag
  *            @arg @ref SMARTCARD_CLEAR_TCF    Transmission complete clear flag
<<<<<<< HEAD
  @if STM32L443xx
  *            @arg @ref SMARTCARD_CLEAR_TCBGTF Transmission complete before guard time clear flag (when flag available)    
  @endif
=======
  *            @arg @ref SMARTCARD_CLEAR_TCBGTF Transmission complete before guard time clear flag
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  *            @arg @ref SMARTCARD_CLEAR_RTOF   Receiver timeout clear flag
  *            @arg @ref SMARTCARD_CLEAR_EOBF   End of block clear flag
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

/** @brief  Clear the SMARTCARD PE pending flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_PEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_PEF)

<<<<<<< HEAD

=======
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/** @brief  Clear the SMARTCARD FE pending flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_FEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_FEF)

/** @brief  Clear the SMARTCARD NE pending flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_NEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_NEF)

/** @brief  Clear the SMARTCARD ORE pending flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_OREFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_OREF)

/** @brief  Clear the SMARTCARD IDLE pending flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_IDLEF)

<<<<<<< HEAD
/** @brief  Enables the specified SmartCard interrupt.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __INTERRUPT__ specifies the SMARTCARD interrupt to enable.
  *          This parameter can be one of the following values:
  *            @arg SMARTCARD_IT_EOBF: End Of Block interrupt
  *            @arg SMARTCARD_IT_RTOF: Receive TimeOut interrupt
  *            @arg SMARTCARD_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg SMARTCARD_IT_TC:   Transmission complete interrupt
  *            @arg SMARTCARD_IT_RXNE: Receive Data register not empty interrupt
  *            @arg SMARTCARD_IT_PE:   Parity Error interrupt
  *            @arg SMARTCARD_IT_ERR:  Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SMARTCARD_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U)? ((__HANDLE__)->Instance->CR1 |= (1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                        ((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U)? ((__HANDLE__)->Instance->CR2 |= (1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                        ((__HANDLE__)->Instance->CR3 |= (1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))))
/** @brief  Disables the specified SmartCard interrupt.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __INTERRUPT__ specifies the SMARTCARD interrupt to enable.
  *          This parameter can be one of the following values:
  *            @arg SMARTCARD_IT_EOBF: End Of Block interrupt
  *            @arg SMARTCARD_IT_RTOF: Receive TimeOut interrupt
  *            @arg SMARTCARD_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg SMARTCARD_IT_TC:   Transmission complete interrupt
  *            @arg SMARTCARD_IT_RXNE: Receive Data register not empty interrupt
  *            @arg SMARTCARD_IT_PE:   Parity Error interrupt
  *            @arg SMARTCARD_IT_ERR:  Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SMARTCARD_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U)? ((__HANDLE__)->Instance->CR1 &= ~ ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                        ((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U)? ((__HANDLE__)->Instance->CR2 &= ~ ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                        ((__HANDLE__)->Instance->CR3 &= ~ ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))))

/** @brief  Checks whether the specified SmartCard interrupt has occurred or not.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __IT__ specifies the SMARTCARD interrupt to check.
  *          This parameter can be one of the following values:
  *            @arg SMARTCARD_IT_EOBF: End Of Block interrupt
  *            @arg SMARTCARD_IT_RTOF: Receive TimeOut interrupt  
  *            @arg SMARTCARD_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg SMARTCARD_IT_TC:   Transmission complete interrupt
  *            @arg SMARTCARD_IT_RXNE: Receive Data register not empty interrupt
  *            @arg SMARTCARD_IT_ORE:  OverRun Error interrupt
  *            @arg SMARTCARD_IT_NE:   Noise Error interrupt
  *            @arg SMARTCARD_IT_FE:   Framing Error interrupt
  *            @arg SMARTCARD_IT_PE:   Parity Error interrupt
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_SMARTCARD_GET_IT(__HANDLE__, __IT__) ((__HANDLE__)->Instance->ISR & ((uint32_t)1U << ((__IT__)>> 0x08U))) 

/** @brief  Checks whether the specified SmartCard interrupt interrupt source is enabled.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __IT__ specifies the SMARTCARD interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg SMARTCARD_IT_EOBF: End Of Block interrupt
  *            @arg SMARTCARD_IT_RTOF: Receive TimeOut interrupt  
  *            @arg SMARTCARD_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg SMARTCARD_IT_TC:   Transmission complete interrupt
  *            @arg SMARTCARD_IT_RXNE: Receive Data register not empty interrupt
  *            @arg SMARTCARD_IT_ORE:  OverRun Error interrupt
  *            @arg SMARTCARD_IT_NE:   Noise Error interrupt
  *            @arg SMARTCARD_IT_FE:   Framing Error interrupt
  *            @arg SMARTCARD_IT_PE:   Parity Error interrupt
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_SMARTCARD_GET_IT_SOURCE(__HANDLE__, __IT__) ((((((uint8_t)(__IT__)) >> 5U) == 1U)? (__HANDLE__)->Instance->CR1:(((((uint8_t)(__IT__)) >> 5U) == 2U)? \
                                                               (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & ((uint32_t)1 << \
                                                               (((uint16_t)(__IT__)) & SMARTCARD_IT_MASK)))


/** @brief  Clears the specified SMARTCARD ISR flag, in setting the proper ICR register flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __IT_CLEAR__ specifies the interrupt clear register flag that needs to be set
  *                       to clear the corresponding interrupt
  *          This parameter can be one of the following values:
  *            @arg USART_CLEAR_PEF: Parity Error Clear Flag
  *            @arg USART_CLEAR_FEF: Framing Error Clear Flag
  *            @arg USART_CLEAR_NEF: Noise detected Clear Flag
  *            @arg USART_CLEAR_OREF: OverRun Error Clear Flag
  *            @arg USART_CLEAR_TCF: Transmission Complete Clear Flag
  *            @arg USART_CLEAR_RTOF: Receiver Time Out Clear Flag
  *            @arg USART_CLEAR_EOBF: End Of Block Clear Flag 
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR = (uint32_t)(__IT_CLEAR__)) 

/** @brief  Set a specific SMARTCARD request flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __REQ__ specifies the request flag to set
  *          This parameter can be one of the following values:  
  *            @arg SMARTCARD_RXDATA_FLUSH_REQUEST: Receive Data flush Request 
  *            @arg SMARTCARD_TXDATA_FLUSH_REQUEST: Transmit data flush Request 
  *
  * @retval None
  */ 
#define __HAL_SMARTCARD_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint32_t)(__REQ__)) 

/** @brief  Enable the USART associated to the SMARTCARD Handle
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @retval None
  */
#define __HAL_SMARTCARD_ENABLE(__HANDLE__)               ( (__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  Disable the USART associated to the SMARTCARD Handle
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @retval None
  */
#define __HAL_SMARTCARD_DISABLE(__HANDLE__)              ( (__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)

/** @brief  Macros to enable or disable the SmartCard DMA request.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  *         The Handle Instance which can be USART1 or USART2.
  * @param  __REQUEST__ specifies the SmartCard DMA request.
  *          This parameter can be one of the following values:
  *            @arg SMARTCARD_DMAREQ_TX: SmartCard DMA transmit request
  *            @arg SMARTCARD_DMAREQ_RX: SmartCard DMA receive request
  */
#define __HAL_SMARTCARD_DMA_REQUEST_ENABLE(__HANDLE__, __REQUEST__)    ((__HANDLE__)->Instance->CR3 |=  (__REQUEST__))
#define __HAL_SMARTCARD_DMA_REQUEST_DISABLE(__HANDLE__, __REQUEST__)   ((__HANDLE__)->Instance->CR3 &=  ~(__REQUEST__))
=======
/** @brief  Check whether the specified Smartcard flag is set or not.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_FLAG_TCBGT Transmission complete before guard time flag (when flag available)
  *            @arg @ref SMARTCARD_FLAG_TEACK Transmit enable acknowledge flag
  *            @arg @ref SMARTCARD_FLAG_BUSY  Busy flag
  *            @arg @ref SMARTCARD_FLAG_EOBF  End of block flag
  *            @arg @ref SMARTCARD_FLAG_RTOF  Receiver timeout flag
  *            @arg @ref SMARTCARD_FLAG_TXE   Transmit data register empty flag
  *            @arg @ref SMARTCARD_FLAG_TC    Transmission complete flag
  *            @arg @ref SMARTCARD_FLAG_RXNE  Receive data register not empty flag
  *            @arg @ref SMARTCARD_FLAG_IDLE  Idle line detection flag
  *            @arg @ref SMARTCARD_FLAG_ORE   Overrun error flag
  *            @arg @ref SMARTCARD_FLAG_NE    Noise error flag
  *            @arg @ref SMARTCARD_FLAG_FE    Framing error flag
  *            @arg @ref SMARTCARD_FLAG_PE    Parity error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SMARTCARD_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))

/** @brief  Enable the specified SmartCard interrupt.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __INTERRUPT__ specifies the SMARTCARD interrupt to enable.
  *          This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_IT_EOB    End of block interrupt
  *            @arg @ref SMARTCARD_IT_RTO    Receive timeout interrupt
  *            @arg @ref SMARTCARD_IT_TXE    Transmit data register empty interrupt
  *            @arg @ref SMARTCARD_IT_TC     Transmission complete interrupt
  *            @arg @ref SMARTCARD_IT_TCBGT  Transmission complete before guard time interrupt (when interruption available)
  *            @arg @ref SMARTCARD_IT_RXNE   Receive data register not empty interrupt
  *            @arg @ref SMARTCARD_IT_IDLE   Idle line detection interrupt
  *            @arg @ref SMARTCARD_IT_PE     Parity error interrupt
  *            @arg @ref SMARTCARD_IT_ERR    Error interrupt(frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SMARTCARD_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((((__INTERRUPT__) & SMARTCARD_CR_MASK) >> SMARTCARD_CR_POS) == 1U)? ((__HANDLE__)->Instance->CR1 |= ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((((__INTERRUPT__) & SMARTCARD_CR_MASK) >> SMARTCARD_CR_POS) == 2U)? ((__HANDLE__)->Instance->CR2 |= ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((__HANDLE__)->Instance->CR3 |= ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))))

/** @brief  Disable the specified SmartCard interrupt.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __INTERRUPT__ specifies the SMARTCARD interrupt to disable.
  *          This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_IT_EOB    End of block interrupt
  *            @arg @ref SMARTCARD_IT_RTO    Receive timeout interrupt
  *            @arg @ref SMARTCARD_IT_TXE    Transmit data register empty interrupt
  *            @arg @ref SMARTCARD_IT_TC     Transmission complete interrupt
  *            @arg @ref SMARTCARD_IT_TCBGT  Transmission complete before guard time interrupt (when interruption available)
  *            @arg @ref SMARTCARD_IT_RXNE   Receive data register not empty interrupt
  *            @arg @ref SMARTCARD_IT_IDLE   Idle line detection interrupt
  *            @arg @ref SMARTCARD_IT_PE     Parity error interrupt
  *            @arg @ref SMARTCARD_IT_ERR    Error interrupt(frame error, noise error, overrun error)
  * @retval None
  */
#define __HAL_SMARTCARD_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((((__INTERRUPT__) & SMARTCARD_CR_MASK) >> SMARTCARD_CR_POS) == 1U)? ((__HANDLE__)->Instance->CR1 &= ~ ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((((__INTERRUPT__) & SMARTCARD_CR_MASK) >> SMARTCARD_CR_POS) == 2U)? ((__HANDLE__)->Instance->CR2 &= ~ ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((__HANDLE__)->Instance->CR3 &= ~ ((uint32_t)1U << ((__INTERRUPT__) & SMARTCARD_IT_MASK))))

/** @brief  Check whether the specified SmartCard interrupt has occurred or not.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __INTERRUPT__ specifies the SMARTCARD interrupt to check.
  *          This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_IT_EOB    End of block interrupt
  *            @arg @ref SMARTCARD_IT_RTO    Receive timeout interrupt
  *            @arg @ref SMARTCARD_IT_TXE    Transmit data register empty interrupt
  *            @arg @ref SMARTCARD_IT_TC     Transmission complete interrupt
  *            @arg @ref SMARTCARD_IT_TCBGT  Transmission complete before guard time interrupt (when interruption available)
  *            @arg @ref SMARTCARD_IT_RXNE   Receive data register not empty interrupt
  *            @arg @ref SMARTCARD_IT_IDLE   Idle line detection interrupt
  *            @arg @ref SMARTCARD_IT_PE     Parity error interrupt
  *            @arg @ref SMARTCARD_IT_ERR    Error interrupt(frame error, noise error, overrun error)
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_SMARTCARD_GET_IT(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->ISR & ((uint32_t)0x01U << (((__INTERRUPT__) & SMARTCARD_ISR_MASK)>> SMARTCARD_ISR_POS))) != 0U) ? SET : RESET)

/** @brief  Check whether the specified SmartCard interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __INTERRUPT__ specifies the SMARTCARD interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_IT_EOB    End of block interrupt
  *            @arg @ref SMARTCARD_IT_RTO    Receive timeout interrupt
  *            @arg @ref SMARTCARD_IT_TXE    Transmit data register empty interrupt
  *            @arg @ref SMARTCARD_IT_TC     Transmission complete interrupt
  *            @arg @ref SMARTCARD_IT_TCBGT  Transmission complete before guard time interrupt (when interruption available)
  *            @arg @ref SMARTCARD_IT_RXNE   Receive data register not empty interrupt
  *            @arg @ref SMARTCARD_IT_IDLE   Idle line detection interrupt
  *            @arg @ref SMARTCARD_IT_PE     Parity error interrupt
  *            @arg @ref SMARTCARD_IT_ERR    Error interrupt(frame error, noise error, overrun error)
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_SMARTCARD_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((((((__INTERRUPT__) & SMARTCARD_CR_MASK) >> SMARTCARD_CR_POS) == 0x01U)? (__HANDLE__)->Instance->CR1 : \
                                                                    (((((__INTERRUPT__) & SMARTCARD_CR_MASK) >> SMARTCARD_CR_POS) == 0x02U)? (__HANDLE__)->Instance->CR2 : \
                                                                    (__HANDLE__)->Instance->CR3)) & ((uint32_t)0x01U << (((uint16_t)(__INTERRUPT__)) & SMARTCARD_IT_MASK)))  != 0U) ? SET : RESET)

/** @brief  Clear the specified SMARTCARD ISR flag, in setting the proper ICR register flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __IT_CLEAR__ specifies the interrupt clear register flag that needs to be set
  *                       to clear the corresponding interrupt.
  *          This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_CLEAR_PEF    Parity error clear flag
  *            @arg @ref SMARTCARD_CLEAR_FEF    Framing error clear flag
  *            @arg @ref SMARTCARD_CLEAR_NEF    Noise detected clear flag
  *            @arg @ref SMARTCARD_CLEAR_OREF   OverRun error clear flag
  *            @arg @ref SMARTCARD_CLEAR_IDLEF  Idle line detection clear flag
  *            @arg @ref SMARTCARD_CLEAR_TCF    Transmission complete clear flag
  *            @arg @ref SMARTCARD_CLEAR_TCBGTF Transmission complete before guard time clear flag (when flag available)
  *            @arg @ref SMARTCARD_CLEAR_RTOF   Receiver timeout clear flag
  *            @arg @ref SMARTCARD_CLEAR_EOBF   End of block clear flag
  * @retval None
  */
#define __HAL_SMARTCARD_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR |= (uint32_t)(__IT_CLEAR__))

/** @brief  Set a specific SMARTCARD request flag.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __REQ__ specifies the request flag to set
  *          This parameter can be one of the following values:
  *            @arg @ref SMARTCARD_RXDATA_FLUSH_REQUEST Receive data flush Request
  *            @arg @ref SMARTCARD_TXDATA_FLUSH_REQUEST Transmit data flush Request
  * @retval None
  */
#define __HAL_SMARTCARD_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint16_t)(__REQ__))

/** @brief  Enable the SMARTCARD one bit sample method.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

/** @brief  Disable the SMARTCARD one bit sample method.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3 &= (uint32_t)~((uint32_t)USART_CR3_ONEBIT))

/** @brief  Enable the USART associated to the SMARTCARD Handle.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  Disable the USART associated to the SMARTCARD Handle
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @retval None
  */
#define __HAL_SMARTCARD_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)

/**
  * @}
  */

/* Private macros -------------------------------------------------------------*/
/** @defgroup SMARTCARD_Private_Macros SMARTCARD Private Macros
  * @{
  */

/** @brief  Report the SMARTCARD clock source.
  * @param  __HANDLE__ specifies the SMARTCARD Handle.
  * @param  __CLOCKSOURCE__ output variable.
  * @retval the SMARTCARD clocking source, written in __CLOCKSOURCE__.
  */
#define SMARTCARD_GETCLOCKSOURCE(__HANDLE__, __CLOCKSOURCE__)  \
  do {                                                         \
    if((__HANDLE__)->Instance == USART1)                       \
    {                                                          \
       switch(__HAL_RCC_GET_USART1_SOURCE())                   \
       {                                                       \
        case RCC_USART1CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK2;     \
          break;                                               \
        case RCC_USART1CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART1CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART1CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
       }                                                       \
    }                                                          \
    else if((__HANDLE__)->Instance == USART2)                  \
    {                                                          \
       switch(__HAL_RCC_GET_USART2_SOURCE())                   \
       {                                                       \
        case RCC_USART2CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK1;     \
          break;                                               \
        case RCC_USART2CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART2CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART2CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
       }                                                       \
    }                                                          \
    else if((__HANDLE__)->Instance == USART3)                  \
    {                                                          \
       switch(__HAL_RCC_GET_USART3_SOURCE())                   \
       {                                                       \
        case RCC_USART3CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK1;     \
          break;                                               \
        case RCC_USART3CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART3CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART3CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
       }                                                       \
    }                                                          \
    else if((__HANDLE__)->Instance == USART6)                  \
    {                                                          \
       switch(__HAL_RCC_GET_USART6_SOURCE())                   \
       {                                                       \
        case RCC_USART6CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK2;     \
          break;                                               \
        case RCC_USART6CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART6CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART6CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
       }                                                       \
    }                                                          \
    else                                                       \
    {                                                          \
      (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED;     \
    }                                                          \
  } while(0U)

/** @brief  Check the Baud rate range.
  * @note   The maximum Baud Rate is derived from the maximum clock on F7 (216 MHz)
  *         divided by the oversampling used on the SMARTCARD (i.e. 16).
  * @param  __BAUDRATE__ Baud rate set by the configuration function.
  * @retval Test result (TRUE or FALSE)
  */
#define IS_SMARTCARD_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 13500001U)

/** @brief  Check the block length range.
  * @note   The maximum SMARTCARD block length is 0xFF.
  * @param  __LENGTH__ block length.
  * @retval Test result (TRUE or FALSE)
  */
#define IS_SMARTCARD_BLOCKLENGTH(__LENGTH__) ((__LENGTH__) <= 0xFFU)

/** @brief  Check the receiver timeout value.
  * @note   The maximum SMARTCARD receiver timeout value is 0xFFFFFF.
  * @param  __TIMEOUTVALUE__ receiver timeout value.
  * @retval Test result (TRUE or FALSE)
  */
#define IS_SMARTCARD_TIMEOUT_VALUE(__TIMEOUTVALUE__)    ((__TIMEOUTVALUE__) <= 0xFFFFFFU)

/** @brief  Check the SMARTCARD autoretry counter value.
  * @note   The maximum number of retransmissions is 0x7.
  * @param  __COUNT__ number of retransmissions.
  * @retval Test result (TRUE or FALSE)
  */
#define IS_SMARTCARD_AUTORETRY_COUNT(__COUNT__)         ((__COUNT__) <= 0x7U)

/** @brief Ensure that SMARTCARD frame length is valid.
  * @param __LENGTH__ SMARTCARD frame length.
  * @retval SET (__LENGTH__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_SMARTCARD_WORD_LENGTH(__LENGTH__) ((__LENGTH__) == SMARTCARD_WORDLENGTH_9B)

/** @brief Ensure that SMARTCARD frame number of stop bits is valid.
  * @param __STOPBITS__ SMARTCARD frame number of stop bits.
  * @retval SET (__STOPBITS__ is valid) or RESET (__STOPBITS__ is invalid)
  */
#define IS_SMARTCARD_STOPBITS(__STOPBITS__) (((__STOPBITS__) == SMARTCARD_STOPBITS_0_5) ||\
                                             ((__STOPBITS__) == SMARTCARD_STOPBITS_1_5))

/** @brief Ensure that SMARTCARD frame parity is valid.
  * @param __PARITY__ SMARTCARD frame parity.
  * @retval SET (__PARITY__ is valid) or RESET (__PARITY__ is invalid)
  */
#define IS_SMARTCARD_PARITY(__PARITY__) (((__PARITY__) == SMARTCARD_PARITY_EVEN) || \
                                         ((__PARITY__) == SMARTCARD_PARITY_ODD))

/** @brief Ensure that SMARTCARD communication mode is valid.
  * @param __MODE__ SMARTCARD communication mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_SMARTCARD_MODE(__MODE__) ((((__MODE__) & 0xFFF3U) == 0x00U) && ((__MODE__) != 0x00U))

/** @brief Ensure that SMARTCARD frame polarity is valid.
  * @param __CPOL__ SMARTCARD frame polarity.
  * @retval SET (__CPOL__ is valid) or RESET (__CPOL__ is invalid)
  */
#define IS_SMARTCARD_POLARITY(__CPOL__) (((__CPOL__) == SMARTCARD_POLARITY_LOW) || ((__CPOL__) == SMARTCARD_POLARITY_HIGH))

/** @brief Ensure that SMARTCARD frame phase is valid.
  * @param __CPHA__ SMARTCARD frame phase.
  * @retval SET (__CPHA__ is valid) or RESET (__CPHA__ is invalid)
  */
#define IS_SMARTCARD_PHASE(__CPHA__) (((__CPHA__) == SMARTCARD_PHASE_1EDGE) || ((__CPHA__) == SMARTCARD_PHASE_2EDGE))

/** @brief Ensure that SMARTCARD frame last bit clock pulse setting is valid.
  * @param __LASTBIT__ SMARTCARD frame last bit clock pulse setting.
  * @retval SET (__LASTBIT__ is valid) or RESET (__LASTBIT__ is invalid)
  */
#define IS_SMARTCARD_LASTBIT(__LASTBIT__) (((__LASTBIT__) == SMARTCARD_LASTBIT_DISABLE) || \
                                           ((__LASTBIT__) == SMARTCARD_LASTBIT_ENABLE))

/** @brief Ensure that SMARTCARD frame sampling is valid.
  * @param __ONEBIT__ SMARTCARD frame sampling.
  * @retval SET (__ONEBIT__ is valid) or RESET (__ONEBIT__ is invalid)
  */
#define IS_SMARTCARD_ONE_BIT_SAMPLE(__ONEBIT__) (((__ONEBIT__) == SMARTCARD_ONE_BIT_SAMPLE_DISABLE) || \
                                                 ((__ONEBIT__) == SMARTCARD_ONE_BIT_SAMPLE_ENABLE))

/** @brief Ensure that SMARTCARD NACK transmission setting is valid.
  * @param __NACK__ SMARTCARD NACK transmission setting.
  * @retval SET (__NACK__ is valid) or RESET (__NACK__ is invalid)
  */
#define IS_SMARTCARD_NACK(__NACK__) (((__NACK__) == SMARTCARD_NACK_ENABLE) || \
                                     ((__NACK__) == SMARTCARD_NACK_DISABLE))

/** @brief Ensure that SMARTCARD receiver timeout setting is valid.
  * @param __TIMEOUT__ SMARTCARD receiver timeout setting.
  * @retval SET (__TIMEOUT__ is valid) or RESET (__TIMEOUT__ is invalid)
  */
#define IS_SMARTCARD_TIMEOUT(__TIMEOUT__) (((__TIMEOUT__) == SMARTCARD_TIMEOUT_DISABLE) || \
                                           ((__TIMEOUT__) == SMARTCARD_TIMEOUT_ENABLE))

/** @brief Ensure that SMARTCARD advanced features initialization is valid.
  * @param __INIT__ SMARTCARD advanced features initialization.
  * @retval SET (__INIT__ is valid) or RESET (__INIT__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_INIT(__INIT__) ((__INIT__) <= (SMARTCARD_ADVFEATURE_NO_INIT                | \
                                                               SMARTCARD_ADVFEATURE_TXINVERT_INIT          | \
                                                               SMARTCARD_ADVFEATURE_RXINVERT_INIT          | \
                                                               SMARTCARD_ADVFEATURE_DATAINVERT_INIT        | \
                                                               SMARTCARD_ADVFEATURE_SWAP_INIT              | \
                                                               SMARTCARD_ADVFEATURE_RXOVERRUNDISABLE_INIT  | \
                                                               SMARTCARD_ADVFEATURE_DMADISABLEONERROR_INIT | \
                                                               SMARTCARD_ADVFEATURE_MSBFIRST_INIT))

/** @brief Ensure that SMARTCARD frame TX inversion setting is valid.
  * @param __TXINV__ SMARTCARD frame TX inversion setting.
  * @retval SET (__TXINV__ is valid) or RESET (__TXINV__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_TXINV(__TXINV__) (((__TXINV__) == SMARTCARD_ADVFEATURE_TXINV_DISABLE) || \
                                                  ((__TXINV__) == SMARTCARD_ADVFEATURE_TXINV_ENABLE))

/** @brief Ensure that SMARTCARD frame RX inversion setting is valid.
  * @param __RXINV__ SMARTCARD frame RX inversion setting.
  * @retval SET (__RXINV__ is valid) or RESET (__RXINV__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_RXINV(__RXINV__) (((__RXINV__) == SMARTCARD_ADVFEATURE_RXINV_DISABLE) || \
                                                  ((__RXINV__) == SMARTCARD_ADVFEATURE_RXINV_ENABLE))

/** @brief Ensure that SMARTCARD frame data inversion setting is valid.
  * @param __DATAINV__ SMARTCARD frame data inversion setting.
  * @retval SET (__DATAINV__ is valid) or RESET (__DATAINV__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_DATAINV(__DATAINV__) (((__DATAINV__) == SMARTCARD_ADVFEATURE_DATAINV_DISABLE) || \
                                                      ((__DATAINV__) == SMARTCARD_ADVFEATURE_DATAINV_ENABLE))

/** @brief Ensure that SMARTCARD frame RX/TX pins swap setting is valid.
  * @param __SWAP__ SMARTCARD frame RX/TX pins swap setting.
  * @retval SET (__SWAP__ is valid) or RESET (__SWAP__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_SWAP(__SWAP__) (((__SWAP__) == SMARTCARD_ADVFEATURE_SWAP_DISABLE) || \
                                                ((__SWAP__) == SMARTCARD_ADVFEATURE_SWAP_ENABLE))

/** @brief Ensure that SMARTCARD frame overrun setting is valid.
  * @param __OVERRUN__ SMARTCARD frame overrun setting.
  * @retval SET (__OVERRUN__ is valid) or RESET (__OVERRUN__ is invalid)
  */
#define IS_SMARTCARD_OVERRUN(__OVERRUN__) (((__OVERRUN__) == SMARTCARD_ADVFEATURE_OVERRUN_ENABLE) || \
                                           ((__OVERRUN__) == SMARTCARD_ADVFEATURE_OVERRUN_DISABLE))

/** @brief Ensure that SMARTCARD DMA enabling or disabling on error setting is valid.
  * @param __DMA__ SMARTCARD DMA enabling or disabling on error setting.
  * @retval SET (__DMA__ is valid) or RESET (__DMA__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_DMAONRXERROR(__DMA__) (((__DMA__) == SMARTCARD_ADVFEATURE_DMA_ENABLEONRXERROR) || \
                                                       ((__DMA__) == SMARTCARD_ADVFEATURE_DMA_DISABLEONRXERROR))

/** @brief Ensure that SMARTCARD frame MSB first setting is valid.
  * @param __MSBFIRST__ SMARTCARD frame MSB first setting.
  * @retval SET (__MSBFIRST__ is valid) or RESET (__MSBFIRST__ is invalid)
  */
#define IS_SMARTCARD_ADVFEATURE_MSBFIRST(__MSBFIRST__) (((__MSBFIRST__) == SMARTCARD_ADVFEATURE_MSBFIRST_DISABLE) || \
                                                        ((__MSBFIRST__) == SMARTCARD_ADVFEATURE_MSBFIRST_ENABLE))

/** @brief Ensure that SMARTCARD request parameter is valid.
  * @param __PARAM__ SMARTCARD request parameter.
  * @retval SET (__PARAM__ is valid) or RESET (__PARAM__ is invalid)
  */
#define IS_SMARTCARD_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == SMARTCARD_RXDATA_FLUSH_REQUEST) || \
                                                   ((__PARAM__) == SMARTCARD_TXDATA_FLUSH_REQUEST))

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/* Include SMARTCARD HAL Extension module */
#include "stm32f7xx_hal_smartcard_ex.h"
=======
/* Include SMARTCARD HAL Extended module */
#include "stm32f7xx_hal_smartcard_ex.h"

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/* Exported functions --------------------------------------------------------*/
/** @addtogroup SMARTCARD_Exported_Functions
  * @{
  */
<<<<<<< HEAD
  
/** @addtogroup SMARTCARD_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  **********************************/
=======

/* Initialization and de-initialization functions  ****************************/
/** @addtogroup SMARTCARD_Exported_Functions_Group1
  * @{
  */

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
HAL_StatusTypeDef HAL_SMARTCARD_Init(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_DeInit(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_MspInit(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_MspDeInit(SMARTCARD_HandleTypeDef *hsmartcard);
<<<<<<< HEAD
=======

#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_SMARTCARD_RegisterCallback(SMARTCARD_HandleTypeDef *hsmartcard, HAL_SMARTCARD_CallbackIDTypeDef CallbackID, pSMARTCARD_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SMARTCARD_UnRegisterCallback(SMARTCARD_HandleTypeDef *hsmartcard, HAL_SMARTCARD_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_SMARTCARD_REGISTER_CALLBACKS */

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

<<<<<<< HEAD
/** @addtogroup SMARTCARD_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *******************************************************/
=======
/* IO operation functions *****************************************************/
/** @addtogroup SMARTCARD_Exported_Functions_Group2
  * @{
  */

>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
HAL_StatusTypeDef HAL_SMARTCARD_Transmit(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SMARTCARD_Receive(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SMARTCARD_Transmit_IT(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SMARTCARD_Receive_IT(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SMARTCARD_Transmit_DMA(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SMARTCARD_Receive_DMA(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_SMARTCARD_Abort(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortTransmit(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortReceive(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_Abort_IT(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortTransmit_IT(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortReceive_IT(SMARTCARD_HandleTypeDef *hsmartcard);

void HAL_SMARTCARD_IRQHandler(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_TxCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_RxCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_ErrorCallback(SMARTCARD_HandleTypeDef *hsmartcard);
<<<<<<< HEAD
void HAL_SMARTCARD_AbortCpltCallback (SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortTransmitCpltCallback (SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortReceiveCpltCallback (SMARTCARD_HandleTypeDef *hsmartcard);
=======
void HAL_SMARTCARD_AbortCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortTransmitCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortReceiveCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/**
  * @}
  */

<<<<<<< HEAD
/** @addtogroup SMARTCARD_Exported_Functions_Group3
  * @{
  */
/* Peripheral State functions  **************************************************/
HAL_SMARTCARD_StateTypeDef HAL_SMARTCARD_GetState(SMARTCARD_HandleTypeDef *hsmartcard);
uint32_t HAL_SMARTCARD_GetError(SMARTCARD_HandleTypeDef *hsmartcard);

/**
  * @}
  */ 
=======
/* Peripheral State and Error functions ***************************************/
/** @addtogroup SMARTCARD_Exported_Functions_Group4
  * @{
  */

HAL_SMARTCARD_StateTypeDef HAL_SMARTCARD_GetState(SMARTCARD_HandleTypeDef *hsmartcard);
uint32_t                   HAL_SMARTCARD_GetError(SMARTCARD_HandleTypeDef *hsmartcard);
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/**
  * @}
  */
<<<<<<< HEAD
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup SMARTCARD_Private_Constants SMARTCARD Private Constants
  * @{
  */

#define IS_SMARTCARD_WORD_LENGTH(__LENGTH__) ((__LENGTH__) == SMARTCARD_WORDLENGTH_9B) 
#define IS_SMARTCARD_STOPBITS(__STOPBITS__) ((__STOPBITS__) == SMARTCARD_STOPBITS_1_5)
#define IS_SMARTCARD_PARITY(__PARITY__) (((__PARITY__) == SMARTCARD_PARITY_EVEN) || \
                                         ((__PARITY__) == SMARTCARD_PARITY_ODD))
#define IS_SMARTCARD_MODE(__MODE__) ((((__MODE__) & (uint32_t)0xFFF3) == 0x00) && ((__MODE__) != (uint32_t)0x00))
#define IS_SMARTCARD_POLARITY(__CPOL__) (((__CPOL__) == SMARTCARD_POLARITY_LOW) || ((__CPOL__) == SMARTCARD_POLARITY_HIGH))
#define IS_SMARTCARD_PHASE(__CPHA__) (((__CPHA__) == SMARTCARD_PHASE_1EDGE) || ((__CPHA__) == SMARTCARD_PHASE_2EDGE))
#define IS_SMARTCARD_LASTBIT(__LASTBIT__) (((__LASTBIT__) == SMARTCARD_LASTBIT_DISABLE) || \
                                           ((__LASTBIT__) == SMARTCARD_LASTBIT_ENABLE))
#define IS_SMARTCARD_ONE_BIT_SAMPLE(__ONEBIT__) (((__ONEBIT__) == SMARTCARD_ONE_BIT_SAMPLE_DISABLE) || \
                                                  ((__ONEBIT__) == SMARTCARD_ONE_BIT_SAMPLE_ENABLE))
#define IS_SMARTCARD_NACK(__NACK__) (((__NACK__) == SMARTCARD_NACK_ENABLE) || \
                                     ((__NACK__) == SMARTCARD_NACK_DISABLE))
#define IS_SMARTCARD_TIMEOUT(__TIMEOUT__) (((__TIMEOUT__) == SMARTCARD_TIMEOUT_DISABLE) || \
                                           ((__TIMEOUT__) == SMARTCARD_TIMEOUT_ENABLE))
#define IS_SMARTCARD_ADVFEATURE_INIT(INIT)           ((INIT) <= (SMARTCARD_ADVFEATURE_NO_INIT | \
                                                            SMARTCARD_ADVFEATURE_TXINVERT_INIT | \
                                                            SMARTCARD_ADVFEATURE_RXINVERT_INIT | \
                                                            SMARTCARD_ADVFEATURE_DATAINVERT_INIT | \
                                                            SMARTCARD_ADVFEATURE_SWAP_INIT | \
                                                            SMARTCARD_ADVFEATURE_RXOVERRUNDISABLE_INIT | \
                                                            SMARTCARD_ADVFEATURE_DMADISABLEONERROR_INIT   | \
                                                            SMARTCARD_ADVFEATURE_MSBFIRST_INIT))  
#define IS_SMARTCARD_ADVFEATURE_TXINV(TXINV) (((TXINV) == SMARTCARD_ADVFEATURE_TXINV_DISABLE) || \
                                         ((TXINV) == SMARTCARD_ADVFEATURE_TXINV_ENABLE))
#define IS_SMARTCARD_ADVFEATURE_RXINV(RXINV) (((RXINV) == SMARTCARD_ADVFEATURE_RXINV_DISABLE) || \
                                         ((RXINV) == SMARTCARD_ADVFEATURE_RXINV_ENABLE))
#define IS_SMARTCARD_ADVFEATURE_DATAINV(DATAINV) (((DATAINV) == SMARTCARD_ADVFEATURE_DATAINV_DISABLE) || \
                                             ((DATAINV) == SMARTCARD_ADVFEATURE_DATAINV_ENABLE))
#define IS_SMARTCARD_ADVFEATURE_SWAP(SWAP) (((SWAP) == SMARTCARD_ADVFEATURE_SWAP_DISABLE) || \
                                       ((SWAP) == SMARTCARD_ADVFEATURE_SWAP_ENABLE))
#define IS_SMARTCARD_OVERRUN(OVERRUN)         (((OVERRUN) == SMARTCARD_ADVFEATURE_OVERRUN_ENABLE) || \
                                          ((OVERRUN) == SMARTCARD_ADVFEATURE_OVERRUN_DISABLE))
#define IS_SMARTCARD_ADVFEATURE_DMAONRXERROR(DMA)      (((DMA) == SMARTCARD_ADVFEATURE_DMA_ENABLEONRXERROR) || \
                                                   ((DMA) == SMARTCARD_ADVFEATURE_DMA_DISABLEONRXERROR))
#define IS_SMARTCARD_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 4500001)
#define IS_SMARTCARD_BLOCKLENGTH(__LENGTH__) ((__LENGTH__) <= 0xFF)
#define IS_SMARTCARD_TIMEOUT_VALUE(__TIMEOUTVALUE__)    ((__TIMEOUTVALUE__) <= 0xFFFFFF)
#define IS_SMARTCARD_AUTORETRY_COUNT(__COUNT__)         ((__COUNT__) <= 0x7)
#define IS_SMARTCARD_ADVFEATURE_MSBFIRST(MSBFIRST) (((MSBFIRST) == SMARTCARD_ADVFEATURE_MSBFIRST_DISABLE) || \
                                               ((MSBFIRST) == SMARTCARD_ADVFEATURE_MSBFIRST_ENABLE))
#define IS_SMARTCARD_REQUEST_PARAMETER(PARAM) (((PARAM) == SMARTCARD_RXDATA_FLUSH_REQUEST) || \
                                               ((PARAM) == SMARTCARD_TXDATA_FLUSH_REQUEST))   

=======
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/**
  * @}
  */

<<<<<<< HEAD
/* Private functions ---------------------------------------------------------*/
/** @defgroup SMARTCARD_Private_Functions SMARTCARD Private Functions
  * @{
  */

=======
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
/**
  * @}
  */

/**
  * @}
<<<<<<< HEAD
  */ 

/**
  * @}
=======
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8
  */

#ifdef __cplusplus
}
#endif

<<<<<<< HEAD
#endif /* __STM32F7xx_HAL_SMARTCARD_H */
=======
#endif /* STM32F7xx_HAL_SMARTCARD_H */
>>>>>>> 49e424905b5922b07aa7166ec7a0eeb90adf58a8

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
