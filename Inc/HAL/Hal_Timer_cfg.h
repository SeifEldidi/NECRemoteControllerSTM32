/*
 * Hal_Timer_cfg.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Seif pc
 */

#ifndef HAL_HAL_TIMER_CFG_H_
#define HAL_HAL_TIMER_CFG_H_

/*-------------Includes Section Start---------------*/
#include <stdint.h>
#include "../std_macros.h"
/*-------------Includes Section End----------------*/

/*------------Macro Declarations Start-----------*/
#define configHALTIMER_DELAY_EN		EN
#define configHALTIMX_ICP_EN		EN
#define configHALTIMX_CCP_EN		EN
#define configHALTIMX_PWM_EN 		EN

#define configHALTIMER1_DELAY_INT  		DIS
#define configHALTIMER1_CCP1_INT  		DIS
#define configHALTIMER1_CCP2_INT  		DIS
#define configHALTIMER1_CCP3_INT  		DIS
#define configHALTIMER1_CCP4_INT  		DIS
#define configHALTIMER1_INT_EN			configHALTIMER1_INT == EN && configHALTIMER1_EN ==EN


#define configHALTIMER2_DELAY_INT  		EN
#define configHALTIMER2_CCP1_INT  		DIS
#define configHALTIMER2_CCP2_INT  		DIS
#define configHALTIMER2_CCP3_INT  		DIS
#define configHALTIMER2_CCP4_INT  		DIS
#define configHALTIMER2_INT		    	DIS
#define configHALTIMER2_INT_EN			configHALTIMER2_INT == EN && configHALTIMER2_EN ==EN


#define configHALTIMER3_DELAY_INT  		DIS
#define configHALTIMER3_CCP1_INT  		DIS
#define configHALTIMER3_CCP2_INT  		DIS
#define configHALTIMER3_CCP3_INT  		DIS
#define configHALTIMER3_CCP4_INT  		DIS
#define configHALTIMER3_INT				DIS
#define configHALTIMER3_INT_EN			configHALTIMER3_INT == EN && configHALTIMER3_EN ==EN


#define configHALTIMER4_DELAY_INT  		DIS
#define configHALTIMER4_CCP1_INT  		DIS
#define configHALTIMER4_CCP2_INT  		DIS
#define configHALTIMER4_CCP3_INT  		DIS
#define configHALTIMER4_CCP4_INT  		DIS
#define configHALTIMER4_INT				DIS
#define configHALTIMER4_INT_EN			configHALTIMER4_INT == EN && configHALTIMER4_EN ==EN


#define configHALTIMER5_DELAY_INT  		DIS
#define configHALTIMER5_CCP1_INT  		DIS
#define configHALTIMER5_CCP2_INT  		DIS
#define configHALTIMER5_CCP3_INT  		DIS
#define configHALTIMER5_CCP4_INT  		DIS
#define configHALTIMER5_INT				DIS
#define configHALTIMER5_INT_EN			configHALTIMER5_INT == EN && configHALTIMER5_EN ==EN



#define configHALTIM_INT_EN			configHALTIMER1_INT_EN == EN || configHALTIMER2_INT_EN == EN ||\
	configHALTIMER3_INT_EN  == EN ||configHALTIMER4_INT_EN == EN || configHALTIMER5_INT_EN == EN
/*------------Macro Declarations End-----------*/

/*-----------Function Macro Start----------------*/
/*-----------Function Macro End----------------*/

/*----------Defined Data types start-------------------*/


/*----------Defined Data types End----------------*/

/*-----------Software Interfaces start--------------*/

/*-----------Software Interfaces End--------------*/

#endif /* HAL_HAL_TIMER_CFG_H_ */
