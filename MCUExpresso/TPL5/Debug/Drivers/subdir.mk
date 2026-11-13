################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/DigitalInput.cpp \
../Drivers/Display7Segs.cpp \
../Drivers/PerifericoTemporizado.cpp \
../Drivers/PintInt.cpp \
../Drivers/Teclado.cpp \
../Drivers/TecladoMatricial.cpp \
../Drivers/Timer.cpp \
../Drivers/gpio.cpp 

CPP_DEPS += \
./Drivers/DigitalInput.d \
./Drivers/Display7Segs.d \
./Drivers/PerifericoTemporizado.d \
./Drivers/PintInt.d \
./Drivers/Teclado.d \
./Drivers/TecladoMatricial.d \
./Drivers/Timer.d \
./Drivers/gpio.d 

OBJS += \
./Drivers/DigitalInput.o \
./Drivers/Display7Segs.o \
./Drivers/PerifericoTemporizado.o \
./Drivers/PintInt.o \
./Drivers/Teclado.o \
./Drivers/TecladoMatricial.o \
./Drivers/Timer.o \
./Drivers/gpio.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.cpp Drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -I"C:\Users\jesco\Documents\Info II\MCUXpresso_CL2026\TPL5\Aplicacion" -I"C:\Users\jesco\Documents\Info II\MCUXpresso_CL2026\TPL5\Drivers" -I"C:\Users\jesco\Documents\Info II\MCUXpresso_CL2026\TPL5\Firmware" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers

clean-Drivers:
	-$(RM) ./Drivers/DigitalInput.d ./Drivers/DigitalInput.o ./Drivers/Display7Segs.d ./Drivers/Display7Segs.o ./Drivers/PerifericoTemporizado.d ./Drivers/PerifericoTemporizado.o ./Drivers/PintInt.d ./Drivers/PintInt.o ./Drivers/Teclado.d ./Drivers/Teclado.o ./Drivers/TecladoMatricial.d ./Drivers/TecladoMatricial.o ./Drivers/Timer.d ./Drivers/Timer.o ./Drivers/gpio.d ./Drivers/gpio.o

.PHONY: clean-Drivers

