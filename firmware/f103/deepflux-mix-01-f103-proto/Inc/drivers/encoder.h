//------------------------- Ganpati Bappa Morya ---------------------

#ifndef DRIVERS_ENCODER_H_
#define DRIVERS_ENCODER_H_

#include <stdint.h>

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



#endif /* DRIVERS_ENCODER_H_ */
