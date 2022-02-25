#include "Types.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"

/*(0 for A, 1 For B, 2 For C, 3 For D , 4 For E , 5 For F)*/
//#define Port_Selc 0

void GPIO_Init(GPIO_PORT_t port)
{
	/*Enable clock for pins of the Port selected*/
	SET_BIT(SYSCTL_RCGCGPIO_R,port);
	while (GET_BIT(SYSCTL_PRGPIO_R,port)== 0)
	{};
}

void GPIO_SetPinDirection(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_Direction_t direction)
{
	switch(port)
	{
		case GPIO_PORTA:
			
			switch(direction)
			{
				case GPIO_DIRECTION_INPUT_PUSH_PULL:
					CLR_BIT(GPIO_PORTA_DIR_R,pin);
					/*Pull up resistor*/
					SET_BIT(GPIO_PORTA_PUR_R,pin);
					break;
				case GPIO_DIRECTION_INPUT_FLOAT:
					CLR_BIT(GPIO_PORTA_DIR_R,pin);
					/*Open drain mode*/
					SET_BIT(GPIO_PORTA_ODR_R,pin);
					break;
				case GPIO_DIRECTION_OUTPUT :
					SET_BIT(GPIO_PORTA_DIR_R,pin);
					break;
				default : /*Do Nothing */ break;
			};
			/*Enable as digital I/O*/
			SET_BIT(GPIO_PORTA_DEN_R,pin);
			break;
		case GPIO_PORTB:

			switch(direction)
			{
				case GPIO_DIRECTION_INPUT_PUSH_PULL:
					CLR_BIT(GPIO_PORTB_DIR_R,pin);
					/*Pull up resistor*/
					SET_BIT(GPIO_PORTB_PUR_R,pin);
					break;
				case GPIO_DIRECTION_INPUT_FLOAT:
					CLR_BIT(GPIO_PORTB_DIR_R,pin);
					/*Open drain mode*/
					SET_BIT(GPIO_PORTB_ODR_R,pin);
					break;
				case GPIO_DIRECTION_OUTPUT :
					SET_BIT(GPIO_PORTB_DIR_R,pin);
					break;
				default : /*Do Nothing */ break;
			};
			/*Enable as digital I/O*/
			SET_BIT(GPIO_PORTB_DEN_R,pin);
			break;

		case GPIO_PORTC:

			switch(direction)
			{
				case GPIO_DIRECTION_INPUT_PUSH_PULL:
					CLR_BIT(GPIO_PORTC_DIR_R,pin);
					/*Pull up resistor*/
					SET_BIT(GPIO_PORTC_PUR_R,pin);
					break;
				case GPIO_DIRECTION_INPUT_FLOAT:
					CLR_BIT(GPIO_PORTC_DIR_R,pin);
					/*Open drain mode*/
					SET_BIT(GPIO_PORTC_ODR_R,pin);
					break;
				case GPIO_DIRECTION_OUTPUT :
					SET_BIT(GPIO_PORTC_DIR_R,pin);
					break;
				default : /*Do Nothing */ break;
			};
			/*Enable as digital I/O*/
			SET_BIT(GPIO_PORTC_DEN_R,pin);
			break;

		case GPIO_PORTD:

			switch(direction)
			{
				case GPIO_DIRECTION_INPUT_PUSH_PULL:
					CLR_BIT(GPIO_PORTD_DIR_R,pin);
					/*Pull up resistor*/
					SET_BIT(GPIO_PORTD_PUR_R,pin);
					break;
				case GPIO_DIRECTION_INPUT_FLOAT:
					CLR_BIT(GPIO_PORTD_DIR_R,pin);
					/*Open drain mode*/
					SET_BIT(GPIO_PORTD_ODR_R,pin);
					break;
				case GPIO_DIRECTION_OUTPUT :
					SET_BIT(GPIO_PORTD_DIR_R,pin);
					break;
				default : /*Do Nothing */ break;
			};
			/*Enable as digital I/O*/
			SET_BIT(GPIO_PORTD_DEN_R,pin);
			break;

		case GPIO_PORTE:

			switch(direction)
			{
				case GPIO_DIRECTION_INPUT_PUSH_PULL:
					CLR_BIT(GPIO_PORTE_DIR_R,pin);
					/*Pull up resistor*/
					SET_BIT(GPIO_PORTE_PUR_R,pin);
					break;
				case GPIO_DIRECTION_INPUT_FLOAT:
					CLR_BIT(GPIO_PORTE_DIR_R,pin);
					/*Open drain mode*/
					SET_BIT(GPIO_PORTE_ODR_R,pin);
					break;
				case GPIO_DIRECTION_OUTPUT :
					SET_BIT(GPIO_PORTE_DIR_R,pin);
					break;
				default : /*Do Nothing */ break;
			};
			/*Enable as digital I/O*/
			SET_BIT(GPIO_PORTE_DEN_R,pin);
			break;

		case GPIO_PORTF:

			switch(direction)
			{
				case GPIO_DIRECTION_INPUT_PUSH_PULL:
					CLR_BIT(GPIO_PORTF_DIR_R,pin);
					/*Pull up resistor*/
					SET_BIT(GPIO_PORTF_PUR_R,pin);
					break;
				case GPIO_DIRECTION_INPUT_FLOAT:
					CLR_BIT(GPIO_PORTF_DIR_R,pin);
					/*Open drain mode*/
					SET_BIT(GPIO_PORTF_ODR_R,pin);
					break;
				case GPIO_DIRECTION_OUTPUT :
					SET_BIT(GPIO_PORTF_DIR_R,pin);
					break;
				default : /*Do Nothing */ break;
			};
			/*Enable as digital I/O*/
			SET_BIT(GPIO_PORTF_DEN_R,pin);
			break;	


		default: /*Do Nothing */ break;	
	};

}

