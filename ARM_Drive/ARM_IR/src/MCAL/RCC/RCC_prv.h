/*
 * RCC_prv.h
 *
 *  Created on: Jan 10, 2024
 *      Author: userH
 */

#ifndef RCC_RCC_PRV_H_
#define RCC_RCC_PRV_H_


#define Enable    1
#define Disable   0
#define PLL       24
#define CSS       19
#define HSEBYP    18
#define HSEON     16
#define HSION     0
#define HSI_ON    0b00
#define HSE_ON    0b01
#define PLL_ON    0b10

#define RCC_BASE_ADDR    0x40021000

typedef struct
{
	u32 CR       ;
	u32 CFGR     ;
	u32 CIR      ;
	u32 APB2RSTR ;
	u32 APB1RSTR ;
	u32 AHBENR   ;
	u32 APB2ENR  ;
	u32 APB1ENR  ;
	u32 BDCR     ;
	u32 CSR      ;

}RCC_MemMap_t;


#define RCC   ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


#endif /* RCC_RCC_PRV_H_ */
