#include "config.h"
#include "Type.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"
#include "PWM.h"

#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

uint32_t Load ;

#endif

void PWMClockSet (PWM_Module module,PWM_Number number)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

    SET_BIT(SYSCTL_RCGCPWM_R,module);      /*Enable and provide a clock to PWM module  in Run mode*/
		switch(module)
		{
			case M0PWM:
					switch(number)
					{
						case PWM0:
							SET_BIT(SYSCTL_RCGCGPIO_R,1);					 /* enable clock to PORTB */
							break;
						case PWM1:
							SET_BIT(SYSCTL_RCGCGPIO_R,1);					 /* enable clock to PORTB */
							break;
						case PWM2:
							SET_BIT(SYSCTL_RCGCGPIO_R,1);					 /* enable clock to PORTB */
							break;
						case PWM3:
							SET_BIT(SYSCTL_RCGCGPIO_R,1);					 /* enable clock to PORTB */
							break;
						case PWM4:
							SET_BIT(SYSCTL_RCGCGPIO_R,4);					 /* enable clock to PORTE */
							break;
						case PWM5:
							SET_BIT(SYSCTL_RCGCGPIO_R,4);					 /* enable clock to PORTE */
							break;
						case PWM6:
							SET_BIT(SYSCTL_RCGCGPIO_R,3);					 /* enable clock to PORTD */
						  SET_BIT(SYSCTL_RCGCGPIO_R,2);					 /* enable clock to PORTC */
							break;
						case PWM7:
							SET_BIT(SYSCTL_RCGCGPIO_R,3);					 /* enable clock to PORTD */
						  SET_BIT(SYSCTL_RCGCGPIO_R,2);					 /* enable clock to PORTC */
							break;							
					  default: break;
					
					}
				break;
					
			case M1PWM:
					switch(number)
					{
					  case PWM0:
						  SET_BIT(SYSCTL_RCGCGPIO_R,3);					 /* enable clock to PORTD */	
							break;
						case PWM1:
							SET_BIT(SYSCTL_RCGCGPIO_R,3);					 /* enable clock to PORTD */
							break;
						case PWM2:
							SET_BIT(SYSCTL_RCGCGPIO_R,0);					 /* enable clock to PORTA */
							SET_BIT(SYSCTL_RCGCGPIO_R,4);					 /* enable clock to PORTE */
							break;
						case PWM3:
							SET_BIT(SYSCTL_RCGCGPIO_R,0);					 /* enable clock to PORTA */
						  SET_BIT(SYSCTL_RCGCGPIO_R,4);					 /* enable clock to PORTE */
							break;
						case PWM4:
							SET_BIT(SYSCTL_RCGCGPIO_R,5);					 /* enable clock to PORTF */
							break;
						case PWM5:
							SET_BIT(SYSCTL_RCGCGPIO_R,5);					 /* enable clock to PORTF */
							break;
						case PWM6:
							SET_BIT(SYSCTL_RCGCGPIO_R,5);					 /* enable clock to PORTF */
							break;
						case PWM7:
							SET_BIT(SYSCTL_RCGCGPIO_R,5);					 /* enable clock to PORTF */
							break;							
					  default: break;
					
					}
				break;
					
			default: break;
		}

#endif
}

void PWMDiv(PWM_SYSCLK_DIV div)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

    SET_BIT(SYSCTL_RCC_R,20);              /* Enable System Clock Divisor function  */
    SYSCTL_RCC_R|=(div<<17);
    
#endif  
}