void GPIO_SetPinState(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_State_t state)
{
	switch (port)
	{
	case GPIO_PORTA:
		switch(state)
		{
			case GPIO_STATE_HIGH:
				SET_BIT(GPIO_PORTA_DATA_R,pin);
				break;
			case GPIO_STATE_LOW:
				CLR_BIT(GPIO_PORTA_DATA_R,pin);
				break;
			default : /*Do Nothing */ break;
		};
		break;
	case GPIO_PORTB:	
		switch(state)
		{
			case GPIO_STATE_HIGH:
				SET_BIT(GPIO_PORTB_DATA_R,pin);
				break;
			case GPIO_STATE_LOW:
				CLR_BIT(GPIO_PORTB_DATA_R,pin);
				break;
			default : /*Do Nothing */ break;
		};
		break;
	case GPIO_PORTC:	
		switch(state)
		{
			case GPIO_STATE_HIGH:
				SET_BIT(GPIO_PORTC_DATA_R,pin);
				break;
			case GPIO_STATE_LOW:
				CLR_BIT(GPIO_PORTC_DATA_R,pin);
				break;
			default : /*Do Nothing */ break;
		};
		break;
	case GPIO_PORTD:	
		switch(state)
		{
			case GPIO_STATE_HIGH:
				SET_BIT(GPIO_PORTD_DATA_R,pin);
				break;
			case GPIO_STATE_LOW:
				CLR_BIT(GPIO_PORTD_DATA_R,pin);
				break;
			default : /*Do Nothing */ break;
		};
		break;
	case GPIO_PORTE:	
		switch(state)
		{
			case GPIO_STATE_HIGH:
				SET_BIT(GPIO_PORTE_DATA_R,pin);
				break;
			case GPIO_STATE_LOW:
				CLR_BIT(GPIO_PORTE_DATA_R,pin);
				break;
			default : /*Do Nothing */ break;
		};
		break;
	case GPIO_PORTF:	
		switch(state)
		{
			case GPIO_STATE_HIGH:
				SET_BIT(GPIO_PORTF_DATA_R,pin);
				break;
			case GPIO_STATE_LOW:
				CLR_BIT(GPIO_PORTF_DATA_R,pin);
				break;
			default : /*Do Nothing */ break;
		};
		break;
	
	default:  /*Do Nothing */ break;	
	};
}


GPIO_State_t GPIO_GetPinState(GPIO_PORT_t port,GPIO_PIN_t pin)
{
	uint08_t ReadPinValue;
	switch (port)
	{
		case GPIO_PORTA:
			ReadPinValue = GET_BIT(GPIO_PORTA_DATA_R,pin);
			break;

		case GPIO_PORTB:
			ReadPinValue = GET_BIT(GPIO_PORTB_DATA_R,pin);
			break;
			
		case GPIO_PORTC:
			ReadPinValue = GET_BIT(GPIO_PORTC_DATA_R,pin);
			break;

		case GPIO_PORTD:
			ReadPinValue = GET_BIT(GPIO_PORTD_DATA_R,pin);
			break;	

		case GPIO_PORTE:
			ReadPinValue = GET_BIT(GPIO_PORTE_DATA_R,pin);
			break;

		case GPIO_PORTF:
			ReadPinValue = GET_BIT(GPIO_PORTF_DATA_R,pin);
			break;				
		default:
			break;

	}
	
	return ReadPinValue;

}
