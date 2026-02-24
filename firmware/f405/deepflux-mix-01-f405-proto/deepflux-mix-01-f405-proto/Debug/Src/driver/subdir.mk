################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/button.c \
../Src/driver/encoder.c \
../Src/driver/gpio_bare.c \
../Src/driver/timer.c 

OBJS += \
./Src/driver/button.o \
./Src/driver/encoder.o \
./Src/driver/gpio_bare.o \
./Src/driver/timer.o 

C_DEPS += \
./Src/driver/button.d \
./Src/driver/encoder.d \
./Src/driver/gpio_bare.d \
./Src/driver/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/%.o Src/driver/%.su Src/driver/%.cyclo: ../Src/driver/%.c Src/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F405xx -DSTM32 -DSTM32F4 -DSTM32F405RGTx -c -I../Inc -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f405/deepflux-mix-01-f405-proto/deepflux-mix-01-f405-proto/Inc/core" -I"C:/Users/prath/OneDrive/Desktop/DeepFlux Technologies/DeepFlux MIX-01/github/deepflux-mix01/firmware/f405/deepflux-mix-01-f405-proto/deepflux-mix-01-f405-proto/Inc/driver" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M4/STM32F405TG/Library/stm32cubef4-v1-28-0/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/prath/OneDrive/Desktop/Embedded/Arm Cortex M4/STM32F405TG/Library/stm32cubef4-v1-28-0/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver

clean-Src-2f-driver:
	-$(RM) ./Src/driver/button.cyclo ./Src/driver/button.d ./Src/driver/button.o ./Src/driver/button.su ./Src/driver/encoder.cyclo ./Src/driver/encoder.d ./Src/driver/encoder.o ./Src/driver/encoder.su ./Src/driver/gpio_bare.cyclo ./Src/driver/gpio_bare.d ./Src/driver/gpio_bare.o ./Src/driver/gpio_bare.su ./Src/driver/timer.cyclo ./Src/driver/timer.d ./Src/driver/timer.o ./Src/driver/timer.su

.PHONY: clean-Src-2f-driver

