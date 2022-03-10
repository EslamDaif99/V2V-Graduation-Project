#include "Type.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"
#include "PWM.h"

uint32_t Load;


void PWMPinConfigure(PWM_Module module,PWM_Number number)
{

    switch(module)
    {
        case M0PWM:

            switch(number)
            {
                case PWM0:
                    GPIO_PORTB_AFSEL_R|=0x40;
                    GPIO_PORTB_PCTL_R|=0x0400000;
                    break;

                case PWM1:
                    GPIO_PORTB_AFSEL_R|=0x80;
                    GPIO_PORTB_PCTL_R|=0x4000000;
                    break;

                case PWM2:
                    GPIO_PORTB_AFSEL_R|=0x10;
                    GPIO_PORTB_PCTL_R|=0x0004000;
                    break;

                case PWM3:
                    GPIO_PORTB_AFSEL_R|=0x20;
                    GPIO_PORTB_PCTL_R|=0x00400000;
                    break;

                case PWM4:
                    GPIO_PORTE_AFSEL_R|=0x10;
                    GPIO_PORTE_PCTL_R|=0x0040000;
                    break;

                case PWM5:
                    GPIO_PORTE_AFSEL_R|=0x20;
                    GPIO_PORTE_PCTL_R|=0x00400000;
                    break;

                case PWM6:
                    GPIO_PORTD_AFSEL_R|=0x01;
                    GPIO_PORTD_PCTL_R|=0x00000004;

                    GPIO_PORTC_AFSEL_R|=0x10;
                    GPIO_PORTC_PCTL_R|=00040000;
                    break;

                case PWM7:
                    GPIO_PORTD_AFSEL_R|=0x02;
                    GPIO_PORTD_PCTL_R|=0x00000040;

                    GPIO_PORTC_AFSEL_R|=0x20;
                    GPIO_PORTC_PCTL_R|=0x00400000; 
                    break;
            }

            break;
        case M1PWM:
                switch(number)
            {
                case PWM0:
                    GPIO_PORTD_AFSEL_R|=0x01;
                    GPIO_PORTD_PCTL_R|= 0x00000005;
                    break;

                case PWM1:
                    GPIO_PORTD_AFSEL_R|=0x02;
                    GPIO_PORTD_PCTL_R|=0x00000050;
                    break;

                case PWM2:
                    GPIO_PORTA_AFSEL_R|=0x40;
                    GPIO_PORTA_PCTL_R|=0x05000000;

                    GPIO_PORTE_AFSEL_R|=0x10;
                    GPIO_PORTE_PCTL_R|=0x00050000;
                    break;

                case PWM3:
                    GPIO_PORTA_AFSEL_R|=0x80;
                    GPIO_PORTA_PCTL_R|=0x50000000;

                    GPIO_PORTE_AFSEL_R|=0x20;
                    GPIO_PORTE_PCTL_R|=0x00500000;
                    break;

                case PWM4:
                    GPIO_PORTF_AFSEL_R|=0x01;
                    GPIO_PORTF_PCTL_R|=0x00000005;
                    break;

                case PWM5:
                    GPIO_PORTF_AFSEL_R|=0x02;
                    GPIO_PORTF_PCTL_R|=0x00000050;
                    break;

                case PWM6:
                    GPIO_PORTF_AFSEL_R|=0x04;
                    GPIO_PORTF_PCTL_R|=0x00000500;
                    break;

                case PWM7:
                    GPIO_PORTF_AFSEL_R|=0x08;
                    GPIO_PORTF_PCTL_R|=0x00005000;
                    break;
                default:
                        /*Do nothing*/ break;
            }

            break;
        
        default:
            /*Do nothing*/ break;


    }


}


void PWMClockSet (PWM_Module module)
{
    SET_BIT(SYSCTL_RCGCPWM_R,module);      /*Enable and provide a clock to PWM module  in Run mode*/

}


void PWMDiv(PWM_SYSCLK_DIV div)
{
    SET_BIT(SYSCTL_RCC_R,20);              /* Enable System Clock Divisor function  */
    SYSCTL_RCC_R|=(div<<17);
    
}


