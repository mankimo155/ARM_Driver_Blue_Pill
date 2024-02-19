/*
 * SISTICK_int.h
 *
 *  Created on: Jan 17, 2024
 *      Author: userH
 */

#ifndef MCAL_SYSTICK_SISTICK_INT_H_
#define MCAL_SYSTICK_SISTICK_INT_H_

#define S_1             1000000
#define MS_1            1000

void MSTK_vInit(void);

void MSTK_vStartTimer(u32 A_u32LoadValue);
void MSTK_vStoptTimer(void);


void MSTK_vDelay(u32 A_u32Ticks);

void MSTK_vSetInterval_Single(u32 A_u32LoadValue,void (*A_STKcallback)(void));
void MSTK_vSetInterval_Periodic(u32 A_u32LoadValue,void (*A_STKcallback)(void));

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);


#endif /* MCAL_SYSTICK_SISTICK_INT_H_ */
