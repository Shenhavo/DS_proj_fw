/*
 * file_operations_playground.h
 *
 *  Created on: 9 Apr 2020
 *      Author: Dan
 *
 *      How to use the `FS_FileOperationsBmpCompressDma` example?
 *      take the images from the project's drive dir `sd file content`
 *      (or other *.BMP) file that has W/H of multiply of 16.
 *      choose the file to convert by the define `BMP_FILE_NAME_ON_SD`
 *      the output would be in `JPEG_FILE_NAME_ON_SD`
 */

#ifndef _F_OP_PLAYGROUND_H_
#define _F_OP_PLAYGROUND_H_



#define FILE_NAME						"MyTxt.TXT"
#define IMG_TO_COMPRESS					"gray_640_480.bmp"
#define IMG_TO_RESAVE					"CpyBmp01.bmp"
#define BMP_FILE_NAME_ON_SD				"gray_320_240.bmp"
#define BMP_TO_RESAVE_FILE_NAME_ON_SD	"IMG_CPY.BMP"
#define JPEG_FILE_NAME_ON_SD			"gray_320_240_sram_compress_q75_ch422.jpg"

#define IS_NEED_SD_FORAMT	0


void SD_Initialize(void);
void FS_Init(void);
void FS_FileOperations(void);
void FS_FileSearchOperations(void);
void FS_FileOperationsBmpCompress(void);
void FS_FileOperationsBmpResave(void);
void FS_FileOperationsBmpResaveOnSdCard(void);
void FS_FileOperationsBmpCompressDma(void);
void FS_FileOperationsDcmiRamCompressDma(uint8_t *pDataToCompress);

#endif /* _F_OP_PLAYGROUND_H_ */
