#include "Type.h"
#include "BITMATH.h"
#include "UART.h"
#include "tm4c123gh6pm.h"

void UART_Init(void)
{
	uint32_t delay;
    /* Baudrate 115200 , Stop 1 , No Paritiy , 8 Bits Data */
	/*clk of UART0*/
	SET_BIT(SYSCTL_RCGCUART_R,0)
	/*clk of Port A*/
	SET_BIT(SYSCTL_RCGCGPIO_R,0);
	/*Wait to ensure that clock had been enabled*/
    delay = 1;
	/*Enable alternative functions For PINA0 & PINA1*/
    SET_BIT(GPIO_PORTA_AFSEL_R,0);
    SET_BIT(GPIO_PORTA_AFSEL_R,1);
    /*Choose PINA0 & PINA1 as UART */
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
	/*Disable Analog Mode*/
	GPIO_PORTA_AMSEL_R = 0x00;
	/*PINA0 input and enabled*/
	CLR_BIT(GPIO_PORTA_DIR_R,0);
	SET_BIT(GPIO_PORTA_DEN_R,0);
	/*PINA1 output and enabled*/
	SET_BIT(GPIO_PORTA_DIR_R,1);
	SET_BIT(GPIO_PORTA_DEN_R,1);
	/*Disable UART*/
	CLR_BIT(UART0_CTL_R,0);
	/*Baud rate*/
	UART0_IBRD_R =8;    //16000000/(16*115200) =8.6805;
	UART0_FBRD_R =44;    //.6805*64+.5=44.05
	/*1 STOP bit*/
	CLR_BIT(UART0_LCRH_R,3);
	/*8 bit data*/
	SET_BIT(GPIO_PORTA_AFSEL_R,5);
	SET_BIT(GPIO_PORTA_AFSEL_R,6);
	/*Enable UART*/
	SET_BIT(UART0_CTL_R,0);

}

void UART_Tx(uint08_t byte)
{
	/*Wait for TXFF*/
	while(GET_BIT(UART0_FR_R,5)==1){};
	UART0_DR_R = byte;
}

uint08_t UART_Rx(uint08_t * bytePtr)
{
	/*Wait for RXFE*/
	while(GET_BIT(UART0_FR_R,4)==0){};
	* bytePtr = UART0_DR_R;
    return UART_RX_UNAVAILABLE;
}

void UART_Update(void)
{
    /* Send 'A' Every 1 Second */
    UART_Tx('A');
}
