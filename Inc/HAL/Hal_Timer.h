/*
 * Hal_Timer.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Seif pc
 */

#ifndef HAL_HAL_TIMER_H_
#define HAL_HAL_TIMER_H_
/*-------------Includes Section Start---------------*/
#include <stdint.h>
#include "../std_macros.h"
#include "Hal_Timer_cfg.h"
#include "Hal_RCC.h"
#include "../core/CortexM4_core_NVIC.h"
#include "Hal_GPIO.h"
/*-------------Includes Section End----------------*/

/*------------Macro Declarations Start-----------*/
#define APB1_PERIPHBASE				0x40000000UL
#define APB2_PERIPHBASE				0x40011000UL

#define TIM1_OFFSET					0x00000000UL
#define TIM2_OFFSET					0x00000000UL
#define TIM3_OFFSET					0x00000400UL
#define TIM4_OFFSET					0x00000800UL
#define TIM5_OFFSET					0x00000C00UL
#define TIM9_OFFSET					0x00004000UL
#define TIM10_OFFSET				0x00004400UL
#define TIM11_OFFSET				0x00004800UL


#define TIM1						((__IO TIM_TypeDef *)(APB2_PERIPHBASE+TIM1_OFFSET))
#define TIM2						((__IO TIM_TypeDef *)(APB1_PERIPHBASE+TIM2_OFFSET))
#define TIM3						((__IO TIM_TypeDef *)(APB1_PERIPHBASE+TIM3_OFFSET))
#define TIM4						((__IO TIM_TypeDef *)(APB1_PERIPHBASE+TIM4_OFFSET))
#define TIM5						((__IO TIM_TypeDef *)(APB1_PERIPHBASE+TIM5_OFFSET))
#define TIM9						((__IO TIM_TypeDef *)(APB2_PERIPHBASE+TIM9_OFFSET))
#define TIM10						((__IO TIM_TypeDef *)(APB2_PERIPHBASE+TIM10_OFFSET))
#define TIM11						((__IO TIM_TypeDef *)(APB2_PERIPHBASE+TIM11_OFFSET))

#define TIMX_DELAY_MODE				0U
#define TIMX_ICP_MODE				1U
#define TIMX_CCP_MODE				2U
#define TIMX_PWM_MODE				0x03U

#define TIME_MS						1000
#define TIMER_16BIT					0x00U
#define TIMER_32BIT					0x01U
#define TIMER_16BIT_MAX				65535
#define TIMER_32BIT_MAX				4294967295

#define TIMER_COUNTER_UP			0x0U
#define TIMER_COUNTER_D				0x1U

#define BASE_USER_DEFINED			0x00U
#define BASE_1MS_TICK				0x01U
#define BASE_1US_TICK				0x02U

#define TIMER_INT_EN				0x0U
#define TIMER_INT_DIS				0x1U

#define TIMX_CHN_1					0U
#define TIMX_CHN_2					1U
#define TIMX_CHN_3					2U
#define TIMX_CHN_4					3U

#define TIMX_CCP1_ACT_LOW			1U
#define TIMX_CCP1_ACT_HIGH			2U
#define TIMX_CCP1_TOGGLE			3U
#define TIMX_CCP1_DIS				(0U)

#define TIMX_CCP2_ACT_LOW			(1<<2)
#define TIMX_CCP2_ACT_HIGH			(2<<2)
#define TIMX_CCP2_TOGGLE			(3<<2)
#define TIMX_CCP2_DIS				(0<<2)

#define TIMX_CCP3_ACT_LOW			(1<<4)
#define TIMX_CCP3_ACT_HIGH			(2<<4)
#define TIMX_CCP3_TOGGLE			(3<<4)
#define TIMX_CCP3_DIS				(0<<4)

#define TIMX_CCP4_ACT_LOW			(1<<6)
#define TIMX_CCP4_ACT_HIGH			(2<<6)
#define TIMX_CCP4_TOGGLE			(3<<6)
#define TIMX_CCP4_DIS				(0<<6)
/*-----------TIMx_CR1------------*/
#define APRE		7U
#define APRE_EN		(1<<APRE)
#define APRE_DIS	(~APRE_EN)

#define CMS			5U
#define CMS_EDG		(0<<CMS)
#define CMS_C_UP	(1<<CMS)
#define CMS_C_D		(2<<CMS)
#define CMS_C_U_D	(3<<CMS)

#define DIR			4U
#define CNT_D		(1<<DIR)
#define CNT_UP		(~CNT_D)

#define CEN			0U
#define CNT_EN		(1<<CEN)
#define CNT_DIS		(~CNT_EN)
/*-----------TIMx_DIER------------*/
#define UIE			0U
#define UIE_EN		(1<<UIE)

#define UIE_READ    (1<<UIE)
/*------------TIMx_CCMR1-------------*/
#define OC2CE			15U

