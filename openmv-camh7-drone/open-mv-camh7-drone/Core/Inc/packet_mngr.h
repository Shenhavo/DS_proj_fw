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
//#include "imu_mngr.h"

#define NEW_IMU_EVENT_CYCLE_MSEC	5
#define NEW_IMU_CALLS_PER_PACKET	10
#define NEW_FRAME_EVENT_CYCLE_MSEC	50

#define UPDATE_IMU_EVENT_CTR(x)			(x)++;\
										(x)=((x)%NEW_IMU_EVENT_CYCLE_MSEC)
#define UPDATE_IMU_CALLS_CTR(x)			(x)++;\
										(x)=((x)%NEW_IMU_CALLS_PER_PACKET)
#define UPDATE_FRAME_EVENT_CTR(x)		(x)++;\
										(x)=((x)%NEW_FRAME_EVENT_CYCLE_MSEC)
#define COUNTING_ENDED_VAL				0

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
	uint32_t			m_ImuEventCtr;
	uint32_t			m_ImuCallsPerPacket;
	uint32_t			m_FrameEventCtr;

	bool				m_tmpIsFrameReady;

} stPacketMngr;


void PacketMngr_Init(void);
void PacketMngr_Routine(void);
bool PacketMngr_GetIsFrameReady(void);



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
