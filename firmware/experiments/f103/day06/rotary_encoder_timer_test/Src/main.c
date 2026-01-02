//----------------------- Ganpati Bappa Morya ---------------------------

#include <stdint.h>
#include <stdio.h>
#include <stm32f1xx.h>
#include "rcc.h"
#include "Printf_debug.h"

volatile uint8_t button_state = 0;
volatile uint8_t button_last = 1;
volatile uint8_t debounce_cnt = 0;

#define DEBOUNCE_TIME 8   // 8 ms

volatile int16_t encoder_last = 0;

void TIM2_Encoder_Init(void){

	RCC->APB2ENR |= (1 << 2);	//GPIOA CLK Enable
	RCC->APB1ENR |= (1 << 0);	//TIM2 CLK Enable

	GPIOA->CRL &= ~(0xFF << 0);	//Clear PA0 And PA1 CRL
	GPIOA->CRL |= (0x44 << 0);	//Input Floating (CNF = 01, MODE = 00)

	//-------------- Reset Timer Reg -----------------
	TIM2->CR1 = 0;
	TIM2->CR2 = 0;
	TIM2->SMCR = 0;

	TIM2->SMCR |= (0b011 << 0);	//SMS = 011 (Encoder Mode 3) - Both Edges

	TIM2->CCMR1 &= ~0xFFFF;		//Clear CCMR1 Reg
	TIM2->CCMR1 |= (1 << 0);	//CC1S = 01 => TI1
	TIM2->CCMR1 |= (1 << 8);	//CC2S = 01 => TI2
	TIM2->CCMR1 |= (3 << 4);	//8 Sample Filter
	TIM2->CCMR1 |= (3 << 12);	//8 Sample Filter

	TIM2->CCER |= (1 << 0);		//Enable Capture 1
	TIM2->CCER |= (1 << 4);		//Enable Capture 2

	TIM2->ARR = 0xFFFF;
	TIM2->CNT = 0;

	TIM2->CR1 |= (1 << 0);


}

void TIM3_Init(void){

	RCC->APB1ENR |= (1 << 1);

	TIM3->PSC = 7200 - 1;
	TIM3->ARR = 10 - 1;
	TIM3->DIER |= (1 << 0);
	NVIC_EnableIRQ(TIM3_IRQn);
	TIM3->CNT = 0;
	TIM3->CR1 |= (1 << 0);

}

void GPIO_Init(void){

	RCC->APB2ENR |= (1 << 2);

	GPIOA->CRL &= ~(0xF << 16);
	GPIOA->CRL |= (8 << 16);
	GPIOA->ODR |= (1 << 4);
}

void small_delay(uint32_t count)
{
    while (count--)
    {
        __NOP();
    }
}

void TIM3_IRQHandler(void){

	if(TIM3->SR & (1 << 0)){
		TIM3->SR &= ~(1 << 0);

		uint8_t raw = (GPIOA->IDR & (1 << 4)) ? 1 : 0;

		if(raw == button_last){
			if(debounce_cnt < DEBOUNCE_TIME){
				debounce_cnt++;
			}
			else{
				if(button_state != raw){
					button_state = raw;
					if(button_state == 0){
						printf("Encoder Button Pressed...\n");
						fflush(stdout);
					}
				}
			}
		}
		else{
			debounce_cnt = 0;
			button_last = raw;
		}
	}
}

int main(void)
{
	RCC_72_Init();
	USART2_INIT();
	GPIO_Init();
	TIM2_Encoder_Init();
	TIM3_Init();

	printf("Debugging Start.....\n");
	fflush(stdout);

	while(1){
		int16_t pos = (int16_t)TIM2->CNT;

		int16_t delta = pos - encoder_last;

		if(delta >= 2){
			printf("Encoder +1\n");
			fflush(stdout);
			encoder_last += 2;
		}
		else{
			if(delta <= -2){
				printf("Encoder -1\n");
				fflush(stdout);
				encoder_last -= 2;
			}
		}
//		printf("ENC: %d\r\n", pos);
//		fflush(stdout);
//		small_delay(20000);
	}

}
