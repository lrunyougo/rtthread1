#include <rtdef.h>

#ifndef ARM_GIC_CPU_NUM
#define ARM_GIC_CPU_NUM RT_CPUS_NR
#endif

#define GICV3_ROUTED_TO_ALL   1UL
#define GICV3_ROUTED_TO_SPEC  0UL

int arm_gic_get_active_irq(rt_uint64_t index);
void arm_gic_ack(rt_uint64_t index, int irq);

void arm_gic_mask(rt_uint64_t index, int irq);
void arm_gic_umask(rt_uint64_t index, int irq);

rt_uint64_t arm_gic_get_pending_irq(rt_uint64_t index, int irq);
void arm_gic_set_pending_irq(rt_uint64_t index, int irq);
void arm_gic_clear_pending_irq(rt_uint64_t index, int irq);

void arm_gic_set_configuration(rt_uint64_t index, int irq, rt_uint32_t config);
rt_uint64_t arm_gic_get_configuration(rt_uint64_t index, int irq);

void arm_gic_clear_active(rt_uint64_t index, int irq);

void arm_gic_set_router_cpu(rt_uint64_t index, int irq, rt_uint64_t aff);
void arm_gic_set_cpu(rt_uint64_t index, int irq, unsigned int cpumask);
rt_uint64_t arm_gic_get_target_cpu(rt_uint64_t index, int irq);

void arm_gic_set_priority(rt_uint64_t index, int irq, rt_uint64_t priority);
rt_uint64_t arm_gic_get_priority(rt_uint64_t index, int irq);

void arm_gic_set_interface_prior_mask(rt_uint64_t index, rt_uint64_t priority);
rt_uint64_t arm_gic_get_interface_prior_mask(rt_uint64_t index);

void arm_gic_set_binary_point(rt_uint64_t index, rt_uint64_t binary_point);
rt_uint64_t arm_gic_get_binary_point(rt_uint64_t index);

rt_uint64_t arm_gic_get_irq_status(rt_uint64_t index, int irq);

#if defined(RT_USING_SMP) || defined(RT_USING_AMP)
void arm_gic_send_affinity_sgi(rt_uint64_t index, int irq, rt_uint32_t cpu_masks[], rt_uint64_t routing_mode);
#endif

rt_uint64_t arm_gic_get_high_pending_irq(rt_uint64_t index);

rt_uint64_t arm_gic_get_interface_id(rt_uint64_t index);

void arm_gic_set_group(rt_uint64_t index, int irq, rt_uint64_t group);
rt_uint64_t arm_gic_get_group(rt_uint64_t index, int irq);

int arm_gic_redist_address_set(rt_uint64_t index, rt_uint64_t redist_addr, int cpu_id);
int arm_gic_cpu_interface_address_set(rt_uint64_t index, rt_uint64_t interface_addr, int cpu_id);

int arm_gic_dist_init(rt_uint64_t index, rt_uint64_t dist_base, int irq_start);
int arm_gic_redist_init(rt_uint64_t index, rt_uint64_t redist_base);
int arm_gic_cpu_init(rt_uint64_t index, rt_uint64_t cpu_base);

void arm_gic_dump_type(rt_uint64_t index);
void arm_gic_dump(rt_uint64_t index);
