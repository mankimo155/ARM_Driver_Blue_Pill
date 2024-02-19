/*
 * FLACH_pro.c
 *
 *  Created on: Feb 9, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"


#include "FLASH_int.h"
#include "FLASH_cfg.h"
#include "FLASH_prv.h"


void MFMI_vEraseAppArea(void)
{
	while(GET_BIT(FIM->SR,0)==1){}
	if(GET_BIT(FIM->CR,7)==1)
	{
		FIM->KEYR=KEY_1;
		FIM->KEYR=KEY_2;
	}
	SET_BIT(FIM->CR,2);
	SET_BIT(FIM->CR,6);
	while(GET_BIT(FIM->SR,0)==1){}
	SET_BIT(FIM->SR,5);
	CLR_BIT(FIM->CR,2);
}
void MFMI_vSectorErase(u32 A_u8PageADD)
{
	while(GET_BIT(FIM->SR,0)==1){}
	if(GET_BIT(FIM->CR,7)==1)
	{
		FIM->KEYR=KEY_1;
		FIM->KEYR=KEY_2;
	}
	SET_BIT(FIM->CR,1);
	FIM->AR=A_u8PageADD;
	SET_BIT(FIM->CR,6);
	while(GET_BIT(FIM->SR,0)==1){}
	SET_BIT(FIM->SR,5);
	CLR_BIT(FIM->CR,1);
}
void MFMI_vFlashWrite(u32 A_u32Address,
		             u16* A_pu16Data,
					 u16  A_u16Length)
{
	while(GET_BIT(FIM->SR,0)==1){}
	if(GET_BIT(FIM->CR,7)==1)
	{
		SET_BIT(FIM->CR,9);
		FIM->OPTKEYR=KEY_1;
		FIM->OPTKEYR=KEY_2;
	}
	SET_BIT(FIM->CR,5);
	SET_BIT(FIM->CR,0);
	for(u16 i =0 ;i<A_u16Length;i++)
	{
		*((volatile u16*)(A_u32Address))=A_pu16Data[i];
		A_u32Address+=2;
		while(GET_BIT(FIM->SR,0)==1){}
	}
	CLR_BIT(FIM->CR,0);
	CLR_BIT(FIM->CR,5);
}





