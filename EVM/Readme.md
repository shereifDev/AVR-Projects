# Electronic Voting Machine Project

## Overview
This project is a simple counter application implemented on an AVR microcontroller. It uses buttons to increment counters and an LCD to display the current values. The counters can be reset to zero using a dedicated reset button.

## Features
- **Four Counters (A, B, C, D):** Each counter can be incremented by pressing its corresponding button.
- **Reset Functionality:** A reset button resets all counters to zero.
- **LCD Display:** The current values of the counters are displayed on an LCD screen.
- **Debouncing:** Simple debouncing logic is implemented to ensure reliable button presses.

## Hardware Requirements
- AVR microcontroller (e.g., ATmega32)
- 16x2 LCD screen
- 5 push buttons (for counters A, B, C, D, and reset)
- Pull-up resistors for buttons (or internal pull-ups can be used)
- Power supply (e.g., 5V)

## Software Requirements
- AVR-GCC compiler
- AVRDUDE (for flashing the microcontroller)
- avr-libc (AVR C library)

## Pin Configuration
- **Buttons:**
  - BUTTON_A: PD0
  - BUTTON_B: PD1
  - BUTTON_C: PD2
  - BUTTON_D: PD3
  - RESET: PD4
- **LCD:**
  - RS: PB0
  - RW: PB1
  - E: PB2
  - Data Pins: PB4-PB7 (4-bit mode)

## How It Works
1. **Initialization:**
   - The LCD is initialized, and the buttons are configured with internal pull-up resistors.
   - The LCD displays a welcome message and prompts the user to press any button to start.

2. **Main Loop:**
   - The program continuously checks the state of each button.
   - When a button is pressed, the corresponding counter is incremented, and the new value is displayed on the LCD.
   - If the reset button is pressed, all counters are reset to zero, and the LCD is updated accordingly.

## Code Structure
- **LCD.h:** Contains functions for initializing and controlling the LCD.
- **switch.h:** Contains functions for initializing and reading the state of the buttons.
- **EVO.h:** Contains project-specific definitions and configurations.
- **main.c:** Contains the main logic of the application.
