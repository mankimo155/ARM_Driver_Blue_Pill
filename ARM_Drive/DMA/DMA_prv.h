/*
 * DMA_prv.h
 *
 *  Created on: Feb 7, 2024
 *      Author: userH
 */

#ifndef MCAL_DMA_DMA_PRV_H_
#define MCAL_DMA_DMA_PRV_H_

#define DMA1_BASW_ADD   0x40020000


typedef struct
{
	u32 CCR ;
	u32 CNDTR;
	u32 CPAR ;
	u32 CMAR ;
	u32 RASERVED;
}DMA_stream_T;


typedef struct
{
	u32 ISR ;
	u32 IFCR ;
	DMA_stream_T S[7];
}MDAx_MamMap_t;


#define DMA_1  ((volatile MDAx_MamMap_t*)(DMA1_BASW_ADD))

#endif /* MCAL_DMA_DMA_PRV_H_ */
