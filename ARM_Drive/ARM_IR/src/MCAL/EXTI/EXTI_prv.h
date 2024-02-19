/*
 * EXTI_prv.h
 *
 *  Created on: Jan 17, 2024
 *      Author: userH
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR 0x40010400
#define AFIO_BASE_ADDR 0x40010008


typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;


}MEXTI_MamMap_t;

typedef struct
{
	u32 EXTICR[4];

}MAFIO_MamMap_t;



#define EXTI ((volatile MEXTI_MamMap_t*)(EXTI_BASE_ADDR))
#define AFIO ((volatile MAFIO_MamMap_t*)(AFIO_BASE_ADDR))

#endif /* MCAL_EXTI_EXTI_PRV_H_ */