void PWMPinConfigure(PWM_Module module,PWM_Number number)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

    switch(module)
    {
        case M0PWM:

            switch(number)
            {
                case PWM0:
	                GPIO_PORTB_LOCK_R= 0x4C4F434B;
                    GPIO_PORTB_CR_R  |=0x40;						
                    GPIO_PORTB_DIR_R |=0x40;
    				GPIO_PORTB_AFSEL_R|=0x40;
                    GPIO_PORTB_PCTL_R&= ~(0x0F00000);
    			    GPIO_PORTB_PCTL_R|=0x0400000;
					GPIO_PORTB_DEN_R |=0x40;
                    break;

                case PWM1:
                    GPIO_PORTB_LOCK_R= 0x4C4F434B;
                    GPIO_PORTB_CR_R  |=0x80;						
                    GPIO_PORTB_DIR_R |=0x80;
                    GPIO_PORTB_AFSEL_R|=0x80;
                    GPIO_PORTB_PCTL_R&= ~(0xF000000);
                    GPIO_PORTB_PCTL_R|=0x4000000;
                    GPIO_PORTB_DEN_R |=0x80;
                    break;

                case PWM2:
                    GPIO_PORTB_LOCK_R= 0x4C4F434B;
                    GPIO_PORTB_CR_R  |=0x10;						
                    GPIO_PORTB_DIR_R |=0x10;
                    GPIO_PORTB_AFSEL_R|=0x10;
                    GPIO_PORTB_PCTL_R&= ~(0x0000F000);
                    GPIO_PORTB_PCTL_R|=0x0004000;
                    GPIO_PORTB_DEN_R |=0x10; 
                    break;

                case PWM3:
                    GPIO_PORTB_LOCK_R= 0x4C4F434B;
                    GPIO_PORTB_CR_R  |=0x20;						
                    GPIO_PORTB_DIR_R |=0x20;
                    GPIO_PORTB_AFSEL_R|=0x20;
                    GPIO_PORTB_PCTL_R&= ~(0x00F00000);
    			    GPIO_PORTB_PCTL_R|=0x00400000;
					GPIO_PORTB_DEN_R |=0x20; 
                    break;

                case PWM4:
                    GPIO_PORTE_LOCK_R= 0x4C4F434B;
                    GPIO_PORTE_CR_R  |=0x10;						
                    GPIO_PORTE_DIR_R |=0x10;
                    GPIO_PORTE_AFSEL_R|=0x10;
                    GPIO_PORTE_PCTL_R&= ~(0x00F0000);
    			    GPIO_PORTE_PCTL_R|=0x0040000;
					GPIO_PORTE_DEN_R |=0x10; 
                    break;

                case PWM5:
					GPIO_PORTE_LOCK_R= 0x4C4F434B;
					GPIO_PORTE_CR_R  |=0x20;						
					GPIO_PORTE_DIR_R |=0x20;  
                    GPIO_PORTE_AFSEL_R|=0x20;
                    GPIO_PORTE_PCTL_R&= ~(0x00F00000);
  			        GPIO_PORTE_PCTL_R|=0x00400000;
					GPIO_PORTE_DEN_R |=0x20; 								
								
																

                    break;

                case PWM6:
					GPIO_PORTD_LOCK_R= 0x4C4F434B;
					GPIO_PORTD_CR_R  |=0x01;						
					GPIO_PORTD_DIR_R |=0x01;
                    GPIO_PORTD_AFSEL_R|=0x01;
                    GPIO_PORTD_PCTL_R&= ~(0x0000000F);
    			    GPIO_PORTD_PCTL_R|=0x00000004;
					GPIO_PORTD_DEN_R |=0x01;
								
					GPIO_PORTC_LOCK_R= 0x4C4F434B;
					GPIO_PORTC_CR_R  |=0x10;						
					GPIO_PORTC_DIR_R |=0x10;
     				GPIO_PORTC_AFSEL_R|=0x10;
                    GPIO_PORTC_PCTL_R&= ~(0x000F0000);
    			    GPIO_PORTC_PCTL_R|=00040000;
					GPIO_PORTC_DEN_R |=0x10;
                    break;

                case PWM7:
                    GPIO_PORTD_LOCK_R= 0x4C4F434B;
                    GPIO_PORTD_CR_R  |=0x02;						
                    GPIO_PORTD_DIR_R |=0x02;
                    GPIO_PORTD_AFSEL_R|=0x02;
                    GPIO_PORTD_PCTL_R&= ~(0x000000F0); 
    			    GPIO_PORTD_PCTL_R|=0x00000040;
					GPIO_PORTD_DEN_R |=0x02;

								
                    GPIO_PORTC_LOCK_R= 0x4C4F434B;
                    GPIO_PORTC_CR_R  |=0x20;						
                    GPIO_PORTC_DIR_R |=0x20; 
                    GPIO_PORTC_AFSEL_R|=0x20;
                    GPIO_PORTC_PCTL_R&= ~(0x00F00000); 
                    GPIO_PORTC_PCTL_R|=0x00400000; 
                    GPIO_PORTC_DEN_R |=0x20;
                    break;
            }

            break;
        case M1PWM:
                switch(number)
            {
                case PWM0:
                    GPIO_PORTD_LOCK_R= 0x4C4F434B;
                    GPIO_PORTD_CR_R  |=0x01;						
                    GPIO_PORTD_DIR_R |=0x01;
                    GPIO_PORTD_AFSEL_R|=0x01;
                    GPIO_PORTD_PCTL_R&= ~(0x0000000F);
                    GPIO_PORTD_PCTL_R|= 0x00000005;    			   
					GPIO_PORTD_DEN_R |=0x01;
                    break;

                case PWM1:
                    GPIO_PORTD_LOCK_R= 0x4C4F434B;
                    GPIO_PORTD_CR_R  |=0x02;						
                    GPIO_PORTD_DIR_R |=0x02; 
                    GPIO_PORTD_AFSEL_R|=0x02;
                    GPIO_PORTD_PCTL_R&= ~(0x000000F0);
                    GPIO_PORTD_PCTL_R|=0x00000050;   			   
					GPIO_PORTD_DEN_R |=0x02;
                    break;

                case PWM2:
                    GPIO_PORTA_LOCK_R= 0x4C4F434B;
                    GPIO_PORTA_CR_R  |=0x40;						
                    GPIO_PORTA_DIR_R |=0x40; 
                    GPIO_PORTA_AFSEL_R|=0x40;
                    GPIO_PORTA_PCTL_R&= ~(0x0F000000);
   			        GPIO_PORTA_PCTL_R|=0x05000000;
					GPIO_PORTA_DEN_R |=0x40;
								
								
                    GPIO_PORTE_LOCK_R= 0x4C4F434B;
                    GPIO_PORTE_CR_R  |=0x10;						
                    GPIO_PORTE_DIR_R |=0x10;
                    GPIO_PORTE_AFSEL_R|=0x10;
                    GPIO_PORTE_PCTL_R&= ~(0x000F0000);
                    GPIO_PORTE_PCTL_R|=0x00050000;    
					GPIO_PORTE_DEN_R |=0x10;
                    break;

                case PWM3:
					GPIO_PORTA_LOCK_R= 0x4C4F434B;
					GPIO_PORTA_CR_R  |=0x80;						
					GPIO_PORTA_DIR_R |=0x80;
                    GPIO_PORTA_AFSEL_R|=0x80;
                    GPIO_PORTA_PCTL_R &= ~(0xF0000000);
					GPIO_PORTA_PCTL_R|=0x50000000;
					GPIO_PORTA_DEN_R |=0x80;
								
								
								
                    GPIO_PORTE_LOCK_R= 0x4C4F434B;
                    GPIO_PORTE_CR_R  |=0x20;						
                    GPIO_PORTE_DIR_R |=0x20;
                    GPIO_PORTE_AFSEL_R|=0x20;
                    GPIO_PORTE_PCTL_R &= ~(0x00F00000);
					GPIO_PORTE_PCTL_R|=0x00500000;
					GPIO_PORTE_DEN_R |=0x20;          
                    break;

                case PWM4:
                    GPIO_PORTF_LOCK_R= 0x4C4F434B; 			  //TO UN LOCK THE PORTF
                    GPIO_PORTF_CR_R  |=0x01;							/*TO MAKE SURE THAT I WILL USE  PIN0*/
                    GPIO_PORTF_DIR_R |=0x01;    			    /* WE SET PIN0 output*/
                    GPIO_PORTF_AFSEL_R|=0x01;
                    GPIO_PORTF_PCTL_R &= ~(0x0000000F);
                    GPIO_PORTF_PCTL_R|=0x00000005;
                    GPIO_PORTF_DEN_R |=0x01;            /* set PF0 as a digital pin */
                    break;

                case PWM5:
                    GPIO_PORTF_LOCK_R= 0x4C4F434B; 			  //TO UN LOCK THE PORTF
                    GPIO_PORTF_CR_R  |=0x02;							/*TO MAKE SURE THAT I WILL USE  PIN1*/
                    GPIO_PORTF_DIR_R |=0x02;    			    /* WE SET PIN1 output*/
                    GPIO_PORTF_AFSEL_R|=0x02;
                    GPIO_PORTF_PCTL_R &= ~(0x000000F0);
                    GPIO_PORTF_PCTL_R|=0x00000050;
                    GPIO_PORTF_DEN_R |=0x02;            /* set PF1 as a digital pin */
                    break;

                case PWM6:
                    GPIO_PORTF_LOCK_R= 0x4C4F434B; 			  //TO UN LOCK THE PORTF
                    GPIO_PORTF_CR_R  |=0x04;							 /*TO MAKE SURE THAT I WILL USE  PIN2*/
                    GPIO_PORTF_DIR_R |=0x04;    			    /*WE SET PIN2 output*/
                    GPIO_PORTF_AFSEL_R|=0x04;
                    GPIO_PORTF_PCTL_R &= ~(0x00000F00);
                    GPIO_PORTF_PCTL_R|=0x00000500;
                    GPIO_PORTF_DEN_R |=0x04;            /* set PF2 as a digital pin */
                    break;

                case PWM7:
                    GPIO_PORTF_LOCK_R= 0x4C4F434B; 			  //TO UN LOCK THE PORTF
                    GPIO_PORTF_CR_R  |=0x08;							 
                    GPIO_PORTF_DIR_R |=0x08;    			    /* WE SET PIN3 output*/
                    GPIO_PORTF_AFSEL_R|=0x08;
                    GPIO_PORTF_PCTL_R&= ~(0x0000F000);
                    GPIO_PORTF_PCTL_R|=0x00005000;
                    GPIO_PORTF_DEN_R |=0x08;            /* set PF3 as a digital pin */
                    break;
                default:
                        /*Do nothing*/ break;
            }

            break;
        
        default:
            /*Do nothing*/ break;


    }