#define	OC2M			12U
#define OC2M_Frozen		(0<<OC2M)
#define OC2M_HIGH		(1<<OC2M)
#define OC2M_LOW		(2<<OC2M)
#define OC2M_TOGG		(3<<OC2M)
#define OC2M_FLOW		(4<<OC2M)
#define OC2M_FHIG		(5<<OC2M)
#define OC2M_PWM1		(6<<OC2M)
#define OC2M_PWM2		(7<<OC2M)

#define	IC2F			12U
#define IC2F_0		   (0<<IC2F)
#define IC2F_1		   (1<<IC2F)
#define IC2F_2		   (2<<IC2F)
#define IC2F_3		   (3<<IC2F)
#define IC2F_4		   (4<<IC2F)
#define IC2F_5		   (5<<IC2F)
#define IC2F_6		   (6<<IC2F)
#define IC2F_7		   (7<<IC2F)
#define IC2F_8		   (8<<IC2F)
#define IC2F_9		   (9<<IC2F)
#define IC2F_10		   (10<<IC2F)
#define IC2F_11		   (11<<IC2F)
#define IC2F_12		   (12<<IC2F)
#define IC2F_13		   (13<<IC2F)
#define IC2F_14		   (14<<IC2F)
#define IC2F_15		   (15<<IC2F)

#define IC2PSC			10U
#define IC2PSC_1		(0<<IC1PSC)
#define IC2PSC_2		(1<<IC1PSC)
#define IC2PSC_4		(2<<IC1PSC)
#define IC2PSC_8		(3<<IC1PSC)

#define OC2PE			11U
#define OC2PE_PREDIS	(~OC1PE_PREEN)
#define OC2PE_PREEN		(1<<OC1PE)

#define CC2S 			8U
#define CC2S_OUT		(0<<CC2S)
#define CC2S_IN_T1		(1<<CC2S)
#define CC2S_IN_T2		(2<<CC2S)

#define OC1CE			7U

#define	OC1M			4U
#define OC1M_Frozen		(0<<OC1M)
#define OC1M_HIGH		(1<<OC1M)
#define OC1M_LOW		(2<<OC1M)
#define OC1M_TOGG		(3<<OC1M)
#define OC1M_FLOW		(4<<OC1M)
#define OC1M_FHIG		(5<<OC1M)
#define OC1M_PWM1		(6<<OC1M)
#define OC1M_PWM2		(7<<OC1M)

#define	IC1F			4U
#define IC1F_0		   (0<<IC1F)
#define IC1F_1		   (1<<IC1F)
#define IC1F_2		   (2<<IC1F)
#define IC1F_3		   (3<<IC1F)
#define IC1F_4		   (4<<IC1F)
#define IC1F_5		   (5<<IC1F)
#define IC1F_6		   (6<<IC1F)
#define IC1F_7		   (7<<IC1F)
#define IC1F_8		   (8<<IC1F)
#define IC1F_9		   (9<<IC1F)
#define IC1F_10		   (10<<IC1F)
#define IC1F_11		   (11<<IC1F)
#define IC1F_12		   (12<<IC1F)
#define IC1F_13		   (13<<IC1F)
#define IC1F_14		   (14<<IC1F)
#define IC1F_15		   (15<<IC1F)

#define IC1PSC			2U
#define IC1PSC_1		(0<<IC1PSC)
#define IC1PSC_2		(1<<IC1PSC)
#define IC1PSC_4		(2<<IC1PSC)
#define IC1PSC_8		(3<<IC1PSC)

#define OC1PE			3U
#define OC1PE_PREDIS	(~OC1PE_PREEN)
#define OC1PE_PREEN		(1<<OC1PE)

#define CC1S 			0U
#define CC1S_OUT		(0<<CC2S)
#define CC1S_IN_T1		(1<<CC2S)
#define CC1S_IN_T2		(2<<CC2S)
/*------------TIMx_CCMR2-------------*/
#define OC4CE			15U

#define	OC4M			12U
#define OC4M_Frozen		(0<<OC4M)
#define OC4M_HIGH		(1<<OC4M)
#define OC4M_LOW		(2<<OC4M)
#define OC4M_TOGG		(3<<OC4M)
#define OC4M_FLOW		(4<<OC4M)
#define OC4M_FHIG		(5<<OC4M)
#define OC4M_PWM1		(6<<OC4M)
#define OC4M_PWM2		(7<<OC4M)

#define OC4PE			11U
#define OC4PE_PREDIS	(~OC4PE_PREEN)
#define OC4PE_PREEN		(1<<OC4PE)

#define CC4S 			8U
#define CC4S_OUT		(0<<CC4S)
#define CC4S_IN_T1		(1<<CC4S)
#define CC4S_IN_T2		(2<<CC4S)

#define OC3CE			7U

