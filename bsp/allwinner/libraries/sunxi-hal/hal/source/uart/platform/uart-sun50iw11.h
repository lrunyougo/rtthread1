/*
* Copyright (c) 2019-2025 Allwinner Technology Co., Ltd. ALL rights reserved.
*
* Allwinner is a trademark of Allwinner Technology Co.,Ltd., registered in
* the the People's Republic of China and other countries.
* All Allwinner Technology Co.,Ltd. trademarks are used with permission.
*
* DISCLAIMER
* THIRD PARTY LICENCES MAY BE REQUIRED TO IMPLEMENT THE SOLUTION/PRODUCT.
* IF YOU NEED TO INTEGRATE THIRD PARTY'S TECHNOLOGY (SONY, DTS, DOLBY, AVS OR MPEGLA, ETC.)
* IN ALLWINNERS'SDK OR PRODUCTS, YOU SHALL BE SOLELY RESPONSIBLE TO OBTAIN
* ALL APPROPRIATELY REQUIRED THIRD PARTY LICENCES.
* ALLWINNER SHALL HAVE NO WARRANTY, INDEMNITY OR OTHER OBLIGATIONS WITH RESPECT TO MATTERS
* COVERED UNDER ANY REQUIRED THIRD PARTY LICENSE.
* YOU ARE SOLELY RESPONSIBLE FOR YOUR USAGE OF THIRD PARTY'S TECHNOLOGY.
*
*
* THIS SOFTWARE IS PROVIDED BY ALLWINNER"AS IS" AND TO THE MAXIMUM EXTENT
* PERMITTED BY LAW, ALLWINNER EXPRESSLY DISCLAIMS ALL WARRANTIES OF ANY KIND,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING WITHOUT LIMITATION REGARDING
* THE TITLE, NON-INFRINGEMENT, ACCURACY, CONDITION, COMPLETENESS, PERFORMANCE
* OR MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL ALLWINNER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS, OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __UART_SUN50IW11_H__
#define __UART_SUN50IW11_H__

/* config for DSP */
#if defined(CONFIG_CORE_DSP0)
#include <interrupt.h>
#include <hal_prcm.h>

#define SUNXI_IRQ_UART0     (RINTC_IRQ_MASK | 10)
/* not used */
#define SUNXI_IRQ_UART1     (0)
#define SUNXI_IRQ_UART2     (0)
#define SUNXI_IRQ_UART3     (0)

#define SUNXI_UART0_BASE    (0x07080000)
/* not used */
#define SUNXI_UART1_BASE    (0xffffffff)
#define SUNXI_UART2_BASE    (0xffffffff)
#define SUNXI_UART3_BASE    (0xffffffff)

#define UART_FIFO_SIZE      (64)

#define UART0_GPIO_FUNCTION (2)
#define UART1_GPIO_FUNCTION (2)
#define UART2_GPIO_FUNCTION (2)
#define UART3_GPIO_FUNCTION (2)

#define UART0_TX        GPIOL(8)
#define UART0_RX        GPIOL(9)
/* not used */
#define UART1_TX        GPIOL(8)
#define UART1_RX        GPIOL(9)
#define UART2_TX        GPIOL(8)
#define UART2_RX        GPIOL(9)
#define UART3_TX        GPIOL(8)
#define UART3_RX        GPIOL(9)

/* for prcm and ccmu compatibility */
#define HAL_CLK_PERIPH_UART0    CCU_MOD_CLK_R_UART
/* not used */
#define HAL_CLK_PERIPH_UART1    CCU_MOD_CLK_NONE
#define HAL_CLK_PERIPH_UART2    CCU_MOD_CLK_NONE
#define HAL_CLK_PERIPH_UART3    CCU_MOD_CLK_NONE
#endif /* CONFIG_CORE_DSP0 */

#endif /*__UART_SUN50IW11_H__  */
