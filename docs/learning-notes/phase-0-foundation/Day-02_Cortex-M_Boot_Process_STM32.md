# 🔴 Phase 0 — Foundation
## Day 02 — ARM Cortex-M Core & MCU Boot Process (STM32)

> **Purpose**
>
> This document builds a mental model of how the ARM Cortex-M core actually works.
> After this day, the MCU boot process should feel logical, not magical.

---

## 0️⃣ Why Learn Cortex-M Core First

Every STM32 peripheral, driver, and firmware decision ultimately runs on the ARM Cortex-M core.

If you do not understand:
- how instructions execute
- how exceptions work
- how memory is used

you will debug symptoms, not causes.

---

## 1️⃣ ARM Cortex-M at a Glance

STM32F103 uses ARM Cortex-M3  
STM32F405 uses ARM Cortex-M4F  

Common features:
- 32-bit RISC architecture
- Harvard architecture
- Memory-mapped peripherals
- Exception-driven design

---

## 2️⃣ Cortex-M Register Set

| Register | Purpose |
|--------|--------|
| R0–R12 | General purpose |
| R13 (SP) | Stack Pointer |
| R14 (LR) | Link Register |
| R15 (PC) | Program Counter |
| xPSR | Program status |

Understanding registers explains crashes.

---

## 3️⃣ Stack (Critical Memory)

- Grows downward
- Stores return addresses, locals, registers
- Used heavily during interrupts

Two stack pointers:
- MSP (default at reset)
- PSP (RTOS use)

---

## 4️⃣ Heap

- Used by malloc/free
- Allocated from RAM
- Often avoided in firmware

Static allocation gives predictability.

---

## 5️⃣ Startup Code

Responsibilities:
1. Set stack pointer
2. Copy .data to RAM
3. Clear .bss
4. Jump to main()

Startup defines MCU behavior.

---

## 6️⃣ Vector Table

- Located at 0x00000000
- Holds stack pointer + handler addresses
- Acts as interrupt routing table

Wrong vector = undefined execution.

---

## 7️⃣ Exceptions vs Interrupts

Exceptions:
- Reset
- HardFault
- SysTick

Interrupts:
- Timers
- GPIO
- ADC
- USB

Handled via same mechanism.

---

## 8️⃣ MCU Boot Flow

1. Reset
2. Read vector table
3. Load SP
4. Jump to Reset_Handler
5. Startup code
6. main()
7. Interrupt handling

---

## 9️⃣ DJ Controller Relevance

- USB timing depends on interrupts
- Stack integrity is critical
- Audio expansion needs precision

---

## 🔍 Day-02 Outcome

You now understand:
- Core registers
- Stack/heap
- Startup code
- Vector tables
- MCU boot lifecycle

---

## 🔜 Day 03 Preview

Memory map and linker scripts.

---

© DeepFlux Technologies — DeepFlux MIX-01
