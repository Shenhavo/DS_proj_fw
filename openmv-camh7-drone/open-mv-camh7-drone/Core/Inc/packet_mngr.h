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

#define	FULL_PACKET_SIZE_B				1024
#define NEW_FRAME_DATA_SIZE_B			1017
#define NEW_FRAME_HEADER_SIZE_B			7
#define MID_FRAME_DATA_SIZE_B			1023
#define MID_FRAME_HEADER_SIZE_B			1

#pragma pack(push,1)
typedef struct stNewFrame_name {
	uint8_t		m_NewFrameSOF;
	uint16_t	m_FrameSize;
	uint32_t	m_SysTick;
	uint8_t		m_Data[NEW_FRAME_DATA_SIZE_B];
} stNewFrame;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct stMidFrame_name {
	uint8_t		m_MidFrameSOF;
	uint8_t		m_Data[MID_FRAME_DATA_SIZE_B];
} stMidFrame;
#pragma pack(pop)

typedef enum eFrameState_name
{
	ePacketMngrState_off = 0,
	ePacketMngrState_NewFrame,
	ePacketMngrState_MidFrame,
	ePacketMngrState_IMU,
}ePacketMngrState;

typedef struct stPacketMngr_name {
	stImg*				m_p_stImg;

	ePacketMngrState	m_ePacketMngrState;
	uint32_t			m_ImuEventCtr;
	uint32_t			m_ImuCallsPerPacket;
	uint32_t			m_FrameEventCtr;
	bool				m_IsImuReady;
	uint8_t				m_PacketBytes[FULL_PACKET_SIZE_B];
} stPacketMngr;


void PacketMngr_Init(void);
void PacketMngr_Update(void);
eImgStates PacketMngr_IterateImg(int8_t a_Socket);
ePacketMngrState PacketMngr_GetState(void);
void PacketMngr_SetState(ePacketMngrState a_ePacketMngrState);
void PacketMngr_GetNewImg( void );


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
