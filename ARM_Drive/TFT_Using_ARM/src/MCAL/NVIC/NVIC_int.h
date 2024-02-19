/*
 * NVIC_int.h
 *
 *  Created on: Jan 15, 2024
 *      Author: userH
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_


#define GROUP_4BITS 0b011
#define GROUP_3BITS 0b100
#define GROUP_2BITS 0b101
#define GROUP_1BITS 0b110
#define GROUP_0BITS 0b111

/////////////////////////
#define PEND_SV -6
#define SYSTICK -5
////////////////////////////
#define SV_CALL -4
/////////////////////////
#define MEMORY_MANAGE -3
#define BUS_FAULT -2
#define USAGE_FAULT -1
/////////////////////////
#define NO_GROUP_PRIORITY 0
#define GROUP_PRIORITY_0 0
#define GROUP_PRIORITY_1 1
#define GROUP_PRIORITY_2 2
#define GROUP_PRIORITY_3 3
#define GROUP_PRIORITY_4 4
#define GROUP_PRIORITY_5 5
#define GROUP_PRIORITY_6 6
#define GROUP_PRIORITY_7 7
#define GROUP_PRIORITY_8 8
#define GROUP_PRIORITY_9 9
#define GROUP_PRIORITY_10 10
#define GROUP_PRIORITY_11 11
#define GROUP_PRIORITY_12 12
#define GROUP_PRIORITY_13 13
#define GROUP_PRIORITY_14 14
#define GROUP_PRIORITY_15 15

#define NO_SUB_PRIORITY 0
#define SUB_PRIORITY_0 0
#define SUB_PRIORITY_1 1
#define SUB_PRIORITY_2 2
#define SUB_PRIORITY_3 3
#define SUB_PRIORITY_4 4
#define SUB_PRIORITY_5 5
#define SUB_PRIORITY_6 6
#define SUB_PRIORITY_7 7
#define SUB_PRIORITY_8 8
#define SUB_PRIORITY_9 9
#define SUB_PRIORITY_10 10
#define SUB_PRIORITY_11 11
#define SUB_PRIORITY_12 12
#define SUB_PRIORITY_13 13
#define SUB_PRIORITY_14 14
#define SUB_PRIORITY_15 15

typedef enum
{
	/******  STM32 specific Interrupt Numbers *********************************************************/
	WWDG_IRQnum                   = 0,      /*!< Window WatchDog Interrupt                            */
	PVD_IRQnum                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
	TAMPER_IRQnum                 = 2,      /*!< Tamper Interrupt                                     */
	RTC_IRQnum                    = 3,      /*!< RTC global Interrupt                                 */
	FLASH_IRQnum                  = 4,      /*!< FLASH global Interrupt                               */
	RCC_IRQnum                    = 5,      /*!< RCC global Interrupt                                 */
	EXTI0_IRQnum                  = 6,      /*!< EXTI Line0 Interrupt                                 */
	EXTI1_IRQnum                  = 7,      /*!< EXTI Line1 Interrupt                                 */
	EXTI2_IRQnum                  = 8,      /*!< EXTI Line2 Interrupt                                 */
	EXTI3_IRQnum                  = 9,      /*!< EXTI Line3 Interrupt                                 */
	EXTI4_IRQnum                  = 10,     /*!< EXTI Line4 Interrupt                                 */
	DMA1_Channel1_IRQnum          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
	DMA1_Channel2_IRQnum          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
	DMA1_Channel3_IRQnum          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
	DMA1_Channel4_IRQnum          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
	DMA1_Channel5_IRQnum          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
	DMA1_Channel6_IRQnum          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
	DMA1_Channel7_IRQnum          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
	ADC1_2_IRQnum                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
	USB_HP_CAN1_TX_IRQnum         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
	USB_LP_CAN1_RX0_IRQnum        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
	CAN1_RX1_IRQnum               = 21,     /*!< CAN1 RX1 Interrupt                                   */
	CAN1_SCE_IRQnum               = 22,     /*!< CAN1 SCE Interrupt                                   */
	EXTI9_5_IRQnum                = 23,     /*!< External Line[9:5] Interrupts                        */
	TIM1_BRK_IRQnum               = 24,     /*!< TIM1 Break Interrupt                                 */
	TIM1_UP_IRQnum                = 25,     /*!< TIM1 Update Interrupt                                */
	TIM1_TRG_COM_IRQnum           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
	TIM1_CC_IRQnum                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
	TIM2_IRQnum                   = 28,     /*!< TIM2 global Interrupt                                */
	TIM3_IRQnum                   = 29,     /*!< TIM3 global Interrupt                                */
	TIM4_IRQnum                   = 30,     /*!< TIM4 global Interrupt                                */
	I2C1_EV_IRQnum                = 31,     /*!< I2C1 Event Interrupt                                 */
	I2C1_ER_IRQnum                = 32,     /*!< I2C1 Error Interrupt                                 */
	I2C2_EV_IRQnum                = 33,     /*!< I2C2 Event Interrupt                                 */
	I2C2_ER_IRQnum                = 34,     /*!< I2C2 Error Interrupt                                 */
	SPI1_IRQnum                   = 35,     /*!< SPI1 global Interrupt                                */
	SPI2_IRQnum                   = 36,     /*!< SPI2 global Interrupt                                */
	USART1_IRQnum                 = 37,     /*!< USART1 global Interrupt                              */
	USART2_IRQnum                 = 38,     /*!< USART2 global Interrupt                              */
	USART3_IRQnum                 = 39,     /*!< USART3 global Interrupt                              */
	EXTI15_10_IRQnum              = 40,     /*!< External Line[15:10] Interrupts                      */
	RTCAlarm_IRQnum               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
	USBWakeUp_IRQnum              = 42      /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
}IRQnum_t;

void MNVIC_vEnableIntreupt(u8 A_u8IntreuptId);
void MNVIC_vDisableIntreupt(u8 A_u8IntreuptId);
void MNVIC_vSetPendingFlag(u8 A_u8IntreuptId);
void MNVIC_vClearPendingFlag(u8 A_u8IntreuptId);
u8   MNVIC_vGetActiveFlag(u8 A_u8IntreuptId);
void MNVIC_VoidSetPriority(s8 Copy_u8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);
void MNVIC_voidSetPriorityConfig(u8 Copy_u8Group);

#endif /* MCAL_NVIC_NVIC_INT_H_ */
