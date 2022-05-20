#ifndef _GPIO_H_
#define _GPIO_H_

#include "Type.h"
typedef enum
{
    /* List the GPIO Ports */
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,

}GPIO_PORT_t;

typedef enum
{
    /* List the GPIO Pins */
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,

}GPIO_PIN_t;

typedef enum
{
    GPIO_DIRECTION_INPUT_PUSH_PULL,
    GPIO_DIRECTION_INPUT_PULL_DOWN,
    GPIO_DIRECTION_INPUT_FLOAT,
    GPIO_DIRECTION_OUTPUT

}GPIO_Direction_t;

typedef enum
{
    GPIO_STATE_LOW,
    GPIO_STATE_HIGH,

}GPIO_State_t;

#define PORT_HIGH 0xff
#define PORT_LOW  0x00

/*Initialization*/
void GPIO_Init(GPIO_PORT_t port,GPIO_PIN_t pin);
/*For Pins*/
void GPIO_SetPinDirection(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_Direction_t direction);
void GPIO_SetPinState(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_State_t state);
GPIO_State_t GPIO_GetPinState(GPIO_PORT_t port,GPIO_PIN_t pin);
/*For Ports*/
void GPIO_SetPortDirection(GPIO_PORT_t port,GPIO_Direction_t direction);
void GPIO_SetPortState(GPIO_PORT_t port,uint08_t state);
uint08_t GPIO_readPort(GPIO_PORT_t port);

#endif
