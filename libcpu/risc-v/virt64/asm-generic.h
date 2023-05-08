/*
 * Copyright (c) 2006-2023 RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-12     WangXiaoyao  the first version
 */
#ifndef __ASM_GENERIC_H__
#define __ASM_GENERIC_H__

/* use to mark a start point where every task start from */
#define START_POINT(funcname)               \
    .cfi_sections .debug_frame, .eh_frame;  \
    .global funcname;                       \
    .cfi_startproc;                         \
    funcname:                               \
    .cfi_undefined ra

#define START_POINT_END(name) \
    .cfi_endproc

#endif /* __ASM_GENERIC_H__ */