void PWMGenConfigure (PWM_Module module, PWM_Mode mode, PWM_Number number)
{

  switch(module)
  { 
      case M0PWM:

            switch(number)
            {
                case PWM0: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_0_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_0_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM1: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_0_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_0_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
														break;
                    }
                    break;

                case PWM2: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_1_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_1_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM3: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_1_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_1_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM4: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_2_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_2_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													 break;
                    }
                    break;

                case PWM5: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_2_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_2_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */break;
                    }
                    break;

                case PWM6: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_3_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_3_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM7: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM0_3_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_3_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;
            }
            break;

      case M1PWM:

            switch(number)
            {
                case PWM0: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_0_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_0_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM1: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_0_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_0_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */break;
                    }
                    break;

                case PWM2: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_2_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_2_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM3: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_1_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_1_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM4: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_2_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_2_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM5: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_2_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_2_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM6: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_3_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_3_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */
													break;
                    }
                    break;

                case PWM7: 

                    switch(mode)
                    {
                        case Count_UP:
                            SET_BIT(PWM1_3_CTL_R,1);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_3_CTL_R,1);
                            break;
                        
                        default:
                            /*Do Nothing */break;
                    }
                    break;

                default:
									break;
                    /*Do Nothing */

            }
            break;
     default:
            /*Do Nothing */
		             break;

  }


}

