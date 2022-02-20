#ifndef _GPIO_H_
#define	_GPIO_H_

typedef enum 
{
	/* List the gpio pins */
	GPIO_PIN_PORTA_0,
	
}GPIO_PIN_t;

typedef enum 
{
	GPIO_DIRECTION_INPUT,
	GPIO_DIRECTION_OUTPUT,
	
}GPIO_Direction_t;

typedef enum 
{
	/* List the gpio pins */
	GPIO_STATE_LOW,
	GPIO_STATE_HIGH,
	
}GPIO_State_t;

void GPIO_Init(void);
void GPIO_SetPinDirection(GPIO_PIN_t pin,GPIO_Direction_t direction);
void GPIO_SetPinState(GPIO_PIN_t pin,GPIO_State_t state);
GPIO_State_t GPIO_GetPinState(GPIO_PIN_t pin);


#endif