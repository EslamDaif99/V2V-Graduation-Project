#include "Motor.h"
#include "GPIO.h"
#include "Port.h"
#include "Type.h"
#include "PWM.h"


void Motor_Init(void)
{
	/***********Motor_1**************/

	 PWMClockSet(M1PWM,PWM6);	
	 PWMDiv(PWM_SYSCLK_DIV_64);
	 PWMPinConfigure(M1PWM,PWM6); 
	
    	
	 
#if 1
	
	 PWMGenDisable(M1PWM,Generator_3,PWM6);                                                                    
	 PWMGenConfigure(M1PWM,Count_DOWN, PWM6);                                             
	 PWMGenPeriodSet(M1PWM,Generator_3,PWM_SYSCLK_DIV_64,50);   
	 PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,75);
	 PWMGenEnable(M1PWM,Generator_3, PWM6);
	
#endif
	
	 GPIO_Init(MOTOR_1_PORT,MOTOR_1_IN1);
	 GPIO_Init(MOTOR_1_PORT,MOTOR_1_IN2);
	 GPIO_SetPinDirection(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_DIRECTION_OUTPUT);
	 GPIO_SetPinDirection(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_DIRECTION_OUTPUT);
	

	 GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
	 GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);
	
	/************Motor_2********/
	//GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_ENABLE,GPIO_DIRECTION_OUTPUT);
//  GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_DIRECTION_OUTPUT);
//	GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_DIRECTION_OUTPUT);
//	
//	//GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_ENABLE,GPIO_STATE_LOW);
//	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
//	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

//	/************Motor_3********/
//	//GPIO_SetPinDirection(MOTOR_3_PORT,MOTOR_3_ENABLE,GPIO_DIRECTION_OUTPUT);
//    GPIO_SetPinDirection(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_DIRECTION_OUTPUT);
//	GPIO_SetPinDirection(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_DIRECTION_OUTPUT);
//	
//	//GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_ENABLE,GPIO_STATE_LOW);
//	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_LOW);
//	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);

//	/************Motor_4********/
//	//GPIO_SetPinDirection(MOTOR_4_PORT,MOTOR_4_ENABLE,GPIO_DIRECTION_OUTPUT);
//    GPIO_SetPinDirection(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_DIRECTION_OUTPUT);
//	GPIO_SetPinDirection(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_DIRECTION_OUTPUT);
//	
//	//GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_ENABLE,GPIO_STATE_LOW);
//	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_LOW);
//	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);
//	Motor_Start();
  Motor_GoForward();
}

void Motor_Update(void)
{


}

void Motor_Start(void)
{
	 /*Enable Motor_1*/
	 PWMGenEnable(M1PWM,Generator_3, PWM6);
}

void Motor_Stop(void)
{
	/*Disable Motor_1*/
  PWMGenDisable(M1PWM,Generator_3, PWM6);
}

void Motor_GoForward(void)
{
    /************Motor_1********/
	
	GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
	GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);
	
//	/************Motor_2********/

//	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
//	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);
//	
//	/************Motor_3********/

//	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_HIGH);
//	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);
//	
//	/************Motor_4********/

//	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_HIGH);
//	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);
}

void Motor_SetSpeed(Motor_Speed_t speed)
{
	if (speed == MOTOR_SPEED_LOW)
	{
		PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,25);
	}
	else if (speed == MOTOR_SPEED_MID)
  {
	 PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,50);
	}
	else if (speed == MOTOR_SPEED_HIGH)
  {
		PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,75);
	}
	else
  {/*Do no thing*/}	
	  
}
