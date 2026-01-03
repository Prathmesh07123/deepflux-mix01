# Day 6 — Timers & Encoder (Jog Wheel Ready)

## 🎯 Goal of Day 6
Understand how STM32 timers work and use them to interface a **rotary encoder (jog wheel)** using **hardware encoder mode**.

🧠 **Outcome:** Jog wheel ready (direction + speed detected reliably)

---

## 1️⃣ Timers Overview (STM32 Perspective)

### What is a Timer?
A timer is a **hardware counter** inside the MCU that:
- Counts clock pulses  
- Measures time  
- Generates events (interrupts)  
- Captures external signals  

Think of it as a **very fast stopwatch** built into hardware.

---

### STM32F103 Timer Types (Important)
| Timer | Type | Notes |
|------|------|------|
| TIM1 | Advanced | PWM, motor control |
| TIM2 | General (32-bit) | Encoder-friendly |
| TIM3 | General (16-bit) | Encoder-friendly |
| TIM4 | General (16-bit) | UI / buttons |

👉 For encoders, **general-purpose timers** are perfect.

---

### Key Timer Blocks
- **Counter (CNT)** → stores current count  
- **Prescaler (PSC)** → slows clock  
- **Auto Reload (ARR)** → max count  
- **Channels (CH1–CH4)** → external inputs / outputs  

---

## 2️⃣ Encoder Basics (Quadrature Encoder)

### What is a Rotary Encoder?
A rotary encoder outputs **two digital signals**:
- Channel A  
- Channel B  

They are **90° out of phase** → called *quadrature*.

---

### Direction Detection Logic
| A leads | B leads | Meaning |
|------|------|------|
| A | B | Clockwise |
| B | A | Counter-clockwise |

Instead of decoding in software, STM32 timers can do this **in hardware** 😎

---

### Why NOT Software Decode?
❌ CPU heavy  
❌ Missed pulses at fast rotation  
❌ Complex debounce  

✅ **Hardware encoder mode** solves all of this.

---

## 3️⃣ Timer Encoder Mode

### What is Encoder Mode?
Timer uses:
- CH1 → Encoder A  
- CH2 → Encoder B  

Timer **automatically**:
- Counts up or down  
- Detects direction  
- Handles bouncing better than GPIO interrupts  

---

### Encoder Modes
| Mode | Description |
|----|----|
| Mode 1 | Count on CH1 edges |
| Mode 2 | Count on CH2 edges |
| Mode 3 | Count on both edges (best resolution) |

👉 **Use Mode 3** for jog wheel.

---

## 4️⃣ Practical Timer Selection

### Prototype Choice
- **TIM2** → Encoder (Jog wheel)  
- **TIM3** → Button debounce timer  
- **TIM4** → UI / LED timing  

TIM2 is **32-bit**, perfect for smooth scrolling.

---

## 5️⃣ Encoder Count Strategy

### How CNT Register Is Used
- Read `TIMx->CNT`
- Compare with previous value
- Difference = movement

Example:
- +1, +2 → jog forward  
- -1, -2 → jog backward  

---

### Speed Sensitivity
| Rotation Speed | CNT Change |
|---------------|-----------|
| Slow | ±1 |
| Medium | ±4 |
| Fast | ±10+ |

This enables:
- Track scroll  
- Fine seek  
- Scratch (later)

---

## 6️⃣ Why Timer Encoder Mode is Perfect

✅ No CPU decoding  
✅ Very low latency  
✅ Direction + speed  
✅ Professional-grade method  

Most DJ controllers use this concept.

---

## 7️⃣ Important Mental Model

> Encoder is **NOT** an interrupt  
> Encoder is a **counter**

You simply **poll the counter** every 1–2 ms.

---

## 8️⃣ What We Are NOT Doing Yet
- No MIDI  
- No DJ software mapping  
- No ADC jog  

This day builds the **hardware foundation**.

---

## 🚀 Day 7 Preview
- Bare-metal encoder driver
- Jog → scroll logic
- MIDI jog messages

---

## 🧠 One-Line Summary
**Timer encoder mode converts a noisy mechanical encoder into a clean digital jog wheel.**
