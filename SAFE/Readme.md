# Secure Safe System with AVR Microcontroller

This project implements a secure safe system using an AVR microcontroller (e.g., ATmega32). The system uses a keypad for password entry, an LCD for user interaction, and an EEPROM to store the password securely. It also includes LEDs for visual feedback.

---

## Features
- **Password Protection**: The safe can be unlocked only with the correct 4-digit password.
- **Password Setup**: The user can set a new password during the first run.
- **Lockout Mechanism**: After 3 incorrect attempts, the system locks for 9 seconds.
- **Visual Feedback**:
  - Green LED indicates the safe is open.
  - Red LED indicates the safe is locked.

---

## Hardware Requirements
- AVR Microcontroller (e.g., ATmega32)
- 4x4 Keypad
- 16x2 LCD
- 2 LEDs (Green and Red)
- Resistors (for LEDs)
- Breadboard and Jumper Wires

---

## How to Use
1. **Set Password**:
   - On the first run, the system will prompt you to set a new password.
   - Enter a 4-digit password and confirm it.
   
![Alt text](https://github.com/shereifDev/AVR-Projects/blob/main/SAFE/shots/Screenshot_1.png)

2. **Unlock the Safe**:
   - Enter the correct 4-digit password to unlock the safe.
   - The green LED will turn on to indicate success.
     
![Alt text](https://github.com/shereifDev/AVR-Projects/blob/main/SAFE/shots/Screenshot_6.png)

3. **Reset the System**:
   - Enter `0000` to reset the system and set a new password.

 ![Alt text](https://github.com/shereifDev/AVR-Projects/blob/main/SAFE/shots/Screenshot_1.png)

4. **Lockout Mechanism**:
   - If you enter the wrong password 3 times, the system will lock for 9 seconds.
   
![Alt text](https://github.com/shereifDev/AVR-Projects/blob/main/SAFE/shots/Screenshot_5.png)
