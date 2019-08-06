/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-01     tyustli      the first version
 *
 */

#include "board.h"
#include <rtthread.h>
#include <rtdevice.h>

#define DBG_TAG "drv_lcd_mcu"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

typedef struct
{
    rt_uint16_t lcd_cmd;
    rt_uint16_t lcd_data;
} lcd_typedef;

struct lcd_mcu_device
{
    struct rt_lcd_mcu  mcu;
    FMC_NORSRAM_TimingTypeDef FMC_ReadWriteTim;
    FMC_NORSRAM_TimingTypeDef FMC_WriteTim;
    SRAM_HandleTypeDef SRAM_Handler;
    lcd_typedef *lcd_addr;
};
static struct lcd_mcu_device mcu_device;

static rt_err_t _lcd_mcu_write_cmd(struct rt_lcd_mcu *device, void *cmd, rt_size_t len)
{
    rt_uint32_t *write_cmd;
    struct lcd_mcu_device *mcu_device;
    RT_ASSERT(device);

    mcu_device = (struct lcd_mcu_device *)device->parent.user_data;
    RT_ASSERT(mcu_device);

    write_cmd = (rt_uint32_t *)cmd;
    while(len--)
    {
        mcu_device->lcd_addr->lcd_cmd = *write_cmd++;
    }

    return RT_EOK;
}

static rt_err_t _lcd_mcu_write_data(struct rt_lcd_mcu *device, void *data, rt_size_t len)
{
    rt_uint32_t *write_data;
    struct lcd_mcu_device *mcu_device;
    RT_ASSERT(device);

    mcu_device = (struct lcd_mcu_device *)device->parent.user_data;
    RT_ASSERT(mcu_device);

    write_data = (rt_uint32_t *)data;
    while(len--)
    {
        mcu_device->lcd_addr->lcd_data = *write_data++;
    }

    return RT_EOK;
}

static rt_err_t _lcd_mcu_read_data(struct rt_lcd_mcu *device, rt_uint32_t read_reg, void *read_data)
{
    struct lcd_mcu_device *mcu_device;
    RT_ASSERT(device);

    mcu_device = (struct lcd_mcu_device *)device->parent.user_data;
    RT_ASSERT(mcu_device);

    *(rt_uint32_t *)read_data = mcu_device->lcd_addr->lcd_data;

    return RT_EOK;
}

static rt_err_t _lcd_mcu_write_reg(struct rt_lcd_mcu *device, rt_uint32_t write_reg, rt_uint32_t write_data)
{
    struct lcd_mcu_device *mcu_device;
    RT_ASSERT(device);

    mcu_device = (struct lcd_mcu_device *)device->parent.user_data;
    RT_ASSERT(mcu_device);

    mcu_device->lcd_addr->lcd_cmd = write_reg;
    mcu_device->lcd_addr->lcd_data = write_data;

    return RT_EOK;
}

static rt_err_t _lcd_mcu_config(struct rt_lcd_mcu *device, void *args)
{
    struct rt_lcd_mcu_config *config;
    struct lcd_mcu_device *mcu_device;

    RT_ASSERT(device != RT_NULL);
    RT_ASSERT(args != RT_NULL);

    mcu_device = (struct lcd_mcu_device *)device->parent.user_data;
    RT_ASSERT(mcu_device);
    config = (struct rt_lcd_mcu_config *)args;
    RT_ASSERT(config);
    
    mcu_device->lcd_addr = (lcd_typedef *)config->addr;
    mcu_device->SRAM_Handler.Instance = FMC_NORSRAM_DEVICE;
    mcu_device->SRAM_Handler.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
    mcu_device->SRAM_Handler.Init.NSBank = config->channel;
    mcu_device->SRAM_Handler.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
    mcu_device->SRAM_Handler.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
    mcu_device->SRAM_Handler.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
    mcu_device->SRAM_Handler.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
    mcu_device->SRAM_Handler.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
    mcu_device->SRAM_Handler.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
    mcu_device->SRAM_Handler.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
    mcu_device->SRAM_Handler.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
    mcu_device->SRAM_Handler.Init.ExtendedMode = FMC_EXTENDED_MODE_ENABLE;
    mcu_device->SRAM_Handler.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
    mcu_device->SRAM_Handler.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
    mcu_device->SRAM_Handler.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ASYNC;

    mcu_device->FMC_ReadWriteTim.AddressSetupTime = 0x0F;
    mcu_device->FMC_ReadWriteTim.AddressHoldTime = 0x00;
    mcu_device->FMC_ReadWriteTim.DataSetupTime = 0x46;
    mcu_device->FMC_ReadWriteTim.AccessMode = FMC_ACCESS_MODE_A;

    mcu_device->FMC_WriteTim.AddressSetupTime = 0x0F;
    mcu_device->FMC_WriteTim.AddressHoldTime = 0x00;
    mcu_device->FMC_WriteTim.DataSetupTime = 0x0F;
    mcu_device->FMC_WriteTim.AccessMode = FMC_ACCESS_MODE_A;
    HAL_SRAM_Init(&mcu_device->SRAM_Handler, &mcu_device->FMC_ReadWriteTim, &mcu_device->FMC_WriteTim);
    rt_thread_mdelay(50);
    FMC_Bank1E->BWTR[0] &= ~(0XF << 0);
    FMC_Bank1E->BWTR[0] &= ~(0XF << 8);
    FMC_Bank1E->BWTR[0] |= 4 << 0;
    FMC_Bank1E->BWTR[0] |= 4 << 8;

    return RT_EOK;
}

static struct rt_lcd_mcu_ops _lcd_mcu_ops =
{
    _lcd_mcu_write_cmd,
    _lcd_mcu_write_data,
    _lcd_mcu_read_data,
    _lcd_mcu_write_reg,
    _lcd_mcu_config,
};

int rt_lcd_mcu_init(void)
{
    rt_err_t result;

    result = RT_EOK;
    result = rt_lcd_mcu_register(&mcu_device.mcu, "lcd_mcu", &_lcd_mcu_ops, &mcu_device);
    if (result != RT_EOK)
    {
        LOG_E("register lcd interface device failed error code = %d\n", result);
    }

    return result;
}

INIT_PREV_EXPORT(rt_lcd_mcu_init);

/****************** end of file *******************/

