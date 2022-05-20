#ifndef SPEED_H_
#define SPEED_H_


extern uint16_t Counts;

void Speed_Init(void);
void SpeedAction(void);
void Speed_Update(void);
uint16_t  Speed_GetValue(void);

#endif /* SPEED_H_ */
