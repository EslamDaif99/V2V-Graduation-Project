
#ifndef INTPIN_H_
#define INTPIN_H_

void GPIOPortD_Handler(void);
void SpeedPinConfig(void(*func)(void));
void EnableSpeedInt(void);
void DisableSpeedInt(void);

#endif
