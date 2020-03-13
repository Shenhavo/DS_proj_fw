################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../wifi/winc1500/socket/source/socket.c 

OBJS += \
./wifi/winc1500/socket/source/socket.o 

C_DEPS += \
./wifi/winc1500/socket/source/socket.d 


# Each subdirectory must supply rules for building sources it contributes
wifi/winc1500/socket/source/socket.o: ../wifi/winc1500/socket/source/socket.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/socket/source/socket.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

