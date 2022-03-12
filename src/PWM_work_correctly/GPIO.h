#ifndef GPIO_H_
#define GPIO_H_
/*********24/2/2022************/ 
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
/********PORTA*****************/
#define GPIO_PORTA_DATA_R       (*((volatile uint32_t *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile uint32_t *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile uint32_t *)0x40004420))
#define GPIO_PORTA_DEN_R        (*((volatile uint32_t *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile uint32_t *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile uint32_t *)0x40004524))	

#define SYSCTL_RCC_R            (*((volatile uint32_t *)0x400FE060))
#define SYSCTL_RCC2_R           (*((volatile uint32_t *)0x400FE070))

/*************PORTF**********/
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))
#define GPIO_PORTF_DIR_R        (*((volatile uint32_t *)0x40025400))
	
/************PWM********/
#define SYSCTL_RCGCPWM_R        (*((volatile uint32_t *)0x400FE640))

#define PWM1_3_CTL_R            (*((volatile uint32_t *)0x40029100))		
#define PWM1_3_GENA_R           (*((volatile uint32_t *)0x40029120))	
#define PWM1_3_CMPA_R           (*((volatile uint32_t *)0x40029118))
#define PWM1_3_LOAD_R           (*((volatile uint32_t *)0x40029110))   
#define PWM1_ENABLE_R           (*((volatile uint32_t *)0x40029008))
		
#endif    