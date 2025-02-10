
#### **Project Name:**  
Electronic Calculator using AVR Microcontroller

![Alt text](https://github.com/shereifDev/AVR-Projects/blob/main/Simple%20Calculator/shots/Screenshot_1.png)

---

#### **Description:**  
This project is a simple electronic calculator implemented using an AVR microcontroller. It uses a **keypad** for input and an **LCD** for displaying the numbers and results. The calculator supports basic arithmetic operations: addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`). It can handle two-digit numbers as input and display results up to three digits.

---

#### **Features:**
- **Input:**  
  - Two-digit numbers (e.g., 12, 45, etc.).
  - Basic arithmetic operations: `+`, `-`, `*`, `/`.
- **Output:**  
  - Displays the result on the LCD.
  - Supports results up to three digits.
- **Reset:**  
  - Press `A` to clear the screen and start over.

---

#### **Hardware Requirements:**
1. **Microcontroller:**  
   - AVR (e.g., ATmega32).
2. **Input:**  
   - 4x4 Keypad.
3. **Output:**  
   - 16x2 LCD.
4. **Power Supply:**  
   - 5V DC.
5. **Other Components:**  
   - Resistors, capacitors, and connecting wires.

---

#### **How It Works:**
1. **Initialization:**  
   - The LCD and keypad are initialized.
   - A welcome message ("ELECTRONIC CALC") is displayed on the LCD.
2. **Input:**  
   - The user enters two numbers (up to two digits each) and selects an operation (`+`, `-`, `*`, `/`).
3. **Calculation:**  
   - The microcontroller performs the selected operation and calculates the result.
4. **Output:**  
   - The result is displayed on the LCD.
5. **Reset:**  
   - The user can press `A` to clear the screen and start a new calculation.

---
