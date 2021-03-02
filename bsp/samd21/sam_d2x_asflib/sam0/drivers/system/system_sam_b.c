/**
 * \file
 *
 * \brief SAM System related functionality
 *
 * Copyright (C) 2015-2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "system_sam_b.h"

uint32_t system_clock_value;

/**
 * \brief System clock config
 *
 * Use this function to config system clock.
 *
 * \param[in]  resoure    Selection system clock resource
 * \param[in]  freq       Selection clock frequency
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_config(enum system_clock_resource resoure, \
                enum system_clock_freq freq)
{
    switch (resoure) {
        case CLOCK_RESOURCE_XO_26_MHZ:
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                    LPMCU_MISC_REGS_LPMCU_CTRL_USE_BT26M_CLK | \
                    LPMCU_MISC_REGS_LPMCU_CTRL_USE_ARM_LP_CLK;
            system_clock_value = 26000000;
            break;

        case CLOCK_RESOURCE_LP_2_MHZ:
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                    LPMCU_MISC_REGS_LPMCU_CTRL_USE_ARM_LP_CLK;
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg &= \
                    ~LPMCU_MISC_REGS_LPMCU_CTRL_USE_BT26M_CLK;
            AON_GP_REGS0->AON_PMU_CTRL.reg |= \
                    AON_GP_REGS_AON_PMU_CTRL_PMU_2MHZ_CLK_EN;
            system_clock_value = 2000000;
            break;

        case CLOCK_RESOURCE_RC_26_MHZ:
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg &= \
                    ~(LPMCU_MISC_REGS_LPMCU_CTRL_USE_BT26M_CLK | \
                    LPMCU_MISC_REGS_LPMCU_CTRL_USE_ARM_LP_CLK);
            system_clock_value = 26000000;
            break;

        default:
            return STATUS_ERR_INVALID_ARG;
    }

    LPMCU_MISC_REGS0->LPMCU_CTRL.reg &= \
        ~LPMCU_MISC_REGS_LPMCU_CTRL_LPMCU_CLK_SEL_Msk;
    LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
        LPMCU_MISC_REGS_LPMCU_CTRL_LPMCU_CLK_SEL(freq);

    return STATUS_OK;
}

/**
 * \brief Get the system clock value
 *
 * Use this function to get system clock value.
 *
 * \return system clock value.
 */
uint32_t system_clock_get_value(void)
{
    return system_clock_value;
}

