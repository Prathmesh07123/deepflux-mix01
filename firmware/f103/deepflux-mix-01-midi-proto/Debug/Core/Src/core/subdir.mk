################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/core/Printf_debug.c \
../Core/Src/core/rcc.c 

OBJS += \
./Core/Src/core/Printf_debug.o \
./Core/Src/core/rcc.o 

C_DEPS += \
./Core/Src/core/Printf_debug.d \
./Core/Src/core/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/core/%.o Core/Src/core/%.su Core/Src/core/%.cyclo: ../Core/Src/core/%.c Core/Src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f103/deepflux-mix-01-midi-proto/Middlewares/ST/STM32_USB_Device_Library/Class/MIDI/Inc" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f103/deepflux-mix-01-midi-proto/Core/Inc/core" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f103/deepflux-mix-01-midi-proto/Core/Inc/drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-core

clean-Core-2f-Src-2f-core:
	-$(RM) ./Core/Src/core/Printf_debug.cyclo ./Core/Src/core/Printf_debug.d ./Core/Src/core/Printf_debug.o ./Core/Src/core/Printf_debug.su ./Core/Src/core/rcc.cyclo ./Core/Src/core/rcc.d ./Core/Src/core/rcc.o ./Core/Src/core/rcc.su

.PHONY: clean-Core-2f-Src-2f-core

