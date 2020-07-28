/*
 * file_operations_playground.c
 *
 *  Created on: 9 Apr 2020
 *      Author: Dan
 */



#include "fatfs.h"

#include <stdio.h>

#include "camera_mngr.h" // frame defs
#include "jpeg.h"
#include "jpeg_utils_conf.h"
#include "jpeg_utils.h"
#include "jpeg_encode_dma.h"
#include "f_op_playground.h"










/**
 * @brief  resaves bitmap to sd card
 * @retval None
 */
void FS_FileOperationsBmpResaveOnSdCard(void)
{
	FRESULT res;					/* FatFs function common result code */
	FIL BmpFileSrc, BmpFileDst;     /* File object */

	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		/*##-6- Open the file with read access #############################*/
		if((res = f_open(&BmpFileSrc, BMP_FILE_NAME_ON_SD, FA_READ)) == FR_OK)
		{
			printf("FR_OK\r\n");
			if((res = f_open(&BmpFileDst, BMP_TO_RESAVE_FILE_NAME_ON_SD, FA_WRITE | FA_CREATE_ALWAYS)) == FR_OK)
			{
				printf("file resave on SD starting ..\r\n");

				uint32_t ReadChunks = 0;
				uint32_t BytesWritten, BytesRead = 0;

				do{
					f_read(&BmpFileSrc, workBuffer, sizeof(workBuffer), (void *)&BytesRead);
					printf("read %ld: %ld\r\n", ReadChunks, BytesRead);
					f_write(&BmpFileDst, workBuffer, BytesRead, (void *)&BytesWritten);
					ReadChunks++;

					if(BytesRead != BytesWritten)
					{
						printf("copy ERR\r\n");
						break;
					}

				} while(BytesRead>0);
				f_close(&BmpFileDst);
			}
			f_close(&BmpFileSrc);
		}
		else
		{
			printf("f_open ERR: %d\r\n", res);
		}

	}
}

/**
 * @brief  compress bitmap to jpeg
 * please read the file documentation
 * @retval None
 */
void FS_FileOperationsBmpCompressDma(void)
{
	FRESULT res;			/* FatFs function common result code */


	/* Register the file system object to the FatFs module */
	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		printf("compressing file: %s\r\n", BMP_FILE_NAME_ON_SD);

		FIL DestJpegImg, SrcBmpFile;     /* File object */
		//uint32_t BytesWritten, BytesRead = 0;
		uint32_t JpegEncodeProcessingEnd = 0;

		/*##-6- Open the file with read access #############################*/
		if((res = f_open(&SrcBmpFile, BMP_FILE_NAME_ON_SD, FA_READ)) == FR_OK)
		{
			printf("FR_OK\r\n");
			if((res = f_open(&DestJpegImg, JPEG_FILE_NAME_ON_SD, FA_WRITE | FA_CREATE_ALWAYS)) == FR_OK)
			{
				printf("file compression starting ..\r\n");

				JPEG_ConfTypeDef SrcBmpInfo;
				BMP_GetInfo(&SrcBmpFile, &SrcBmpInfo);
				printf("SrcBmp Params: W=%ld H=%ld\r\n", SrcBmpInfo.ImageWidth, SrcBmpInfo.ImageHeight);

				/*##-8- JPEG Encoding with DMA (Not Blocking ) Method ################*/
				JpegEncodeDMA_FromSdToSd(&hjpeg, &SrcBmpFile, &DestJpegImg);

				/*##-9- Wait till end of JPEG encoding and perform Input/Output Processing in BackGround  #*/
				do
				{
					JPEG_EncodeInputHandler(&hjpeg);
					JpegEncodeProcessingEnd = JPEG_EncodeOutputHandler(&hjpeg);

				}while(JpegEncodeProcessingEnd == 0);

				/*##-10- Close the JPEG file #######################################*/

				uint32_t SrcBmpImgFileSize = f_size(&SrcBmpFile);
				uint32_t DestJpegImgFileSize = f_size(&DestJpegImg);
				printf("source file size = %ld [bits]\r\n", SrcBmpImgFileSize);
				printf("converted file size = %ld [bits]\r\n", DestJpegImgFileSize);

				if ( (res = f_close(&DestJpegImg)) == FR_OK )
				{
					printf("DestJpegImg close OK\r\n");
				}
			}
			if ( (res = f_close(&SrcBmpFile)) == FR_OK )
			{
				printf("SrcBmpFile close OK\r\n");
			}
		}
		else
		{
			printf("f_open ERR: %d\r\n", res);
		}

	}

}


/**
 * @brief  compress from dcmi ram to jpeg
 * please read the file documentation
 * @retval None
 */
void FS_FileOperationsDcmiRamCompressDma(uint8_t *pDataToCompress)
{
	FRESULT res;			/* FatFs function common result code */

	/* Register the file system object to the FatFs module */
	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		printf("compressing dcmi sram frame\r\n");

		FIL DestJpegImg;     /* File object */
		//uint32_t BytesWritten, BytesRead = 0;
		uint32_t JpegEncodeProcessingEnd = 0;

		/*##-6- Open the file with read access #############################*/
		uint8_t JpegFname[39] = {0x00};
		sprintf(JpegFname, "gray_%d_%d_sram_compress_q%d_ch%d.jpg", IMG_W, IMG_H, JPEG_IMAGE_QUALITY, JPEG_CHROMA_SAMPLING);
		if((res = f_open(&DestJpegImg, JpegFname, FA_WRITE | FA_CREATE_ALWAYS)) == FR_OK)
		{
			printf("compression starting ..\r\n");

			JPEG_ConfTypeDef SrcBmpInfo;
			SrcBmpInfo.ImageWidth = IMG_W;
			SrcBmpInfo.ImageHeight = IMG_H;
			printf("SrcBmp Params: W=%ld H=%ld\r\n", SrcBmpInfo.ImageWidth, SrcBmpInfo.ImageHeight);

			/*##-8- JPEG Encoding with DMA (Not Blocking ) Method ################*/
			JpegEncodeDMA_FromRamToSd(&hjpeg, pDataToCompress, &DestJpegImg);

			/*##-9- Wait till end of JPEG encoding and perform Input/Output Processing in BackGround  #*/
			do
			{
				JPEG_EncodeInputHandler(&hjpeg);
				JpegEncodeProcessingEnd = JPEG_EncodeOutputHandler(&hjpeg);

			}while(JpegEncodeProcessingEnd == 0);

			/*##-10- Close the JPEG file #######################################*/

			//				uint32_t SrcBmpImgFileSize = f_size(&SrcBmpFile);
			uint32_t DestJpegImgFileSize = f_size(&DestJpegImg);
			printf("source file size = %ld [bits]\r\n", SrcBmpInfo.ImageWidth * SrcBmpInfo.ImageHeight);
			printf("converted file: %s\r\n size = %ld [bits]\r\n", JpegFname, DestJpegImgFileSize);

			if ( (res = f_close(&DestJpegImg)) == FR_OK )
			{
				printf("DestJpegImg close OK\r\n");
			}
		}

	}

}


