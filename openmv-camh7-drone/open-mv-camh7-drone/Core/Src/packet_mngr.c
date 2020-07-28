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

static void PacketMngr_GetNewImuCall(void);
static eImgStates PacketMngr_IterateImg(int8_t a_Socket);
static void PacketMngr_IterateImu();
static void PacketMngr_SendImu(int8_t a_Socket);
static void PacketMngr_SetState(ePacketMngrState a_ePacketMngrState);

/* ================
void PacketMngr_Init(void);
================ */
void PacketMngr_Init(void)
{
	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;
	PacketMngr_SetState(ePacketMngrState_off);
	p_stPacketMngr->m_FrameEventCtr			=	0;
	p_stPacketMngr->m_p_stImg				= Img_jpg_GetStruct();
	p_stPacketMngr->m_ImuEventCtr			=	0;
	p_stPacketMngr->m_ImuCallsPerPacket		=	0;
	p_stPacketMngr->m_IsImuCallReady		= false;
	p_stPacketMngr->m_IsImuPacketReady		= false;
	p_stPacketMngr->m_IsFramePacketReady	= false;
	memset((&p_stPacketMngr->m_stImuPacket),0,sizeof(stImuPacket));
}

/* ================
void PacketMngr_Start(void)
================ */
void PacketMngr_Start(void)
{
	stPacketMngr* 	p_stPacketMngr 	= 	&g_stPacketMngr;
	stImg*			p_stImg			=	p_stPacketMngr->m_p_stImg;
	p_stImg->m_eCurrImgStates		= 	eImgStates_finished;
	p_stImg->m_eNextImgStates		= 	eImgStates_finished;
}


/* ================
void PacketMngr_TxRoutine(void)
================ */
void PacketMngr_TxRoutine(int8_t a_Socket)
{
	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;
#ifdef USING_IMU
	PacketMngr_IterateImu();
#endif
	switch (p_stPacketMngr->m_ePacketMngrState) {
	case ePacketMngrState_off:
	{
#ifdef USING_FRAME
		if(p_stPacketMngr->m_IsFramePacketReady	== true) // SO: it prioritizes frames over imu packets
		{
			p_stPacketMngr->m_IsFramePacketReady = false;
			if(Img_jpg_GetCurrImgState() == eImgStates_finished)
			{

				PacketMngr_SetState(ePacketMngrState_Frame);
				PacketMngr_GetNewImg(); // TODO: SO: restarting image structure, later bring a new image
				PacketMngr_IterateImg(a_Socket);
			}
			else
			{
				printf("##M\r\n");
			}
		}
		else // SO: case imu
		{
#endif
#ifdef USING_IMU
			if(p_stPacketMngr->m_IsImuPacketReady == true)
			{
				PacketMngr_SendImu(a_Socket);
			}
#endif
#ifdef USING_FRAME
		}
#endif
	}
	break;
	case ePacketMngrState_Frame:
	{
		PacketMngr_IterateImg( a_Socket);
	}
	break;
	case ePacketMngrState_IMU:
	{
		printf("V\r\n"); // SO: it never going to get here probably
	}
	break;
	default:
	{
		printf("U\r\n"); // SO: it never going to get here probably
	}
		break;
	}
}

/* ================
void PacketMngr_Update(void);
================ */
void PacketMngr_Update(void)
{
	stPacketMngr* p_stPacketMngr = &g_stPacketMngr;

#ifdef USING_IMU
	UPDATE_IMU_EVENT_CTR(p_stPacketMngr->m_ImuEventCtr);

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
#endif
#ifdef USING_FRAME
	UPDATE_FRAME_EVENT_CTR(p_stPacketMngr->m_FrameEventCtr);
	if(p_stPacketMngr->m_FrameEventCtr == COUNTING_ENDED_VAL)	// SO: new frame packet
	{
		p_stPacketMngr->m_IsFramePacketReady	= true;
//		printf("1->%d\r\n", HAL_GetTick());
	}
#endif
}

