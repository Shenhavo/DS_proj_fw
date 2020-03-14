/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __wifi_mngr_H
#define __wifi_mngr_H
#ifdef __cplusplus
 extern "C" {
#endif

 int8_t WifiMngr_Init(void);
 sint8 WifiMngr_ScanReq(tenuM2mScanCh a_e_tenuM2mScanCh);
 sint8 WifiMngr_Connect(tenuM2mScanCh a_e_tenuM2mScanCh);
 sint8	WifiMngr_HandleEvents(void);

#ifdef __cplusplus
}
#endif
#endif /*__ wifi_mngr_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
