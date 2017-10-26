/*
 * File      : stm32f7xx_rtc.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2015, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-10-25     ZYH      first implementation
 */
#include "stm32f7xx_rtc.h"
#include <board.h>
#include <rtdevice.h>
#include <time.h>
RTC_HandleTypeDef hrtc;

/* RTC init function */
void MX_RTC_Init(void)
{
  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef sDate;

    /**Initialize RTC Only 
    */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  RT_ASSERT(HAL_RTC_Init(&hrtc) == HAL_OK);
    /**Initialize RTC and set the Time and Date 
    */
  if(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) != 0x32F2){
  sTime.Hours = 22;
  sTime.Minutes = 28;
  sTime.Seconds = 0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  RT_ASSERT(HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) == HAL_OK);

  sDate.WeekDay = RTC_WEEKDAY_THURSDAY;
  sDate.Month = RTC_MONTH_OCTOBER;
  sDate.Date = 26;
  sDate.Year = 17;

  RT_ASSERT(HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) == HAL_OK);
	}
  HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR0,0x32F2);

}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */
    /* RTC clock enable */
    __HAL_RCC_RTC_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{
	
  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }
} 


static rt_err_t stm32_rtc_control(struct rt_device *dev,
                                  int              cmd,
                                  void             *args)
{
	SCB_CleanDCache();
	struct tm* now = localtime((const time_t*) args);
	RTC_TimeTypeDef sTime;
  RTC_DateTypeDef sDate;
	switch(cmd)
	{
		case RT_DEVICE_CTRL_RTC_GET_TIME:
			HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			now->tm_hour = sTime.Hours;
			now->tm_min = sTime.Minutes;
			now->tm_sec = sTime.Seconds;
			now->tm_year = sDate.Year+100;
			now->tm_mon = sDate.Month-1;
			now->tm_mday = sDate.Date;
			*((time_t*)args) = mktime(now);
			break;
		case RT_DEVICE_CTRL_RTC_SET_TIME:
			sTime.Hours = now->tm_hour;
			sTime.Minutes = now->tm_min;
			sTime.Seconds = now->tm_sec;
			sDate.Year = now->tm_year-100;
			sDate.Month = now->tm_mon+1;
			sDate.Date = now->tm_mday;
			SCB_CleanDCache();
			HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			break;
	}
	return RT_EOK;
}

struct rt_device rtc_device;

int rt_hw_rtc_init(void)
{
	MX_RTC_Init();
	
	rtc_device.type        = RT_Device_Class_RTC;
	rtc_device.rx_indicate = RT_NULL;
	rtc_device.tx_complete = RT_NULL;

	rtc_device.init        = RT_NULL;
	rtc_device.open        = RT_NULL;
	rtc_device.close       = RT_NULL;
	rtc_device.read        = RT_NULL;
	rtc_device.write       = RT_NULL;
	rtc_device.control     = stm32_rtc_control;
	rtc_device.user_data   = RT_NULL;

	/* register a character device */
	return rt_device_register(&rtc_device, "rtc", RT_DEVICE_FLAG_DEACTIVATE);
}

INIT_BOARD_EXPORT(rt_hw_rtc_init);











