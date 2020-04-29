/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dcmi.h"
#include "dma.h"
#include "dma2d.h"
#include "fatfs.h"
#include "i2c.h"
#include "jpeg.h"
#include "mdma.h"
#include "sdmmc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include "debug_mngr.h"
#include "config/conf_winc.h"
#include "driver/include/m2m_types.h"
#include "wifi_mngr.h"
#include "led.h"

#include "jpeg_utils_conf.h"
#include "jpeg_utils.h"
#include "encode_dma.h"

#include "bno055.h"

#include "sensor.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/*!
 * @brief struct for Accel-output data of precision float
 */
typedef struct
{
    float x; /**< accel x float data */
    float y; /**< accel y float data */
    float z; /**< accel z float data */
}bno055_accel_float_t_mock;

/*!
 * @brief struct for Gyro-output data of precision float
 */
typedef struct
{
    float x; /**< Gyro x float data */
    float y; /**< Gyro y float data */
    float z; /**< Gyro z float data */
}bno055_gyro_float_t_mock;

/*!
 * @brief struct for Mag-output data of precision float
 */
typedef struct
{
    float x; /**< Mag x float data */
    float y; /**< Mag y float data */
    float z; /**< Mag z float data */
}bno055_mag_float_t_mock;

#pragma pack(1)
typedef struct
{
	bno055_accel_float_t_mock 	accl_f;
	bno055_gyro_float_t_mock	gyro_f;
	bno055_mag_float_t_mock		mag_f;
}ImuSensorData;

ImuSensorData ImuMockStruct = {0x00};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

void ImuMockValues(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  
  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
	
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DCMI_Init();
  MX_MDMA_Init();
  MX_JPEG_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_DMA2D_Init();
  /* USER CODE BEGIN 2 */
	LED_Init();
	WifiMngr_Init();
	FS_Init();

	if ( Fatfs_GetRetSD() == 0 )
	{
		printf("FATFS Link Driver OK\r\n");
	}
	else
	{
		printf("FATFS Link Driver ERR\r\n");
	}

	printf("~~ init finished ~~\r\n");
	printf("GIT REV SHA: %s\r\n", PROJ_SHA);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	if(BSP_SD_IsDetected())
	{
		FS_FileOperationsBmpCompressDma();
	}
	else
	{
		printf("sd not detected, skipping example\r\n");
	}
	TIM_StartImuTick();

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	sensor_init();
	int CamId = sensor_get_id();
	printf("camera id = %d\r\n", CamId);
	if ( CamId == MT9V034_ID )
	{
		printf("camera OK\r\n");
	}
	else
	{
		printf("camera ERR\r\n");
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	while (1)
	{
		WifiMngr_HandleEvents();

		if (TIM_IsImuTimeoutEvent() == true)
		{
//			ImuMockValues();
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Supply configuration update enable 
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage 
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_SPI2
                              |RCC_PERIPHCLK_SDMMC|RCC_PERIPHCLK_I2C1;
  PeriphClkInitStruct.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL;
  PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.I2c123ClockSelection = RCC_I2C123CLKSOURCE_D2PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/**
 * @brief  print a demo of imu data
 * @retval None
 */
void ImuMockValues(void)
{
	uint32_t CurrTick = HAL_GetTick();

	// accl values [m^2/sec] ~ ( -20, +20 )
	// sanity check : accl_f.x^2 + accl_f.y^2 = 1
	ImuMockStruct.accl_f.x = sin(CurrTick);
	ImuMockStruct.accl_f.y = cos(CurrTick);
	ImuMockStruct.accl_f.z = CurrTick;

	// gyro in dps ~ ( -500 , + 500 )
	// sanity check : gyro_f.y^2 + gyro_f.z = 1
	ImuMockStruct.gyro_f.x = CurrTick*2;
	ImuMockStruct.gyro_f.y = 500 * -sin(CurrTick);
	ImuMockStruct.gyro_f.z = 500 * -cos(CurrTick);

	// microTesla data of mag xyz (???)
	// this is not mandatory
	ImuMockStruct.mag_f.x = 1;
	ImuMockStruct.mag_f.y = 2;
	ImuMockStruct.mag_f.z = 3;

	// send payload here

	// note the printf adds delay to the code
	printf("~~~~ imu mock ~~~~\r\n");


	printf("accl_f.x =\t%f\r\n", ImuMockStruct.accl_f.x);
	printf("accl_f.y =\t%f\r\n", ImuMockStruct.accl_f.y);
	printf("accl_f.z =\t%f\r\n", ImuMockStruct.accl_f.z);

	printf("gyro_f.x =\t%f\r\n", ImuMockStruct.gyro_f.x);
	printf("gyro_f.y =\t%f\r\n", ImuMockStruct.gyro_f.y);
	printf("gyro_f.z =\t%f\r\n", ImuMockStruct.gyro_f.z);

	printf("mag_f.x =\t%f\r\n", ImuMockStruct.mag_f.x);
	printf("mag_f.y =\t%f\r\n", ImuMockStruct.mag_f.y);
	printf("mag_f.z =\t%f\r\n", ImuMockStruct.mag_f.z);
}


// TODO: DB - define in cube and move to `stm32h7xx_it.h`
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == CONF_WINC_SPI_INT_PIN)
	{
		isr();
	}
}

/* USER CODE END 4 */

/* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();
  /** Initializes and configures the Region and the memory to be protected 
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x24000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;
  MPU_InitStruct.SubRegionDisable = 0x0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	printf("\r\n***Error_handler***\r\n");
	while (true)
	{
		HAL_Delay(500);
		LED_SetState(eLedStates_red);
		HAL_Delay(500);
		LED_SetState(eLedStates_all_off);
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	 tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	printf("\r\n***assert_failed***\r\n");
	printf("Wrong parameters value: file %s on line %d\r\n", file, line);
	while (true)
	{
		HAL_Delay(500);
		LED_SetState(eLedStates_red);
		HAL_Delay(500);
		LED_SetState(eLedStates_all_off);
	}

  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
