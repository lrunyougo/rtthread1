/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-07-06     Bernard      first version
 */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <rthw.h>
#include <board.h>

#ifndef MAX_MSI_HANDLERS
#define MAX_MSI_HANDLERS    MAX_HANDLERS
#endif /* MAX_MSI_HANDLERS */

#ifndef MSI_INTID_START
#define MSI_INTID_START     8192
#endif /* MSI_INTID_START */

#define INT_IRQ     0x00
#define INT_FIQ     0x01

#define IRQ_MODE_TRIG_LEVEL         (0x00) /* Trigger: level triggered interrupt */
#define IRQ_MODE_TRIG_EDGE          (0x01) /* Trigger: edge triggered interrupt */
#define IRQ_MODE_MASK               (0x01)

void rt_hw_vector_init(void);

void rt_hw_interrupt_init(void);
void rt_hw_interrupt_mask(int vector);
void rt_hw_interrupt_umask(int vector);

int rt_hw_interrupt_get_irq(void);
void rt_hw_interrupt_ack(int vector);

void rt_hw_interrupt_set_target_cpus(int vector, unsigned long cpu_mask);
unsigned int rt_hw_interrupt_get_target_cpus(int vector);

void rt_hw_interrupt_set_triger_mode(int vector, unsigned int mode);
unsigned int rt_hw_interrupt_get_triger_mode(int vector);

void rt_hw_interrupt_set_pending(int vector);
unsigned int rt_hw_interrupt_get_pending(int vector);
void rt_hw_interrupt_clear_pending(int vector);

void rt_hw_interrupt_set_priority(int vector, unsigned int priority);
unsigned int rt_hw_interrupt_get_priority(int vector);

void rt_hw_interrupt_set_priority_mask(unsigned int priority);
unsigned int rt_hw_interrupt_get_priority_mask(void);

int rt_hw_interrupt_set_prior_group_bits(unsigned int bits);
unsigned int rt_hw_interrupt_get_prior_group_bits(void);

/* message interrupt api */
rt_uint32_t rt_hw_interrupt_msi_alloc_irq(void);
rt_err_t rt_hw_interrupt_msi_setup_deviceid(unsigned int device_id, unsigned int event_num);
rt_err_t rt_hw_interrupt_msi_map_irq(unsigned int device_id, unsigned int event_id, unsigned int irq);
rt_uint64_t rt_hw_interrupt_msi_address_get(void);

rt_isr_handler_t rt_hw_interrupt_install(int vector, rt_isr_handler_t handler,
        void *param, const char *name);

#if defined(RT_USING_SMP) || defined(RT_USING_AMP)
void rt_hw_ipi_handler_install(int ipi_vector, rt_isr_handler_t ipi_isr_handler);
#endif

#endif

