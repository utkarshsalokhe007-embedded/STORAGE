# Project 2 — ESP32-S3 TX → STM32F407 RX

## Overview

This project implements the reverse UART communication path from Project 1.

The ESP32-S3 transmits data using the ESP-IDF UART driver, while the STM32F407 receives the data using a bare-metal, register-level USART implementation.

The project extends the previous experiment by moving the transmitter and receiver responsibilities to the opposite microcontrollers.

## Architecture

```text
┌─────────────────────┐
│      ESP32-S3       │
│                     │
│   ESP-IDF UART1     │
│                     │
│     GPIO17 TX       │
└──────────┬──────────┘
           │
           │ UART
           │
           ▼
┌─────────────────────┐
│     STM32F407       │
│                     │
│ Bare-Metal USART2   │
│                     │
│       PA3 RX        │
└──────────┬──────────┘
           │
           ▼
      STM32 Application
```

## Communication

The ESP32-S3 generates and transmits UART data through `UART_NUM_1`.

The STM32F407 receives the incoming data through `USART2` using a register-level implementation.

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
ESP32-S3                 STM32F407

UART TX (GPIO17) ──────> USART2 RX (PA3)

GND              ──────> GND
```

A common ground is required between both boards.

## ESP32-S3 — Transmitter

The ESP32-S3 uses the ESP-IDF UART driver to configure UART1 and continuously transmit data.

For the detailed ESP32 transmitter implementation, see:

[ESP32 TX Implementation](./ESP32_TX/)

## STM32F407 — Receiver

The STM32F407 implements USART2 at the register level.

The receiver monitors the USART receive status and reads incoming data from the USART data register.

The project also demonstrates controlling the onboard Orange LED based on received data. Receiving the character `'1'` turns the STM32F407 Discovery board's Orange LED (PD13) on, while any other character turns it off — as documented in the STM32 RX implementation below.

For the detailed STM32 implementation, see:

[STM32 RX Implementation](./STM32_RX/)

## Result

The completed communication path is:

```text
ESP32-S3
   │
   │ ESP-IDF UART1 TX
   ▼
STM32F407
   │
   │ Bare-Metal USART2 RX
   ▼
STM32 Application
   │
   ▼
Orange LED Control
```

According to the current implementation, receiving the character `'1'` turns the STM32F407 Discovery board's Orange LED on, while another character turns it off.

## What This Project Demonstrates

* ESP32-S3 UART transmission using ESP-IDF
* STM32F407 bare-metal UART reception
* USART2 register-level configuration
* RXNE polling
* TXE-based transmission
* `printf()` retargeting
* GPIO output control
* Cross-MCU UART communication

## Current Limitations

The UART receiver currently uses a blocking/polling approach.

The implementation is intentionally kept simple to focus on understanding the USART peripheral and register-level communication.

## Future Improvements

Planned improvements include:

* UART interrupt-based reception
* Timer-based delays
* Receive buffering
* DMA-based UART communication
* More complex command parsing
* Using received commands to control additional peripherals

## Demonstration

A video demonstration of this project will be added here.

<!-- Add LinkedIn / video link here -->

## Previous Project

The opposite communication direction is implemented in:

[Project 1 — STM32F407 TX → ESP32-S3 RX](../Project_1_STM32_TX_to_ESP32_RX/)