/**
 * \brief System clock peripheral enable
 *
 * Use this function to enable system clock peripheral.
 *
 * \param[in]  peripheral    Selection peripheral
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_peripheral_enable(enum system_peripheral peripheral)
{
    switch (peripheral) {
        case PERIPHERAL_SPI_FLASH:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_SPI_FLASH0_CLK_EN;
        break;

        case PERIPHERAL_SPI0_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_SPI0_CORE_CLK_EN;
        break;

        case PERIPHERAL_SPI1_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_SPI1_CORE_CLK_EN;
        break;

        case PERIPHERAL_I2C0_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_I2C0_CORE_CLK_EN;
        break;

        case PERIPHERAL_DUALT_TIMER:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_DUALTIMER0_CLK_EN;
        break;

        case PERIPHERAL_GPIO_CLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_GPIO_CLK_EN;
        break;

        case PERIPHERAL_TIMER:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_TIMER0_CLK_EN;
        break;

        case PERIPHERAL_WDT0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_WDT0_CLK_EN;
        break;

        case PERIPHERAL_WDT1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_WDT1_CLK_EN;
        break;

        case PERIPHERAL_UART0_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART0_CORE_CLK_EN;
        break;

        case PERIPHERAL_UART0_IF:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART0_IF_CLK_EN;
        break;

        case PERIPHERAL_UART1_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART1_CORE_CLK_EN;
        break;

        case PERIPHERAL_UART1_IF:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART1_IF_CLK_EN;
        break;

        case PERIPHERAL_NVIC:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_IRQ_CTRLR_CORE_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_IDRAM_1_GL_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_IDRAM_2_GL_MEM_CLK_EN;
        break;

        case PERIPHERAL_ROM:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_ROM_MEM_CLK_EN;
        break;

        case PERIPHERAL_LOW_POWER_IF:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_CALIB_XBAR_IF_CLK_EN;
        break;

        case PERIPHERAL_AON_WRAPPER:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_AON_WRAPPER_CLK_EN;
        break;

        case PERIPHERAL_ARM_PCLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_ARM_PCLK_EN;
        break;

        case PERIPHERAL_ARM_GATED_PCLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_ARM_PCLKG_EN;
        break;

        case PERIPHERAL_ARM_BLE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_BLE_MEM_CLK_EN;
        break;

        case PERIPHERAL_QDEC0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_QUAD_DEC0_CLK_EN;
        break;

        case PERIPHERAL_QDEC1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_QUAD_DEC1_CLK_EN;
        break;

        case PERIPHERAL_QDEC2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_QUAD_DEC2_CLK_EN;
        break;

        case PERIPHERAL_I2C1_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_I2C1_CORE_CLK_EN;
        break;

        case PERIPHERAL_LOW_POWER_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_CALIB_CLK_EN;
        break;

        case PERIPHERAL_EFUSE1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE0_CLK_EN;
        break;

        case PERIPHERAL_EFUSE2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE1_CLK_EN;
        break;

        case PERIPHERAL_EFUSE3:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE2_CLK_EN;
        break;

        case PERIPHERAL_EFUSE4:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE3_CLK_EN;
        break;

        case PERIPHERAL_EFUSE5:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE4_CLK_EN;
        break;

        case PERIPHERAL_EFUSE6:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE5_CLK_EN;
        break;

        case PERIPHERAL_PWM0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM0_CLK_EN;
        break;

        case PERIPHERAL_PWM1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM1_CLK_EN;
        break;

        case PERIPHERAL_PWM2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM2_CLK_EN;
        break;

        case PERIPHERAL_PWM3:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM3_CLK_EN;
        break;

        case PERIPHERAL_ADC:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SENS_ADC_CLK_EN;
        break;

        case PERIPHERAL_SPI0_SCK_PHASE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SPI0_SCK_PHASE_INT_CLK_EN;
        break;

        case PERIPHERAL_SPI1_SCK_PHASE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SPI1_SCK_PHASE_INT_CLK_EN;
        break;

        case PERIPHERAL_GPIO_GCLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_GPIO_GCLK_EN;
        break;

        case PERIPHERAL_TIMER0_GATE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_TIMER0_PGCLK_EN;
        break;

        case PERIPHERAL_SHA_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SHA_CORE_CLK_EN;
        break;

        case PERIPHERAL_SHA_AHB:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SHA_AHB_CLK_EN;
        break;

        case PERIPHERAL_AES_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_AES_CORE_CLK_EN;
        break;

        case PERIPHERAL_AES_AHB:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_AES_AHB_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1_0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_1_0_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1_1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_1_1_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1_2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_1_2_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM2_0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_2_0_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM2_1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_2_1_MEM_CLK_EN;
        break;

        case PERIPHERAL_BLE_RXTX:
            LPMCU_MISC_REGS0->BTMCU_CTRL.reg |= \
                LPMCU_MISC_REGS_BTMCU_CTRL_RXTX_SEQ_CLK_EN;
        break;

        case PERIPHERAL_BLE_AHB:
            LPMCU_MISC_REGS0->BTMCU_CTRL.reg |= \
                LPMCU_MISC_REGS_BTMCU_CTRL_AHB_CLK_EN;
        break;

        case PERIPHERAL_BLE_PERIPH_REGS:
            LPMCU_MISC_REGS0->BTMCU_CTRL.reg |= \
                LPMCU_MISC_REGS_BTMCU_CTRL_PERIPH_REGS_CLK_EN;
        break;

        default:
            return STATUS_ERR_INVALID_ARG;
    }

    return STATUS_OK;
}

/**
 * \brief System clock peripheral disable
 *
 * Use this function to disable system clock peripheral.
 *
 * \param[in]  peripheral    Selection peripheral
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_peripheral_disable(enum system_peripheral peripheral)
{
    switch (peripheral) {
        case PERIPHERAL_SPI_FLASH:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_SPI_FLASH0_CLK_EN;
        break;

        case PERIPHERAL_SPI0_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_SPI0_CORE_CLK_EN;
        break;

        case PERIPHERAL_SPI1_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_SPI1_CORE_CLK_EN;
        break;

        case PERIPHERAL_I2C0_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_I2C0_CORE_CLK_EN;
        break;

        case PERIPHERAL_DUALT_TIMER:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_DUALTIMER0_CLK_EN;
        break;

        case PERIPHERAL_GPIO_CLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_GPIO_CLK_EN;
        break;

        case PERIPHERAL_TIMER:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_TIMER0_CLK_EN;
        break;

        case PERIPHERAL_WDT0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_WDT0_CLK_EN;
        break;

        case PERIPHERAL_WDT1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_WDT1_CLK_EN;
        break;

        case PERIPHERAL_UART0_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART0_CORE_CLK_EN;
        break;

        case PERIPHERAL_UART0_IF:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART0_IF_CLK_EN;
        break;

        case PERIPHERAL_UART1_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART1_CORE_CLK_EN;
        break;

        case PERIPHERAL_UART1_IF:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_UART1_IF_CLK_EN;
        break;

        case PERIPHERAL_NVIC:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_IRQ_CTRLR_CORE_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_IDRAM_1_GL_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_IDRAM_2_GL_MEM_CLK_EN;
        break;

        case PERIPHERAL_ROM:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_ROM_MEM_CLK_EN;
        break;

        case PERIPHERAL_LOW_POWER_IF:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_CALIB_XBAR_IF_CLK_EN;
        break;

        case PERIPHERAL_AON_WRAPPER:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_AON_WRAPPER_CLK_EN;
        break;

        case PERIPHERAL_ARM_PCLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_ARM_PCLK_EN;
        break;

        case PERIPHERAL_ARM_GATED_PCLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_ARM_PCLKG_EN;
        break;

        case PERIPHERAL_ARM_BLE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_BLE_MEM_CLK_EN;
        break;

        case PERIPHERAL_QDEC0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_QUAD_DEC0_CLK_EN;
        break;

        case PERIPHERAL_QDEC1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_QUAD_DEC1_CLK_EN;
        break;

        case PERIPHERAL_QDEC2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_QUAD_DEC2_CLK_EN;
        break;

        case PERIPHERAL_I2C1_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_I2C1_CORE_CLK_EN;
        break;

        case PERIPHERAL_LOW_POWER_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_0_CALIB_CLK_EN;
        break;

        case PERIPHERAL_EFUSE1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE0_CLK_EN;
        break;

        case PERIPHERAL_EFUSE2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE1_CLK_EN;
        break;

        case PERIPHERAL_EFUSE3:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE2_CLK_EN;
        break;

        case PERIPHERAL_EFUSE4:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE3_CLK_EN;
        break;

        case PERIPHERAL_EFUSE5:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE4_CLK_EN;
        break;

        case PERIPHERAL_EFUSE6:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_EFUSE5_CLK_EN;
        break;

        case PERIPHERAL_PWM0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM0_CLK_EN;
        break;

        case PERIPHERAL_PWM1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM1_CLK_EN;
        break;

        case PERIPHERAL_PWM2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM2_CLK_EN;
        break;

        case PERIPHERAL_PWM3:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_PWM3_CLK_EN;
        break;

        case PERIPHERAL_ADC:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SENS_ADC_CLK_EN;
        break;

        case PERIPHERAL_SPI0_SCK_PHASE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SPI0_SCK_PHASE_INT_CLK_EN;
        break;

        case PERIPHERAL_SPI1_SCK_PHASE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SPI1_SCK_PHASE_INT_CLK_EN;
        break;

        case PERIPHERAL_GPIO_GCLK:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_GPIO_GCLK_EN;
        break;

        case PERIPHERAL_TIMER0_GATE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_TIMER0_PGCLK_EN;
        break;

        case PERIPHERAL_SHA_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SHA_CORE_CLK_EN;
        break;

        case PERIPHERAL_SHA_AHB:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_SHA_AHB_CLK_EN;
        break;

        case PERIPHERAL_AES_CORE:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_AES_CORE_CLK_EN;
        break;

        case PERIPHERAL_AES_AHB:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_AES_AHB_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1_0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_1_0_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1_1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_1_1_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM1_2:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_1_2_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM2_0:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_2_0_MEM_CLK_EN;
        break;

        case PERIPHERAL_IDRAM2_1:
            LPMCU_MISC_REGS0->LPMCU_CLOCK_ENABLES_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CLOCK_ENABLES_1_IDRAM_2_1_MEM_CLK_EN;
        break;

        case PERIPHERAL_BLE_RXTX:
            LPMCU_MISC_REGS0->BTMCU_CTRL.reg &= \
                ~LPMCU_MISC_REGS_BTMCU_CTRL_RXTX_SEQ_CLK_EN;
        break;

        case PERIPHERAL_BLE_AHB:
            LPMCU_MISC_REGS0->BTMCU_CTRL.reg &= \
                ~LPMCU_MISC_REGS_BTMCU_CTRL_AHB_CLK_EN;
        break;

        case PERIPHERAL_BLE_PERIPH_REGS:
            LPMCU_MISC_REGS0->BTMCU_CTRL.reg &= \
                ~LPMCU_MISC_REGS_BTMCU_CTRL_PERIPH_REGS_CLK_EN;
        break;

        default:
            return STATUS_ERR_INVALID_ARG;
    }

    return STATUS_OK;
}

/**
 * \brief System clock peripheral frequency config
 *
 * Use this function to config system clock peripheral frequency.
 *
 * \param[in]  peripheral    Selection peripheral
 * \param[in]  freq          Selection clock frequency
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_peripheral_freq_config( \
        enum system_peripheral peripheral, \
        enum system_clock_freq freq)
{
    switch (peripheral) {
        case PERIPHERAL_SPI_FLASH:
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg &= \
                    ~LPMCU_MISC_REGS_LPMCU_CTRL_SPI_FLASH0_CLKSEL_Msk;
            switch (freq) {
                case CLOCK_FREQ_26_MHZ:
                    LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                        LPMCU_MISC_REGS_LPMCU_CTRL_SPI_FLASH0_CLKSEL_3;
                    break;
                case CLOCK_FREQ_13_MHZ:
                    LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                        LPMCU_MISC_REGS_LPMCU_CTRL_SPI_FLASH0_CLKSEL_2;
                    break;
                case CLOCK_FREQ_6_5_MHZ:
                    LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                        LPMCU_MISC_REGS_LPMCU_CTRL_SPI_FLASH0_CLKSEL_1;
                break;
                case CLOCK_FREQ_3_25_MHZ:
                    LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                        LPMCU_MISC_REGS_LPMCU_CTRL_SPI_FLASH0_CLKSEL_0;
                break;
            }
            break;

        case PERIPHERAL_DUALT_TIMER:
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_CTRL_DUALTIMER0_CLK_SEL_Msk;
            LPMCU_MISC_REGS0->LPMCU_CTRL.reg |= \
                LPMCU_MISC_REGS_LPMCU_CTRL_DUALTIMER0_CLK_SEL(freq);
            break;

        case PERIPHERAL_PWM0:
            LPMCU_MISC_REGS0->PWM0_CTRL.reg &= \
                ~LPMCU_MISC_REGS_PWM0_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->PWM0_CTRL.reg |= \
                LPMCU_MISC_REGS_PWM0_CTRL_CLOCK_SEL(freq);
            break;

        case PERIPHERAL_PWM1:
            LPMCU_MISC_REGS0->PWM1_CTRL.reg &= \
                ~LPMCU_MISC_REGS_PWM1_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->PWM1_CTRL.reg |= \
                LPMCU_MISC_REGS_PWM1_CTRL_CLOCK_SEL(freq);
            break;

        case PERIPHERAL_PWM2:
            LPMCU_MISC_REGS0->PWM2_CTRL.reg &= \
                ~LPMCU_MISC_REGS_PWM2_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->PWM2_CTRL.reg |= \
                LPMCU_MISC_REGS_PWM2_CTRL_CLOCK_SEL(freq);
            break;

        case PERIPHERAL_PWM3:
            LPMCU_MISC_REGS0->PWM3_CTRL.reg &= \
                ~LPMCU_MISC_REGS_PWM3_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->PWM3_CTRL.reg |= \
                LPMCU_MISC_REGS_PWM3_CTRL_CLOCK_SEL(freq);
            break;

        case PERIPHERAL_QDEC0:
            LPMCU_MISC_REGS0->QUAD_DEC0_CTRL.reg &= \
                ~LPMCU_MISC_REGS_QUAD_DEC0_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->QUAD_DEC0_CTRL.reg |= \
                LPMCU_MISC_REGS_QUAD_DEC0_CTRL_CLOCK_SEL(freq);
            break;

        case PERIPHERAL_QDEC1:
            LPMCU_MISC_REGS0->QUAD_DEC1_CTRL.reg &= \
                ~LPMCU_MISC_REGS_QUAD_DEC1_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->QUAD_DEC1_CTRL.reg |= \
                LPMCU_MISC_REGS_QUAD_DEC1_CTRL_CLOCK_SEL(freq);
            break;

        case PERIPHERAL_QDEC2:
            LPMCU_MISC_REGS0->QUAD_DEC2_CTRL.reg &= \
                ~LPMCU_MISC_REGS_QUAD_DEC2_CTRL_CLOCK_SEL_Msk;
            LPMCU_MISC_REGS0->QUAD_DEC2_CTRL.reg |= \
                LPMCU_MISC_REGS_QUAD_DEC2_CTRL_CLOCK_SEL(freq);
            break;

        default:
            return  STATUS_ERR_INVALID_ARG;
    }

    return STATUS_OK;
}

/**
 * \brief System global reset
 *
 * Use this function to reset system global.
 *
 */
