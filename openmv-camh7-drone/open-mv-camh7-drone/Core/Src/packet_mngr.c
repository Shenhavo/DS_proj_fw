/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#include <stdbool.h>
#include <stdio.h>
#include "main.h"
#include "camera_mngr.h"
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
	p_stPacketMngr->m_ePacketMngrState		=	ePacketMngrState_off;
	p_stPacketMngr->m_p_stImg				= Img_jpg_GetStruct();

	p_stPacketMngr->m_ImuEventCtr			=	0;
	p_stPacketMngr->m_ImuCallsPerPacket		=	0;
	p_stPacketMngr->m_IsImuCallReady		= false;
	p_stPacketMngr->m_IsImuPacketReady		= false;
	memset((&p_stPacketMngr->m_stImuPacket),0,sizeof(stImuPacket));

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
		p_stPacketMngr->m_IsImuCallReady	=	true;

		if(p_stPacketMngr->m_ImuCallsPerPacket == COUNTING_ENDED_VAL) // SO: new IMU packet
		{
			p_stPacketMngr->m_IsImuPacketReady = true;
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
			if ( CameraMngr_GetCompressedImgState() == eCompressedImgState_WaitForSend )
			{
				CameraMngr_SetCompressedImgState( eCompressedImgState_SendStart );

				stNewFrame* p_stNewFrame 	= (stNewFrame*)(p_stPacketMngr->m_PacketBytes);
				p_stNewFrame->m_NewFrameSOF	=	NEW_FRAME_SOF;
				p_stNewFrame->m_FrameSize	=	CameraMngr_GetCompressedImgSize(); // p_stImg->m_SizeB;
				p_stNewFrame->m_SysTick		=	HAL_GetTick();

				uint16_t 	packet_data_size_b 	= 	0;
				p_stImg->m_pImg					= 	CameraMngr_GetCompressedImg();
				uint8_t*	pData				=   p_stImg->m_pImg;

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
					CameraMngr_SetCompressedImgState( eCompressedImgState_SendCmplt );
				}

				memcpy(p_stNewFrame->m_Data, pData, packet_data_size_b);

				Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stNewFrame , NEW_FRAME_HEADER_SIZE_B + packet_data_size_b, 0);
			}
			else
			{
				printf("img not ready\r\n");
			}
		}
		break;
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
				CameraMngr_SetCompressedImgState( eCompressedImgState_SendCmplt );
			}

			memcpy(p_stMidFrame->m_Data, pData, packet_data_size_b);
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

	if(Result == SOCK_ERR_BUFFER_FULL) //SO: SOCK_ERR_BUFFER_FULL is received whenever user clicks on wifi connections
	{
		printf("Socket err: %d\r\n", Result);
		p_stImg->m_eCurrImgStates = eImgStates_finished;
		p_stImg->m_eNextImgStates = eImgStates_finished;
	}

//	assert_param( (Result == SOCK_ERR_NO_ERROR) );

	 return Img_jpg_UpdateImgState();
}

/* ================
void PacketMngr_IterateImu( int8_t a_Socket )
================ */
void PacketMngr_IterateImu( int8_t a_Socket )
{
	// TODO: SO: see if sending the packet takes more than 3msec...otherwise there will be missing data
	stPacketMngr* 	p_stPacketMngr 	= 	&g_stPacketMngr;
	stImuPacket* p_stImuPacket = &p_stPacketMngr->m_stImuPacket;
	if(p_stPacketMngr->m_IsImuCallReady == true)
	{
		p_stPacketMngr->m_IsImuCallReady = false;
		PacketMngr_GetNewImuCall();
		UPDATE_IMU_CALLS_CTR(p_stPacketMngr->m_ImuCallsPerPacket);

		if(p_stPacketMngr->m_IsImuPacketReady == true)
		{
			p_stImuPacket->m_ImuSOF = IMU_SOF;
			p_stImuPacket->m_SysTick = HAL_GetTick();
//			printf("Tick: %d\r\n", HAL_GetTick());
		}
	}

	if( (p_stPacketMngr->m_IsImuPacketReady == true)&&
			(p_stPacketMngr->m_ePacketMngrState == ePacketMngrState_off))
	{
		p_stPacketMngr->m_ePacketMngrState = ePacketMngrState_IMU;
		p_stPacketMngr->m_IsImuPacketReady =	false;
		int8_t Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stImuPacket , sizeof(stImuPacket), 0);

		if(Result == SOCK_ERR_BUFFER_FULL) //SO: SOCK_ERR_BUFFER_FULL is received whenever user clicks on wifi connections
		{
			printf("Socket err imu: %d\r\n", Result);
		}
		p_stPacketMngr->m_ePacketMngrState = ePacketMngrState_off;
	}
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

/* ================
void PacketMngr_GetNewImuCall(void)
================ */
void PacketMngr_GetNewImuCall(void)
{

	stPacketMngr* 	p_stPacketMngr 		= 	&g_stPacketMngr;
	uint32_t		ImuCallsPerPacket	=	p_stPacketMngr->m_ImuCallsPerPacket;
	stImuCall*		p_stImuCall			= 	&p_stPacketMngr->m_stImuPacket.m_ImuCalls_a[ImuCallsPerPacket];

	stImuCall* pNewCall =  SD_MPU6050_GetImuCall();
	memcpy(p_stImuCall, pNewCall, sizeof(stImuCall));

	//============== TODO: SO: fill real values ==============
//	p_stImuCall->m_GyroX	=	ImuCallsPerPacket*0;
//	p_stImuCall->m_GyroY	=	ImuCallsPerPacket*-100;
//	p_stImuCall->m_GyroZ	=	ImuCallsPerPacket*200;
//	p_stImuCall->m_AccX		=	ImuCallsPerPacket*-300;
//	p_stImuCall->m_AccY		=	ImuCallsPerPacket*400;
//	p_stImuCall->m_AccZ		=	ImuCallsPerPacket*-500;

}

///* ================
//bool PacketMngr_GetIsImuPacketReady(void)
//================ */
//bool PacketMngr_GetIsImuPacketReady(void)
//{
//	return g_stPacketMngr.m_IsImuPacketReady;
//}
//
//
///* ================
//void PacketMngr_SetIsImuPacketReady( bool a_IsImuPacketReady)
//================ */
//void PacketMngr_SetIsImuPacketReady( bool a_IsImuPacketReady)
//{
//	g_stPacketMngr.m_IsImuPacketReady = a_IsImuPacketReady;
//}


/*****END OF FILE****/
