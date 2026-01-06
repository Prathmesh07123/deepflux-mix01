################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/core/Printf_debug.c \
../Src/core/rcc.c 

OBJS += \
./Src/core/Printf_debug.o \
./Src/core/rcc.o 

C_DEPS += \
./Src/core/Printf_debug.d \
./Src/core/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Src/core/%.o Src/core/%.su Src/core/%.cyclo: ../Src/core/%.c Src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Inc/drivers" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Src/drivers" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Inc/core" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Src/core" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M3/Nucleo-STM32F103RB/Nucleo-f103rb/en.stm32cubef1/STM32Cube_FW_F1_V1.8.0/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M3/Nucleo-STM32F103RB/Nucleo-f103rb/en.stm32cubef1/STM32Cube_FW_F1_V1.8.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-core

clean-Src-2f-core:
	-$(RM) ./Src/core/Printf_debug.cyclo ./Src/core/Printf_debug.d ./Src/core/Printf_debug.o ./Src/core/Printf_debug.su ./Src/core/rcc.cyclo ./Src/core/rcc.d ./Src/core/rcc.o ./Src/core/rcc.su

.PHONY: clean-Src-2f-core

