#include "Type.h"
#include "BITMATH.h"
#include "INTPin.h"
#include "Speed.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"

extern uint16_t Counts;
void SpeedInit(void)
{
	SpeedPinConfig(SpeedAction);
	EnableSpeedInt();
}
void SpeedAction(void)
{
	Counts++;
	/*For check*/
	GPIO_Init(GPIO_PORTD,GPIO_PIN_1);
	GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_1,GPIO_DIRECTION_OUTPUT);
	GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_1,GPIO_STATE_HIGH);
	/*Clear Flag*/
	SET_BIT(GPIO_PORTD_ICR_R,0);
}
