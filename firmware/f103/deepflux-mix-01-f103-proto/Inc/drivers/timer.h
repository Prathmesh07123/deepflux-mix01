//------------- Ganpati Bappa Morya -----------------

#ifndef DRIVERS_TIMER_H_
#define DRIVERS_TIMER_H_

#include <stdint.h>
#include <stm32f1xx.h>

//----------------- TIMER 3 Button MACRO --------------------
#define RCC_APB1ENR_TIM3EN 	(1 << 1)	// Enable Clock For TIM3
#define TIM3_DIER_UIE		(1 << 0)	// Update Interrupt Enable
#define TIM3_CR1_CEN 		(1 << 0)	// Enable Counter
#define TIM3_SR_UIF			(1 << 0)	// Update Interrupt Flag

void TIM3_Button_Init(void);

#endif /* DRIVERS_TIMER_H_ */
