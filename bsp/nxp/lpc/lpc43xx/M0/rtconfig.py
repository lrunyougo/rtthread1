import os

# core to be use
USE_CORE = 'CORE_M0'

# toolchains options
ARCH='arm'

CPU = 'cortex-m0'

CROSS_TOOL='keil'


# get setting from environment.
if os.getenv('RTT_CC'):
        CROSS_TOOL = os.getenv('RTT_CC')

# cross_tool provides the cross compiler
# EXEC_PATH is the compiler execute path, for example, CodeSourcery, Keil MDK, IAR
if  CROSS_TOOL == 'gcc':
    PLATFORM = 'gcc'
    EXEC_PATH = r'C:/Program Files/CodeSourcery/arm-none-eabi/bin'
elif CROSS_TOOL == 'keil':
    PLATFORM = 'armcc'
    EXEC_PATH = r'D:/Keil'
elif CROSS_TOOL == 'iar':
    PLATFORM = 'iccarm'
    EXEC_PATH = r'C:/Program Files/IAR Systems/Embedded Workbench 6.0'

if os.getenv('RTT_EXEC_PATH'):
        EXEC_PATH = os.getenv('RTT_EXEC_PATH')

#
BUILD = 'debug'

if PLATFORM == 'gcc':
    # toolchains
    PREFIX = 'arm-none-eabi-'
    CC = PREFIX + 'gcc'
    AS = PREFIX + 'gcc'
    AR = PREFIX + 'ar'
    LINK = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY = PREFIX + 'objcopy'
    DEVICE = ' -mthumb -mcpu=cortex-m0 -ffunction-sections -fdata-sections -Wall'
    CFLAGS = DEVICE
    AFLAGS = ' -c' + DEVICE + ' -x assembler-with-cpp -Wa,-mimplicit-it=thumb '
    LFLAGS = DEVICE + ' -Wl,-Map=rtthread-lpc43xx.map,-cref,-u,Reset_Handler -T rtthread-lpc43xx.ld'

    CPATH = ''
    LPATH = ''

    CFLAGS += ' -gdwarf-2'
    AFLAGS += ' -gdwarf-2'
    if BUILD == 'debug':
        CFLAGS += ' -O0'
    else:
        CFLAGS += ' -O2'

    POST_ACTION = OBJCPY + ' -O binary $TARGET rtthread.bin\n' +\
                  SIZE + ' $TARGET \n' +\
                  '../bin2C.py rtthread.bin ../M4/applications/M0_CODE.h'

elif PLATFORM == 'armcc':
    # toolchains
    CC = 'armcc'
    AS = 'armasm'
    AR = 'armar'
    LINK = 'armlink'
    TARGET_EXT = 'axf'

    DEVICE = ' --device DARMSTM'
    CFLAGS = DEVICE + ' --apcs=interwork'
    AFLAGS = DEVICE
    LFLAGS = DEVICE + ' --info sizes --info totals --info unused --info veneers --list rtthread-lpc43xx.map --scatter rtthread-lpc43xx_spifi.sct'

    CFLAGS += ' -I' + EXEC_PATH + '/ARM/RV31/INC'
    LFLAGS += ' --libpath ' + EXEC_PATH + '/ARM/RV31/LIB'

    EXEC_PATH += '/arm/bin40/'

    if BUILD == 'debug':
        CFLAGS += ' -g -O0'
        AFLAGS += ' -g'
    else:
        CFLAGS += ' -O2'

    POST_ACTION = 'fromelf --bin $TARGET --output rtthread.bin \nfromelf -z $TARGET'

elif PLATFORM == 'iccarm':
    # toolchains
    CC = 'iccarm'
    AS = 'iasmarm'
    AR = 'iarchive'
    LINK = 'ilinkarm'
    TARGET_EXT = 'out'

    CFLAGS = ' --diag_suppress Pa050'
    CFLAGS += ' --no_cse' 
    CFLAGS += ' --no_unroll' 
    CFLAGS += ' --no_inline' 
    CFLAGS += ' --no_code_motion' 
    CFLAGS += ' --no_tbaa' 
    CFLAGS += ' --no_clustering' 
    CFLAGS += ' --no_scheduling' 
    CFLAGS += ' --debug' 
    CFLAGS += ' --endian=little' 
    if USE_CORE == 'CORE_M4':
        CFLAGS += ' --cpu=Cortex-M4' 
        CFLAGS += ' --fpu=None'
    else:
        CFLAGS += ' --cpu=Cortex-M0'
    CFLAGS += ' -e' 
    CFLAGS += ' --dlib_config "' + EXEC_PATH + '/arm/INC/c/DLib_Config_Normal.h"'    
    CFLAGS += ' -Ol'    
    CFLAGS += ' --use_c++_inline'
        
    AFLAGS = ''
    AFLAGS += ' -s+' 
    AFLAGS += ' -w+' 
    AFLAGS += ' -r' 
    if USE_CORE == 'CORE_M4':
        AFLAGS += ' --cpu Cortex-M4' 
        AFLAGS += ' --fpu None' 
    else:
        AFLAGS += ' --cpu Cortex-M0' 

    LFLAGS = ' --config lpc43xx_flash.icf'
    LFLAGS += ' --redirect _Printf=_PrintfTiny' 
    LFLAGS += ' --redirect _Scanf=_ScanfSmall' 
    LFLAGS += ' --entry __iar_program_start'    

    EXEC_PATH = EXEC_PATH + '/arm/bin/'
    POST_ACTION = ''
