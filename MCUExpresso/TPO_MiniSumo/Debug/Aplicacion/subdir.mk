################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aplicacion/TPO_MiniSumo.cpp 

CPP_DEPS += \
./Aplicacion/TPO_MiniSumo.d 

OBJS += \
./Aplicacion/TPO_MiniSumo.o 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.cpp Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\Franko Dona\Documents\GitHub\UTN-Informatica-II\MCUExpresso\TPO_MiniSumo\Drivers" -I"C:\Users\Franko Dona\Documents\GitHub\UTN-Informatica-II\MCUExpresso\TPO_MiniSumo\Firmware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Aplicacion

clean-Aplicacion:
	-$(RM) ./Aplicacion/TPO_MiniSumo.d ./Aplicacion/TPO_MiniSumo.o

.PHONY: clean-Aplicacion

