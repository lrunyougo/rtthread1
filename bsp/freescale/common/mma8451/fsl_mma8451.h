/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file
 * @brief Public interface for the MMA8451 accelerometer driver.
 * @ingroup diag_accel
 */

#if !defined(__FSL_MMA8451_H__)
#define __FSL_MMA8451_H__

#include "fsl_i2c_master_driver.h"

/*!
 * @addtogroup mma8451
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Register definitions for the MMA8451.*/
typedef enum _status{
  kStatus_Success = 0,
  kStatusFail     = 1
}mma8451_status_t;

enum _mma8451_constants
{
    kMMA8451_STATUS = 0x00,
    kMMA8451_OUT_X_MSB = 0x01,
    kMMA8451_OUT_X_LSB = 0x02,
    kMMA8451_OUT_Y_MSB = 0x03,
    kMMA8451_OUT_Y_LSB = 0x04,
    kMMA8451_OUT_Z_MSB = 0x05,
    kMMA8451_OUT_Z_LSB = 0x06,
    kMMA8451_F_SETUP = 0x09,
    kMMA8451_TRIG_CFG = 0x0a,
    kMMA8451_SYSMOD = 0x0b,
    kMMA8451_INT_SOURCE = 0x0c,
    kMMA8451_WHO_AM_I = 0x0d,
    kMMA8451_WHO_AM_I_Device_ID = 0x1a,
    kMMA8451_XYZ_DATA_CFG = 0x0e,
    kMMA8451_CTRL_REG1 = 0x2a,
    kMMA8451_CTRL_REG2 = 0x2b,
    kMMA8451_CTRL_REG3 = 0x2c,
    kMMA8451_CTRL_REG4 = 0x2d,
    kMMA8451_CTRL_REG5 = 0x2e
};

/*! @brief MMA8451 driver instance.*/
typedef struct _mma8451_device {
    uint32_t i2cInstance;
    i2c_master_state_t state;
    i2c_device_t i2cDevice;
} mma8451_device_t;

/*! @brief 3D acceleration values.*/
typedef struct _acceleration {
    int16_t x;
    int16_t y;
    int16_t z;
} acceleration_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the MMA8451 driver instance.
 *
 * @param device Device driver state structure that will be filled in by this function.
 *      It is the responsibility of the caller to provide storage for this structure, and
 *      to free that storage when the driver is no longer needed.
 *
 * @return kStatus_Success or kStatusFail.
 */
mma8451_status_t mma8451_init(mma8451_device_t * device);

/*!
 * @brief Read the current acceleration values.
 *
 * @param device Pointer to a valid device instance structure.
 * @param accel Pointer to a structure that will be filled in with the current acceleration
 *      values for all three axes.
 *
 * @return kStatus_Success or kStatusFail.
 */
mma8451_status_t mma8451_get_acceleration(mma8451_device_t * device, acceleration_t * accel);

/*!
 * @brief Read a single register of the MMA8451.
 *
 * @param device Pointer to a valid device instance structure.
 * @param reg_addr Address of the internal MMA8451 register to read.
 *
 * @return The register's value.
 */
uint8_t mma8451_read_register(mma8451_device_t * device, uint8_t reg_addr);

/*!
 * @brief Write a single register of the MMA8451.
 *
 * @param device Pointer to a valid device instance structure.
 * @param reg_addrAddress of the internal MMA8451 register to change the value of.
 * @param reg_val New value for the register.
 *
 * @return kStatus_Success or kStatusFail.
 */
mma8451_status_t mma8451_write_register(mma8451_device_t * device, uint8_t reg_addr, uint8_t reg_val);


#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /*__FSL_MMA8451_H__*/
/*******************************************************************************
 * EOF
 ******************************************************************************/
