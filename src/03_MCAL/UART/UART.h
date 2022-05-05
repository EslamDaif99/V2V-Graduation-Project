#ifndef _UART_H_
#define _UART_H_

#define UART_RX_AVAILABLE           (0xAB)
#define UART_RX_UNAVAILABLE         (0xCD)

typedef enum
{
	/* List the UART*/
	UART_0,
	UART_1,
	UART_2,
	UART_3,
	UART_4,
	UART_5,
	UART_6,
	UART_7

}UART_t;
void UART_Init(uint08_t  UART_t);
void UART_Tx(uint08_t byte,uint08_t  UART_t);
uint08_t UART_Rx(uint08_t * bytePtr , uint08_t  UART_t);
void UART_Update(void);

#endif
