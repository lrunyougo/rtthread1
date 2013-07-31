/*
 * File      : drv_uart.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2013, RT-Thread Develop Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://openlab.rt-thread.com/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-07-11     reynolds     port to TWR-K60F120M
 */


#include "drv_uart.h"

static struct rt_serial_device _k60_serial;  /* abstracted serial for RTT */
static struct serial_ringbuffer _k60_int_rx; /* UART send buffer area     */

void rt_hw_FIFO_init(struct rt_serial_device *serial);
void rt_hw_FIFO_deinit(struct rt_serial_device *serial);

struct k60_serial_device
{
    /* UART base address */
    UART_Type *baseAddress;

    /* UART IRQ Number */
    int irq_num;

    /* device config */
    struct serial_configure config;
};

/* hardware abstract device */
static struct k60_serial_device _k60_node =
{
    (UART_Type *)UART5,
    k60_uasrt_irq_num,
};

static rt_err_t _configure(struct rt_serial_device *serial, struct serial_configure *cfg)
{
    unsigned int reg_C1 = 0,reg_C3 = 0,reg_C4 = 0,reg_BDH = 0,reg_BDL = 0,reg_S2,reg_BRFA=0;
    unsigned int cal_SBR = 0;
    UART_Type *uart_reg;

    /* ref : drivers\system_MK60F12.c Line 64 ,BusClock = 60MHz
     * calculate baud_rate
     * NOTE :
     * UART0 and UART1 are clocked from the core clock, the remaining UARTs are
     * clocked on the bus clock. The maximum baud rate is 1/16 of related source clock
     * frequency.
     */
    uart_reg = ((struct k60_serial_device *)serial->parent.user_data)->baseAddress;

    /* calc SBR */
    cal_SBR = 60000000 / (16 * cfg->baud_rate);

    /* calc baud_rate */
    reg_BDH = (cal_SBR & 0x1FFF) >> 8 & 0x00FF;
    reg_BDL = cal_SBR & 0x00FF;

    /* fractional divider */
    reg_BRFA = ((60000*32000)/(cfg->baud_rate * 16)) - (cal_SBR * 32);

    reg_C4 = (unsigned char)(reg_BRFA & 0x001F);

    /*
     * set bit order
     */
    if (cfg->bit_order == BIT_ORDER_LSB)
        reg_S2 &= ~(UART_S2_MSBF_MASK << UART_S2_MSBF_SHIFT);
    else if (cfg->bit_order == BIT_ORDER_MSB)
        reg_S2 |= UART_S2_MSBF_MASK << UART_S2_MSBF_SHIFT;

    /*
     * set data_bits
     */
    if (cfg->data_bits == DATA_BITS_8)
        reg_C1 &= ~(UART_C1_M_MASK << UART_C1_M_SHIFT);
    else if (cfg->data_bits == DATA_BITS_9)
        reg_C1 |= UART_C1_M_MASK << UART_C1_M_SHIFT;

    /*
     * set parity
     */
    if (cfg->parity == PARITY_NONE)
    {
        reg_C1 &= ~(UART_C1_PE_MASK);
    }
    else
    {
        /* first ,set parity enable bit */
        reg_C1 |= (UART_C1_PE_MASK);
        
        /* second ,determine parity odd or even*/
        if (cfg->parity == PARITY_ODD)
            reg_C1 |= UART_C1_PT_MASK;
        if (cfg->parity == PARITY_EVEN)
            reg_C1 &= ~(UART_C1_PT_MASK);
    }

    /*
     * set stop bit
     * not supported on Tower? need ur help!
     */

    /*
     * set NZR mode
     * not tested
     */
    if (cfg->invert != NRZ_NORMAL)
    {
        /* not in normal mode ,set inverted polarity */
        reg_C3 |= UART_C3_TXINV_MASK;
    }

    switch( (int)uart_reg)
    {
    /* Tower board use UART5 for communication
     * if you're using other board
     * set clock and pin map for UARTx
     */
    case UART5_BASE:

        /* set UART5 clock    */
        SIM->SCGC1 |= SIM_SCGC1_UART5_MASK;/* Enable UART gate clocking     */
        SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;/* Enable PORTE gate clocking    */

        /* set UART5 pin    */
        PORTE->PCR[ 8] = (3UL <<  8);      /* Pin mux configured as ALT3    */
        PORTE->PCR[ 9] = (3UL <<  8);      /* Pin mux configured as ALT3    */
        break;
    default:
        break;
    }

    rt_hw_FIFO_init(serial);

    uart_reg->BDH = reg_BDH;
    uart_reg->BDL = reg_BDL;
    uart_reg->C1 = reg_C1;
    uart_reg->C4 = reg_C4;
    uart_reg->S2 = reg_S2;

    uart_reg->S2  =  0;
    uart_reg->C3  =  0;

    uart_reg->RWFIFO = UART_RWFIFO_RXWATER(1);
    uart_reg->TWFIFO = UART_TWFIFO_TXWATER(0);


    return RT_EOK;
}

