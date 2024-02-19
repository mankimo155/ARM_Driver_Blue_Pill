/*
 * LED_MATRIX_int.h
 *
 *  Created on: Jan 21, 2024
 *      Author: userH
 */

#ifndef HAL_LED_MATRIX_LED_MATRIX_INT_H_
#define HAL_LED_MATRIX_LED_MATRIX_INT_H_


void MLEDMTX_vInit(void);

void MLEDMTX_vDisplayFrame(u8 *AR_u8frame,u32 A_32uframe_delay);

//void MLEDMTX_DisplayMatrix(u8 AR_u8Matrix[][NO_COLS],u32 A_u32Martix_Delay);


#endif /* HAL_LED_MATRIX_LED_MATRIX_INT_H_ */
