/*
 * RTOS_prv.h
 *
 *  Created on: Jan 22, 2024
 *      Author: userH
 */

#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_

typedef enum
{
	Suspended,
	Running
}RunState;


typedef struct
{
	void (*TaskHandler)(void)    ;
	u8        Periodicity        ;
	u8        FirstDelay         ;
	RunState  TaskRunState       ;
}Task_Set_t;



#endif /* RTOS_RTOS_PRV_H_ */
