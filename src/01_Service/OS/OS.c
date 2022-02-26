#include "OS.h"
#include "GPIO.h"
#include "LED.h"
#include "Type.h"
#include "Timer.h"
static uint08_t OS_Tick;

void OS_Init(void)
{
	OS_Tick = 0;

	GPIO_Init(GPIO_PORTA,GPIO_PIN_0);
	
	LED_Init();

	/* OS Tick */
	Timer_Init();
}

void OS_IncreamentTick(void)
{
	OS_Tick++;
}

void OS_Update(void)
{
	if(OS_Tick != 0)
	{
		LED_Update();
		OS_Tick--;
	}
	else
	{
		/* Do Nothing */
	}	
	
}
