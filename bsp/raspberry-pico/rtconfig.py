import os
import sys

# toolchains options
ARCH='arm'
CPU='cortex-m0-dual'
CROSS_TOOL='gcc'

# bsp lib config
BSP_LIBRARY_TYPE = None

if os.getenv('RTT_CC'):
    CROSS_TOOL = os.getenv('RTT_CC')
if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')

# cross_tool provides the cross compiler
# EXEC_PATH is the compiler execute path, for example, CodeSourcery, Keil MDK, IAR
if  CROSS_TOOL == 'gcc':
    PLATFORM    = 'gcc'
    EXEC_PATH   = r'/usr/bin'
    # EXEC_PATH   = r'C:\RT-ThreadStudio\repo\Extract\ToolChain_Support_Packages\ARM\GNU_Tools_for_ARM_Embedded_Processors\5.4.1\bin'
elif CROSS_TOOL == 'keil':
    PLATFORM    = 'armcc'
    EXEC_PATH   = r'C:/Keil_v5'
elif CROSS_TOOL == 'iar':
    PLATFORM    = 'iccarm'
    EXEC_PATH   = r'C:/Program Files (x86)/IAR Systems/Embedded Workbench 8.3'

if os.getenv('RTT_EXEC_PATH'):
    EXEC_PATH = os.getenv('RTT_EXEC_PATH')

BUILD = 'debug'

if PLATFORM == 'gcc':
    # toolchains
    PREFIX = 'arm-none-eabi-'
    CC = PREFIX + 'gcc'
    AS = PREFIX + 'gcc'
    AR = PREFIX + 'ar'
    CXX = PREFIX + 'g++'
    LINK = PREFIX + 'gcc'
    TARGET_EXT = 'elf'
    SIZE = PREFIX + 'size'
    OBJDUMP = PREFIX + 'objdump'
    OBJCPY = PREFIX + 'objcopy'