#endif
}


void PWMGenDisable(PWM_Module module,PWM_Number number)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

    switch(module)
    {
        case M0PWM:
            if( (number==PWM0) ||(number==PWM1) )
            {
                CLR_BIT (PWM0_0_CTL_R,0);
            }
            else if((number==PWM2) ||(number==PWM3))
            {
                CLR_BIT (PWM0_1_CTL_R,0);
            }
            else if((number==PWM4) ||(number==PWM5))
            {
                CLR_BIT (PWM0_2_CTL_R,0);
            }
             else if((number==PWM6) ||(number==PWM7))
            {
                CLR_BIT (PWM0_3_CTL_R,0);
            }
            else {/*Do nothing*/}
            break;

        case M1PWM:
            if( (number==PWM0) ||(number==PWM1) )
            {
                CLR_BIT (PWM1_0_CTL_R,0);
            }
            else if((number==PWM2) ||(number==PWM3))
            {
                CLR_BIT (PWM1_1_CTL_R,0);
            }
            else if((number==PWM4) ||(number==PWM5))
            {
                CLR_BIT (PWM1_2_CTL_R,0);
            }
             else if((number==PWM6) ||(number==PWM7))
            {
                CLR_BIT (PWM1_3_CTL_R,0);
            }
            else {/*Do nothing*/}
            break;

        default:
					
            /*Do Nothing */    break;
    }

