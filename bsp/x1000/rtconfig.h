#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 8
/* RT_THREAD_PRIORITY_8 is not set */
#define RT_THREAD_PRIORITY_32
/* RT_THREAD_PRIORITY_256 is not set */
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_DEBUG
#define RT_USING_OVERFLOW_CHECK
#define RT_DEBUG_INIT 0
#define RT_DEBUG_THREAD 0
#define RT_USING_HOOK
#define IDLE_THREAD_STACK_SIZE 512
/* RT_USING_TIMER_SOFT is not set */

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE
/* RT_USING_SIGNALS is not set */

/* Memory Management */

#define RT_USING_MEMPOOL
/* RT_USING_MEMHEAP is not set */
/* RT_USING_NOHEAP is not set */
#define RT_USING_SMALL_MEM
/* RT_USING_SLAB is not set */
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
/* RT_USING_INTERRUPT_INFO is not set */
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "uart2"
/* RT_USING_MODULE is not set */
#define ARCH_MIPS
#define ARCH_MIPS_XBURST

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN

/* C++ features */

/* RT_USING_CPLUSPLUS is not set */

/* Command shell */

#define RT_USING_FINSH
#define FINSH_USING_HISTORY
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_CMD_SIZE 80
/* FINSH_USING_AUTH is not set */
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
/* FINSH_USING_MSH_ONLY is not set */

/* Device virtual file system */

#define RT_USING_DFS
#define DFS_USING_WORKDIR
#define DFS_FILESYSTEMS_MAX 4
<<<<<<< HEAD
=======
#define DFS_FILESYSTEM_TYPES_MAX 2
>>>>>>> upstream/master
#define DFS_FD_MAX 4
#define RT_USING_DFS_ELMFAT

/* elm-chan's FatFs, Generic FAT Filesystem Module */

#define RT_DFS_ELM_CODE_PAGE 437
#define RT_DFS_ELM_WORD_ACCESS
/* RT_DFS_ELM_USE_LFN_0 is not set */
/* RT_DFS_ELM_USE_LFN_1 is not set */
/* RT_DFS_ELM_USE_LFN_2 is not set */
#define RT_DFS_ELM_USE_LFN_3
#define RT_DFS_ELM_USE_LFN 3
#define RT_DFS_ELM_MAX_LFN 255
#define RT_DFS_ELM_DRIVES 4
#define RT_DFS_ELM_MAX_SECTOR_SIZE 4096
/* RT_DFS_ELM_USE_ERASE is not set */
#define RT_DFS_ELM_REENTRANT
#define RT_USING_DFS_DEVFS
/* RT_USING_DFS_NET is not set */
/* RT_USING_DFS_ROMFS is not set */
/* RT_USING_DFS_RAMFS is not set */
/* RT_USING_DFS_UFFS is not set */
<<<<<<< HEAD
=======
/* RT_USING_DFS_NFS is not set */
>>>>>>> upstream/master

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SERIAL
/* RT_USING_CAN is not set */
/* RT_USING_HWTIMER is not set */
<<<<<<< HEAD
/* RT_USING_I2C is not set */
=======
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
>>>>>>> upstream/master
#define RT_USING_PIN
#define RT_USING_MTD_NOR
/* RT_USING_MTD_NAND is not set */
/* RT_USING_RTC is not set */
<<<<<<< HEAD
/* RT_USING_SDIO is not set */
/* RT_USING_SPI is not set */
/* RT_USING_WDT is not set */
=======
#define RT_USING_SDIO
/* RT_USING_SPI is not set */
/* RT_USING_WDT is not set */
/* RT_USING_WIFI is not set */

/* Using USB */

>>>>>>> upstream/master
/* RT_USING_USB_HOST is not set */
/* RT_USING_USB_DEVICE is not set */

/* POSIX layer and C standard library */

#define RT_USING_LIBC
<<<<<<< HEAD
/* RT_USING_PTHREADS is not set */
#define RT_USING_POSIX
/* RT_USING_POSIX_MMAP is not set */
/* RT_USING_POSIX_TERMIOS is not set */

/* Network stack */

/* light weight TCP/IP stack */

/* RT_USING_LWIP is not set */

/* Modbus master and slave stack */

/* RT_USING_MODBUS is not set */

/* RT-Thread UI Engine */

/* RT_USING_GUIENGINE is not set */

/* VBUS(Virtual Software BUS) */

/* RT_USING_VBUS is not set */
=======
#define RT_USING_PTHREADS
/* RT_USING_POSIX is not set */

/* Network stack */

/* light weight TCP/IP stack */

#define RT_USING_LWIP
/* RT_USING_LWIP141 is not set */
#define RT_USING_LWIP202
/* RT_USING_LWIP_IPV6 is not set */
/* RT_LWIP_IGMP is not set */
#define RT_LWIP_ICMP
/* RT_LWIP_SNMP is not set */
#define RT_LWIP_DNS
#define RT_LWIP_DHCP
#define IP_SOF_BROADCAST 1
#define IP_SOF_BROADCAST_RECV 1

/* Static IPv4 Address */

