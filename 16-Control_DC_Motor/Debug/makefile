################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include HAL/HSWITCH/subdir.mk
-include HAL/HSEVEN_SEGMENT/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKPD/subdir.mk
-include HAL/HCLCD/subdir.mk
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
16-Control_DC_Motor.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: 16-Control_DC_Motor.elf secondary-outputs

# Tool invocations
16-Control_DC_Motor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,16-Control_DC_Motor.map -mmcu=atmega32 -o "16-Control_DC_Motor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

16-Control_DC_Motor.lss: 16-Control_DC_Motor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 16-Control_DC_Motor.elf  >"16-Control_DC_Motor.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 16-Control_DC_Motor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 16-Control_DC_Motor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 16-Control_DC_Motor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
