/*
 * GPIO_prv.h
 *
 *  Created on: Jan 11, 2024
 *      Author: userH
 */

#ifndef MCAL_GPIO_GPIO_PRV_H_
#define MCAL_GPIO_GPIO_PRV_H_

#define GPIOA_BASE_ADDERS   0x40010800
#define GPIOB_BASE_ADDERS   0x40010C00
#define GPIOC_BASE_ADDERS   0x40011000

typedef struct
{
	u32 CRL ;
	u32 CRH ;
	u32 IDR ;
	u32 ODR ;
	u32 BSRR ;
	u32 BRR ;
	u32 LCKR ;

}GPIOX_MemMad_t;

#define GPIOA   ((volatile GPIOX_MemMad_t* )(GPIOA_BASE_ADDERS))
#define GPIOB   ((volatile GPIOX_MemMad_t* )(GPIOB_BASE_ADDERS))
#define GPIOC   ((volatile GPIOX_MemMad_t* )(GPIOC_BASE_ADDERS))
#endif /* MCAL_GPIO_GPIO_PRV_H_ */
