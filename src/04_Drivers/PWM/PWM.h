#ifndef _PWM_H_
#define	_PWM_H_

#include "Type.h"


typedef enum
{
    M0PWM,
    M1PWM

}PWM_Module;


typedef enum
{ 
  PWM0,
	PWM1,
	PWM2,
  PWM3,
	PWM4,
	PWM5,
	PWM6,
	PWM7
	
}PWM_Number;


typedef enum
{
  Generator_0,
	Generator_1,
	Generator_2,
	Generator_3,
	
}PWM_Generator;


typedef enum
{
  Control_0,
	Control_1,
	Control_2,
	Control_3,
	
}PWM_Control;


typedef enum
{ 
	Count_UP,
	Count_DOWN,
}PWM_Mode;


typedef enum 
{
    PWM_SYSCLK_DIV_2,
    PWM_SYSCLK_DIV_4,
    PWM_SYSCLK_DIV_8,
    PWM_SYSCLK_DIV_16,
    PWM_SYSCLK_DIV_32,
    PWM_SYSCLK_DIV_64
    
}PWM_SYSCLK_DIV;


typedef enum{

    Do_nothing,    
    Invert_pwmA,   
    Drive_pwmA_Low,
    Drive_pwmA_High,

}PWM_comparator_Action;



void PWMClockSet(PWM_Module module,PWM_Number number);                                                                            
void PWMDiv(PWM_SYSCLK_DIV div);
void PWMPinConfigure(PWM_Module module,PWM_Number number);  

void PWMGenDisable(PWM_Module module, PWM_Generator generator, PWM_Number number);

void PWMGenConfigure(PWM_Module module, PWM_Mode mode, PWM_Number number);                                      

         
void PWMGenPeriodSet(PWM_Module module, PWM_Generator generator, PWM_SYSCLK_DIV div, uint32_t Clock_Required);   
void PWMDutyCycleSet(PWM_Module module, PWM_Number number, PWM_Mode mode, uint32_t duty_cycle);                  

void PWMGenEnable(PWM_Module module, PWM_Generator generator, PWM_Number number);



#endif
