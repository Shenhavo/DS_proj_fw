################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../winc1500/common/source/nm_common.c 

OBJS += \
./winc1500/common/source/nm_common.o 

C_DEPS += \
./winc1500/common/source/nm_common.d 


# Each subdirectory must supply rules for building sources it contributes
winc1500/common/source/nm_common.o: ../winc1500/common/source/nm_common.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/common/source/nm_common.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

