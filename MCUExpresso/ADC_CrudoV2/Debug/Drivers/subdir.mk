################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/AnalogInput.cpp \
../Drivers/DigitalInput.cpp \
../Drivers/PerifericoTemporizado.cpp \
../Drivers/Timer.cpp \
../Drivers/bufferCirc.cpp \
../Drivers/gpio.cpp \
../Drivers/serialCom.cpp 

CPP_DEPS += \
./Drivers/AnalogInput.d \
./Drivers/DigitalInput.d \
./Drivers/PerifericoTemporizado.d \
./Drivers/Timer.d \
./Drivers/bufferCirc.d \
./Drivers/gpio.d \
./Drivers/serialCom.d 

OBJS += \
./Drivers/AnalogInput.o \
./Drivers/DigitalInput.o \
./Drivers/PerifericoTemporizado.o \
./Drivers/Timer.o \
./Drivers/bufferCirc.o \
./Drivers/gpio.o \
./Drivers/serialCom.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.cpp Drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\joaco\OneDrive - UTN.BA\UTN\Info 2 - Catedra\2026\10-23 ADC y DAC\ADC_CrudoV2\Aplicacion" -I"C:\Users\joaco\OneDrive - UTN.BA\UTN\Info 2 - Catedra\2026\10-23 ADC y DAC\ADC_CrudoV2\Drivers" -I"C:\Users\joaco\OneDrive - UTN.BA\UTN\Info 2 - Catedra\2026\10-23 ADC y DAC\ADC_CrudoV2\Firmware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers

clean-Drivers:
	-$(RM) ./Drivers/AnalogInput.d ./Drivers/AnalogInput.o ./Drivers/DigitalInput.d ./Drivers/DigitalInput.o ./Drivers/PerifericoTemporizado.d ./Drivers/PerifericoTemporizado.o ./Drivers/Timer.d ./Drivers/Timer.o ./Drivers/bufferCirc.d ./Drivers/bufferCirc.o ./Drivers/gpio.d ./Drivers/gpio.o ./Drivers/serialCom.d ./Drivers/serialCom.o

.PHONY: clean-Drivers

