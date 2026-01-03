# 🔵 Day 08 — ADC Fundamentals & Potentiometers (STM32 Bare-Metal)

## 🎯 Goal of Day 8
Understand how **analog controls (pots, faders)** are converted into  
**stable, noise-free digital values** suitable for **MIDI controllers**.

🧠 **Outcome:** Reliable analog input foundation for DJ controller firmware

---

## 🧠 Big Picture

Every analog control follows this path:

Human hand  
→ Analog voltage  
→ ADC sampling  
→ Digital number  
→ Scaling  
→ MIDI value (0–127)

If ADC design is weak:
- Volume jumps
- Filters crackle
- FX feel cheap
- Controller feels unprofessional

**ADC quality = controller quality**

---

## 1️⃣ What ADC Really Does

ADC (Analog-to-Digital Converter):
- Samples an input voltage
- Compares it to a reference (Vref)
- Outputs a binary number

### STM32F103 ADC Specs
- Resolution: **12-bit**
- Output range: **0–4095**
- Reference voltage: **VDDA (~3.3V)**

### Example
If:
- Vref = 3.3V  
- Input = 1.65V  

ADC = (1.65 / 3.3) × 4095 ≈ 2047

---

## 2️⃣ ADC Resolution (Why 12-bit Is Ideal)

| Resolution | Steps | Practical Feel |
|----------|------|----------------|
| 8-bit | 256 | Jumpy |
| 10-bit | 1024 | Acceptable |
| **12-bit** | **4096** | Smooth |
| 16-bit | 65536 | Overkill |

### DJ Controller Reality
- MIDI range is only **0–127**
- Higher ADC resolution gives:
  - Better noise immunity
  - Smoother scaling
  - Stable filtering

✔ STM32F103 ADC is perfectly suited

---

## 3️⃣ Sampling Time (Most Important ADC Parameter)

ADC does **not** read instantly.

Internally:

Input → Sample capacitor → Hold → Convert

If sampling time is **too short**:
- Capacitor doesn’t fully charge
- ADC reads a lower value
- Causes jitter and instability

### STM32 ADC Sampling Options
- 1.5 cycles
- 7.5 cycles
- 13.5 cycles
- 28.5 cycles
- 41.5 cycles
- 55.5 cycles
- 71.5 cycles
- 239.5 cycles

### Rule for Pots
> **Always use longer sampling time**

✔ More stable  
✔ Less noise  
✔ No CPU cost  

---

## 4️⃣ Why 10k Pots Are Ideal

| Pot Value | Result |
|---------|--------|
| 1k | High current, noisy |
| 5k | Acceptable |
| **10k** | **Perfect** |
| 50k | Slow charging |
| 100k | Floating noise |

### Electrical Reason
- ADC has an internal sampling capacitor
- Pot acts as source resistance
- 10k provides:
  - Proper charge time
  - Low noise
  - Stable readings

🎯 This is why **professional MIDI gear uses 10k pots**

---

## 5️⃣ ADC Clock & Timing

ADC clock comes from:

PCLK2 / prescaler

### Safe Configuration
- PCLK2 = 72 MHz
- ADC prescaler = /6
- ADC clock = **12 MHz**

✔ Within datasheet limits  
✔ Accurate conversions  

---

## 6️⃣ Where ADC Noise Comes From

Noise is **not always ADC fault**.

Sources include:
- Pot mechanical wear
- Human hand interference
- Power rail ripple
- Ground bounce
- MUX switching transients

ADC only exposes electrical reality.

📝 Noise mitigation is handled in:
- RC filtering
- software smoothing

---

## 7️⃣ DJ Controller Signal Flow

Correct firmware pipeline:

ADC raw (0–4095)  
→ filtering  
→ smoothing  
→ clamping  
→ scaling  
→ MIDI CC (0–127)

❌ Never send raw ADC values directly

---

## 🧪 Day 8 Mini-Check

You should now understand:
- Why 10k pots are preferred
- Why sampling time matters more than speed
- Why ADC noise ≠ bad firmware


---

## 🧠 Day 8 Summary

You learned:
- ADC fundamentals
- Resolution vs feel
- Sampling time importance
- Potentiometer selection rules
- Professional DJ controller ADC mindset

---

## 🔜 Next: Day 9

**ADC Registers & Single-Channel Implementation**

- ADC_CR1 / ADC_CR2
- ADC_SQRx
- Manual trigger
- UART debugging of ADC values

---
