#include "Type.h"
#include "UART.h"

void UART_Init(void)
{
    /* Baudrate 115200 , Stop 1 , No Paritiy , 8 Bits Data */ 
}

void UART_Tx(uint08_t byte)
{

}

uint08_t UART_Rx(uint08_t * bytePtr)
{
    return UART_RX_UNAVAILABLE;
}

void UART_Update(void)
{
    /* Send 'A' Every 1 Second */
    UART_Tx('A');
}