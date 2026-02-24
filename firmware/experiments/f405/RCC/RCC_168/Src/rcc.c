//---------------------------- Ganpati Bappa Morya --------------------------------

#include <stdint.h>
#include <stm32f4xx.h>
#include "rcc.h"

void clock_168_Init(void){

	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_VOS;

	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));

	FLASH->ACR = FLASH_ACR_LATENCY5 |
			FLASH_ACR_ICEN |
			FLASH_ACR_DCEN |
			FLASH_ACR_PRFTEN;

	RCC->CFGR &= ~(0xF << 4);
	RCC->CFGR &= ~(0b111 << 10);
	RCC->CFGR &= ~(0b111 << 13);

	RCC->CFGR |= RCC_CFGR_HPRE_1;
	RCC->CFGR |= RCC_CFGR_PPRE1_4;
	RCC->CFGR |= RCC_CFGR_PPRE2_2;



	RCC->PLLCFGR = RCC_PLLCFGR_PLLM8 |
			RCC_PLLCFGR_PLLN336 |
			RCC_PLLCFGR_PLLP2 |
			RCC_PLLCFGR_PLLQ4 |
			RCC_PLLCFGR_PLLSRC;

	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));

	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}


