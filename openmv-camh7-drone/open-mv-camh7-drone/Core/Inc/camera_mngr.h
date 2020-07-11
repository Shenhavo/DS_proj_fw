/*
 * camera_mngr.h
 */

#ifndef INC_CAMERA_MNGR_H_
#define INC_CAMERA_MNGR_H_

#define CAMERA_BENCHMARK

//#define JPEG_444_GS_MCU_SIZE        (64)
// 640 * 480 = 307200
#define FRAME_SIZE		FRAMESIZE_VGA
#define IMG_W			(640)
#define IMG_H			(480)

// 320 * 240 = 76800
//#define FRAME_SIZE		FRAMESIZE_QVGA
//#define IMG_W			(320)
//#define IMG_H			(240)

//// 160 * 120 = 19200
//#define FRAME_SIZE		FRAMESIZE_QQVGA
//#define IMG_W			(160)
//#define IMG_H			(120)

#define FRAME_BUFF_SIZE  ( IMG_H * IMG_W )
ALIGN_32BYTES( uint8_t CameraFrameBuff[FRAME_BUFF_SIZE] );

#define JPEG_BUFF_MAX_SIZE	20000
ALIGN_32BYTES( uint8_t JpegFrameBuff[JPEG_BUFF_MAX_SIZE	] ); // TODO: define something!!!


typedef struct stCameraMngr_name {

	uint8_t*			m_pFrameBuff;
	uint32_t			m_FrameWidth;
	uint32_t			m_FrameHeight;
	uint32_t			m_FrameBuffSize;

	uint8_t*			m_pJpegFrameBuff;
	uint32_t			m_JpegFrameBuffSize;
	uint32_t			m_JpegFrameBuffConvSize;

	bool				m_isFrameReady;
	bool				m_isJpegReady;

#ifdef CAMERA_BENCHMARK
	uint32_t			m_JpegConvStartTick;
	uint32_t			m_JpegConvDuration_msec;

	uint32_t			m_DcmiFrameAcqStartTick;
	uint32_t			m_DcmiFrameAcqDuration_msec;
#endif // CAMERA_BENCHMARK
} stCameraMngr;




void CameraMngr_Init(void);

void CameraMngr_WaitForFrame(void);
void CameraMngr_DcmiFrameAcqDma(void);

bool CamerMngr_isFrameReady(void);
bool CameraMngr_isJpegReady(void);

uint8_t* CameraMngr_GetFrameBuff(void);
uint8_t* CameraMngr_GetJpegFrameBuff(void);
uint32_t CameraMngr_GetJpegFrameBuffSize(void);

void CameraMngr_Compress(void);

#endif /* INC_CAMERA_MNGR_H_ */
