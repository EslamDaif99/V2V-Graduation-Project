#ifndef _MOTOR_H_
#define _MOTOR_H_


typedef enum
{
    MOTOR_SPEED_LOW,
    MOTOR_SPEED_MID,
    MOTOR_SPEED_HIGH

}Motor_Speed_t;

void Motor_Init(void);
void Motor_Update(void);
void Motor_Start(void);
void Motor_Stop(void);
void Motor_GoForward(void);
void Motor_SetSpeed(Motor_Speed_t speed);

#endif