void system_global_reset(void)
{
    LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
        ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_GLOBAL_RSTN;
    LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
        LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_GLOBAL_RSTN;
};

/**
 * \brief System peripheral reset
 *
 * Use this function to reset system peripheral.
 *
 * \param[in]  peripheral    Selection peripheral
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_peripheral_reset(enum system_peripheral peripheral)
{
    switch (peripheral) {
        case PERIPHERAL_LPMCU_CPU:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CPU_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CPU_RSTN;
        break;

        case PERIPHERAL_SPI_FLASH:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI_FLASH0_SYS_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI_FLASH0_SYS_RSTN;
        break;

        case PERIPHERAL_SPI_FLASH_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI_FLASH0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI_FLASH0_RSTN;
        break;

        case PERIPHERAL_SPI0_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI0_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI0_CORE_RSTN;
        break;

        case PERIPHERAL_SPI0_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI0_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI0_IF_RSTN;
        break;

        case PERIPHERAL_SPI1_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI1_CORE_RESETN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI1_CORE_RESETN;
        break;

        case PERIPHERAL_SPI1_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI1_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_SPI1_IF_RSTN;
        break;

        case PERIPHERAL_I2C0_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_I2C0_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_I2C0_CORE_RSTN;
        break;

        case PERIPHERAL_I2C0_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_I2C0_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_I2C0_IF_RSTN;
        break;

        case PERIPHERAL_GPIO_CLK:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_GPIO_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_GPIO_RSTN;
        break;

        case PERIPHERAL_TIMER:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_TIMER0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_TIMER0_RSTN;
        break;

        case PERIPHERAL_UART0_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART0_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART0_CORE_RSTN;
        break;

        case PERIPHERAL_UART0_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART0_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART0_IF_RSTN;
        break;

        case PERIPHERAL_UART1_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART1_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART1_CORE_RSTN;
        break;

        case PERIPHERAL_UART1_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART1_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_UART1_IF_RSTN;
        break;

        case PERIPHERAL_WDT0:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_WDT0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_WDT0_RSTN;
        break;

        case PERIPHERAL_WDT1:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_WDT1_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_WDT1_RSTN;
        break;

        case PERIPHERAL_NVIC:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_IRQ_CTRLR_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_IRQ_CTRLR_CORE_RSTN;
        break;

        case PERIPHERAL_MBIST:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_MBIST_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_MBIST_RSTN;
        break;

        case PERIPHERAL_LOW_POWER_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CALIB_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CALIB_RSTN;
        break;

        case PERIPHERAL_LOW_POWER_APB:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CALIB_XBAR_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_CALIB_XBAR_IF_RSTN;
        break;

        case PERIPHERAL_LPMCU_DEBUG:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_DBUG_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_DBUG_RSTN;
        break;

        case PERIPHERAL_ARM_FREE_CLK:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_ARM_FREE_CLK_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_ARM_FREE_CLK_RSTN;
        break;

        case PERIPHERAL_ARM_APB:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_ARM_PRESETN_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_ARM_PRESETN_RSTN;
        break;

        case PERIPHERAL_QDEC0:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_QUAD_DEC0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_QUAD_DEC0_RSTN;
        break;

        case PERIPHERAL_QDEC1:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_QUAD_DEC1_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_QUAD_DEC1_RSTN;
        break;

        case PERIPHERAL_QDEC2:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_QUAD_DEC2_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_QUAD_DEC2_RSTN;
        break;

        case PERIPHERAL_PWM0:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM0_RSTN;
        break;

        case PERIPHERAL_PWM1:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM1_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM1_RSTN;
        break;

        case PERIPHERAL_PWM2:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM2_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM2_RSTN;
        break;

        case PERIPHERAL_PWM3:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM3_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_0.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_0_PWM3_RSTN;
        break;

        case PERIPHERAL_DUALT_TIMER:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_DUALTIMER0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_DUALTIMER0_RSTN;
        break;

        case PERIPHERAL_I2C1_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_I2C1_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_I2C1_CORE_RSTN;
        break;

        case PERIPHERAL_I2C1_IF:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_I2C1_IF_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_I2C1_IF_RSTN;
        break;

        case PERIPHERAL_SHA_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_SHA_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_SHA_CORE_RSTN;
        break;

        case PERIPHERAL_SHA_AHB:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_SHA_AHB_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_SHA_AHB_RSTN;
        break;

        case PERIPHERAL_AES_CORE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_AES_CORE_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_AES_CORE_RSTN;
        break;

        case PERIPHERAL_AES_AHB:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_AES_AHB_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SECURITY_AES_AHB_RSTN;
        break;

        case PERIPHERAL_SPI0_SCK_CLK:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI0_SCK_CLK_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI0_SCK_CLK_RSTN;
        break;

        case PERIPHERAL_SPI1_SCK_CLK:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI1_SCK_CLK_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI1_SCK_CLK_RSTN;
        break;

        case PERIPHERAL_SPI0_SCK_PHASE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI0_SCK_PHASE_INT_CLK_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI0_SCK_PHASE_INT_CLK_RSTN;
        break;

        case PERIPHERAL_SPI1_SCK_PHASE:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI1_SCK_PHASE_INT_CLK_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_SPI1_SCK_PHASE_INT_CLK_RSTN;
        break;

        case PERIPHERAL_DMA:
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg &= \
                ~LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_PROV_DMA_CTRL0_RSTN;
            LPMCU_MISC_REGS0->LPMCU_GLOBAL_RESET_1.reg |= \
                LPMCU_MISC_REGS_LPMCU_GLOBAL_RESET_1_PROV_DMA_CTRL0_RSTN;
        break;

        default:
            return STATUS_ERR_INVALID_ARG;
    }

    return STATUS_OK;
}

/**
 * \brief Register the ISR
 *
 * Use this function to register a ISR to the RAM table.
 *
 * \param[in] isr_index Index of the ISR
 * \param[in] isr_address Address of the ISR
 *
 */