#endif
}

void PWMGenConfigure (PWM_Module module, PWM_Mode mode, PWM_Number number)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

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
                            PWM0_0_GENA_R|=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_0_CTL_R,1);
                            PWM0_0_GENA_R|=(1<<2)|(1<<3)|(1<<7);
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
                            PWM0_0_GENB_R|=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_0_CTL_R,1);
                            PWM0_0_GENB_R|=(1<<11)|(1<<12);
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
                            PWM0_1_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_1_CTL_R,1);
                            PWM0_1_GENA_R|=(1<<2)|(1<<3)|(1<<7);
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
                            PWM0_1_GENB_R|=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_1_CTL_R,1);
                            PWM0_1_GENB_R=(1<<2)|(1<<3)|(1<<11);
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
                            PWM0_2_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_2_CTL_R,1);
                            PWM0_2_GENA_R|=(1<<2)|(1<<3)|(1<<7);
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
                            PWM0_2_GENB_R|=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_2_CTL_R,1);
                            PWM0_2_GENB_R=(1<<2)|(1<<3)|(1<<11);
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
                            PWM0_3_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_3_CTL_R,1);
                            PWM0_3_GENA_R|=(1<<2)|(1<<3)|(1<<7);
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
                            PWM0_3_GENB_R=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM0_3_CTL_R,1);
                            PWM0_3_GENB_R=(1<<2)|(1<<3)|(1<<11);
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
                            PWM1_0_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_0_CTL_R,1);
                            PWM1_0_GENA_R|=(1<<2)|(1<<3)|(1<<7);
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
                            PWM1_0_GENB_R=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_0_CTL_R,1);
                            PWM1_0_GENB_R=(1<<2)|(1<<3)|(1<<11);
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
                            PWM1_1_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_2_CTL_R,1);
                            PWM1_1_GENA_R=(1<<2)|(1<<3)|(1<<7);
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
                            PWM1_1_GENB_R=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_1_CTL_R,1);
                            PWM1_1_GENB_R=(1<<2)|(1<<3)|(1<<11);
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
                            PWM1_2_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_2_CTL_R,1);
                            PWM1_2_GENA_R=(1<<2)|(1<<3)|(1<<7);
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
                            PWM1_2_GENB_R=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_2_CTL_R,1);
                            PWM1_2_GENB_R=(1<<2)|(1<<3)|(1<<11);
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
                            PWM1_3_GENA_R=(1<<3)|(1<<4);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_3_CTL_R,1);
                            PWM1_3_GENA_R=(1<<2)|(1<<3)|(1<<7);
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
                            PWM1_3_GENB_R=(1<<9)|(1<<10);
                            break;
                        
                        case Count_DOWN:	
                            CLR_BIT(PWM1_3_CTL_R,1);
                            PWM1_3_GENB_R=(1<<2)|(1<<3)|(1<<11);
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

