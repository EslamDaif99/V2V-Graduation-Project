#include "Timer.h"
#include "OS.h"
#include "tm4c123gh6pm.h"

static void inline enable_irq(void)
{
    __asm  ("    CPSIE  I\n");
}

void Timer_Init(void)
{
    /* Configure SysTick */
    NVIC_ST_RELOAD_R = 16000000-1;  /* reload with number of clocks per second */
    NVIC_ST_CTRL_R = 7;             /* enable SysTick interrupt, use system clock */

    enable_irq();                   /* global enable interrupt */
}

void SysTick_Handler(void)
{
    Timer_Update();
}

void Timer_Update(void) /* ISR every 1 second */
{
    OS_IncreamentTick();
}