/*
 * Hal_Timer.c
 *
 *  Created on: Aug 4, 2023
 *      Author: Seif pc
 */
#include "../../Inc/HAL/Hal_Timer.h"

#if configHALTIMER1_DELAY_INT == EN
static void (*Timer1Callback)(void);
#endif

#if configHALTIMER1_CCP1_INT
static void (*Timer1CCP1Callback)(void);
#endif

#if configHALTIMER1_CCP2_INT
static void (*Timer1CCP2Callback)(void);
#endif

#if configHALTIMER1_CCP3_INT
static void (*Timer1CCP3Callback)(void);
#endif

#if configHALTIMER1_CCP4_INT
static void (*Timer1CCP4Callback)(void);
#endif

#if configHALTIMER2_DELAY_INT == EN
static void (*Timer2Callback)(void);
#endif

#if configHALTIMER2_CCP1_INT
static void (*Timer2CCP1Callback)(void);
#endif

#if configHALTIMER2_CCP2_INT
static void (*Timer2CCP2Callback)(void);
#endif

#if configHALTIMER2_CCP3_INT
static void (*Timer2CCP3Callback)(void);
#endif

#if configHALTIMER2_CCP4_INT
static void (*Timer2CCP4Callback)(void);
#endif

#if configHALTIMER3_DELAY_INT == EN
static void (*Timer3Callback)(void);
#endif

#if configHALTIMER3_CCP1_INT
static void (*Timer3CCP1Callback)(void);
#endif

#if configHALTIMER3_CCP2_INT
static void (*Timer3CCP2Callback)(void);
#endif

#if configHALTIMER3_CCP3_INT
static void (*Timer3CCP3Callback)(void);
#endif

#if configHALTIMER3_CCP4_INT
static void (*Timer3CCP4Callback)(void);
#endif


#if configHALTIMER4_DELAY_INT == EN
static void (*Timer4Callback)(void);
#endif

#if configHALTIMER4_CCP1_INT
static void (*Timer4CCP1Callback)(void);
#endif

#if configHALTIMER4_CCP2_INT
static void (*Timer4CCP2Callback)(void);
#endif

#if configHALTIMER4_CCP3_INT
static void (*Timer4CCP3Callback)(void);
#endif

#if configHALTIMER4_CCP4_INT
static void (*Timer4CCP4Callback)(void);
#endif


#if configHALTIMER5_DELAY_INT == EN
static void (*Timer5Callback)(void);
#endif

#if configHALTIMER5_CCP1_INT
static void (*Timer5CCP1Callback)(void);
#endif

#if configHALTIMER5_CCP2_INT
static void (*Timer5CCP2Callback)(void);
#endif

#if configHALTIMER5_CCP3_INT
static void (*Timer5CCP3Callback)(void);
#endif

#if configHALTIMER5_CCP4_INT
static void (*Timer5CCP4Callback)(void);
#endif



static void vTimerINT_Init(TIM_TypeDef * TIM_INST, void (*Func)(void))
{
	if (TIM_INST == TIM1) {
#if configHALTIMER1_INT_EN == EN
		Timer1Callback = Func;
		NVIC_EnableIRQ(EXTI15_10_IRQ);
#endif
	} else if (TIM_INST == TIM2) {
#if configHALTIMER2_DELAY_INT == EN
		Timer2Callback = Func;
		NVIC_EnableIRQ(TIM2_IRQ);
#endif
	} else if (TIM_INST == TIM3) {
#if configHALTIMER3_INT_EN == EN
		Timer3Callback = Func;
		NVIC_EnableIRQ(TIM3_IRQ);
#endif
	} else if (TIM_INST == TIM4) {
#if configHALTIMER4_INT_EN == EN
		Timer4Callback = Func;
		NVIC_EnableIRQ(TIM4_IRQ);
#endif
	} else if (TIM_INST == TIM5) {
#if configHALTIMER5_INT_EN == EN
		Timer5Callback = Func;
		NVIC_EnableIRQ(TIM5_IRQ);
#endif
	}
}

#if configHALTIMER2_DELAY_INT == EN
void TIM2_IRQHandler()
{
	NVIC_ClearPendingIRQ(TIM2_IRQ);
#if configHALTIMER2_DELAY_INT == EN
	TIM2->SR &=~(UIE_READ);
	if(Timer2Callback != NULL)
		Timer2Callback();
#endif
#if configHALTIMER2_CCP_EN == EN

#endif
}
#endif

