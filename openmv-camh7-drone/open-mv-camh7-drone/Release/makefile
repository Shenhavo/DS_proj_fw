################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
open-mv-camh7-drone.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
open-mv-camh7-drone.list \


# All Target
all: open-mv-camh7-drone.elf secondary-outputs

# Tool invocations
open-mv-camh7-drone.elf: $(OBJS) $(USER_OBJS) C:\developments\shenhavs-code\DS_proj_fw\openmv-camh7-drone\open-mv-camh7-drone\STM32H743VITX_FLASH.ld
	arm-none-eabi-gcc -o "open-mv-camh7-drone.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\developments\shenhavs-code\DS_proj_fw\openmv-camh7-drone\open-mv-camh7-drone\STM32H743VITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="open-mv-camh7-drone.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

open-mv-camh7-drone.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "open-mv-camh7-drone.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
