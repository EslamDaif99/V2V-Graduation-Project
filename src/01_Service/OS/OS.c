#include "OS.h"
#include "GPIO.h"
#include "LED.h"
#include "Type.h"
#include "Timer.h"
#include "Port.h"
#include "Motor.h"

static uint08_t OS_Tick;

void OS_Init(void)
{
	OS_Tick = 0;

	
//	GPIO_Init(MOTOR_1_PORT,MOTOR_1_ENABLE);
//	GPIO_Init(MOTOR_2_PORT,MOTOR_2_ENABLE);
//	GPIO_Init(MOTOR_3_PORT,MOTOR_3_ENABLE);
//	GPIO_Init(MOTOR_4_PORT,MOTOR_4_ENABLE);
	
	GPIO_Init(MOTOR_1_PORT,MOTOR_1_IN1);
	GPIO_Init(MOTOR_1_PORT,MOTOR_1_IN2);

//	GPIO_Init(MOTOR_2_PORT,MOTOR_2_IN1);
//	GPIO_Init(MOTOR_2_PORT,MOTOR_2_IN2);

//	GPIO_Init(MOTOR_3_PORT,MOTOR_3_IN1);
//	GPIO_Init(MOTOR_3_PORT,MOTOR_3_IN2);

//	GPIO_Init(MOTOR_4_PORT,MOTOR_4_IN1);
//	GPIO_Init(MOTOR_4_PORT,MOTOR_4_IN2);	
	
	
	Motor_Init();
	Motor_Start();
}

void OS_IncreamentTick(void)
{
	OS_Tick++;
}


void OS_Update(void)
{
	Motor_GoForward();

}
