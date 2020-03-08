/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
 // SO: moved from main.h
 /* Private defines -----------------------------------------------------------*/
 #define LED_R_Pin GPIO_PIN_0
 #define LED_R_GPIO_Port GPIOC
 #define LED_G_Pin GPIO_PIN_1
 #define LED_G_GPIO_Port GPIOC
 #define LED_B_Pin GPIO_PIN_2
 #define LED_B_GPIO_Port GPIOC
 #define WIFI_CHIP_EN_Pin GPIO_PIN_5
 #define WIFI_CHIP_EN_GPIO_Port GPIOA
 #define WIFI_RESET_N_Pin GPIO_PIN_12
 #define WIFI_RESET_N_GPIO_Port GPIOD
 #define WIFI_INT_N_Pin GPIO_PIN_13
 #define WIFI_INT_N_GPIO_Port GPIOD
 #define WIFI_INT_N_EXTI_IRQn EXTI15_10_IRQn

 #define SPI2_NSS_GPIO GPIOB
 #define SPI2_NSS_Pin GPIO_PIN_12
 /* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
