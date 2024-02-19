/*
 * RTOS_pro.c
 *
 *  Created on: Jan 22, 2024
 *      Author: userH
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/SYSTICK/SISTICK_int.h"
#include "RTOS_int.h"
#include "RTOS_cfg.h"
#include "RTOS_prv.h"

Task_Set_t SystemTasks[MAX_NUM_OF_TASKS] = {0};
u8   TaskTiming [MAX_NUM_OF_TASKS];

Task_Set_t Empty = {0};




u8 RTOS_u8CreateTask (  void(*Copy_Handler)(void) , u8 Copy_u8Periodicity, u8 Copy_u8Priority , u8 Copy_FirstD )
{
	u8 Local_ErrorState = 0;

	/* Verify that the priority index within the correct range */
	if (Copy_u8Priority < MAX_NUM_OF_TASKS)
	{

		if (SystemTasks[Copy_u8Priority].TaskHandler == NULL)
		{
			SystemTasks[Copy_u8Priority].TaskHandler  = Copy_Handler;
			SystemTasks[Copy_u8Priority].Periodicity  = Copy_u8Periodicity;
			TaskTiming [Copy_u8Priority]              = Copy_FirstD;
			SystemTasks[Copy_u8Priority].TaskRunState = Running;
		}

		else
		{
			/* The required priority is alread reserved */
			Local_ErrorState = 2;
		}
	}

	else
	{
		/* Wrong priority */
		Local_ErrorState = 1;

	}

	return Local_ErrorState;
}

void Scheduler(void)
{
	u8 Local_Counter=0;

	/* Loop on all Taks */
	for (Local_Counter =0; Local_Counter < MAX_NUM_OF_TASKS; Local_Counter++)
	{
		/* Is there a registered task ... ? */
		if (SystemTasks[Local_Counter].TaskHandler != 0)
		{
			if (SystemTasks[Local_Counter].TaskRunState == Running )
			{
				if (TaskTiming[Local_Counter] == 0)
				{
					/* Run the task */
					SystemTasks[Local_Counter].TaskHandler();

					/* Reload the periodicity */
					TaskTiming[Local_Counter] = SystemTasks[Local_Counter].Periodicity;
				}

				else
				{
					TaskTiming[Local_Counter]--;
				}
			}
		}
	}
}

u8 RTOS_u8DeleteTask(u8 Copy_u8Priority)
{
	u8 Local_ErrorState = 0;
	if (SystemTasks[Copy_u8Priority].TaskHandler != 0)
	{
		/* Task exist, execute the removal */
		SystemTasks[Copy_u8Priority] = Empty;
	}

	else
	{
		/* Task not exist */
		Local_ErrorState = 1;
	}

	return Local_ErrorState;

}

u8 RTOS_u8SuspendTask(u8 Copy_u8Priority)
{
	u8 Local_ErrorState = 0;
	if (SystemTasks[Copy_u8Priority].TaskHandler != 0)
	{

		SystemTasks[Copy_u8Priority].TaskRunState = Suspended;
	}

	else
	{
		/* Task not exist */
		Local_ErrorState = 1;
	}

	return Local_ErrorState;
}

u8 RTOS_u8ResumeTask(u8 Copy_u8Priority)
{
	u8 Local_ErrorState = 0;
	if (SystemTasks[Copy_u8Priority].TaskHandler != 0)
	{

		SystemTasks[Copy_u8Priority].TaskRunState = Running;
	}

	else
	{
		/* Task not exist */
		Local_ErrorState = 1;
	}

	return Local_ErrorState;
}
void RTOS_voidStartOS(void)
{
	MSTK_vSetInterval_Periodic(RTOS_TICK_TIME,Scheduler);
}
