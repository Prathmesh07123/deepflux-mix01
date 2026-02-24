//--------------------- Ganpati Bappa Morya --------------------

#include <stdint.h>
#include <stm32f4xx.h>
#include "timer.h"

void TIM2_Button_Init(void){

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->PSC = 8400 - 1;
	TIM2->ARR = 10 - 1;
	TIM2->DIER |= TIM2_DIER_UIE;
	NVIC_SetPriority(TIM2_IRQn, 0);
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM2->CNT = 0;
	TIM2->CR1 |= TIM2_CR1_CEN;
}

void TIM3_Encoder_Init(void){

	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// Reset the timer
	TIM3->CR1 = 0;
	TIM3->CR2 = 0;
	TIM3->SMCR = 0;

	TIM3->SMCR |= TIM3_SMCR_SMS_EN;

	TIM3->CCMR1 &= ~0xFFFF;
	TIM3->CCMR1 |= TIM3_CCMR1_CC1S_01;
	TIM3->CCMR1 |= TIM3_CCMR1_CC2S_01;
	TIM3->CCMR1 |= TIM3_CCMR1_8S_TI1;
	TIM3->CCMR1 |= TIM3_CCMR1_8S_TI2;

	TIM3->CCER |= TIM3_CCER_ENC1;
	TIM3->CCER |= TIM3_CCER_ENC2;

	TIM3->ARR = 0xFFFF;
	TIM3->CNT = 0;

	TIM3->CR1 |= TIM3_CR1_ENC;
}
