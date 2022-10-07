#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

#define SOC_TMS320F28X

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_8
#define RT_THREAD_PRIORITY_MAX 8
#define RT_TICK_PER_SECOND 100
#define RT_USING_HOOK
#define RT_HOOK_USING_FUNC_PTR
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 1024

/* kservice optimization */

#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_SMALL_MEM_AS_HEAP
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "scia"
#define RT_VER_NUM 0x50000
#define ARCH_TIDSP
#define ARCH_TIDSP_C28X
#define ARCH_CPU_STACK_GROWS_UPWARD

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 2048
#define RT_MAIN_THREAD_PRIORITY 4
#define RT_USING_MSH
#define RT_USING_FINSH
#define FINSH_USING_MSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_THREAD_PRIORITY 4
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_CMD_SIZE 80
#define MSH_USING_BUILT_IN_COMMANDS
#define FINSH_USING_DESCRIPTION
#define FINSH_ARG_MAX 10

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SERIAL
#define RT_USING_SERIAL_V1
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_PIN
#define RT_USING_PWM

/* Using USB */


/* C/C++ and POSIX layer */

#define RT_LIBC_DEFAULT_TIMEZONE 8

/* POSIX (Portable Operating System Interface) layer */


/* Interprocess Communication (IPC) */


/* Socket is in the 'Network' category */


/* Network */


/* Utilities */


/* RT-Thread Utestcases */


/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */

/* JSON: JavaScript Object Notation, a lightweight data-interchange format */


/* XML: Extensible Markup Language */


/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */


/* u8g2: a monochrome graphic library */


/* PainterEngine: A cross-platform graphics application framework written in C language */


/* tools packages */


/* system packages */

/* enhanced kernel services */


/* acceleration: Assembly language or algorithmic acceleration packages */


/* CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */


/* Micrium: Micrium software products porting for RT-Thread */


/* peripheral libraries and drivers */


/* Kendryte SDK */


/* AI packages */


/* miscellaneous packages */

/* project laboratory */

/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */


/* Arduino libraries */


/* Projects */


/* Sensors */


/* Display */


/* Timing */


/* Data Processing */


/* Data Storage */

/* Communication */


/* Device Control */


/* Other */

/* Signal IO */


/* Uncategorized */

/* Hardware Drivers Config */

/* Onboard Peripheral Drivers */

/* On-chip Peripheral Drivers */

#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART1
#define BSP_USING_PWM
#define BSP_USING_PWM1

/* Basic settings for PWM1 */

#define BSP_PWM1_INIT_PERIOD 5000
#define BSP_PWM1_INIT_PULSE 3000

/* Advanced Settings for PWM1 */

#define BSP_PWM1_PHASE_ENABLE
#define BSP_PWM1_MASTER
#define BSP_PWM1_PHASE 0
#define BSP_PWM1_IT_ENABLE
#define BSP_PWM1_INTSEL_ET_CTR_ZERO
#define BSP_PWM1_INTSEL 1
#define BSP_PWM1_INT_ET_1ST
#define BSP_PWM1_INTPRD 1
#define BSP_PWM1_HSPCLKDIV1
#define BSP_PWM1_HSPCLKDIV 0
#define BSP_PWM1_CLKDIV1
#define BSP_PWM1_CLKDIV 0
#define BSP_PWM1_CTR_MODE_UPDOWN
#define BSP_PWM1_CTRMODE 2
#define BSP_PWM1_CC_CTR_ZERO
#define BSP_PWM1_LOADAMODE 0
#define BSP_PWM1_DB 100
#define BSP_USING_PWM2

/* Basic settings for PWM2 */

#define BSP_PWM2_INIT_PERIOD 10000
#define BSP_PWM2_INIT_PULSE 1000

/* Advanced Settings for PWM2 */

#define BSP_PWM2_PHASE_ENABLE
#define BSP_PWM2_SLAVE
#define BSP_PWM2_PHASE 90
#define BSP_PWM2_HSPCLKDIV1
#define BSP_PWM2_HSPCLKDIV 0
#define BSP_PWM2_CLKDIV1
#define BSP_PWM2_CLKDIV 0
#define BSP_PWM2_CTR_MODE_UPDOWN
#define BSP_PWM2_CTRMODE 2
#define BSP_PWM2_CC_CTR_ZERO
#define BSP_PWM2_LOADAMODE 0
#define BSP_PWM2_DB 100
#define BSP_USING_PWM3

/* Basic settings for PWM3 */

#define BSP_PWM3_INIT_PERIOD 10000
#define BSP_PWM3_INIT_PULSE 1000

/* Advanced Settings for PWM3 */

#define BSP_PWM3_PHASE_ENABLE
#define BSP_PWM3_SLAVE
#define BSP_PWM3_PHASE 180
#define BSP_PWM3_HSPCLKDIV1
#define BSP_PWM3_HSPCLKDIV 0
#define BSP_PWM3_CLKDIV1
#define BSP_PWM3_CLKDIV 0
#define BSP_PWM3_CTR_MODE_UPDOWN
#define BSP_PWM3_CTRMODE 2
#define BSP_PWM3_CC_CTR_ZERO
#define BSP_PWM3_LOADAMODE 0
#define BSP_PWM3_DB 100
#define BSP_USING_PWM4

/* Basic settings for PWM4 */

#define BSP_PWM4_INIT_PERIOD 10000
#define BSP_PWM4_INIT_PULSE 1000

/* Advanced Settings for PWM4 */

#define BSP_PWM4_PHASE_ENABLE
#define BSP_PWM4_SLAVE
#define BSP_PWM4_PHASE 270
#define BSP_PWM4_HSPCLKDIV1
#define BSP_PWM4_HSPCLKDIV 0
#define BSP_PWM4_CLKDIV1
#define BSP_PWM4_CLKDIV 0
#define BSP_PWM4_CTR_MODE_UPDOWN
#define BSP_PWM4_CTRMODE 2
#define BSP_PWM4_CC_CTR_ZERO
#define BSP_PWM4_LOADAMODE 0
#define BSP_PWM4_DB 100

/* Board extended module Drivers */

#include "rtconfig_project.h"

#endif
