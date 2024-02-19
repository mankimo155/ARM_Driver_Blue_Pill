/*
 * UART_int.h
 *
 *  Created on: Feb 1, 2024
 *      Author: userH
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

#define TX_Only    0
#define RX_Only    1
#define TX_RX_EN   2
#define DATA_8     0
#define DATA_9     1
#define EVEN_PARITY    0
#define ODD_PARITY    1
#define STOP_BIT_1 0
#define STOP_BIT_2 2
#define ENABLE     1
#define DISABLE     0




typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_MamMap_t;

#define UART1  ((UART_MamMap_t*)(0x40013800))

typedef struct
{
	u32 BaudRate;
	u8 DataWidth;
	u8 StopBit ;
	u8 Parity_Enable;
	u8 Parity_Selection;
	u8 TxDirection;
	u8 HardwareFlowControl;
}UART_InitType;

typedef struct
{
	u8 ClockOutput;
	u8 ClockPolarity;
	u8 ClockPhase;
	u8 LastBitclock;

}UART_ClockInitType;

//#define UART1  ((volatile UART_MamMap_t*)(UART_BASE_ADD))

void MUSART_vInit(UART_InitType* PS_InitStruct,
		         UART_ClockInitType* PS_InitClockStruct,
				 UART_MamMap_t* UARTx );
void MUSART_Enable(UART_MamMap_t *USARTx);
void MUSART_voidTransmitByte (UART_MamMap_t *USARTx,u8 A_u8Byte);
void MUSART_voidTransmitString (UART_MamMap_t *USARTx, u8 * A_ptru8String );
u8 MUSART_u8ReceiveByteSynchNonBlocking ( UART_MamMap_t *USARTx );
u8 * MUSART_ptrReceiveStringSynchNonBlocking ( UART_MamMap_t *USARTx );
void MUSART_RxIntSetStatus(UART_MamMap_t *USARTx, u8 copy_u8Status);
void MUSART_voidClearFlags(UART_MamMap_t *USARTx);
u8 MUSART_u8ReadDataRegister(UART_MamMap_t *USARTx);
void MUSART1_voidSetCallBack( void (*ptr) (void) );
void MUSART2_voidSetCallBack( void (*ptr) (void) );
void MUSART6_voidSetCallBack( void (*ptr) (void) );

#endif /* MCAL_UART_UART_INT_H_ */
