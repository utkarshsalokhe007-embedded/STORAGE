#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

//this file must contain stm32 driver file there fore mcu specific file is stm32f407xx
#include "stm32f407xx.h"

/* contents inside driver apis are :
1) gpio port name
2)gpio pin number
3) gpio mode
4) gpio speed
5) gpio outputtype
6)gpio pull up pulldown
7) gpio alternate function
all above will be used by user application
*/
typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;
/*this is handle structure for gpio pin*/

typedef struct
{
    //pointer to hold the base address of the GPIO peripheral
    GPIO_RegDef_t *pGPIOx; /*This hold the base address of gpio port to which the pin belongs x=a,b,c... */
    GPIO_PinConfig_t GPIO_PinConfig; /*This Holds Pin configuration gpio's settings*/

}GPIO_Handle_t;
/*this is CONFIGURATION structure for gpio pin*/

/*********************************************************************************************************
 * API'S Supported by this driver
 * for more info about the apis check the func defintions
 */

 /*
 *peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
 /*
 *Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

 /*
 *Data Read And Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

 /*
 *IRQ Configuration and Handling
 */
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);

#endif /*INC_STM32F407XX_GPIO_DRIVER_H_*/
