################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Drivers/Device_Devices/HD44780_LCD/subdir.mk
-include Drivers/Device_Devices/ADXL_345_accelerometer/subdir.mk
-include Drivers/ARM_Drivers/Delay_Micros/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ADXL 345 accelerometer
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ADXL\ 345\ accelerometer.elf \

MAP_FILES += \
ADXL\ 345\ accelerometer.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ADXL\ 345\ accelerometer.list \

OBJCOPY_HEX += \
ADXL\ 345\ accelerometer.hex \


# All Target
all: main-build

# Main-build Target
main-build: ADXL\ 345\ accelerometer.elf secondary-outputs

# Tool invocations
ADXL\ 345\ accelerometer.elf ADXL\ 345\ accelerometer.map: $(OBJS) $(USER_OBJS) C:\Users\asus\OneDrive\ -\ Helwan\ university(Engineering\ Mataria)\Desktop\UAV_Navigation_System\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ADXL 345 accelerometer.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\asus\OneDrive - Helwan university(Engineering Mataria)\Desktop\UAV_Navigation_System\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ADXL 345 accelerometer.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ADXL\ 345\ accelerometer.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ADXL 345 accelerometer.list"
	@echo 'Finished building: $@'
	@echo ' '

ADXL\ 345\ accelerometer.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "ADXL 345 accelerometer.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ADXL\ 345\ accelerometer.elf ADXL\ 345\ accelerometer.hex ADXL\ 345\ accelerometer.list ADXL\ 345\ accelerometer.map ADXL\\ 345\\ accelerometer.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