void system_register_isr(enum ram_isr_table_index isr_index,
        uint32_t isr_address)
{
    uint32_t *temp;
    temp = (uint32_t *)(isr_index * 4 + ISR_RAM_MAP_START_ADDRESS);
    *temp = isr_address;
}

/**
 * \brief Unregister the ISR
 *
 * Use this function to unregister a ISR to the RAM table.
 *
 * \param[in] isr_index Index of the ISR
 *
 */
void system_unregister_isr(enum ram_isr_table_index isr_index)
{
    uint32_t *temp;
    temp = (uint32_t *)(isr_index * 4 + ISR_RAM_MAP_START_ADDRESS);
    *temp = 0;
}

/**
 * \brief Initializes an system calibration configuration structure to default values
 *
 * This function will initialize a given system calibration configuration
 * structure to a set of known default values. This function should be called
 * on any new instance of the configuration structures before being modified by
 * the user application.
 *
 * \param[out] config  Configuration structure to initialize to default values
 */
void system_calibration_get_config_defaults(struct system_calibration_config *config)
{
    config->clk_num             = CALIBRATION_CLK_NUM_1024;
    config->interrupt_control   = CALIBRATION_INTERRUPT_OSC_DONE;
    config->osc_fractional_part = 0;
    config->osc_integer_part    = 0;
    config->rtc_fractional_part = 0;
    config->rtc_integer_part    = 0;
}

