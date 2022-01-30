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
04-Display_Switch_State_On_CLCD.lss \

FLASH_IMAGE += \
04-Display_Switch_State_On_CLCD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 04-Display_Switch_State_On_CLCD.elf secondary-outputs

# Tool invocations
04-Display_Switch_State_On_CLCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,04-Display_Switch_State_On_CLCD.map -mmcu=atmega32 -o "04-Display_Switch_State_On_CLCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

04-Display_Switch_State_On_CLCD.lss: 04-Display_Switch_State_On_CLCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 04-Display_Switch_State_On_CLCD.elf  >"04-Display_Switch_State_On_CLCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

04-Display_Switch_State_On_CLCD.hex: 04-Display_Switch_State_On_CLCD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 04-Display_Switch_State_On_CLCD.elf  "04-Display_Switch_State_On_CLCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 04-Display_Switch_State_On_CLCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 04-Display_Switch_State_On_CLCD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 04-Display_Switch_State_On_CLCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
