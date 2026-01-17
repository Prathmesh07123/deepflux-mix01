//------------------------- Ganpati Bappa Morya ---------------------------


/* Includes ------------------------------------------------------------------*/
#include "usbd_midi_if.h"
#include "usbd_midi.h"
#include "Printf_debug.h"
#include "led.h"

volatile uint8_t led_play_state = 0;
volatile uint8_t led_cue_state  = 0;

/* Private function prototypes -----------------------------------------------*/
static uint16_t MIDI_Receive(uint8_t *msg, uint16_t length);
static uint16_t MIDI_Transmit(uint8_t *msg, uint16_t length);

/* USB MIDI interface callbacks structure */
USBD_MIDI_ItfTypeDef USBD_MIDI_fops =
{
    MIDI_Receive,
    MIDI_Transmit
};

/* -------------------------------------------------------------------------- */
/* RX callback: Host → Device				                                  */
/* -------------------------------------------------------------------------- */
static uint16_t MIDI_Receive(uint8_t *msg, uint16_t length)
{
    /* Each USB MIDI packet = 4 bytes */
       uint8_t cin = msg[0] & 0x0F;
       uint8_t status = msg[1] & 0xF0;
       uint8_t data1 = msg[2];
       uint8_t data2 = msg[3];

//#ifdef DEBUG
//       printf("MIDI RX: CIN_CABLE: %02X, STATUS: %02X, DATA1: %02X, DATA2: %02X\r\n",
//    		   cin_cable, status, data1, data2);
//       fflush(stdout);
//#endif

    if((cin == 0x09) && (status == 0x90)){

    	if(data1 == 0x0B){
    		led_play_state = (data2 > 0) ? 1 : 0;
    	}
    	else if(data1 == 0x0C){
    		led_cue_state = (data2 > 0) ? 1 : 0;
    	}
    }


    return length;
}

/* -------------------------------------------------------------------------- */
/* TX callback: Device → Host                                                  */
/* -------------------------------------------------------------------------- */
static uint16_t MIDI_Transmit(uint8_t *msg, uint16_t length)
{
    return USBD_MIDI_Send(msg, length);
}

/* -------------------------------------------------------------------------- */
/* Public API                                                                  */
/* -------------------------------------------------------------------------- */
uint8_t USB_MIDI_Send(uint8_t *data, uint16_t len)
{
    return USBD_MIDI_Send(data, len);
}

/* -------------------------------------------------------------------------- */
/* Helper MIDI functions                                                       */
/* -------------------------------------------------------------------------- */

/* Send Note ON */
void USB_MIDI_NoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
    uint8_t packet[4];

    packet[0] = 0x09;                          // CIN = Note On
    packet[1] = 0x90 | (channel & 0x0F);       // Status
    packet[2] = note & 0x7F;
    packet[3] = velocity & 0x7F;

    USB_MIDI_Send(packet, 4);
}

/* Send Note OFF */
void USB_MIDI_NoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
    uint8_t packet[4];

    packet[0] = 0x08;                          // CIN = Note Off
    packet[1] = 0x80 | (channel & 0x0F);
    packet[2] = note & 0x7F;
    packet[3] = velocity & 0x7F;

    USB_MIDI_Send(packet, 4);
}

/* Send Control Change (ADC → MIDI) */
void USB_MIDI_CC(uint8_t channel, uint8_t cc, uint8_t value)
{
    uint8_t packet[4];

    packet[0] = 0x0B;                          // CIN = CC
    packet[1] = 0xB0 | (channel & 0x0F);
    packet[2] = cc & 0x7F;
    packet[3] = value & 0x7F;

    USB_MIDI_Send(packet, 4);
}


