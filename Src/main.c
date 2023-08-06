/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Seif Eldidi
 * @brief          : Main program body
 ******************************************************************************
*/

#include <stdint.h>
#include "HAL/Hal_RCC.h"
#include "core/CortexM4_core_Systick.h"
#include "HAL/Hal_GPIO.h"
#include "core/CortexM4_core_NVIC.h"
#include "HAL/Hal_ADC.h"
#include "HAL/Hal_Usart.h"
#include "HAL/hal_Timer.h"

uint32_t IR_RemoteCode ;
uint32_t overflow ;
uint8_t ISR_FIRED;
uint32_t Prev_Code ;

void ISR_Timer()
{
	static uint32_t OV ;
	overflow++;
	if(ISR_FIRED == 0)
		OV = overflow;
	else if(ISR_FIRED == 1)
	{
		if(overflow - OV >= 4)
		{
			overflow = OV;
			ISR_FIRED=0;
			NVIC_EnableIRQ(EXTI0_IRQ);
		}
	}
}

void IR_REMOTE_FRAME_READ_ISR()
{
	GPIO_State EDGE ;
	EDGE = HAL_GPIO_ReadPin (GPIOA ,GPIO_PIN_0);
	static uint8_t Repeat_FLAG ;
	static uint32_t Time_Delay_HIGH_US ;
	static uint32_t Time_Period_US     ;
	static int32_t BIT_POS = 31;
	static uint32_t ISR_VIST ;
	static uint32_t BIT_Counter ;
	/*------Reset Bit_Counter if Bit>33 as a full frame is recieved---*/
	if(BIT_Counter > 33)
	{
		BIT_POS = 31 ;
		BIT_Counter = 0;
		/*------Do Not update Code Recived if A repeat code is sent---*/
		if(Repeat_FLAG == 0)
			Prev_Code = IR_RemoteCode;
		IR_RemoteCode = 0;
		/*------a Global Flag to turn off the interrupt for a small delay---*/
		ISR_FIRED = 1;
		NVIC_DisableIRQ(EXTI0_IRQ);
	}
	/*-------Check For Falling Edge-----*/
	if( EDGE == GPIO_PIN_RESET)
	{
		/*------check for the first falling edge---*/
		if(ISR_VIST == 0)
		{
			ISR_VIST = 1;
		}
		/*------check for the second falling edge to read data---*/
		else if (ISR_VIST == 2)
		{
			BIT_Counter++;
			Time_Period_US = uHAL_TIMERGETTicks(TIM2);
			/*----Calculate Time Difference between Second Falling edge and Rising Edge--*/
			if(Time_Period_US > Time_Delay_HIGH_US)
				Time_Period_US = Time_Period_US -Time_Delay_HIGH_US;
			else
				Time_Period_US = Time_Period_US + 70000 -Time_Delay_HIGH_US;
			/*Process Time */
			/*----if the pulse is sent for about 560us a zero is detected--*/
			if(Time_Period_US <= 590 && Time_Period_US>= 500)
				CLEAR_BIT(IR_RemoteCode,BIT_POS--);
			/*----if the pulse is sent for about 1687us a zero is detected--*/
			else if(Time_Period_US <= 1770 && Time_Period_US >=1600)
				SET_BIT(IR_RemoteCode,BIT_POS--);
			/*----Repeat Code--*/
			else if(Time_Period_US <= 2475 && Time_Period_US >2150)
				Repeat_FLAG=1;
			/*----HIGH period of Normal Frame--*/
			else if(Time_Period_US <= 4950 && Time_Period_US >4200)
			{
				Repeat_FLAG=0;
				BIT_POS = 31 ;
			}
			/*Reset */
			ISR_VIST = 0;
			Time_Delay_HIGH_US = 0;
			Time_Period_US = 0;
		}
	}/*-------Check for Rising Edge------*/
	else if( EDGE == GPIO_PIN_SET )
	{
		Time_Delay_HIGH_US = uHAL_TIMERGETTicks(TIM2) ;
		ISR_VIST = 2;
	}
}

int main(void)
{
	/* RCC configuration Structure */
	RCC_Config_t RCC_Config = {
			.MSTR_CLK_SRC = SW_CLK_PLLO,
			.PLL_SRC = PLL_HSE,
			.PLL_M = 25,
			.PLL_N = 168,
			.PLL_P = PLLP_2,
			.PLL_Q = PLLQ_4_S,
			.AHB_PRE = AHBDIV_1,
			.APB1_PRE = APB_AHB_2,
			.APB2_PRE = APB_AHB_1,
	};
	/* SystemClock Init */
	HAL_RCC_Init(&RCC_Config);
	SystemCoreClockUpdate();
	/*------------Timer Init----------*/
	Timer_Config_t Timer_t = {
			.Timer_Mode = TIMX_DELAY_MODE,
			.Instance = TIM2,
			.Timer.Int_EN_DIS = TIMER_INT_EN,
			.Timer.TimerCallback = ISR_Timer,
			.Timer.Base_MS = BASE_USER_DEFINED,
			.Timer.AutoReloadVal = 70000,
			.Timer.Prescaler = 84,
			.Timer.Counter_Mode= TIMER_COUNTER_UP,
	};
	GPIO_InitStruct GPIO_PIN ={
				.Pin = GPIO_PIN_1|GPIO_PIN_2,
				.Speed = GPIO_Speed_50MHz,
				.mode = GPIO_MODE_OUTPUT_PP,
				.pull = GPIO_NOPULL,
	};
	GPIO_InitStruct GPIO_IR_PIN ={
			.GPIO0_Callbck = IR_REMOTE_FRAME_READ_ISR,
			.Pin  = GPIO_PIN_0,
			.mode = GPIO_MODE_IT_RISING_FALLING,
			.pull = GPIO_NOPULL,
	};
	HAL_GPIO_Init(GPIOA,&GPIO_PIN);
	HAL_GPIO_Init(GPIOA,&GPIO_IR_PIN);
	/*-----Init Timer---*/
	xHAL_TIMERInit(&Timer_t);
	while(1)
	{
		if(Prev_Code == 0xFFA25D)
		{
			Prev_Code = 0x00;
			HAL_GPIO_TogglePin(GPIOA , GPIO_PIN_1);
		}
		else if(Prev_Code == 0xFF629D)
		{
			Prev_Code = 0x00;
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
		}
	}
	return 0;
}



