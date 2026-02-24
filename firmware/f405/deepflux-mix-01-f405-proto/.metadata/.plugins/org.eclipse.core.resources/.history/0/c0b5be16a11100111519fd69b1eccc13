//------------------------- Ganpati Bappa Morya ---------------------


#ifndef DRIVER_ENCODER_H_
#define DRIVER_ENCODER_H_

#include <stdint.h>
#include <stm32f4xx.h>

//-------------------- CONFIG -----------------------

#define ENCODER_STEP_COUNTS 2
#define ENCODER_QUEUE_SIZE 8

//===================================================

//--------------------- Encoder event -----------------------
typedef struct{

	int8_t delta;
}encoder_event_t;

//===========================================================

//----------------------- Public API ------------------------

void Encoder_Init(void);
void Encoder_Scan_1ms(void);
uint8_t Encoder_GetEvent(encoder_event_t *event);

//===========================================================

#endif /* DRIVER_ENCODER_H_ */
