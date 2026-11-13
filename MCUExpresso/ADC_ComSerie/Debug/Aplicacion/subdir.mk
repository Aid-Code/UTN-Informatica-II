################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aplicacion/ADC_Crudo.cpp 

CPP_DEPS += \
./Aplicacion/ADC_Crudo.d 

OBJS += \
./Aplicacion/ADC_Crudo.o 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.cpp Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\joaco\OneDrive - UTN.BA\UTN\Info 2 - Catedra\2026\10-23 ADC y DAC\ADC_ComSerie\Drivers" -I"C:\Users\joaco\OneDrive - UTN.BA\UTN\Info 2 - Catedra\2026\10-23 ADC y DAC\ADC_ComSerie\Firmware" -I"C:\Users\joaco\OneDrive - UTN.BA\UTN\Info 2 - Catedra\2026\10-23 ADC y DAC\ADC_ComSerie\Aplicacion" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Aplicacion

clean-Aplicacion:
	-$(RM) ./Aplicacion/ADC_Crudo.d ./Aplicacion/ADC_Crudo.o

.PHONY: clean-Aplicacion

