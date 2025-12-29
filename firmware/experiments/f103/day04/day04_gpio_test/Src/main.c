//----------------- Ganpati Bappa Morya -------------------

#include <stdint.h>
#include <stm32f1xx.h>

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

//----------------- TIMER MACRO --------------------
#define RCC_APB1ENR_TIM2EN 	(1 << 0)	//TIM2 CLK Enable
#define TIM2_PSC_7200		7200		//Prescaler for 0.1ms tick
#define TIM2_DIER_UIE		(1 << 0)	//Update Interrup Enable
#define TIM2_CR1_CEN		(1 << 0)	//Counter Enable
#define TIM2_SR_UIF			(1 << 0)

//----------------- GPIO INITILIZATION MACRO ---------------------
#define RCC_APB2ENR_IOPAEN	(1 << 2)	//Enable CLK for GPIOA
#define RCC_APB2ENR_IOPCEN	(1 << 4)	//Enable CLK for GPIOC
#define GPIOA_CRL_PA0 		(0x8 << 0)	//PA0 = Input Internal Pull UP
#define GPIOA_ODR_PA0		(1 << 0)	//Enable Internal Pull-UP
#define GPIOC_CRH_PC13		(0x3 << 20)	//PC13 = General Purpose Output

volatile uint8_t button_state = 0;
volatile uint8_t button_last = 1;
volatile uint8_t debounce_cnt = 0;

#define DEBOUNCE_TIME 20   // 20 ms


void CLK_Init(void);
void GPIO_Init(void);
void TIM2_Init(void);
void TIM2_IRQHandler(void);

void CLK_Init(void){

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
	while((RCC->CFGR & (0b11 << 2)) != RCC_CEGR_SWS_PLL);

}

void GPIO_Init(void){
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN);

	GPIOA->CRL &= ~(0xF << 0);
	GPIOA->CRL |= GPIOA_CRL_PA0;
	GPIOA->ODR |= GPIOA_ODR_PA0;

	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= GPIOC_CRH_PC13;

}

void TIM2_Init(void){

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = TIM2_PSC_7200 - 1;
	TIM2->ARR = 10 - 1;
	TIM2->DIER |= TIM2_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM2->CNT = 0;
	TIM2->CR1 |= TIM2_CR1_CEN;

}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM2_SR_UIF)
    {
        TIM2->SR &= ~TIM2_SR_UIF;

        uint8_t raw = (GPIOA->IDR & (1 << 0)) ? 1 : 0;

        if (raw == button_last)
        {
            if (debounce_cnt < DEBOUNCE_TIME)
            {
                debounce_cnt++;
            }
            else
            {
                if (button_state != raw)
                {
                    button_state = raw;

                    if (button_state == 0)   // active LOW
                    {
                        GPIOC->ODR ^= (1 << 13);
                    }
                }
            }
        }
        else
        {
            debounce_cnt = 0;
            button_last = raw;
        }
    }
}





int main(void)
{
	CLK_Init();
	GPIO_Init();
	TIM2_Init();

	while(1){

	}
}