/**
 * \brief System calibration set configuration
 *
 * Use this function to set system calibration configuration.
 *
 * \param[in]  config    Point to struct system_calibration_config
 *
 */
void system_calibration_set_config(struct system_calibration_config *config)
{
    Assert(config);

    LP_CLK_CAL_REGS0->CONFIG_REG.reg &= \
        ~(LP_CLK_CAL_REGS_CONFIG_REG_NUMBER_CALIB_CLKS_Msk | \
        LP_CLK_CAL_REGS_CONFIG_REG_IRQ_CONTROL_Msk);
    LP_CLK_CAL_REGS0->CONFIG_REG.reg |= \
        LP_CLK_CAL_REGS_CONFIG_REG_NUMBER_CALIB_CLKS(config->clk_num) | \
        LP_CLK_CAL_REGS_CONFIG_REG_IRQ_CONTROL(config->interrupt_control);
}

/**
 * \brief System calibration get interrupt status
 *
 * Use this function to get system calibration interrupt status.
 *
 * \param[in]  config    Point to struct system_calibration_config
 *
 * \return Status of operation.
 * \retval CALBRATION_NO_IN_PROGRESS     No calibration in progress
 * \retval CALBRATION_IN_PROGRESS        Calibration in progress
 * \retval CALBRATION_DONE               Calibration done
 */
