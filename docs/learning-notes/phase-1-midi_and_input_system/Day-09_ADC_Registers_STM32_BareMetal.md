# 🔵 Day 09 — ADC Registers & Single-Channel Implementation (STM32 Bare-Metal)

## 🎯 Goal of Day 9
Implement **single-channel ADC** on STM32F103 using **bare-metal register programming** and understand how each ADC register works in real firmware.

🧠 **Outcome:** A stable, correct ADC foundation ready for multi-pot scanning in DJ controller firmware.

---

## 🧠 Big Picture

Human hand  
→ Pot voltage  
→ GPIO (analog mode)  
→ ADC sample & hold  
→ ADC conversion  
→ Digital value  
→ Firmware processing  

If ADC configuration is wrong:
- Pots feel unstable
- MIDI values jitter
- Controller feels cheap

**ADC correctness = product quality**

---

## 1️⃣ STM32F103 ADC Overview

- 12-bit SAR ADC (0–4095)
- Up to 16 channels
- Shared ADC clock
- Software or hardware trigger

Prototype choices:
- ✔ Single channel
- ✔ Software trigger
- ✔ Continuous conversion

---

## 2️⃣ ADC Clock Configuration

- SYSCLK = 72 MHz
- PCLK2 = 72 MHz
- ADC prescaler = /6
- ADC clock = **12 MHz**

📌 Rule: ADC clock ≤ 14 MHz

---

## 3️⃣ GPIO Configuration

ADC pins must be **analog mode**:

- MODE = 00  
- CNF  = 00  

Disconnects digital buffers and reduces noise.

---

## 4️⃣ ADC Registers

### ADC_CR1
Unused for Day 9:
```
CR1 = 0
```

### ADC_CR2
Controls enable, trigger, calibration, and conversion start.

---

## 5️⃣ Sampling Time

- Sampling time = **55.5 cycles**
- Required for pots due to source resistance

Provides stable, low-noise readings.

---

## 6️⃣ Channel Selection (SQR)

- SQR1: sequence length = 1
- SQR3: channel 5 (PA5)

---

## 7️⃣ ADC Enable & Calibration

Required flow:
1. Enable ADC
2. Short delay
3. Reset calibration
4. Start calibration
5. Wait until complete

Skipping calibration causes silent inaccuracy.

---

## 8️⃣ Trigger & Conversion Mode

- Software trigger
- Continuous conversion

Chosen for simplicity and debugging.

---

## 9️⃣ ADC Noise Reality

ADC values fluctuate even when untouched:
- ±10–20 counts is normal

Causes:
- Electrical noise
- Power ripple
- Pot tolerance
- Human coupling

---

## 10️⃣ Architecture Decision

- ❌ No DMA for ADC
- ✅ Timer-based scanning
- DMA reserved for USB Audio

Clean, predictable, product-grade firmware.

---

## 🧠 Day 9 Summary

You now understand:
- Bare-metal ADC register flow
- Calibration importance
- Real-world ADC noise
- Correct product architecture decisions

---

## 🔜 Next: Day 10

**Timer-Triggered ADC**
