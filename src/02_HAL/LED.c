#include "LED.h"
#include "GPIO.h"
#include "Port.h"
#include "Type.h"
#include "BITMATH.h"

#define LED_STATE_ON       (0XAB)
#define LED_STATE_OFF      (0XEC)


static uint08_t LED_state;

void LED_Init(void)
{
    /* Set led state variable to off */
    LED_state = LED_STATE_OFF;

    /* Set Led pin to output */
    GPIO_SetPinDirection(PORT,LED_PIN_NUMBER,GPIO_DIRECTION_OUTPUT);
   
    /* Set Led pin state to low */
    GPIO_SetPinState(PORT,LED_PIN_NUMBER,GPIO_STATE_LOW);
}

void LED_Update(void)
{

    switch (LED_state)
    {
    case LED_STATE_OFF:

        /* Set Led On */
        LED_state = LED_STATE_ON;

        /* Set Led pin state to high */
        GPIO_SetPinState(PORT,LED_PIN_NUMBER,GPIO_STATE_HIGH);

        break;

    case LED_STATE_ON:

        /* Set Led off */
        LED_state = LED_STATE_OFF;

        /* Set Led pin state to high */
        GPIO_SetPinState(PORT,LED_PIN_NUMBER,GPIO_STATE_LOW);

        break;

    default:
        /* Do No Thing */
        break;
    }

}