/* ================
void PacketMngr_IterateImg(void);
================ */
eImgStates PacketMngr_IterateImg(int8_t a_Socket)
{

	stPacketMngr* 	p_stPacketMngr 	= 	&g_stPacketMngr;
	stImg*			p_stImg			=	p_stPacketMngr->m_p_stImg;
	stFrame* 		p_stFrame 		= (stFrame*)(p_stPacketMngr->m_PacketBytes);
	uint16_t 	packet_data_size_b 	= 	0;
	uint8_t*	pData				=	p_stImg->m_pImg;

	int8_t Result = SOCK_ERR_NO_ERROR;

	switch (p_stImg->m_eCurrImgStates)
	{
		case eImgStates_start:
		{
			p_stImg->m_SysTick 			= 	HAL_GetTick();
			p_stImg->m_eCurrImgStates	= eImgStates_sending;
			PacketMngr_SetState(ePacketMngrState_Frame);
		}
		case eImgStates_sending:
		{
			p_stFrame->m_FrameSOF	=	FRAME_SOF;
			p_stFrame->m_SysTick	=	p_stImg->m_SysTick;
			p_stFrame->m_FrameSize	=	p_stImg->m_SizeB;
//			p_stFrame->m_PacketIdx	=	(p_stFrame->m_FrameSize)%FRAME_DATA_SIZE_B? (p_stFrame->m_FrameSize)/FRAME_DATA_SIZE_B: ((p_stFrame->m_FrameSize)/FRAME_DATA_SIZE_B)+1;


			if( p_stImg->m_SizeB > FRAME_DATA_SIZE_B)
			{
				packet_data_size_b  += FRAME_DATA_SIZE_B;
				p_stImg->m_SizeB 	-= FRAME_DATA_SIZE_B;
				p_stImg->m_pImg		+= FRAME_DATA_SIZE_B;
				p_stImg->m_eNextImgStates = eImgStates_sending;
			}
			else
			{
				packet_data_size_b  += p_stImg->m_SizeB;
				p_stImg->m_SizeB 	-= p_stImg->m_SizeB;
				p_stImg->m_pImg		+= p_stImg->m_SizeB;
				p_stImg->m_eNextImgStates = eImgStates_finished;
				PacketMngr_SetState(ePacketMngrState_off);
			}

			memcpy(p_stFrame->m_Data, pData, packet_data_size_b);

			Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stFrame , NEW_FRAME_HEADER_SIZE_B + packet_data_size_b, 0);
		}
		break;
		case eImgStates_finished:
		{
			printf("F\r\n");
		}
		break;
		default:
			break;
	}

	if(Result == SOCK_ERR_BUFFER_FULL)
	{

		printf("Socket err frame: %d\r\n", Result);
	}


	 return Img_jpg_UpdateImgState();
}

/* ================
void PacketMngr_IterateImu()
================ */
void PacketMngr_IterateImu()
{
	stPacketMngr* 	p_stPacketMngr 	= 	&g_stPacketMngr;
	if(p_stPacketMngr->m_IsImuCallReady == true)
	{
		p_stPacketMngr->m_IsImuCallReady = false;
		PacketMngr_GetNewImuCall();
		UPDATE_IMU_CALLS_CTR(p_stPacketMngr->m_ImuCallsPerPacket);
	}
}

/* ================
void PacketMngr_SendImu(int8_t a_Socket)
================ */
void PacketMngr_SendImu(int8_t a_Socket)
{
	stPacketMngr* 	p_stPacketMngr 	= 	&g_stPacketMngr;
	stImuPacket* p_stImuPacket = &p_stPacketMngr->m_stImuPacket;

	p_stImuPacket->m_ImuSOF = IMU_SOF;
	p_stImuPacket->m_SysTick = HAL_GetTick();

	if( (p_stPacketMngr->m_IsImuPacketReady == true)&&
			(p_stPacketMngr->m_ePacketMngrState == ePacketMngrState_off))
	{
		PacketMngr_SetState(ePacketMngrState_IMU);
		p_stPacketMngr->m_IsImuPacketReady =	false;
		int8_t Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stImuPacket , sizeof(stImuPacket), 0);
		printf("I\r\n");
		if(Result == SOCK_ERR_BUFFER_FULL) //SO: SOCK_ERR_BUFFER_FULL is received whenever user clicks on wifi connections
		{
			printf("Socket err imu: %d\r\n", Result);
//			HAL_Delay(1);
//			Result = send((socketIdx_t) a_Socket, (uint8_t*)p_stImuPacket , sizeof(stImuPacket), 0);
		}
		PacketMngr_SetState(ePacketMngrState_off);
	}
}

/* ================
void PacketMngr_SetState( a_ePacketMngrState)
================ */
void PacketMngr_SetState(ePacketMngrState a_ePacketMngrState)
{
	g_stPacketMngr.m_ePacketMngrState = a_ePacketMngrState;
//	printf("*%d\r\n",a_ePacketMngrState);
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

}


/*****END OF FILE****/
