/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : pin_mux.c
**     Project     : MRB-KW019032NA
**     Processor   : MKW01Z128CHN4
**     Component   : PinSettings
**     Version     : Component 1.2.0, Driver 1.4, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : GNU C Compiler
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc.
**     All Rights Reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file pin_mux.c
** @version 1.4
** @brief
**
*/
/*!
**  @addtogroup pin_mux_module pin_mux module documentation
**  @{
*/

/* MODULE pin_mux. */

#include "fsl_device_registers.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"
#include "pin_mux.h"

void configure_gpio_pins(uint32_t instance)
{
  switch(instance) {
    case PORTA_IDX:                             /* PTA */
      /* PORTA_PCR4 */
      PORT_HAL_SetMuxMode(PORTA,4u,kPortMuxAsGpio);
      /* PORTA_PCR18 */
      PORT_HAL_SetMuxMode(PORTA,18u,kPortMuxAsGpio);
      /* PORTA_PCR19 */
      PORT_HAL_SetMuxMode(PORTA,19u,kPortMuxAsGpio);
      break;
    case PORTB_IDX:                             /* PTB */
      /* PORTB_PCR0 */
      PORT_HAL_SetMuxMode(PORTB,0u,kPortMuxAsGpio);
      break;
    case PORTC_IDX:                             /* PTC */
      /* PORTC_PCR3 */
      PORT_HAL_SetMuxMode(PORTC,3u,kPortMuxAsGpio);
      /* PORTC_PCR4 */
      PORT_HAL_SetMuxMode(PORTC,4u,kPortMuxAsGpio);
      break;
    case PORTD_IDX:                             /* PTD */
      /* PORTD_PCR0 */
      PORT_HAL_SetMuxMode(PORTD,0u,kPortMuxAsGpio);
      /* PORTD_PCR4 */
      PORT_HAL_SetMuxMode(PORTD,4u,kPortMuxAsGpio);
      /* PORTD_PCR5 */
      PORT_HAL_SetMuxMode(PORTD,5u,kPortMuxAsGpio);
      /* PORTD_PCR6 */
      PORT_HAL_SetMuxMode(PORTD,6u,kPortMuxAsGpio);
      /* PORTD_PCR7 */
      PORT_HAL_SetMuxMode(PORTD,7u,kPortMuxAsGpio);
      break;
    case PORTE_IDX:                             /* PTE */
      /* PORTE_PCR16 */
      PORT_HAL_SetMuxMode(PORTE,16u,kPortMuxAsGpio);
      /* PORTE_PCR17 */
      PORT_HAL_SetMuxMode(PORTE,17u,kPortMuxAsGpio);
      /* PORTE_PCR30 */
      PORT_HAL_SetMuxMode(PORTE,30u,kPortMuxAsGpio);
      break;
    default:
      break;
  }
}

void configure_i2c_pins(uint32_t instance)
{
  switch(instance) {
    case I2C0_IDX:                          /* I2C0 */
      /* PORTB_PCR2 */
      PORT_HAL_SetMuxMode(PORTB,2u,kPortMuxAlt2);
      PORT_HAL_SetPassiveFilterCmd(PORTB,2u,false);
      PORT_HAL_SetPullMode(PORTB,2u,kPortPullUp);
      PORT_HAL_SetPullCmd(PORTB,2u,true);
      /* PORTB_PCR1 */
      PORT_HAL_SetMuxMode(PORTB,1u,kPortMuxAlt2);
      PORT_HAL_SetPassiveFilterCmd(PORTB,1u,false);
      PORT_HAL_SetPullMode(PORTB,1u,kPortPullUp);
      PORT_HAL_SetPullCmd(PORTB,1u,true);
      break;
    case I2C1_IDX:                          /* I2C1 */
      /* PORTC_PCR1 */
      PORT_HAL_SetMuxMode(PORTC,1u,kPortMuxAlt2);
      PORT_HAL_SetPassiveFilterCmd(PORTC,1u,false);
      /* PORTC_PCR2 */
      PORT_HAL_SetMuxMode(PORTC,2u,kPortMuxAlt2);
      PORT_HAL_SetPassiveFilterCmd(PORTC,2u,false);
      break;
    default:
      break;
  }
}

void configure_rtc_pins(uint32_t instance)
{
  /* PORTE_PCR26 */
  PORT_HAL_SetMuxMode(PORTE,26u,kPortMuxAlt6);
}

void configure_lpsci_pins(uint32_t instance)
{
  switch(instance) {
    case UART0_IDX:                             /* LPSCI0 */
      /* PORTA_PCR1 */
      PORT_HAL_SetMuxMode(PORTA,1u,kPortMuxAlt2);
      /* PORTA_PCR2 */
      PORT_HAL_SetMuxMode(PORTA,2u,kPortMuxAlt2);
      break;
    default:
      break;
  }
}

