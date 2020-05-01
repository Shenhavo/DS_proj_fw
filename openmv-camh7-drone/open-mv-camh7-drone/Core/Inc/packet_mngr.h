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

#define NEW_FRAME_DATA_SIZE_B			1017
#define MID_FRAME_DATA_SIZE_B			1023

typedef struct stNewFrame_name {
	uint8_t		m_NewFrameSOF;
	uint16_t	m_FrameSize;
	uint32_t	m_SysTick;
	uint8_t		m_Data[MID_FRAME_DATA_SIZE_B];
} stNewFrame;

typedef struct stMidFrame_name {
	uint8_t		m_MidFrameSOF;
	uint8_t		m_Data[MID_FRAME_DATA_SIZE_B];
} stMidFrame;


//typedef enum eFrameState_name
//{
//	eFrameState_off = 0,
//	eFrameState_NewFrame,
//	eFrameState_MidFrame,
//}eFrameState;

typedef struct stPacketMngr_name {
	stImg*				m_p_stImg;

//	eFrameState			m_eFrameState;
	uint32_t			m_ImuEventCtr;
	uint32_t			m_ImuCallsPerPacket;
	uint32_t			m_FrameEventCtr;
	bool				m_IsImuReady;

} stPacketMngr;


void PacketMngr_Init(void);
void PacketMngr_Update(void);
stImg* PacketMngr_Iterate(void);
eFrameState PacketMngr_GetState(void);



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
