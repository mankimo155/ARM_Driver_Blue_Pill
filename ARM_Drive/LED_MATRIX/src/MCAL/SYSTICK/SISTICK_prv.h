/*
 * SISTICK_prv.h
 *
 *  Created on: Jan 17, 2024
 *      Author: userH
 */

#ifndef MCAL_SYSTICK_SISTICK_PRV_H_
#define MCAL_SYSTICK_SISTICK_PRV_H_


#define CLKS 2
#define STK_AHB 1
#define TICKINT 1
#define ENABLE 1
#define DISABLE 0
#define STK_ENABLE 0
#define STK_BASE_ADDR 0xE000E010
#define COUNTFLAG 16
typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}MSTK_MemMap_t;

#define STK ((volatile MSTK_MemMap_t*)(STK_BASE_ADDR))

#endif /* MCAL_SYSTICK_SISTICK_PRV_H_ */
