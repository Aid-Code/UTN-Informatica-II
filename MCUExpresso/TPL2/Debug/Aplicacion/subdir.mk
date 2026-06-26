################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aplicacion/Ejercicio1.cpp \
../Aplicacion/Ejercicio2.cpp \
../Aplicacion/Ejercicio3.cpp \
../Aplicacion/Ejercicio4.cpp \
../Aplicacion/Ejercicio4b.cpp \
../Aplicacion/Ejercicio5.cpp 

CPP_DEPS += \
./Aplicacion/Ejercicio1.d \
./Aplicacion/Ejercicio2.d \
./Aplicacion/Ejercicio3.d \
./Aplicacion/Ejercicio4.d \
./Aplicacion/Ejercicio4b.d \
./Aplicacion/Ejercicio5.d 

OBJS += \
./Aplicacion/Ejercicio1.o \
./Aplicacion/Ejercicio2.o \
./Aplicacion/Ejercicio3.o \
./Aplicacion/Ejercicio4.o \
./Aplicacion/Ejercicio4b.o \
./Aplicacion/Ejercicio5.o 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.cpp Aplicacion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\abril\OneDrive\Documentos\GitHub\UTN-Informatica-II\MCUExpresso\TPL2\Aplicacion" -I"C:\Users\abril\OneDrive\Documentos\GitHub\UTN-Informatica-II\MCUExpresso\TPL2\Drivers" -I"C:\Users\abril\OneDrive\Documentos\GitHub\UTN-Informatica-II\MCUExpresso\TPL2\Firmware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Aplicacion

clean-Aplicacion:
	-$(RM) ./Aplicacion/Ejercicio1.d ./Aplicacion/Ejercicio1.o ./Aplicacion/Ejercicio2.d ./Aplicacion/Ejercicio2.o ./Aplicacion/Ejercicio3.d ./Aplicacion/Ejercicio3.o ./Aplicacion/Ejercicio4.d ./Aplicacion/Ejercicio4.o ./Aplicacion/Ejercicio4b.d ./Aplicacion/Ejercicio4b.o ./Aplicacion/Ejercicio5.d ./Aplicacion/Ejercicio5.o

.PHONY: clean-Aplicacion

