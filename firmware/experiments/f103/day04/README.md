# Day 04 – GPIO Button Debounce Using Timer Interrupt

**Target MCU:** STM32F103  
**Programming Style:** Bare-Metal (CMSIS only)  
**System Clock:** 72 MHz (HSE + PLL)

---

## 🎯 Objective

- Configure STM32F103 system clock using **HSE + PLL**
- Use **TIM2 interrupt** instead of SysTick
- Implement **software debounce** for push button
- Toggle LED only on **valid button press**
- Fully interrupt-driven firmware design

---

## 🧱 Firmware Flow

CLK_Init()  
→ GPIO_Init()  
→ TIM2_Init()  
→ TIM2_IRQHandler()

---

## 1️⃣ Clock Initialization – `CLK_Init()`

### Step-by-Step Process

1. Enable **HSE oscillator**
2. Wait until **HSE ready**
3. Configure **FLASH latency = 2 wait states**
4. Enable **FLASH prefetch buffer**
5. Set **AHB prescaler = /1**
6. Set **APB1 prescaler = /2**
7. Set **APB2 prescaler = /1**
8. Select **HSE as PLL source**
9. Set **PLL multiplier = ×9**
10. Enable **PLL**
11. Wait until **PLL locks**
12. Switch **SYSCLK to PLL**
13. Confirm **PLL is system clock**

✔ Final SYSCLK = **72 MHz**

---

## 2️⃣ GPIO Initialization – `GPIO_Init()`

### Pin Configuration

- **PA0** → Input with Pull-Up (Button)
- **PC13** → Output Push-Pull (LED)

### Steps

- Enable GPIOA and GPIOC clocks
- Configure PA0 as input with pull-up
- Configure PC13 as output
- LED default state = OFF

---

## 3️⃣ Timer Initialization – `TIM2_Init()`

### Timer Configuration

- Timer clock = **36 MHz**
- Prescaler = **7200 − 1**
- Timer tick = **0.1 ms**
- ARR = **10 − 1**
- Interrupt period = **1 ms**

### Steps

- Enable TIM2 clock
- Set prescaler and auto-reload
- Enable update interrupt
- Enable NVIC interrupt
- Start timer

---

## 4️⃣ TIM2 Interrupt Handler – `TIM2_IRQHandler()`

### Debounce Logic

1. Check update interrupt flag
2. Clear UIF flag
3. Read raw button state
4. Compare with previous state
5. Count stable samples
6. Accept state after **20 ms**
7. Toggle LED on valid press
8. Ignore switch bouncing

✔ Clean debounce  
✔ No blocking delays  
✔ Real-time safe  

---

## 🧠 Key Learnings

- STM32 clock tree configuration
- FLASH latency vs system clock
- Timer-based scheduling
- Interrupt-driven debounce logic
- Bare-metal register-level programming

---

## 🚀 Next Steps

- EXTI + timer debounce
- Long press / double press detection
- Low-power sleep with timer wake-up

---

**No HAL. Pure Bare Metal STM32.**
