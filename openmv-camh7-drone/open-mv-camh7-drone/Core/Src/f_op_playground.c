/*
 * file_operations_playground.c
 *
 *  Created on: 9 Apr 2020
 *      Author: Dan
 */


#include "fatfs.h"

#include "stdio.h"

#include "jpeg.h"
#include "jpeg_utils_conf.h"
#include "jpeg_utils.h"
#include "encode_dma.h"

#include "img_bmp_file.h"
#include "img_jpg_file.h"

#include "f_op_playground.h"


//FATFS g_SDFatFs;  /* File system object for SD card logical drive */ // TODO: DB - check this
static uint8_t isInitialized = 0;
uint8_t workBuffer[_MAX_SS];



/**
 * @brief  SD init with BSP
 * @retval None
 */
void SD_Initialize(void)
{
	if (isInitialized == 0)
	{
		BSP_SD_Init();

		if(BSP_SD_IsDetected())
		{
			isInitialized = 1;
		}
	}
}

/**
 * @brief  FS init and creating of filesystem
 * @retval None
 */
void FS_Init(void)
{
	if(BSP_SD_IsDetected())
	{
		FRESULT res;

		if (IS_NEED_SD_FORAMT)
		{
			printf("formatting SD\r\n");
			res = f_mkfs(SDPath, FM_FAT32, 0, workBuffer, sizeof(workBuffer));
			if (res != FR_OK)
			{
				Error_Handler();
			}

		}
		else
		{
			printf("no SD format\r\n");
		}

		/* Create FAT volume */
//		FATFS_LinkDriver(&SD_Driver, SDPath); // this exists in `MX_FATFS_Init()`

	}

}


/**
 * @brief  example write-read test
 * @retval None
 */
void FS_FileOperations(void)
{
	FRESULT res;                                          /* FatFs function common result code */
	uint32_t byteswritten, bytesread;                     /* File write/read counts */
	uint8_t wtext[] = "testestest!!"; /* File write buffer */
	uint8_t rtext[100];                                   /* File read buffer */
	FIL MyFile;     /* File object */

	/* Register the file system object to the FatFs module */
	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		/* Create and Open a new text file object with write access */
		if((res = f_open(&MyFile, FILE_NAME, FA_CREATE_ALWAYS | FA_WRITE)) == FR_OK)
		{
			/* Write data to the text file */
			res = f_write(&MyFile, wtext, sizeof(wtext), (void *)&byteswritten);

			if((byteswritten > 0) && (res == FR_OK))
			{
				/* Close the open text file */
				f_close(&MyFile);

				/* Open the text file object with read access */
				if(f_open(&MyFile, FILE_NAME, FA_READ) == FR_OK)
				{
					/* Read data from the text file */
					res = f_read(&MyFile, rtext, sizeof(rtext), (void *)&bytesread);

					if((bytesread > 0) && (res == FR_OK))
					{
						/* Close the open text file */
						f_close(&MyFile);

						/* Compare read data with the expected data */
						if((bytesread == byteswritten))
						{
							/* Success of the demo: no error occurrence */
							//              BSP_LED_On(LED1);
							printf("successful file write-read\r\n");
							return;
						}
					}
				}
			}
		}
	}
	/* Error */
	Error_Handler();
}

/**
 * @brief  example of using sd card and looking for a file extension
 * @retval None
 */
void FS_FileSearchOperations(void)
{
	FRESULT res;                                          /* FatFs function common result code */
	uint32_t byteswritten, bytesread;                     /* File write/read counts */

	/* Register the file system object to the FatFs module */
	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		printf("searching for images\r\n");
		FRESULT fr;     /* Return value */
		DIR dj;         /* Directory object */
		FILINFO fno;    /* File information */

		printf("jpg:\r\n");
		fr = f_findfirst(&dj, &fno, "", "*.jpg");  /* Start to search for jpeg files */

		while (fr == FR_OK && fno.fname[0]) {         /* Repeat while an item is found */
			printf("%s\n", fno.fname);                /* Print the object name */
			fr = f_findnext(&dj, &fno);               /* Search for next item */
		}

		printf("bmp:\r\n");
		fr = f_findfirst(&dj, &fno, "", "*.bmp");  /* Start to search for bmp files */

		while (fr == FR_OK && fno.fname[0]) {         /* Repeat while an item is found */
			printf("%s\n", fno.fname);                /* Print the object name */
			fr = f_findnext(&dj, &fno);               /* Search for next item */
		}

		f_closedir(&dj);
	}
	/* Error */
	Error_Handler();
}

