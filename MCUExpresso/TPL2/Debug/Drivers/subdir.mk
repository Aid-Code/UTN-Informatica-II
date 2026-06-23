################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/DigitalInput.cpp \
../Drivers/PerifericoTemporizado.cpp \
../Drivers/PintInt.cpp \
../Drivers/Timer.cpp \
../Drivers/gpio.cpp 

CPP_DEPS += \
./Drivers/DigitalInput.d \
./Drivers/PerifericoTemporizado.d \
./Drivers/PintInt.d \
./Drivers/Timer.d \
./Drivers/gpio.d 

OBJS += \
./Drivers/DigitalInput.o \
./Drivers/PerifericoTemporizado.o \
./Drivers/PintInt.o \
./Drivers/Timer.o \
./Drivers/gpio.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.cpp Drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\abril\Documents\GitHub\UTN-Informatica-II\MCUExpresso\TPL2\Aplicacion" -I"C:\Users\abril\Documents\GitHub\UTN-Informatica-II\MCUExpresso\TPL2\Drivers" -I"C:\Users\abril\Documents\GitHub\UTN-Informatica-II\MCUExpresso\TPL2\Firmware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers

clean-Drivers:
	-$(RM) ./Drivers/DigitalInput.d ./Drivers/DigitalInput.o ./Drivers/PerifericoTemporizado.d ./Drivers/PerifericoTemporizado.o ./Drivers/PintInt.d ./Drivers/PintInt.o ./Drivers/Timer.d ./Drivers/Timer.o ./Drivers/gpio.d ./Drivers/gpio.o

.PHONY: clean-Drivers

