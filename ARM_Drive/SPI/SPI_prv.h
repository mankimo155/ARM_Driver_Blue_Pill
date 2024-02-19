/*
 * SPI_prv.h
 *
 *  Created on: Jan 30, 2024
 *      Author: userH
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define CPHA     0
#define CPOL     1
#define MSTR     2
#define BUAD_RATE_2 0b000
#define LSB      7
#define SPE      6
#define SSM      9
#define SSI      8
#define DFF      11

#define SPI1_BASE_ADD  0x40013000


typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR ;
	u32 DR ;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_MamMap_t;


#define SPI ((volatile SPI_MamMap_t*)(SPI1_BASE_ADD))

#endif /* MCAL_SPI_SPI_PRV_H_ */
