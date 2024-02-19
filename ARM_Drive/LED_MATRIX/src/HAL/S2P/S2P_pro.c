/*
 * S2P_pro.c
 *
 *  Created on: Jan 22, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/SISTICK_int.h"


#include "S2P_int.h"
#include "S2P_cfg.h"
#include "S2P_prv.h"


void S2P_vLatchData(void)
{
	MGPIO_vSetPinVal(S2P_PORT,S2P_LATCH_PIN,GPIO_HIGH);
	MSTK_vDelay(1);
	MGPIO_vSetPinVal(S2P_PORT,S2P_LATCH_PIN,GPIO_LOW);
	MSTK_vDelay(1);
}
void S2P_vShiftData(void)
{
	MGPIO_vSetPinVal(S2P_PORT,S2P_SHIFT_PIN,GPIO_HIGH);
	MSTK_vDelay(1);
	MGPIO_vSetPinVal(S2P_PORT,S2P_SHIFT_PIN,GPIO_LOW);
	MSTK_vDelay(1);

}


void HS2P_vInit(void)
{
	MGPIO_vSetMode(S2P_PORT,S2P_DATA_PIN,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MGPIO_vSetMode(S2P_PORT,S2P_LATCH_PIN,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MGPIO_vSetMode(S2P_PORT,S2P_SHIFT_PIN,MODE_OUTPUT_PUSH_PULL_10MHZ);


}
void HS2P_vSendData(u32 A_u32Data)
{
	for(u8 i = 0 ; i< (8*S2P_NO_SHIFT_RAG) ; i++)
	{
		MGPIO_vSetPinVal(S2P_PORT,S2P_DATA_PIN,GET_BIT(A_u32Data,i));
		S2P_vShiftData();
	}
	S2P_vLatchData();
}