#define RT_LWIP_IPADDR "192.168.1.30"
#define RT_LWIP_GWADDR "192.168.1.1"
#define RT_LWIP_MSKADDR "255.255.255.0"
#define RT_LWIP_UDP
#define RT_LWIP_TCP
/* RT_LWIP_RAW is not set */
/* RT_LWIP_PPP is not set */
#define RT_MEMP_NUM_NETCONN 8
#define RT_LWIP_PBUF_NUM 16
#define RT_LWIP_RAW_PCB_NUM 4
#define RT_LWIP_UDP_PCB_NUM 4
#define RT_LWIP_TCP_PCB_NUM 4
#define RT_LWIP_TCP_SEG_NUM 40
#define RT_LWIP_TCP_SND_BUF 8196
#define RT_LWIP_TCP_WND 8196
#define RT_LWIP_TCPTHREAD_PRIORITY 10
#define RT_LWIP_TCPTHREAD_MBOX_SIZE 8
#define RT_LWIP_TCPTHREAD_STACKSIZE 2048
#define RT_LWIP_ETHTHREAD_PRIORITY 12
#define RT_LWIP_ETHTHREAD_STACKSIZE 1024
#define RT_LWIP_ETHTHREAD_MBOX_SIZE 8
#define RT_LWIP_REASSEMBLY_FRAG
#define LWIP_NETIF_STATUS_CALLBACK 1
#define SO_REUSE 1
#define LWIP_SO_RCVTIMEO 1
#define LWIP_SO_SNDTIMEO 1
#define LWIP_SO_RCVBUF 1

/* Modbus master and slave stack */

/* RT_USING_MODBUS is not set */
/* LWIP_USING_DHCPD is not set */
/* RT_USING_NETUTILS is not set */

/* RT-Thread UI Engine */

#define RT_USING_GUIENGINE
#define RTGUI_NAME_MAX 16
/* RTGUI_USING_TTF is not set */
#define RTGUI_USING_FONT16
#define RTGUI_USING_FONT12
/* RTGUI_USING_FONTHZ is not set */
/* RTGUI_IMAGE_XPM is not set */
#define RTGUI_IMAGE_JPEG_NONE
/* RTGUI_IMAGE_JPEG is not set */
/* RTGUI_IMAGE_TJPGD is not set */
/* RTGUI_IMAGE_PNG_NONE is not set */
/* RTGUI_IMAGE_PNG is not set */
#define RTGUI_IMAGE_LODEPNG
/* RTGUI_IMAGE_BMP is not set */
#define RTGUI_IMAGE_CONTAINER
#define RTGUI_USING_DEMO

/* VBUS(Virtual Software BUS) */

/* RT_USING_VBUS is not set */

/* Utilities */

/* RT_USING_LOGTRACE is not set */
/* RT_USING_RYM is not set */

/* RT-Thread Senior Membership Packages */

/* system packages */

/* PKG_USING_FTL_SRC is not set */
>>>>>>> upstream/master

/* RT-Thread online packages */

/* system packages */

/* PKG_USING_PARTITION is not set */
<<<<<<< HEAD
/* PKG_USING_SQLITE is not set */
=======
/* PKG_USING_PERSIMMON is not set */
/* PKG_USING_SQLITE is not set */
/* PKG_USING_RTI is not set */
>>>>>>> upstream/master

/* IoT - internet of things */

/* PKG_USING_PAHOMQTT is not set */
/* PKG_USING_WEBCLIENT is not set */
/* PKG_USING_MONGOOSE is not set */
/* PKG_USING_WEBTERMINAL is not set */
/* PKG_USING_CJSON is not set */
/* PKG_USING_EZXML is not set */
<<<<<<< HEAD

/* Marvell WiFi */

/* PKG_USING_MARVELLWIFI is not set */
=======
/* PKG_USING_NANOPB is not set */
>>>>>>> upstream/master

/* security packages */

/* PKG_USING_MBEDTLS is not set */
<<<<<<< HEAD
=======
/* PKG_USING_libsodium is not set */
/* PKG_USING_TINYCRYPT is not set */
>>>>>>> upstream/master

/* language packages */

/* PKG_USING_JERRYSCRIPT is not set */
<<<<<<< HEAD

/* multimedia packages */

/* PKG_USING_FASTLZ is not set */
=======
/* PKG_USING_MICROPYTHON is not set */

/* multimedia packages */

/* PKG_USING_OPENMV is not set */
>>>>>>> upstream/master

/* tools packages */

/* PKG_USING_CMBACKTRACE is not set */
/* PKG_USING_EASYLOGGER is not set */
/* PKG_USING_SYSTEMVIEW is not set */
<<<<<<< HEAD

/* miscellaneous packages */

=======
/* PKG_USING_IPERF is not set */

/* miscellaneous packages */

/* PKG_USING_FASTLZ is not set */
/* PKG_USING_MINILZO is not set */

/* example package: hello */

>>>>>>> upstream/master
/* PKG_USING_HELLO is not set */
#define BOARD_X1000_REALBOARD
/* RT_USING_HARD_FLOAT is not set */
/* BOARD_PHOENIX is not set */
/* BOARD_HALLEY2 is not set */
/* BOARD_HALLEY2_FIR is not set */
/* BOARD_HALLEY2_REALBOARD is not set */
#define BOARD_HALLEY2_REALBOARD_V2
/* RT_USING_UART0 is not set */
/* RT_USING_UART1 is not set */
#define RT_USING_UART2
<<<<<<< HEAD
#define RT_USING_AUDIO
#define RT_USING_CPU_FFS
=======
#define RT_USING_MSC0
#define RT_USING_MSC1
#define RT_MMCSD_STACK_SIZE 2048
#define RT_USING_I2C0
/* RT_USING_I2C1 is not set */
/* RT_USING_I2C2 is not set */
#define RT_USING_SLCD
#define RT_USING_ILI9488
/* RT_USING_ILI9341 is not set */
/* RT_USING_OTM4802 is not set */
/* RT_USING_TRULY_TFT240240 is not set */
#define RT_USING_TOUCH
#define RT_USING_GT9XX
/* RT_USING_FT6x06 is not set */
#define RT_TOUCH_THREAD_PRIORITY 10
#define RT_USING_AUDIO
#define RT_USING_ICODEC
#define RT_USING_CPU_FFS
/* WIFI_USING_AP6212 is not set */
/* WIFI_USING_AP6181 is not set */
>>>>>>> upstream/master

#endif
