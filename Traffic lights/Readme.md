# Traffic Lights System

This project simulates a traffic lights system using AVR microcontroller. The traffic lights are controlled by an array of LEDs connected to different ports of the microcontroller.

## Project Description

The project simulates a simple traffic light control system using LEDs connected to Port C and Port D of the microcontroller. Each set of lights changes based on a fixed delay to represent real-world traffic light behavior (red, yellow, green). The delay time for each light is 2 seconds.

### Features:
- **Multiple LEDs**: LEDs are connected to two ports to represent different traffic lights.
- **Time Delay**: Delays between LED changes to simulate the traffic light sequence.
  
### Tools and Hardware:
- **Microcontroller**: AVR ATmega32
- **Simulation Software**: Proteus (for circuit simulation)
- **Compiler**: AVR-GCC
- **Clock Frequency**: 8 MHz

## Connections:

- **Port C**: LEDs for traffic lights
  - C0, C1, C2, C3, C4, C5, C6, C7
- **Port D**: LEDs for traffic lights
  - D0, D1, D2, D3

