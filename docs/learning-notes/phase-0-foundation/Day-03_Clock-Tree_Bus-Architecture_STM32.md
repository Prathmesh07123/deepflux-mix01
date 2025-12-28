# 🔴 Phase 0 — Foundation
## Day 03 — Clock Tree & Bus Architecture (STM32 Bare‑Metal)

> **Purpose of this document**
>
> This note explains the **clock system of STM32 MCUs** from absolute fundamentals.
> When you return after months or years, this file should help you confidently
> configure clocks **without copying random code**.
>
> Clocks define *time*. Audio, USB, MIDI, DMA — everything depends on this.

---

## 1. What Is a Clock in a Microcontroller?

A clock is a **timing reference** that tells the MCU:
- When to fetch an instruction
- When to execute logic
- When peripherals operate

Without a clock, the MCU is **inert silicon**.

**Key idea:**  
Every instruction and peripheral action is synchronized to clock ticks.

---

## 2. Why Clock Configuration Is Critical

Clock configuration directly affects:
- CPU speed
- Peripheral timing
- USB functionality
- Audio sample accuracy
- Power consumption

A wrong clock setup may:
- Cause USB enumeration failure
- Break audio playback
- Create random timing bugs
- Misconfigure baud rates and timers

Clock bugs are **system‑level bugs**, not peripheral bugs.

---

## 3. Clock Sources in STM32

### 3.1 HSI — High Speed Internal Oscillator

- Internal RC oscillator
- Fast startup
- Low cost (no external parts)
- Poor accuracy and temperature drift

**Usage:**
- Early boot
- Basic testing
- Low‑precision tasks

**Analogy:**  
HSI is like DJing without headphones — it works, but precision suffers.

---

### 3.2 HSE — High Speed External Oscillator

- External crystal or clock source
- High accuracy and stability
- Required for USB and reliable audio

**Usage:**
- USB communication
- Audio (I2S / SAI)
- Precise timing systems

**Analogy:**  
HSE is your master BPM reference — everything locks to it.

---

## 4. PLL — Phase Locked Loop

Crystals operate at low frequencies (8–12 MHz).
The MCU needs much higher speeds.

PLL:
- Takes a stable clock input
- Multiplies it to high frequency
- Keeps output synchronized (locked)

**If PLL loses lock:**
- USB fails
- Audio glitches
- Timing becomes unstable

**Analogy:**  
PLL is a BPM scaler that must never drift from the master tempo.

---

## 5. Clock Tree Overview

Typical STM32 clock flow:

HSE / HSI  
→ PLL  
→ SYSCLK  
→ AHB  
→ APB1 / APB2  

Each stage distributes clock signals to different hardware blocks.

---

## 6. SYSCLK — System Clock

- Feeds CPU core
- Drives system logic
- Determines execution speed

Typical values:
- STM32F103: 72 MHz
- STM32F405: 168 MHz

Changing SYSCLK affects **everything**.

---

## 7. AHB vs APB — Bus Architecture

### 7.1 AHB (Advanced High‑Performance Bus)

- High‑speed backbone
- Connects CPU, RAM, DMA
- Handles heavy data traffic

**Analogy:**  
AHB is a highway for bulk data movement.

---

### 7.2 APB (Advanced Peripheral Bus)

Two peripheral buses:

- **APB1** — slower peripherals
- **APB2** — faster peripherals

APB connects:
- Timers
- UART, I2C, SPI
- ADC, GPIO

**Analogy:**  
APB buses are city roads connected to the main highway.

---

## 8. Critical Timer Clock Rule

If APB prescaler ≠ 1:

Timer clock = APB clock × 2

This rule causes many timing bugs when ignored.

Always calculate **actual timer frequency**.

---

## 9. Why Audio Needs Stable Clocks

Audio is time‑based data:
- 44.1 kHz = 44,100 samples/second
- 48 kHz = 48,000 samples/second

Clock instability causes:
- Pitch variation
- Audio crackling
- Dropouts

USB audio, I2S, and SAI require:
- Accurate clock sources
- Low jitter
- Stable PLL configuration

---

## 10. Common Clock Configuration Mistakes

- Using HSI for USB
- Blindly copying HAL clock code
- Ignoring prescaler effects
- Forgetting Flash wait states
- Not verifying PLL lock status

Clock configuration must be **intentional**, not accidental.

---

## 11. Mental Checklist Before Writing RCC Code

- Which clock source am I using?
- Is it accurate enough?
- What is SYSCLK?
- What are AHB/APB frequencies?
- Are timers affected by prescalers?
- Does this meet audio/USB requirements?

---

## 🧠 Day 03 Outcome

After this day, you should:
- Understand STM32 clock architecture
- Confidently design clock trees
- Avoid random RCC configuration
- Respect clock stability for audio systems

---

**Next:**  
Day 04 — GPIO, Inputs & Human Interface Devices
