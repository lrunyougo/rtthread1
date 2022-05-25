/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2015-01-20     Bernard      the first version
 * 2021-02-06     Meco Man     fix RT_ENOSYS code in negative
 * 2022-04-29     WangQiang    add pin operate command in MSH
 */

#include <drivers/pin.h>

#ifdef RT_USING_FINSH
#include <finsh.h>
#endif

static struct rt_device_pin _hw_pin;
static rt_size_t _pin_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    struct rt_device_pin_status *status;
    struct rt_device_pin *pin = (struct rt_device_pin *)dev;

    /* check parameters */
    RT_ASSERT(pin != RT_NULL);

    status = (struct rt_device_pin_status *)buffer;
    if (status == RT_NULL || size != sizeof(*status))
        return 0;

    status->status = pin->ops->pin_read(dev, status->pin);
    return size;
}

static rt_size_t _pin_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    struct rt_device_pin_status *status;
    struct rt_device_pin *pin = (struct rt_device_pin *)dev;

    /* check parameters */
    RT_ASSERT(pin != RT_NULL);

    status = (struct rt_device_pin_status *)buffer;
    if (status == RT_NULL || size != sizeof(*status))
        return 0;

    pin->ops->pin_write(dev, (rt_base_t)status->pin, (rt_base_t)status->status);

    return size;
}

static rt_err_t _pin_control(rt_device_t dev, int cmd, void *args)
{
    struct rt_device_pin_mode *mode;
    struct rt_device_pin *pin = (struct rt_device_pin *)dev;

    /* check parameters */
    RT_ASSERT(pin != RT_NULL);

    mode = (struct rt_device_pin_mode *)args;
    if (mode == RT_NULL)
        return -RT_ERROR;

    pin->ops->pin_mode(dev, (rt_base_t)mode->pin, (rt_base_t)mode->mode);

    return 0;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops pin_ops =
{
    RT_NULL,
    RT_NULL,
    RT_NULL,
    _pin_read,
    _pin_write,
    _pin_control
};
#endif

int rt_device_pin_register(const char *name, const struct rt_pin_ops *ops, void *user_data)
{
    _hw_pin.parent.type         = RT_Device_Class_Pin;
    _hw_pin.parent.rx_indicate  = RT_NULL;
    _hw_pin.parent.tx_complete  = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    _hw_pin.parent.ops          = &pin_ops;
#else
    _hw_pin.parent.init         = RT_NULL;
    _hw_pin.parent.open         = RT_NULL;
    _hw_pin.parent.close        = RT_NULL;
    _hw_pin.parent.read         = _pin_read;
    _hw_pin.parent.write        = _pin_write;
    _hw_pin.parent.control      = _pin_control;
#endif

    _hw_pin.ops                 = ops;
    _hw_pin.parent.user_data    = user_data;

    /* register a character device */
    rt_device_register(&_hw_pin.parent, name, RT_DEVICE_FLAG_RDWR);

    return 0;
}

rt_err_t rt_pin_attach_irq(rt_int32_t pin, rt_uint32_t mode,
                           void (*hdr)(void *args), void *args)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    if (_hw_pin.ops->pin_attach_irq)
    {
        return _hw_pin.ops->pin_attach_irq(&_hw_pin.parent, pin, mode, hdr, args);
    }
    return -RT_ENOSYS;
}

rt_err_t rt_pin_detach_irq(rt_int32_t pin)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    if (_hw_pin.ops->pin_detach_irq)
    {
        return _hw_pin.ops->pin_detach_irq(&_hw_pin.parent, pin);
    }
    return -RT_ENOSYS;
}

rt_err_t rt_pin_irq_enable(rt_base_t pin, rt_uint32_t enabled)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    if (_hw_pin.ops->pin_irq_enable)
    {
        return _hw_pin.ops->pin_irq_enable(&_hw_pin.parent, pin, enabled);
    }
    return -RT_ENOSYS;
}

/* RT-Thread Hardware PIN APIs */
void rt_pin_mode(rt_base_t pin, rt_base_t mode)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    _hw_pin.ops->pin_mode(&_hw_pin.parent, pin, mode);
}

void rt_pin_write(rt_base_t pin, rt_base_t value)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    _hw_pin.ops->pin_write(&_hw_pin.parent, pin, value);
}

int rt_pin_read(rt_base_t pin)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    return _hw_pin.ops->pin_read(&_hw_pin.parent, pin);
}


rt_base_t rt_pin_get(const char *name)
{
    RT_ASSERT(_hw_pin.ops != RT_NULL);
    RT_ASSERT(name[0] == 'P');

    if (_hw_pin.ops->pin_get == RT_NULL)
    {
        return -RT_ENOSYS;
    }

    return _hw_pin.ops->pin_get(name);
}

#ifdef FINSH_USING_MSH