void PWMGenEnable(PWM_Module module, PWM_Generator generator, PWM_Number number)
{

    switch(module)
    {
        case M0PWM:
            switch(generator)
            {
                case Generator_0 :
                    SET_BIT (PWM0_0_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    
                    SET_BIT(PWM0_ENABLE_R,number);       /*The generated pwm0A' signal is passed to the MnPWM0 pin*/
                           /*The generated pwm0B' signal is passed to the MnPWM1 pin*/
                    break;

                case Generator_1 :
                    SET_BIT (PWM0_1_CTL_R,0);

                    SET_BIT(PWM0_ENABLE_R,number);       /*The generated pwm1A' signal is passed to the MnPWM0 pin*/
                          /*The generated pwm1B' signal is passed to the MnPWM1 pin*/
                    break;

                case Generator_2 :
                    SET_BIT (PWM0_2_CTL_R,0);

                    SET_BIT(PWM0_ENABLE_R,number);       /*The generated pwm2A' signal is passed to the MnPWM0 pin*/
                         /*The generated pwm2B' signal is passed to the MnPWM1 pin*/
                    break;

                case Generator_3 :
                    SET_BIT (PWM0_3_CTL_R,0);

                    SET_BIT(PWM0_ENABLE_R,number);       /*The generated pwm3A' signal is passed to the MnPWM0 pin*/
                           /*The generated pwm3B' signal is passed to the MnPWM1 pin*/
                    break;

                default:
                    /*Do Nothing */ break;
            }
            break;

        case M1PWM:
            switch(generator)
            {
                case Generator_0 :
                    SET_BIT (PWM1_0_CTL_R,0);

                    SET_BIT(PWM1_ENABLE_R,number);       /*The generated pwm0A' signal is passed to the MnPWM0 pin*/
                         /*The generated pwm0B' signal is passed to the MnPWM1 pin*/
                    break;

                case Generator_1 :
                    SET_BIT (PWM1_1_CTL_R,0);

                    SET_BIT(PWM1_ENABLE_R,number);       /*The generated pwm1A' signal is passed to the MnPWM0 pin*/
                          /*The generated pwm1B' signal is passed to the MnPWM1 pin*/
                    break;

                case Generator_2 :
                    SET_BIT (PWM1_2_CTL_R,0);

                    SET_BIT(PWM1_ENABLE_R,number);       /*The generated pwm2A' signal is passed to the MnPWM0 pin*/
                          /*The generated pwm2B' signal is passed to the MnPWM1 pin*/
                    break;

                case Generator_3 :
                    SET_BIT (PWM1_3_CTL_R,0);

                    SET_BIT(PWM1_ENABLE_R,number);       /*The generated pwm3A' signal is passed to the MnPWM0 pin*/
                         /*The generated pwm3B' signal is passed to the MnPWM1 pin*/
                    break;

                default:
                    /*Do Nothing */ break;
            }
            break;

        default:
            /*Do Nothing */  break; 
    }

  

}

void PWMGenDisable(PWM_Module module, PWM_Generator generator, PWM_Number number)
{
    switch(module)
    {
        case M0PWM:
            switch(generator)
            {
                case Generator_0 :
                    CLR_BIT (PWM0_0_CTL_R,0);
                    CLR_BIT(PWM0_ENABLE_R,number);
                    break;

                case Generator_1 :
                    CLR_BIT (PWM0_1_CTL_R,0);
                    CLR_BIT(PWM0_ENABLE_R,number);
                    break;

                case Generator_2 :
                    CLR_BIT (PWM0_2_CTL_R,0);
                    CLR_BIT(PWM0_ENABLE_R,number);
                    break;

                case Generator_3 :
                    CLR_BIT (PWM0_3_CTL_R,0);
                    CLR_BIT(PWM0_ENABLE_R,number);
                    break;

                default:
                    /*Do Nothing */ break;
            }
            break;

        case M1PWM:
            switch(generator)
            {
                case Generator_0 :
                    CLR_BIT (PWM1_0_CTL_R,0);
										
                    CLR_BIT(PWM1_ENABLE_R,number);
                    break;

                case Generator_1 :
                    CLR_BIT (PWM1_1_CTL_R,0);
                    CLR_BIT(PWM1_ENABLE_R,number);
                    break;

                case Generator_2 :
                    CLR_BIT (PWM1_2_CTL_R,0);
                    CLR_BIT(PWM1_ENABLE_R,number);
                    break;

                case Generator_3 :
                    CLR_BIT (PWM1_3_CTL_R,0);
                    CLR_BIT(PWM1_ENABLE_R,number);
										
                    break;

                default:
                    /*Do Nothing */	break;
            }
            break;

        default:
            /*Do Nothing */    break;
    }

  

}

void PWMGenPeriodSet(PWM_Module module, PWM_Generator generator, PWM_SYSCLK_DIV div, uint32_t Clock_Required)
{
        uint32_t System_Clock;
        switch(div)
        {   
            case PWM_SYSCLK_DIV_2:
                System_Clock=16000000/2;
                break;

            case PWM_SYSCLK_DIV_4:
                System_Clock=16000000/4;
                break;

            case PWM_SYSCLK_DIV_8:
                System_Clock=16000000/8;
                break;

            case PWM_SYSCLK_DIV_16:
                System_Clock=16000000/16;
                break;

            case PWM_SYSCLK_DIV_32:
                System_Clock=16000000/32;
                break;

            case PWM_SYSCLK_DIV_64:
                System_Clock=16000000/64;
                break;

            default:
                System_Clock=16000000;

        }
        
        Load =System_Clock/Clock_Required;      /*Load Value passed to  "PWMPulseWidthSet" function */

        switch(module)
        {
            case M0PWM:
                switch(generator)
                {
                    case Generator_0 :
                        PWM0_0_LOAD_R=Load;
                        break;

                    case Generator_1 :
                        PWM0_1_LOAD_R=Load;
                        break;

                    case Generator_2 :
                        PWM0_2_LOAD_R=Load;
                        break;

                    case Generator_3 :
                        PWM0_3_LOAD_R=Load;
                        break;

                    default:
                        /*Do Nothing */break;
                }

                break;
            case M1PWM:
                switch(generator)
                {
                    case Generator_0 :
                        PWM1_0_LOAD_R=Load;
                        break;

                    case Generator_1 :
                        PWM1_1_LOAD_R=Load;
                        break;

                    case Generator_2 :
                        PWM1_2_LOAD_R=Load;
                        break;

                    case Generator_3 :
                        PWM1_3_LOAD_R=Load;
                        break;

                    default:
                        /*Do Nothing */break;
								
                }
                break;

            default:
                /*Do Nothing */break;
        }

         
}


void PWMDutyCycleSet(PWM_Module module, PWM_Number number, PWM_Mode mode, uint32_t duty_cycle)
{

    switch(module)
    { 
      case M0PWM:

            switch(number)
            {
                case PWM0: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_0_CMPA_R=(duty_cycle/100)*Load;

                            PWM0_0_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_0_GENA_R|=(Do_nothing<<5);


                            break;

                        case Count_DOWN:
                            PWM0_0_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM0_0_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_0_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/	break;
                    }
                    break;

                case PWM1: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_0_CMPB_R=(duty_cycle/100)*Load;

                            PWM0_0_GENB_R|=(Drive_pwmA_High<<9);
                            
                            break;

                        case Count_DOWN:
                            PWM0_0_CMPB_R=((100-duty_cycle)/100)*Load;

                            
                            PWM0_0_GENB_R|=(Drive_pwmA_High<<11);
                            
                            break;

                        default:
                        /*Do nothing*/break;

                    }
                    break;

                case PWM2: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_1_CMPA_R=(duty_cycle/100)*Load;

                            PWM0_1_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_1_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM0_1_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM0_1_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_1_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM3: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_1_CMPB_R=(duty_cycle/100)*Load;

                            PWM0_1_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM0_1_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM0_1_GENB_R|=(Drive_pwmA_High<<11);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM4: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_2_CMPA_R=(duty_cycle/100)*Load;

                            PWM0_2_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_2_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM0_2_CMPA_R=((100-duty_cycle)/100)*Load;

                            
                            PWM0_2_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_2_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM5: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_2_CMPB_R=(duty_cycle/100)*Load;

                            PWM0_2_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM0_2_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM0_2_GENB_R|=(Drive_pwmA_High<<11);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM6: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_3_CMPA_R=(duty_cycle/100)*Load;

                            PWM0_3_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_3_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM0_3_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM0_3_GENA_R|=(Drive_pwmA_High<<3);
                            PWM0_3_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM7: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_3_CMPB_R=(duty_cycle/100)*Load;

                            PWM0_3_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM0_3_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM0_3_GENB_R|=(Drive_pwmA_High<<11);
                            break;


                        default:
                        /*Do nothing*/break;
                    }
                    break;
                default:
                /*Do nothing*/break;
            }
            break;

    case M1PWM:

            switch(number)
            {
                case PWM0: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_0_CMPA_R=(duty_cycle/100)*Load;

                            PWM1_0_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_0_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM1_0_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM1_0_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_0_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM1: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_0_CMPB_R=(duty_cycle/100)*Load;

                            PWM1_0_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM1_0_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM1_0_GENB_R|=(Drive_pwmA_High<<11);
                            break;

                        default:
                        /*Do nothing*/break;

                    }
                    break;

                case PWM2: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_1_CMPA_R=(duty_cycle/100)*Load;

                            PWM1_1_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_1_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM1_1_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM1_1_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_1_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM3: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_1_CMPB_R=(duty_cycle/100)*Load;

                            PWM1_1_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM1_1_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM1_1_GENB_R|=(Drive_pwmA_High<<11);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM4: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_2_CMPA_R=(duty_cycle/100)*Load;

                            PWM1_2_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_2_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM1_2_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM1_2_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_2_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM5: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_2_CMPB_R=(duty_cycle/100)*Load;

                            PWM1_2_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM1_2_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM1_2_GENB_R|=(Drive_pwmA_High<<11);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM6: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_3_CMPA_R=(duty_cycle/100)*Load;

                            PWM1_3_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_3_GENA_R|=(Do_nothing<<5);
                            break;

                        case Count_DOWN:
                            PWM1_3_CMPA_R=((100-duty_cycle)/100)*Load;

                            PWM1_3_GENA_R|=(Drive_pwmA_High<<3);
                            PWM1_3_GENA_R|=(Drive_pwmA_Low<<7);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM7: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_3_CMPB_R=(duty_cycle/100)*Load;

                            PWM1_3_GENB_R|=(Drive_pwmA_High<<9);
                            break;

                        case Count_DOWN:
                            PWM1_3_CMPB_R=((100-duty_cycle)/100)*Load;

                            PWM1_3_GENB_R|=(Drive_pwmA_High<<11);
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;
                default:
                /*Do nothing*/break;
            }
            break;
      
        
     default:
            /*Do Nothing */break;

  }

}
      