#if configHALTIMER3_INT_EN == EN
void TIM3_IRQHandler()
{
	NVIC_ClearPendingIRQ(TIM3_IRQ);
#if configHALTIMER3_DELAY_EN == EN
	TIM3->SR &=~(UIE_READ);
	if(Timer3Callback != NULL)
		Timer3Callback();
#endif
}
#endif

#if configHALTIMER4_INT_EN == EN
void TIM4_IRQHandler()
{
	NVIC_ClearPendingIRQ(TIM4_IRQ);
#if configHALTIMER4_DELAY_EN == EN
	TIM4->SR &=~(UIE_READ);
	if(Timer4Callback != NULL)
		Timer4Callback();
#endif
}
#endif

#if configHALTIMER5_INT_EN == EN
void TIM5_IRQHandler()
{
	NVIC_ClearPendingIRQ(TIM5_IRQ);
#if configHALTIMER5_DELAY_EN == EN
	TIM5->SR &=~(UIE_READ);
	if(Timer5Callback != NULL)
		Timer5Callback();
#endif
}
#endif



/* Name   : static void vTimerCLK_EN(TIM_TypeDef * TIM_INST)
 * brief  : Software API to En Clock of Timer
 * param  : takes TIM_TypeDef * TIM_INST
 * return : nothing
 */
static void vTimerCLK_EN(TIM_TypeDef * TIM_INST)
{

	if(TIM_INST == TIM1)
	{
		HAL_RCC_TIM1_EN();
	}
	else if( TIM_INST == TIM2)
	{
		HAL_RCC_TIM2_EN();
	}
	else if( TIM_INST == TIM3)
	{
		HAL_RCC_TIM3_EN();
	}
	else if( TIM_INST == TIM4)
	{
		HAL_RCC_TIM4_EN();
	}
	else if( TIM_INST == TIM5)
	{
		HAL_RCC_TIM5_EN();
	}
	else if( TIM_INST == TIM9)
	{
		HAL_RCC_TIM9_EN();
	}else if( TIM_INST == TIM10)
	{
		HAL_RCC_TIM10_EN();
	} else if( TIM_INST == TIM11)
	{
		HAL_RCC_TIM11_EN();
	}
}

/* Name   : static uint32_t uTimer_Freq(TIM_TypeDef * TIM_INST)
 * brief  : Software API to Get Freq of Timer
 * param  : takes TIM_TypeDef * TIM_INST
 * return : uint32_t CLK_FREQ
 */

static uint32_t uTimer_Freq(TIM_TypeDef * TIM_INST)
{
	uint32_t CLK_FREQ = 0UL;
	if( TIM_INST == TIM2 || TIM_INST == TIM3 ||TIM_INST == TIM4 ||TIM_INST == TIM5 )
		CLK_FREQ = HAL_RCC_GET_APB2FREQ();
	else if(TIM_INST == TIM1 || TIM_INST == TIM9 ||TIM_INST == TIM10 ||TIM_INST == TIM11  )
		CLK_FREQ = HAL_RCC_GET_APB1FREQ();
	return CLK_FREQ;
}

/* Name   : static uint8_t uTimer_Size(TIM_TypeDef * TIM_INST)
 * brief  : Software API to get Size of Timer
 * param  : takes TIM_TypeDef * TIM_INST
 * return : Flag to indicate Size
 *
 */
static uint8_t uTimer_Size(TIM_TypeDef * TIM_INST)
{
	uint8_t Timer_Size = 0UL;
	if( TIM_INST == TIM2 || TIM_INST == TIM5  )
		Timer_Size = TIMER_32BIT;
	else
		Timer_Size = TIMER_16BIT;
	return Timer_Size;
}


#if configHALTIMER_DELAY_EN == EN


vHAL_TIMERSETTicks(TIM_TypeDef * Instance ,uint32_t Ticks)
{
	Instance->CNT = Ticks;
}

uint32_t uHAL_TIMERGETTicks(TIM_TypeDef * Instance)
{
	return Instance->CNT;
}

/* Name   : void vTimerBas1MSInit(TIM_TypeDef * Instance)
 * brief  : Software API to initiliaze Timer AutoReload Register
 * param  : takes Timer_Config_t *Timer To init Timer as 1ms Counter
 * return : whether the operation was successful or not
 * 			HAL_ERR Fail
 * 			HAL_OK  Success
 */

