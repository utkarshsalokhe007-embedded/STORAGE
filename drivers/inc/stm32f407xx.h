/*
 * stm32f407xx.h
 *
 *  Created on: Aug 28, 2026
 *      Author: admin
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_
#include <stdint.h>

#define __vO volatile

#define FLASH_BASEADDR   0x08000000U  /* SEARCH FLASH IN R.M INSIDE  Memory and bus architecture , TABLE Table 3. Memory mapping vs. Boot mode/physical remap GIVES BASE ADDRESS*/
#define SRAM1_BASEADDR   0x20000000U  /*ABOVE COMMENT HELPS HERE FOR ADDRESS ALSO */
#define SRAM2_BASEADDR   0x2001C000U  /*ABOVE COMMENT HELPS HERE FOR ADDRESS ALSO */
#define ROM              0x1fff0000U    /*ABOVE COMMENT HELPS HERE FOR ADDRESS ALSO */
#define SRAM             SRAM1_BASEADDR


#define PERIPH_BASE      0x40000000U
#define APB1PERIPH_BASE  PERIPH_BASE  /*GO INSIDE RM SEARCH MEMORY MAP Table 1. STM32F4xx register boundary addresses GIVES ADDRESSES*/
#define APB2PERIPH_BASE  0x40010000U  /*GO INSIDE RM SEARCH MEMORY MAP Table 1. STM32F4xx register boundary addresses GIVES ADDRESSES*/
#define AHB1PERIPH_BASE  0x40020000U  /*GO INSIDE RM SEARCH MEMORY MAP Table 1. STM32F4xx register boundary addresses GIVES ADDRESSES*/
#define AHB2PERIPH_BASE  0x50000000U  /*GO INSIDE RM SEARCH MEMORY MAP Table 1. STM32F4xx register boundary addresses GIVES ADDRESSES*/
#define AHB3PERIPH_BASE  0xA0000000U  /*GO INSIDE RM SEARCH MEMORY MAP Table 1. STM32F4xx register boundary addresses GIVES ADDRESSES*/
#define RCC_BASEADDR     (AHB1PERIPH_BASE + 0x3800)
/* AHB1 BUS*/

#define GPIOA_BASEADDR  (0x40020000U + 0X0000 )     /* BASE ADDR + OFFSETS GO INSIDE RM SEARCH MEMORY MAP Table 1. STM32F4xx register boundary addresses GIVES ADDRESSES CHECK AHB1*/
#define GPIOB_BASEADDR  (0x40020000U + 0X0400 )     /* USE THIS (0x40020000U + 0X0400 ) OR (AHB1PERIPH_BASE +OFFSET ) */
#define GPIOC_BASEADDR  (0x40020000U + 0X0800 )
#define GPIOD_BASEADDR  (0x40020000U + 0X0C00 )
#define GPIOE_BASEADDR  (0x40020000U + 0X1000 )
#define GPIOF_BASEADDR  (0x40020000U + 0X1400 )
#define GPIOG_BASEADDR  (0x40020000U + 0X1800 )
#define GPIOH_BASEADDR  (0x40020000U + 0X1C00 )
#define GPIOI_BASEADDR  (0x40020000U + 0X2000 )
#define GPIOJ_BASEADDR  (0x40020000U + 0X2400 )
#define GPIOK_BASEADDR  (0x40020000U + 0X2800 )


/* APB1 BUS*/
#define I2C1_BASEADDR   (APB1PERIPH_BASE + 0X5400 )
#define I2C2_BASEADDR   (APB1PERIPH_BASE + 0X5800 )
#define I2C3_BASEADDR   (APB1PERIPH_BASE + 0X5C00 )
#define SPI2_BASEADDR   (APB1PERIPH_BASE + 0X3800 )
#define SPI3_BASEADDR   (APB1PERIPH_BASE + 0X3C00 )
#define USART2_BASEADDR (APB1PERIPH_BASE + 0X4400 )
#define USART3_BASEADDR (APB1PERIPH_BASE + 0X4800 )
#define UART4_BASEADDR  (APB1PERIPH_BASE + 0X4C00 )
#define UART5_BASEADDR  (APB1PERIPH_BASE + 0X5000 )

