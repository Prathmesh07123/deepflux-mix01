# 🔴 Day 05 — Interrupts, EXTI & NVIC (STM32 Bare-Metal)

## 🎯 Goal of Day 5
Understand how **interrupt-driven firmware** works and how to build a  
**responsive UI** using **NVIC** and **EXTI** instead of polling.

🧠 **Outcome:** Fast, non-blocking button response

---

## 1️⃣ Why Interrupts?

### ❌ Polling Buttons
- Wastes CPU cycles  
- Misses fast events  
- Breaks real-time behavior  
- Scales poorly as firmware grows  

### ✅ Interrupts
- React instantly to hardware events  
- CPU executes ISR only when needed  
- Enables real-time, professional firmware design  

---

## 2️⃣ What Happens During an Interrupt

1. Hardware event occurs (button press)  
2. EXTI detects edge  
3. NVIC checks enable & priority  
4. CPU jumps to ISR  
5. ISR executes  
6. CPU resumes main loop exactly where it stopped  

---

## 3️⃣ NVIC (Nested Vectored Interrupt Controller)

NVIC is responsible for:
- Enabling / disabling interrupts  
- Priority management  
- Nested interrupt handling  

### Enable an interrupt
```c
NVIC_EnableIRQ(EXTI0_IRQn);
```

### Set priority  
*(0 = highest priority)*
```c
NVIC_SetPriority(EXTI0_IRQn, 5);
```

---

## 4️⃣ Interrupt Priority Rules

- Lower number → higher priority  
- Higher-priority ISR can preempt lower-priority ISR  
- Equal priority → no nesting  
- **Keep ISRs short**  

### DJ Controller Example Priority
1. Rotary Encoder  
2. Buttons  
3. LEDs / UI effects  

---

## 5️⃣ EXTI (External Interrupt)

EXTI connects GPIO pins to interrupt lines.

| GPIO Pin | EXTI Line |
|---------|-----------|
| PA0     | EXTI0     |
| PA1     | EXTI1     |
| PB5     | EXTI5     |

---

## 6️⃣ Edge Trigger Selection

For buttons using **pull-up resistors**:

- Idle state → HIGH  
- Pressed → LOW  

Use **falling edge trigger**:
```c
EXTI->FTSR |= (1 << 0);
```

---

## 7️⃣ AFIO Mapping (GPIO → EXTI)

Each EXTI line must be mapped to a GPIO port.

Example: **PA0 → EXTI0**
```c
AFIO->EXTICR[0] = 0;
```

---

## 8️⃣ EXTI Interrupt Mask

Enable interrupt generation for the EXTI line:
```c
EXTI->IMR |= (1 << 0);
```

---

## 9️⃣ EXTI Interrupt Handler

```c
void EXTI0_IRQHandler(void)
{
    if (EXTI->PR & (1 << 0))
    {
        EXTI->PR |= (1 << 0);   // Clear pending bit
        // Handle button event
    }
}
```

⚠️ **Clearing the pending bit is mandatory**, or the ISR will retrigger forever.

---

## 🔴 ISR Rules (Very Important)

### ❌ Never do inside ISR
- delay()  
- printf()  
- Busy loops  
- Heavy computation  

### ✅ Correct ISR Behavior
- Set flags  
- Capture state  
- Exit immediately  

---

## 🔁 Correct Design Pattern

### ISR
```c
button_event = 1;
```

### Main Loop
```c
if (button_event)
{
    button_event = 0;
    // Process button logic
}
```

This keeps ISRs fast and firmware deterministic.

---

## 1️⃣0️⃣ Why No Debounce in EXTI?

- EXTI reacts to **raw electrical edges**  
- Mechanical buttons **bounce**  
- EXTI alone cannot debounce reliably  

### Correct Approach
- Use EXTI only to **detect event**
- Perform debounce using **timer-based logic**

📝 Debouncing is handled using **timers (Day 4 logic)**.

---

## 🧠 Day 5 Summary

You learned:
- How interrupts work internally  
- NVIC enable & priority rules  
- EXTI configuration for buttons  
- ISR discipline and best practices  
- How to design a responsive UI  

---

## 🔜 Next: Day 6
**Timers + Rotary Encoder (Jog Wheel)**

