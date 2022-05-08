#ifndef _PORT_H_
#define _PORT_H_
#include "config.h"

/* ***************** This is a Temp Solution ***************** */

#if (PWM_SWC_STATUS == SWC_STATUS_ENABLE)

#define LED_PORT           (GPIO_PORTA)
#define LED_PIN_NUMBER     (GPIO_PIN_4)

#else

#define LED_PORT           (GPIO_PORTF)
#define LED_PIN_NUMBER     (GPIO_PIN_3)

#endif


#define MOTOR_1_PORT       (GPIO_PORTA)
#define MOTOR_2_PORT       (GPIO_PORTA)
#define MOTOR_3_PORT       (GPIO_PORTC)
#define MOTOR_4_PORT       (GPIO_PORTC)


/***************Motor 1***************/

#define MOTOR_1_ENABLE     (GPIO_PIN_0)           /*PF0 PWM */
#define MOTOR_1_IN1        (GPIO_PIN_2)
#define MOTOR_1_IN2        (GPIO_PIN_3)

/***************Motor 2***************/
#define MOTOR_2_ENABLE     (GPIO_PIN_1)           /*PF1 PWM */
#define MOTOR_2_IN1        (GPIO_PIN_6)
#define MOTOR_2_IN2        (GPIO_PIN_7)

/***************Motor 3***************/
#define MOTOR_3_ENABLE     (GPIO_PIN_2)			  /*PF2 PWM */
#define MOTOR_3_IN1        (GPIO_PIN_4)
#define MOTOR_3_IN2        (GPIO_PIN_5)

/***************Motor 4***************/
#define MOTOR_4_ENABLE     (GPIO_PIN_3)			   /*PF3 PWM */
#define MOTOR_4_IN1        (GPIO_PIN_6)
#define MOTOR_4_IN2        (GPIO_PIN_7)

/***************UART ***************/
/* UART_RX_PIN          PB0 */
/* UART_TX_PIN          PB1 */

#endif
