/*
 * EXTI_int.h
 *
 *  Created on: Jan 17, 2024
 *      Author: userH
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define ENABLE 1
#define DISNABLE 0
#define EXTI_RISING 1
#define EXTI_FALLING 2
#define EXTI_IN_CHANGE 3
#define EXTI_PORTA 0b0000
#define EXTI_PORTB 0b0001

 enum {
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
};

void MEXTI_vInit(void);

void MEXTI_vEnableLine(u8 A_u8Trigger,u8 A_u8LineNo);
void MEXTI_vSetCallBack(u8 A_u8LineNo,void (*ptr)(void));
void MEXTI_vDiableLine(u8 A_u8LineNo);
void MEXT_vClearPandingFlag(u8 A_u8LineNo);
void MEXTI_vSoftWareTrigger(u8 A_u8LineNo);
void MEXTI_vSetTrigger(u8 A_u8Trigger,u8 A_u8LineNo);
void MSYSCFG_vSetExtiPort(u8 A_u8LineNo,u8 A_u8Port);
#endif /* MCAL_EXTI_EXTI_INT_H_ */
