//----------------------------------- Ganpati Bappa Morya ---------------------------------

#include <stdio.h>
#include <stdint.h>
#include <stm32f4xx.h>
#include "rcc.h"
#include "timer.h"
#include "button.h"
#include "printf_debug.h"

int main(void)
{

	clock_168_Init();
	GPIO_Init();
	USART2_INIT();
	TIM2_Button_Init();
	Button_Init();

	button_event_t btn_evt;

	while(1){

		if(Button_GetEvent(&btn_evt)){
			if(btn_evt.type == BUTTON_EVENT_PRESSED){
				switch(btn_evt.button){
					case BTN_ENCODER:
						printf("Encode Button pressed\n");
						fflush(stdout);
						break;
					case BTN_CUE:
						printf("CUE Button pressed\n");
						fflush(stdout);
						break;
					case BTN_PLAY:
						printf("PLAY Button pressed\n");
						fflush(stdout);
						break;
					case BTN_COUNT:
					  	break;
				}
			}
			if(btn_evt.type == BUTTON_EVENT_RELEASED){
				switch(btn_evt.button){
					case BTN_ENCODER:
						printf("Encode Button Released\n");
						fflush(stdout);
						break;
					case BTN_CUE:
						printf("CUE Button Released\n");
						fflush(stdout);
						break;
					case BTN_PLAY:
						printf("PLAY Button Released\n");
						fflush(stdout);
						break;
					case BTN_COUNT:
						break;
				}
			}
		}
	}


}

//================== ISR ==================

void TIM2_IRQHandler(void){
	if(TIM2->SR & TIM2_SR_UIF){
		TIM2->SR &= ~TIM2_SR_UIF;

		Button_Scan_1ms();
	}
}
