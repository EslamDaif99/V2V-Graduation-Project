#include "config.h"
#include "Type.h"
#include "SysTick.h"
#include "GPIO.h"
#include "LED.h"
#include "Motor.h"
#include "UART.h"
#include "Port.h"
#include "OS.h"

#if (OS_SWC_STATUS == SWC_STATUS_ENABLE)

#define OS_MAX_TASK_COUNT					(0x0A)
#define OS_TICK_MS							(0x01)

#define LED_UPDATE_PERIODICITY_MS			(0x3E8) /* 1000 MS */
#define MOTOR_UPDATE_PERIODICITY_MS			(0x01) /* 1 MS */
#define UART_UPDATE_PERIODICITY_MS			(0x3E8) /* 1 MS */


typedef struct
{
	uint32_t periodicity_ms;
	uint64_t counter_ms;
	void (* process)(void);
}
OS_Task_t;

static OS_Task_t OS_TaskList[OS_MAX_TASK_COUNT];
static uint08_t OS_Tick;

#endif

void OS_Init(void)
{
#if (OS_SWC_STATUS == SWC_STATUS_ENABLE)

	uint32_t index;

	/* ************* Initialize OS Data ************* */

	OS_Tick = 0;

	index = 0;

	while(index < OS_MAX_TASK_COUNT)
	{
		OS_TaskList[index].counter_ms = 0;
		OS_TaskList[index].periodicity_ms = 0;
		OS_TaskList[index].process = NULL_PTR;

		index++;
	}

	/* ************* Add OS Tasks ************* */

	/* ************* OS Task 0x00 ************* */
	index = 0;
	OS_TaskList[index].periodicity_ms = LED_UPDATE_PERIODICITY_MS;
	OS_TaskList[index].process = LED_Update;
	index++;

	/* ************* OS Task 0x01 ************* */
	OS_TaskList[index].periodicity_ms = MOTOR_UPDATE_PERIODICITY_MS;
	OS_TaskList[index].process = Motor_Update;
	index++;

	/* ************* OS Task 0x01 ************* */
	OS_TaskList[index].periodicity_ms = UART_UPDATE_PERIODICITY_MS;
	OS_TaskList[index].process = UART_Update;
	index++;

	/* ************* SWC Initialization ************* */


	LED_Init();
	Motor_Init();
	UART_Init();

	SysTick_Init();

#endif
}

void OS_Update(void)
{
#if (OS_SWC_STATUS == SWC_STATUS_ENABLE)

	uint32_t index = 0;

	if(OS_Tick > 0)
	{
		while(index < OS_MAX_TASK_COUNT)
		{
			OS_Task_t * currentTask = &OS_TaskList[index];

			if(currentTask->process != NULL_PTR)
			{
				currentTask->counter_ms = currentTask->counter_ms + OS_TICK_MS;

				if(currentTask->counter_ms >= currentTask->periodicity_ms)
				{
					currentTask->process();
					currentTask->counter_ms = 0;
				}
				else
				{
					/* Do Nothing */
				}
			}

			index++;
		}

		OS_Tick--;
	}
	else
	{
		/* Do Nothing */
	}

#endif
}

void OS_IncreamentTick(void)
{
#if (OS_SWC_STATUS == SWC_STATUS_ENABLE)

	OS_Tick++;

#endif
}
