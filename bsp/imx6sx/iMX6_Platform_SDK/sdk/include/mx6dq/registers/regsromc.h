/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_ROMC_REGISTERS_H__
#define __HW_ROMC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ ROMC
 *
 * ROMC
 *
 * Registers defined in this header file:
 * - HW_ROMC_ROMPATCHnD - ROMC Data Registers
 * - HW_ROMC_ROMPATCHCNTL - ROMC Control Register
 * - HW_ROMC_ROMPATCHENH - ROMC Enable Register High
 * - HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
 * - HW_ROMC_ROMPATCHnA - ROMC Address Registers
 * - HW_ROMC_ROMPATCHSR - ROMC Status Register
 *
 * - hw_romc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ROMC_BASE
#define HW_ROMC_INSTANCE_COUNT (1) //!< Number of instances of the ROMC module.
#define REGS_ROMC_BASE (0x021ac000) //!< Base address for ROMC.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHnD - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHnD - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC. If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatchnd
{
    reg32_t U;
    struct _hw_romc_rompatchnd_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatchnd_t;
#endif

/*!
 * @name Constants and macros for entire ROMC_ROMPATCHnD register
 */
//@{
//! @brief Number of instances of the ROMC_ROMPATCHnD register.
#define HW_ROMC_ROMPATCHnD_COUNT     (8)

#define HW_ROMC_ROMPATCHnD_ADDR(n)   (REGS_ROMC_BASE + 0xd4 + (0x4 * (n)))

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHnD(n)        (*(volatile hw_romc_rompatchnd_t *) HW_ROMC_ROMPATCHnD_ADDR(n))
#define HW_ROMC_ROMPATCHnD_RD(n)     (HW_ROMC_ROMPATCHnD(n).U)
#define HW_ROMC_ROMPATCHnD_WR(n, v)  (HW_ROMC_ROMPATCHnD(n).U = (v))
#define HW_ROMC_ROMPATCHnD_SET(n, v) (HW_ROMC_ROMPATCHnD_WR(n, HW_ROMC_ROMPATCHnD_RD(n) |  (v)))
#define HW_ROMC_ROMPATCHnD_CLR(n, v) (HW_ROMC_ROMPATCHnD_WR(n, HW_ROMC_ROMPATCHnD_RD(n) & ~(v)))
#define HW_ROMC_ROMPATCHnD_TOG(n, v) (HW_ROMC_ROMPATCHnD_WR(n, HW_ROMC_ROMPATCHnD_RD(n) ^  (v)))
#endif
//@}

/*
 * constants & macros for individual ROMC_ROMPATCHnD bitfields
 */

/*! @name Register ROMC_ROMPATCHnD, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */
//@{
#define BP_ROMC_ROMPATCHnD_DATAX      (0)      //!< Bit position for ROMC_ROMPATCHnD_DATAX.
#define BM_ROMC_ROMPATCHnD_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCHnD_DATAX.

//! @brief Get value of ROMC_ROMPATCHnD_DATAX from a register value.
#define BG_ROMC_ROMPATCHnD_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHnD_DATAX) >> BP_ROMC_ROMPATCHnD_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCHnD_DATAX.
#define BF_ROMC_ROMPATCHnD_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHnD_DATAX) & BM_ROMC_ROMPATCHnD_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCHnD_DATAX(n, v)   (HW_ROMC_ROMPATCHnD_WR(n, (HW_ROMC_ROMPATCHnD_RD(n) & ~BM_ROMC_ROMPATCHnD_DATAX) | BF_ROMC_ROMPATCHnD_DATAX(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHCNTL - ROMC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHCNTL - ROMC Control Register (RW)
 *
 * Reset value: 0x08400000
 *
 * The ROMC control register (ROMC_ROMPATCHCNTL) contains the block disable bit and the data fix
 * enable bits. The block disable bit provides a means to disable the ROMC data fix and opcode
 * patching functions, even when the address comparators are enabled. The External Boot feature is
 * not affected by this bit. The eight data fix enable bits (0 through 7), when set, assign the
 * associated address comparators to data fix operations Bits 27 and 22 always read as 1s.
 */
typedef union _hw_romc_rompatchcntl
{
    reg32_t U;
    struct _hw_romc_rompatchcntl_bitfields
    {
        unsigned DATAFIX : 8; //!< [7:0] Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for code patch routine.
        unsigned RESERVED0 : 21; //!< [28:8] Reserved
        unsigned DIS : 1; //!< [29] ROMC Disable -- This bit, when set, disables all ROMC operations.
        unsigned RESERVED1 : 2; //!< [31:30] Reserved
    } B;
} hw_romc_rompatchcntl_t;
#endif

/*!
 * @name Constants and macros for entire ROMC_ROMPATCHCNTL register
 */
//@{
#define HW_ROMC_ROMPATCHCNTL_ADDR      (REGS_ROMC_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHCNTL           (*(volatile hw_romc_rompatchcntl_t *) HW_ROMC_ROMPATCHCNTL_ADDR)
#define HW_ROMC_ROMPATCHCNTL_RD()      (HW_ROMC_ROMPATCHCNTL.U)
#define HW_ROMC_ROMPATCHCNTL_WR(v)     (HW_ROMC_ROMPATCHCNTL.U = (v))
#define HW_ROMC_ROMPATCHCNTL_SET(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() |  (v)))
#define HW_ROMC_ROMPATCHCNTL_CLR(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHCNTL_TOG(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() ^  (v)))
#endif
//@}

/*
 * constants & macros for individual ROMC_ROMPATCHCNTL bitfields
 */

/*! @name Register ROMC_ROMPATCHCNTL, field DATAFIX[7:0] (RW)
 *
 * Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for
 * code patch routine.
 *
 * Values:
 * - 0 - Address comparator triggers a opcode patch
 * - 1 - Address comparator triggers a data fix
 */
//@{
#define BP_ROMC_ROMPATCHCNTL_DATAFIX      (0)      //!< Bit position for ROMC_ROMPATCHCNTL_DATAFIX.
#define BM_ROMC_ROMPATCHCNTL_DATAFIX      (0x000000ff)  //!< Bit mask for ROMC_ROMPATCHCNTL_DATAFIX.

//! @brief Get value of ROMC_ROMPATCHCNTL_DATAFIX from a register value.
#define BG_ROMC_ROMPATCHCNTL_DATAFIX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHCNTL_DATAFIX) >> BP_ROMC_ROMPATCHCNTL_DATAFIX)

//! @brief Format value for bitfield ROMC_ROMPATCHCNTL_DATAFIX.
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHCNTL_DATAFIX) & BM_ROMC_ROMPATCHCNTL_DATAFIX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAFIX field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DATAFIX(v)   (HW_ROMC_ROMPATCHCNTL_WR((HW_ROMC_ROMPATCHCNTL_RD() & ~BM_ROMC_ROMPATCHCNTL_DATAFIX) | BF_ROMC_ROMPATCHCNTL_DATAFIX(v)))
#endif
//@}

