/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
  ******************************************************************************
  *******************************************************************************/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
//#include "stm32f4xx_nucleo_144.h" // TODO: see if i missed something
#include "stdio.h"
#include "driver/include/m2m_types.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
/** Wi-Fi Settings */


//#define MAIN_WIFI_M2M_PRODUCT_NAME        "NMCTemp"
//#define MAIN_WIFI_M2M_SERVER_IP           0xC0A80079 /* 255.255.255.255 */
#define ATWINC_AP_IP_BYTE0	0xC0 /* 192 */
#define ATWINC_AP_IP_BYTE1	0xA8 /* 168 */
#define ATWINC_AP_IP_BYTE2	0x01 /* 1 */
#define ATWINC_AP_IP_BYTE3	0x01 /* 1 */



#define MAIN_WIFI_M2M_SERVER_PORT         (6666)
//#define MAIN_WIFI_M2M_REPORT_INTERVAL     (1000)

#define MAIN_WIFI_M2M_BUFFER_SIZE      1024 //SOCKET_BUFFER_MAX_LENGTH

#define IPV4_BYTE(val, index)          ((val >> (index * 8)) & 0xFF)

/** AP mode Settings */
#define MAIN_WLAN_SSID                 "WINC1500_AP" /* < SSID */
#define MAIN_WLAN_AUTH                 M2M_WIFI_SEC_OPEN /* < Security manner */
#define MAIN_WLAN_CHANNEL              (6) /* < Channel number */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/

/* USER CODE END Header */


/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */


/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
