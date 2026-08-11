# Project 1 — STM32F407 TX → ESP32-S3 RX

## Overview

This project demonstrates UART communication between an STM32F407 Discovery board and an ESP32-S3 using two different approaches to embedded development.

The STM32F407 side is implemented using bare-metal, register-level programming, while the ESP32-S3 side uses the ESP-IDF UART driver.

The purpose of this project is to understand UART communication while comparing direct peripheral configuration on STM32 with the driver-based approach provided by ESP-IDF.

## Architecture

```text
┌─────────────────────┐
│     STM32F407       │
│                     │
│  Bare-Metal USART2  │
│                     │
│       PA2 TX        │
└──────────┬──────────┘
           │
           │ UART
           │
           ▼
┌─────────────────────┐
│      ESP32-S3       │
│                     │
│   ESP-IDF UART1     │
│                     │
│     GPIO18 RX       │
└──────────┬──────────┘
           │
           ▼
     ESP-IDF Monitor
```

## Communication

The STM32F407 generates and transmits a message through `USART2`.

The ESP32-S3 receives the transmitted data through `UART_NUM_1` and displays the received message through the ESP-IDF logging/monitor interface.

### UART Configuration

| Parameter    | Configuration |
| ------------ | ------------- |
| Protocol     | UART          |
| Baud Rate    | 115200        |
| Data Bits    | 8             |
| Parity       | None          |
| Stop Bits    | 1             |
| Flow Control | Disabled      |

## Hardware

* STM32F407 Discovery Board
* ESP32-S3
* USB cables
* Jumper wires

### Connection

```text
STM32F407                ESP32-S3

USART2 TX (PA2)  ──────>  UART RX (GPIO18)

GND              ──────>  GND
```

A common ground is required between both boards.

## STM32F407 — Transmitter

The STM32F407 transmitter is implemented entirely at the register level without using the STM32 HAL UART APIs.

The USART2 peripheral is configured through the STM32 peripheral registers, and `printf()` is retargeted to the USART transmitter.

For the detailed STM32 implementation, see:

[STM32 TX Implementation](./STM32_TX/)

## ESP32-S3 — Receiver

The ESP32-S3 uses the ESP-IDF UART driver to configure UART1, receive incoming data through its driver buffer, and display the received message using `ESP_LOGI`.

For the detailed ESP32 implementation, see:

[ESP32 RX Implementation](./ESP32_RX/)

## Result

The completed communication path is:

```text
STM32F407
   │
   │ Bare-Metal USART2 TX
   ▼
ESP32-S3
   │
   │ ESP-IDF UART1 RX
   ▼
ESP-IDF Monitor
```

The message transmitted by the STM32F407 is successfully received and displayed by the ESP32-S3 in real time.

## What This Project Demonstrates

* STM32F407 bare-metal UART transmission
* Register-level peripheral configuration
* USART2 configuration
* GPIO alternate-function configuration
* `printf()` retargeting
* ESP-IDF UART driver configuration
* UART data reception and buffering
* Communication between two different MCU architectures

## Current Limitations

The current implementation intentionally uses a simple polling/busy-wait approach.

The STM32 is also operating with the current clock configuration documented in its individual project README.

These limitations are part of the current learning stage and will be addressed in later projects.

## Future Improvements

Planned improvements include:

* Timer-based delays
* UART interrupt-driven communication
* Improved receive/transmit handling
* DMA-based UART communication
* Further exploration of STM32 peripheral drivers

## Demonstration

A video demonstration of this project will be added here.

<!-- Add LinkedIn / video link here -->

## Related Project

The reverse communication direction is implemented separately in:

[Project 2 — ESP32-S3 TX → STM32F407 RX](../Project_2_STM32_RX_from_ESP32_TX/)
