# 🔘 Software Button Debounce in Embedded C

## 📌 Overview

This project implements a **software button debounce algorithm** in Embedded C.

Mechanical push buttons do not produce a clean digital signal when pressed or released. Instead, they generate multiple rapid transitions (known as **contact bounce**) before settling into a stable state.

This project filters those unwanted transitions using a **3-sample software debounce algorithm**, ensuring that only valid button press and release events are detected.

---

## 🚀 Features

- Software debounce implementation
- Debounce period of 3 consecutive identical samples
- Detects button press and release events
- Prevents false triggering caused by switch bounce
- Modular and reusable code
- No dynamic memory allocation
- Uses fixed-width integer types (`uint8_t`)
- Compatible with Embedded C (C99)

---

## 📂 Project Structure

```
Software-Button-Debounce/
│
├── debounce.c
├── README.md
```

---

## 🛠️ Technologies Used

- C99
- GCC Compiler
- Embedded C Programming
- Standard Libraries
  - stdio.h
  - stdint.h

---

## 📖 How It Works

The debounce algorithm works by comparing each new button sample with the previous sample.

If the same value is received repeatedly, a counter is incremented.

Once **three consecutive identical samples** are detected, the new button state is considered stable.

If the input changes before reaching three consecutive samples, the counter resets and starts counting again.

This effectively filters out mechanical switch bounce.

---

## 📌 Debounce Logic

Initial State

```

Stable State = Released
Counter = 0

```

Example Input

```

Raw Samples

0
0
1
0
1
1
1
1
0
0
0

```

Stable Output

```

Stable State

0
0
0
0
0
0
1
1
1
1
0

```

Only after three consecutive identical samples does the stable state change.

---

## 📚 Functions Implemented

### `button_init()`

Initializes the debounce variables.

---

### `button_update(uint8_t raw_state)`

Processes one raw button sample.

Returns the current stable button state.

---

### `button_get_state()`

Returns the current debounced button state.

---

## ▶️ Build Instructions

Compile using GCC

```bash
gcc -Wall -std=c99 debounce.c -o debounce
```

Run

```bash
./debounce
```

---

## ✅ Sample Output

```
Raw     Stable
-----------------
0       0
0       0
1       0
0       0
1       0
1       0
1       1
Button Pressed
1       1
0       1
0       1
0       0
Button Released
```

---

## 💡 Applications

- Push button interfaces
- Keypad scanning
- Industrial control panels
- Automotive embedded systems
- Consumer electronics
- IoT devices
- Microcontroller projects

---

## 🎯 Learning Outcomes

Through this project, the following Embedded C concepts were practiced:

- Software debouncing
- Static variables
- State tracking
- Event detection
- Fixed-width integer types
- Modular programming
- Embedded software design

---

## 👨‍💻 Author

**Himanshu Pawar**

Electronics & Telecommunication Engineering

Embedded Systems Enthusiast

GitHub: https://github.com/YOUR_USERNAME

LinkedIn: https://www.linkedin.com/in/himanshu-pawar-a74b732a9/
