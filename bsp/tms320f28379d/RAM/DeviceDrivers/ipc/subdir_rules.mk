################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
DeviceDrivers/ipc/completion.obj: E:/Documents/workspace/C/rt-thread/components/drivers/ipc/completion.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=softlib --tmu_support=tmu0 --vcu_support=vcu2 --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d" --include_path="E:/Documents/workspace/C/rt-thread/components/finsh" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/headers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/common/include" --include_path="E:/Documents/workspace/C/rt-thread/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/drivers" --include_path="E:/Documents/workspace/C/rt-thread/src" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include/drivers" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --advice:performance=all --define=CPU1 --define=_RAM --define=_LAUNCHXL_F28379D --define=RT_USING_LIBC -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="DeviceDrivers/ipc/$(basename $(<F)).d_raw" --obj_directory="DeviceDrivers/ipc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DeviceDrivers/ipc/dataqueue.obj: E:/Documents/workspace/C/rt-thread/components/drivers/ipc/dataqueue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=softlib --tmu_support=tmu0 --vcu_support=vcu2 --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d" --include_path="E:/Documents/workspace/C/rt-thread/components/finsh" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/headers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/common/include" --include_path="E:/Documents/workspace/C/rt-thread/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/drivers" --include_path="E:/Documents/workspace/C/rt-thread/src" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include/drivers" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --advice:performance=all --define=CPU1 --define=_RAM --define=_LAUNCHXL_F28379D --define=RT_USING_LIBC -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="DeviceDrivers/ipc/$(basename $(<F)).d_raw" --obj_directory="DeviceDrivers/ipc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DeviceDrivers/ipc/ringblk_buf.obj: E:/Documents/workspace/C/rt-thread/components/drivers/ipc/ringblk_buf.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=softlib --tmu_support=tmu0 --vcu_support=vcu2 --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d" --include_path="E:/Documents/workspace/C/rt-thread/components/finsh" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/headers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/common/include" --include_path="E:/Documents/workspace/C/rt-thread/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/drivers" --include_path="E:/Documents/workspace/C/rt-thread/src" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include/drivers" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --advice:performance=all --define=CPU1 --define=_RAM --define=_LAUNCHXL_F28379D --define=RT_USING_LIBC -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="DeviceDrivers/ipc/$(basename $(<F)).d_raw" --obj_directory="DeviceDrivers/ipc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DeviceDrivers/ipc/ringbuffer.obj: E:/Documents/workspace/C/rt-thread/components/drivers/ipc/ringbuffer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=softlib --tmu_support=tmu0 --vcu_support=vcu2 --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d" --include_path="E:/Documents/workspace/C/rt-thread/components/finsh" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/headers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/common/include" --include_path="E:/Documents/workspace/C/rt-thread/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/drivers" --include_path="E:/Documents/workspace/C/rt-thread/src" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include/drivers" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --advice:performance=all --define=CPU1 --define=_RAM --define=_LAUNCHXL_F28379D --define=RT_USING_LIBC -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="DeviceDrivers/ipc/$(basename $(<F)).d_raw" --obj_directory="DeviceDrivers/ipc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DeviceDrivers/ipc/waitqueue.obj: E:/Documents/workspace/C/rt-thread/components/drivers/ipc/waitqueue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=softlib --tmu_support=tmu0 --vcu_support=vcu2 --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d" --include_path="E:/Documents/workspace/C/rt-thread/components/finsh" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/headers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/common/include" --include_path="E:/Documents/workspace/C/rt-thread/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/drivers" --include_path="E:/Documents/workspace/C/rt-thread/src" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include/drivers" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --advice:performance=all --define=CPU1 --define=_RAM --define=_LAUNCHXL_F28379D --define=RT_USING_LIBC -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="DeviceDrivers/ipc/$(basename $(<F)).d_raw" --obj_directory="DeviceDrivers/ipc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DeviceDrivers/ipc/workqueue.obj: E:/Documents/workspace/C/rt-thread/components/drivers/ipc/workqueue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=softlib --tmu_support=tmu0 --vcu_support=vcu2 --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d" --include_path="E:/Documents/workspace/C/rt-thread/components/finsh" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/headers/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/libraries/common/include" --include_path="E:/Documents/workspace/C/rt-thread/include" --include_path="E:/Documents/workspace/C/rt-thread/bsp/tms320f28379d/drivers" --include_path="E:/Documents/workspace/C/rt-thread/src" --include_path="E:/Documents/workspace/C/rt-thread/components/drivers/include/drivers" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --advice:performance=all --define=CPU1 --define=_RAM --define=_LAUNCHXL_F28379D --define=RT_USING_LIBC -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="DeviceDrivers/ipc/$(basename $(<F)).d_raw" --obj_directory="DeviceDrivers/ipc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


