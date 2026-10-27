################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/Teclado/Teclado.cpp \
../Drivers/Teclado/TecladoLineal.cpp \
../Drivers/Teclado/TecladoMatricial.cpp 

CPP_DEPS += \
./Drivers/Teclado/Teclado.d \
./Drivers/Teclado/TecladoLineal.d \
./Drivers/Teclado/TecladoMatricial.d 

OBJS += \
./Drivers/Teclado/Teclado.o \
./Drivers/Teclado/TecladoLineal.o \
./Drivers/Teclado/TecladoMatricial.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Teclado/%.o: ../Drivers/Teclado/%.cpp Drivers/Teclado/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Firmware" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Drivers\Teclado" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Drivers\Display7Segs" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Drivers" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Aplicacion" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-Teclado

clean-Drivers-2f-Teclado:
	-$(RM) ./Drivers/Teclado/Teclado.d ./Drivers/Teclado/Teclado.o ./Drivers/Teclado/TecladoLineal.d ./Drivers/Teclado/TecladoLineal.o ./Drivers/Teclado/TecladoMatricial.d ./Drivers/Teclado/TecladoMatricial.o

.PHONY: clean-Drivers-2f-Teclado

