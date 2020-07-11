/*
 * camera_mngr.c
 */
#include <stdio.h>
#include "dcmi.h"
#include "jpeg.h"
#include "ff.h" // TODO: DB - fix this. only jpeg_encode_dma needs this
#include "sensor.h"
#include "jpeg_encode_dma.h"
#include "camera_mngr.h"

stCameraMngr g_CameraMngr = {0x00};


bool CameraMngr_isDcmiAcqRunning( void );

/**
 * @brief  CameraMngr_Init
 * @retval None
 */
void CameraMngr_Init(void)
{
	stCameraMngr* pThis = &g_CameraMngr;

	sensor_init();

	int CamId = sensor_get_id();

	printf("camera id = %d\r\n", CamId);
	if (CamId == MT9V034_ID)
	{
		printf("camera MT9V034 OK\r\n");
	}
	else
	{
		printf("camera MT9V034 ERR\r\n");
	}

	sensor_reset();
	sensor_set_pixformat(PIXFORMAT_GRAYSCALE); // only grayscale supported
	sensor_set_framesize(FRAME_SIZE);

	pThis->m_FrameWidth 	= IMG_W;
	pThis->m_FrameHeight 	= IMG_H;
	pThis->m_isFrameReady 	= false;
	pThis->m_pFrameBuff		= CameraFrameBuff;
	pThis->m_FrameBuffSize	= FRAME_BUFF_SIZE;
	pThis->m_pJpegFrameBuff = JpegFrameBuff;
	pThis->m_JpegFrameBuffSize = 0;
	pThis->m_JpegFrameBuffConvSize = 0;
	pThis->m_isJpegReady 	= false;

#ifdef CAMERA_BENCHMARK
	pThis->m_JpegConvStartTick			= 0;
	pThis->m_JpegConvDuration_msec		= 0;
	pThis->m_DcmiFrameAcqStartTick		= 0;
	pThis->m_DcmiFrameAcqDuration_msec 	= 0;

	printf( "CameraFrameBuff\t@ 0x%x  aligned with = %ld to uint32_t\r\n",
			(uint32_t) CameraFrameBuff,
			((uint32_t) CameraFrameBuff - D1_AXISRAM_BASE) % 32);

	printf( "JpegFrameBuff\t@ 0x%x aligned with = %ld to uint32_t\r\n",
			(uint32_t) JpegFrameBuff,
			((uint32_t) JpegFrameBuff - D1_AXISRAM_BASE) % 32);


	printf("img dim = W=%d\tH=%d\r\n", IMG_W, IMG_H);

	if (JPEG_CHROMA_SAMPLING == JPEG_420_SUBSAMPLING)
	{
		printf("JPEG_CHROMA_SAMPLING = \tJPEG_420_SUBSAMPLING\r\n");
	}
	else if (JPEG_CHROMA_SAMPLING == JPEG_422_SUBSAMPLING)
	{
		printf("JPEG_CHROMA_SAMPLING = \tJPEG_422_SUBSAMPLING\r\n");
	}
	else if (JPEG_CHROMA_SAMPLING == JPEG_444_SUBSAMPLING)
	{
		printf("JPEG_CHROMA_SAMPLING = \tJPEG_444_SUBSAMPLING\r\n");
	}

	printf("JPEG_IMAGE_QUALITY = \t %d\r\n", JPEG_IMAGE_QUALITY);
	printf("MAX_INPUT_LINES = \t %d\r\n", MAX_INPUT_LINES);

#endif // CAMERA_BENCHMARK
}

/**
 * @brief  CameraMngr_GetImgBuff
 * @retval Frame Buff ptr
 */
uint8_t* CameraMngr_GetFrameBuff(void)
{
	return g_CameraMngr.m_pFrameBuff;
}

/**
 * @brief  CamerMngr_GetJpegFrameBuff
 * @retval Jpeg Buff ptr
 */
uint8_t* CameraMngr_GetJpegFrameBuff(void)
{
	return g_CameraMngr.m_pJpegFrameBuff;
}

