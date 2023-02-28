/* Copyright (c) 2019-2025 Allwinner Technology Co., Ltd. ALL rights reserved.

 * Allwinner is a trademark of Allwinner Technology Co.,Ltd., registered in
 * the the People's Republic of China and other countries.
 * All Allwinner Technology Co.,Ltd. trademarks are used with permission.

 * DISCLAIMER
 * THIRD PARTY LICENCES MAY BE REQUIRED TO IMPLEMENT THE SOLUTION/PRODUCT.
 * IF YOU NEED TO INTEGRATE THIRD PARTY¡¯S TECHNOLOGY (SONY, DTS, DOLBY, AVS OR MPEGLA, ETC.)
 * IN ALLWINNERS¡¯SDK OR PRODUCTS, YOU SHALL BE SOLELY RESPONSIBLE TO OBTAIN
 * ALL APPROPRIATELY REQUIRED THIRD PARTY LICENCES.
 * ALLWINNER SHALL HAVE NO WARRANTY, INDEMNITY OR OTHER OBLIGATIONS WITH RESPECT TO MATTERS
 * COVERED UNDER ANY REQUIRED THIRD PARTY LICENSE.
 * YOU ARE SOLELY RESPONSIBLE FOR YOUR USAGE OF THIRD PARTY¡¯S TECHNOLOGY.


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

#ifndef __RTC_SUN50IW11_H__
#define __RTC_SUN50IW11_H__

#define BIT(nr)     (1UL << (nr))

/* config for DSP */
#if defined(CONFIG_CORE_DSP0)
#define SUNXI_RTC_BASE      (0x07090000)
#define SUNXI_RTC_DATA_BASE (SUNXI_RTC_BASE + 0x100)

#define RTC_DM_REG0 (SUNXI_RTC_BASE + (0x4 * 0))
#define RTC_DM_REG1 (SUNXI_RTC_BASE + (0x4 * 1))
#define RTC_DM_REG2 (SUNXI_RTC_BASE + (0x4 * 2))
#define RTC_DM_REG3 (SUNXI_RTC_BASE + (0x4 * 3))
#define RTC_DM_REG4 (SUNXI_RTC_BASE + (0x4 * 4))
#define RTC_DM_REG5 (SUNXI_RTC_BASE + (0x4 * 5))
#define RTC_DM_REG6 (SUNXI_RTC_BASE + (0x4 * 6))
/* rtc domain record reg */
#define RTC_RECORD_REG   (RTC_DM_REG3)
#define START_OS_REG     (RTC_DM_REG2)
#endif /* CONFIG_CORE_DSP0 */

#endif /* __RTC-SUN50IW11_H__ */
