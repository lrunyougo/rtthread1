/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-09-09     WCH        the first version
 */
#include "board.h"
#include <rtdevice.h>
#include <drv_usart.h>
#include "hal_udma_ctrl_reg_defs.h"
#include "hal_udma_uart_reg_defs.h"
#include "udma_uart_driver.h"
#include <string.h>
#include "core-v-mcu-config.h"
#ifdef RT_USING_SERIAL

//#define DRV_DEBUG
#define LOG_TAG              "drv.uart"
#include <drv_log.h>

#if !defined(BSP_USING_UART1) && !defined(BSP_USING_UART2) && !defined(BSP_USING_UART3) && !defined(BSP_USING_UART4) && \
    !defined(BSP_USING_UART5) && !defined(BSP_USING_UART6) && !defined(BSP_USING_UART7) && !defined(BSP_USING_UART8) 
    #error "Please define at least one BSP_USING_UARTx"
    /* this driver can be disabled at menuconfig -> RT-Thread Components -> Device Drivers */
#endif

extern char u1buffer[128], u0buffer[128];
extern  int u1rdptr, u1wrptr, u0rdptr,u0wrptr;
extern UdmaUart_t *puart0 ;
extern UdmaUart_t *puart1 ;

enum
{
    UART1_INDEX,
};

struct ch32_uart_config uart_config[1] =
{
   {
     "uart1"
   }
};

struct ch32_uart uart_obj[1] = {0};

static rt_err_t ch32_configure(struct rt_serial_device *serial, struct serial_configure *cfg)
{
     return RT_EOK;
}

static rt_err_t ch32_control(struct rt_serial_device *serial, int cmd, void *arg)
{
    return RT_EOK;
}

uint16_t rt_writeraw(uint8_t uart_id, uint16_t write_len, uint8_t* write_buffer) {
	UdmaUart_t*				puart = (UdmaUart_t*)(UDMA_CH_ADDR_UART + uart_id * UDMA_CH_SIZE);

	while (puart->status_b.tx_busy) {  // ToDo: Why is this necessary?  Thought the semaphore should have protected
	}

	puart->tx_saddr = (uint32_t)write_buffer;
	puart->tx_size = write_len;
	puart->tx_cfg_b.en = 1; //enable the transfer

	return 0;
}

//char put_data;
static int ch32_putc(struct rt_serial_device *serial, char c)
{
	char put_data =c;
    struct ch32_uart *uart;
    RT_ASSERT(serial != RT_NULL);
    uart = (struct ch32_uart *)serial->parent.user_data;
    rt_writeraw(0, 1,&put_data);
    return 1;
}

static int ch32_getc(struct rt_serial_device *serial)
{
    signed char ch;
    struct ch32_uart *uart;
    RT_ASSERT(serial != RT_NULL);
    uart = (struct ch32_uart *)serial->parent.user_data;
    ch = -1;
    //ch = udma_uart_getchar(0);

	UdmaUart_t*	puart = (UdmaUart_t*)(UDMA_CH_ADDR_UART + 0 * UDMA_CH_SIZE);

	if (puart->valid_b.rx_data_valid == 1) {
		ch = puart->data_b.rx_data & 0xff;
	}

    return (int)ch;
}

rt_size_t ch32dma_transmit(struct rt_serial_device *serial, rt_uint8_t *buf, rt_size_t size, int direction)
{
    return RT_EOK;
}

 void uart_isr(struct rt_serial_device *serial)
{
    struct ch32_uart *uart = (struct ch32_uart *) serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);
    rt_hw_serial_isr(serial, RT_SERIAL_EVENT_RX_IND);
}

static const struct rt_uart_ops ch32_uart_ops =
{
    ch32_configure,
    ch32_control,
    ch32_putc,
    ch32_getc,
    ch32dma_transmit
};
//extern struct rt_ringbuffer uart_rxTCB;
//extern struct rt_semaphore  shell_rx_semaphore;

void uart_rx_isr (void *id){
	rt_interrupt_enter();
	if (id == 6) {
		while (*(int*)0x1a102130) {
			u1buffer[u1wrptr++] = puart1->data_b.rx_data & 0xff;
			u1wrptr &= 0x7f;
		}
	}
	if (id == 2) {
		while (puart0->valid) {
			//u0buffer[u0wrptr++] = puart0->data_b.rx_data & 0xff;
			//u0wrptr &= 0x7f;
			//outdata(0,sizeof(u0buffer),u0buffer);
			//outdata(0,sizeof(n_data),n_data);
			//rt_ringbuffer_putchar(&uart_rxTCB,puart0->data_b.rx_data & 0xff);
			//u0wrptr=0;
			uart_isr(&(uart_obj[UART1_INDEX].serial));

		}
		//rt_sem_release(&shell_rx_semaphore);
	}
	rt_interrupt_leave();
}


int rt_hw_usart_init(void)
{
    rt_size_t obj_num = 1;
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;
    rt_err_t result = 0;

    for (int i = 0; i < obj_num; i++)
    {
        /* init UART object */
        uart_obj[i].config        = &uart_config[i];
        uart_obj[i].serial.ops    = &ch32_uart_ops;
        uart_obj[i].serial.config = config;

        /* register UART device */
        result = rt_hw_serial_register(&uart_obj[i].serial, uart_obj[i].config->name,
                                       RT_DEVICE_FLAG_RDWR
                                       | RT_DEVICE_FLAG_INT_RX
                                       ,&uart_obj[i]);
        RT_ASSERT(result == RT_EOK);
    }
    return result;
}

//INIT_APP_EXPORT(rt_hw_usart_init);

#endif /* RT_USING_SERIAL */