#define	OC3M			4U
#define OC3M_Frozen		(0<<OC3M)
#define OC3M_HIGH		(1<<OC3M)
#define OC3M_LOW		(2<<OC3M)
#define OC3M_TOGG		(3<<OC3M)
#define OC3M_FLOW		(4<<OC3M)
#define OC3M_FHIG		(5<<OC3M)
#define OC3M_PWM1		(6<<OC3M)
#define OC3M_PWM2		(7<<OC3M)

#define OC3PE			3U
#define OC3PE_PREDIS	(~OC3PE_PREEN)
#define OC3PE_PREEN		(1<<OC3PE)

#define CC3S 			0U
#define CC3S_OUT		(0<<CC3S)
#define CC3S_IN_T1		(1<<CC3S)
#define CC3S_IN_T2		(2<<CC3S)
/*------------TIMx_CCER-------------*/
#define CC4NP			15U
#define CC4NP_EN		(1<<CC4NP)
#define CC4NP_DIS		(~CC4NP_EN)

#define CC4P			13U
#define CC4P_FEDG		(1<<CC4P_FEDG)
#define CC4P_REDG		(~CC4P_FEDG)

#define CC4E			12U
#define CC4E_EN			(1<<CC4E)

#define CC3NP			11U
#define CC3NP_EN		(1<<CC3NP)
#define CC3NP_DIS		(~CC3NP_EN)

#define CC3P			9U
#define CC3P_FEDG		(1<<CC3P)
#define CC3P_REDG		(~CC3P_FEDG)

#define CC3E			8U
#define CC3E_EN			(1<<CC3E)

#define CC2NP			7U
#define CC2NP_EN		(1<<CC2NP)
#define CC2NP_DIS		(~CC2NP_EN)

#define CC2P			5U
#define CC2P_FEDG		(1<<CC2P)
#define CC2P_REDG		(~CC2P_FEDG)

#define CC2E			4U
#define CC2E_EN			(1<<CC2E)


#define CC1NP			3U
#define CC1NP_EN		(1<<CC1NP)
#define CC1NP_DIS		(~CC1NP_EN)

#define CC1P			1U
#define CC1P_FEDG		(1<<C1P)
#define CC1P_REDG		(~CC1P_FEDG)

#define CC1E			0U
#define CC1E_EN			(1<<CC1E)
/*------------Macro Declarations End-----------*/

/*-----------Function Macro Start----------------*/

/*-----------Function Macro End----------------*/

/*----------Defined Data types start-------------------*/
typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  __IO uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;

#if configHALTIMER_DELAY_EN == EN
typedef struct
{
	uint8_t Base_MS;
	uint32_t AutoReloadVal;
	uint32_t Prescaler;
	uint8_t Counter_Mode;/* UP/Down Counter */
#if configHALTIMER2_DELAY_INT == EN
	uint8_t Int_EN_DIS;
	void (*TimerCallback)(void);
#endif
}Timer_TimeBase_t;
#endif

#if configHALTIMX_CCP_EN
typedef struct
{
	uint8_t TIMX_CCP_CHN_EN;   /* Channels Enabled */
	uint32_t ARR;			  /* Auto Reload Val */
	uint32_t Prescaler;
	uint32_t CCR1;
	uint32_t CCR2;
	uint32_t CCR3;
	uint32_t CCR4;
#if configHALTIM_INT_EN
	uint8_t Int_EN_DIS;
	void (*TimerCCP1Callback)(void);
	void (*TimerCCP2Callback)(void);
	void (*TimerCCP3Callback)(void);
	void (*TimerCCP4Callback)(void);
#endif
}Timer_CCP_t;
#endif

typedef struct
{
	TIM_TypeDef * Instance;
	uint8_t 	  Timer_Mode;
#if configHALTIMER_DELAY_EN == EN
	Timer_TimeBase_t Timer;
#endif
#if configHALTIMX_CCP_EN == EN
	Timer_CCP_t Timer_CCP;
#endif
}Timer_Config_t;

/*----------Defined Data types End----------------*/

/*-----------Software Interfaces start--------------*/
ERR xHAL_TIMERInit(Timer_Config_t *Timer);
#if configHALTIMER_DELAY_EN == EN
void vHAL_TIMERdelayMs(TIM_TypeDef * Instance ,uint32_t Delay);
void vHAL_TIMERdelayUs(TIM_TypeDef * Instance ,uint32_t Delay);
vHAL_TIMERSETTicks(TIM_TypeDef * Instance ,uint32_t Ticks);
uint32_t uHAL_TIMERGETTicks(TIM_TypeDef * Instance);
uint32_t uHal_TIMERGetTickCountISR(TIM_TypeDef * Instance);
#endif

#if configHALTIMX_CCP_EN
#endif
/*-----------Software Interfaces End--------------*/


#endif /* HAL_HAL_TIMER_H_ */
