################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../winc1500/driver/source/m2m_ate_mode.c \
../winc1500/driver/source/m2m_crypto.c \
../winc1500/driver/source/m2m_hif.c \
../winc1500/driver/source/m2m_ota.c \
../winc1500/driver/source/m2m_periph.c \
../winc1500/driver/source/m2m_ssl.c \
../winc1500/driver/source/m2m_wifi.c \
../winc1500/driver/source/nmasic.c \
../winc1500/driver/source/nmbus.c \
../winc1500/driver/source/nmdrv.c \
../winc1500/driver/source/nmi2c.c \
../winc1500/driver/source/nmspi.c \
../winc1500/driver/source/nmuart.c 

OBJS += \
./winc1500/driver/source/m2m_ate_mode.o \
./winc1500/driver/source/m2m_crypto.o \
./winc1500/driver/source/m2m_hif.o \
./winc1500/driver/source/m2m_ota.o \
./winc1500/driver/source/m2m_periph.o \
./winc1500/driver/source/m2m_ssl.o \
./winc1500/driver/source/m2m_wifi.o \
./winc1500/driver/source/nmasic.o \
./winc1500/driver/source/nmbus.o \
./winc1500/driver/source/nmdrv.o \
./winc1500/driver/source/nmi2c.o \
./winc1500/driver/source/nmspi.o \
./winc1500/driver/source/nmuart.o 

C_DEPS += \
./winc1500/driver/source/m2m_ate_mode.d \
./winc1500/driver/source/m2m_crypto.d \
./winc1500/driver/source/m2m_hif.d \
./winc1500/driver/source/m2m_ota.d \
./winc1500/driver/source/m2m_periph.d \
./winc1500/driver/source/m2m_ssl.d \
./winc1500/driver/source/m2m_wifi.d \
./winc1500/driver/source/nmasic.d \
./winc1500/driver/source/nmbus.d \
./winc1500/driver/source/nmdrv.d \
./winc1500/driver/source/nmi2c.d \
./winc1500/driver/source/nmspi.d \
./winc1500/driver/source/nmuart.d 


# Each subdirectory must supply rules for building sources it contributes
winc1500/driver/source/m2m_ate_mode.o: ../winc1500/driver/source/m2m_ate_mode.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_ate_mode.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/m2m_crypto.o: ../winc1500/driver/source/m2m_crypto.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_crypto.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/m2m_hif.o: ../winc1500/driver/source/m2m_hif.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_hif.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/m2m_ota.o: ../winc1500/driver/source/m2m_ota.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_ota.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/m2m_periph.o: ../winc1500/driver/source/m2m_periph.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_periph.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/m2m_ssl.o: ../winc1500/driver/source/m2m_ssl.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_ssl.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/m2m_wifi.o: ../winc1500/driver/source/m2m_wifi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/m2m_wifi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/nmasic.o: ../winc1500/driver/source/nmasic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/nmasic.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/nmbus.o: ../winc1500/driver/source/nmbus.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/nmbus.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/nmdrv.o: ../winc1500/driver/source/nmdrv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/nmdrv.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/nmi2c.o: ../winc1500/driver/source/nmi2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/nmi2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/nmspi.o: ../winc1500/driver/source/nmspi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/nmspi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
winc1500/driver/source/nmuart.o: ../winc1500/driver/source/nmuart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H743xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Utilities/JPEG -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../winc1500 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"winc1500/driver/source/nmuart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

