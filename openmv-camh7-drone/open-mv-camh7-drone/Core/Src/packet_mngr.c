/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#include <stdbool.h>
#include "main.h"
#include "packet_mngr.h"

static stPacketMngr	g_stPacketMngr;

/* ================
void PacketMngr_Init(void);
================ */
void PacketMngr_Init(void)
{
	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;
	p_stPacketMngr->m_FrameEventCtr			=	0;
	p_stPacketMngr->m_ImuEventCtr			=	0;
	p_stPacketMngr->m_ImuCallsPerPacket		=	0;
	p_stPacketMngr->m_ePacketMngrState		=	ePacketMngrState_off;
	p_stPacketMngr->m_tmpIsFrameReady		= false;
	p_stPacketMngr->m_p_stImg				= Img_jpg_GetStruct();
}

/* ================
void PacketMngr_Update(void);
================ */
void PacketMngr_Update(void)
{
	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;

	UPDATE_FRAME_EVENT_CTR(p_stPacketMngr->m_FrameEventCtr);
	UPDATE_IMU_EVENT_CTR(p_stPacketMngr->m_ImuEventCtr);
//	printf("Imu %d\r\n",p_stPacketMngr->m_ImuEventCtr);
//	printf("frame %d\r\n",p_stPacketMngr->m_FrameEventCtr);

	if(p_stPacketMngr->m_ImuEventCtr == COUNTING_ENDED_VAL) // SO: new IMU call Event
	{

//		printf("new imu call\r\n");
		UPDATE_IMU_CALLS_CTR(p_stPacketMngr->m_ImuCallsPerPacket);
		if(p_stPacketMngr->m_ImuCallsPerPacket == COUNTING_ENDED_VAL) // SO: new IMU packet
		{
//			printf("new imu packet\r\n");
		}
	}

	if(p_stPacketMngr->m_FrameEventCtr == COUNTING_ENDED_VAL)	// SO: new frame packet
	{
		p_stPacketMngr->m_IsFrameReady 	=	true;
//		printf("1->%d\r\n", HAL_GetTick());
	}
}

/* ================
stImg* PacketMngr_Iterate(void);
================ */
stImg* PacketMngr_Iterate(void)
{
	//TODO: SO: add IMU packets later on

	 stImg* p_stImg = Img_jpg_Iterate();

	// prepare a new packet


	return p_stImg;
}

/* ================
ePacketMngrState PacketMngr_GetState(void)
================ */
eFrameState PacketMngr_GetState(void)
{
	return g_stPacketMngr.m_ePacketMngrState;
}

/* ================
void PacketMngr_SetState( a_ePacketMngrState)
================ */
void PacketMngr_SetState(a_ePacketMngrState)
{
	g_stPacketMngr.m_ePacketMngrState = a_ePacketMngrState;
}

/*****END OF FILE****/
