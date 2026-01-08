################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/drivers/adc.c \
../Src/drivers/button.c \
../Src/drivers/encoder.c \
../Src/drivers/gpio.c \
../Src/drivers/timer.c 

OBJS += \
./Src/drivers/adc.o \
./Src/drivers/button.o \
./Src/drivers/encoder.o \
./Src/drivers/gpio.o \
./Src/drivers/timer.o 

C_DEPS += \
./Src/drivers/adc.d \
./Src/drivers/button.d \
./Src/drivers/encoder.d \
./Src/drivers/gpio.d \
./Src/drivers/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/drivers/%.o Src/drivers/%.su Src/drivers/%.cyclo: ../Src/drivers/%.c Src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Inc/drivers" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Src/drivers" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Inc/core" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/Firmware/F103/deepflux-mix-01-f103-proto/Src/core" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M3/Nucleo-STM32F103RB/Nucleo-f103rb/en.stm32cubef1/STM32Cube_FW_F1_V1.8.0/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M3/Nucleo-STM32F103RB/Nucleo-f103rb/en.stm32cubef1/STM32Cube_FW_F1_V1.8.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-drivers

clean-Src-2f-drivers:
	-$(RM) ./Src/drivers/adc.cyclo ./Src/drivers/adc.d ./Src/drivers/adc.o ./Src/drivers/adc.su ./Src/drivers/button.cyclo ./Src/drivers/button.d ./Src/drivers/button.o ./Src/drivers/button.su ./Src/drivers/encoder.cyclo ./Src/drivers/encoder.d ./Src/drivers/encoder.o ./Src/drivers/encoder.su ./Src/drivers/gpio.cyclo ./Src/drivers/gpio.d ./Src/drivers/gpio.o ./Src/drivers/gpio.su ./Src/drivers/timer.cyclo ./Src/drivers/timer.d ./Src/drivers/timer.o ./Src/drivers/timer.su

.PHONY: clean-Src-2f-drivers

