#include "Timer.h"
#include "OS.h"


void Timer_Init(void)
{
    /* init systick timer */
}

void Timer_Update(void) /* ISR every 1 second */ 
{
    OS_IncreamentTick();
}