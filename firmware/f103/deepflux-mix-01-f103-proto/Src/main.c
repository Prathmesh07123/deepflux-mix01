//--------------------- Ganpati Bappa Morya ------------------


#include <stdint.h>
#include <stdio.h>
#include <stm32f1xx.h>
#include "rcc.h"
#include "gpio.h"
#include "timer.h"
#include "button.h"
#include "Printf_debug.h"

#define DEBUG

int main(void)
{
	RCC_72_Init();
	GPIO_Init();
	USART2_INIT();
	Button_Init();


	TIM3_Button_Init();
#ifdef DEBUG
	printf("Debugging Start...\n");
	fflush(stdout);
#endif

	button_event_t evt;

	while(1){

		if(Button_GetEvent(&evt)){
			if(evt.button == BTN_CUE && evt.type == BUTTON_EVENT_PRESSED){
				printf("CUE pressed\n");
				fflush(stdout);
			}
			if(evt.button == BTN_PLAY && evt.type == BUTTON_EVENT_PRESSED){
				printf("Play pressed\n");
				fflush(stdout);
			}
		}

	}

}

//================== ISR ==================

void TIM3_IRQHandler(void){

    if (TIM3->SR & TIM3_SR_UIF){

        TIM3->SR &= ~TIM3_SR_UIF;
        Button_Scan_1ms();
    }
}
