#include "config.h"
#include "LED.h"
#include "GPIO.h"
#include "Port.h"
#include "Type.h"
#include "BITMATH.h"

#if (LED_SWC_STATUS == SWC_STATUS_ENABLE)

#define LED_STATE_ON       (0XAB)
#define LED_STATE_OFF      (0XEC)


static uint08_t LED_state;

#endif

void LED_Init(void)
{
#if (LED_SWC_STATUS == SWC_STATUS_ENABLE)

    GPIO_Init(LED_PORT,LED_PIN_NUMBER);
    
    /* Set led state variable to off */
    LED_state = LED_STATE_OFF;

    /* Set Led pin to output */
    GPIO_SetPinDirection(LED_PORT,LED_PIN_NUMBER,GPIO_DIRECTION_OUTPUT);

    /* Set Led pin state to low */
    GPIO_SetPinState(LED_PORT,LED_PIN_NUMBER,GPIO_STATE_LOW);

#endif
}

void LED_Update(void)
{
#if (LED_SWC_STATUS == SWC_STATUS_ENABLE)

    switch (LED_state)
    {
    case LED_STATE_OFF:

        /* Set Led On */
        LED_state = LED_STATE_ON;

        /* Set Led pin state to high */
        GPIO_SetPinState(LED_PORT,LED_PIN_NUMBER,GPIO_STATE_HIGH);

        break;

    case LED_STATE_ON:

        /* Set Led off */
        LED_state = LED_STATE_OFF;

        /* Set Led pin state to high */
        GPIO_SetPinState(LED_PORT,LED_PIN_NUMBER,GPIO_STATE_LOW);

        break;

    default:
        /* Do No Thing */
        break;
    }
    
#endif
}
