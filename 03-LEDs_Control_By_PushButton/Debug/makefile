################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MDIO/subdir.mk
-include HAL/HSWITCH/subdir.mk
-include HAL/HSEVEN_SEGMENT/subdir.mk
-include HAL/HLED/subdir.mk
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
03-LEDs_Control_By_PushButton.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: 03-LEDs_Control_By_PushButton.elf secondary-outputs

# Tool invocations
03-LEDs_Control_By_PushButton.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,03-LEDs_Control_By_PushButton.map -mmcu=atmega32 -o "03-LEDs_Control_By_PushButton.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

03-LEDs_Control_By_PushButton.lss: 03-LEDs_Control_By_PushButton.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 03-LEDs_Control_By_PushButton.elf  >"03-LEDs_Control_By_PushButton.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 03-LEDs_Control_By_PushButton.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 03-LEDs_Control_By_PushButton.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 03-LEDs_Control_By_PushButton.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
