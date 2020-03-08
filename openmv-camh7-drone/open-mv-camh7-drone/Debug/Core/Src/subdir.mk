################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/dcmi.c \
../Core/Src/debug.c \
../Core/Src/dma.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/jpeg.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/sys.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/dcmi.o \
./Core/Src/debug.o \
./Core/Src/dma.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/jpeg.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/sys.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/dcmi.d \
./Core/Src/debug.d \
./Core/Src/dma.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/jpeg.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/sys.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/dcmi.o: ../Core/Src/dcmi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/dcmi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/debug.o: ../Core/Src/debug.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/debug.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/dma.o: ../Core/Src/dma.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/gpio.o: ../Core/Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/i2c.o: ../Core/Src/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/jpeg.o: ../Core/Src/jpeg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/jpeg.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/spi.o: ../Core/Src/spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32h7xx_hal_msp.o: ../Core/Src/stm32h7xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32h7xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32h7xx_it.o: ../Core/Src/stm32h7xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32h7xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sys.o: ../Core/Src/sys.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sys.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/system_stm32h7xx.o: ../Core/Src/system_stm32h7xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32h7xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/usart.o: ../Core/Src/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp/include" -I/open-mv-camh7-drone/wifi/host_drv/bus_wrapper/include -I/open-mv-camh7-drone/wifi/host_drv/driver/include -I/open-mv-camh7-drone/wifi/host_drv/module_config/samd21 -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I/open-mv-camh7-drone/wifi/host_drv/spi_flash/include -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common/include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I/open-mv-camh7-drone/wifi/host_drv/socket/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

