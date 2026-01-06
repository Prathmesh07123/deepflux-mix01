//----------------------- Ganpati Bappa Morya -----------------------

#ifndef CORE_RCC_H_
#define CORE_RCC_H_

#include <stdint.h>
#include <stm32f1xx.h>

/* ===============================
 * Public Clock APIs
 * =============================== */

/**
 * @brief  Configure system clock to 72 MHz
 *         HSE → PLL → SYSCLK
 */

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
#define RCC_CFGR_SWS_PLL	(0b10 << 2)	//FLAG of SYSCLK == PLL



void RCC_72_Init(void);

#endif /* CORE_RCC_H_ */
