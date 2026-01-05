# 🟡 Day 22 — MIDI Fundamentals for DJ Controllers (STM32 + Mixxx)

## 🎯 Goal
Understand **MIDI** as a control communication protocol used by DJ controllers and learn how hardware events (buttons, potentiometers, encoders) are translated into MIDI messages understood by **Mixxx**.

**Outcome:** A clear understanding of what MIDI data to send and receive for real DJ controller firmware.

---

## 🧠 Big Picture

> **MIDI is not audio.**

MIDI is a lightweight control language that sends *intent*, not sound, between:

- **Your controller** (STM32 firmware)
- **DJ software** (Mixxx)

### Event Flow
```
Human action
 → Button / Pot / Encoder
 → Firmware event
 → MIDI message
 → Mixxx action
```

### Why MIDI Design Matters
Bad MIDI design causes:
- Laggy buttons
- LEDs out of sync
- Unprofessional controller feel

Correct MIDI design results in:
- Tight response
- Accurate feedback
- Professional-grade hardware behavior

---

## 1️⃣ What MIDI Really Is

**MIDI (Musical Instrument Digital Interface)** is:

- Event-based
- Extremely low bandwidth
- Deterministic and reliable

### DJ Controller Mapping
| Hardware | MIDI Message |
|--------|--------------|
| Buttons | Notes |
| Pots | Control Change (CC) |
| Encoders | Relative CC |
| LEDs | MIDI feedback from software |

---

## 2️⃣ MIDI Message Structure (Core Concept)

Most MIDI messages are **3 bytes**:

```
[ STATUS ] [ DATA 1 ] [ DATA 2 ]
```

Each byte has a defined role.

---

## 3️⃣ Status Byte (Type + Channel)

**Format:**
```
1xxx cccc
```

### Common Status Types
| Function | Hex |
|--------|-----|
| Note ON | 0x90 |
| Note OFF | 0x80 |
| Control Change (CC) | 0xB0 |

### Channel Encoding
| Channel | Offset |
|--------|--------|
| Channel 1 | +0 |
| Channel 2 | +1 |

**Example:**
```
0x90 → Note ON, Channel 1
0x91 → Note ON, Channel 2
```

---

## 4️⃣ Data Byte 1 — Control Identifier

Identifies *which* control was used.

| Control Type | Meaning |
|-------------|---------|
| Note | Note number |
| CC | Controller number |

These numbers are **user-defined** and mapped inside Mixxx.

**Examples:**
- Play button → Note `60`
- Low EQ pot → CC `16`

---

## 5️⃣ Data Byte 2 — Value

| Control | Value |
|-------|-------|
| Button Press | 127 |
| Button Release | 0 |
| Pot Position | 0–127 |
| Encoder Move | Direction value |

---

## 6️⃣ Buttons → MIDI Notes

Buttons use **Note messages**.

### Button Press
```
0x90 0x3C 0x7F
```

### Button Release
```
0x90 0x3C 0x00
```

> Mixxx accepts both Note OFF styles.

---

## 7️⃣ Pots → Control Change (CC)

Pots send **absolute position values**.

### Example
```
0xB0 0x10 0x40
```

**Meaning:**
- CC message
- Controller number `16`
- Value `64` (middle position)

### ADC Scaling Rule
```
0–4095  →  0–127
```

❗ Never send raw ADC values.

---

## 8️⃣ Encoders → Relative Control Change

Encoders send **movement**, not position.

### Typical Relative Scheme
| Direction | Value |
|---------|-------|
| Clockwise | 65 |
| Counter-Clockwise | 63 |

### Example Messages
```
0xB0 0x20 0x41  // Clockwise
0xB0 0x20 0x3F  // Counter-Clockwise
```

Mixxx supports **relative encoder mode**.

---

## 9️⃣ LEDs → MIDI Feedback

LEDs must reflect **software state**, not button state.

### Correct Feedback Flow
```
Button pressed
 → MIDI sent to Mixxx
 → Mixxx updates internal state
 → Mixxx sends MIDI back
 → Firmware updates LED
```

### LED Messages
**ON**
```
0x90 0x3C 0x7F
```

**OFF**
```
0x90 0x3C 0x00
```

---

## 🔁 MIDI Is Bidirectional

| Direction | Purpose |
|---------|---------|
| Controller → PC | User input |
| PC → Controller | LED feedback |

Firmware must **both transmit and receive MIDI**.

---

## 🔧 Architecture Decisions (Product-Level)

### ❌ Avoid
- Polling loops
- Blocking delays

### ✅ Use
- Timer-driven inputs
- Event-based MIDI sending
- USB dedicated to MIDI only

### Timers Handle
- Button debouncing
- ADC scanning
- Encoder decoding
- LED updates

➡️ CPU remains **free, deterministic, and responsive**.

---

## 🧠 Day 22 Summary

You now understand:

- MIDI as a control protocol
- 3-byte MIDI message structure
- Notes vs Control Change
- Relative encoder messaging
- MIDI-driven LED feedback
- Why Mixxx is ideal for custom DJ controllers

---

## 🔜 Next: Day 23 — USB Basics for MIDI Devices

- What USB really does
- Endpoints & descriptors
- USB Full-Speed overview
- STM32 USB FS fundamentals

