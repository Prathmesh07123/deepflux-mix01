# 🔴 Phase 0 — Foundation
## Day 01 — Firmware Architecture & System Thinking (STM32 Bare‑Metal)

> **Purpose of this document**
>
> This note is written so that if you return after **some year**, you can rebuild
> your firmware understanding from **absolute scratch**, without assuming any
> prior momentum.
>
> Read this slowly. Re-read it when confused. Firmware architecture is not about
> speed — it is about correctness.

---

## 0️⃣ What Problem Firmware Solves

Firmware exists to **translate physical reality into deterministic logic**.

- Voltage becomes data
- Time becomes scheduling
- Hardware behavior becomes software structure

In a DJ controller:
- Knob position → ADC voltage → MIDI value
- Button press → GPIO edge → event
- USB packet → interrupt → protocol handling

Firmware is the **bridge** between electrons and intent.

---

## 1️⃣ What Firmware Is (Precise Definition)

Firmware is:

- Software that runs **directly on silicon**
- Without an operating system
- With **full responsibility** for:
  - startup
  - memory
  - timing
  - hardware correctness

Unlike application software:
- There is no safety net
- There is no scheduler unless you build one
- A wrong register write can freeze the system

**Firmware engineers think in systems, not functions.**

---

## 2️⃣ What Happens on STM32 Reset (Very Important)

When an STM32 resets, the following happens **before your code exists**:

1. CPU reads address `0x00000000`
2. Loads initial **stack pointer**
3. Jumps to `Reset_Handler`
4. Flash wait states configured
5. Clock tree initialized
6. RAM memory prepared:
   - `.data` copied from flash to RAM
   - `.bss` zeroed
7. `main()` is called

👉 **Key realization**
>
> `main()` is NOT the start of firmware.
> Startup code and linker script define reality.

If you do not understand startup code,
you do not fully understand firmware.

---

## 3️⃣ Firmware Architecture Layers (Mental Model)

Correct firmware is layered **by responsibility**, not files.

```
Application Logic
│
State Machines / Control Logic
│
Middleware (USB, MIDI)
│
Drivers (GPIO, ADC, TIM)
│
CMSIS / Registers
│
STM32 Silicon
```

Why layering matters:
- Bugs are localized
- Code scales to new MCUs
- Features do not break timing
- Audio extensions become possible

**Flat firmware scales badly. Layered firmware scales cleanly.**

---

## 4️⃣ Super‑Loop Architecture (The Core Pattern)

The super‑loop is the heartbeat of bare‑metal systems.

```c
int main(void)
{
    system_init();

    while (1)
    {
        scan_inputs();
        process_state();
        send_outputs();
    }
}
```

Properties:
- Deterministic execution
- Easy to reason about
- No hidden scheduling

Danger:
- Blocking delays
- Busy‑waits
- Polling everything blindly

A disciplined super‑loop is powerful.
An undisciplined one is chaos.

---

## 5️⃣ Interrupts (When Hardware Speaks)

Interrupts exist because:
> **Some events cannot wait**

Examples:
- USB packet arrival
- Timer overflow
- ADC conversion complete

Correct interrupt philosophy:
- ISR does the **minimum**
- Sets flags
- Moves data
- Never blocks
- Never loops

All heavy logic belongs in the main loop.

ISR = messenger  
Main loop = thinker

---

## 6️⃣ Hybrid Architecture (Used in MIX‑01)

DeepFlux MIX‑01 uses:

- Super‑loop → control logic & state
- Interrupts → time‑critical events

Why this works:
- Predictable timing
- Clean debugging
- Audio‑ready foundation
- Easy MIDI expansion

This architecture mirrors real commercial controllers.

---

## 7️⃣ STM32 Block Diagram (Why You Must Study It)

The block diagram tells you:
- Which peripheral sits on which bus
- What clock feeds what logic
- Where DMA can be used
- Why latency exists

Example:
- ADC on APB2
- USB on AHB
- Timers split across APB1/APB2

If you ignore the block diagram,
you will fight invisible performance problems.

---

## 8️⃣ Why Architecture Matters for DJ Controllers

DJ controllers are **real‑time instruments**.

Bad architecture causes:
- Missed MIDI messages
- USB dropouts
- Encoder jitter
- Audio glitches (future)

Good architecture gives:
- Stable timing
- Clean expansion path
- Confidence in behavior

Professional products succeed because of architecture,
not features.

---

## 9️⃣ Day‑01 Final Understanding Check

After Day‑01, you should clearly know:

- What firmware truly is
- What runs before `main()`
- Why startup code matters
- How super‑loops work
- Why interrupts must be minimal
- How architecture impacts product quality

If anything above feels unclear,
**re‑read this document before moving on.**

---

## 🔜 Day‑02 Preview

**Day‑02:**
- ARM Cortex-M basics
- Registers, stack, heap
- Startup code overview
- Vector table concept

---

© DeepFlux Technologies — DeepFlux MIX‑01
