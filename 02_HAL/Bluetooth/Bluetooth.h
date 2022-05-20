/*
 * Bluetooth.h
 *
 *  Created on: May 20, 2022
 *      Author: MARIEM
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_


void Bluetooth_Init(void); // Initialize UART5 module for HC-05
char Bluetooth_Read(void); //Read data from Rx5 pin of TM4C123
void Bluetooth_Control(char data);

#endif /* BLUETOOTH_H_ */
