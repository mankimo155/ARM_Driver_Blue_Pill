#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/SPI/SPI_int.h"
#include "TFT/TFT_int.h"
#include "TFT_test.h"


int main(void)
{
	MRCC_vInit();
	MRCC_vEnablClock(RCC_APB2,RCC_PORTA);
	MRCC_vEnablClock(RCC_APB2,12);
	MRCC_vEnablClock(RCC_APB2,RCC_AFIO);
	HTFT_vInit();
	HTFT_vShowImage(TFT_test,20480);
	//HTFT_vFillBackGround(0xFFFF);
	//HTFT_vFillRectangle(50,100,50,150,0x000);
	while(1)
	{

	}
}
