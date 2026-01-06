//------------- Ganpati Bappa Morya -----------------

#ifndef DRIVERS_TIMER_H_
#define DRIVERS_TIMER_H_

#include <stdint.h>
#include <stm32f1xx.h>

//---------------- TIMER 2 Encoder MACRO --------------------

#define RCC_APB1ENR_TIM2EN	(1 << 0)	// Enable Clock For TIM2
#define TIM2_SMCR_SMS_EN	(0b011 << 0)// SMS = 011 (Encoder Mode 3) - Both Edges
#define TIM2_CCMR1_CC1S_01	(1 << 0)	//CC1S = 01 => TI1
#define TIM2_CCMR1_CC2S_01	(1 << 8)	//CC2S = 01 => TI2
#define TIM2_CCMR1_8S_TI1	(3 << 4)	//8 Sample Filter
#define TIM2_CCMR1_8S_TI2	(3 << 12)	//8 Sample Filter
#define TIM2_CCER_ENC1		(1 << 0)	//Enable Capture 1
#define TIM2_CCER_ENC2		(1 << 4)	//Enable Capture 2
#define TIM2_CR1_ENC		(1 << 0)	//Enable Counter

//===========================================================

//----------------- TIMER 3 Button MACRO --------------------

#define RCC_APB1ENR_TIM3EN 	(1 << 1)	// Enable Clock For TIM3
#define TIM3_DIER_UIE		(1 << 0)	// Update Interrupt Enable
#define TIM3_CR1_CEN 		(1 << 0)	// Enable Counter
#define TIM3_SR_UIF			(1 << 0)	// Update Interrupt Flag

//===========================================================

void TIM2_Encoder_Init(void);
void TIM3_Button_Init(void);

#endif /* DRIVERS_TIMER_H_ */
