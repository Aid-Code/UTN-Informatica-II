################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Firmware/Init.cpp \
../Firmware/Systick.cpp \
../Firmware/cr_cpp_config.cpp \
../Firmware/cr_startup_lpc84x.cpp 

C_SRCS += \
../Firmware/crp.c \
../Firmware/mtb.c 

S_SRCS += \
../Firmware/aeabi_romdiv_patch.s 

CPP_DEPS += \
./Firmware/Init.d \
./Firmware/Systick.d \
./Firmware/cr_cpp_config.d \
./Firmware/cr_startup_lpc84x.d 

C_DEPS += \
./Firmware/crp.d \
./Firmware/mtb.d 

OBJS += \
./Firmware/Init.o \
./Firmware/Systick.o \
./Firmware/aeabi_romdiv_patch.o \
./Firmware/cr_cpp_config.o \
./Firmware/cr_startup_lpc84x.o \
./Firmware/crp.o \
./Firmware/mtb.o 


# Each subdirectory must supply rules for building sources it contributes
Firmware/%.o: ../Firmware/%.cpp Firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Firmware/%.o: ../Firmware/%.s Firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__NEWLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__LPC84X__ -g3 -gdwarf-4 -mcpu=cortex-m0 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Firmware/%.o: ../Firmware/%.c Firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -DCPP_USE_HEAP -D__LPC84X__ -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Firmware

clean-Firmware:
	-$(RM) ./Firmware/Init.d ./Firmware/Init.o ./Firmware/Systick.d ./Firmware/Systick.o ./Firmware/aeabi_romdiv_patch.o ./Firmware/cr_cpp_config.d ./Firmware/cr_cpp_config.o ./Firmware/cr_startup_lpc84x.d ./Firmware/cr_startup_lpc84x.o ./Firmware/crp.d ./Firmware/crp.o ./Firmware/mtb.d ./Firmware/mtb.o

.PHONY: clean-Firmware

