# 🔵 Day 09 – ADC Single-Channel Implementation (STM32 Bare-Metal)

**Target MCU:** STM32F103  
**Programming Style:** Bare-Metal (CMSIS only)  
**System Clock:** 72 MHz (HSE + PLL)

---

## 🎯 Objective

- Understand STM32 ADC register-level configuration  
- Configure ADC clock prescaler  
- Initialize GPIO pin for analog input  
- Perform ADC calibration  
- Implement single-channel ADC conversion  
- Read stable potentiometer values via UART  
- Observe real-world ADC noise behavior  

🧠 **Outcome:** One potentiometer reliably read using bare-metal ADC

---

## 🧱 Firmware Flow

```
RCC_72_Init()
→ USART2_Init()
→ ADC_Init()
→ main loop (poll EOC → read DR → print)
```

---

## 1️⃣ STM32F103 ADC Overview

### ADC Capabilities

- Resolution: **12-bit**
- Output range: **0–4095**
- Reference voltage: **VDDA (~3.3V)**
- Up to **16 external channels**
- ADC clock derived from **PCLK2**

✔ Suitable for pots, faders, sensors  
✔ Ideal for MIDI controller inputs

---

## 2️⃣ ADC Clock Configuration

### Why ADC Prescaler Matters

- ADC clock must **not exceed 14 MHz**
- Higher clock → inaccurate conversions

### Configuration Used

- PCLK2 = 72 MHz  
- ADC prescaler = **/6**  
- ADC clock = **12 MHz**  

```c
RCC->CFGR |= (0b10 << 14);   // ADCPRE = /6
```

✔ Within datasheet limits  
✔ Stable conversions

---

## 3️⃣ GPIO Analog Pin Initialization

### Selected Channel

- ADC Channel 5  
- PA5 → Analog Input  

### GPIO Configuration

- MODE = 00  
- CNF  = 00  
- Analog mode (no digital buffer)

```c
GPIOA->CRL &= ~(0xF << 20);
```

✔ Prevents leakage  
✔ Reduces noise  
✔ Mandatory for ADC

---

## 4️⃣ ADC Register Initialization

### ADC Control Registers

- **ADC_CR1** → Not used for basic single-channel  
- **ADC_CR2** → Enable, calibration, trigger, mode  
- **ADC_SMPR2** → Sampling time  
- **ADC_SQR1** → Conversion length  
- **ADC_SQR3** → Channel selection  

```c
ADC1->CR1 = 0;
ADC1->CR2 = 0;
```

✔ Clean reset state  
✔ Predictable behavior

---

## 5️⃣ Sampling Time Configuration

### Why Sampling Time Is Critical

ADC uses an internal **sample-and-hold capacitor**.

If sampling time is too short:
- Capacitor doesn’t fully charge  
- ADC values fluctuate  
- Pot readings become unstable  

### Selected Sampling Time

- **55.5 ADC cycles**

```c
ADC1->SMPR2 |= (0b101 << 15);
```

✔ Stable pot readings  
✔ No CPU cost  
✔ Professional-grade behavior

---

## 6️⃣ Conversion Sequence Setup

### Single Conversion Only

- Sequence length = 1  
- Channel = ADC Channel 5  

```c
ADC1->SQR1 &= ~(0xF << 20);  // Length = 1
ADC1->SQR3 |= (5 << 0);     // Channel 5
```

✔ Simple  
✔ Predictable  
✔ Perfect for prototype

---

## 7️⃣ ADC Power-Up & Calibration

### ADC Enable

```c
ADC1->CR2 |= ADC_CR2_ADON;
```

Short delay required after enabling ADC.

### Calibration (Mandatory)

```c
ADC1->CR2 |= ADC_CR2_RSTCAL;
while(ADC1->CR2 & ADC_CR2_RSTCAL);

ADC1->CR2 |= ADC_CR2_CAL;
while(ADC1->CR2 & ADC_CR2_CAL);
```

✔ Removes offset error  
✔ Improves accuracy  
✔ Must be done once after power-up

---

## 8️⃣ Conversion Trigger & Mode

### Mode Used

- Software trigger  
- Continuous conversion  

```c
ADC1->CR2 |= ADC_CR2_EXTSEL_SW;
ADC1->CR2 |= ADC_CR2_EXTTRIG;
ADC1->CR2 |= ADC_CR2_CONT;
ADC1->CR2 |= ADC_CR2_SWSTART;
```

✔ ADC runs continuously  
✔ CPU reads when ready

---

## 9️⃣ Reading ADC Value (Main Loop)

### Polling End-of-Conversion (EOC)

```c
while(!(ADC1->SR & ADC_SR_EOC));
uint16_t adc_val = ADC1->DR;
```

### UART Debug Output

```c
printf("ADC Val : %u\r\n", adc_val);
```

✔ Simple  
✔ Deterministic  
✔ Suitable for first prototype

---

## 🔍 Observed ADC Behavior (Real Hardware)

Even when pot is untouched:

```
ADC Val : 1058
ADC Val : 1063
ADC Val : 1051
ADC Val : 1071
```

### Why This Happens

- ADC quantization noise  
- Power rail ripple  
- Pot mechanical noise  
- Human body interference  

⚠️ **This is normal**

Noise handling will be addressed using:
- Software filtering  
- Threshold dead-band  
- Timer-based sampling  

---

## 🧠 Key Learnings

- ADC clock must respect datasheet limits  
- Sampling time matters more than speed  
- Calibration is mandatory  
- Raw ADC values are never perfectly stable  
- UART is essential for firmware validation  
- Bare-metal ADC gives full control  

---

## 🚀 Next Steps

- Timer-based ADC sampling (no busy-wait)  
- Software smoothing / averaging  
- Threshold filtering for pots  
- ADC scanning using MUX (CD74HC4067)  
- Mapping ADC values to MIDI range (0–127)  

---

**No HAL. Pure Bare-Metal STM32.**  
Read hardware properly. Process data smartly.
