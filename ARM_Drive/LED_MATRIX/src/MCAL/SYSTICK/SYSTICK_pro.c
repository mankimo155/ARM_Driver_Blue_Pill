/*
 * SYSTICK_pro.c
 *
 *  Created on: Jan 17, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SISTICK_int.h"
#include "SISTICK_cfg.h"
#include "SISTICK_prv.h"


static void (*GS_STK_Callback)(void);
static u8 GS_u8SingleFlag ;

void MSTK_vInit(void)
{
#if STCK_CLK_SORUSE == STK_AHB
	SET_BIT(STK->CTRL,CLKS);
#endif

#if STCK_CLK_INTERUPT_EN == ENABLE
	SET_BIT(STK->CTRL,TICKINT);
#endif
}

void MSTK_vStartTimer(u32 A_u32LoadValue)
{

	STK->VAL=0;
	STK->LOAD=A_u32LoadValue;
	SET_BIT(STK->CTRL,STK_ENABLE);

}
void MSTK_vStoptTimer(void){
	CLR_BIT(STK->CTRL,STK_ENABLE);

}


void MSTK_vDelay(u32 A_u32Ticks)
{
	STK->VAL=0;
	STK->LOAD=A_u32Ticks;
	SET_BIT(STK->CTRL,STK_ENABLE);
	while(GET_BIT(STK->CTRL,COUNTFLAG)!=1){}
	CLR_BIT(STK->CTRL,STK_ENABLE);
}

void MSTK_vSetInterval_Single(u32 A_u32LoadValue,void (*A_STKcallback)(void))
{
	GS_u8SingleFlag=1;
	GS_STK_Callback = A_STKcallback ;
	STK->VAL=0;
	STK->LOAD=A_u32LoadValue;
	SET_BIT(STK->CTRL,STK_ENABLE);

}
void MSTK_vSetInterval_Periodic(u32 A_u32LoadValue,void (*A_STKcallback)(void))
{
	GS_u8SingleFlag=0;
	GS_STK_Callback=A_STKcallback;
	STK->VAL=0;
	STK->LOAD=A_u32LoadValue;
	SET_BIT(STK->CTRL,STK_ENABLE);


}

u32 MSTK_u32GetElapsedTime(void)
{
	return (STK->LOAD-STK->VAL) ;
}

u32 MSTK_u32GetRemainingTime(void)
{
	return STK->VAL ;

}

void SysTick_Handler(void)
{
	if(GS_STK_Callback != NULL)
	{
		GS_STK_Callback();
	}
	if(GS_u8SingleFlag==1)
	{
	CLR_BIT(STK->CTRL,STK_ENABLE);
	}
}
