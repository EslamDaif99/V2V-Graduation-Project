#include <stdint.h>
#include <stdio.h>
#include "MOTOR_DRIVER.h"
#include "GPIO.h"

//Spin motor in one direction by giving IN1 and IN2 signals to L298N
void Turn_oneDirection(void)
{
 	 	 SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTA */
		 GPIO_PORTA_LOCK_R = 0x4C4F434B; 			         //TO UN LOCK THE PORTA
	   GPIO_PORTA_CR_R |= (1<<3)|(1<<2);						 // TO MAKE SURE THAT I WILL USE  PIN 2 and 3	
	   GPIO_PORTA_DIR_R |= (1<<3)|(1<<2);            /* pin digital */
     GPIO_PORTA_DEN_R |= (1<<3)|(1<<2);            /* pin digital */
     GPIO_PORTA_DATA_R |=(1<<2);
		 GPIO_PORTA_DATA_R &=~(1<<3);
}

//Spin motor in other direction by giving IN1 and IN2 signals to L298N

void Turn_OtherDirection(void)
{
     SYSCTL_RCGCGPIO_R |= 0x01;   								 /* enable clock to PORTA */
		 GPIO_PORTA_LOCK_R = 0x4C4F434B; 			         //TO UN LOCK THE PORTA
	   GPIO_PORTA_CR_R |= (1<<3)|(1<<2);						 // TO MAKE SURE THAT I WILL USE  PIN 2 and 3
	   GPIO_PORTA_DIR_R |= (1<<3)|(1<<2);            /* pin digital */
     GPIO_PORTA_DEN_R |= (1<<3)|(1<<2);            /* pin digital */
     GPIO_PORTA_DATA_R |=(1<<3);
		 GPIO_PORTA_DATA_R &=~(1<<2);
	   //GPIO_PORTA_DATA_R |=(0<<2);
}