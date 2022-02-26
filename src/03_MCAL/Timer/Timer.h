#ifndef _TIMER_H_
#define _TIMER_H_

static void inline enable_irq(void);
void Timer_Init(void);
void Timer_Update(void);
void SysTick_Handler(void);

#endif
