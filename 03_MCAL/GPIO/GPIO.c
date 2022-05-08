#include "config.h"
#include "Type.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"

#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

#endif

void GPIO_Init(GPIO_PORT_t port,GPIO_PIN_t pin)
{
#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

	volatile uint32_t delay;

	if(port == GPIO_PORTA)
		{
			/*Enable clock*/
			SET_BIT(SYSCTL_RCGCGPIO_R,port);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Unlock PORTA */
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			/*Ensure the control register*/
			SET_BIT(GPIO_PORTA_CR_R,pin);
			/*Disable alternative functions*/
			GPIO_PORTA_AFSEL_R = 0x00;
			/*Disable Analog Mode*/
			GPIO_PORTA_AMSEL_R = 0x00;
		}
	else if(port == GPIO_PORTB)
		{
			/*Enable clock*/
			SET_BIT(SYSCTL_RCGCGPIO_R,port);
			/*Wait to ensure that clock had been enabled*/
			delay = 1;
			/*Unlock PORTB */
			GPIO_PORTB_LOCK_R= 0x4C4F434B;
			/*Ensure the control register*/
			SET_BIT(GPIO_PORTB_CR_R,pin);
			/*Disable alternative functions*/
			GPIO_PORTB_AFSEL_R = 0x00;
			/*Disable Analog Mode*/
			GPIO_PORTB_AMSEL_R = 0x00;
		}
	else if(port == GPIO_PORTC)
		{
			/*Enable clock*/
			SET_BIT(SYSCTL_RCGCGPIO_R,port);
			/*Wait to ensure that clock had been enabled*/
			delay = 1;
			/*Unlock PORTC */
			GPIO_PORTC_LOCK_R= 0x4C4F434B;
			/*Ensure the control register*/
			SET_BIT(GPIO_PORTC_CR_R,pin);
			/*Disable alternative functions*/
			GPIO_PORTC_AFSEL_R = 0x00;
			/*Disable Analog Mode*/
			GPIO_PORTC_AMSEL_R = 0x00;
		}
	else if(port == GPIO_PORTD)
		{
			/*Enable clock*/
			SET_BIT(SYSCTL_RCGCGPIO_R,port);
			/*Wait to ensure that clock had been enabled*/
			delay = 1;
			/*Unlock PORTD */
			GPIO_PORTD_LOCK_R= 0x4C4F434B;
			/*Ensure the control register*/
			SET_BIT(GPIO_PORTD_CR_R,pin);
			/*Disable alternative functions*/
			GPIO_PORTD_AFSEL_R = 0x00;
			/*Disable Analog Mode*/
			GPIO_PORTD_AMSEL_R = 0x00;
		}
	else if(port == GPIO_PORTE)
		{
			/*Enable clock*/
			SET_BIT(SYSCTL_RCGCGPIO_R,port);
			/*Wait to ensure that clock had been enabled*/
			delay = 1;
			/*Unlock PORTE */
			GPIO_PORTE_LOCK_R= 0x4C4F434B;
			/*Ensure the control register*/
			SET_BIT(GPIO_PORTE_CR_R,pin);
			/*Disable alternative functions*/
			GPIO_PORTE_AFSEL_R = 0x00;
			/*Disable Analog Mode*/
			GPIO_PORTE_AMSEL_R = 0x00;
		}
	else if(port == GPIO_PORTF)
		{
			/*Enable clock*/
			SET_BIT(SYSCTL_RCGCGPIO_R,port);
			/*Wait to ensure that clock had been enabled*/
			delay = 1;
			/*Unlock PORTF */
			GPIO_PORTF_LOCK_R= 0x4C4F434B;
			/*Ensure the control register*/
			SET_BIT(GPIO_PORTF_CR_R,pin);
			/*Disable alternative functions*/
			GPIO_PORTF_AFSEL_R = 0x00;
			/*Disable Analog Mode*/
			GPIO_PORTF_AMSEL_R = 0x00;
		}
	else
		{ /*Do nothing*/
		}

#endif
}


void GPIO_SetPinDirection(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_Direction_t direction)
{
#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

	if (port == GPIO_PORTA)
		{
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
			/*Enable Digital I/O*/
			SET_BIT(GPIO_PORTA_DEN_R,pin);
		}
	else if (port == GPIO_PORTB)
		{
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
			/*Enable Digital I/O*/
			SET_BIT(GPIO_PORTB_DEN_R,pin);
		}
	else if (port == GPIO_PORTC)
		{
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
			/*Enable Digital I/O*/
			SET_BIT(GPIO_PORTC_DEN_R,pin);
		}
	else if (port == GPIO_PORTD)
		{
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
			/*Enable Digital I/O*/
			SET_BIT(GPIO_PORTD_DEN_R,pin);
		}
	else if (port == GPIO_PORTE)
		{
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
			/*Enable Digital I/O*/
			SET_BIT(GPIO_PORTE_DEN_R,pin);
		}
	else if (port == GPIO_PORTF)
		{
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
			/*Enable Digital I/O*/
			SET_BIT(GPIO_PORTF_DEN_R,pin);
		}
	else
		{ /*Do nothing*/
		}

#endif
}

