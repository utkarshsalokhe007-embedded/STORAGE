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
 * @return            - none
 *
 * @Note              - use this function to clear the active state of gpio to bring back to default state use this function

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
 * @brief             - Reads the current logic level of a single input pin from the
 *                       port's input data register (IDR)
 *
 * @param[in]         - Base address of the GPIO port (pGPIOx)
 * @param[in]         - Pin number to read (0-15), e.g. PinNumber = 5 reads pin 5
 * @param[in]         -
 *
 * @return            - 0 or 1, representing the logic level read from the pin
 *
 * @Note              - The pin must be configured as input mode for this to return
 *                       a meaningful value

 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
}
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             - Reads the current logic levels of all 16 pins of a GPIO port
 *                       at once from the port's input data register (IDR)
 *
 * @param[in]         - Base address of the GPIO port (pGPIOx)
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - 16-bit value where each bit represents the logic level of the
 *                       corresponding pin (bit 0 = pin 0, bit 1 = pin 1, and so on)
 *
 * @Note              -

 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             - Sets a single output pin to HIGH or LOW by writing to the
 *                       port's output data register (ODR)
 *
 * @param[in]         - Base address of the GPIO port (pGPIOx)
 * @param[in]         - Pin number to write to (0-15)
 * @param[in]         - Value to write - GPIO_PIN_SET (1) or GPIO_PIN_RESET (0)
 *
 * @return            - none
 *
 * @Note              - The pin must be configured as output mode for this to have
 *                       any physical effect

 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value){
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             - Writes a 16-bit value to the entire GPIO port at once by
 *                       writing directly to the port's output data register (ODR)
 *
 * @param[in]         - Base address of the GPIO port (pGPIOx)
 * @param[in]         - 16-bit value to write - each bit sets the corresponding pin's
 *                       output level (bit 0 = pin 0, bit 1 = pin 1, and so on)
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - This overwrites all 16 pins of the port simultaneously - any
 *                       pins not configured as output will be unaffected on the
 *                       physical pin, but their ODR bit is still written

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint8_t Value){
}
/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             - Inverts the current output state of a single pin (HIGH becomes
 *                       LOW and vice versa) by flipping its bit in the output data
 *                       register (ODR)
 *
 * @param[in]         - Base address of the GPIO port (pGPIOx)
 * @param[in]         - Pin number to toggle (0-15)
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - The pin must be configured as output mode for this to have
 *                       any physical effect

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