/**
 * @brief  compress bitmpa to jpeg - NOT TESTED!
 * @retval None
 */
void FS_FileOperationsBmpCompress(void)
{
	FRESULT res;                                          /* FatFs function common result code */


	/* Register the file system object to the FatFs module */
	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		printf("compressing file: %s\r\n", IMG_TO_COMPRESS);

		FIL MyCompressedImg;     /* File object */
		uint32_t BytesWritten = 0;
		uint8_t DataOut[500000] = {0xFF};
		uint32_t DataOutSize = 500000;
		if((res = f_open(&MyCompressedImg, IMG_TO_COMPRESS, FA_WRITE | FA_CREATE_ALWAYS)) == FR_OK)
		{
			printf("file compression starting ..\r\n");
			// JPEG_DecodingUsingFs_Polling
			if ( (res = HAL_JPEG_Encode(&hjpeg, img_bmp_file, IMG_BMP_SIZE_B, DataOut, DataOutSize, 10000)) == HAL_OK )
			{
				if ( (res = f_write( &MyCompressedImg, &DataOut, DataOutSize, &BytesWritten)) == FR_OK )
				{
					printf("finished! %u bytes\r\n", BytesWritten);
				}
				else
				{
					printf("f_write err: %d\r\n", res);
				}
				//		   JPEG_DecodingUsingFs_Polling
				//		   JPEG_EcodingUsingFs_Polling

				f_close(&MyCompressedImg);
			}
			else
			{
				printf("jpeg conversion err: %d\r\n", res);
			}
		}
		else
		{
			printf("f_open err: %d\r\n", res);
		}

	}

}

/**
 * @brief  resaves bitmap to sd card
 * @retval None
 */
void FS_FileOperationsBmpResave(void)
{
	FRESULT res;                                          /* FatFs function common result code */
	uint32_t BytesWritten = 0;
	FIL MyImgCopy;     /* File object */
	if(f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) == FR_OK)
	{
		if((res = f_open(&MyImgCopy, IMG_TO_RESAVE, FA_WRITE | FA_CREATE_ALWAYS)) == FR_OK)
		{
			printf("file resave starting ..\r\n");
			for (uint32_t PixelIdx = 0; PixelIdx < IMG_BMP_SIZE_B; PixelIdx++)
			{
				res = f_write( &MyImgCopy, &img_bmp_file[PixelIdx], 1, &BytesWritten);
			}
			printf("finished!\r\n");
			f_close(&MyImgCopy);
		}
		else
		{
			printf("f_open err: %d\r\n", res);
		}
	}
}

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
					printf("read %d: %d\r\n", ReadChunks, BytesRead);
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
		uint32_t BytesWritten, BytesRead = 0;
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
				printf("SrcBmp Params: W=%d H=%d\r\n", SrcBmpInfo.ImageWidth, SrcBmpInfo.ImageHeight);

				/*##-8- JPEG Encoding with DMA (Not Blocking ) Method ################*/
				JPEG_Encode_DMA(&hjpeg, &SrcBmpFile, &DestJpegImg);

				/*##-9- Wait till end of JPEG encoding and perform Input/Output Processing in BackGround  #*/
				do
				{
					JPEG_EncodeInputHandler(&hjpeg);
					JpegEncodeProcessingEnd = JPEG_EncodeOutputHandler(&hjpeg);

				}while(JpegEncodeProcessingEnd == 0);

				/*##-10- Close the JPEG file #######################################*/

				uint32_t SrcBmpImgFileSize = f_size(&SrcBmpFile);
				uint32_t DestJpegImgFileSize = f_size(&DestJpegImg);
				printf("source file size = %d [bits]\r\n", SrcBmpImgFileSize);
				printf("converted file size = %d [bits]\r\n", DestJpegImgFileSize);

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
