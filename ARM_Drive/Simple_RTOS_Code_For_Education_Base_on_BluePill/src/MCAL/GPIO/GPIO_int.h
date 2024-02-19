/*
 * GPIO_int.h
 *
 *  Created on: Jan 11, 2024
 *      Author: userH
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_
#include "../../LIB/STD_TYPES.h"

#define PORTA         0
#define PORTB         1
#define PORTC         2

#define PIN0          0
#define PIN1          1
#define PIN2          2
#define PIN3          3
#define PIN4          4
#define PIN5          5
#define PIN6          6
#define PIN7          7
#define PIN8          8
#define PIN9          9
#define PIN10         10
#define PIN11         11
#define PIN12         12
#define PIN13         13
#define PIN14         14
#define PIN15         15
#define GPIO_HIGH     1
#define GPIO_LOW      0

#define MODE_OUTPUT_PUSH_PULL_2MHZ                0b0010
#define MODE_OUTPUT_OPEN_DRIN_2MHZ                0b0110
#define MODE_OUTPUT_ALTREN_FUNC_PUSH_PULL_2MHZ    0b1010
#define MODE_OUTPUT_ALTREN_FUN_DRIN_2MHZ          0b1110

#define MODE_OUTPUT_PUSH_PULL_10MHZ               0b0001
#define MODE_OUTPUT_OPEN_DRIN_10MHZ               0b0101
#define MODE_OUTPUT_ALTREN_FUNC_PUSH_PULL_10MHZ   0b1001
#define MODE_OUTPUT_ALTREN_FUN_DRIN_10MHZ         0b1101

#define MODE_INPUT_ANALOG_                        0b0000
#define MODE_INPUT_FLOATING_                      0b0100
#define MODE_INPUT_PULL_UP_PULL_DOWIN             0b1000

typedef struct
{
	u8 PORTX ;
	u8 PINX  ;
	u8 MODE  ;
}GPIO_Set_t;


void MGPIO_vInit(GPIO_Set_t* GPIOX);
void MGPIO_vSetMode(u8 A_u8PortNO, u8 A_u8PinNo, u8 A_u8Mode);
void MGPIO_vSetPinVal(u8 A_u8PortNO, u8 A_u8PinNo, u8 A_u8PinVal);
u8 MGPIO_vGetPinVal(u8 A_u8PortNO, u8 A_u8PinNo);
void MGPIO_vSetPortValLowPart(u8 A_u8PortNO,u8 A_u8PortVal);
void MGPIO_vSetPortValHighPart(u8 A_u8PortNO,u8 A_u8PortVal);
void MGPIO_vTogPinVal(u8 A_u8PortNO, u8 A_u8PinNo);
void MGPIO_vSetAlternativeFunction(u8 A_u8PortId , u8 A_u8PinNo,u8 A_u8AltFun);


#endif /* MCAL_GPIO_GPIO_INT_H_ */
