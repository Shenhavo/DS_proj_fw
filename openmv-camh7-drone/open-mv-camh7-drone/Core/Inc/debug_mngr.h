/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEBUG_MNGR_H
#define _DEBUG_MNGR_H
#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>

#ifdef USE_UART_DEBUG
#include "usart.h"
#endif //USE_UART_DEBUG

 int _write(int file, char *ptr, int len)
 {
//   int i=0;
//
//   for(i=0 ; i<len ; i++)
//   {
//#ifdef USE_UART_DEBUG
//	   HAL_UART_Transmit( &DEBUG_UART_HANDLER, (uint8_t*)ptr, 1,1); // TODO: SO&DB: comment all function in release mode
//#endif //USE_UART_DEBUG
//
//#ifdef USE_SWV_DEBUG
//	   ITM_SendChar((*ptr));
//#endif //USE_UART_DEBUG
//
//	   ptr++;
//   }
//
//   return len;
 }

#ifdef __cplusplus
}
#endif
#endif /*_DEBUG_MNGR_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
