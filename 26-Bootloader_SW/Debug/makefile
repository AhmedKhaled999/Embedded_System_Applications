################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
26-Bootloader_SW.lss \

FLASH_IMAGE += \
26-Bootloader_SW.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 26-Bootloader_SW.elf secondary-outputs

# Tool invocations
26-Bootloader_SW.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,26-Bootloader_SW.map -Ttext=0x7000 -mmcu=atmega32 -o "26-Bootloader_SW.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

26-Bootloader_SW.lss: 26-Bootloader_SW.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 26-Bootloader_SW.elf  >"26-Bootloader_SW.lss"
	@echo 'Finished building: $@'
	@echo ' '

26-Bootloader_SW.hex: 26-Bootloader_SW.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 26-Bootloader_SW.elf  "26-Bootloader_SW.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 26-Bootloader_SW.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 26-Bootloader_SW.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 26-Bootloader_SW.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
