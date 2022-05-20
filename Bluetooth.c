/*
 * Bluetooth.c
 *
 *  Created on: May 20, 2022
 *      Author: MARIEM
 */
#include "Type.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "UART.h"
#include "Motor.h"
#include "tm4c123gh6pm.h"

/* HC-05 Bluetooth Module*/

char Received_data = 0;
uint16_t duty_cycle = 25;


void Bluetooth_Init(void)
{
#if (Bluetooth_SWC_STATUS == SWC_STATUS_ENABLE)

    /*Initiate UART*/
    UART_Init(UART_5);
    /*Leds to check */
    GPIO_Init(GPIO_PORTD,GPIO_PIN_6);
    GPIO_Init(GPIO_PORTD,GPIO_PIN_7);
    GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_6, GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_6, GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_6,GPIO_STATE_LOW);
    GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_7,GPIO_STATE_LOW);


#endif
}


/* Read data from Rx5 pin of TM4C123 */
char Bluetooth_Read(void)
{
#if (Bluetooth_SWC_STATUS == SWC_STATUS_ENABLE)
     char data;

     if(GET_BIT(UART5_FR_R ,4) == 0) /* wait until Rx buffer is not full */
     {
         data = UART5_DR_R ;     /* before giving it another byte */
     }

     return (unsigned char) data;
#endif
}

void Bluetooth_Control(char data)
{
#if (Bluetooth_SWC_STATUS == SWC_STATUS_ENABLE)

        switch (data)
        {
            case 'H':
                /*High Speed*/
                GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_6,GPIO_STATE_HIGH);
                GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_7,GPIO_STATE_HIGH);
                duty_cycle = 75;
                Motor_SetSpeed(MOTOR_SPEED_HIGH);
                break;

            case 'M':
                /*Medium Speed*/
                GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_6,GPIO_STATE_LOW);
                GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_7,GPIO_STATE_HIGH);
                duty_cycle = 50;
                Motor_SetSpeed(MOTOR_SPEED_MID);
                break;

            case 'L':
                /*Low Speed*/
                GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_6,GPIO_STATE_HIGH);
                GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_7,GPIO_STATE_LOW);
                duty_cycle = 25;
                Motor_SetSpeed(MOTOR_SPEED_LOW);
                break;

            case 'F':
                /*Go Forward*/
                break;

            case 'B':
                /*Go Backward*/
                break;

            case 'S':
                /*STOP*/
                break;

            default:
                /*Do nothing*/
                break;
        }
#endif
}

void Bluetooth (void)
{
#if (Bluetooth_SWC_STATUS == SWC_STATUS_ENABLE)
    Bluetooth_Init();
    Received_data = Bluetooth_Read();
    Bluetooth_Control(Received_data);
#endif
}
