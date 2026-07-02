################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aplicacion/ProyectoBase.cpp 

CPP_DEPS += \
./Aplicacion/ProyectoBase.d 

OBJS += \
./Aplicacion/ProyectoBase.o 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.cpp Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\abril\Documents\GitHub\UTN-Informatica-II\MCUExpresso\ProyectoBase\Drivers" -I"C:\Users\abril\Documents\GitHub\UTN-Informatica-II\MCUExpresso\ProyectoBase\Firmware" -I"C:\Users\abril\Documents\GitHub\UTN-Informatica-II\MCUExpresso\ProyectoBase\Aplicacion" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Aplicacion

clean-Aplicacion:
	-$(RM) ./Aplicacion/ProyectoBase.d ./Aplicacion/ProyectoBase.o

.PHONY: clean-Aplicacion

