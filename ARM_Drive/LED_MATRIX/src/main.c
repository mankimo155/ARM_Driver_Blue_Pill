

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/SYSTICK/SISTICK_int.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "HAL/LED_MATRIX/LED_MATRIX_int.h"
#include "HAL/S2P/S2P_int.h"



int main(void)
{



	MRCC_vInit();
	MRCC_vEnablClock(RCC_APB2,RCC_PORTA);
	MSTK_vInit();

	while(1)
	{



	}

}
