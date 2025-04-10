# Digital Clock with Stopwatch and Timer 

![Alt text](https://github.com/shereifDev/AVR-Projects/blob/main/RTC/shots/Screenshot%20(6).png)

## Project Description
This project implements a multi-functional digital clock using an ATmega32 microcontroller with three main modes:
1. **Clock Mode**: Standard 24-hour digital clock with time setting capability
2. **Stopwatch Mode**: Counts up with start/pause functionality
3. **Timer Mode**: Countdown timer with alarm (buzzer) when time elapses

## Hardware Components
- ATmega32 microcontroller
- 6-digit 7-segment display
- 4x4 matrix keypad
- 2 LEDs (for mode indication)
- Buzzer (for timer alarm)
- Push buttons for mode control

## Features
- **Clock Mode**:
  - 24-hour format
  - Time setting via keypad
- **Stopwatch Mode**:
  - Counts up to 23:59:59
  - Start/pause functionality
- **Timer Mode**:
  - Countdown timer with configurable hours, minutes, seconds
  - Visual (LED) and audible (buzzer) alarm when time elapses
- **Visual Indicators**:
  - Green LED for Stopwatch mode
  - Red LED for Timer mode
  - No LED for Clock mode

## Usage Instructions
1. **Clock Mode** (default):
   - Press SET CLOCK (PA7) to set time using keypad
   - Format: HH MM SS (24-hour format)

2. **Stopwatch Mode**:
   - Press STOPWATCH button (PA6) to enter
   - Press PAUSE/RESUME (PA4) to control counting
   - Green LED indicates active stopwatch

3. **Timer Mode**:
   - Press TIMER button (PA3) to enter
   - Set time using keypad (HH MM SS)
   - Countdown starts automatically
   - Red LED indicates active timer
   - Buzzer sounds when time elapses

## Software Implementation
- Uses Timer2 overflow interrupt for timekeeping (1 second intervals)
- Multiplexed 7-segment display driving
- Button debouncing implemented
- Efficient mode switching between clock, stopwatch, and timer