# /usr/bin/arm-none-eabi-g++  -march=armv6-m -mcpu=cortex-m0plus -mthumb -Og -g -Wl,--build-id=none --specs=nosys.specs -Wl,--wrap=sprintf -Wl,--wrap=snprintf -Wl,--wrap=vsnprintf -Wl,--wrap=__clzsi2 -Wl,--wrap=__clzdi2 -Wl,--wrap=__ctzsi2 -Wl,--wrap=__ctzdi2 -Wl,--wrap=__popcountsi2 -Wl,--wrap=__popcountdi2 -Wl,--wrap=__clz -Wl,--wrap=__clzl -Wl,--wrap=__clzll -Wl,--wrap=__aeabi_idiv -Wl,--wrap=__aeabi_idivmod -Wl,--wrap=__aeabi_ldivmod -Wl,--wrap=__aeabi_uidiv -Wl,--wrap=__aeabi_uidivmod -Wl,--wrap=__aeabi_uldivmod -Wl,--wrap=__aeabi_dadd -Wl,--wrap=__aeabi_ddiv -Wl,--wrap=__aeabi_dmul -Wl,--wrap=__aeabi_drsub -Wl,--wrap=__aeabi_dsub -Wl,--wrap=__aeabi_cdcmpeq -Wl,--wrap=__aeabi_cdrcmple -Wl,--wrap=__aeabi_cdcmple -Wl,--wrap=__aeabi_dcmpeq -Wl,--wrap=__aeabi_dcmplt -Wl,--wrap=__aeabi_dcmple -Wl,--wrap=__aeabi_dcmpge -Wl,--wrap=__aeabi_dcmpgt -Wl,--wrap=__aeabi_dcmpun -Wl,--wrap=__aeabi_i2d -Wl,--wrap=__aeabi_l2d -Wl,--wrap=__aeabi_ui2d -Wl,--wrap=__aeabi_ul2d -Wl,--wrap=__aeabi_d2iz -Wl,--wrap=__aeabi_d2lz -Wl,--wrap=__aeabi_d2uiz -Wl,--wrap=__aeabi_d2ulz -Wl,--wrap=__aeabi_d2f -Wl,--wrap=sqrt -Wl,--wrap=cos -Wl,--wrap=sin -Wl,--wrap=tan -Wl,--wrap=atan2 -Wl,--wrap=exp -Wl,--wrap=log -Wl,--wrap=ldexp -Wl,--wrap=copysign -Wl,--wrap=trunc -Wl,--wrap=floor -Wl,--wrap=ceil -Wl,--wrap=round -Wl,--wrap=sincos -Wl,--wrap=asin -Wl,--wrap=acos -Wl,--wrap=atan -Wl,--wrap=sinh -Wl,--wrap=cosh -Wl,--wrap=tanh -Wl,--wrap=asinh -Wl,--wrap=acosh -Wl,--wrap=atanh -Wl,--wrap=exp2 -Wl,--wrap=log2 -Wl,--wrap=exp10 -Wl,--wrap=log10 -Wl,--wrap=pow -Wl,--wrap=powint -Wl,--wrap=hypot -Wl,--wrap=cbrt -Wl,--wrap=fmod -Wl,--wrap=drem -Wl,--wrap=remainder -Wl,--wrap=remquo -Wl,--wrap=expm1 -Wl,--wrap=log1p -Wl,--wrap=fma -Wl,--wrap=__aeabi_lmul -Wl,--wrap=__aeabi_fadd -Wl,--wrap=__aeabi_fdiv -Wl,--wrap=__aeabi_fmul -Wl,--wrap=__aeabi_frsub -Wl,--wrap=__aeabi_fsub -Wl,--wrap=__aeabi_cfcmpeq -Wl,--wrap=__aeabi_cfrcmple -Wl,--wrap=__aeabi_cfcmple -Wl,--wrap=__aeabi_fcmpeq -Wl,--wrap=__aeabi_fcmplt -Wl,--wrap=__aeabi_fcmple -Wl,--wrap=__aeabi_fcmpge -Wl,--wrap=__aeabi_fcmpgt -Wl,--wrap=__aeabi_fcmpun -Wl,--wrap=__aeabi_i2f -Wl,--wrap=__aeabi_l2f -Wl,--wrap=__aeabi_ui2f -Wl,--wrap=__aeabi_ul2f -Wl,--wrap=__aeabi_f2iz -Wl,--wrap=__aeabi_f2lz -Wl,--wrap=__aeabi_f2uiz -Wl,--wrap=__aeabi_f2ulz -Wl,--wrap=__aeabi_f2d -Wl,--wrap=sqrtf -Wl,--wrap=cosf -Wl,--wrap=sinf -Wl,--wrap=tanf -Wl,--wrap=atan2f -Wl,--wrap=expf -Wl,--wrap=logf -Wl,--wrap=ldexpf -Wl,--wrap=copysignf -Wl,--wrap=truncf -Wl,--wrap=floorf -Wl,--wrap=ceilf -Wl,--wrap=roundf -Wl,--wrap=sincosf -Wl,--wrap=asinf -Wl,--wrap=acosf -Wl,--wrap=atanf -Wl,--wrap=sinhf -Wl,--wrap=coshf -Wl,--wrap=tanhf -Wl,--wrap=asinhf -Wl,--wrap=acoshf -Wl,--wrap=atanhf -Wl,--wrap=exp2f -Wl,--wrap=log2f -Wl,--wrap=exp10f -Wl,--wrap=log10f -Wl,--wrap=powf -Wl,--wrap=powintf -Wl,--wrap=hypotf -Wl,--wrap=cbrtf -Wl,--wrap=fmodf -Wl,--wrap=dremf -Wl,--wrap=remainderf -Wl,--wrap=remquof -Wl,--wrap=expm1f -Wl,--wrap=log1pf -Wl,--wrap=fmaf -Wl,--wrap=malloc -Wl,--wrap=calloc -Wl,--wrap=free -Wl,--wrap=memcpy -Wl,--wrap=memset -Wl,--wrap=__aeabi_memcpy -Wl,--wrap=__aeabi_memset -Wl,--wrap=__aeabi_memcpy4 -Wl,--wrap=__aeabi_memset4 -Wl,--wrap=__aeabi_memcpy8 -Wl,--wrap=__aeabi_memset8 -Wl,-Map=blink.elf.map -Wl,--script=/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_standard_link/memmap_default.ld -Wl,--gc-sections -Wl,--wrap=printf -Wl,--wrap=vprintf -Wl,--wrap=puts -Wl,--wrap=putchar CMakeFiles/blink.dir/blink.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_divider/divider.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_time/time.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_sync/sem.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_sync/mutex.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_util/datetime.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_util/pheap.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/common/pico_util/queue.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_printf/printf.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_bit_ops/bit_ops_aeabi.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_divider/divider.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_double/double_aeabi.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_double/double_math.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_double/double_v1_rom_shim.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_int64_ops/pico_int64_ops_aeabi.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_float/float_aeabi.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_float/float_math.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_float/float_v1_rom_shim.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_mem_ops/mem_ops_aeabi.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_standard_link/crt0.S.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c.obj CMakeFiles/blink.dir/home/henson/Documents/rasp-pico/pico/pico-sdk/src/rp2_common/pico_stdio_uart/stdio_uart.c.obj  -o blink.elf  ../pico_sdk/src/rp2_common/boot_stage2/bs2_default_padded_checksummed.S 