/*! @name Register ROMC_ROMPATCHCNTL, field DIS[29] (RW)
 *
 * ROMC Disable -- This bit, when set, disables all ROMC operations. This bit is used to enable
 * secure operations.
 *
 * Values:
 * - 0 - Does not affect any ROMC functions (default)
 * - 1 - Disable all ROMC functions: data fixing, and opcode patching
 */
//@{
#define BP_ROMC_ROMPATCHCNTL_DIS      (29)      //!< Bit position for ROMC_ROMPATCHCNTL_DIS.
#define BM_ROMC_ROMPATCHCNTL_DIS      (0x20000000)  //!< Bit mask for ROMC_ROMPATCHCNTL_DIS.

//! @brief Get value of ROMC_ROMPATCHCNTL_DIS from a register value.
#define BG_ROMC_ROMPATCHCNTL_DIS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHCNTL_DIS) >> BP_ROMC_ROMPATCHCNTL_DIS)

//! @brief Format value for bitfield ROMC_ROMPATCHCNTL_DIS.
#define BF_ROMC_ROMPATCHCNTL_DIS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHCNTL_DIS) & BM_ROMC_ROMPATCHCNTL_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DIS(v)   (HW_ROMC_ROMPATCHCNTL_WR((HW_ROMC_ROMPATCHCNTL_RD() & ~BM_ROMC_ROMPATCHCNTL_DIS) | BF_ROMC_ROMPATCHCNTL_DIS(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHENH - ROMC Enable Register High
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHENH - ROMC Enable Register High (RO)
 *
 * Reset value: 0x00000000
 *
 * The ROMC enable register high (ROMC_ROMPATCHENH) and ROMC enable register low (ROMC_ROMPATCHENL)
 * control whether or not the associated address comparator can trigger a opcode patch or data fix
 * event. This implementation of the ROMC only has 16 comparators, therefore ROMC_ROMPATCHENH and
 * the upper half of ROMC_OMPATCHENL are read-only. ROMC_ROMPATCHENL[15:0] are associated with
 * comparators 15 through 0. ROMC_ROMPATCHENLH[31:0] would have been associated with comparators 63
 * through 32.
 */
