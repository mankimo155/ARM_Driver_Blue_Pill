/*
 * EXTI_pro.c
 *
 *  Created on: Jan 17, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"




#include "EXTI_int.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"

static void (*CallBackFun[16])(void);

void MEXTI_vInit(void)
{
	//EXTI->IMR=0;
	//	EXTI->PR=0xFFFFFFFF;

}

void MEXTI_vEnableLine(u8 A_u8Trigger,u8 A_u8LineNo)
{

	SET_BIT(EXTI->IMR,A_u8LineNo);
	switch(A_u8Trigger)
	{
	case EXTI_RISING:
		SET_BIT(EXTI->RTSR,A_u8LineNo);
		CLR_BIT(EXTI->FTSR,A_u8LineNo);
	break;
	case EXTI_FALLING:
		SET_BIT(EXTI->FTSR,A_u8LineNo);
		CLR_BIT(EXTI->RTSR,A_u8LineNo);
	break;
	case EXTI_IN_CHANGE:
		SET_BIT(EXTI->FTSR,A_u8LineNo);
		SET_BIT(EXTI->RTSR,A_u8LineNo);
	break;
	}

}

void MEXTI_vDiableLine(u8 A_u8LineNo)
{
	CLR_BIT(EXTI->IMR,A_u8LineNo);

}

void MEXTI_vSoftWareTrigger(u8 A_u8LineNo)
{

	SET_BIT(EXTI->SWIER,A_u8LineNo);
}
void MEXTI_vSetTrigger(u8 A_u8Trigger,u8 A_u8LineNo)
{
	switch(A_u8Trigger)
	{
	case EXTI_RISING:
		SET_BIT(EXTI->RTSR,A_u8LineNo);
		CLR_BIT(EXTI->FTSR,A_u8LineNo);
	break;
	case EXTI_FALLING:
		SET_BIT(EXTI->FTSR,A_u8LineNo);
		CLR_BIT(EXTI->RTSR,A_u8LineNo);
	break;
	case EXTI_IN_CHANGE:
		SET_BIT(EXTI->FTSR,A_u8LineNo);
		SET_BIT(EXTI->RTSR,A_u8LineNo);
	break;
	}


}

void MEXT_vClearPandingFlag(u8 A_u8LineNo)
{
	SET_BIT(EXTI->PR,A_u8LineNo);
}

void MEXTI_vSetCallBack(u8 A_u8LineNo,void (*ptr)(void))
{
	CallBackFun[A_u8LineNo]=ptr;

}
void MSYSCFG_vSetExtiPort(u8 A_u8LineNo,u8 A_u8Port)
{
	AFIO->EXTICR[A_u8LineNo/4] &= ~((0b1111) <<((A_u8LineNo%4)*4));
	AFIO->EXTICR[A_u8LineNo/4] |= ((A_u8Port) <<((A_u8LineNo%4)*4));
}
void EXTI0_IRQHandler(void)
{
	if(CallBackFun[0]!=NULL)
	{
	CallBackFun[0]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE0);
}