#endif
}

void PWMGenPeriodSet(PWM_Module module, PWM_Number number, PWM_SYSCLK_DIV div, uint32_t Clock_Required)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

        uint32_t System_Clock=0;
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
        //Load =5000;
        switch(module)
        {
            case M0PWM:
                if((number==PWM0) ||(number==PWM1))
                {
                    PWM0_0_LOAD_R=Load;
                }
                else if ((number==PWM2) ||(number==PWM3))
                {
                    PWM0_1_LOAD_R=Load;
                }
                else if ((number==PWM4) ||(number==PWM5))
                {
                    PWM0_2_LOAD_R=Load;
                }
                else if ((number==PWM6) ||(number==PWM7))
                {
                    PWM0_3_LOAD_R=Load;
                }
                else{/*Do nothing*/}
                break;
                
            case M1PWM:
                if((number==PWM0) ||(number==PWM1))
                {
                    PWM1_0_LOAD_R=Load;
                }
                else if ((number==PWM2) ||(number==PWM3))
                {
                    PWM1_1_LOAD_R=Load;
                }
                else if ((number==PWM4) ||(number==PWM5))
                {
                    PWM1_2_LOAD_R=Load;
                }
                else if ((number==PWM6) ||(number==PWM7))
                {
                    PWM1_3_LOAD_R=Load;
                }
                else{/*Do nothing*/}
                break;

            default:
                /*Do Nothing */break;
        }