void GPIO_SetPinState(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_State_t state)
{
#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

	if (port == GPIO_PORTA)
		{
			switch(state)
			{
				case GPIO_STATE_HIGH:  SET_BIT(GPIO_PORTA_DATA_R,pin);  break;
				case GPIO_STATE_LOW:   CLR_BIT(GPIO_PORTA_DATA_R,pin);  break;
				default : /*Do Nothing */ break;
			};
		}
	else if(port == GPIO_PORTB)
		{
			switch(state)
			{
				case GPIO_STATE_HIGH:  SET_BIT(GPIO_PORTB_DATA_R,pin);  break;
				case GPIO_STATE_LOW:   CLR_BIT(GPIO_PORTB_DATA_R,pin);  break;
				default : /*Do Nothing */ break;
			};
		}
	else if(port == GPIO_PORTC)
		{
			switch(state)
			{
				case GPIO_STATE_HIGH:  SET_BIT(GPIO_PORTC_DATA_R,pin);  break;
				case GPIO_STATE_LOW:   CLR_BIT(GPIO_PORTC_DATA_R,pin);  break;
				default : /*Do Nothing */ break;
			};
		}
	else if(port == GPIO_PORTD)
		{
			switch(state)
			{
				case GPIO_STATE_HIGH:  SET_BIT(GPIO_PORTD_DATA_R,pin);  break;
				case GPIO_STATE_LOW:   CLR_BIT(GPIO_PORTD_DATA_R,pin);  break;
				default : /*Do Nothing */ break;
			};
		}
	else if(port == GPIO_PORTE)
		{
			switch(state)
			{
				case GPIO_STATE_HIGH:  SET_BIT(GPIO_PORTE_DATA_R,pin);  break;
				case GPIO_STATE_LOW:   CLR_BIT(GPIO_PORTE_DATA_R,pin);  break;
				default : /*Do Nothing */ break;
			};
		}
	else if(port == GPIO_PORTF)
		{
			switch(state)
			{
				case GPIO_STATE_HIGH:  SET_BIT(GPIO_PORTF_DATA_R,pin);  break;
				case GPIO_STATE_LOW:   CLR_BIT(GPIO_PORTF_DATA_R,pin);  break;
				default : /*Do Nothing */ break;
			};
		}
	else
		{ /*Do nothing*/
		}

#endif
}

GPIO_State_t GPIO_GetPinState(GPIO_PORT_t port,GPIO_PIN_t pin)
	{
#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

		uint08_t ReadPinValue = 0;

		if(port == GPIO_PORTA)
			{
				ReadPinValue = GET_BIT(GPIO_PORTA_DATA_R,pin);
				return ReadPinValue;
			}
		else if(port == GPIO_PORTB)
			{
				ReadPinValue = GET_BIT(GPIO_PORTB_DATA_R,pin);
				return ReadPinValue;
			}
		else if(port == GPIO_PORTC)
			{
				ReadPinValue = GET_BIT(GPIO_PORTC_DATA_R,pin);
				return ReadPinValue;
			}
		else if(port == GPIO_PORTD)
			{
				ReadPinValue = GET_BIT(GPIO_PORTD_DATA_R,pin);
				return ReadPinValue;
			}
		else if(port == GPIO_PORTE)
			{
				ReadPinValue = GET_BIT(GPIO_PORTE_DATA_R,pin);
				return ReadPinValue;
			}
		else if(port == GPIO_PORTF)
			{
				ReadPinValue = GET_BIT(GPIO_PORTF_DATA_R,pin);
				return ReadPinValue;
			}
		else
		   {
			   /*DO NOTHING*/
				return ReadPinValue;
		   }

#endif
}

