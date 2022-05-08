#include "config.h"
#include "Motor.h"
#include "GPIO.h"
#include "Port.h"
#include "Type.h"
#include "PWM.h"

#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

#endif

void Motor_Init(void)
{
#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

	/*****PWM_MOTOR_1****PORTF***PIN0*****/
	 PWMClockSet(M1PWM,PWM4);	
	 PWMDiv(PWM_SYSCLK_DIV_64);
	 PWMPinConfigure(M1PWM,PWM4);
	 PWMGenDisable(M1PWM,PWM4);                                                                    
	 PWMGenConfigure(M1PWM,Count_DOWN, PWM4);                                           
	 PWMGenPeriodSet(M1PWM,PWM4,PWM_SYSCLK_DIV_64,50); 	   
	 PWMDutyCycleSet(M1PWM,PWM4,Count_DOWN,75);
	 PWMGenEnable(M1PWM,PWM4);


	/*****PWM_MOTOR_2****PORTF***PIN1*****/
	 PWMClockSet(M1PWM,PWM5);	
	 PWMDiv(PWM_SYSCLK_DIV_64);
	 PWMPinConfigure(M1PWM,PWM5);
	 PWMGenDisable(M1PWM,PWM5);                                                                    
	 PWMGenConfigure(M1PWM,Count_DOWN, PWM5);                                            
	 PWMGenPeriodSet(M1PWM,PWM5,PWM_SYSCLK_DIV_64,50); 	   
	 PWMDutyCycleSet(M1PWM,PWM5,Count_DOWN,75);
	 PWMGenEnable(M1PWM,PWM5);

	/*****PWM_Motor_3***PORTF***PIN2*******/

	 PWMClockSet(M1PWM,PWM6);	
	 PWMDiv(PWM_SYSCLK_DIV_64);
	 PWMPinConfigure(M1PWM,PWM6);
	 PWMGenDisable(M1PWM,PWM6);                                                                    
	 PWMGenConfigure(M1PWM,Count_DOWN, PWM6);                                           
	 PWMGenPeriodSet(M1PWM,PWM6,PWM_SYSCLK_DIV_64,50); 	   
	 PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,75);
	 PWMGenEnable(M1PWM,PWM6);
	

	/*****PWM_Motor_4***PORTF***PIN3*******/
	 PWMClockSet(M1PWM,PWM7);	
	 PWMDiv(PWM_SYSCLK_DIV_64);
	 PWMPinConfigure(M1PWM,PWM7);
	 PWMGenDisable(M1PWM,PWM7);                                                                    
	 PWMGenConfigure(M1PWM,Count_DOWN, PWM7);                                          
	 PWMGenPeriodSet(M1PWM,PWM7,PWM_SYSCLK_DIV_64,50); 	   
	 PWMDutyCycleSet(M1PWM,PWM7,Count_DOWN,75);
	 PWMGenEnable(M1PWM,PWM7);


    /********MOTOR_1*******/
	
	 GPIO_Init(MOTOR_1_PORT);
	 GPIO_Init(MOTOR_1_PORT);
	 GPIO_SetPinDirection(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_DIRECTION_OUTPUT);
	 GPIO_SetPinDirection(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_DIRECTION_OUTPUT);
	

	 GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
	 GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);
	
	/************Motor_2********/

	GPIO_Init(MOTOR_2_PORT);
	GPIO_Init(MOTOR_2_PORT);
    GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_DIRECTION_OUTPUT);
	GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_DIRECTION_OUTPUT);


	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

	/************Motor_3********/

    GPIO_Init(MOTOR_3_PORT);
    GPIO_Init(MOTOR_3_PORT);
    GPIO_SetPinDirection(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_DIRECTION_OUTPUT);
	GPIO_SetPinDirection(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_DIRECTION_OUTPUT);


	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_LOW);
	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);

	/************Motor_4********/

    GPIO_Init(MOTOR_4_PORT);
    GPIO_Init(MOTOR_4_PORT);
    GPIO_SetPinDirection(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_DIRECTION_OUTPUT);
	GPIO_SetPinDirection(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_DIRECTION_OUTPUT);


	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_LOW);
	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);
//	Motor_Start();
  Motor_GoForward();

#endif
}

void Motor_Update(void)
{
#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

#endif
}

void Motor_Start(void)
{
#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

	 /*Enable Motor_1*/
	 PWMGenEnable(M1PWM,PWM4);	
	 /*Enable Motor_2*/
	 PWMGenEnable(M1PWM,PWM5);	
	 /*Enable Motor_3*/
	 PWMGenEnable(M1PWM,PWM6);
	 /*Enable Motor_4*/
	 PWMGenEnable(M1PWM,PWM7);	 

#endif
}

void Motor_Stop(void)
{
#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

  /*Disable Motor_1*/
  PWMGenDisable(M1PWM,PWM4);
  /*Disable Motor_2*/
  PWMGenDisable(M1PWM,PWM5);
  /*Disable Motor_3*/
  PWMGenDisable(M1PWM,PWM6);
  /*Disable Motor_4*/
  PWMGenDisable(M1PWM,PWM7);

#endif
}

void Motor_GoForward(void)
{
#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

    /************Motor_1********/
	
	GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
	GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);
	
	/************Motor_2********/

	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
	GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

	/************Motor_3********/

	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_HIGH);
	GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);

	/************Motor_4********/

	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_HIGH);
	GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);

#endif
}

void Motor_SetSpeed(Motor_Speed_t speed)
{
#if (MOTOR_SWC_STATUS == SWC_STATUS_ENABLE)

	if (speed == MOTOR_SPEED_LOW)
	{	
		PWMDutyCycleSet(M1PWM,PWM4,Count_DOWN,25);
		PWMDutyCycleSet(M1PWM,PWM5,Count_DOWN,25);
		PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,25);
		PWMDutyCycleSet(M1PWM,PWM7,Count_DOWN,25);
		
	}
	else if (speed == MOTOR_SPEED_MID)
    {
	 
	 	PWMDutyCycleSet(M1PWM,PWM4,Count_DOWN,50);
		PWMDutyCycleSet(M1PWM,PWM5,Count_DOWN,50);
		PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,50);
		PWMDutyCycleSet(M1PWM,PWM7,Count_DOWN,50);
	}
	else if (speed == MOTOR_SPEED_HIGH)
    {
		PWMDutyCycleSet(M1PWM,PWM4,Count_DOWN,75);
		PWMDutyCycleSet(M1PWM,PWM5,Count_DOWN,75);
		PWMDutyCycleSet(M1PWM,PWM6,Count_DOWN,75);
		PWMDutyCycleSet(M1PWM,PWM7,Count_DOWN,75);
	}
	else
    {/*Do no thing*/}	
	
#endif	  
}
