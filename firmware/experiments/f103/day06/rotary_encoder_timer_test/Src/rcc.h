//------------------------- Ganpati Bappa Morya -------------------------
/*
 * rcc.h
 *
 *  Created on: Dec 30, 2025
 *      Author: prath
 */

#ifndef RCC_H_
#define RCC_H_

//----------------- CLK INITILIZATION MACRO -------------------
#define RCC_CR_HSEON		(1 << 16)	//HSE ON
#define RCC_CR_HSERDY		(1 << 17)	//HSE Ready
#define FLASH_ACR_LATENCY2	(2 << 0)	//Latency = 2 Wait State (For 72MHZ)
#define FLASH_ACR_PRFTBE 	(1 << 4)	//Prefetch Enable
#define FLASH_ACR_PRFTBS	(1 << 5)	//Prefetch Status
#define RCC_CFGR_PLLSRC_HSE	(1 << 16)	//PLL Source = HSE(8MHZ)
#define RCC_CFGR_PLLMUL_9	(0x7 << 18)	//PLLMUL = 9
#define RCC_CR_PLLON 		(1 << 24)	//PLLON
#define RCC_CR_PLLRDY		(1 << 25)	//PLL Ready (LOCKED)
#define RCC_CFGR_SW_PLL		(0b10 << 0)	//SYSCLK == PLL
#define RCC_CEGR_SWS_PLL	(0b10 << 2)	//FLAG of SYSCLK == PLL

void RCC_72_Init(void);


#endif /* RCC_H_ */
