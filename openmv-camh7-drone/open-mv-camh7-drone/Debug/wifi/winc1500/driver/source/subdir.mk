################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../wifi/winc1500/driver/source/m2m_ate_mode.c \
../wifi/winc1500/driver/source/m2m_crypto.c \
../wifi/winc1500/driver/source/m2m_hif.c \
../wifi/winc1500/driver/source/m2m_ota.c \
../wifi/winc1500/driver/source/m2m_periph.c \
../wifi/winc1500/driver/source/m2m_ssl.c \
../wifi/winc1500/driver/source/m2m_wifi.c \
../wifi/winc1500/driver/source/nmasic.c \
../wifi/winc1500/driver/source/nmbus.c \
../wifi/winc1500/driver/source/nmdrv.c \
../wifi/winc1500/driver/source/nmi2c.c \
../wifi/winc1500/driver/source/nmspi.c \
../wifi/winc1500/driver/source/nmuart.c 

OBJS += \
./wifi/winc1500/driver/source/m2m_ate_mode.o \
./wifi/winc1500/driver/source/m2m_crypto.o \
./wifi/winc1500/driver/source/m2m_hif.o \
./wifi/winc1500/driver/source/m2m_ota.o \
./wifi/winc1500/driver/source/m2m_periph.o \
./wifi/winc1500/driver/source/m2m_ssl.o \
./wifi/winc1500/driver/source/m2m_wifi.o \
./wifi/winc1500/driver/source/nmasic.o \
./wifi/winc1500/driver/source/nmbus.o \
./wifi/winc1500/driver/source/nmdrv.o \
./wifi/winc1500/driver/source/nmi2c.o \
./wifi/winc1500/driver/source/nmspi.o \
./wifi/winc1500/driver/source/nmuart.o 

C_DEPS += \
./wifi/winc1500/driver/source/m2m_ate_mode.d \
./wifi/winc1500/driver/source/m2m_crypto.d \
./wifi/winc1500/driver/source/m2m_hif.d \
./wifi/winc1500/driver/source/m2m_ota.d \
./wifi/winc1500/driver/source/m2m_periph.d \
./wifi/winc1500/driver/source/m2m_ssl.d \
./wifi/winc1500/driver/source/m2m_wifi.d \
./wifi/winc1500/driver/source/nmasic.d \
./wifi/winc1500/driver/source/nmbus.d \
./wifi/winc1500/driver/source/nmdrv.d \
./wifi/winc1500/driver/source/nmi2c.d \
./wifi/winc1500/driver/source/nmspi.d \
./wifi/winc1500/driver/source/nmuart.d 


# Each subdirectory must supply rules for building sources it contributes
wifi/winc1500/driver/source/m2m_ate_mode.o: ../wifi/winc1500/driver/source/m2m_ate_mode.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_ate_mode.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/m2m_crypto.o: ../wifi/winc1500/driver/source/m2m_crypto.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_crypto.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/m2m_hif.o: ../wifi/winc1500/driver/source/m2m_hif.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_hif.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/m2m_ota.o: ../wifi/winc1500/driver/source/m2m_ota.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_ota.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/m2m_periph.o: ../wifi/winc1500/driver/source/m2m_periph.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_periph.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/m2m_ssl.o: ../wifi/winc1500/driver/source/m2m_ssl.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_ssl.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/m2m_wifi.o: ../wifi/winc1500/driver/source/m2m_wifi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/m2m_wifi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/nmasic.o: ../wifi/winc1500/driver/source/nmasic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/nmasic.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/nmbus.o: ../wifi/winc1500/driver/source/nmbus.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/nmbus.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/nmdrv.o: ../wifi/winc1500/driver/source/nmdrv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/nmdrv.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/nmi2c.o: ../wifi/winc1500/driver/source/nmi2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/nmi2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/nmspi.o: ../wifi/winc1500/driver/source/nmspi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/nmspi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
wifi/winc1500/driver/source/nmuart.o: ../wifi/winc1500/driver/source/nmuart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"../wifi/winc1500" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"wifi/winc1500/driver/source/nmuart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

