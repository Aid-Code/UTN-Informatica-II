################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/Display7Segs/Display7Segs.cpp \
../Drivers/Display7Segs/Habilitaciones.cpp \
../Drivers/Display7Segs/HabilitacionesCD4017.cpp \
../Drivers/Display7Segs/Segmentos.cpp \
../Drivers/Display7Segs/Segmentos4511.cpp 

CPP_DEPS += \
./Drivers/Display7Segs/Display7Segs.d \
./Drivers/Display7Segs/Habilitaciones.d \
./Drivers/Display7Segs/HabilitacionesCD4017.d \
./Drivers/Display7Segs/Segmentos.d \
./Drivers/Display7Segs/Segmentos4511.d 

OBJS += \
./Drivers/Display7Segs/Display7Segs.o \
./Drivers/Display7Segs/Habilitaciones.o \
./Drivers/Display7Segs/HabilitacionesCD4017.o \
./Drivers/Display7Segs/Segmentos.o \
./Drivers/Display7Segs/Segmentos4511.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Display7Segs/%.o: ../Drivers/Display7Segs/%.cpp Drivers/Display7Segs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Firmware" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Drivers\Teclado" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Drivers\Display7Segs" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Drivers" -I"C:\Users\jesco\Documents\Info II\Guias de Ejercicios\GuiaEjerciciosTecladoDisplay\Ejercicio8\Aplicacion" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-Display7Segs

clean-Drivers-2f-Display7Segs:
	-$(RM) ./Drivers/Display7Segs/Display7Segs.d ./Drivers/Display7Segs/Display7Segs.o ./Drivers/Display7Segs/Habilitaciones.d ./Drivers/Display7Segs/Habilitaciones.o ./Drivers/Display7Segs/HabilitacionesCD4017.d ./Drivers/Display7Segs/HabilitacionesCD4017.o ./Drivers/Display7Segs/Segmentos.d ./Drivers/Display7Segs/Segmentos.o ./Drivers/Display7Segs/Segmentos4511.d ./Drivers/Display7Segs/Segmentos4511.o

.PHONY: clean-Drivers-2f-Display7Segs

