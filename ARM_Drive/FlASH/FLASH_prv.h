/*
 * FLASH_prv.h
 *
 *  Created on: Feb 9, 2024
 *      Author: userH
 */

#ifndef MCAL_FLASH_FLASH_PRV_H_
#define MCAL_FLASH_FLASH_PRV_H_


#define FLASH_ACR    (0x40022000)

#define KEY_1  0x45670123

#define KEY_2  0xCDEF89AB

typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 RESERCED;
	u32 OBR;
	u32 WRPA;

}FLASH_MamMor_t;

#define FIM  ((volatile FLASH_MamMor_t*)(FLASH_ACR))

#endif /* MCAL_FLASH_FLASH_PRV_H_ */
