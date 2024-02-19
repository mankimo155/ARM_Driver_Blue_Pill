
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/SYSTICK/SISTICK_int.h"
#include "RTOS/RTOS_int.h"


void Toggle(void)
{
	MGPIO_vTogPinVal(PORTA,PIN0);
}
void Toggle_1(void)
{
	MGPIO_vTogPinVal(PORTA,PIN1);
}
void Toggle_2(void)
{
	MGPIO_vTogPinVal(PORTA,PIN2);
}
void Toggle_3(void)
{
	MGPIO_vTogPinVal(PORTA,PIN3);
}
void Toggle_4(void)
{
	MGPIO_vTogPinVal(PORTA,PIN4);
}
void Toggle_5(void)
{
	MGPIO_vTogPinVal(PORTA,PIN5);
}
void Toggle_6(void)
{
	MGPIO_vTogPinVal(PORTA,PIN6);
}
void Toggle_7(void)
{
	MGPIO_vTogPinVal(PORTA,PIN7);
}




int main(void)
{
	MRCC_vInit();
	MSTK_vInit();
	MRCC_vEnablClock(RCC_APB2,RCC_PORTA);

	for(u8 i = 0 ;i <8 ; i++)
	{
		MGPIO_vSetMode(PORTA,i,MODE_OUTPUT_PUSH_PULL_10MHZ);
	}


	RTOS_u8CreateTask(Toggle,10,0,0);
	RTOS_u8CreateTask(Toggle_1,15,1,1);
	RTOS_u8CreateTask(Toggle_2,20,2,2);
	RTOS_u8CreateTask(Toggle_3,24,3,3);
	RTOS_u8CreateTask(Toggle_4,28,4,4);
	RTOS_u8CreateTask(Toggle_5,32,5,5);
	RTOS_u8CreateTask(Toggle_6,46,6,6);
	RTOS_u8CreateTask(Toggle_7,54,7,7);
	RTOS_voidStartOS();






	while(1)
	{

	}
}
