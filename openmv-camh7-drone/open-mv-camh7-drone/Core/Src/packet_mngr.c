/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#include <stdbool.h>
#include "main.h"
#include "wifi_mngr.h"
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
eImgStates PacketMngr_Iterate(void);
================ */
eImgStates PacketMngr_IterateImg(void)
{

	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;



	stImg* p_stImg = Img_jpg_Iterate();



	switch (p_stImg->m_eImgStates)
	{
		case eImgStates_start:
		{
			stNewFrame* p_stNewFrame = (stNewFrame*)(&p_stPacketMngr->m_PacketData);
			p_stNewFrame->m_NewFrameSOF	=	NEW_FRAME_SOF;
			p_stNewFrame->m_FrameSize	=	p_stImg->m_SizeB;
			p_stNewFrame->m_SysTick		=	HAL_GetTick();
			memcpy(p_stNewFrame->m_Data, p_stImg->m_pImg, );


			if( pstImg->m_SizeB > PACKET_DATA_LEN_B)
			{
				pstImg->m_eImgStates = eImgStates_sending;
			}
			else
			{
				pstImg->m_eImgStates = eImgStates_last_packet;
			}


			send(a_p_stWifiMngr->m_tcp_client_socket, p_stImg->m_pImg, PACKET_DATA_SIZE_B, 0);
		}
		case eImgStates_sending:
		{


			if( pstImg->m_SizeB > PACKET_DATA_LEN_B)
			{
				pstImg->m_SizeB -= PACKET_DATA_LEN_B;
				pstImg->m_pImg	+= PACKET_DATA_LEN_B;
			}
			else
			{
				pstImg->m_eImgStates = eImgStates_last_packet;
			}


			send(a_p_stWifiMngr->m_tcp_client_socket, p_stImg->m_pImg, PACKET_DATA_SIZE_B, 0);
		}
		break;
		case eImgStates_last_packet:
		{
			pstImg->m_eImgStates = eImgStates_finished;
			send(a_p_stWifiMngr->m_tcp_client_socket, p_stImg->m_pImg, p_stImg->m_SizeB, 0);
		}
		break;
		case eImgStates_finished:
		{
		}
		break;
		default:
			break;
	}


















	// prepare a new packet


	 return p_stImg->m_eImgStates;
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
