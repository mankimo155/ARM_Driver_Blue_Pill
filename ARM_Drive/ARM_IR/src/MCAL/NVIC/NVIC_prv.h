/*
 * NVIC_prv.h
 *
 *  Created on: Jan 15, 2024
 *      Author: userH
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_


#define NVIC_BASE_ADR   0xE000E100

typedef struct
{
	volatile u32 ISER[2];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
	u32 RESERVED0[28];
	volatile u32 ICER[2];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
	u32 RSERVED1[28];
	volatile u32 ISPR[2];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
	u32 RESERVED2[28];
	volatile u32 ICPR[2];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
	u32 RESERVED3[28];
	volatile u32 IABR[2];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
	u32 RESERVED4[60];
	volatile u8  IPR[240];  /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
	u32 RESERVED5[644];
	volatile  u32 STIR;
}NVIC_MamMap_t;

#define NVIC  ((volatile NVIC_MamMap_t*)(NVIC_BASE_ADR))
#define AIRCR *((volatile u32*)(0xE000ED0C))
#define SHPR1 *((volatile u32*)(0xE000ED18))
#define SHPR2 *((volatile u32*)(0xE000ED1C))
#define SHPR3 *((volatile u32*)(0xE000ED20))

#endif /* MCAL_NVIC_NVIC_PRV_H_ */
