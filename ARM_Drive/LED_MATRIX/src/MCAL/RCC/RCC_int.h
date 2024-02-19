/*
 * RCC_int.h
 *
 *  Created on: Jan 10, 2024
 *      Author: userH
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_
#include "../../LIB/STD_TYPES.h"

#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2
#define RCC_PORTA  2
#define RCC_PORTB  3
#define RCC_PORTC  4



void MRCC_vInit(void);
void MRCC_vEnablClock(u32 A_u32BusId ,u32 A_u32PriephralId );
void MRCC_vDisablClock(u32 A_u32BusId ,u32 A_u32PriephralId );


#endif /* MCAL_RCC_RCC_INT_H_ */
