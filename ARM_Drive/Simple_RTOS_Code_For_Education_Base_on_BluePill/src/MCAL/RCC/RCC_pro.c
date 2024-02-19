/*
 * RCC_pro.c
 *
 *  Created on: Jan 10, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_cfg.h"
#include "RCC_prv.h"


void MRCC_vInit(void){

#if RCC_PLL == Enable
	SET_BIT(RCC->CR,PLL);
#endif

#if RCC_CSS == Enable
	SET_BIT(RCC->CR,CSS);
#endif

#if RCC_HSEBYP == Enable
	SET_BIT(RCC->CR,HSEBYP);
#endif

#if RCC_HSE == Enable
	SET_BIT(RCC->CR,HSEON);
#endif

#if RCC_HSI == Enable
	SET_BIT(RCC->CR,HSION);
#endif

RCC->CFGR = (RCC->CFGR & 0b00) | (RCC_SWS);

}
void MRCC_vEnablClock(u32 A_u32BusId , u32 A_u32PriephralId )
{

	switch(A_u32BusId)
	{
	case 0 :
		SET_BIT(RCC->AHBENR,A_u32PriephralId);
		break;
	case 1 :
		SET_BIT(RCC->APB1ENR,A_u32PriephralId);

		break;
	case 2 :
		SET_BIT(RCC->APB2ENR,A_u32PriephralId);
		break;
	}

}


void MRCC_vDisablClock(u32 A_u32BusId ,u32 A_u32PriephralId )
{

	switch(A_u32BusId)
	{
	case 0 :
		CLR_BIT(RCC->AHBENR,A_u32PriephralId);
		break;
	case 1 :
		CLR_BIT(RCC->APB1ENR,A_u32PriephralId);
		break;
	case 2 :
		CLR_BIT(RCC->APB2ENR,A_u32PriephralId);
		break;
	}


}
