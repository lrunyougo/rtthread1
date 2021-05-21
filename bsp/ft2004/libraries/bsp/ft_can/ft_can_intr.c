/*
 * @[H]: Copyright (C) 2014-2021 Phytium Technology.  All rights reserved.
 * 
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 * 
 *  Use of the Software is limited solely to applications:
 *  (a) running on a Phytium device, or
 *  (b) that interact with a Phytium device through a bus or interconnect.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  PHYTIUM  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 *  OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 * 
 *  Except as contained in this notice, the name of the Phytium shall not be used
 *  in advertising or otherwise to promote the sale, use or other dealings in
 *  this Software without prior written authorization from Phytium. 
 * 
 * @Date: 2021-04-29 10:40:47
 * @LastEditTime: 2021-04-29 10:40:47
 * @Description:  Description of file
 * @Modify History: 
 * * * Ver   Who        Date         Changes
 * * ----- ------     --------    --------------------------------------
 */

#include "ft_can.h"
#include "ft_can_hw.h"
#include "ft_assert.h"
#include "ft_types.h"

ft_error_t FCan_SetHandler(FCan_t *Can_p, u32 HandlerType, FCan_irqHandler_t IrqCallBackFunc, void *IrqCallBackRef)
{
    ft_error_t status = FCAN_SUCCESS;
    Ft_assertNonvoid(Can_p != NULL);
    Ft_assertNonvoid(Can_p->IsReady == FT_COMPONENT_IS_READLY);
    switch (HandlerType)
    {
    case FCAN_HANDLER_SEND:
        Can_p->SendHandler = IrqCallBackFunc;
        Can_p->SendRef = IrqCallBackRef;
        break;
    case FCAN_HANDLER_RECV:
        Can_p->RecvHandler = IrqCallBackFunc;
        Can_p->RecvRef = IrqCallBackRef;
        break;
    case FCAN_HANDLER_ERROR:
        Can_p->ErrorHandler = IrqCallBackFunc;
        Can_p->ErrorRef = IrqCallBackRef;
        break;
    default:
        status = FCAN_FAILURE;
    }

    return status;
}

static void FCan_TxInterrupt(FCan_t *Can_p)
{
    FCan_Config_t *Config_p = &Can_p->Config;
    FCan_SetBit(Config_p->CanBaseAddress, FCAN_INTR_OFFSET, FCAN_INTR_TEIC_MASK | FCAN_INTR_REIC_MASK);

    if (0 != Can_p->TxFifoCnt)
    {
        Can_p->TxFifoCnt--;
        FCan_ClearBit(Config_p->CanBaseAddress, FCAN_CTRL_OFFSET, FCAN_CTRL_XFER_MASK);
        FCan_SetBit(Config_p->CanBaseAddress, FCAN_CTRL_OFFSET, FCAN_CTRL_TXREQ_MASK);
        FCan_SetBit(Config_p->CanBaseAddress, FCAN_CTRL_OFFSET, FCAN_CTRL_XFER_MASK);
    }
    else
    {
        if (Can_p->SendHandler)
        {
            Can_p->SendHandler(Can_p->SendRef);
        }
    }
}

static void FCan_ErrorInterrupt(FCan_t *Can_p)
{
    if (Can_p->ErrorHandler)
    {
        Can_p->ErrorHandler(Can_p->ErrorRef);
    }
}

static void FCan_RxInterrupt(FCan_t *Can_p)
{
    if (Can_p->RecvHandler)
    {
        Can_p->RecvHandler(Can_p->RecvRef);
    }
}

void FCan_IntrHandler(void *InstancePtr)
{
    u32 Irq;
    FCan_t *Can_p = (FCan_t *)InstancePtr;
    FCan_Config_t *Config_p;
    Ft_assertVoid(Can_p != NULL);
    Ft_assertVoid(Can_p->IsReady == FT_COMPONENT_IS_READLY);
    Config_p = &Can_p->Config;
    Irq = FCan_ReadReg(Config_p->CanBaseAddress, FCAN_INTR_OFFSET);

    if (0 == Irq)
    {
        return;
    }

    /* Check for the type of error interrupt and Processing it */
    if (Irq & FCAN_INTR_TEIS_MASK)
    {
        Irq &= ~FCAN_INTR_REIS_MASK;
        FCan_TxInterrupt(Can_p);
    }

    if (Irq & (FCAN_INTR_EIS_MASK | FCAN_INTR_RFIS_MASK |
               FCAN_INTR_BOIS_MASK | FCAN_INTR_PEIS_MASK | FCAN_INTR_PWIS_MASK))
    {
        FCan_SetBit(Config_p->CanBaseAddress, FCAN_INTR_OFFSET, (FCAN_INTR_EIC_MASK | FCAN_INTR_RFIC_MASK | FCAN_INTR_BOIC_MASK | FCAN_INTR_PEIC_MASK | FCAN_INTR_PWIC_MASK));
        FCan_ErrorInterrupt(Can_p);
    }

    if (Irq & FCAN_INTR_REIS_MASK)
    {
        FCan_SetBit(Config_p->CanBaseAddress, FCAN_INTR_OFFSET, FCAN_INTR_REIE_MASK);
        FCan_RxInterrupt(Can_p);
        FCan_SetBit(Config_p->CanBaseAddress, FCAN_INTR_OFFSET, FCAN_INTR_REIC_MASK);
        FCan_SetBit(Config_p->CanBaseAddress, FCAN_INTR_OFFSET, FCAN_INTR_REIE_MASK);
    }
}