static rt_err_t _control(struct rt_serial_device *serial, int cmd, void *arg)
{
    UART_Type *uart_reg;
    int uart_irq_num = 0;

    uart_reg = ((struct k60_serial_device *)serial->parent.user_data)->baseAddress;
    uart_irq_num = ((struct k60_serial_device *)serial->parent.user_data)->irq_num;

    switch (cmd)
    {
    case RT_DEVICE_CTRL_CLR_INT:
        /* only disable INT_EN ,NVIC should be set by RT_DEVICE_CTRL_SUSPEND */        
        if ( (int)arg & RT_DEVICE_FLAG_INT_RX )
        {
            /* disable rx irq */
            uart_reg->C2 &= ~UART_C2_RIE_MASK;
        }
        break;
    case RT_DEVICE_CTRL_SET_INT:
        /* only enable INT_EN ,NVIC should be set by resume */
        if ( (int)arg & RT_DEVICE_FLAG_INT_RX )
        {
            /* enable rx irq */
            uart_reg->C2 |= UART_C2_RIE_MASK;
        }
        break;
    case RT_DEVICE_CTRL_SUSPEND:
        if ( (int)arg & (RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_INT_RX) )
        {
            /* disable NVIC */
            NVICICER1 |= 1 << (uart_irq_num % 32);
        }
    
        
        /* suspend device */
        uart_reg->C2  &=  ~(UART_C2_RE_MASK |
                            UART_C2_TE_MASK);

        rt_hw_FIFO_deinit(serial);
        break;
    case RT_DEVICE_CTRL_RESUME:
        /* resume device */
        rt_hw_FIFO_init(serial);

        if ( (int)arg & (RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_INT_TX) )
        {
            /* enable NVIC,we are sure uart's NVIC vector is in NVICICPR1 */
            NVICICPR1 |= 1 << (uart_irq_num % 32);
            NVICISER1 |= 1 << (uart_irq_num % 32);

        }
        
        /* configure done now start device */
        uart_reg->C2  |=  UART_C2_RE_MASK |
                          UART_C2_TE_MASK;
        break;
    }

    return RT_EOK;
}

static int _putc(struct rt_serial_device *serial, char c)
{
    UART_Type *uart_reg;
    uart_reg = ((struct k60_serial_device *)serial->parent.user_data)->baseAddress;

#ifdef USE_UART_TX_FIFO
    /* if we use fifo ,we'll wait fifo has enough space to put one DataWord(char c) */
    while ( !(UART_FIFO_TX_ENTRY - uart_reg->TCFIFO > 0));
#else
    /* without fifo ,we'll check whether D reg is empty for new transmit */
    while (!(uart_reg->S1 & UART_S1_TDRE_MASK));
#endif
    uart_reg->D = (c & 0xFF);
    
    
    return 1;
}

static int _getc(struct rt_serial_device *serial)
{
    UART_Type *uart_reg;
    uart_reg = ((struct k60_serial_device *)serial->parent.user_data)->baseAddress;

    if (uart_reg->S1 & UART_S1_RDRF_MASK)
        return (uart_reg->D);
    else
        return -1;
}

static const struct rt_uart_ops _k60_ops =
{
    _configure,
    _control,
    _putc,
    _getc,
};


void UART5_RX_TX_IRQHandler(void)
{
    rt_hw_serial_isr((struct rt_serial_device*)&_k60_serial);
}


void rt_hw_uart_init(void)
{
    struct serial_configure config;

    /* fake configuration */
    config.baud_rate = BAUD_RATE_115200;
    config.bit_order = BIT_ORDER_LSB;
    config.data_bits = DATA_BITS_8;
    config.parity    = PARITY_NONE;
    config.stop_bits = STOP_BITS_1;
    config.invert    = NRZ_NORMAL;

    _k60_serial.ops    = &_k60_ops;
    _k60_serial.int_rx = &_k60_int_rx;
    _k60_serial.config = config;

    rt_hw_serial_register(&_k60_serial, "uart5",
                          RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_STREAM,
                          (void*)&_k60_node);
}

void rt_hw_console_output(const char *str)
{
    while(*str != '\0')
    {
        if (*str == '\n')
            _putc(&_k60_serial,'\r');
        _putc(&_k60_serial,*str);
        str++;
    }
}

void rt_hw_FIFO_init(struct rt_serial_device *serial)
{
    UART_Type *uart_reg;
    uart_reg = ((struct k60_serial_device *)serial->parent.user_data)->baseAddress;

#ifdef USE_UART_TX_FIFO
    /* clear TE and RE to set PFIFO
     * TE and RE is ensured by other method
     * to make sure TE & RE not set
     */
    uart_reg->C2  &=  ~(UART_C2_RE_MASK | UART_C2_TE_MASK);

    /* flush TX FIFO */
    uart_reg->CFIFO = UART_CFIFO_TXFLUSH_MASK;

    /* set PFIFO to enable TX FIFO*/
    uart_reg->PFIFO |= UART_PFIFO_TXFE_MASK ;

    /* set TX FIFO watermark
     * at most ,less than FIFO entry
     */
    uart_reg->TWFIFO = UART_FIFO_TX_WATERMARK;
#endif

#ifdef USE_UART_RX_FIFO
    /* RX fifo init */
#endif
}

void rt_hw_FIFO_deinit(struct rt_serial_device *serial)
{
    UART_Type *uart_reg;
    uart_reg = ((struct k60_serial_device *)serial->parent.user_data)->baseAddress;

#ifdef USE_UART_TX_FIFO
    /* clear TE and RE to set PFIFO
     * TE and RE is ensured by other method
     * to make sure TE & RE not set
     */
    uart_reg->C2  &=  ~(UART_C2_RE_MASK | UART_C2_TE_MASK);

    /* flush TX FIFO */
    uart_reg->CFIFO = UART_CFIFO_TXFLUSH_MASK;

    /* set PFIFO to enable TX FIFO*/
    uart_reg->PFIFO &= ~(UART_PFIFO_TXFE_MASK);
#endif

#ifdef USE_UART_RX_FIFO
    /* RX fifo deinit */
#endif
}
