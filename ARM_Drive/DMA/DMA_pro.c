/*
 * DMA_pro.c
 *
 *  Created on: Feb 7, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "DMA_int.h"
#include "DMA_cfg.h"
#include "DMA_prv.h"

void (*G_vCallBacl_DMA)(void);



void MDMA_vInit(void)
{
	DMA_1->S[0].CCR=0b100101011010010;

}
void MDMA_vSetStream(u8  A_u8StreamId ,
					 u32* A_pu32SrcAddress,
		             u32* A_pu32DestAddress,
					 u32 A_u32DataSize     ,
					 u32 A_u32BlockSize    )
{
	DMA_1->S[A_u8StreamId].CPAR=A_pu32DestAddress;
	DMA_1->S[A_u8StreamId].CMAR=A_pu32SrcAddress;
	DMA_1->S[A_u8StreamId].CNDTR=A_u32BlockSize;
}

void MDMA_vEnableStream(u8  A_u8StreamId)
{
	DMA_1->IFCR=0b1111;
	SET_BIT(DMA_1->S[A_u8StreamId].CCR,0);

}
void MDMA_vSetStreamCallback(u8  A_u8StreamId ,
		                     void (*fptr)(void))
{
	G_vCallBacl_DMA=fptr;


}

void DMA1_Channel1_IRQHandler(void)
{
	G_vCallBacl_DMA();
}
