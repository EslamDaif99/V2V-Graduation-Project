#include "SysTick.h"
#include "OS.h"
#include "tm4c123gh6pm.h"
#include "Type.h"

static void inline enable_irq(void);

static void inline enable_irq(void)
{
    __asm  ("    CPSIE  I\n");
}

void SysTick_Init(void)
{
    /* Configure SysTick */
    NVIC_ST_CTRL_R = 0;              /* Disable timer*/
    NVIC_ST_RELOAD_R = 15999;  	/* reload with number of clocks per second */ /* [Galal : The initial number is updated to be 1 MS ] */
    NVIC_ST_CTRL_R = 7;             /* enable SysTick interrupt, use system clock */
    NVIC_ST_CURRENT_R	=0;	    /*Clear Current value*/
    enable_irq();                   /* global enable interrupt */
}

void SysTick_Handler(void)
{
	SysTick_Update();
}

void SysTick_Update(void) /* ISR every 1 second */
{
    OS_IncreamentTick();
}
