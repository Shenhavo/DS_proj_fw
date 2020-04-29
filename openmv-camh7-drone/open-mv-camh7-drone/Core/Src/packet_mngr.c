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
	// TODO: SO: init also stImg !!!
}

/* ================
void PacketMngr_Routine(void);
================ */
void PacketMngr_Routine(void)
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
		p_stPacketMngr->m_tmpIsFrameReady 	=	true;
		printf("1->%d\r\n", HAL_GetTick());
	}
}

/* ================
bool PacketMngr_GetIsFrameReady(void);
================ */
bool PacketMngr_GetIsFrameReady(void)
{
	bool Retval = false;
	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;
	if( p_stPacketMngr->m_tmpIsFrameReady == true)
	{
		Retval = true;
		p_stPacketMngr->m_tmpIsFrameReady = false;
	}
	return Retval;
}

/*****END OF FILE****/
