/*
 * RTOS_int.h
 *
 *  Created on: Jan 22, 2024
 *      Author: userH
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_


u8 RTOS_u8CreateTask (  void(*Copy_Handler)(void) , u8 Copy_u8Periodicity, u8 Copy_u8Priority , u8 Copy_FirstD );
void RTOS_voidStartOS(void);
u8 RTOS_u8DeleteTask(u8 Copy_u8Priority);
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority);
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority);

#endif /* RTOS_RTOS_INT_H_ */
