#ifndef _UART_H_
#define _UART_H_

#define UART_RX_AVAILABLE           (0xAB)
#define UART_RX_UNAVAILABLE         (0xCD)
#define UART_TX_OK                  (0xEA)
#define UART_TX_NOK                 (0x9A)

void UART_Init(void);
uint08_t UART_Tx(uint08_t byte);
uint08_t UART_Rx(uint08_t * bytePtr);
void UART_Update(void);

#endif

