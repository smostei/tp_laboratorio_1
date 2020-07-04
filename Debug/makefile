################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include likedList/testing/src/subdir.mk
-include likedList/testing/subdir.mk
-include likedList/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: mosteiro-santiago-laboratorio-tp-1

# Tool invocations
mosteiro-santiago-laboratorio-tp-1: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C Linker'
	gcc  -o "mosteiro-santiago-laboratorio-tp-1" $(OBJS) $(USER_OBJS) $(LIBS)/Users/santiagomosteiro/eclipse-workspace/mosteiro-santiago-laboratorio-tp-1/LinkedList.a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) mosteiro-santiago-laboratorio-tp-1
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
