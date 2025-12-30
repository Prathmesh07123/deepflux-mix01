//------------------------- Ganpati Bappa Morya -----------------------

#include <stdint.h>
#include <stm32f1xx.h>
#include "rcc.h"

//------------------------- GPIO INITILIZATION MACRO ---------------------
#define RCC_APB2ENR_IOPAEN	(1 << 2)	//Enable CLK for GPIOA
#define RCC_APB2ENR_IOPCEN	(1 << 4)	//Enable CLK for GPIOC
#define RCC_APB2ENR_AFIOEN	(1 << 0)	//Enable AFIO CLK for EXTI
#define GPIOA_CRL_PA0 		(0x8 << 0)	//PA0 = Input Internal Pull UP
#define GPIOA_ODR_PA0		(1 << 0)	//Enable Internal Pull-UP
#define GPIOC_CRH_PC13		(0x3 << 20)	//PC13 = General Purpose Output

void GPIO_Init(void);
void EXTI0_IRQHandler(void);

void GPIO_Init(void){

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	GPIOA->CRL &= ~(0xF << 0);
	GPIOA->CRL |= GPIOA_CRL_PA0;
	GPIOA->ODR |= GPIOA_ODR_PA0;

	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= GPIOC_CRH_PC13;

	AFIO->EVCR = 0;
	AFIO->EXTICR[0] = 0;

	EXTI->FTSR |= (1 << 0);
	EXTI->IMR |= (1 << 0);

	NVIC_EnableIRQ(EXTI0_IRQn);

}

void EXTI0_IRQHandler(void){
	if(EXTI->PR & (1 << 0)){
		EXTI->PR = (1 << 0);
		GPIOC->ODR ^= (1 << 13);
	}
}


int main(void)
{

	RCC_72_Init();
	GPIO_Init();

	while(1){

	}

}
