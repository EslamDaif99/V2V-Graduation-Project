#ifndef _CONFIG_H_
#define _CONFIG_H_

/* ********** Software Component Status Options ********** */

#define SWC_STATUS_ENABLE                   (0xAB)
#define SWC_STATUS_DISABLE                  (0xCD)

/* ********** Software Components Status  ********** */

#define OS_SWC_STATUS                       (SWC_STATUS_ENABLE)
#define LED_SWC_STATUS                      (SWC_STATUS_ENABLE)
#define MOTOR_SWC_STATUS                    (SWC_STATUS_ENABLE)
#define GPIO_SWC_STATUS                     (SWC_STATUS_ENABLE)
#define SYSTICK_SWC_STATUS                  (SWC_STATUS_ENABLE)
#define UART_SWC_STATUS                     (SWC_STATUS_ENABLE)
#define PWM_SWC_STATUS                      (SWC_STATUS_DISABLE)

#endif
