/*
 * UART_pro.c
 *
 *  Created on: Feb 1, 2024
 *      Author: userH
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"



#include "UART_int.h"
#include "UART_cfg.h"
#include "UART_prv.h"

void (*CallBack_Fun)(void);

void MUSART_vInit(UART_InitType* PS_InitStruct,
		         UART_ClockInitType* PS_InitClockStruct,
				 UART_MamMap_t* UARTx )
{
	UARTx->BRR = UART_BRR_SAMPLING8(__PCLK__,PS_InitStruct->BaudRate);
	UARTx->CR1=(PS_InitStruct->DataWidth<<MUSART_CR1_M_BIT)|
			    (PS_InitStruct->Parity_Enable<<MUSART_CR1_PCE_BIT)|
				(PS_InitStruct->Parity_Selection<<MUSART_CR1_PS_BIT);
		switch(PS_InitStruct->TxDirection)
		{
		case TX_Only:SET_BIT(UARTx->CR1,MUSART_CR1_TE_BIT);break;
		case RX_Only:SET_BIT(UARTx->CR1,MUSART_CR1_RE_BIT);break;
		case TX_RX_EN:
		SET_BIT(UARTx->CR1,MUSART_CR1_TE_BIT);
		SET_BIT(UARTx->CR1,MUSART_CR1_RE_BIT);
		break;
		}
		UARTx->CR2 =(PS_InitStruct->StopBit<<MUSART_CR2_STOP_BIT)|
		        (PS_InitClockStruct->ClockOutput<<MUSART_CR2_CLKEN_BIT)|
				(PS_InitClockStruct->ClockPhase<<MUSART_CR2_CPHA_BIT)|
				((PS_InitClockStruct->ClockPolarity<<MUSART_CR2_CPOL_BIT))|
				((PS_InitClockStruct->LastBitclock<<MUSART_CR2_LBCL_BIT));
		UARTx->SR=0;


}

void MUSART_Enable(UART_MamMap_t *USARTx)
{
	SET_BIT(USARTx->CR1,MUSART_CR1_UE_BIT);
}

void MUSART_voidTransmitByte (UART_MamMap_t *USARTx,u8 A_u8Byte)
{
	while(GET_BIT(USARTx->SR,MUSART_SR_TXE_BIT)==0){}
	USARTx->DR=A_u8Byte;
	while(GET_BIT(USARTx->SR,MUSART_SR_TC_BIT)==0){}
	CLR_BIT(USARTx->SR,MUSART_SR_TC_BIT);
}
void MUSART_voidTransmitString (UART_MamMap_t *USARTx, u8 * A_ptru8String )
{
	u8 L_u8Iterator=0;
	while(A_ptru8String[L_u8Iterator]!='\0')
	{
		MUSART_voidTransmitByte(USARTx,A_ptru8String[L_u8Iterator]);
		L_u8Iterator++;
	}
}

u8 MUSART_u8ReceiveByteSynchNonBlocking ( UART_MamMap_t *USARTx )
{
	u8 L_u8Data=0;
	u32 L_u32TimeOut=0;
	while((GET_BIT(USARTx->SR,MUSART_SR_RXNE_BIT)==0) && (L_u32TimeOut<THRESHOLD_VALUE))
		{
		L_u32TimeOut++;
		}
	if(L_u32TimeOut==THRESHOLD_VALUE)
	{
		L_u8Data=255;
	}
	else
	{
		L_u8Data=USARTx->DR;
	}
	return L_u8Data;

}
void MUSART1_voidSetCallBack( void (*ptr) (void) )
{
	CallBack_Fun=ptr;
}
void USART1_IRQHandler(void)
{
	UART1 -> SR = 0 ;
	CallBack_Fun();
}
