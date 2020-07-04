################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../likedList/testing/utest.c 

OBJS += \
./likedList/testing/utest.o 

C_DEPS += \
./likedList/testing/utest.d 


# Each subdirectory must supply rules for building sources it contributes
likedList/testing/%.o: ../likedList/testing/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