/**
 * @brief  CameraMngr_GetJpegFrameBuffSize
 * @retval
 */
uint32_t CameraMngr_GetJpegFrameBuffSize(void)
{
	return g_CameraMngr.m_JpegFrameBuffConvSize;
}

/**
 * @brief  CamerMngr_isFrameReady
 * @retval
 */
bool CamerMngr_isFrameReady(void)
{
	return g_CameraMngr.m_isFrameReady;
}

/**
 * @brief  CameraMngr_isJpegReady
 * @retval
 */
bool CameraMngr_isJpegReady(void)
{
	return g_CameraMngr.m_isJpegReady;
}

/**
 * @brief  CameraMngr_WaitForFrame
 * @retval None
 */
void CameraMngr_WaitForFrame(void)
{
	uint32_t TickStart = HAL_GetTick();

	// Wait for frame
	while ( CameraMngr_isDcmiAcqRunning() )
	{
		// Wait for interrupt
		__WFI();

		if ((HAL_GetTick() - TickStart) >= 3000)
		{
			HAL_DCMI_Stop(&hdcmi);
			break;
		}
	}

}

bool CameraMngr_isDcmiAcqRunning( void )
{
	return ( (DCMI->CR & DCMI_CR_CAPTURE) != 0 );
}

/**
 * @brief  CameraMngr_DcmiFrameAcqDma
 * @retval None
 */
void CameraMngr_DcmiFrameAcqDma( void )
{
	stCameraMngr* pThis = &g_CameraMngr;

	printf("dcmi acq starting ..\r\n");

#ifdef CAMERA_BENCHMARK
	pThis->m_DcmiFrameAcqDuration_msec = 0;
	pThis->m_DcmiFrameAcqStartTick = HAL_GetTick();
#endif // CAMERA_BENCHMARK


	// start capture
	HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_SNAPSHOT, (uint32_t)g_CameraMngr.m_pFrameBuff, g_CameraMngr.m_FrameBuffSize);

	// dummy loop poll on dcmi capture complete
	CameraMngr_WaitForFrame(); // TODO: DB - make this non-blocking

#ifdef CAMERA_BENCHMARK
	pThis->m_DcmiFrameAcqDuration_msec = HAL_GetTick() - pThis->m_DcmiFrameAcqStartTick;
	printf("dcmi frame acq duration %ld[msec] \r\n", pThis->m_DcmiFrameAcqDuration_msec );
#endif // CAMERA_BENCHMARK

}

/**
 * @brief  CameraMngr_Compress
 * @retval None
 */
void CameraMngr_Compress(void)
{
	stCameraMngr* pThis = &g_CameraMngr;
	uint32_t JpegEncodeProcessingEnd = 0;

	printf("compression starting ..\r\n");

#ifdef CAMERA_BENCHMARK
	pThis->m_JpegConvDuration_msec = 0;
	pThis->m_JpegConvStartTick = HAL_GetTick();
#endif // CAMERA_BENCHMARK

	pThis->m_JpegFrameBuffConvSize = 0;


	JpegEncodeDMA_FromRamToRam(&hjpeg, pThis->m_pFrameBuff, pThis->m_pJpegFrameBuff);

	do
	{
		JPEG_EncodeInputHandler(&hjpeg);
		JpegEncodeProcessingEnd = JPEG_EncodeOutputHandler(&hjpeg);

	} while(JpegEncodeProcessingEnd == 0);

	pThis->m_JpegFrameBuffConvSize = JpegEncodeDMA_GetOutBuffSize();


#ifdef CAMERA_BENCHMARK
	//printf("src size = %ld [b]\r\n", pThis->m_FrameBuffSize);
	printf("out size = %ld [b]\r\n", pThis->m_JpegFrameBuffConvSize);

	pThis->m_JpegConvDuration_msec = HAL_GetTick() - pThis->m_JpegConvStartTick;
	printf("jpeg compress duration %ld[msec] \r\n", pThis->m_JpegConvDuration_msec );
#endif // CAMERA_BENCHMARK
}