#   -march=armv6-m -mcpu=cortex-m0plus -mthumb -Og -g   -ffunction-sections -fdata-sections
    DEVICE = ' -march=armv6-m -mcpu=cortex-m0plus -mthumb -ffunction-sections -fdata-sections'
    CFLAGS = DEVICE + ' -Dgcc'
    AFLAGS = ' -c' + DEVICE + ' -x assembler-with-cpp -Wa,-mimplicit-it=thumb -ILibraries/pico-sdk/src/common/pico_stdlib/include -ILibraries/pico-sdk/src/rp2_common/hardware_gpio/include -ILibraries/pico-sdk/src/common/pico_base/include -ILibraries/generated/pico_base -ILibraries/pico-sdk/src/boards/include -ILibraries/pico-sdk/src/rp2_common/pico_platform/include -ILibraries/pico-sdk/src/rp2040/hardware_regs/include -ILibraries/pico-sdk/src/rp2_common/hardware_base/include -ILibraries/pico-sdk/src/rp2040/hardware_structs/include -ILibraries/pico-sdk/src/rp2_common/hardware_claim/include -ILibraries/pico-sdk/src/rp2_common/hardware_sync/include -ILibraries/pico-sdk/src/rp2_common/hardware_uart/include -ILibraries/pico-sdk/src/rp2_common/hardware_divider/include -ILibraries/pico-sdk/src/common/pico_time/include -ILibraries/pico-sdk/src/rp2_common/hardware_timer/include -ILibraries/pico-sdk/src/common/pico_sync/include -ILibraries/pico-sdk/src/common/pico_util/include -ILibraries/pico-sdk/src/rp2_common/pico_runtime/include -ILibraries/pico-sdk/src/rp2_common/hardware_clocks/include -ILibraries/pico-sdk/src/rp2_common/hardware_resets/include -ILibraries/pico-sdk/src/rp2_common/hardware_watchdog/include -ILibraries/pico-sdk/src/rp2_common/hardware_xosc/include -ILibraries/pico-sdk/src/rp2_common/hardware_pll/include -ILibraries/pico-sdk/src/rp2_common/hardware_vreg/include -ILibraries/pico-sdk/src/rp2_common/hardware_irq/include -ILibraries/pico-sdk/src/rp2_common/pico_printf/include -ILibraries/pico-sdk/src/rp2_common/pico_bootrom/include -ILibraries/pico-sdk/src/common/pico_bit_ops/include -ILibraries/pico-sdk/src/common/pico_divider/include -ILibraries/pico-sdk/src/rp2_common/pico_double/include -ILibraries/pico-sdk/src/rp2_common/pico_int64_ops/include -ILibraries/pico-sdk/src/rp2_common/pico_float/include -ILibraries/pico-sdk/src/common/pico_binary_info/include -ILibraries/pico-sdk/src/rp2_common/pico_stdio/include -ILibraries/pico-sdk/src/rp2_common/pico_stdio_uart/include'
    LFLAGS = DEVICE + ' -Wl,-Map=rt-thread.map,-cref,-u,Reset_Handler -T link.ld' + ' -Wl,--build-id=none --specs=nosys.specs -Wl,--wrap=sprintf -Wl,--wrap=snprintf -Wl,--wrap=vsnprintf -Wl,--wrap=__clzsi2 -Wl,--wrap=__clzdi2 -Wl,--wrap=__ctzsi2 -Wl,--wrap=__ctzdi2 -Wl,--wrap=__popcountsi2 -Wl,--wrap=__popcountdi2 -Wl,--wrap=__clz -Wl,--wrap=__clzl -Wl,--wrap=__clzll -Wl,--wrap=__aeabi_idiv -Wl,--wrap=__aeabi_idivmod -Wl,--wrap=__aeabi_ldivmod -Wl,--wrap=__aeabi_uidiv -Wl,--wrap=__aeabi_uidivmod -Wl,--wrap=__aeabi_uldivmod -Wl,--wrap=__aeabi_dadd -Wl,--wrap=__aeabi_ddiv -Wl,--wrap=__aeabi_dmul -Wl,--wrap=__aeabi_drsub -Wl,--wrap=__aeabi_dsub -Wl,--wrap=__aeabi_cdcmpeq -Wl,--wrap=__aeabi_cdrcmple -Wl,--wrap=__aeabi_cdcmple -Wl,--wrap=__aeabi_dcmpeq -Wl,--wrap=__aeabi_dcmplt -Wl,--wrap=__aeabi_dcmple -Wl,--wrap=__aeabi_dcmpge -Wl,--wrap=__aeabi_dcmpgt -Wl,--wrap=__aeabi_dcmpun -Wl,--wrap=__aeabi_i2d -Wl,--wrap=__aeabi_l2d -Wl,--wrap=__aeabi_ui2d -Wl,--wrap=__aeabi_ul2d -Wl,--wrap=__aeabi_d2iz -Wl,--wrap=__aeabi_d2lz -Wl,--wrap=__aeabi_d2uiz -Wl,--wrap=__aeabi_d2ulz -Wl,--wrap=__aeabi_d2f -Wl,--wrap=sqrt -Wl,--wrap=cos -Wl,--wrap=sin -Wl,--wrap=tan -Wl,--wrap=atan2 -Wl,--wrap=exp -Wl,--wrap=log -Wl,--wrap=ldexp -Wl,--wrap=copysign -Wl,--wrap=trunc -Wl,--wrap=floor -Wl,--wrap=ceil -Wl,--wrap=round -Wl,--wrap=sincos -Wl,--wrap=asin -Wl,--wrap=acos -Wl,--wrap=atan -Wl,--wrap=sinh -Wl,--wrap=cosh -Wl,--wrap=tanh -Wl,--wrap=asinh -Wl,--wrap=acosh -Wl,--wrap=atanh -Wl,--wrap=exp2 -Wl,--wrap=log2 -Wl,--wrap=exp10 -Wl,--wrap=log10 -Wl,--wrap=pow -Wl,--wrap=powint -Wl,--wrap=hypot -Wl,--wrap=cbrt -Wl,--wrap=fmod -Wl,--wrap=drem -Wl,--wrap=remainder -Wl,--wrap=remquo -Wl,--wrap=expm1 -Wl,--wrap=log1p -Wl,--wrap=fma -Wl,--wrap=__aeabi_lmul -Wl,--wrap=__aeabi_fadd -Wl,--wrap=__aeabi_fdiv -Wl,--wrap=__aeabi_fmul -Wl,--wrap=__aeabi_frsub -Wl,--wrap=__aeabi_fsub -Wl,--wrap=__aeabi_cfcmpeq -Wl,--wrap=__aeabi_cfrcmple -Wl,--wrap=__aeabi_cfcmple -Wl,--wrap=__aeabi_fcmpeq -Wl,--wrap=__aeabi_fcmplt -Wl,--wrap=__aeabi_fcmple -Wl,--wrap=__aeabi_fcmpge -Wl,--wrap=__aeabi_fcmpgt -Wl,--wrap=__aeabi_fcmpun -Wl,--wrap=__aeabi_i2f -Wl,--wrap=__aeabi_l2f -Wl,--wrap=__aeabi_ui2f -Wl,--wrap=__aeabi_ul2f -Wl,--wrap=__aeabi_f2iz -Wl,--wrap=__aeabi_f2lz -Wl,--wrap=__aeabi_f2uiz -Wl,--wrap=__aeabi_f2ulz -Wl,--wrap=__aeabi_f2d -Wl,--wrap=sqrtf -Wl,--wrap=cosf -Wl,--wrap=sinf -Wl,--wrap=tanf -Wl,--wrap=atan2f -Wl,--wrap=expf -Wl,--wrap=logf -Wl,--wrap=ldexpf -Wl,--wrap=copysignf -Wl,--wrap=truncf -Wl,--wrap=floorf -Wl,--wrap=ceilf -Wl,--wrap=roundf -Wl,--wrap=sincosf -Wl,--wrap=asinf -Wl,--wrap=acosf -Wl,--wrap=atanf -Wl,--wrap=sinhf -Wl,--wrap=coshf -Wl,--wrap=tanhf -Wl,--wrap=asinhf -Wl,--wrap=acoshf -Wl,--wrap=atanhf -Wl,--wrap=exp2f -Wl,--wrap=log2f -Wl,--wrap=exp10f -Wl,--wrap=log10f -Wl,--wrap=powf -Wl,--wrap=powintf -Wl,--wrap=hypotf -Wl,--wrap=cbrtf -Wl,--wrap=fmodf -Wl,--wrap=dremf -Wl,--wrap=remainderf -Wl,--wrap=remquof -Wl,--wrap=expm1f -Wl,--wrap=log1pf -Wl,--wrap=fmaf -Wl,--wrap=malloc -Wl,--wrap=calloc -Wl,--wrap=free -Wl,--wrap=memcpy -Wl,--wrap=memset -Wl,--wrap=__aeabi_memcpy -Wl,--wrap=__aeabi_memset -Wl,--wrap=__aeabi_memcpy4 -Wl,--wrap=__aeabi_memset4 -Wl,--wrap=__aeabi_memcpy8 -Wl,--wrap=__aeabi_memset8 -Wl,--gc-sections -Wl,--wrap=printf -Wl,--wrap=vprintf -Wl,--wrap=puts -Wl,--wrap=putchar'

    CPATH = ''
    LPATH = ''

    if BUILD == 'debug':
        CFLAGS += ' -O0 -gdwarf-2 -g'
        AFLAGS += ' -gdwarf-2'
    else:
        CFLAGS += ' -O2'

    CXXFLAGS = CFLAGS #+ ' -Wl,--build-id=none --specs=nosys.specs -Wl,--wrap=sprintf -Wl,--wrap=snprintf -Wl,--wrap=vsnprintf -Wl,--wrap=__clzsi2 -Wl,--wrap=__clzdi2 -Wl,--wrap=__ctzsi2 -Wl,--wrap=__ctzdi2 -Wl,--wrap=__popcountsi2 -Wl,--wrap=__popcountdi2 -Wl,--wrap=__clz -Wl,--wrap=__clzl -Wl,--wrap=__clzll -Wl,--wrap=__aeabi_idiv -Wl,--wrap=__aeabi_idivmod -Wl,--wrap=__aeabi_ldivmod -Wl,--wrap=__aeabi_uidiv -Wl,--wrap=__aeabi_uidivmod -Wl,--wrap=__aeabi_uldivmod -Wl,--wrap=__aeabi_dadd -Wl,--wrap=__aeabi_ddiv -Wl,--wrap=__aeabi_dmul -Wl,--wrap=__aeabi_drsub -Wl,--wrap=__aeabi_dsub -Wl,--wrap=__aeabi_cdcmpeq -Wl,--wrap=__aeabi_cdrcmple -Wl,--wrap=__aeabi_cdcmple -Wl,--wrap=__aeabi_dcmpeq -Wl,--wrap=__aeabi_dcmplt -Wl,--wrap=__aeabi_dcmple -Wl,--wrap=__aeabi_dcmpge -Wl,--wrap=__aeabi_dcmpgt -Wl,--wrap=__aeabi_dcmpun -Wl,--wrap=__aeabi_i2d -Wl,--wrap=__aeabi_l2d -Wl,--wrap=__aeabi_ui2d -Wl,--wrap=__aeabi_ul2d -Wl,--wrap=__aeabi_d2iz -Wl,--wrap=__aeabi_d2lz -Wl,--wrap=__aeabi_d2uiz -Wl,--wrap=__aeabi_d2ulz -Wl,--wrap=__aeabi_d2f -Wl,--wrap=sqrt -Wl,--wrap=cos -Wl,--wrap=sin -Wl,--wrap=tan -Wl,--wrap=atan2 -Wl,--wrap=exp -Wl,--wrap=log -Wl,--wrap=ldexp -Wl,--wrap=copysign -Wl,--wrap=trunc -Wl,--wrap=floor -Wl,--wrap=ceil -Wl,--wrap=round -Wl,--wrap=sincos -Wl,--wrap=asin -Wl,--wrap=acos -Wl,--wrap=atan -Wl,--wrap=sinh -Wl,--wrap=cosh -Wl,--wrap=tanh -Wl,--wrap=asinh -Wl,--wrap=acosh -Wl,--wrap=atanh -Wl,--wrap=exp2 -Wl,--wrap=log2 -Wl,--wrap=exp10 -Wl,--wrap=log10 -Wl,--wrap=pow -Wl,--wrap=powint -Wl,--wrap=hypot -Wl,--wrap=cbrt -Wl,--wrap=fmod -Wl,--wrap=drem -Wl,--wrap=remainder -Wl,--wrap=remquo -Wl,--wrap=expm1 -Wl,--wrap=log1p -Wl,--wrap=fma -Wl,--wrap=__aeabi_lmul -Wl,--wrap=__aeabi_fadd -Wl,--wrap=__aeabi_fdiv -Wl,--wrap=__aeabi_fmul -Wl,--wrap=__aeabi_frsub -Wl,--wrap=__aeabi_fsub -Wl,--wrap=__aeabi_cfcmpeq -Wl,--wrap=__aeabi_cfrcmple -Wl,--wrap=__aeabi_cfcmple -Wl,--wrap=__aeabi_fcmpeq -Wl,--wrap=__aeabi_fcmplt -Wl,--wrap=__aeabi_fcmple -Wl,--wrap=__aeabi_fcmpge -Wl,--wrap=__aeabi_fcmpgt -Wl,--wrap=__aeabi_fcmpun -Wl,--wrap=__aeabi_i2f -Wl,--wrap=__aeabi_l2f -Wl,--wrap=__aeabi_ui2f -Wl,--wrap=__aeabi_ul2f -Wl,--wrap=__aeabi_f2iz -Wl,--wrap=__aeabi_f2lz -Wl,--wrap=__aeabi_f2uiz -Wl,--wrap=__aeabi_f2ulz -Wl,--wrap=__aeabi_f2d -Wl,--wrap=sqrtf -Wl,--wrap=cosf -Wl,--wrap=sinf -Wl,--wrap=tanf -Wl,--wrap=atan2f -Wl,--wrap=expf -Wl,--wrap=logf -Wl,--wrap=ldexpf -Wl,--wrap=copysignf -Wl,--wrap=truncf -Wl,--wrap=floorf -Wl,--wrap=ceilf -Wl,--wrap=roundf -Wl,--wrap=sincosf -Wl,--wrap=asinf -Wl,--wrap=acosf -Wl,--wrap=atanf -Wl,--wrap=sinhf -Wl,--wrap=coshf -Wl,--wrap=tanhf -Wl,--wrap=asinhf -Wl,--wrap=acoshf -Wl,--wrap=atanhf -Wl,--wrap=exp2f -Wl,--wrap=log2f -Wl,--wrap=exp10f -Wl,--wrap=log10f -Wl,--wrap=powf -Wl,--wrap=powintf -Wl,--wrap=hypotf -Wl,--wrap=cbrtf -Wl,--wrap=fmodf -Wl,--wrap=dremf -Wl,--wrap=remainderf -Wl,--wrap=remquof -Wl,--wrap=expm1f -Wl,--wrap=log1pf -Wl,--wrap=fmaf -Wl,--wrap=malloc -Wl,--wrap=calloc -Wl,--wrap=free -Wl,--wrap=memcpy -Wl,--wrap=memset -Wl,--wrap=__aeabi_memcpy -Wl,--wrap=__aeabi_memset -Wl,--wrap=__aeabi_memcpy4 -Wl,--wrap=__aeabi_memset4 -Wl,--wrap=__aeabi_memcpy8 -Wl,--wrap=__aeabi_memset8 -Wl,--gc-sections -Wl,--wrap=printf -Wl,--wrap=vprintf -Wl,--wrap=puts -Wl,--wrap=putchar'

    POST_ACTION = OBJCPY + ' -O binary $TARGET rtthread.bin\n' + SIZE + ' $TARGET \n'
    if "linux" in sys.platform:
        elf2uf2_path = os.path.join(os.getcwd(), "tools", "elf2uf2")
        os.system("chmod +x {0}".format(elf2uf2_path))
    else:
        elf2uf2_path = os.path.join(os.getcwd(), "tools", "elf2uf2.exe")
    POST_ACTION += "{0} rtthread-pico.elf rtthread-pico.uf2".format(elf2uf2_path) 
