#include "config.h"
#include "Type.h"
#include "BITMATH.h"
#include "UART.h"
#include "tm4c123gh6pm.h"

#if (UART_SWC_STATUS == SWC_STATUS_ENABLE)

#endif

void UART_Init(void)
{
#if (UART_SWC_STATUS == SWC_STATUS_ENABLE)

	uint32_t delay;
    /* Baudrate 115200 , Stop 1 , No Paritiy , 8 Bits Data */
	/*clk of UART0*/
	SET_BIT(SYSCTL_RCGCUART_R,1);
	/*clk of Port A*/
	SET_BIT(SYSCTL_RCGCGPIO_R,1);
	/*Wait to ensure that clock had been enabled*/
    (void)(delay = 1);
	/*Enable alternative functions For PINA0 & PINA1*/
    SET_BIT(GPIO_PORTB_AFSEL_R,0);
    SET_BIT(GPIO_PORTB_AFSEL_R,1);
    /*Choose PINA0 & PINA1 as UART */
    GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;
	/*Disable Analog Mode*/
	GPIO_PORTB_AMSEL_R = 0x00;
	/*PINA0 input and enabled*/
	CLR_BIT(GPIO_PORTB_DIR_R,0);
	SET_BIT(GPIO_PORTB_DEN_R,0);
	/*PINA1 output and enabled*/
	SET_BIT(GPIO_PORTB_DIR_R,1);
	SET_BIT(GPIO_PORTB_DEN_R,1);
	/*Disable UART*/
	CLR_BIT(UART1_CTL_R,0);
	/*Baud rate*/
	UART1_IBRD_R =8;    //16000000/(16*115200) =8.6805;
	UART1_FBRD_R =44;    //.6805*64+.5=44.05
	/*1 STOP bit*/
	CLR_BIT(UART1_LCRH_R,3);
	/*8 bit data*/
	SET_BIT(UART1_LCRH_R,5);
	SET_BIT(UART1_LCRH_R,6);
	/*Enable UART*/
	SET_BIT(UART1_CTL_R,0);

#endif
}

void UART_Tx(uint08_t byte)
{
#if (UART_SWC_STATUS == SWC_STATUS_ENABLE)

	/*Wait for TXFF*/
	while(GET_BIT(UART1_FR_R,5)==1){};
	UART1_DR_R = byte;

#endif
}

uint08_t UART_Rx(uint08_t * bytePtr)
{
#if (UART_SWC_STATUS == SWC_STATUS_ENABLE)

	/*Wait for RXFE*/
	while(GET_BIT(UART1_FR_R,4)==0){};
	* bytePtr = UART1_DR_R;
    return UART_RX_UNAVAILABLE;

#endif
}

void UART_Update(void)
{
#if (UART_SWC_STATUS == SWC_STATUS_ENABLE)

    /* Send 'A' Every 1 Second */
    UART_Tx('A');

#endif
}
