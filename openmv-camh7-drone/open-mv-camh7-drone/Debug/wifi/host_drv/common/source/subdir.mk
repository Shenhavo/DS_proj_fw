################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../wifi/host_drv/common/source/nm_common.c 

OBJS += \
./wifi/host_drv/common/source/nm_common.o 

C_DEPS += \
./wifi/host_drv/common/source/nm_common.d 


# Each subdirectory must supply rules for building sources it contributes
wifi/host_drv/common/source/nm_common.o: ../wifi/host_drv/common/source/nm_common.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/host_drv/common/source/nm_common.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