static void print_usage(void)
{
    rt_kprintf("\r\npin operate command\t\n");
    rt_kprintf("Usage : pin [option] [pin_num] ...\r\n");
    rt_kprintf("option : \r\n");
    rt_kprintf("\tnum\t: get pin number from hardware pin, \r\n\t\t e.g. MSH >pin num PA16\r\n");
    rt_kprintf("\tmode\t: set pin mode to output/input/input_pullup/input_pulldown/output_od, \r\n\t\t e.g. MSH >pin mode PA16 output\r\n");
    rt_kprintf("\tread\t: read pin level of hardware pin, \r\n\t\t e.g. MSH >pin read PA16\r\n");
    rt_kprintf("\twrite\t: write pin level(high/low or on/off) to hardware pin, \r\n\t\t e.g. MSH >pin write PA16 high\r\n");
    rt_kprintf("\thelp\t: this help list\r\n");
}

// e.g. MSH >pin num PA16
static void pin_get(int argc, char *argv[])
{
    rt_base_t pin;
    if (argc < 3)
    {
        print_usage();
        return;
    }
    if ('P' != argv[2][0])
    {
        print_usage();
        return;
    }
    pin = rt_pin_get(argv[2]);
    rt_kprintf("%s : %d\r\n", argv[2], pin);
}

// e.g. MSH >pin mode PA16 output
static void pin_mode(int argc, char *argv[])
{
    rt_base_t pin;
    rt_base_t mode;
    if (argc < 4)
    {
        print_usage();
        return;
    }
    if (!rt_isint(argv[2]))
    {
        if ('P' != argv[2][0])
        {
            print_usage();
            return;
        }
        pin = rt_pin_get(argv[2]);
    }
    else
    {
        pin = rt_strtoint(argv[2]);
    }
    if (0 == rt_strcmp("output", argv[3]))
    {
        mode = PIN_MODE_OUTPUT;
    }
    else if (0 == rt_strcmp("input", argv[3]))
    {
        mode = PIN_MODE_INPUT;
    }
    else if (0 == rt_strcmp("input_pullup", argv[3]))
    {
        mode = PIN_MODE_INPUT_PULLUP;
    }    
    else if (0 == rt_strcmp("input_pulldown", argv[3]))
    {
        mode = PIN_MODE_INPUT_PULLDOWN;
    }
    else if (0 == rt_strcmp("output_od", argv[3]))
    {
        mode = PIN_MODE_OUTPUT_OD;
    }
    else
    {
        print_usage();
        return;
    }

    rt_pin_mode(pin, mode);
}

// e.g. MSH >pin read PA16
static void pin_read(int argc, char *argv[])
{
    rt_base_t pin;
    rt_base_t value;
    if (argc < 3)
    {
        print_usage();
        return;
    }
    if (!rt_isint(argv[2]))
    {
        if ('P' != argv[2][0])
        {
            print_usage();
            return;
        }
        pin = rt_pin_get(argv[2]);
    }
    else
    {
        pin = rt_strtoint(argv[2]);
    }
    value = rt_pin_read(pin);
    if (value == PIN_HIGH)
    {
        rt_kprintf("pin[%d] = on\r\n", pin);
    }
    else
    {
        rt_kprintf("pin[%d] = off\r\n", pin);
    }
}

// e.g. MSH >pin write PA16 high
static void pin_write(int argc, char *argv[])
{
    rt_base_t pin;
    rt_base_t value;
    if (argc < 4)
    {
        print_usage();
        return;
    }
    if (!rt_isint(argv[2]))
    {
        if ('P' != argv[2][0])
        {
            print_usage();
            return;
        }
        pin = rt_pin_get(argv[2]);
    }
    else
    {
        pin = rt_strtoint(argv[2]);
    }
    if ((0 == rt_strcmp("high", argv[3])) || (0 == rt_strcmp("on", argv[3])))
    {
        value = PIN_HIGH;
    }
    else if ((0 == rt_strcmp("low", argv[3])) || (0 == rt_strcmp("off", argv[3])))
    {
        value = PIN_LOW;
    }
    else
    {
        print_usage();
        return;
    }
    rt_pin_write(pin, value);
}

static void pin_cmd(int argc, char *argv[])
{
    if (argc < 3)
    {
        print_usage();
        return ;
    }
    if (0 == rt_strcmp("num", argv[1]))
    {
        pin_get(argc, argv);
    }
    else if (0 == rt_strcmp("mode", argv[1]))
    {
        pin_mode(argc, argv);
    }
    else if (0 == rt_strcmp("read", argv[1]))
    {
        pin_read(argc, argv);
    }
    else if (0 == rt_strcmp("write", argv[1]))
    {
        pin_write(argc, argv);
    }
    else
    {
        print_usage();
        return;
    }
}
MSH_CMD_EXPORT_ALIAS(pin_cmd, pin, pin operate command);
#endif
