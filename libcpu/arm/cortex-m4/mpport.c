#include <rtdef.h>
#include <mp.h>
#include "mpport.h"

#define DBG_ENABLE
#define DBG_SECTION_NAME "MEMORY PROTECTION"
#define DBG_LEVEL DBG_ERROR
#include <rtdbg.h>

#define MEM_REGION_TO_MPU_INDEX(thread, region) ((rt_size_t)region - (rt_size_t)(&(thread->mem_regions[0])) / sizeof(rt_mem_region_t)) + NUM_STATIC_REGIONS

extern rt_mem_region_t *rt_mem_protection_find_free_region(rt_thread_t thread);
extern rt_mem_region_t *rt_mem_protection_find_region(rt_thread_t thread, rt_mem_region_t *region);

rt_hw_mp_exception_hook_t hook;

static rt_uint32_t default_mem_attr[] = {
    NORMAL_OUTER_INNER_WRITE_THROUGH_NON_SHAREABLE,
    NORMAL_OUTER_INNER_WRITE_BACK_WRITE_READ_ALLOCATE_NON_SHAREABLE,
    DEVICE_NON_SHAREABLE,
    NORMAL_OUTER_INNER_WRITE_BACK_WRITE_READ_ALLOCATE_NON_SHAREABLE,
    NORMAL_OUTER_INNER_WRITE_THROUGH_NON_SHAREABLE,
    DEVICE_SHAREABLE,
    DEVICE_NON_SHAREABLE
};

static inline rt_uint32_t mpu_rasr(rt_mem_region_t *region)
{
    rt_uint32_t rasr = 0;
    if (region->attr.rasr & RESERVED)
    {
        if ((uint32_t)region->start >= 0xE0000000U)
        {
            rasr |= ((uint32_t)region->start >= 0xE0100000U) ? STRONGLY_ORDERED_SHAREABLE : DEVICE_SHAREABLE;            
        }
        else
        {
            rasr |= (region->attr.rasr | default_mem_attr[((uint32_t)region->start & ~0xFFFFFFF) >> 1]);
        }
    }
    else
    {
        rasr |= region->attr.rasr;
    }
    rasr |= (region->attr.rasr & RESERVED) ? (region->attr.rasr | default_mem_attr[(uint32_t)region->start & ~0xFFFFFFF]): region->attr.rasr;
    rasr |= ((32 - __builtin_clz(region->size - 1U) - 2 + 1) << MPU_RASR_SIZE_Pos) & MPU_RASR_SIZE_Msk;
    rasr |= MPU_RASR_SRD_Msk;
    rasr |= MPU_RASR_ENABLE_Msk;
    return rasr;
}

rt_bool_t rt_hw_mp_region_valid(rt_mem_region_t *region)
{
    if (region->size < MPU_MIN_REGION_SIZE)
    {
        LOG_E("Region size is too small");
        return RT_FALSE;
    }
    if (region->size & (region->size - 1) != 0)
    {
        LOG_E("Region size is not power of 2");
        return RT_FALSE;
    }
    if ((rt_uint32_t)region->start & (region->size - 1) != 0)
    {
        LOG_E("Region is not naturally aligned");
        return RT_FALSE;
    }
    return RT_TRUE;
}

