################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32h743vitx.s 

OBJS += \
./Core/Startup/startup_stm32h743vitx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/bsp" -I"C:/Shenhav/proyecto_final/firmware/DS_proj_fw/openmv-camh7-drone/open-mv-camh7-drone/wifi/host_drv/common" -x assembler-with-cpp --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

