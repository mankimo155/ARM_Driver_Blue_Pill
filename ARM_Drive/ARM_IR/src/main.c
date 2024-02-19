#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/SYSTICK/SISTICK_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/EXTI/EXTI_int.h"


u32 ARR[33]={0};
u8 G_u8Counter=0;
u8 G_u8Flage=0;
u8 G_u8Data=0;


void IR_Action(void)
{
	switch(G_u8Data)
	{
	case 12:
		G_u8Data=0;
		MGPIO_vTogPinVal(PORTA,PIN1);
		break;
	case 24:
		G_u8Data=0;
		MGPIO_vTogPinVal(PORTA,PIN2);
		break;
	case 94:
		G_u8Data=0;
		MGPIO_vTogPinVal(PORTA,PIN3);
		break;
	}

}

void STK(void)
{
	for(u8 i = 0 ; i<8 ; i++)
	{
		if((ARR[i+17]>=1000)&&(ARR[i+17]<=1200))
		{
			CLR_BIT(G_u8Data,i);
		}
		else if((ARR[i+17]>=2000)&&(ARR[i+17]<=2300))
		{
			SET_BIT(G_u8Data,i);
		}

	}
	G_u8Flage=0;
	G_u8Counter=0;
	IR_Action();

}



void IR(void)
{
	if(G_u8Flage==0)
	{
		G_u8Flage=1;
		MSTK_vSetInterval_Single(MS_1*90,STK);
	}
	else if(G_u8Flage==1)
	{
		ARR[G_u8Counter]=MSTK_u32GetElapsedTime();
		MSTK_vSetInterval_Single(MS_1*90,STK);
		G_u8Counter++;
	}


}




int main(void)
{
	MRCC_vInit();
	MSTK_vInit();
	MRCC_vEnablClock(RCC_APB2,RCC_PORTA);
	MRCC_vEnablClock(RCC_APB2,0);
	MGPIO_vSetMode(PORTA,PIN0,MODE_INPUT_FLOATING_);
	MGPIO_vSetMode(PORTA,PIN1,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MGPIO_vSetMode(PORTA,PIN2,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MGPIO_vSetMode(PORTA,PIN3,MODE_OUTPUT_PUSH_PULL_10MHZ);
	MEXTI_vSetCallBack(EXTI_LINE0,IR);
	MEXTI_vEnableLine(EXTI_FALLING,EXTI_LINE0);
	MNVIC_vEnableIntreupt(EXTI0_IRQnum);


	while(1)
	{


	}


}
