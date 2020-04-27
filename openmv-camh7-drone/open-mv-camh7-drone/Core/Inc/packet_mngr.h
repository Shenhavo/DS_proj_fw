/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __packet_mngr_H
#define __packet_mngr_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "img_jpg_file.h"
#include "imu_mngr.h"

#define NEW_FRAME_SOF	'!'
#define MID_FRAME_SOF	'A'
#define IMU_SOF			'i'


typedef enum ePacketMngrState_name
{
	ePacketMngrState_off = 0,
	ePacketMngrState_NewFrame,
	ePacketMngrState_MidFrame,
	ePacketMngrState_IMU,
}ePacketMngrState;

typedef struct stPacketMngr_name {
	ePacketMngrState	m_ePacketMngrState;
	stImg				m_stImg;
//	stImu				m_stImu;
} stPacketMngr;


void PacketMngr_Init(void);
void PacketMngr_Routine( eLedStates a_eLedStates);


#ifdef __cplusplus
}
#endif
#endif /*__packet_mngr_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