void configure_uart_pins(uint32_t instance)
{
  switch(instance) {
    case UART1_IDX:                             /* UART1 */
      /* PORTE_PCR0 */
      PORT_HAL_SetMuxMode(PORTE,0u,kPortMuxAlt3);
      /* PORTE_PCR1 */
      PORT_HAL_SetMuxMode(PORTE,1u,kPortMuxAlt3);
      break;
    case UART2_IDX:                             /* UART2 */
      /* PORTE_PCR16 */
      PORT_HAL_SetMuxMode(PORTE,16u,kPortMuxAlt3);
      /* PORTE_PCR17 */
      PORT_HAL_SetMuxMode(PORTE,17u,kPortMuxAlt3);
      break;
    default:
      break;
  }
}

/* Setup TSI pins for on board electrodes */
void configure_tsi_pins(uint32_t instance) // todo
{
  switch(instance) {
    case TSI0_IDX:                             /* TSI0 */
      /* PORTB_PCR16 */
      PORT_HAL_SetMuxMode(PORTB,16u,kPortPinDisabled);
      /* PORTB_PCR17 */
      PORT_HAL_SetMuxMode(PORTB,17u,kPortPinDisabled);
      break;
    default:
      break;
  }
}

void configure_spi_pins(uint32_t instance)
{
  switch(instance) {
    case SPI0_IDX:                          /* SPI0 */
      /* PORTE_PCR19 */
      PORT_HAL_SetMuxMode(PORTE,19u,kPortMuxAlt2); /* MISO */
      /* PORTE_PCR18 */
      PORT_HAL_SetMuxMode(PORTE,18u,kPortMuxAlt2); /* MOSI */
      /* PORTE_PCR17 */
      PORT_HAL_SetMuxMode(PORTE,17u,kPortMuxAlt2); /* SCK */
      /* PORTE_PCR16 */
      PORT_HAL_SetMuxMode(PORTE,16u,kPortMuxAlt2); /* PCS0 */
      break;
    case SPI1_IDX:                          /* SPI1 */
      /* PORTD_PCR7 */
      PORT_HAL_SetMuxMode(PORTD,7u,kPortMuxAlt2); /* MISO */
      /* PORTD_PCR6 */
      PORT_HAL_SetMuxMode(PORTD,6u,kPortMuxAlt2); /* MOSI */
      /* PORTD_PCR5 */
      PORT_HAL_SetMuxMode(PORTD,5u,kPortMuxAlt2); /* SCK */
      /* PORTD_PCR4 */
      PORT_HAL_SetMuxMode(PORTD,4u,kPortMuxAlt2); /* PCS0 */
      break;
    default:
      break;
  }
}

/* Setup SPI pins to communicate with wireless modem */
void configure_spi_pins_for_modem(uint32_t instance)
{
  switch(instance) {
    case SPI0_IDX:                          /* SPI0 */
      /* PORTE_PCR19 */
      PORT_HAL_SetMuxMode(PORTC,6u,kPortMuxAlt2); /* MISO */
      /* PORTE_PCR18 */
      PORT_HAL_SetMuxMode(PORTC,7u,kPortMuxAlt2); /* MOSI */
      /* PORTE_PCR17 */
      PORT_HAL_SetMuxMode(PORTC,5u,kPortMuxAlt2); /* SCK */
      /* PORTE_PCR16 */
      PORT_HAL_SetMuxMode(PORTD,0u,kPortMuxAlt2); /* PCS0 */
      break;
    default:
      break;
  }
}

void configure_tpm_pins(uint32_t instance)
{
  switch(instance) {
    case TPM0_IDX:                             /* TPM0 */
      /* PTD_PCR5 TPM0 channel 5 */
      PORT_HAL_SetMuxMode(PORTD,5u,kPortMuxAlt4);
      break;
    default:
      break;
  }
}

void configure_cmp_pins(uint32_t instance)
{
  switch (instance) {
    case CMP0_IDX:
      PORT_HAL_SetMuxMode(PORTC,6u,kPortPinDisabled); /* PTC6 - CMP0_IN0. */
      break;
    default:
      break;
  }
}

void configure_dac_pins(uint32_t instance)
{
  switch (instance) {
    case DAC0_IDX:
      PORT_HAL_SetMuxMode(PORTE,30u,kPortPinDisabled);
      break;
    default:
      break;
  }
}

void configure_xcvr_pins(void)
{
  /* XCVR DIO0 */
  PORT_HAL_SetMuxMode(PORTC,4u,kPortMuxAsGpio);
  GPIO_HAL_SetPinDir(GPIOC,4u,kGpioDigitalInput);

  /* XCVR DIO1 */
  PORT_HAL_SetMuxMode(PORTC,3u,kPortMuxAsGpio);
  GPIO_HAL_SetPinDir(GPIOC,3u,kGpioDigitalInput);

  /* XCVR DIO4 */
  PORT_HAL_SetMuxMode(PORTD,4u,kPortMuxAsGpio);
  GPIO_HAL_SetPinDir(GPIOD,4u,kGpioDigitalInput);

  /* XCVR CLKIN */
  PORT_HAL_SetMuxMode(PORTA,18u,kPortMuxAsGpio);
  GPIO_HAL_SetPinDir(GPIOA,18u,kGpioDigitalInput);

  /* XCVR RESET */
  PORT_HAL_SetMuxMode(PORTE,30u,kPortMuxAsGpio);
  GPIO_HAL_SetPinDir(GPIOE,30u,kGpioDigitalOutput);
}

/* END pin_mux. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
