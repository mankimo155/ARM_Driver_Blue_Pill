/*
 * SPI_pro.c
 *
 *  Created on: Jan 30, 2024
 *      Author: userH
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../GPIO/GPIO_int.h"

#include "SPI_int.h"
#include "SPI-cfg.h"
#include "SPI_prv.h"




void MSPI_vInit(void)
{
	 /*SPI ENABLE*/
	 SET_BIT(SPI->CR1,SPE);
	 SET_BIT(SPI->CR2,2);
	/*SPI MODE: CPHA & CPOL*/
	 SET_BIT(SPI->CR1,CPOL);
	 SET_BIT(SPI->CR1,CPHA);
	 /*Select Master/Slave Mode*/
	 SET_BIT(SPI->CR1,MSTR);
	 /*Select Baud Rate*/
	 SPI->CR1=(SPI->CR1 & (~(0b111<<3)))|(SPI_BUD_RATE<<3);
	 /*MSB OR LSB */
	 CLR_BIT(SPI->CR1,LSB);
	 /*SSM & SSI Cfg*/
	 SET_BIT(SPI->CR1,SSM);
	 SET_BIT(SPI->CR1,SSI);
	 /*Data Format*/
	 CLR_BIT(SPI->CR1,DFF);

	 //SPI->CR1=0b0000001101101111;
	 MGPIO_vSetMode(PORTA,PIN6,MODE_INPUT_FLOATING_);
	 MGPIO_vSetMode(PORTA,PIN7,MODE_OUTPUT_ALTREN_FUNC_PUSH_PULL_10MHZ);
	 MGPIO_vSetMode(PORTA,PIN5,MODE_OUTPUT_ALTREN_FUNC_PUSH_PULL_10MHZ);


}
u16 MSPI_u16TranSceive(u16 A_u16Data)
{
	SPI->DR = A_u16Data;
	while(GET_BIT(SPI->SR,7) == 1){}
	return SPI->DR ;
}