#endif      
}


void PWMDutyCycleSet(PWM_Module module, PWM_Number number, PWM_Mode mode, uint32_t duty_cycle)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

   /*	Load =System_Clock/Clock_Required;  */ 
   /*Load Value passed to  "PWMPulseWidthSet" function */
	      /*Load Value passed to  "PWMPulseWidthSet" function */
    //Load =5000;
  
    //uint32_t y =0;
    switch(module)
    { 
      case M0PWM:

            switch(number)
            {
                case PWM0: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_0_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_0_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/	break;
                    }
                    break;

                case PWM1: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_0_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_0_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;

                    }
                    break;

                case PWM2: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_1_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_1_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM3: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_1_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_1_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM4: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_2_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_2_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM5: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_2_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_2_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM6: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_3_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_3_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM7: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM0_3_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM0_3_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;
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
                            PWM1_0_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_0_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM1: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_0_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_0_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;

                    }
                    break;

                case PWM2: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_1_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_1_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM3: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_1_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_1_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM4: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_2_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_2_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM5: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_2_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_2_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;

                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM6: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_3_CMPA_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:

                        
                            PWM1_3_CMPA_R=(((100-duty_cycle)*0.01)*Load)-1;
                            
                        
                            break;

                        default:
                        /*Do nothing*/break;
                    }
                    break;

                case PWM7: 

                    switch(mode)
                    {
                        case Count_UP:
                            PWM1_3_CMPB_R=((duty_cycle*0.01)*Load)-1;
                            break;

                        case Count_DOWN:
                            PWM1_3_CMPB_R=(((100-duty_cycle)*0.01)*Load)-1;

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

#endif
}


void PWMGenEnable(PWM_Module module,PWM_Number number)
{
#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

    switch(module)
    {
        case M0PWM:
            if((number==PWM0) ||(number==PWM1))
            {
                    SET_BIT (PWM0_0_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM0_ENABLE_R,number);  
            }
            else if ((number==PWM2) ||(number==PWM3))
            {
                    SET_BIT (PWM0_1_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM0_ENABLE_R,number);  

            }
            else if ((number==PWM4) ||(number==PWM5))
            {
                    SET_BIT (PWM0_2_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM0_ENABLE_R,number);  

            }
            else if ((number==PWM6) ||(number==PWM7))
            {
                    SET_BIT (PWM0_3_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM0_ENABLE_R,number);  

            }
            else{/*Do nothing*/}
            break;

        case M1PWM:

            if((number==PWM0) ||(number==PWM1))
            {
                    SET_BIT (PWM1_0_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM1_ENABLE_R,number);  
            }
            else if ((number==PWM2) ||(number==PWM3))
            {
                    SET_BIT (PWM1_1_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM1_ENABLE_R,number);  

            }
            else if ((number==PWM4) ||(number==PWM5))
            {
                    SET_BIT (PWM1_2_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM1_ENABLE_R,number);  

            }
            else if ((number==PWM6) ||(number==PWM7))
            {
                    SET_BIT (PWM1_3_CTL_R,0);
                    /***************    PWM0_ENABLE_R*********************/
                    SET_BIT(PWM1_ENABLE_R,number);  

            }
            else{/*Do nothing*/}
            break;
            
        default:
            /*Do Nothing */  break; 
    }

#endif
}
