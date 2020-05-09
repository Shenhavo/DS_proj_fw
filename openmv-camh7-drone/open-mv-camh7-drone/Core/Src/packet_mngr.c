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
		PacketMngr_SetState(ePacketMngrState_NewFrame);
//		printf("1->%d\r\n", HAL_GetTick());
	}
}

/* ================
eImgStates PacketMngr_Iterate(void);
================ */
eImgStates PacketMngr_IterateImg( int8_t a_Socket)
{

	stPacketMngr* 	p_stPacketMngr 	= 	&g_stPacketMngr;
	stImg*			p_stImg			=	p_stPacketMngr->m_p_stImg;

	int8_t Result = SOCK_ERR_NO_ERROR;

	switch (p_stImg->m_eCurrImgStates)
	{
		case eImgStates_start:
		{
			stNewFrame* p_stNewFrame 	= (stNewFrame*)(p_stPacketMngr->m_PacketBytes);
			p_stNewFrame->m_NewFrameSOF	=	NEW_FRAME_SOF;
			p_stNewFrame->m_FrameSize	=	p_stImg->m_SizeB;
			p_stNewFrame->m_SysTick		=	HAL_GetTick();
			printf("systick = %d\r\n", p_stNewFrame->m_SysTick);

			uint16_t 	packet_data_size_b 	= 	0;
			uint8_t*	pData				=	p_stImg->m_pImg;

			if( p_stImg->m_SizeB > NEW_FRAME_DATA_SIZE_B)
			{
				packet_data_size_b  += NEW_FRAME_DATA_SIZE_B;
				p_stImg->m_SizeB 	-= NEW_FRAME_DATA_SIZE_B;
				p_stImg->m_pImg		+= NEW_FRAME_DATA_SIZE_B;
				p_stImg->m_eNextImgStates = eImgStates_sending;
				PacketMngr_SetState(ePacketMngrState_MidFrame);
			}
			else
			{
				packet_data_size_b  += p_stImg->m_SizeB;
				p_stImg->m_SizeB 	-= p_stImg->m_SizeB;
				p_stImg->m_pImg		+= p_stImg->m_SizeB;
				p_stImg->m_eNextImgStates = eImgStates_finished;
				PacketMngr_SetState(ePacketMngrState_off);
			}

			memcpy(p_stNewFrame->m_Data, pData, packet_data_size_b);

			Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stNewFrame , NEW_FRAME_HEADER_SIZE_B + packet_data_size_b, 0);
		}
		case eImgStates_sending:
		{
			stMidFrame* p_stMidFrame 	= (stMidFrame*)(p_stPacketMngr->m_PacketBytes);
			p_stMidFrame->m_MidFrameSOF	= MID_FRAME_SOF;

			uint16_t 	packet_data_size_b 	= 	0;
			uint8_t*	pData				=	p_stImg->m_pImg;


			if( p_stImg->m_SizeB > MID_FRAME_DATA_SIZE_B)
			{
				packet_data_size_b  += MID_FRAME_DATA_SIZE_B;
				p_stImg->m_SizeB 	-= MID_FRAME_DATA_SIZE_B;
				p_stImg->m_pImg		+= MID_FRAME_DATA_SIZE_B;
				p_stImg->m_eNextImgStates = eImgStates_sending;
				PacketMngr_SetState(ePacketMngrState_MidFrame);
			}
			else
			{
				packet_data_size_b  += p_stImg->m_SizeB;
				p_stImg->m_SizeB 	-= p_stImg->m_SizeB;
				p_stImg->m_pImg		+= p_stImg->m_SizeB;
				p_stImg->m_eNextImgStates = eImgStates_finished;
				PacketMngr_SetState(ePacketMngrState_off);
			}

			memcpy(p_stMidFrame->m_Data, pData, packet_data_size_b);
			printf("0x%x,0x%x,0x%x,0x%x\r\n", p_stMidFrame->m_Data[0],p_stMidFrame->m_Data[1],p_stMidFrame->m_Data[2],p_stMidFrame->m_Data[3]);
			Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stMidFrame , MID_FRAME_HEADER_SIZE_B + packet_data_size_b, 0);
		}
		break;
		case eImgStates_finished:
		{
		}
		break;
		default:
			break;
	}

	assert_param( (Result == SOCK_ERR_NO_ERROR) );

	 return Img_jpg_UpdateImgState();
}

/* ================
ePacketMngrState PacketMngr_GetState(void)
================ */
ePacketMngrState PacketMngr_GetState(void)
{
	return g_stPacketMngr.m_ePacketMngrState;
}

/* ================
void PacketMngr_SetState( a_ePacketMngrState)
================ */
void PacketMngr_SetState(ePacketMngrState a_ePacketMngrState)
{
	g_stPacketMngr.m_ePacketMngrState = a_ePacketMngrState;
}

/* ================
void PacketMngr_GetNewImg( void )
================ */
void PacketMngr_GetNewImg( void )
{
	Img_jpg_GetNewImg();
}


/*****END OF FILE****/
