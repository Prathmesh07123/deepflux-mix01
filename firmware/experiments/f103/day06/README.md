# Day 06 – Rotary Encoder Using TIM2 Encoder Mode

**Target MCU:** STM32F103  
**Programming Style:** Bare-Metal (CMSIS only)  
**System Clock:** 72 MHz (HSE + PLL)

---

## 🎯 Objective

- Understand **STM32 timers** at a conceptual level
- Learn **quadrature rotary encoder basics**
- Configure **TIM2 in encoder mode**
- Decode encoder rotation **in hardware**
- Implement **smooth jog wheel logic**
- Add **button debounce using timer interrupt**
- Debug encoder movement via **UART**

🧠 Outcome: **Jog wheel ready**

---

## 🧱 Firmware Flow

RCC_72_Init()  
→ USART2_Init()  
→ GPIO_Init()  
→ TIM2_Encoder_Init()  
→ TIM3_Init()  
→ main loop (position tracking)

---

## 1️⃣ Rotary Encoder Basics (Quadrature)

### Encoder Signals

A mechanical rotary encoder provides:

- **CLK** (Channel A)
- **DT** (Channel B)
- **SW** (Push button)

### Working Principle

- Channels A & B are **90° phase shifted**
- Direction is determined by **edge order**
- Each detent produces **multiple transitions**

✔ Clockwise → Count Up  
✔ Counter-Clockwise → Count Down  

---

## 2️⃣ Timer Overview (Why TIM2?)

### Why use Timer Encoder Mode?

- No GPIO polling
- No EXTI overload
- Hardware handles edge detection
- Zero CPU overhead for counting

### TIM2 Selection

- **32-bit timer** (used as 16-bit here)
- Supports **Encoder Mode**
- High resolution
- Ideal for jog wheels

---

## 3️⃣ TIM2 Encoder Initialization – `TIM2_Encoder_Init()`

### Pin Mapping

- **PA0** → Encoder Channel A  
- **PA1** → Encoder Channel B  

### Configuration Steps

1. Enable GPIOA & TIM2 clocks
2. Configure PA0 & PA1 as **floating inputs**
3. Reset TIM2 control registers
4. Set **SMS = 011** → Encoder Mode 3
5. Map:
   - CC1 → TI1
   - CC2 → TI2
6. Enable digital input filters (8 samples)
7. Enable capture channels
8. Set ARR = `0xFFFF`
9. Reset CNT
10. Enable TIM2 counter

✔ Hardware quadrature decoding  
✔ Counts on **both edges**

---

## 4️⃣ Encoder Count Handling (Main Loop)

### Important Observation

- Encoder mode counts **2 steps per detent**
- Software divides count logically

### Logic Used

- Compare current CNT with last value
- Step threshold = **±2**
- Print:
  - `Encoder +1`
  - `Encoder -1`

✔ Clean jog resolution  
✔ No bounce  
✔ No interrupts needed  

---

## 5️⃣ Encoder Button Debounce – TIM3

### Button Pin

- **PA4** → Encoder push button (Pull-Up)

### Why TIM3?

- Stable periodic sampling
- No blocking delays
- Independent of encoder logic

### TIM3 Configuration

- Timer clock = **36 MHz**
- Prescaler = **7200 − 1**
- ARR = **10 − 1**
- Interrupt period = **1 ms**

---

## 6️⃣ TIM3 Interrupt Handler – `TIM3_IRQHandler()`

### Debounce Logic

1. Read raw button state
2. Compare with last state
3. Count stable samples
4. Accept state after **8 ms**
5. Detect **press event only**
6. Print message on valid press

✔ Fast response  
✔ No false triggers  
✔ DJ-controller friendly  

---

## 7️⃣ Small Delay for Smooth Debug

### Why Small Delay?

- Prevent UART flooding
- Improve readability
- No real-time impact

### Implementation

- Simple NOP loop
- Used only in debug loop
- **Not used in ISR**

---

## 🧠 Key Learnings

- STM32 timer architecture
- Encoder hardware decoding
- Encoder mode vs EXTI
- Timer-based debounce
- UART debugging in bare-metal
- Handling double-edge counts

---

## 🚀 Next Steps

- MIDI theory (USB / UART MIDI)
- Map jog wheel to **VirtualDJ**
- LED feedback from DJ software
- Shift + encoder behavior
- Acceleration curves for jog

---

**No HAL. No Arduino. Pure Bare-Metal STM32.**  
**Hardware does the hard work. Firmware stays clean.**
