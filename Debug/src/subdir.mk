################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Person.cpp \
../src/PhoneBook.cpp \
../src/PhonebookBST.cpp 

OBJS += \
./src/Person.o \
./src/PhoneBook.o \
./src/PhonebookBST.o 

CPP_DEPS += \
./src/Person.d \
./src/PhoneBook.d \
./src/PhonebookBST.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


