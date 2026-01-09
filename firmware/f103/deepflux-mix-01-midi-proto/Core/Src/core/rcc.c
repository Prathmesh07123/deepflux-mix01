//-------------------------- Ganpati Bappa Morya ----------------------

#include <stdint.h>
#include <stm32f1xx.h>
#include "rcc.h"


void RCC_72_Init(void){

	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));

	FLASH->ACR &= ~(0x7 << 0);
	FLASH->ACR |= FLASH_ACR_LATENCY2;
	FLASH->ACR |= FLASH_ACR_PRFTBE;
	while(!(FLASH->ACR & FLASH_ACR_PRFTBS));

	RCC->CFGR &= ~(0xF << 4);
	RCC->CFGR &= ~(0b111 << 8);
	RCC->CFGR |= (0b100 << 8);
	RCC->CFGR &= ~(0b111 << 11);

	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;
	RCC->CFGR &= ~(0xF << 18);
	RCC->CFGR |= RCC_CFGR_PLLMUL_9;

	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));

	RCC->CFGR &= ~(0b11 << 0);
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & (0b11 << 2)) != RCC_CFGR_SWS_PLL);

}



