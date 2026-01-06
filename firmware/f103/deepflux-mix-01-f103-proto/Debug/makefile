################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/drivers/subdir.mk
-include Src/core/subdir.mk
-include Src/subdir.mk
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


BUILD_ARTIFACT_NAME := deepflux-mix-01-f103-proto
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
deepflux-mix-01-f103-proto.elf \

MAP_FILES += \
deepflux-mix-01-f103-proto.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
deepflux-mix-01-f103-proto.list \

OBJCOPY_HEX += \
deepflux-mix-01-f103-proto.hex \


# All Target
all: main-build

# Main-build Target
main-build: deepflux-mix-01-f103-proto.elf secondary-outputs

# Tool invocations
deepflux-mix-01-f103-proto.elf deepflux-mix-01-f103-proto.map: $(OBJS) $(USER_OBJS) C:\Users\prath\OneDrive\Desktop\DeepFlux\ Technologies\DeepFlux\ MIX-01\Firmware\F103\deepflux-mix-01-f103-proto\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "deepflux-mix-01-f103-proto.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\prath\OneDrive\Desktop\DeepFlux Technologies\DeepFlux MIX-01\Firmware\F103\deepflux-mix-01-f103-proto\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="deepflux-mix-01-f103-proto.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

deepflux-mix-01-f103-proto.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "deepflux-mix-01-f103-proto.list"
	@echo 'Finished building: $@'
	@echo ' '

deepflux-mix-01-f103-proto.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "deepflux-mix-01-f103-proto.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) deepflux-mix-01-f103-proto.elf deepflux-mix-01-f103-proto.hex deepflux-mix-01-f103-proto.list deepflux-mix-01-f103-proto.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
