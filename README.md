# 🎛 DeepFlux MIX-01

**DeepFlux MIX-01** is a firmware-first, bare-metal STM32-based DIY DJ controller engineered by **DeepFlux Technologies**.

This project focuses on **low-level embedded system design**, **deterministic firmware behavior**, and **scalable hardware architecture**, following practices used in professional audio and control products.

---

## 🚀 Project Vision

To design and build a **modular, professional-grade DJ controller platform** that evolves through clearly defined engineering phases:

- USB MIDI control surface
- Integrated audio interface
- DSP-capable audio processing
- Professional balanced audio outputs

All development is done with a **deep understanding of the STM32 architecture** and **register-level firmware control**.

---

## 🧠 Design Philosophy

> **Bare-metal first. Architecture before features.**

- Direct register-level programming
- Deterministic execution
- Interrupt-driven design where required
- Clear separation between:
  - hardware drivers
  - middleware
  - application logic
- Hardware designed with future revisions in mind

The goal is to understand **how the system actually works**, not just make it function.

---

## 📦 Project Phases

### 🔹 Phase 0 — Foundation
- Firmware architecture principles
- STM32 internal block diagrams
- Clock tree and reset behavior
- Super-loop vs interrupt-driven systems
- GPIO, ADC, timers theory

### 🔹 Phase 1 — USB MIDI Controller
- STM32F103C8T6 (prototype platform)
- Potentiometers, encoders, buttons, faders
- USB MIDI device implementation
- Integration with DJ software (VirtualDJ, etc.)

### 🔹 Phase 2 — Audio Engine
- Migration to STM32F405
- I2S / SAI audio interfaces
- External DAC
- Headphone output

### 🔹 Phase 3 — Professional Audio
- Balanced XLR outputs
- Audio-grade power and grounding
- DSP processing
- Standalone mixer capability

---

## 🧩 Hardware Architecture (Planned)

- **Master Controller Board**
  - STM32 MCU
  - Power regulation
  - Expansion headers
- **Modular Control Boards**
  - Potentiometer modules
  - Encoder modules
  - Fader modules
- **Future Audio Board**
  - External DAC
  - Analog output stages

This modular design supports **easy debugging, upgrades, and revisions**.

---

## 🧪 Firmware Approach

- Bare-metal C
- Custom startup and linker scripts
- Register-level peripheral control
- USB MIDI class implementation
- Minimal abstraction only where justified

Firmware is written to be **readable, traceable, and maintainable**.

---

## 📁 Repository Contents

This repository contains:
- 📘 Daily learning notes (Markdown)
- 🧠 Firmware source code
- 🖥 PCB schematics and layouts
- 🧱 Mechanical CAD and STL files
- 🛠 Development tools and test utilities

Each folder documents both **implementation** and **engineering reasoning**.

---

## 📚 Learning-Driven Development

Every stage of development is documented:
- Daily study notes
- Design decisions
- Trade-offs
- Bugs, fixes, and lessons learned

This repository serves as:
- A personal engineering knowledge base
- A long-term reference
- A portfolio-grade embedded systems project

---

## 🧑‍💻 Author

**Company:** DeepFlux Technologies  
**Project:** DeepFlux MIX-01  

---

## 📜 License

This project is currently intended for **educational and engineering development purposes**.  
Licensing will be finalized in future revisions.

---

## ⭐ Final Note

This project is about **understanding systems deeply** and **building them correctly**.

Every line of code and every schematic exists for a reason.
