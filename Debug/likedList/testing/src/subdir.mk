################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../likedList/testing/src/Employee.c \
../likedList/testing/src/addNodeTest.c \
../likedList/testing/src/addTest.c \
../likedList/testing/src/clearTest.c \
../likedList/testing/src/cloneTest.c \
../likedList/testing/src/containsAllTest.c \
../likedList/testing/src/containsTest.c \
../likedList/testing/src/deleteLinkedListTest.c \
../likedList/testing/src/getNodeTest.c \
../likedList/testing/src/getTest.c \
../likedList/testing/src/indexOfTest.c \
../likedList/testing/src/isEmptyTest.c \
../likedList/testing/src/lenTest.c \
../likedList/testing/src/main_test.c \
../likedList/testing/src/newTest.c \
../likedList/testing/src/popTest.c \
../likedList/testing/src/pushTest.c \
../likedList/testing/src/removeTest.c \
../likedList/testing/src/setTest.c \
../likedList/testing/src/sortTest.c \
../likedList/testing/src/subListTest.c 

OBJS += \
./likedList/testing/src/Employee.o \
./likedList/testing/src/addNodeTest.o \
./likedList/testing/src/addTest.o \
./likedList/testing/src/clearTest.o \
./likedList/testing/src/cloneTest.o \
./likedList/testing/src/containsAllTest.o \
./likedList/testing/src/containsTest.o \
./likedList/testing/src/deleteLinkedListTest.o \
./likedList/testing/src/getNodeTest.o \
./likedList/testing/src/getTest.o \
./likedList/testing/src/indexOfTest.o \
./likedList/testing/src/isEmptyTest.o \
./likedList/testing/src/lenTest.o \
./likedList/testing/src/main_test.o \
./likedList/testing/src/newTest.o \
./likedList/testing/src/popTest.o \
./likedList/testing/src/pushTest.o \
./likedList/testing/src/removeTest.o \
./likedList/testing/src/setTest.o \
./likedList/testing/src/sortTest.o \
./likedList/testing/src/subListTest.o 

C_DEPS += \
./likedList/testing/src/Employee.d \
./likedList/testing/src/addNodeTest.d \
./likedList/testing/src/addTest.d \
./likedList/testing/src/clearTest.d \
./likedList/testing/src/cloneTest.d \
./likedList/testing/src/containsAllTest.d \
./likedList/testing/src/containsTest.d \
./likedList/testing/src/deleteLinkedListTest.d \
./likedList/testing/src/getNodeTest.d \
./likedList/testing/src/getTest.d \
./likedList/testing/src/indexOfTest.d \
./likedList/testing/src/isEmptyTest.d \
./likedList/testing/src/lenTest.d \
./likedList/testing/src/main_test.d \
./likedList/testing/src/newTest.d \
./likedList/testing/src/popTest.d \
./likedList/testing/src/pushTest.d \
./likedList/testing/src/removeTest.d \
./likedList/testing/src/setTest.d \
./likedList/testing/src/sortTest.d \
./likedList/testing/src/subListTest.d 


# Each subdirectory must supply rules for building sources it contributes
likedList/testing/src/%.o: ../likedList/testing/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