typedef union _hw_romc_rompatchenh
{
    reg32_t U;
    struct _hw_romc_rompatchenh_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved
    } B;
} hw_romc_rompatchenh_t;
#endif

/*!
 * @name Constants and macros for entire ROMC_ROMPATCHENH register
 */
//@{
#define HW_ROMC_ROMPATCHENH_ADDR      (REGS_ROMC_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENH           (*(volatile hw_romc_rompatchenh_t *) HW_ROMC_ROMPATCHENH_ADDR)
#define HW_ROMC_ROMPATCHENH_RD()      (HW_ROMC_ROMPATCHENH.U)
#endif
//@}

/*
 * constants & macros for individual ROMC_ROMPATCHENH bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHENL - ROMC Enable Register Low (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC enable register high (ROMC_ROMPATCHENH) and ROMC enable register low (ROMC_ROMPATCHENL)
 * control whether or not the associated address comparator can trigger a opcode patch or data fix
 * event. This implementation of the ROMC only has 16 comparators, therefore ROMC_ROMPATCHENH and
 * the upper half of ROMC_ROMPATCHENL are read-only. ROMC_ROMPATCHENL[15:0] are associated with
 * comparators 15 through 0. ROMC_ROMPATCHENLH[31:0] would have been associated with comparators 63
 * through 32.
 */
typedef union _hw_romc_rompatchenl
{
    reg32_t U;
    struct _hw_romc_rompatchenl_bitfields
    {
        unsigned ENABLE : 16; //!< [15:0] Enable Address Comparator - This bit enables the corresponding address comparator to trigger an event.
        unsigned RESERVED0 : 16; //!< [31:16]
    } B;
} hw_romc_rompatchenl_t;
#endif

/*!
 * @name Constants and macros for entire ROMC_ROMPATCHENL register
 */
//@{
#define HW_ROMC_ROMPATCHENL_ADDR      (REGS_ROMC_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENL           (*(volatile hw_romc_rompatchenl_t *) HW_ROMC_ROMPATCHENL_ADDR)
#define HW_ROMC_ROMPATCHENL_RD()      (HW_ROMC_ROMPATCHENL.U)
#define HW_ROMC_ROMPATCHENL_WR(v)     (HW_ROMC_ROMPATCHENL.U = (v))
#define HW_ROMC_ROMPATCHENL_SET(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() |  (v)))
#define HW_ROMC_ROMPATCHENL_CLR(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHENL_TOG(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() ^  (v)))
#endif
//@}

/*
 * constants & macros for individual ROMC_ROMPATCHENL bitfields
 */

/*! @name Register ROMC_ROMPATCHENL, field ENABLE[15:0] (RW)
 *
 * Enable Address Comparator - This bit enables the corresponding address comparator to trigger an
 * event.
 *
 * Values:
 * - 0 - Address comparator disabled
 * - 1 - Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the
 *     associated address
 */
//@{
#define BP_ROMC_ROMPATCHENL_ENABLE      (0)      //!< Bit position for ROMC_ROMPATCHENL_ENABLE.
#define BM_ROMC_ROMPATCHENL_ENABLE      (0x0000ffff)  //!< Bit mask for ROMC_ROMPATCHENL_ENABLE.

//! @brief Get value of ROMC_ROMPATCHENL_ENABLE from a register value.
#define BG_ROMC_ROMPATCHENL_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHENL_ENABLE) >> BP_ROMC_ROMPATCHENL_ENABLE)

