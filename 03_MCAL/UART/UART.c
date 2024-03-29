#include "Type.h"
#include "BITMATH.h"
#include "UART.h"
#include "tm4c123gh6pm.h"

void UART_Init(void)
{
	volatile uint32_t delay;
    /* Baudrate 115200 , Stop 1 , No Paritiy , 8 Bits Data */
	/*clk of UART0*/
	SET_BIT(SYSCTL_RCGCUART_R,1);
	/*clk of Port B*/
	SET_BIT(SYSCTL_RCGCGPIO_R,1);
	/*Wait to ensure that clock had been enabled*/
    (void)(delay = 1);
	/*Enable alternative functions For PINB0 & PINB1*/
    SET_BIT(GPIO_PORTB_AFSEL_R,0);
    SET_BIT(GPIO_PORTB_AFSEL_R,1);
    /*Choose PINB0 & PINB1 as UART */
    GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;
	/*Disable Analog Mode*/
	GPIO_PORTB_AMSEL_R = 0x00;
	/*PINB0 input and enabled*/
	CLR_BIT(GPIO_PORTB_DIR_R,0);
	SET_BIT(GPIO_PORTB_DEN_R,0);
	/*PINB1 output and enabled*/
	SET_BIT(GPIO_PORTB_DIR_R,1);
	SET_BIT(GPIO_PORTB_DEN_R,1);
	/*Disable UART*/
	CLR_BIT(UART1_CTL_R,0);
	/*Baud rate*/
	UART1_IBRD_R =8;    //16000000/(16*115200) =8.6805;
	UART1_FBRD_R =44;    //.6805*64+.5=44.05
	/*1 STOP bit*/
	CLR_BIT(UART1_LCRH_R,3);
	/*FIFO enable*/
	SET_BIT(UART1_LCRH_R,4);
	/*8 bit data*/
	SET_BIT(UART1_LCRH_R,5);
	SET_BIT(UART1_LCRH_R,6);
	/*Enable TXE & RXE & UART*/
	UART1_CTL_R = 0x0301;

}

uint08_t UART_Tx(uint08_t byte)
{
    uint08_t retVal = UART_TX_NOK;

	/*Check for TXFF*/

    if(GET_BIT(UART1_FR_R,5)== 0)
    {
        UART1_DR_R = byte;
        retVal = UART_TX_OK;
    }
    else
    {
        /* Do Nothing */
    }

    return retVal;
}

uint08_t UART_Rx(uint08_t * bytePtr)
{
    uint08_t retVal = UART_RX_UNAVAILABLE;

	/*Check for RXFE*/
    if(GET_BIT(UART1_FR_R,4)== 0)
    {
        * bytePtr = UART1_DR_R;
         retVal = UART_RX_AVAILABLE;
    }
    else
    {

    }

    return retVal;
}

void UART_Update(void)
{
    uint08_t data = 'A';
    /* Send 'A' Every 1 Second or Received Data */
    UART_Rx(&data);
    UART_Tx(data);
}
