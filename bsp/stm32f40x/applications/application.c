/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 */

/**
 * @addtogroup STM32
 */
/*@{*/

#include <stdio.h>

#include "stm32f4xx.h"
#include <board.h>
#include <rtthread.h>

#ifdef RT_USING_LWIP
#include <lwip/sys.h>
#include <lwip/api.h>
#include <netif/ethernetif.h>
#include "stm32_eth.h"
#endif

void rt_init_thread_entry(void* parameter)
{
    /* LwIP Initialization */
#ifdef RT_USING_LWIP
    {
        extern void lwip_sys_init(void);

        /* register ethernetif device */
        eth_system_device_init();

        rt_hw_stm32_eth_init();
        /* re-init device driver */
        rt_device_init_all();

        /* init lwip system */
        lwip_sys_init();
        rt_kprintf("TCP/IP initialized!\n");
    }
#endif

//FS

//GUI
}

ALIGN(RT_ALIGN_SIZE)
static char thread_led_stack[1024];
struct rt_thread thread_led;
static void rt_thread_entry_led(void* parameter)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    /* GPIOD Periph clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    
    
    /* Blink LED forever */
    while (1)
    {
        rt_kprintf("thread_led is running\n");
        /* PD12 to be toggled */
        GPIO_SetBits(GPIOD, GPIO_Pin_12);

        /* Insert delay */
        rt_thread_delay(RT_TICK_PER_SECOND/2);

        /* PD13 to be toggled */
        GPIO_SetBits(GPIOD, GPIO_Pin_13);

        /* Insert delay */
        rt_thread_delay(RT_TICK_PER_SECOND/2);

        /* PD14 to be toggled */
        GPIO_SetBits(GPIOD, GPIO_Pin_14);

        /* Insert delay */
        rt_thread_delay(RT_TICK_PER_SECOND/2);

        /* PD15 to be toggled */
        GPIO_SetBits(GPIOD, GPIO_Pin_15);

        /* Insert delay */
        rt_thread_delay(RT_TICK_PER_SECOND*2);

        GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);

        /* Insert delay */
        rt_thread_delay(RT_TICK_PER_SECOND);

    }
}


<<<<<<< HEAD
=======
ALIGN(RT_ALIGN_SIZE)
static char thread_usart_stack[1024];
struct rt_thread thread_usart;
static void rt_thread_entry_usart(void* parameter)
{
    float f_var_me;

    char str_buffer[256];
    while(1)
    {
        f_var_me = f_var1 * f_var2 + f_var3;
        sprintf(str_buffer, "%f", f_var_me);
        rt_kprintf("thread1 %s\r\n", str_buffer);
        rt_thread_delay(RT_TICK_PER_SECOND);
    }
}
>>>>>>> 3910d6d5a9aba3572abaa2934a9f424fbeaf1c3c

int rt_application_init()
{
    rt_thread_t init_thread;

#if (RT_THREAD_PRIORITY_MAX == 32)
    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   2048, 8, 20);
#else
    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   2048, 80, 20);
#endif

    if (init_thread != RT_NULL)
        rt_thread_startup(init_thread);

<<<<<<< HEAD
    //------- init led thread
    rt_thread_init(&thread_led,
                   "led",
                   rt_thread_entry_led,
                   RT_NULL,
                   &thread_led_stack[0],
                   sizeof(thread_led_stack),11,5);
    rt_thread_startup(&thread_led);

=======
    //------- init led1 thread
    rt_thread_init(&thread_led,
                   "led",
                   rt_thread_entry_led,
                   RT_NULL,
                   &thread_led_stack[0],
                   sizeof(thread_led_stack),11,5);
    rt_thread_startup(&thread_led);

    //------- init led2 thread
    rt_thread_init(&thread_usart,
                   "usart",
                   rt_thread_entry_usart,
                   RT_NULL,
                   &thread_usart_stack[0],
                   sizeof(thread_usart_stack),11,5);
    rt_thread_startup(&thread_usart);
>>>>>>> 3910d6d5a9aba3572abaa2934a9f424fbeaf1c3c

    return 0;
}

/*@}*/
