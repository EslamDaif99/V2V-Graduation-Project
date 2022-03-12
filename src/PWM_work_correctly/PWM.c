#include "GPIO.h"
#include "PWM.h"
#include <stdint.h>
#include <stdio.h>

void PWM_init(void)
{
   
     /* Clock setting for PWM and GPIO PORT */
    SYSCTL_RCGCPWM_R |= 2;       /* Enable clock to PWM1 module  as pin0 for PWM0 and pin 1 for PWM1 */
    SYSCTL_RCGCGPIO_R |= 0x20;   /* Enable system clock to PORTF  as port F in pin 5*/
	  SYSCTL_RCC_R |= (1<<20);     /* Enable System Clock Divisor function in pin20  */
    SYSCTL_RCC_R |= 0x000E0000;  /* Use pre-divider value of 64 and after that feed clock to PWM1 module put 111 in pin
	(17,18,19)*/
	
	
	/* Setting of PF2 pin for M1PWM6 channel output pin */
		GPIO_PORTF_LOCK_R= 0x4C4F434B; 			  //TO UN LOCK THE PORTF
	  GPIO_PORTF_CR_R =0x04;							  // TO MAKE SURE THAT I WILL USE  PIN2
	  GPIO_PORTF_DIR_R |=0x04;    			    // WE SET PIN2 output
	
		GPIO_PORTF_AFSEL_R |= (1<<2);          /* PF2 sets a alternate function */
    GPIO_PORTF_PCTL_R &= ~(0x00000F00);    /*set PF2 as output pin */
    GPIO_PORTF_PCTL_R |= 0x00000500;       /* make PF2 PWM output pin */
    GPIO_PORTF_DEN_R |= (1<<2);            /* set PF2 as a digital pin */
    
    PWM1_3_CTL_R &= ~(1<<0);	   /* Disable Generator 3 counter */
	  PWM1_3_CTL_R &= ~(1<<1);  	 /* select down count mode of counter 3*/
    PWM1_3_GENA_R = 0x0000008C;  /* Set PWM output when counter reloaded set(pin 2,3) and clear when matches PWMCMPA put 0 in pin6and 1 in pin7)*/
    PWM1_3_LOAD_R = 5000; 	     /* set load value for 50Hz 16MHz/64 = 250kHz and (250KHz/5000) */
		PWM1_3_CMPA_R = 1250-1;	       /* set duty cyle to 75% ((100-duty_cycle)%* LOAD_value) ---- (100-75)%*5000=1250*/    
    PWM1_3_CTL_R = 1;            /* Enable Generator 3 counter set pin0  and put 0 in pin1 as we use count down */
    PWM1_ENABLE_R = 0x40;        /* Enable PWM1 channel 6 output -- set pin6 */
}