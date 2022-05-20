
#include "Type.h"
#include "BITMATH.h"
#include "Speed.h"
#include "INTPin.h"
#include "GPIO.h"
//#include "Lcd.h"
#include "tm4c123gh6pm.h"

uint16_t Counts;
uint16_t SpeedValue;
void Speed_Init(void)
{
    SpeedValue =0;
    SpeedPinConfig(SpeedAction);
    GPIO_Init(GPIO_PORTD,GPIO_PIN_1);
    GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_1,GPIO_DIRECTION_OUTPUT);
    GPIO_Init(GPIO_PORTD,GPIO_PIN_2);
    GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_2,GPIO_DIRECTION_OUTPUT);
    GPIO_Init(GPIO_PORTD,GPIO_PIN_3);
    GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_3,GPIO_DIRECTION_OUTPUT);
    EnableSpeedInt();

}
void SpeedAction(void)
{
    SET_BIT(GPIO_PORTD_ICR_R,0);
	Counts++;
    GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_1,GPIO_STATE_HIGH);
}

void Speed_Update(void)
{
    uint16_t Temp;
    DisableSpeedInt();
    Temp = Counts;
    if (Temp == 0)
    {
        GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,GPIO_STATE_HIGH);
    }
    else
    {

        GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,GPIO_STATE_LOW);
    }
  /*  else if (Temp == 500)
    {
        GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_3,GPIO_STATE_HIGH);
        GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,GPIO_STATE_LOW);
    }
    else if (Temp == 2)
    {
        GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,GPIO_STATE_HIGH);
    }
    else if (Temp == 3)
    {
        GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,GPIO_STATE_LOW);
    }*/
    //SpeedValue = ((2*3.14*.03)/20)*Counts;  //m/s
    SpeedValue = Counts;  //m/s

    /*LCD_displayStringRowColumn(0, 2, "no of count");
    LCD_moveCursorXY(1, 2);
    LCD_intgerToString(Temp);
    For check
    GPIO_Init(GPIO_PORTD,GPIO_PIN_0);
    GPIO_SetPinDirection(GPIO_PORTD,GPIO_PIN_1,GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_1,GPIO_STATE_HIGH);*/
    Counts =0;
    //GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_1,GPIO_STATE_LOW);
    EnableSpeedInt();
}
uint16_t  Speed_GetValue(void)
{
    return SpeedValue;
}