/* APB2 BUS*/
#define SPI1_BASEADDR   (APB2PERIPH_BASE + 0X3000 )
#define USART1_BASEADDR (APB2PERIPH_BASE + 0X1000 )
#define USART6_BASEADDR (APB2PERIPH_BASE + 0X1400 )
#define EXTI_BASEADDR   (APB2PERIPH_BASE + 0X3C00 )
#define SYSCFG_BASEADDR (APB2PERIPH_BASE + 0X3800 )

/************************************************** PERIPHERAL REGISTER DEFINITION STRUCTURES  *******************************************************************/

typedef struct
{
	__vO uint32_t MODER;   /*GPIO port mode register (GPIOx_MODER) (x = A..I/J/K)  Address offset: 0x00 */
	__vO uint32_t OTYPER;  /*GPIO port output type register (GPIOx_OTYPER) (x = A..I/J/K) Address offset: 0x04*/
	__vO uint32_t OSPEEDR; /*GPIO port output speed register (GPIOx_OSPEEDR)(x = A..I/J/K)*/
	__vO uint32_t PUPDR;   /*GPIO port pull-up/pull-down register (GPIOx_PUPDR)(x = A..I/J/K)*/
	__vO uint32_t IDR;     /*GPIO port input data register (GPIOx_IDR) (x = A..I/J/K)*/
	__vO uint32_t ODR ;    /*GPIO port output data register (GPIOx_ODR) (x = A..I/J/K)*/
	__vO uint32_t BSRR ;   /*GPIO port bit set/reset register (GPIOx_BSRR) (x = A..I/J/K)*/
	__vO uint32_t LCKR ;   /*GPIO port configuration lock register (GPIOx_LCKR)*/
	__vO uint32_t AFRL ;   /*GPIO alternate function low register (GPIOx_AFRL) (x = A..I/J/K*/
	__vO uint32_t AFRH ;   /*GPIO alternate function high register (GPIOx_AFRH)(x = A..I/J) Address offset: 0x24*/

}GPIO_RegDef_t;

typedef struct
{
	__vO uint32_t CR;           /*RCC clock control register (RCC_CR)  Address offset: 0x00 */
	__vO uint32_t PLLCFGR;      /*RCC PLL configuration register (RCC_PLLCFGR) Address offset: 0x04*/
	__vO uint32_t CFGR;         /*RCC clock configuration register (RCC_CFGR)*/
	__vO uint32_t CIR;          /*RCC clock interrupt register (RCC_CIR)*/
	__vO uint32_t AHB1RSTR;     /*RCC AHB1 peripheral reset register (RCC_AHB1RSTR)*/
	__vO uint32_t AHB2RSTR ;    /*RCC AHB2 peripheral reset register (RCC_AHB2RSTR)*/
	__vO uint32_t AHB3RSTR ;    /*RCC AHB3 peripheral reset register (RCC_AHB3RSTR)*/
	     uint32_t RESERVED1;
	__vO uint32_t APB1RSTR ;    /*RCC APB1 peripheral reset register (RCC_APB1RSTR)*/
	__vO uint32_t APB2RSTR ;    /*RCC APB2 peripheral reset register (RCC_APB2RSTR)*/
         uint32_t RESERVED2[2];
	__vO uint32_t AHB1ENR ;     /*RCC AHB1 peripheral clock register (RCC_AHB1ENR)*/
	__vO uint32_t AHB2ENR ;     /*RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)*/
	__vO uint32_t AHB3ENR;      /*RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)*/
         uint32_t RESERVED3;
	__vO uint32_t APB1ENR;      /*RCC APB1 peripheral clock enable register (RCC_APB1ENR)*/
	__vO uint32_t APB2ENR;      /*RCC APB2 peripheral clock enable register (RCC_APB2ENR)*/
         uint32_t RESERVED4[2];
    __vO uint32_t AHB1LPENR;    /*RCC AHB1 peripheral clock enable in low power mode register(RCC_AHB1LPENR)*/
    __vO uint32_t AHB2LPENR;    /* RCC AHB2 peripheral clock enable in low power mode register(RCC_AHB2LPENR)*/
    __vO uint32_t AHB3LPENR;    /* RCC AHB3 peripheral clock enable in low power mode register(RCC_AHB3LPENR)*/
         uint32_t RESERVED5;
    __vO uint32_t APB1LPENR;    /*RCC APB1 peripheral clock enable in low power mode register(RCC_APB1LPENR)*/
    __vO uint32_t APB2LPENR;    /*RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR)*/
         uint32_t RESERVED6[2];
	__vO uint32_t BDCR;         /*RCC Backup domain control register (RCC_BDCR)*/
	__vO uint32_t CSR;          /*RCC clock control & status register (RCC_CSR)*/
         uint32_t RESERVED7[2];
	__vO uint32_t SSCGR;        /*RCC spread spectrum clock generation register (RCC_SSCGR)*/
	__vO uint32_t PLLI2SCFGR;   /*RCC PLLI2S configuration register (RCC_PLLI2SCFGR)*/
	__vO uint32_t PLLSAICFGR;   /* RCC PLL configuration register (RCC_PLLSAICFGR)*/
	__vO uint32_t DCKCFGR;      /*RCC Dedicated Clock Configuration Register (RCC_DCKCFGR)Address offset: 0x8C*/

}RCC_RegDef_t;

