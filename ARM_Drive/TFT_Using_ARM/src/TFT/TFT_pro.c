/*
 * TFT_pro.c
 *
 *  Created on: Jan 31, 2024
 *      Author: userH
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "../MCAL/SYSTICK/SISTICK_int.h"
#include "../MCAL/SPI/SPI_int.h"

#include "TFT_int.h"
#include "TFT_cfg.h"
#include "TFT_prv.h"

void Reset_seq(void)
{
	MGPIO_vSetPinVal(PORTA,PIN0,GPIO_HIGH);
	MSTK_vDelay(100);
	MGPIO_vSetPinVal(PORTA,PIN0,GPIO_LOW);
	MSTK_vDelay(1);
	MGPIO_vSetPinVal(PORTA,PIN0,GPIO_HIGH);
	MSTK_vDelay(100);
	MGPIO_vSetPinVal(PORTA,PIN0,GPIO_LOW);
	MSTK_vDelay(100);
	MGPIO_vSetPinVal(PORTA,PIN0,GPIO_HIGH);
	MSTK_vDelay(MS_1*120);

}

void vWrite_cmd(u16 cmd)
{
	MGPIO_vSetPinVal(PORTA,PIN1,GPIO_LOW);
	(void)MSPI_u16TranSceive(cmd);

}
void vWrite_data(u16 Data)
{
	MGPIO_vSetPinVal(PORTA,PIN1,GPIO_HIGH);
	(void)MSPI_u16TranSceive(Data);
}

void HTFT_vInit(void)
{
	MGPIO_vSetMode(PORTA,PIN0,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MGPIO_vSetMode(PORTA,PIN1,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MSPI_vInit();
	MSTK_vInit();
	Reset_seq();
	vWrite_cmd(0x11);
	MSTK_vDelay(MS_1*15);
	vWrite_cmd(0x3A);
	vWrite_data(0x05);
	vWrite_cmd(0x29);


}



void HTFT_vShowImage(u16 A_puImg[],u32 A_u32ImgSize )
{
	vWrite_cmd(0x2A);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(127);
	vWrite_cmd(0x2B);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(159);
	vWrite_cmd(0x2C);
	for(u32 i = 0; i<A_u32ImgSize;i++)
	{
		vWrite_data(A_puImg[i]>>8);
		vWrite_data(A_puImg[i]);
	}

}

void HTFT_vSetXpos(u16 A_u16Xstart,u16 A_u16Xend)
{
	vWrite_cmd(0x2A);
	vWrite_data(0);
	vWrite_data(A_u16Xstart);
	vWrite_data(0);
	vWrite_data(A_u16Xend);

}

void HTFT_vSetYpos(u16 A_u16Ystart,u16 A_u16Yend)
{
	vWrite_cmd(0x2B);
	vWrite_data(0);
	vWrite_data(A_u16Ystart);
	vWrite_data(0);
	vWrite_data(A_u16Yend);
}
void HTFT_vFillRectangle(u8 x1,u8 x2 ,u8 y1,u8 y2 ,u16 A_u16Color)
{
	u16 A_u16size = (x2-x1)*(y2-y1);
	vWrite_cmd(0x2A);
	vWrite_data(0);
	vWrite_data(x1);
	vWrite_data(0);
	vWrite_data(x2);
	vWrite_cmd(0x2B);
	vWrite_data(0);
	vWrite_data(y1);
	vWrite_data(0);
	vWrite_data(y2);
	vWrite_cmd(0x2C);
	for(u32 i = 0; i<A_u16size;i++)
	{
		vWrite_data(A_u16Color>>8);
		vWrite_data(A_u16Color);

	}
}

void HTFT_vFillBackGround(u16 A_u16Color)
{
	vWrite_cmd(0x2A);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(127);
	vWrite_cmd(0x2B);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(0);
	vWrite_data(159);
	vWrite_cmd(0x2C);
	for(u32 i = 0; i<20480;i++)
	{
		vWrite_data(A_u16Color>>8);
		vWrite_data(A_u16Color);

	}

}