enum system_calibration_status system_calibration_get_interrupt_status( \
                struct system_calibration_config *config)
{
    switch (config->interrupt_control) {
        case CALIBRATION_INTERRUPT_OSC_DONE:
            if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.OSC_CAL_RUNNING) {
                return CALBRATION_IN_PROGRESS;
            } else if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.CALIBRATION_OSC_DONE) {
                return CALBRATION_DONE;
            }
            break;
        case CALIBRATION_INTERRUPT_RTC_DONE:
            if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.RTC_CAL_RUNNING) {
                return CALBRATION_IN_PROGRESS;
            } else if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.CALIBRATION_RTC_DONE) {
                return CALBRATION_DONE;
            }
            break;
        case CALIBRATION_INTERRUPT_OSC_OR_RTC_DONE:
            if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.CALIBRATION_OSC_DONE || \
                LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.CALIBRATION_RTC_DONE) {
                return CALBRATION_DONE;
            } else if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.OSC_CAL_RUNNING || \
                LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.RTC_CAL_RUNNING){
                return CALBRATION_IN_PROGRESS;
            }
            break;
        case CALIBRATION_INTERRUPT_OSC_AND_RTC_DONE:
            if (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.CALIBRATION_OSC_DONE && \
                LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.CALIBRATION_RTC_DONE) {
                return CALBRATION_DONE;
            } else if  (LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.OSC_CAL_RUNNING || \
                LP_CLK_CAL_REGS0->CALIB_STATUS_REG.bit.RTC_CAL_RUNNING){
                return CALBRATION_IN_PROGRESS;
            }
            break;

        default:
            return CALBRATION_NO_IN_PROGRESS;
    }

    return CALBRATION_NO_IN_PROGRESS;
}

/**
 * \brief System calibration osc enable
 *
 * Use this function to able system calibration osc.
 */
