//driver file should always contain header file of its header
#include "stm32f407xx_gpio_driver.h" // driver specific header

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

 /*
 *peripheral clock setup
 */
 /*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for a given GPIO port by setting/clearing the corresponding bit in RCC's AHB1ENR register
 *
 * @param[in]         - base address of the gpio peripheral(GPIOx)
 * @param[in]         - ENABLE or DISABLE macros (1/0)
 * @param[in]         -
 *
 * @return            -  none / as its void it has no return value
 *
 * @Note              -  In STM32 clock must be enabled before working on any peripheral so before init or any other function always enable reset and clock control

 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
}

 /*
 *Init and DeInit
 */
 /*********************************************************************
 * @fn      		  - Configures a GPIO pin's mode, output speed, pull-up/pull-down, output type, and alternate function according to the settings provided in pGPIOHandle
 *
 * @brief             - This function is responsible for initialisation the gpio
 *
 * @param[in]         - Pointer to a GPIO handle structure containing the target port (pGPIOx) and the desired pin configuration (GPIO_PinConfig)
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -none
 *
 * @Note              - GPIO_PeriClockControl() must be called for the target port before calling
        this function; otherwise the peripheral clock is not active and writes
        to its configuration registers will have no effect.

 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
}


/*********************************************************************
 * @fn      		  - GPIO_DeInit
 *
 * @brief             - This function is responsible to wipe out entire gpio using AHB1RSTR register 
 *
 * @param[in]         - 
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
}

 /*
 *Data Read And Write
 */
 /*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
}
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value){
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint8_t Value){
}
/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){
}

 /*
 *IRQ Configuration and Handling
 */
 /*********************************************************************
 * @fn      		  - GPIO_IRQConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQConfig(void){
}
/*********************************************************************
 * @fn      		  - SPI_IRQPriorityConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQHandling(void){
}
