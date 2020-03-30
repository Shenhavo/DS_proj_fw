/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __debug_mngr_H
#define __debug_mngr_H
#ifdef __cplusplus
 extern "C" {
#endif
#include <stdio.h>

 int _write(int file, char *ptr, int len)
 {
   /* Implement your write code here, this is used by puts and printf for example */
   int i=0;
   for(i=0 ; i<len ; i++)
     ITM_SendChar((*ptr++));
   return len;
 }

#ifdef __cplusplus
}
#endif
#endif /*__debug_mngr_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
