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

//#define CALC_TX_AVG_TIME

#ifdef CALC_TX_AVG_TIME
	#define NUM_OF_TX_TIMES_TO_AVG	500
	#define OUTLINERS_TO_OMIT		10
	 void WifiMngr_Calc(void);
#endif //CALC_TX_AVG_TIME

#define SIZE_OF_AVG_JPEG_IMAGE_KB	15

typedef struct sockaddr_in stSockAdd;
//typedef struct tstrSocketBindMsg stBindMsg;
typedef tstrM2MAPConfig stAccPoint;

typedef tenuM2mConnState eIsWifiConn;

typedef struct stWifiMngr_name { // TODO: add also stImg...
   uint8_t* 		m_pTxBuff;
   uint8_t* 		m_pRxBuff;
   bool	   			m_IsRxReady;
   bool	   			m_IsTxPhase;
   eIsWifiConn		m_eIsWifiConnected;
//   uint32_t 	m_SizeB;

} stWifiMngr;


 int8_t WifiMngr_Init(void);
// sint8 WifiMngr_ScanReq(tenuM2mScanCh a_e_tenuM2mScanCh);
// sint8 WifiMngr_Connect(tenuM2mScanCh a_e_tenuM2mScanCh);
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