void GPIO_SetPortDirection(GPIO_PORT_t port,GPIO_Direction_t direction)
{
#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

	if(port == GPIO_PORTA)
		{
			switch(direction)
					{
					case GPIO_DIRECTION_OUTPUT:
						GPIO_PORTA_DIR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_PUSH_PULL:
						GPIO_PORTA_DIR_R = 0x00;
						/*Pull up mode*/
						GPIO_PORTA_PUR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_FLOAT:
						GPIO_PORTA_DIR_R = 0x00;
						/*Open drain mode*/
						GPIO_PORTA_ODR_R = 0xff;
						break;
					default : /*Do Nothing */ break;
					};
			/*Enable Digital I/O*/
			GPIO_PORTA_DEN_R = 0xff;
		}
	else if(port == GPIO_PORTB)
		{
			switch(direction)
					{
					case GPIO_DIRECTION_OUTPUT:
						GPIO_PORTB_DIR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_PUSH_PULL:
						GPIO_PORTB_DIR_R = 0x00;
						/*Pull up mode*/
						GPIO_PORTB_PUR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_FLOAT:
						GPIO_PORTB_DIR_R = 0x00;
						/*Open drain mode*/
						GPIO_PORTB_ODR_R = 0xff;
						break;
					default : /*Do Nothing */ break;
					};
			/*Enable Digital I/O*/
			GPIO_PORTB_DEN_R = 0xff;
		}
	else if(port == GPIO_PORTC)
		{
			switch(direction)
					{
					case GPIO_DIRECTION_OUTPUT:
						GPIO_PORTC_DIR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_PUSH_PULL:
						GPIO_PORTC_DIR_R = 0x00;
						/*Pull up mode*/
						GPIO_PORTC_PUR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_FLOAT:
						GPIO_PORTC_DIR_R = 0x00;
						/*Open drain mode*/
						GPIO_PORTC_ODR_R = 0xff;
						break;
					default : /*Do Nothing */ break;
					};
			/*Enable Digital I/O*/
			GPIO_PORTC_DEN_R = 0xff;
		}
	else if(port == GPIO_PORTD)
		{
			switch(direction)
					{
					case GPIO_DIRECTION_OUTPUT:
						GPIO_PORTD_DIR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_PUSH_PULL:
						GPIO_PORTD_DIR_R = 0x00;
						/*Pull up mode*/
						GPIO_PORTD_PUR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_FLOAT:
						GPIO_PORTD_DIR_R = 0x00;
						/*Open drain mode*/
						GPIO_PORTD_ODR_R = 0xff;
						break;
					default : /*Do Nothing */ break;
					};
			/*Enable Digital I/O*/
			GPIO_PORTD_DEN_R = 0xff;
		}
	else if(port == GPIO_PORTE)
		{
			switch(direction)
					{
					case GPIO_DIRECTION_OUTPUT:
						GPIO_PORTE_DIR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_PUSH_PULL:
						GPIO_PORTE_DIR_R = 0x00;
						/*Pull up mode*/
						GPIO_PORTE_PUR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_FLOAT:
						GPIO_PORTE_DIR_R = 0x00;
						/*Open drain mode*/
						GPIO_PORTE_ODR_R = 0xff;
						break;
					default : /*Do Nothing */ break;
					};
			/*Enable Digital I/O*/
			GPIO_PORTE_DEN_R = 0xff;
		}
	else if(port == GPIO_PORTF)
		{
			switch(direction)
					{
					case GPIO_DIRECTION_OUTPUT:
						GPIO_PORTF_DIR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_PUSH_PULL:
						GPIO_PORTF_DIR_R = 0x00;
						/*Pull up mode*/
						GPIO_PORTF_PUR_R = 0xff;
						break;
					case GPIO_DIRECTION_INPUT_FLOAT:
						GPIO_PORTF_DIR_R = 0x00;
						/*Open drain mode*/
						GPIO_PORTF_ODR_R = 0xff;
						break;
					default : /*Do Nothing */ break;
					};
			/*Enable Digital I/O*/
			GPIO_PORTF_DEN_R = 0xff;
		}
	else
		{ /*Do nothing*/
		}

#endif
}

void GPIO_SetPortState(GPIO_PORT_t port,uint08_t state)
{
#if (GPIO_SWC_STATUS == SWC_STATUS_ENABLE)

	if (port == GPIO_PORTA)
	{
		GPIO_PORTA_DATA_R = state;
	}
	else if (port == GPIO_PORTB)
	{
	    GPIO_PORTB_DATA_R = state;
	}
	else if (port == GPIO_PORTC)
	{
	    GPIO_PORTC_DATA_R = state;
	}
	else if (port == GPIO_PORTD)
	{
        GPIO_PORTD_DATA_R = state;
	}
	else if (port == GPIO_PORTE)
	{
        GPIO_PORTE_DATA_R = state;
	}
	else if (port == GPIO_PORTF)
	{
        GPIO_PORTF_DATA_R = state;
	}

#endif
}
uint08_t GPIO_readPort(GPIO_PORT_t port){

    uint08_t returned_value =0 ;

        /*write port direction*/
        switch(port){
        case GPIO_PORTA :
            returned_value =GPIO_PORTA_DATA_R ; break ;
        case GPIO_PORTB :
            returned_value =GPIO_PORTB_DATA_R ; break ;
        case GPIO_PORTC :
            returned_value =GPIO_PORTC_DATA_R ; break ;
        case GPIO_PORTD :
            returned_value =GPIO_PORTD_DATA_R ; break ;
        case GPIO_PORTE :
            returned_value =GPIO_PORTE_DATA_R ; break ;
        case GPIO_PORTF :
            returned_value =GPIO_PORTF_DATA_R ; break ;

    }
    return returned_value;
}
