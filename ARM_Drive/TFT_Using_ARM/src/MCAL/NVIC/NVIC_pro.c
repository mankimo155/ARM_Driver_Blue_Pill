/*
 * NVIC_pro.c
 *
 *  Created on: Jan 15, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "NVIC_int.h"
#include "NVIC_cfg.h"
#include "NVIC_prv.h"

u32 GS_u32GroupConf;


void MNVIC_vEnableIntreupt(u8 A_u8IntreuptId)
{
	NVIC->ISER[A_u8IntreuptId/32]=(0b1<<(A_u8IntreuptId%32));
}
void MNVIC_vDisableIntreupt(u8 A_u8IntreuptId)
{
	NVIC->ICER[A_u8IntreuptId/32]=(0b1<<(A_u8IntreuptId%32));

}
void MNVIC_vSetPendingFlag(u8 A_u8IntreuptId)
{
	NVIC->ISPR[A_u8IntreuptId/32]=(0b1<<(A_u8IntreuptId%32));

}
void MNVIC_vClearPendingFlag(u8 A_u8IntreuptId)
{
	NVIC->ICPR[A_u8IntreuptId/32]=(0b1<<(A_u8IntreuptId%32));

}
u8 MNVIC_vGetActiveFlag(u8 A_u8IntreuptId)
{
	return GET_BIT(NVIC->IABR[A_u8IntreuptId/32],(A_u8IntreuptId%32));

}
void MNVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
    GS_u32GroupConf = 0x05FA0000 | (Copy_u8PriorityOption << 8);
    AIRCR = GS_u32GroupConf;
}
void MNVIC_VoidSetPriority(s8 Copy_s8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
    u8 local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((GS_u32GroupConf - 0x05FA0300) / 256);
    // Core Peripheral
    if (Copy_s8INTID < 0)
    {
        if (Copy_s8INTID == MEMORY_MANAGE || Copy_s8INTID == BUS_FAULT || Copy_s8INTID == USAGE_FAULT)
        {
        	Copy_s8INTID += 3;
            SHPR1 = (local_u8Priority) << ((8 * Copy_s8INTID) + 4);
        }
        else if (Copy_s8INTID == SV_CALL)
        {
        	Copy_s8INTID += 7;
            SHPR2 = (local_u8Priority) << ((8 * Copy_s8INTID) + 4);
        }
        else if (Copy_s8INTID == PEND_SV || Copy_s8INTID == SYSTICK)
        {
        	Copy_s8INTID += 8;
            SHPR3 = (local_u8Priority) << ((8 * Copy_s8INTID) + 4);
        }
    }
    // External Peripheral
    else if (Copy_s8INTID >= 0)
    {
        NVIC->IPR[Copy_s8INTID] = local_u8Priority << 4;
    }
}
