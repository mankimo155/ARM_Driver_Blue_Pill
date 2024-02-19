/*
 * GPIO_pro.c
 *
 *  Created on: Jan 11, 2024
 *      Author: userH
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_cnf.h"
#include "GPIO_prv.h"



void MGPIO_vSetMode(u8 A_u8PortNO,u8 A_u8PinNo,u8 A_u8Mode)
{
	if(A_u8PinNo<=7)
	{
		switch(A_u8PortNO)
		{


		case PORTA:
			GPIOA->CRL=((GPIOA->CRL)&(~((0b1111)<<(A_u8PinNo*4))))|(A_u8Mode<<(A_u8PinNo*4));
			break;
		case PORTB:
			GPIOB->CRL=((GPIOB->CRL)&(~((0b1111)<<(A_u8PinNo*4))))|(A_u8Mode<<(A_u8PinNo*4));
			break;
		case PORTC:
			GPIOC->CRL=((GPIOC->CRL)&(~((0b1111)<<(A_u8PinNo*4))))|(A_u8Mode<<(A_u8PinNo*4));
			break;
		}
	}
	else if(A_u8PinNo>7)
	{
		switch(A_u8PortNO)
		{

		case PORTA:
			GPIOA->CRH=((GPIOA->CRH)&(~((0b1111)<<(A_u8PinNo-8)*4)))|(A_u8Mode<<((A_u8PinNo-8)*4));
			break;
		case PORTB:
			GPIOB->CRH=((GPIOB->CRH)&(~((0b1111)<<(A_u8PinNo-8)*4)))|(A_u8Mode<<((A_u8PinNo-8)*4));
			break;
		case PORTC:
			GPIOC->CRH=((GPIOC->CRH)&(~((0b1111)<<((A_u8PinNo-8)*4))))|(A_u8Mode<<((A_u8PinNo-8)*4));
			break;
		}

	}


}
void MGPIO_vSetPinVal(u8 A_u8PortNO, u8 A_u8PinNo, u8 A_u8PinVal)
{

	if(A_u8PinVal==GPIO_HIGH)
	{
		switch (A_u8PortNO) {
		case PORTA :
			SET_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case PORTB :
			SET_BIT(GPIOB->ODR,A_u8PinNo);

			break;
		case PORTC :
			SET_BIT(GPIOC->ODR,A_u8PinNo);

			break;
		}
	}
	else if(A_u8PinVal==GPIO_LOW)
	{
		switch (A_u8PortNO) {
		case PORTA :
			CLR_BIT(GPIOA->ODR,A_u8PinNo);
			break;
		case PORTB :
			CLR_BIT(GPIOB->ODR,A_u8PinNo);
			break;
		case PORTC :
			CLR_BIT(GPIOC->ODR,A_u8PinNo);
			break;
		}

	}
}




u8 MGPIO_vGetPinVal(u8 A_u8PortNO, u8 A_u8PinNo)
{
	u8 L_u8Value=0;

	switch(A_u8PortNO)
	{
	case PORTA:
		L_u8Value=GET_BIT(GPIOA->IDR,A_u8PinNo);
		break;
	case PORTB:
		L_u8Value=GET_BIT(GPIOB->IDR,A_u8PinNo);
		break;
	case PORTC:
		L_u8Value=GET_BIT(GPIOC->IDR,A_u8PinNo);
		break;
	}
	return L_u8Value;
}
void MGPIO_vSetPortValLowPart(u8 A_u8PortNO,u8 A_u8PortVal)
{
	switch (A_u8PortNO) {
			case PORTA :
				GPIOA->ODR=(GPIOA->ODR & ~(0b11111111))|(A_u8PortVal);
				break;
			case PORTB :
				GPIOB->ODR=(GPIOB->ODR & ~(0b11111111))|(A_u8PortVal);
				break;
			case PORTC :
				GPIOC->ODR=(GPIOC->ODR & ~(0b11111111))|(A_u8PortVal);
				break;
			}



}
void MGPIO_vSetPortValHighPart(u8 A_u8PortNO,u8 A_u8PortVal)
{
	switch (A_u8PortNO) {
			case PORTA :
				GPIOA->ODR=(GPIOA->ODR & ~(0b11111111<<8))|(A_u8PortVal<<8);
				break;
			case PORTB :
				GPIOB->ODR=(GPIOB->ODR & ~(0b11111111<<8))|(A_u8PortVal<<8);
				break;
			case PORTC :
				GPIOC->ODR=(GPIOC->ODR & ~(0b11111111<<8))|(A_u8PortVal<<8);
				break;
			}



}
void MGPIO_vTogPinVal(u8 A_u8PortNO, u8 A_u8PinNo)
{
	switch (A_u8PortNO) {
	case PORTA :
		TOG_BIT(GPIOA->ODR,A_u8PinNo);
		break;
	case PORTB :
		TOG_BIT(GPIOB->ODR,A_u8PinNo);
		break;
	case PORTC :
		TOG_BIT(GPIOC->ODR,A_u8PinNo);

		break;
	}

}
void MGPIO_vInit(GPIO_Set_t* GPIOX)
{
	MGPIO_vSetMode(GPIOX->PORTX,GPIOX->PINX,GPIOX->MODE);

}