/************************************************** PERIPHERAL  DEFINITION   *******************************************************************/


#define GPIOA  ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB  ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC  ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD  ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE  ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF  ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG  ((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH  ((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define GPIOI  ((GPIO_RegDef_t *)GPIOI_BASEADDR)


#define RCC    ((RCC_RegDef_t *)RCC_BASEADDR)


/*
*Clock Enable macros for GPIOx peripherals
*/
#define GPIOA_PCLK_EN()  (RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()  (RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()  (RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()  (RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()  (RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN()  (RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN()  (RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN()  (RCC->AHB1ENR |=(1<<7))
#define GPIOI_PCLK_EN()  (RCC->AHB1ENR |=(1<<8))
 /*
 * Clock Enable macros for I2x peripherals
*/
#define I2C1_PCLK_EN()  (RCC->APB1ENR |=(1<<21))
#define I2C2_PCLK_EN()  (RCC->APB1ENR |=(1<<22))
#define I2C3_PCLK_EN()  (RCC->APB1ENR |=(1<<23))
/*
*Clock Enable macros for SPIX peripherals
*/
#define SPI1_PCLK_EN()  (RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()  (RCC->APB1ENR |=(1<<14))
#define SPI3_PCLK_EN()  (RCC->APB1ENR |=(1<<15))
/*
*Clock Enable macros for USARTX peripherals
*/
#define USART1_PCLK_EN()  (RCC->APB2ENR |=(1<<4))
#define USART2_PCLK_EN()  (RCC->APB1ENR |=(1<<17))
#define USART3_PCLK_EN()  (RCC->APB1ENR |=(1<<18))
#define UART4_PCLK_EN()  (RCC->APB1ENR |=(1<<19))
#define UART5_PCLK_EN()  (RCC->APB1ENR |=(1<<20))
#define USART6_PCLK_EN()  (RCC->APB2ENR |=(1<<5))


/*
*Clock Enable macros for ADCX peripherals
*/
#define ADC1_PCLK_EN()  (RCC->APB2ENR |=(1<<8))
#define ADC2_PCLK_EN()  (RCC->APB2ENR |=(1<<9))
#define ADC3_PCLK_EN()  (RCC->APB2ENR |=(1<<10))

/*
*Clock Enable macros for SYSCFGX peripherals
*/
#define SYSCFG_PCLK_EN()  (RCC->APB2ENR |=(1<<14))

/*
*Clock Enable macros for TIMX peripherals
*/
#define TIM1_PCLK_EN()   (RCC->APB2ENR |=(1<<0))
#define TIM2_PCLK_EN()   (RCC->APB1ENR |=(1<<0))
#define TIM3_PCLK_EN()   (RCC->APB1ENR |=(1<<1))
#define TIM4_PCLK_EN()   (RCC->APB1ENR |=(1<<2))
#define TIM5_PCLK_EN()   (RCC->APB1ENR |=(1<<3))
#define TIM6_PCLK_EN()   (RCC->APB1ENR |=(1<<4))
#define TIM7_PCLK_EN()   (RCC->APB1ENR |=(1<<5))
#define TIM8_PCLK_EN()   (RCC->APB2ENR |=(1<<1))
#define TIM9_PCLK_EN()   (RCC->APB2ENR |=(1<<16))
#define TIM10_PCLK_EN()  (RCC->APB2ENR |=(1<<17))
#define TIM11_PCLK_EN()  (RCC->APB2ENR |=(1<<18))
#define TIM12_PCLK_EN()  (RCC->APB1ENR |=(1<<6))
#define TIM13_PCLK_EN()  (RCC->APB1ENR |=(1<<7))
#define TIM14_PCLK_EN()  (RCC->APB1ENR |=(1<<8))


