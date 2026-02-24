//--------------------- Ganpati Bappa Morya --------------------

#ifndef DRIVER_TIMER_H_
#define DRIVER_TIMER_H_

#include <stdint.h>
#include <stm32f4xx.h>

//********************************** TIM2 REG DEFINE **********************************

#define RCC_APB1ENR_TIM2EN	(1 << 0)	// Enable Clock For TIM2
#define TIM2_DIER_UIE		(1 << 0)	// Update Interrupt Enable
#define TIM2_CR1_CEN 		(1 << 0)	// Enable Counter
#define TIM2_SR_UIF			(1 << 0)	// Update Interrupt Flag
//*************************************************************************************

//********************************** TIM3 REG DEFINE **********************************

#define RCC_APB1ENR_TIM3EN	(1 << 1)	// Enable Clock For TIM3
#define TIM3_SMCR_SMS_EN 	(0b011 << 0)// Slave mode selection (Encoder mode 3)
#define TIM3_CCMR1_CC1S_01 	(1 << 0)	// CC1S = 01 => TI1
#define TIM3_CCMR1_CC2S_01 	(1 << 8)	// CC2S = 01 => TI2
#define TIM3_CCMR1_8S_TI1	(3 << 4)	// 8 Sample Filter
#define TIM3_CCMR1_8S_TI2	(3 << 12)	// 8 Sample Filter
#define TIM3_CCER_ENC1		(1 << 0)	// Enable Capture 1
#define TIM3_CCER_ENC2		(1 << 4)	// Enable Capture 2
#define TIM3_CR1_ENC		(1 << 0)	//Enable Counter
//*************************************************************************************


void TIM2_Button_Init(void);
void TIM3_Encoder_Init(void);


#endif /* DRIVER_TIMER_H_ */