static void vTimerBas1MSInit(TIM_TypeDef * Instance)
{
	uint8_t Flag = uTimer_Size(Instance);
	if(Flag == TIMER_16BIT)
	{
		/*----Stop Timer-----*/
		Instance->CR1 &= CNT_DIS;
		/*----Find CLKFREQ---*/
		uint32_t      TIM_CLK  = uTimer_Freq(Instance);
		/*----Create 1ms Delay----*/
		uint32_t P  = TIM_CLK /1000;
		P /= 65535;
		P = P+1;
		uint32_t ARR = ((TIM_CLK/1000)%65535);
		Instance->PSC = P+1;
		Instance->ARR = 65535 - ARR;
	}else{
		/*----Stop Timer-----*/
		Instance->CR1 &= CNT_DIS;
		/*----Find CLKFREQ---*/
		uint32_t TIM_CLK = uTimer_Freq(Instance);
		TIM_CLK /= 1000;
		/*----Create 1ms Delay----*/
		Instance->PSC = 0;
		Instance->ARR = TIM_CLK ;
	}
}

/* Name   : void vTimerBas1USInit(TIM_TypeDef * Instance)
 * brief  : Software API to initiliaze Timer AutoReload Register
 * param  : takes Timer_Config_t *Timer To init Timer as 1Us Counter
 * return : whether the operation was successful or not
 * 			HAL_ERR Fail
 * 			HAL_OK  Success
 */


static void vTimerBas1USInit(TIM_TypeDef * Instance);

/* Name   : ERR xHAL_TIMERDelayInit(Timer_Config_t *Timer)
 * brief  : Software API to initiliaze Timer
 * param  : takes Timer_Config_t *Timer To init Timer As Up/down Counter
 * return : whether the operation was successful or not
 * 			HAL_ERR Fail
 * 			HAL_OK  Success
 */
static ERR xHAL_TIMERDelayInit(Timer_Config_t *Timer)
{
	ERR Err_State = HAL_OK;
	if( Timer != NULL)
	{
		TIM_TypeDef * TIM_INST = Timer->Instance;
		/*--------TimerCLK Config-----------------*/
		vTimerCLK_EN(TIM_INST);
		/*-------Config Timer in Up/Down Mode-------*/
		switch( Timer->Timer.Counter_Mode )
		{
			case TIMER_COUNTER_UP:
				TIM_INST->CR1 |= CMS_EDG;
				TIM_INST->CR1 &= CNT_UP;
				break;
			case TIMER_COUNTER_D:
				TIM_INST->CR1 |= CMS_EDG;
				TIM_INST->CR1 |= CNT_D;
				break;
			default:
				Err_State = HAL_ERR;
				break;
		}
		/*------Proceed if no Errors------*/
		if( Err_State == HAL_OK)
		{
			if(Timer->Timer.Base_MS == BASE_USER_DEFINED)
			{
				TIM_INST->CR1 &= ~(1<<1);
				TIM_INST->PSC = Timer->Timer.Prescaler;
				TIM_INST->ARR = Timer->Timer.AutoReloadVal;
			}else if(Timer->Timer.Base_MS == BASE_1MS_TICK )
			{
				vTimerBas1MSInit(TIM_INST);
			}else if(Timer->Timer.Base_MS == BASE_1US_TICK)
			{

			}
#if configHALTIMER2_DELAY_INT == EN
			/*-----------Configure Interupt-------*/
			if( Timer->Timer.Int_EN_DIS == TIMER_INT_EN)
			{
				vTimerINT_Init(TIM_INST,Timer->Timer.TimerCallback);
				TIM_INST->DIER |= UIE_EN;
			}
#endif
			TIM_INST->CR1 |= CNT_EN;
		}

	}else{
		Err_State = HAL_ERR;
	}
	return Err_State;
}

void vHAL_TIMERdelayMs(TIM_TypeDef * Instance ,uint32_t Delay)
{
	if( Instance != NULL)
	{
		/*----Stop Timer-----*/
		Instance->CR1 &= CNT_DIS;
		/*----Stop Timer-----*/
		uint32_t delay;
		Instance->CNT  = 0;
		Instance->CR1 |= CNT_EN;
		for(delay = 0 ;delay<=Delay-1; delay++ )
		{
			while(!(Instance->SR & UIE_READ));
			Instance->SR &=~UIE_READ;
		}
	}
}


#endif

