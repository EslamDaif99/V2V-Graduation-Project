
#include "Type.h"
#include "BITMATH.h"
#include "INTPin.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"

extern uint16_t Counts;

static void (*handler)(void);
void SpeedPinConfig(void(*func)(void))
{
	handler=func;
	/*Initiate PIN0 in PORTD*/
	GPIO_Init(GPIO_PORTD);
	GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_0,GPIO_DIRECTION_INPUT_PULL_DOWN);

    /*Mask Pin */
	CLR_BIT(GPIO_PORTD_IM_R,0);

    /* Edge*/
	CLR_BIT(GPIO_PORTD_IS_R,0);

    /* Single Edge*/
    CLR_BIT(GPIO_PORTD_IBE_R,0);

    /*Rising Edge*/
    SET_BIT(GPIO_PORTF_IEV_R,0);

    /*Enable Interrupt  (UnMask) */
	SET_BIT(GPIO_PORTD_IM_R,0);

}

void EnableSpeedInt(void)
{
	SET_BIT(NVIC_EN0_R,3);
}

void DisableSpeedInt(void)
{
	CLR_BIT(NVIC_EN0_R,3);
}

void GPIOPortD_Handler()
{
	handler();
}
