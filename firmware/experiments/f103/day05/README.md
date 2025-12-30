# Day 05 -- External Interrupt (EXTI) Button Using NVIC

**Target MCU:** STM32F103\
**Programming Style:** Bare-Metal (CMSIS only)\
**System Clock:** 72 MHz (HSE + PLL)

------------------------------------------------------------------------

## 🎯 Objective

-   Use **EXTI (External Interrupt)** instead of polling
-   Configure **NVIC** for interrupt handling
-   Trigger interrupt on **button press**
-   Toggle LED inside ISR
-   Build a **fully interrupt-driven UI**
-   No HAL. Pure Bare-Metal STM32

------------------------------------------------------------------------

## 🧱 Firmware Flow

    RCC_72_Init()
    → GPIO_Init()
    → EXTI Configuration
    → NVIC Enable
    → EXTI0_IRQHandler()

------------------------------------------------------------------------

## 1️⃣ System Clock Configuration -- RCC_72_Init()

-   HSE used as clock source
-   PLL enabled with ×9 multiplier
-   SYSCLK = **72 MHz**
-   APB1 = 36 MHz
-   APB2 = 72 MHz

✔ Same clock configuration as Day 04\
✔ Stable clock for interrupt-driven firmware

------------------------------------------------------------------------

## 2️⃣ GPIO Initialization -- GPIO_Init()

### Pin Configuration

  Pin    Function   Mode
  ------ ---------- ------------------
  PA0    Button     Input Pull-Up
  PC13   LED        Output Push-Pull

### Steps

-   Enable GPIOA clock
-   Enable GPIOC clock
-   Enable AFIO clock (mandatory for EXTI)
-   Configure PA0 as input with internal pull-up
-   Configure PC13 as output
-   LED default state = OFF

------------------------------------------------------------------------

## 3️⃣ AFIO & EXTI Configuration

### AFIO Mapping

Map PA0 to EXTI0:

``` c
AFIO->EXTICR[0] = 0;
```

✔ Routes GPIOA pin 0 to EXTI line 0

### EXTI Trigger Selection

Button wiring uses pull-up:

-   Idle → HIGH
-   Pressed → LOW

Falling edge trigger selected:

``` c
EXTI->FTSR |= (1 << 0);
```

### EXTI Interrupt Mask

Enable EXTI line 0 interrupt:

``` c
EXTI->IMR |= (1 << 0);
```

------------------------------------------------------------------------

## 4️⃣ NVIC Configuration

Enable EXTI interrupt in NVIC:

``` c
NVIC_EnableIRQ(EXTI0_IRQn);
```

✔ NVIC now services EXTI0 interrupts

------------------------------------------------------------------------

## 5️⃣ EXTI Interrupt Handler -- EXTI0_IRQHandler()

### ISR Operation

-   Check pending interrupt flag
-   Clear pending bit
-   Toggle LED
-   Exit ISR immediately

``` c
void EXTI0_IRQHandler(void)
{
    if (EXTI->PR & (1 << 0))
    {
        EXTI->PR = (1 << 0);      // Clear pending bit
        GPIOC->ODR ^= (1 << 13);  // Toggle LED
    }
}
```

⚠️ Clearing the pending bit is mandatory\
Otherwise ISR will retrigger continuously.

------------------------------------------------------------------------

## 🔴 ISR Design Rules

❌ No delay\
❌ No loops\
❌ No printf

✅ Short execution\
✅ Deterministic behavior\
✅ Real-time safe

------------------------------------------------------------------------

## 🧠 Key Learnings

-   EXTI working principle
-   AFIO pin-to-interrupt mapping
-   NVIC interrupt enabling
-   Falling-edge detection for buttons
-   Polling vs interrupt-driven UI

------------------------------------------------------------------------

## ⚠️ Note on Button Debounce

EXTI reacts to raw electrical edges\
Mechanical buttons bounce

No debounce implemented here

✔ Debouncing handled using timer interrupt (Day 04)\
✔ Correct modular firmware architecture

------------------------------------------------------------------------

## 🚀 Next Steps

-   Combine EXTI + timer-based debounce
-   Long-press / double-click detection
-   NVIC priority tuning
-   Sleep mode with EXTI wake-up

------------------------------------------------------------------------

## ✅ Summary

✔ Fully interrupt-driven button handling\
✔ Zero CPU polling\
✔ Clean bare-metal EXTI implementation\
✔ Production-grade firmware design

**Day 05 completed successfully.**
