/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-07     ZhaoMaosheng the first version
 */

#include <mm_memblock.h>
#include "common.h"

#define INIT_MEMORY_REGIONS 128
#define INIT_RESERVED_REGIONS 128

#define SZ_128M             0x08000000
#define SZ_256M             0x10000000
#define SZ_512M             0x20000000
#define SZ_1G               0x40000000

static struct rt_mmblk_reg _memory_init_regions[INIT_MEMORY_REGIONS];
static struct rt_mmblk_reg _reserved_init_regions[INIT_RESERVED_REGIONS];

static void _reset_memblock()
{
    mmblk_memory.cnt = 0;
    mmblk_reserved.cnt = 0;
}

static void test_memblock_add_simple(void)
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_1G, size1 = SZ_256M;
    rt_ubase_t base2 = SZ_128M, size2 = SZ_128M;

    rt_memblock_add(base1, size1);

    uassert_int_equal(_memory_init_regions[0].base, base1);
    uassert_int_equal(_memory_init_regions[0].size, size1);
    uassert_int_equal(_memory_init_regions[0].flags, 0);
    uassert_int_equal(mmblk_memory.cnt, 1);

    rt_memblock_add_ext(base2, size2, 1);

    uassert_int_equal(_memory_init_regions[0].base, base2);
    uassert_int_equal(_memory_init_regions[0].size, size2);
    uassert_int_equal(_memory_init_regions[0].flags, 1);
    uassert_int_equal(_memory_init_regions[1].base, base1);
    uassert_int_equal(_memory_init_regions[1].size, size1);
    uassert_int_equal(_memory_init_regions[1].flags, 0);
    uassert_int_equal(mmblk_memory.cnt, 2);
}

static void test_memblock_add_overlap_top()
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_512M, size1 = SZ_1G;
    rt_ubase_t base2 = SZ_256M, size2 = SZ_512M;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base2, size2);

    uassert_int_equal(_memory_init_regions[0].base, SZ_256M);
    uassert_int_equal(_memory_init_regions[0].size, SZ_1G + SZ_256M);
    uassert_int_equal(mmblk_memory.cnt, 1);
}

static void test_memblock_add_overlap_bottom()
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_128M, size1 = SZ_512M;
    rt_ubase_t base2 = SZ_256M, size2 = SZ_1G;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base2, size2);

    uassert_int_equal(_memory_init_regions[0].base, SZ_128M);
    uassert_int_equal(_memory_init_regions[0].size, SZ_1G + SZ_128M);
    uassert_int_equal(mmblk_memory.cnt, 1);
}

static void test_memblock_add_within()
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_128M, size1 = SZ_1G;
    rt_ubase_t base2 = SZ_256M, size2 = SZ_512M;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base2, size2);

    uassert_int_equal(_memory_init_regions[0].base, SZ_128M);
    uassert_int_equal(_memory_init_regions[0].size, SZ_1G);
    uassert_int_equal(mmblk_memory.cnt, 1);
}

static void test_memblock_add_twice()
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_128M, size1 = SZ_1G;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base1, size1);

    uassert_int_equal(_memory_init_regions[0].base, SZ_128M);
    uassert_int_equal(_memory_init_regions[0].size, SZ_1G);
    uassert_int_equal(mmblk_memory.cnt, 1);
}

static void test_memblock_add_between()
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_512M, size1 = SZ_256M;
    rt_ubase_t base2 = SZ_1G, size2 = SZ_512M;
    rt_ubase_t base3 = SZ_512M + SZ_256M, size3 = SZ_256M;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base2, size2);
    rt_memblock_add(base3, size3);

    uassert_int_equal(_memory_init_regions[0].base, SZ_512M);
    uassert_int_equal(_memory_init_regions[0].size, SZ_1G);
    uassert_int_equal(mmblk_memory.cnt, 1);
}

static void test_memblock_add_near_max()
{
    _reset_memblock();

    rt_ubase_t base1 = (rt_ubase_t)0 - (rt_ubase_t)SZ_128M, size1 = SZ_256M;

    rt_memblock_add(base1, size1);

    uassert_int_equal(_memory_init_regions[0].base, base1);
    uassert_int_equal(_memory_init_regions[0].size, SZ_128M - 1);
    uassert_int_equal(mmblk_memory.cnt, 1);
}

