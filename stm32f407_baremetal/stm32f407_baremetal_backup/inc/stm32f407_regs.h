#ifndef STM32F407_REGS_H
#define STM32F407_REGS_H

#include <stdint.h>

#define PERIPH_BASE        0x40000000UL
#define AHB1PERIPH_BASE    (PERIPH_BASE + 0x00020000UL)

/* RCC */
#define RCC_BASE           (AHB1PERIPH_BASE + 0x3800UL)
#define RCC_AHB1ENR        (*(volatile uint32_t *)(RCC_BASE + 0x30))

/* GPIOD (LEDs are on PD12-PD15) */
#define GPIOD_BASE         (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOD_MODER        (*(volatile uint32_t *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR          (*(volatile uint32_t *)(GPIOD_BASE + 0x14))

#define RCC_AHB1ENR_GPIODEN (1UL << 3)

#endif
