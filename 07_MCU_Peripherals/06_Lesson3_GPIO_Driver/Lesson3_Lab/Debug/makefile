################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32_F103C6_Drivers/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Lesson3_Lab.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lesson3_Lab.list \

OBJCOPY_BIN += \
Lesson3_Lab.bin \


# All Target
all: Lesson3_Lab.elf secondary-outputs

# Tool invocations
Lesson3_Lab.elf: $(OBJS) $(USER_OBJS) G:\Git_Repositories\Embedded_Diploma\07_MCU_Peripherals\06_Lesson3_GPIO_Driver\Lesson3_Lab\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Lesson3_Lab.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"G:\Git_Repositories\Embedded_Diploma\07_MCU_Peripherals\06_Lesson3_GPIO_Driver\Lesson3_Lab\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lesson3_Lab.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lesson3_Lab.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lesson3_Lab.list"
	@echo 'Finished building: $@'
	@echo ' '

Lesson3_Lab.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Lesson3_Lab.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
