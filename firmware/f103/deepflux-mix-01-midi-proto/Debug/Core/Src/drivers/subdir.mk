################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/drivers/adc.c \
../Core/Src/drivers/button.c \
../Core/Src/drivers/encoder.c \
../Core/Src/drivers/gpio_bare.c \
../Core/Src/drivers/timer.c 

OBJS += \
./Core/Src/drivers/adc.o \
./Core/Src/drivers/button.o \
./Core/Src/drivers/encoder.o \
./Core/Src/drivers/gpio_bare.o \
./Core/Src/drivers/timer.o 

C_DEPS += \
./Core/Src/drivers/adc.d \
./Core/Src/drivers/button.d \
./Core/Src/drivers/encoder.d \
./Core/Src/drivers/gpio_bare.d \
./Core/Src/drivers/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/drivers/%.o Core/Src/drivers/%.su Core/Src/drivers/%.cyclo: ../Core/Src/drivers/%.c Core/Src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f103/deepflux-mix-01-midi-proto/Middlewares/ST/STM32_USB_Device_Library/Class/MIDI/Inc" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f103/deepflux-mix-01-midi-proto/Core/Inc/core" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f103/deepflux-mix-01-midi-proto/Core/Inc/drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-drivers

clean-Core-2f-Src-2f-drivers:
	-$(RM) ./Core/Src/drivers/adc.cyclo ./Core/Src/drivers/adc.d ./Core/Src/drivers/adc.o ./Core/Src/drivers/adc.su ./Core/Src/drivers/button.cyclo ./Core/Src/drivers/button.d ./Core/Src/drivers/button.o ./Core/Src/drivers/button.su ./Core/Src/drivers/encoder.cyclo ./Core/Src/drivers/encoder.d ./Core/Src/drivers/encoder.o ./Core/Src/drivers/encoder.su ./Core/Src/drivers/gpio_bare.cyclo ./Core/Src/drivers/gpio_bare.d ./Core/Src/drivers/gpio_bare.o ./Core/Src/drivers/gpio_bare.su ./Core/Src/drivers/timer.cyclo ./Core/Src/drivers/timer.d ./Core/Src/drivers/timer.o ./Core/Src/drivers/timer.su

.PHONY: clean-Core-2f-Src-2f-drivers

