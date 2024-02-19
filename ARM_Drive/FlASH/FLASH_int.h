/*
 * FLASH_int.h
 *
 *  Created on: Feb 9, 2024
 *      Author: userH
 */

#ifndef MCAL_FLASH_FLASH_INT_H_
#define MCAL_FLASH_FLASH_INT_H_

void MFMI_vEraseAppArea(void);
void MFMI_vSectorErase(u32 A_u8PageADD);
void MFMI_vFlashWrite(u32 A_u32Address,
		             u16* A_pu16Data,
					 u16  A_u16Length);



#endif /* MCAL_FLASH_FLASH_INT_H_ */
