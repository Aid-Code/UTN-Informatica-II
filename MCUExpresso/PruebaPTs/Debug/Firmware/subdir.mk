################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Firmware/Init.cpp \
../Firmware/Systick.cpp \
../Firmware/cr_cpp_config.cpp \
../Firmware/cr_startup_lpc84x.cpp 

CPP_DEPS += \
./Firmware/Init.d \
./Firmware/Systick.d \
./Firmware/cr_cpp_config.d \
./Firmware/cr_startup_lpc84x.d 

OBJS += \
./Firmware/Init.o \
./Firmware/Systick.o \
./Firmware/cr_cpp_config.o \
./Firmware/cr_startup_lpc84x.o 


# Each subdirectory must supply rules for building sources it contributes
Firmware/%.o: ../Firmware/%.cpp Firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\abril\Documentos\GitHub\UTN-Informatica-II\MCUExpresso\PruebaPTs\Aplicacion" -I"C:\Users\abril\Documentos\GitHub\UTN-Informatica-II\MCUExpresso\PruebaPTs\Drivers" -I"C:\Users\abril\Documentos\GitHub\UTN-Informatica-II\MCUExpresso\PruebaPTs\Firmware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Firmware

clean-Firmware:
	-$(RM) ./Firmware/Init.d ./Firmware/Init.o ./Firmware/Systick.d ./Firmware/Systick.o ./Firmware/cr_cpp_config.d ./Firmware/cr_cpp_config.o ./Firmware/cr_startup_lpc84x.d ./Firmware/cr_startup_lpc84x.o

.PHONY: clean-Firmware

