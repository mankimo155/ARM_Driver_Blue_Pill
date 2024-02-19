/*
 * LED_MATRIX_pro.c
 *
 *  Created on: Jan 21, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/SISTICK_int.h"

#include "LED_MATRIX_cfg.h"
#include "LED_MATRIX_int.h"
#include "LED_MATRIX_prv.h"


void MLEDMTX_vInit(void)
{
	for(u8 i=0 ; i<8;i++)
	{
		MGPIO_vSetMode(PORTA,i,MODE_OUTPUT_PUSH_PULL_10MHZ);
	}
	for(u8 i=5 ; i<13;i++)
	{
		MGPIO_vSetMode(PORTB,i,MODE_OUTPUT_PUSH_PULL_10MHZ);
	}
}

void MLEDMTX_vDisplayFrame(u8 *AR_u8frame,u32 A_32uframe_delay)
{
	for(u8 i=5 ; i<13;i++)
	{
		MGPIO_vSetPinVal(PORTB,i,GPIO_LOW);
	}
	for(u32 i =0 ;i<=A_32uframe_delay;i++){
		for(u8 i=0;i<8;i++)
		{
			MGPIO_vSetPortValLowPart(PORTA,~(AR_u8frame[i]));
			MGPIO_vSetPinVal(PORTB,(i+5),GPIO_HIGH);
			MSTK_vDelay(2500);
			MGPIO_vSetPinVal(PORTB,(i+5),GPIO_LOW);
		}
	}
}


