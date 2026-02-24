################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/core/printf_debug.c \
../Src/core/rcc.c 

OBJS += \
./Src/core/printf_debug.o \
./Src/core/rcc.o 

C_DEPS += \
./Src/core/printf_debug.d \
./Src/core/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Src/core/%.o Src/core/%.su Src/core/%.cyclo: ../Src/core/%.c Src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F405xx -DSTM32 -DSTM32F4 -DSTM32F405RGTx -c -I../Inc -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f405/deepflux-mix-01-f405-proto/deepflux-mix-01-f405-proto/Inc/core" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f405/deepflux-mix-01-f405-proto/deepflux-mix-01-f405-proto/Inc/driver" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M4/STM32F405TG/Library/stm32cubef4-v1-28-0/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M4/STM32F405TG/Library/stm32cubef4-v1-28-0/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-core

clean-Src-2f-core:
	-$(RM) ./Src/core/printf_debug.cyclo ./Src/core/printf_debug.d ./Src/core/printf_debug.o ./Src/core/printf_debug.su ./Src/core/rcc.cyclo ./Src/core/rcc.d ./Src/core/rcc.o ./Src/core/rcc.su

.PHONY: clean-Src-2f-core

