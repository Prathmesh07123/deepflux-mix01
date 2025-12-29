# 🔴 Day 04 — GPIO, Debounce & LED Driving (STM32 Bare‑Metal)

> **Purpose**
>
> This day teaches how to interact with real hardware reliably.
> Buttons, LEDs, encoders — all depend on disciplined GPIO handling.
> Bad GPIO handling = ghost presses, flicker, lag, broken DJ performance.

---

## 🧠 Big Picture

GPIO is the **nervous system** of your DJ controller.

- Buttons = inputs
- LEDs = outputs
- Encoders = fast inputs
- Reliability depends on timing and filtering

**Golden rule:** Never trust raw hardware signals directly.

---

## 1️⃣ GPIO Hardware Model

Every GPIO pin internally looks like:

[ PAD ] → [ Input buffer ] → IDR  
        → [ Output driver ] ← ODR  
        ← [ Mode selector ] ← MODER

You control *behavior*, not just HIGH / LOW.

---

## 2️⃣ GPIO Registers (STM32)

### MODER — Mode Register

Controls *what* the pin is.

| Bits | Mode |
|----|----|
| 00 | Input |
| 01 | Output |
| 10 | Alternate Function |
| 11 | Analog |

Each pin uses **2 bits**.

Example (PA5 output):

```c
GPIOA->MODER &= ~(3 << (5*2));
GPIOA->MODER |=  (1 << (5*2));
```

---

### IDR — Input Data Register

- Read‑only
- Reflects actual pin voltage

```c
uint8_t button = (GPIOA->IDR >> 0) & 1;
```

---

### ODR — Output Data Register

Simple but unsafe with interrupts.

```c
GPIOA->ODR |=  (1 << 5);
GPIOA->ODR &= ~(1 << 5);
```

---

### BSRR — Bit Set/Reset Register (Preferred)

Atomic and interrupt‑safe.

```c
GPIOA->BSRR = (1 << 5);       // SET
GPIOA->BSRR = (1 << (5+16)); // RESET
```

**Professional rule:** Use BSRR for LEDs.

---

## 3️⃣ Button Debounce Theory

Mechanical buttons bounce for **5–30 ms**.

Raw signal:
1 0 1 0 1 1 0 1 1

MCU sees all of it unless filtered.

---

## 4️⃣ Bad Debounce (Do NOT use)

```c
delay_ms(20);
```

Blocks:
- USB MIDI
- Encoder scanning
- LED updates

---

## 5️⃣ Correct Debounce (Time‑Based)

Button state is valid only after being stable for X ms.

```c
typedef struct {
    uint8_t state;
    uint8_t last;
    uint16_t counter;
} Button_t;
```

---

## 6️⃣ LED Driving Without Delays

Never blink LEDs with delay loops.

Required LED states in DJ controllers:

- OFF
- ON
- BLINK
- FLASH

---

## 7️⃣ LED State Machine

```c
typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK,
    LED_FLASH
} LedMode_t;
```

Timer decides when to toggle.

---

## 🧠 Why This Matters

Blocking code:
- Breaks MIDI timing
- Makes jog wheel laggy
- Causes LED desync

Real DJ gear never blocks CPU.

---

## 🧪 Practice Tasks

✔ Configure GPIO input  
✔ Configure GPIO output  
✔ Read IDR  
✔ Drive LED using BSRR  
✔ Implement debounce without delay  
✔ Implement LED blink using timer  

---

## 🧠 Day‑4 Outcome

You now understand:
- GPIO discipline
- Button reliability
- Non‑blocking LED control
- Professional firmware timing

---

## 🔜 Next

**Day 5:** Timers & SysTick — the heartbeat of firmware

---

> If your firmware uses delay() in main logic,
> your design is already broken.
