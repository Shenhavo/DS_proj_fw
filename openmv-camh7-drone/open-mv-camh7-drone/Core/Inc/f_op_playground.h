/*
 * file_operations_playground.h
 *
 *  Created on: 9 Apr 2020
 *      Author: Dan
 */

#ifndef _F_OP_PLAYGROUND_H_
#define _F_OP_PLAYGROUND_H_




#define FILE_NAME			"MyTxt.TXT"
#define IMG_TO_COMPRESS		"image01.bmp"
#define IMG_TO_RESAVE		"CpyBmp01.bmp"
#define BMP_FILE_NAME_ON_SD		"IMG.BMP"//"IMG.BMP" // "image05.jpg"
#define BMP_TO_RESAVE_FILE_NAME_ON_SD		"IMG_CPY.BMP"
#define JPEG_FILE_NAME_ON_SD	"image01.jpg"

#define IS_NEED_SD_FORAMT	0


void SD_Initialize(void);
void FS_Init(void);
void FS_FileOperations(void);
void FS_FileSearchOperations(void);
void FS_FileOperationsBmpCompress(void);
void FS_FileOperationsBmpResave(void);
void FS_FileOperationsBmpResaveOnSdCard(void);
void FS_FileOperationsBmpCompressDma(void);

#endif /* _F_OP_PLAYGROUND_H_ */