void system_osc_calibration_enable(void)
{
    LP_CLK_CAL_REGS0->CONFIG_REG.reg |= \
        LP_CLK_CAL_REGS_CONFIG_REG_START_OSC_CALIB;
}

/**
 * \brief System calibration osc disable
 *
 * Use this function to disable system calibration osc.
 */
void system_osc_calibration_disable(void)
{
    LP_CLK_CAL_REGS0->CONFIG_REG.reg &= \
        ~LP_CLK_CAL_REGS_CONFIG_REG_START_OSC_CALIB;
}

/**
 * \brief System calibration osc get status
 *
 * Use this function to get system calibration osc status.
 *
 * \param[in]  config    Point to struct system_calibration_config
 *
 * \return Status of operation.
 * \retval CALBRATION_NO_IN_PROGRESS     No calibration in progress
 * \retval CALBRATION_IN_PROGRESS        Calibration in progress
 * \retval CALBRATION_DONE               Calibration done
 */
enum system_calibration_status system_osc_calibration_get_status(void)
{
    if (LP_CLK_CAL_REGS0->CALIB_OSC_COUNT_REG.bit.NO_CAL_IN_PROGRESS) {
        return CALBRATION_NO_IN_PROGRESS;
    } else if (LP_CLK_CAL_REGS0->CALIB_OSC_COUNT_REG.bit.CAL_DONE) {
        return CALBRATION_DONE;
    } else {
        return CALBRATION_IN_PROGRESS;
    }
}

/**
 * \brief System calibration osc clear status
 *
 * Use this function to clear system calibration osc status.
 */
void system_osc_calibration_clear_status(void)
{
    //LP_CLK_CAL_REGS0->CALIB_OSC_COUNT_REG.reg = 0x01;
}

/**
 * \brief System calibration osc get results
 *
 * Use this function to get system calibration osc results.
 *
 * \param[in,out]  config    Point to struct system_calibration_config
 */
void system_osc_calibration_result(struct system_calibration_config *config)
{
    config->osc_fractional_part = LP_CLK_CAL_REGS0->CALIB_OSC_COUNT_REG.bit.CAL_FRAC_COUNT;
    config->osc_integer_part = LP_CLK_CAL_REGS0->CALIB_OSC_COUNT_REG.bit.CAL_INT_COUNT;
}

/**
 * \brief System calibration rtc enable
 *
 * Use this function to able system calibration rtc.
 */
void system_rtc_calibration_enable(void)
{
    LP_CLK_CAL_REGS0->CONFIG_REG.reg |= \
        LP_CLK_CAL_REGS_CONFIG_REG_START_RTC_CALIB;
}

/**
 * \brief System calibration rtc disable
 *
 * Use this function to disable system calibration rtc.
 */
void system_rtc_calibration_disable(void)
{
    LP_CLK_CAL_REGS0->CONFIG_REG.reg &= \
        ~LP_CLK_CAL_REGS_CONFIG_REG_START_RTC_CALIB;
}

/**
 * \brief System calibration rtc get status
 *
 * Use this function to get system calibration rtc status.
 *
 * \param[in]  config    Point to struct system_calibration_config
 *
 * \return Status of operation.
 * \retval CALBRATION_NO_IN_PROGRESS     No calibration in progress
 * \retval CALBRATION_IN_PROGRESS        Calibration in progress
 * \retval CALBRATION_DONE               Calibration done
 */
enum system_calibration_status system_rtc_calibration_get_status(void)
{
    if (LP_CLK_CAL_REGS0->CALIB_RTC_COUNT_REG.bit.NO_CAL_IN_PROGRESS) {
        return CALBRATION_NO_IN_PROGRESS;
    } else if (LP_CLK_CAL_REGS0->CALIB_RTC_COUNT_REG.bit.CAL_DONE) {
        return CALBRATION_DONE;
    } else {
        return CALBRATION_IN_PROGRESS;
    }
}

/**
 * \brief System calibration rtc clear status
 *
 * Use this function to clear system calibration rtc status.
 */
void system_rtc_calibration_clear_status(void)
{
    //LP_CLK_CAL_REGS0->CALIB_RTC_COUNT_REG.reg = 0x01;
}

/**
 * \brief System calibration rtc get results
 *
 * Use this function to get system calibration rtc results.
 *
 * \param[in,out]  config    Point to struct system_calibration_config
 */
void system_rtc_calibration_result(struct system_calibration_config *config)
{
    config->rtc_fractional_part = LP_CLK_CAL_REGS0->CALIB_RTC_COUNT_REG.bit.CAL_FRAC_COUNT;
    config->rtc_integer_part = LP_CLK_CAL_REGS0->CALIB_RTC_COUNT_REG.bit.CAL_INT_COUNT;
}