#if configHALTIMX_CCP_EN
static void vHAL_TIMERCCP_PINInit(TIM_TypeDef * Instance , uint8_t Init_VAL ,uint8_t Channel)
{
	GPIO_InitStruct GPIO;
	GPIO.mode = GPIO_MODE_AF_PP;
	GPIO.Speed = GPIO_Speed_2MHz;
	GPIO.pull = GPIO_NOPULL;
	__IO GPIO_Typedef *GPIO_PORT = GPIOA;
	__IO uint32_t * AFR_REG = NULL;
	uint32_t Shift = 0;
	uint32_t CHN = 0;

	if (Init_VAL != TIMX_CCP1_DIS) {
		if (Instance == TIM1) {
			AFR_REG =(uint32_t*) (&GPIO_PORT->AFRH);
			CHN = 1;
			switch (Channel) {
			case TIMX_CHN_1:
				Shift = 0;
				GPIO.Pin = GPIO_PIN_8;
				break;
			case TIMX_CHN_2:
				Shift = 4;
				GPIO.Pin = GPIO_PIN_9;
				break;
			case TIMX_CHN_3:
				Shift = 8;
				GPIO.Pin = GPIO_PIN_10;
				break;
			case TIMX_CHN_4:
				Shift = 12;
				GPIO.Pin = GPIO_PIN_11;
				break;
			}
		} else if (Instance == TIM2) {
			CHN = 1;
			AFR_REG = (uint32_t*)(&GPIO_PORT->AFRL);
			switch (Channel) {
			case TIMX_CHN_1:
				GPIO.Pin = GPIO_PIN_0;
				Shift =0;
				break;
			case TIMX_CHN_2:
				GPIO.Pin = GPIO_PIN_1;
				Shift =4;
				break;
			case TIMX_CHN_3:
				GPIO.Pin = GPIO_PIN_2;
				Shift =8;
				break;
			case TIMX_CHN_4:
				GPIO.Pin = GPIO_PIN_3;
				Shift =12;
				break;
			}
		} else if (Instance == TIM3) {
			CHN = 2;
			AFR_REG = (uint32_t*)(&GPIO_PORT->AFRL);
			switch (Channel) {
			case TIMX_CHN_1:
				Shift = 24;
				GPIO.Pin = GPIO_PIN_6;
				break;
			case TIMX_CHN_2:
				Shift = 28;
				GPIO.Pin = GPIO_PIN_7;
				break;
			case TIMX_CHN_3:
				Shift = 0;
				GPIO.Pin = GPIO_PIN_0;
				GPIO_PORT = GPIOB;
				AFR_REG = (uint32_t*)(&GPIO_PORT->AFRL);
				break;
			case TIMX_CHN_4:
				Shift = 4;
				GPIO.Pin = GPIO_PIN_1;
				GPIO_PORT = GPIOB;
				AFR_REG =(uint32_t*)(&GPIO_PORT->AFRL);
				break;
			}

		} else if (Instance == TIM4) {
			CHN = 2;
			GPIO_PORT = GPIOB;
			AFR_REG = (uint32_t*)(&GPIO_PORT->AFRL);
			switch (Channel) {
			case TIMX_CHN_1:
				Shift = 24;
				GPIO.Pin = GPIO_PIN_6;
				break;
			case TIMX_CHN_2:
				Shift = 28;
				GPIO.Pin = GPIO_PIN_7;
				break;
			case TIMX_CHN_3:
				GPIO.Pin = GPIO_PIN_8;
				Shift = 0;
				AFR_REG = (uint32_t*)(&GPIO_PORT->AFRH);
				break;
			case TIMX_CHN_4:
				Shift = 0;
				GPIO.Pin = GPIO_PIN_9;
				AFR_REG =(uint32_t*)(&GPIO_PORT->AFRH);
				break;
			}
		} else if (Instance == TIM5) {
			CHN = 2;
			AFR_REG = (uint32_t*)(&GPIO_PORT->AFRL);
			switch (Channel) {
			case TIMX_CHN_1:
				GPIO.Pin = GPIO_PIN_0;
				Shift =0;
				break;
			case TIMX_CHN_2:
				GPIO.Pin = GPIO_PIN_1;
				Shift =4;
				break;
			case TIMX_CHN_3:
				GPIO.Pin = GPIO_PIN_2;
				Shift =8;
				break;
			case TIMX_CHN_4:
				GPIO.Pin = GPIO_PIN_3;
				Shift =12;
				break;
			}
		}
		HAL_GPIO_Init(GPIO_PORT, &GPIO);
		*AFR_REG &= (~((0x0F)<<Shift));
		*AFR_REG |= (CHN)<<Shift;
	}
}


