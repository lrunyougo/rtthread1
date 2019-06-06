/*
 * The Clear BSD License
 * Copyright (c) 2018, NXP Semiconductors, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
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

#include "fsl_tempmon.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tempmon"
#endif

/*! @brief TEMPMON calibration data mask. */
#define TEMPMON_HOTTEMPMASK 0xFFU
#define TEMPMON_HOTTEMPSHIFT 0x00U
#define TEMPMON_HOTCOUNTMASK 0xFFF00U
#define TEMPMON_HOTCOUNTSHIFT 0X08U
#define TEMPMON_ROOMCOUNTMASK 0xFFF00000U
#define TEMPMON_ROOMCOUNTSHIFT 0x14U

/*! @brief the room temperature. */
#define TEMPMON_ROOMTEMP 25.0

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint32_t s_hotTemp;    /*!< The value of TEMPMON_TEMPSENSE0[TEMP_VALUE] at room temperature .*/
static uint32_t s_hotCount;   /*!< The value of TEMPMON_TEMPSENSE0[TEMP_VALUE] at the hot temperature.*/
static float s_hotT_ROOM;     /*!< The value of s_hotTemp minus room temperature(25��).*/
static uint32_t s_roomC_hotC; /*!< The value of s_roomCount minus s_hotCount.*/

/*******************************************************************************
 * Code
 ******************************************************************************/
void TEMPMON_Init(TEMPMON_Type *base, const tempmon_config_t *config)
{
    assert(NULL != config);

    uint32_t calibrationData;
    uint32_t roomCount;

    /* Power on the temperature sensor*/
    //base->TEMPSENSE0 &= ~TEMPMON_TEMPSENSE0_POWER_DOWN_MASK;
	  base->TEMPSENSE0_CLR |= TEMPMON_TEMPSENSE0_CLR_POWER_DOWN_MASK;

    /* Set temperature monitor frequency */
    //base->TEMPSENSE1 = TEMPMON_TEMPSENSE1_MEASURE_FREQ(config->frequency);
    base->TEMPSENSE1_SET |= TEMPMON_TEMPSENSE1_SET_MEASURE_FREQ(config->frequency);
	
    /* ready to read calibration data */
    calibrationData = OCOTP->ANA1;
    s_hotTemp = (uint32_t)(calibrationData & TEMPMON_HOTTEMPMASK) >> TEMPMON_HOTTEMPSHIFT;
    s_hotCount = (uint32_t)(calibrationData & TEMPMON_HOTCOUNTMASK) >> TEMPMON_HOTCOUNTSHIFT;
    roomCount = (uint32_t)(calibrationData & TEMPMON_ROOMCOUNTMASK) >> TEMPMON_ROOMCOUNTSHIFT;

    s_hotT_ROOM = s_hotTemp - TEMPMON_ROOMTEMP;
    s_roomC_hotC = roomCount - s_hotCount;

    /* Set alarm temperature */
    TEMPMON_SetTempAlarm(base, config->highAlarmTemp, kTEMPMON_HighAlarmMode);
    TEMPMON_SetTempAlarm(base, config->panicAlarmTemp, kTEMPMON_PanicAlarmMode);
    TEMPMON_SetTempAlarm(base, config->lowAlarmTemp, kTEMPMON_LowAlarmMode);
}

void TEMPMON_Deinit(TEMPMON_Type *base)
{
    base->TEMPSENSE0 |= TEMPMON_TEMPSENSE0_POWER_DOWN_MASK;
}

void TEMPMON_GetDefaultConfig(tempmon_config_t *config)
{
    assert(config);

    /* Default measure frequency */
    config->frequency = 0x03U;
    /* Default high alarm temperature */
    config->highAlarmTemp = 40U;
    /* Default panic alarm temperature */
    config->panicAlarmTemp = 90U;
    /* Default low alarm temperature */
    config->lowAlarmTemp = 20U;
}

float TEMPMON_GetCurrentTemperature(TEMPMON_Type *base)
{
    /* Check arguments */
    assert(NULL != base);

    uint32_t nmeas;
    float tmeas;

    while (!(base->TEMPSENSE0 & TEMPMON_TEMPSENSE0_FINISHED_MASK))
    {
    }

    /* ready to read temperature code value */
    nmeas = (base->TEMPSENSE0 & TEMPMON_TEMPSENSE0_TEMP_CNT_MASK) >> TEMPMON_TEMPSENSE0_TEMP_CNT_SHIFT;

    /* Calculate temperature */
    tmeas = s_hotTemp - (float)((nmeas - s_hotCount) * s_hotT_ROOM / s_roomC_hotC);

    return tmeas;
}

void TEMPMON_SetTempAlarm(TEMPMON_Type *base, uint32_t tempVal, tempmon_alarm_mode alarmMode)
{
    /* Check arguments */
    assert(NULL != base);

    uint32_t tempCodeVal;

    /* Calculate alarm temperature code value */
    tempCodeVal = (uint32_t)(s_hotCount + (s_hotTemp - tempVal) * s_roomC_hotC / s_hotT_ROOM);

    switch (alarmMode)
    {
        case kTEMPMON_HighAlarmMode:
            /* Set high alarm temperature code value */
            base->TEMPSENSE0 |= TEMPMON_TEMPSENSE0_ALARM_VALUE(tempCodeVal);
            break;

        case kTEMPMON_PanicAlarmMode:
            /* Set panic alarm temperature code value */
            base->TEMPSENSE2 |= TEMPMON_TEMPSENSE2_PANIC_ALARM_VALUE(tempCodeVal);
            break;

        case kTEMPMON_LowAlarmMode:
            /* Set low alarm temperature code value */
            base->TEMPSENSE2 |= TEMPMON_TEMPSENSE2_LOW_ALARM_VALUE(tempCodeVal);
            break;

        default:
            assert(false);
            break;
    }
}
