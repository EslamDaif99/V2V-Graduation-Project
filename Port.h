#ifndef _PORT_H_
#define _PORT_H_

#define LED_PORT           (GPIO_PORTF)
#define LED_PIN_NUMBER     (GPIO_PIN_3)



#define MOTOR_1_PORT       (GPIO_PORTA)
#define MOTOR_2_PORT       (GPIO_PORTB)
#define MOTOR_3_PORT       (GPIO_PORTD)
#define MOTOR_4_PORT       (GPIO_PORTD)


/***************Motor 1***************/
//#define MOTOR_1_ENABLE     (GPIO_PIN_4)       /*PB4 PWM */
#define MOTOR_1_ENABLE     (GPIO_PIN_2)  // PORTF PIN2 
#define MOTOR_1_IN1        (GPIO_PIN_2)
#define MOTOR_1_IN2        (GPIO_PIN_3)

/***************Motor 2***************/
#define MOTOR_2_ENABLE     (GPIO_PIN_5)       /*PB5 PWM */
#define MOTOR_2_IN1        (GPIO_PIN_2)
#define MOTOR_2_IN2        (GPIO_PIN_3)

/***************Motor 3***************/
#define MOTOR_3_ENABLE     (GPIO_PIN_0)			  /*PD0 PWM */
#define MOTOR_3_IN1        (GPIO_PIN_2)
#define MOTOR_3_IN2        (GPIO_PIN_3)

/***************Motor 4***************/
#define MOTOR_4_ENABLE     (GPIO_PIN_1)				/*PD1 PWM */
#define MOTOR_4_IN1        (GPIO_PIN_4)
#define MOTOR_4_IN2        (GPIO_PIN_5)






#endif