/**
 * \brief System clock aon config
 *
 * Use this function to config system clock aon.
 *
 * \param[in]  peripheral_aon  Selection system peripheral aon
 * \param[in]  aon_resource    Selection system clock aon resource
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_aon_config( \
        enum system_peripheral_aon peripheral_aon, \
        enum system_clock_aon_resource aon_resource)
{
    switch (peripheral_aon) {
        case PERIPHERAL_AON_SLEEP_TIMER:
            if (aon_resource == CLOCK_AON_RESOURCE_31_25_KHZ) {
                    AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                        AON_GP_REGS_AON_MISC_CTRL_USE_RTC_32KHZ_CLK_SLEEP_TIMER;
                    AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                        ~AON_GP_REGS_AON_MISC_CTRL_USE_EXT_32KHZ_CLK_SLEEP_TIMER;
            } else if (aon_resource == CLOCK_AON_RESOURCE_32_768_KHZ) {
                    AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                        ~AON_GP_REGS_AON_MISC_CTRL_USE_RTC_32KHZ_CLK_SLEEP_TIMER;
                    AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                        AON_GP_REGS_AON_MISC_CTRL_USE_EXT_32KHZ_CLK_SLEEP_TIMER;
            } else if (aon_resource == CLOCK_AON_DEFAULT) {
                    AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                        ~AON_GP_REGS_AON_MISC_CTRL_USE_RTC_32KHZ_CLK_SLEEP_TIMER;
                    AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                        ~AON_GP_REGS_AON_MISC_CTRL_USE_EXT_32KHZ_CLK_SLEEP_TIMER;
            }
        break;

        case PERIPHERAL_AON_POWER_SEQUENCER:
            if (aon_resource == CLOCK_AON_RESOURCE_2_MHZ) {
                AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                    AON_GP_REGS_AON_MISC_CTRL_USE_RTC_AON_PWR_SEQ_CLK;
                AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                    AON_GP_REGS_AON_MISC_CTRL_USE_2M_AON_PWR_SEQ_CLK;
            } else if (aon_resource == CLOCK_AON_DEFAULT) {
                AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                    ~AON_GP_REGS_AON_MISC_CTRL_USE_RTC_AON_PWR_SEQ_CLK;
                AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                    ~AON_GP_REGS_AON_MISC_CTRL_USE_2M_AON_PWR_SEQ_CLK;
            }
        break;

        case PERIPHERAL_AON_PD:
            if (aon_resource == CLOCK_AON_RESOURCE_2_MHZ) {
                AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                    AON_GP_REGS_AON_MISC_CTRL_USE_OSC2M_AS_TB_CLK;
            } else if (aon_resource == CLOCK_AON_DEFAULT) {
                AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                    ~AON_GP_REGS_AON_MISC_CTRL_USE_OSC2M_AS_TB_CLK;
            }

        default:
            return STATUS_ERR_INVALID_ARG;
    }
    return STATUS_OK;
}

/**
 * \brief System clock peripheral aon enable
 *
 * Use this function to enable system clock peripheral aon.
 *
 * \param[in]  peripheral_aon    Selection peripheral
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_peripheral_aon_enable(enum system_peripheral_aon peripheral_aon)
{
    switch (peripheral_aon) {
        case PERIPHERAL_AON_SLEEP_TIMER:
            AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                AON_GP_REGS_AON_MISC_CTRL_AON_SLEEP_TIMER_CLK_EN;
        break;

        case PERIPHERAL_AON_PD:
            AON_GP_REGS0->AON_MISC_CTRL.reg |= \
                AON_GP_REGS_AON_MISC_CTRL_AON_EXT_32KHZ_OUT_EN;
        break;

        default:
            return STATUS_ERR_INVALID_ARG;
    }
    return STATUS_OK;
}

/**
 * \brief System clock peripheral aon disable
 *
 * Use this function to enable system clock peripheral aon.
 *
 * \param[in]  peripheral_aon    Selection peripheral
 *
 * \return Status of operation.
 * \retval STATUS_OK               Clock config correctly
 * \retval STATUS_ERR_INVALID_ARG  If data is invalid
 */
enum status_code system_clock_peripheral_aon_disable(enum system_peripheral_aon peripheral_aon)
{
    switch (peripheral_aon) {
        case PERIPHERAL_AON_SLEEP_TIMER:
            AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                ~AON_GP_REGS_AON_MISC_CTRL_AON_SLEEP_TIMER_CLK_EN;
        break;

        case PERIPHERAL_AON_PD:
            AON_GP_REGS0->AON_MISC_CTRL.reg &= \
                ~AON_GP_REGS_AON_MISC_CTRL_AON_EXT_32KHZ_OUT_EN;
        break;

        default:
            return STATUS_ERR_INVALID_ARG;
    }
    return STATUS_OK;
}
