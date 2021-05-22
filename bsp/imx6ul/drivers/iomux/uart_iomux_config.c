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

// File: uart_iomux_config.c

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
#include "registers/regsuart.h"
#include "iomux_register.h"
#include "io.h"
#include <assert.h>

#define MX6UL_PAD_UART1_TX_DATA__UART1_TX1	(IOMUXC_BASE_ADDR+0x084)
#define MX6UL_PAD_UART1_RX_DATA__UART1_RX1	(IOMUXC_BASE_ADDR+0x088)
#define IOMUXC_UART1_UART_RXD_MUX_SELECT_INPUT1 (IOMUXC_BASE_ADDR+0x624)

#define PIN_CFG(mux_ctl_offset, pad_ctl_offset, select_input_offset, mux_mode, daisy, pad_setting) \
	do {\
		writel(mux_mode, IOMUXC_BASE_ADDR + mux_ctl_offset);\
		if (select_input_offset != 0)\
			writel(daisy, IOMUXC_BASE_ADDR + select_input_offset);\
		writel(pad_setting, IOMUXC_BASE_ADDR + pad_ctl_offset);\
	} while(0);

#define MX6UL_PAD_UART1_TX_DATA__UART1_TX(p)                         PIN_CFG(0x0084, 0x0310, 0x0624, 0x0, 0x2, p)
#define MX6UL_PAD_UART1_RX_DATA__UART1_RX(p)                         PIN_CFG(0x0088, 0x0314, 0x0624, 0x0, 0x3, p)

void uart1_iomux_config(void)
{
    /* UART1 TXD */
    MX6UL_PAD_UART1_TX_DATA__UART1_TX(0x10b0);
    /* UART1 RXD */
    MX6UL_PAD_UART1_RX_DATA__UART1_RX(0x10b0);
}

void uart2_iomux_config(void)
{
}

void uart3_iomux_config(void)
{
}

void uart4_iomux_config(void)
{
}

void uart5_iomux_config(void)
{
}

void uart6_iomux_config(void)
{
}

void uart7_iomux_config(void)
{
}

void uart8_iomux_config(void)
{
}


void uart_iomux_config(int instance)
{
    switch (instance)
    {
        case HW_UART1:
            return uart1_iomux_config();

        case HW_UART2:
            return uart2_iomux_config();

        case HW_UART3:
            return uart3_iomux_config();

        case HW_UART4:
            return uart4_iomux_config();

        case HW_UART5:
            return uart5_iomux_config();

        case HW_UART6:
            return uart5_iomux_config();

        case HW_UART7:
            return uart5_iomux_config();       

        case HW_UART8:
            return uart5_iomux_config(); 
                             
        default:
            assert(false);
    }
}