/******disable  */
/*
*Clock Disable macros for GPIOx peripherals
*/
#define GPIOA_PCLK_DI()  (RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()  (RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()  (RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()  (RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()  (RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()  (RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()  (RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()  (RCC->AHB1ENR &=~(1<<7))
#define GPIOI_PCLK_DI()  (RCC->AHB1ENR &=~(1<<8))
 /*
 * Clock Disable macros for I2x peripherals
*/
#define I2C1_PCLK_DI()  (RCC->APB1ENR &=~(1<<21))
#define I2C2_PCLK_DI()  (RCC->APB1ENR &=~(1<<22))
#define I2C3_PCLK_DI()  (RCC->APB1ENR &=~(1<<23))
/*
*Clock Disable macros for SPIX peripherals
*/
#define SPI1_PCLK_DI()  (RCC->APB2ENR &=~(1<<12))
#define SPI2_PCLK_DI()  (RCC->APB1ENR &=~(1<<14))
#define SPI3_PCLK_DI()  (RCC->APB1ENR &=~(1<<15))
/*
*Clock Disable macros for USARTX peripherals
*/
#define USART1_PCLK_DI()  (RCC->APB2ENR &=~(1<<4))
#define USART2_PCLK_DI()  (RCC->APB1ENR &=~(1<<17))
#define USART3_PCLK_DI()  (RCC->APB1ENR &=~(1<<18))
#define UART4_PCLK_DI()  (RCC->APB1ENR &=~(1<<19))
#define UART5_PCLK_DI()  (RCC->APB1ENR &=~(1<<20))
#define USART6_PCLK_DI()  (RCC->APB2ENR &=~(1<<5))


/*
*Clock Disable macros for ADCX peripherals
*/
#define ADC1_PCLK_DI()  (RCC->APB2ENR &=~(1<<8))
#define ADC2_PCLK_DI()  (RCC->APB2ENR &=~(1<<9))
#define ADC3_PCLK_DI()  (RCC->APB2ENR &=~(1<<10))

/*
*Clock Disable macros for SYSCFGX peripherals
*/
#define SYSCFG_PCLK_DI()  (RCC->APB2ENR &=~(1<<14))

/*
*Clock Disable macros for TIMX peripherals
*/
#define TIM1_PCLK_DI()   (RCC->APB2ENR &=~(1<<0))
#define TIM2_PCLK_DI()   (RCC->APB1ENR &=~(1<<0))
#define TIM3_PCLK_DI()   (RCC->APB1ENR &=~(1<<1))
#define TIM4_PCLK_DI()   (RCC->APB1ENR &=~(1<<2))
#define TIM5_PCLK_DI()   (RCC->APB1ENR &=~(1<<3))
#define TIM6_PCLK_DI()   (RCC->APB1ENR &=~(1<<4))
#define TIM7_PCLK_DI()   (RCC->APB1ENR &=~(1<<5))
#define TIM8_PCLK_DI()   (RCC->APB2ENR &=~(1<<1))
#define TIM9_PCLK_DI()   (RCC->APB2ENR &=~(1<<16))
#define TIM10_PCLK_DI()  (RCC->APB2ENR &=~(1<<17))
#define TIM11_PCLK_DI()  (RCC->APB2ENR &=~(1<<18))
#define TIM12_PCLK_DI()  (RCC->APB1ENR &=~(1<<6))
#define TIM13_PCLK_DI()  (RCC->APB1ENR &=~(1<<7))
#define TIM14_PCLK_DI()  (RCC->APB1ENR &=~(1<<8))

//some generic macros
#define ENABLE             1
#define DISABLE            0
#define SET                ENABLE
#define RESET              DISABLE

#endif /* INC_STM32F407XX_H_ */
