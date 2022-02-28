#include <stdio.h>
#include <stdint.h>

#include "OS.h"
#include "GPIO.h"
#include "LED.h"
#include "Type.h"
#include "Timer.h"
#include "BITMATH.h"
#include "Port.h"

static uint08_t OS_Tick;

void OS_Init(void)
{
	OS_Tick = 0;

	GPIO_Init(PORT,LED_PIN_NUMBER);
	
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