static void vHAL_TIMERCCPX_PINInit(TIM_TypeDef * Instance , uint8_t Init_VAL ,uint8_t Channel)
{
	if(Init_VAL != TIMX_CCP1_DIS)
	{
	switch (Channel) {
		case TIMX_CHN_1:
				switch(Init_VAL)
				{
					case TIMX_CCP1_ACT_LOW:
						Instance->CCMR1 |= OC1M_LOW;
						break;
					case TIMX_CCP1_ACT_HIGH:
						Instance->CCMR1 |= OC1M_HIGH;
						break;
					case TIMX_CCP1_TOGGLE:
						Instance->CCMR1 |= OC1M_TOGG;
						break;
					default:
						break;
				}
				Instance->CCER |= CC1E_EN;
			break;
		case TIMX_CHN_2:
				switch(Init_VAL)
				{
					case TIMX_CCP1_ACT_LOW:
						Instance->CCMR1 |= OC2M_LOW;
						break;
					case TIMX_CCP1_ACT_HIGH:
						Instance->CCMR1 |= OC2M_HIGH;
						break;
					case TIMX_CCP1_TOGGLE:
						Instance->CCMR1 |=OC2M_TOGG;
						break;
					default:
						break;
				}
				Instance->CCER |= CC2E_EN;
			break;
		case TIMX_CHN_3:
				switch(Init_VAL)
				{
					case TIMX_CCP1_ACT_LOW:
						Instance->CCMR2 |= OC3M_LOW;
						break;
					case TIMX_CCP1_ACT_HIGH:
						Instance->CCMR2 |= OC3M_HIGH;
						break;
					case TIMX_CCP1_TOGGLE:
						Instance->CCMR2 |=OC3M_TOGG;
						break;
					default:
						break;
			   }
				Instance->CCER |= CC3E_EN;
		   break;
		case TIMX_CHN_4:
				switch(Init_VAL)
				{
					case TIMX_CCP1_ACT_LOW:
						Instance->CCMR2 |= OC4M_LOW;
						break;
					case TIMX_CCP1_ACT_HIGH:
						Instance->CCMR2 |= OC4M_HIGH;
						break;
					case TIMX_CCP1_TOGGLE:
						Instance->CCMR2 |=OC4M_TOGG;
						break;
					default:
						break;
				}
				Instance->CCER |= CC4E_EN;
			break;
	}
	}
}

static ERR  vHAL_TIMERCCPX_Init(Timer_Config_t *Timer)
{
	ERR Err_State = HAL_OK;
	if( Timer != NULL)
	{
		vTimerCLK_EN(Timer->Instance);
		uint8_t CCPX_CNT = 0;
		const uint8_t CCPX = 0x03;
		for(CCPX_CNT = 0 ;CCPX_CNT<=3 ;CCPX_CNT++)
		{
			uint8_t Init_VAL = (Timer->Timer_CCP.TIMX_CCP_CHN_EN &(CCPX <<(CCPX_CNT *2)))>>(2*CCPX_CNT);
			vHAL_TIMERCCP_PINInit(Timer->Instance ,Init_VAL,CCPX_CNT);
			vHAL_TIMERCCPX_PINInit(Timer->Instance,Init_VAL,CCPX_CNT);
		}
		Timer->Instance->ARR  = Timer->Timer_CCP.ARR;
		Timer->Instance->PSC  = Timer->Timer_CCP.Prescaler;

		Timer->Instance->CCR1 = Timer->Timer_CCP.CCR1;
		Timer->Instance->CCR2 = Timer->Timer_CCP.CCR2;
		Timer->Instance->CCR3 = Timer->Timer_CCP.CCR3;
		Timer->Instance->CCR4 = Timer->Timer_CCP.CCR4;
#if configHALTIM_INT_EN

#endif
		Timer->Instance->CR1 |= CNT_EN;
	}else{
		Err_State = HAL_ERR;
	}
	return Err_State;
}

#endif

/* Name   : ERR xHAL_TIMERInit(Timer_Config_t *Timer)
 * brief  : Software API to initiliaze Timer
 * param  : takes Timer_Config_t *Timer To init Timer
 * return : whether the operation was successful or not
 * 			HAL_ERR Fail
 * 			HAL_OK  Success
 */
ERR xHAL_TIMERInit(Timer_Config_t *Timer)
{
	ERR Err_State = HAL_OK;
	if (Timer != NULL) {
		switch(Timer->Timer_Mode)
		{
			case TIMX_DELAY_MODE:
#if configHALTIMER_DELAY_EN == EN
				xHAL_TIMERDelayInit(Timer);
#endif
				break;
			case TIMX_ICP_MODE:
#if configHALTIMX_ICP_EN
				break;
#endif
			case TIMX_CCP_MODE:
#if configHALTIMX_CCP_EN
				vHAL_TIMERCCPX_Init(Timer);
				break;
#endif
			case TIMX_PWM_MODE:
#if configHALTIMX_PWM_EN
				break;
#endif
			default:
				Err_State = HAL_ERR;
				break;
		}
	} else {
		Err_State = HAL_ERR;
	}
	return Err_State;
}
