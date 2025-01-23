This repository contains the source code and documentation for a car model capable of:
- Parking automatically within a specific garage line
- Avoiding obstacles using infrared (TCRT5000) and ultrasonic (HC-SR04) sensors
- Remote control via the YS-IRTM communication module

The platform is based on the STM32F1 series microcontroller, integrating both embedded hardware modules and software programming.

---

## Features

- **Automatic Parking**  
  Detects the garage boundary and maneuvers the car to park within the specified line.

- **Obstacle Avoidance**  
  Utilizes TCRT5000 and HC-SR04 sensors to detect obstacles and navigate safely.

- **Remote Control**  
  Employs the YS-IRTM communication module to manage mobility actions (e.g., start, stop, direction).

- **Embedded Hardware Integration**  
  Combines sensor modules, motor drivers, and communication modules directly with the STM32F1 board.

---
---

## Hardware & Setup

1. **STM32F1 Development Board**  
   - Any STM32F1xx discovery board or custom board with sufficient GPIO pins.

2. **Motor Driver**  
   - L298N or a similar dual H-bridge for controlling DC motors.

3. **Sensors**  
   - **TCRT5000**: Infrared sensors for boundary detection.  
   - **HC-SR04**: Ultrasonic sensors for distance measurement.

4. **YS-IRTM Module**  
   - Remote control with integrated IR receiver/transmitter for wireless communication.

5. **Power Supply**  
   - A DC battery or regulated power supply (e.g., 5V for motors, 3.3V on-board for MCU).

### Wiring Overview

- **TCRT5000** sensors → GPIO pins (for boundary detection)  
- **HC-SR04** trigger/echo pins → GPIO pins (for distance measurement)  
- **YS-IRTM** TX/RX → UART pins (remote control)  
- **Motor Driver** PWM & control signals → STM32F1 outputs → DC motors

---

## Software Implementation

1. **Initialization**  
   - Configure clock, GPIO, UART, and PWM timers.  
   - Initialize sensors (TCRT5000, HC-SR04) and communication module (YS-IRTM).

2. **Main Loop**  
   - Continuously read sensor data (IR boundary detection, ultrasonic distance).  
   - Update motor control signals to perform automatic parking or obstacle avoidance.  
   - Process remote commands received via the YS-IRTM module.

3. **Algorithm Highlights**  
   - **Automatic Parking**  
     1. Use TCRT5000 to detect boundary lines.  
     2. Execute motor movements to align car within the garage space.  
   - **Obstacle Avoidance**  
     1. Measure distances with HC-SR04.  
     2. If an obstacle is detected within a threshold, adjust direction or speed.

---

## Getting Started

1. **Clone this repository**:

   ```bash
   git clone https://github.com/Yunxuan-Lola/Automatic-Parking-Car.git
