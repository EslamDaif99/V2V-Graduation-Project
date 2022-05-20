#include "Type.h"
#include "COM.h"
#include "Speed.h"
#include "UART.h"


void COM_Init(void)
{
    /*Do Nothing*/
}
void COM_Update(void)
{
    uint16_t SpeedVal;
    uint08_t bytes[2];
    SpeedVal = Speed_GetValue();
    /*MSB*/
    bytes[0] = SpeedVal >> 8;
    UART_Tx(bytes[0]);
    /*LSB*/
    bytes[1] = SpeedVal & 0xFF;
    UART_Tx(bytes[1]);

   // number = (bytes[0] << 8) + bytes[1]; Function of RX
}
