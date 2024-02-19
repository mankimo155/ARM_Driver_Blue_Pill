/*
 * DMA_int.h
 *
 *  Created on: Feb 7, 2024
 *      Author: userH
 */

#ifndef MCAL_DMA_DMA_INT_H_
#define MCAL_DMA_DMA_INT_H_



void MDMA_vInit(void);
void MDMA_vSetStream(u8  A_u8StreamId ,
					 u32* A_pu32SrcAddress,
		             u32* A_pu32DestAddress,
					 u32 A_u32DataSize     ,
					 u32 A_u32BlockSize    );

void MDMA_vEnableStream(u8  A_u8StreamId);
void MDMA_vSetStreamCallback(u8  A_u8StreamId ,
		                     void (*fptr)(void));

#endif /* MCAL_DMA_DMA_INT_H_ */
