#include "stm32f407_regs.h"

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm__("nop");
    }
}

int main(void)
{
    /* Enable clock to GPIOD */
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    /* Set PD12-PD15 as general purpose output (01) */
    GPIOD_MODER &= ~((3UL << (12 * 2)) | (3UL << (13 * 2)) |
                      (3UL << (14 * 2)) | (3UL << (15 * 2)));
    GPIOD_MODER |=  ((1UL << (12 * 2)) | (1UL << (13 * 2)) |
                      (1UL << (14 * 2)) | (1UL << (15 * 2)));

    while (1) {
        GPIOD_ODR ^= (1UL << 12); /* toggle green LED */
        delay(1000000);
        GPIOD_ODR ^= (1UL << 13); /* toggle orange LED */
        delay(1000000);
        GPIOD_ODR ^= (1UL << 14); /* toggle red LED */
        delay(1000000);
        GPIOD_ODR ^= (1UL << 15); /* toggle blue LED */
        delay(1000000);
    }
}
