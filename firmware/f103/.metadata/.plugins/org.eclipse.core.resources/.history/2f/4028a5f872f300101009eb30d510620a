//------------------------- Ganpati Bappa Morya ---------------------------


/* Includes ------------------------------------------------------------------*/
#include "usbd_midi_if.h"
#include "usbd_midi.h"

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
/* RX callback: Host → Device (optional for now)                               */
/* -------------------------------------------------------------------------- */
static uint16_t MIDI_Receive(uint8_t *msg, uint16_t length)
{
    /* Each USB MIDI packet = 4 bytes */
    /* Example packet:
       msg[0] = CIN | Cable
       msg[1] = Status
       msg[2] = Data1
       msg[3] = Data2
    */

    /* For now just ignore or debug */
    /* You can parse here later */

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