static void test_memblock_add(void)
{
    test_memblock_add_simple();
    test_memblock_add_overlap_top();
    test_memblock_add_overlap_bottom();
    test_memblock_add_within();
    test_memblock_add_twice();
    test_memblock_add_between();
    test_memblock_add_near_max();
}

static void test_memblock_set(void)
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_128M, size1 = SZ_256M;
    rt_ubase_t base2 = SZ_512M, size2 = SZ_256M;
    rt_ubase_t base3 = SZ_1G, size3 = SZ_512M;
    rt_ubase_t base_set = SZ_256M, size_set = SZ_1G;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base2, size2);
    rt_memblock_add(base3, size3);
    rt_memblock_mark_nomap(base_set, size_set);

    uassert_int_equal(mmblk_memory.cnt, 5);
    uassert_int_equal(_memory_init_regions[0].base, SZ_128M);
    uassert_int_equal(_memory_init_regions[0].size, SZ_128M);
    uassert_int_equal(_memory_init_regions[0].flags, MEMBLOCK_NONE);
    uassert_int_equal(_memory_init_regions[1].base, SZ_256M);
    uassert_int_equal(_memory_init_regions[1].size, SZ_128M);
    uassert_int_equal(_memory_init_regions[1].flags, MEMBLOCK_NOMAP);
    uassert_int_equal(_memory_init_regions[2].base, SZ_512M);
    uassert_int_equal(_memory_init_regions[2].size, SZ_256M);
    uassert_int_equal(_memory_init_regions[2].flags, MEMBLOCK_NOMAP);
    uassert_int_equal(_memory_init_regions[3].base, SZ_1G);
    uassert_int_equal(_memory_init_regions[3].size, SZ_256M);
    uassert_int_equal(_memory_init_regions[3].flags, MEMBLOCK_NOMAP);
    uassert_int_equal(_memory_init_regions[4].base, SZ_1G + SZ_256M);
    uassert_int_equal(_memory_init_regions[4].size, SZ_256M);
    uassert_int_equal(_memory_init_regions[4].flags, MEMBLOCK_NONE);
}

static void test_memblock_free(void)
{
    _reset_memblock();

    rt_ubase_t base1 = SZ_128M, size1 = SZ_256M;
    rt_ubase_t base2 = SZ_512M, size2 = SZ_256M;
    rt_ubase_t base3 = SZ_512M + SZ_256M, size3 = SZ_256M; /* flag = 1 */
    rt_ubase_t base4 = SZ_1G, size4 = SZ_512M;
    rt_ubase_t base1r = SZ_256M, size1r = SZ_256M + SZ_128M;
    rt_ubase_t base2r = SZ_1G + SZ_128M, size2r = SZ_256M;

    rt_ubase_t mem = 0, start = 0, end = 0;
    rt_uint64_t i = 0;

    rt_memblock_add(base1, size1);
    rt_memblock_add(base2, size2);
    rt_memblock_add_ext(base3, size3, 1);
    rt_memblock_add(base4, size4);
    rt_memblock_reserve(base1r, size1r);
    rt_memblock_reserve(base2r, size2r);

    for_each_free_region(i, MEMBLOCK_NONE, &start, &end)
    {
        mem += end - start;
    }
    uassert_int_equal(mem, SZ_512M);
}

static rt_err_t utest_tc_init(void)
{
    mmblk_memory.cnt = 0;
    mmblk_memory.max = INIT_MEMORY_REGIONS;
    mmblk_memory.regions = _memory_init_regions;

    mmblk_reserved.cnt = 0;
    mmblk_reserved.max = INIT_RESERVED_REGIONS;
    mmblk_reserved.regions = _reserved_init_regions;

    return RT_EOK;
}

static rt_err_t utest_tc_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_memblock_add);
    UTEST_UNIT_RUN(test_memblock_set);
    UTEST_UNIT_RUN(test_memblock_free);
}
UTEST_TC_EXPORT(testcase, "testcases.mm.memblock_tc", utest_tc_init, utest_tc_cleanup, 20);
