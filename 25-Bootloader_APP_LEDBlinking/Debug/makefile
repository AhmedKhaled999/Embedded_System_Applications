################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include APP/subdir.mk
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
25-Bootloader_APP_LEDBlinking.lss \

FLASH_IMAGE += \
25-Bootloader_APP_LEDBlinking.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 25-Bootloader_APP_LEDBlinking.elf secondary-outputs

# Tool invocations
25-Bootloader_APP_LEDBlinking.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,25-Bootloader_APP_LEDBlinking.map -mmcu=atmega32 -o "25-Bootloader_APP_LEDBlinking.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

25-Bootloader_APP_LEDBlinking.lss: 25-Bootloader_APP_LEDBlinking.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 25-Bootloader_APP_LEDBlinking.elf  >"25-Bootloader_APP_LEDBlinking.lss"
	@echo 'Finished building: $@'
	@echo ' '

25-Bootloader_APP_LEDBlinking.hex: 25-Bootloader_APP_LEDBlinking.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 25-Bootloader_APP_LEDBlinking.elf  "25-Bootloader_APP_LEDBlinking.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 25-Bootloader_APP_LEDBlinking.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 25-Bootloader_APP_LEDBlinking.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 25-Bootloader_APP_LEDBlinking.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