rt_err_t rt_hw_mp_init(rt_mem_region_t *static_regions, rt_uint8_t num_regions)
{
    rt_uint8_t num_mpu_regions;
    rt_uint8_t num_dynamic_regions;
    rt_uint8_t region_index;
    num_mpu_regions = (rt_uint8_t)((MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos);
    if (num_mpu_regions == 0)
    {
        LOG_E("Hardware does not support MPU");
        return RT_ERROR;
    }
    if (num_mpu_regions != NUM_MEM_REGIONS)
    {
        LOG_E("Incorrect setting of NUM_MEM_REGIONS");
        LOG_E("NUM_MEM_REGIONS = %d, hardware support %d MPU regions", NUM_MEM_REGIONS, num_mpu_regions);
        return RT_ERROR;
    }
    
    num_dynamic_regions = NUM_DYNAMIC_REGIONS + NUM_EXCLUSIVE_REGIONS;
    if (num_dynamic_regions + NUM_STATIC_REGIONS > num_mpu_regions)
    {
        LOG_E("Insufficient MPU regions: %d hardware MPU regions", num_mpu_regions);
#ifdef RT_USING_HW_STACK_GUARD
        LOG_E("Current configuration requires %d static regions + %d configurable regions + %d exclusive regions + %d stack guard regions", NUM_STATIC_REGIONS, NUM_CONFIGURABLE_REGIONS, NUM_EXCLUSIVE_REGIONS, 2);
#else
        LOG_E("Current configuration requires %d static regions + %d configurable regions + %d exclusive regions", NUM_STATIC_REGIONS, NUM_CONFIGURABLE_REGIONS, NUM_EXCLUSIVE_REGIONS);
#endif
        return RT_ERROR;
    }

    ARM_MPU_Disable();
    for (region_index = 0; region_index < NUM_STATIC_REGIONS; ++region_index)
    {
        if (rt_hw_mp_region_valid(&(static_regions[region_index])) == RT_FALSE)
        {
            return RT_ERROR;
        }
        static_regions[region_index].attr.rasr = mpu_rasr(&(static_regions[region_index]));
        ARM_MPU_SetRegion(ARM_MPU_RBAR(region_index, (uint32_t)static_regions[region_index].start), static_regions[region_index].attr.rasr);
    }
    // Enable background region
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

    return RT_EOK;
}

rt_err_t rt_hw_mp_add_region(rt_thread_t thread, rt_mem_region_t *region)
{
    rt_uint8_t index;
    rt_mem_region_t *free_region;
    if (rt_hw_mp_region_valid(region) == RT_FALSE)
    {
        return RT_ERROR;
    }
    region->attr.rasr = mpu_rasr(region);
    if (thread == RT_NULL)
    {
        return RT_EOK;
    }
    free_region = rt_mem_protection_find_free_region(thread);
    if (free_region == RT_NULL)
    {
        LOG_E("Insufficient regions");
        return RT_ERROR;
    }
    rt_memcpy(free_region, region, sizeof(rt_mem_region_t));
    if (thread == rt_thread_self())
    {
        index = MEM_REGION_TO_MPU_INDEX(thread, free_region);
        ARM_MPU_SetRegion(ARM_MPU_RBAR(index, (uint32_t)region->start), region->attr.rasr);
    }
    return RT_EOK;
}

rt_err_t rt_hw_mp_delete_region(rt_thread_t thread, rt_mem_region_t *region)
{
    rt_uint8_t index;
    rt_mem_region_t *found_region = rt_mem_protection_find_region(thread, region);
    if (found_region == RT_NULL)
    {
        LOG_E("Region not found");
        return RT_ERROR;
    }
    rt_memset(found_region, 0, sizeof(rt_mem_region_t));
    if (thread == rt_thread_self())
    {
        index = MEM_REGION_TO_MPU_INDEX(thread, found_region);
        ARM_MPU_ClrRegion(index);
    }
    return RT_EOK;
}

rt_err_t rt_hw_mp_update_region(rt_thread_t thread, rt_mem_region_t *region)
{
    rt_uint8_t index;
    rt_mem_region_t *old_region = rt_mem_protection_find_region(thread, region);
    if (old_region == RT_NULL)
    {
        LOG_E("Region not found");
        return RT_ERROR;
    }
    if (rt_hw_mp_region_valid(region) == RT_FALSE)
    {
        return RT_ERROR;
    }
    region->attr.rasr = mpu_rasr(region);
    rt_memcpy(old_region, region, sizeof(rt_mem_region_t));
    if (thread == rt_thread_self())
    {
        index = MEM_REGION_TO_MPU_INDEX(thread, old_region);
        ARM_MPU_SetRegion(ARM_MPU_RBAR(index, (uint32_t)region->start), region->attr.rasr);
    }  
    return RT_EOK;
}

rt_err_t rt_hw_mp_exception_set_hook(rt_mem_exception_info_t *info)
{
    return RT_EOK;
}

void rt_hw_mp_table_switch(rt_thread_t thread)
{
    
}

void MemManage_Handler(void)
{
    extern rt_mem_region_t static_regions[NUM_STATIC_REGIONS];
    extern rt_mem_exclusive_region_t exclusive_regions[NUM_EXCLUSIVE_REGIONS];
    rt_mem_exception_info_t info;
    rt_uint8_t i;
    rt_memset(&info, 0, sizeof(rt_mem_exception_info_t));
    info.thread = rt_thread_self();
    if (SCB->CFSR & SCB_CFSR_MMARVALID_Msk)
    {
        info.addr = (void *)(SCB->MMFAR);
        for (i = NUM_EXCLUSIVE_REGIONS - 1; i >= 0; --i)
        {
        if (ADDR_IN_REGION(info.addr, (rt_mem_region_t *)&(exclusive_regions[i])))
            {
                rt_memcpy(&(info.region), &(exclusive_regions[i]), sizeof(rt_mem_region_t));
            }
        }
        for (i = NUM_DYNAMIC_REGIONS - 1; i >= 0; --i)
        {
        if (ADDR_IN_REGION(info.addr, &(info.thread->mem_regions[i])))
            {
                rt_memcpy(&(info.region), &(info.thread->mem_regions[i]), sizeof(rt_mem_region_t));
            }
        }
        for (i = NUM_STATIC_REGIONS - 1; i >= 0; --i)
        {
            if (ADDR_IN_REGION(info.addr, &(static_regions[i])))
            {
                rt_memcpy(&(info.region), &(static_regions[i]), sizeof(rt_mem_region_t));
            }
        }
    }
    info.mmfsr = (SCB->CFSR & SCB_CFSR_MEMFAULTSR_Msk) >> SCB_CFSR_MEMFAULTSR_Pos;
    if (hook != RT_NULL)
    {
        hook(&info);
    }
}
