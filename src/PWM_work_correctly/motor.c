/*********
In this project we just try to use L298 motor driver with PWM
Author: Mariam
date: 18/2/2022
**************/
#include <stdint.h>
#include <stdio.h>
//#include "C:/Keil_v5/EE319KwareSpring2022/inc/tm4c123gh6pm.h"
#include "GPIO.h"
#include "PWM.h"
#include "MOTOR_DRIVER.h"


uint32_t duty_cycle=4999;
void PWM_init(void);
void Turn_oneDirection(void);
void Turn_OtherDirection(void);
void Delay_ms(int time_ms);


int main()
{
		PWM_init();
		Turn_oneDirection();
    /*while(1)
    {
        duty_cycle = duty_cycle - 10;
        if (duty_cycle <= 0) 
				duty_cycle = 5000;
        PWM1_3_CMPA_R = duty_cycle;
        Delay_ms(100);
    }*/
}

void Delay_ms(int time_ms)
{
    int i, j;
    for(i = 0 ; i < time_ms; i++){
        for(j = 0; j < 3180; j++)
            {}  /* excute NOP for 1ms */
		}
}
