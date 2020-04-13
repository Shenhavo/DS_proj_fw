/*
 * file_operations_playground.h
 *
 *  Created on: 9 Apr 2020
 *      Author: Dan
 */

#ifndef INC_F_OP_PLAYGROUND_H_
#define INC_F_OP_PLAYGROUND_H_




#define FILE_NAME			"STM32.TXT"
#define IMG_TO_COMPRESS		"image01.bmp"
#define IMG_TO_RESAVE		"CpyBmp01.bmp"
//#define IMG_TO_COMPRESS		"img01.jpg"
#define IS_NEED_SD_FORAMT	0


void SD_Initialize(void);
void FS_Init(void);
void FS_FileOperations(void);
void FS_FileSearchOperations(void);
void FS_FileOperationsBmpCompress(void);
void FS_FileOperationsBmpResave(void);
void FS_FileOperationsBmpCompressDma(void);

#endif /* INC_F_OP_PLAYGROUND_H_ */