//! @brief Format value for bitfield ROMC_ROMPATCHENL_ENABLE.
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHENL_ENABLE) & BM_ROMC_ROMPATCHENL_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_ROMC_ROMPATCHENL_ENABLE(v)   (HW_ROMC_ROMPATCHENL_WR((HW_ROMC_ROMPATCHENL_RD() & ~BM_ROMC_ROMPATCHENL_ENABLE) | BF_ROMC_ROMPATCHENL_ENABLE(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHnA - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHnA - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatchna
{
    reg32_t U;
    struct _hw_romc_rompatchna_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatchna_t;
#endif

/*!
 * @name Constants and macros for entire ROMC_ROMPATCHnA register
 */
//@{
//! @brief Number of instances of the ROMC_ROMPATCHnA register.
#define HW_ROMC_ROMPATCHnA_COUNT     (16)

#define HW_ROMC_ROMPATCHnA_ADDR(n)   (REGS_ROMC_BASE + 0x100 + (0x4 * (n)))

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHnA(n)        (*(volatile hw_romc_rompatchna_t *) HW_ROMC_ROMPATCHnA_ADDR(n))
#define HW_ROMC_ROMPATCHnA_RD(n)     (HW_ROMC_ROMPATCHnA(n).U)
#define HW_ROMC_ROMPATCHnA_WR(n, v)  (HW_ROMC_ROMPATCHnA(n).U = (v))
#define HW_ROMC_ROMPATCHnA_SET(n, v) (HW_ROMC_ROMPATCHnA_WR(n, HW_ROMC_ROMPATCHnA_RD(n) |  (v)))
#define HW_ROMC_ROMPATCHnA_CLR(n, v) (HW_ROMC_ROMPATCHnA_WR(n, HW_ROMC_ROMPATCHnA_RD(n) & ~(v)))
#define HW_ROMC_ROMPATCHnA_TOG(n, v) (HW_ROMC_ROMPATCHnA_WR(n, HW_ROMC_ROMPATCHnA_RD(n) ^  (v)))
#endif
//@}

/*
 * constants & macros for individual ROMC_ROMPATCHnA bitfields
 */

/*! @name Register ROMC_ROMPATCHnA, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * - 0 - ARM patch
 * - 1 - THUMB patch (ignore if data fix)
 */
//@{
#define BP_ROMC_ROMPATCHnA_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCHnA_THUMBX.
#define BM_ROMC_ROMPATCHnA_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCHnA_THUMBX.

//! @brief Get value of ROMC_ROMPATCHnA_THUMBX from a register value.
#define BG_ROMC_ROMPATCHnA_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHnA_THUMBX) >> BP_ROMC_ROMPATCHnA_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCHnA_THUMBX.
#define BF_ROMC_ROMPATCHnA_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHnA_THUMBX) & BM_ROMC_ROMPATCHnA_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCHnA_THUMBX(n, v)   (HW_ROMC_ROMPATCHnA_WR(n, (HW_ROMC_ROMPATCHnA_RD(n) & ~BM_ROMC_ROMPATCHnA_THUMBX) | BF_ROMC_ROMPATCHnA_THUMBX(v)))
#endif
//@}

/*! @name Register ROMC_ROMPATCHnA, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */
//@{
#define BP_ROMC_ROMPATCHnA_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCHnA_ADDRX.
#define BM_ROMC_ROMPATCHnA_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCHnA_ADDRX.

//! @brief Get value of ROMC_ROMPATCHnA_ADDRX from a register value.
#define BG_ROMC_ROMPATCHnA_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHnA_ADDRX) >> BP_ROMC_ROMPATCHnA_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCHnA_ADDRX.
#define BF_ROMC_ROMPATCHnA_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHnA_ADDRX) & BM_ROMC_ROMPATCHnA_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCHnA_ADDRX(n, v)   (HW_ROMC_ROMPATCHnA_WR(n, (HW_ROMC_ROMPATCHnA_RD(n) & ~BM_ROMC_ROMPATCHnA_ADDRX) | BF_ROMC_ROMPATCHnA_ADDRX(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHSR - ROMC Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHSR - ROMC Status Register (W1C)
 *
 * Reset value: 0x00000000
 *
 * The ROMC status register (ROMC_ROMPATCHSR) indicates the current state of the ROMC and the source
 * number of the most recent address comparator event.
 */
typedef union _hw_romc_rompatchsr
{
    reg32_t U;
    struct _hw_romc_rompatchsr_bitfields
    {
        unsigned SOURCE : 6; //!< [5:0] ROMC Source Number - Binary encoding of the number of the address comparator which has an address match in the most recent patch event on ROMC AHB.
        unsigned RESERVED0 : 11; //!< [16:6] Reserved
        unsigned SW : 1; //!< [17] ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address comparator matches occurred.
        unsigned RESERVED1 : 14; //!< [31:18] Reserved
    } B;
} hw_romc_rompatchsr_t;
#endif

/*!
 * @name Constants and macros for entire ROMC_ROMPATCHSR register
 */
//@{
#define HW_ROMC_ROMPATCHSR_ADDR      (REGS_ROMC_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHSR           (*(volatile hw_romc_rompatchsr_t *) HW_ROMC_ROMPATCHSR_ADDR)
#define HW_ROMC_ROMPATCHSR_RD()      (HW_ROMC_ROMPATCHSR.U)
#define HW_ROMC_ROMPATCHSR_WR(v)     (HW_ROMC_ROMPATCHSR.U = (v))
#define HW_ROMC_ROMPATCHSR_SET(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() |  (v)))
#define HW_ROMC_ROMPATCHSR_CLR(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() & ~(v)))
#define HW_ROMC_ROMPATCHSR_TOG(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() ^  (v)))
#endif
//@}

/*
 * constants & macros for individual ROMC_ROMPATCHSR bitfields
 */

/*! @name Register ROMC_ROMPATCHSR, field SOURCE[5:0] (RO)
 *
 * ROMC Source Number - Binary encoding of the number of the address comparator which has an address
 * match in the most recent patch event on ROMC AHB. If multiple matches occurred, the highest
 * priority source number is used.
 *
 * Values:
 * - 0 - Address Comparator 0 matched
 * - 1 - Address Comparator 1 matched
 * - 15 - Address Comparator 15 matched
 */
//@{
#define BP_ROMC_ROMPATCHSR_SOURCE      (0)      //!< Bit position for ROMC_ROMPATCHSR_SOURCE.
#define BM_ROMC_ROMPATCHSR_SOURCE      (0x0000003f)  //!< Bit mask for ROMC_ROMPATCHSR_SOURCE.

//! @brief Get value of ROMC_ROMPATCHSR_SOURCE from a register value.
#define BG_ROMC_ROMPATCHSR_SOURCE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHSR_SOURCE) >> BP_ROMC_ROMPATCHSR_SOURCE)
//@}

/*! @name Register ROMC_ROMPATCHSR, field SW[17] (W1C)
 *
 * ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address
 * comparator matches occurred. Writing a 1 to this bit will clear this it.
 *
 * Values:
 * - 0 - no event or comparator collisions
 * - 1 - a collision has occurred
 */
//@{
#define BP_ROMC_ROMPATCHSR_SW      (17)      //!< Bit position for ROMC_ROMPATCHSR_SW.
#define BM_ROMC_ROMPATCHSR_SW      (0x00020000)  //!< Bit mask for ROMC_ROMPATCHSR_SW.

//! @brief Get value of ROMC_ROMPATCHSR_SW from a register value.
#define BG_ROMC_ROMPATCHSR_SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHSR_SW) >> BP_ROMC_ROMPATCHSR_SW)

//! @brief Format value for bitfield ROMC_ROMPATCHSR_SW.
#define BF_ROMC_ROMPATCHSR_SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHSR_SW) & BM_ROMC_ROMPATCHSR_SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_ROMC_ROMPATCHSR_SW(v)   (HW_ROMC_ROMPATCHSR_WR((HW_ROMC_ROMPATCHSR_RD() & ~BM_ROMC_ROMPATCHSR_SW) | BF_ROMC_ROMPATCHSR_SW(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_romc_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All ROMC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_romc
{
    reg32_t _reserved0[53];
    volatile hw_romc_rompatchnd_t ROMPATCHnD[8]; //!< ROMC Data Registers
    volatile hw_romc_rompatchcntl_t ROMPATCHCNTL; //!< ROMC Control Register
    volatile hw_romc_rompatchenh_t ROMPATCHENH; //!< ROMC Enable Register High
    volatile hw_romc_rompatchenl_t ROMPATCHENL; //!< ROMC Enable Register Low
    volatile hw_romc_rompatchna_t ROMPATCHnA[16]; //!< ROMC Address Registers
    reg32_t _reserved1[50];
    volatile hw_romc_rompatchsr_t ROMPATCHSR; //!< ROMC Status Register
} hw_romc_t;
#pragma pack()

//! @brief Macro to access all ROMC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ROMC</code>.
#define HW_ROMC     (*(hw_romc_t *) REGS_ROMC_BASE)
#endif

#endif // __HW_ROMC_REGISTERS_H__
// v18/121106/1.2.2
// EOF
