#include "Type.h"
#include "BITMATH.h"
#include "UART.h"
#include "tm4c123gh6pm.h"

void UART_Init(uint08_t  UART_t)
{
	uint32_t delay;
	/* Baudrate 115200 , Stop 1 , No Paritiy , 8 Bits Data */
	switch (UART_t)
	{
		case UART_0:
			/*clk of UART0*/
			SET_BIT(SYSCTL_RCGCUART_R,0);
			/*clk of Port A*/
			SET_BIT(SYSCTL_RCGCGPIO_R,0);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
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
			/*FIFO enable*/
			SET_BIT(UART0_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART0_LCRH_R,5);
			SET_BIT(UART0_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART0_CTL_R = 0x0301;
			break;

		case UART_1:
			/*clk of UART1*/
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
			break;

		case UART_2:
			/*clk of UART2*/
			SET_BIT(SYSCTL_RCGCUART_R,2);
			/*clk of Port D*/
			SET_BIT(SYSCTL_RCGCGPIO_R,3);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Enable alternative functions For PIND6 & PIND7*/
			SET_BIT(GPIO_PORTD_AFSEL_R,6);
			SET_BIT(GPIO_PORTD_AFSEL_R,7);
			/*Choose PIND6 & PIND7 as UART */
			GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x00FFFFFF)+0x11000000;
			/*Disable Analog Mode*/
			GPIO_PORTD_AMSEL_R = 0x00;
			/*PIND6 input and enabled*/
			CLR_BIT(GPIO_PORTD_DIR_R,6);
			SET_BIT(GPIO_PORTD_DEN_R,6);
			/*PIND7 output and enabled*/
			SET_BIT(GPIO_PORTD_DIR_R,7);
			SET_BIT(GPIO_PORTD_DEN_R,7);
			/*Disable UART*/
			CLR_BIT(UART2_CTL_R,0);
			/*Baud rate*/
			UART2_IBRD_R =8;    //16000000/(16*115200) =8.6805;
			UART2_FBRD_R =44;    //.6805*64+.5=44.05
			/*1 STOP bit*/
			CLR_BIT(UART2_LCRH_R,3);
			/*FIFO enable*/
			SET_BIT(UART2_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART2_LCRH_R,5);
			SET_BIT(UART2_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART2_CTL_R = 0x0301;
			break;

		case UART_3:
			/*clk of UART3*/
			SET_BIT(SYSCTL_RCGCUART_R,3);
			/*clk of Port C*/
			SET_BIT(SYSCTL_RCGCGPIO_R,2);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Enable alternative functions For PINC6 & PINC7*/
			SET_BIT(GPIO_PORTC_AFSEL_R,6);
			SET_BIT(GPIO_PORTC_AFSEL_R,7);
			/*Choose PINC6 & PINC7 as UART */
			GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0x00FFFFFF)+0x11000000;
			/*Disable Analog Mode*/
			GPIO_PORTC_AMSEL_R = 0x00;
			/*PINC6 input and enabled*/
			CLR_BIT(GPIO_PORTC_DIR_R,6);
			SET_BIT(GPIO_PORTC_DEN_R,6);
			/*PINC7 output and enabled*/
			SET_BIT(GPIO_PORTC_DIR_R,7);
			SET_BIT(GPIO_PORTC_DEN_R,7);
			/*Disable UART*/
			CLR_BIT(UART3_CTL_R,0);
			/*Baud rate*/
			UART3_IBRD_R =8;    //16000000/(16*115200) =8.6805;
			UART3_FBRD_R =44;    //.6805*64+.5=44.05
			/*1 STOP bit*/
			CLR_BIT(UART3_LCRH_R,3);
			/*FIFO enable*/
			SET_BIT(UART3_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART3_LCRH_R,5);
			SET_BIT(UART3_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART3_CTL_R = 0x0301;
			break;

		case UART_4:
			/*clk of UART4*/
			SET_BIT(SYSCTL_RCGCUART_R,4);
			/*clk of Port C*/
			SET_BIT(SYSCTL_RCGCGPIO_R,2);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Enable alternative functions For PINC4 & PINC5*/
			SET_BIT(GPIO_PORTC_AFSEL_R,4);
			SET_BIT(GPIO_PORTC_AFSEL_R,5);
			/*Choose PINC4 & PINC5 as UART */
			GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00110000;
			/*Disable Analog Mode*/
			GPIO_PORTC_AMSEL_R = 0x00;
			/*PINC4 input and enabled*/
			CLR_BIT(GPIO_PORTC_DIR_R,4);
			SET_BIT(GPIO_PORTC_DEN_R,4);
			/*PINC5 output and enabled*/
			SET_BIT(GPIO_PORTC_DIR_R,5);
			SET_BIT(GPIO_PORTC_DEN_R,5);
			/*Disable UART*/
			CLR_BIT(UART4_CTL_R,0);
			/*Baud rate*/
			UART4_IBRD_R =8;    //16000000/(16*115200) =8.6805;
			UART4_FBRD_R =44;    //.6805*64+.5=44.05
			/*1 STOP bit*/
			CLR_BIT(UART4_LCRH_R,3);
			/*FIFO enable*/
			SET_BIT(UART4_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART4_LCRH_R,5);
			SET_BIT(UART4_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART4_CTL_R = 0x0301;
			break;

		case UART_5:
			/*clk of UART5*/
			SET_BIT(SYSCTL_RCGCUART_R,5);
			/*clk of Port E*/
			SET_BIT(SYSCTL_RCGCGPIO_R,4);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Enable alternative functions For PINE4 & PINE5*/
			SET_BIT(GPIO_PORTE_AFSEL_R,4);
			SET_BIT(GPIO_PORTE_AFSEL_R,5);
			/*Choose PINE4 & PINE5 as UART */
			GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
			/*Disable Analog Mode*/
			GPIO_PORTE_AMSEL_R = 0x00;
			/*PINE4 input and enabled*/
			CLR_BIT(GPIO_PORTE_DIR_R,4);
			SET_BIT(GPIO_PORTE_DEN_R,4);
			/*PINE5 output and enabled*/
			SET_BIT(GPIO_PORTE_DIR_R,5);
			SET_BIT(GPIO_PORTE_DEN_R,5);
			/*Disable UART*/
			CLR_BIT(UART5_CTL_R,0);
			/*Baud rate*/
			UART5_IBRD_R =8;    //16000000/(16*115200) =8.6805;
			UART5_FBRD_R =44;    //.6805*64+.5=44.05
			/*1 STOP bit*/
			CLR_BIT(UART5_LCRH_R,3);
			/*FIFO enable*/
			SET_BIT(UART5_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART5_LCRH_R,5);
			SET_BIT(UART5_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART5_CTL_R = 0x0301;
			break;

		case UART_6:
			/*clk of UART6*/
			SET_BIT(SYSCTL_RCGCUART_R,6);
			/*clk of Port D*/
			SET_BIT(SYSCTL_RCGCGPIO_R,3);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Enable alternative functions For PIND4 & PIND5*/
			SET_BIT(GPIO_PORTD_AFSEL_R,4);
			SET_BIT(GPIO_PORTD_AFSEL_R,5);
			/*Choose PIND4 & PIND5 as UART */
			GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFF00FFFF)+0x00110000;
			/*Disable Analog Mode*/
			GPIO_PORTD_AMSEL_R = 0x00;
			/*PIND4 input and enabled*/
			CLR_BIT(GPIO_PORTD_DIR_R,4);
			SET_BIT(GPIO_PORTD_DEN_R,4);
			/*PIND5 output and enabled*/
			SET_BIT(GPIO_PORTD_DIR_R,5);
			SET_BIT(GPIO_PORTD_DEN_R,5);
			/*Disable UART*/
			CLR_BIT(UART6_CTL_R,0);
			/*Baud rate*/
			UART6_IBRD_R =8;    //16000000/(16*115200) =8.6805;
			UART6_FBRD_R =44;    //.6805*64+.5=44.05
			/*1 STOP bit*/
			CLR_BIT(UART6_LCRH_R,3);
			/*FIFO enable*/
			SET_BIT(UART6_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART6_LCRH_R,5);
			SET_BIT(UART6_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART6_CTL_R = 0x0301;
			break;

		case UART_7:
			/*clk of UART7*/
			SET_BIT(SYSCTL_RCGCUART_R,7);
			/*clk of Port E*/
			SET_BIT(SYSCTL_RCGCGPIO_R,4);
			/*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
			/*Enable alternative functions For PINE0 & PINE1*/
			SET_BIT(GPIO_PORTE_AFSEL_R,0);
			SET_BIT(GPIO_PORTE_AFSEL_R,1);
			/*Choose PINE0 & PINE1 as UART */
			GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFFFFFF00)+0x00000011;
			/*Disable Analog Mode*/
			GPIO_PORTE_AMSEL_R = 0x00;
			/*PINE0 input and enabled*/
			CLR_BIT(GPIO_PORTE_DIR_R,0);
			SET_BIT(GPIO_PORTE_DEN_R,0);
			/*PINe1 output and enabled*/
			SET_BIT(GPIO_PORTE_DIR_R,1);
			SET_BIT(GPIO_PORTE_DEN_R,1);
			/*Disable UART*/
			CLR_BIT(UART7_CTL_R,0);
			/*Baud rate*/
			UART7_IBRD_R =8;    //16000000/(16*115200) =8.6805;
			UART7_FBRD_R =44;    //.6805*64+.5=44.05
			/*1 STOP bit*/
			CLR_BIT(UART7_LCRH_R,3);
			/*FIFO enable*/
			SET_BIT(UART7_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART7_LCRH_R,5);
			SET_BIT(UART7_LCRH_R,6);
			/*Enable TXE & RXE & UART*/
			UART7_CTL_R = 0x0301;
			break;
	}
}

void UART_Tx(uint08_t byte,uint08_t  UART_t)
{
	switch (UART_t)
	{
		case UART_0:
			/*Wait for TXFF*/
			while(GET_BIT(UART0_FR_R,5)==1){};
			UART0_DR_R = byte;
			break;

		case UART_1:
			/*Wait for TXFF*/
			while(GET_BIT(UART1_FR_R,5)==1){};
			UART1_DR_R = byte;
			break;

		case UART_2:
			/*Wait for TXFF*/
			while(GET_BIT(UART2_FR_R,5)==1){};
			UART2_DR_R = byte;
			break;

		case UART_3:
			/*Wait for TXFF*/
			while(GET_BIT(UART3_FR_R,5)==1){};
			UART3_DR_R = byte;
			break;

		case UART_4:
			/*Wait for TXFF*/
			while(GET_BIT(UART4_FR_R,5)==1){};
			UART4_DR_R = byte;
			break;

		case UART_5:
			/*Wait for TXFF*/
			while(GET_BIT(UART5_FR_R,5)==1){};
			UART5_DR_R = byte;
			break;

		case UART_6:
			/*Wait for TXFF*/
			while(GET_BIT(UART6_FR_R,5)==1){};
			UART6_DR_R = byte;
			break;

		case UART_7:
			/*Wait for TXFF*/
			while(GET_BIT(UART7_FR_R,5)==1){};
			UART7_DR_R = byte;
			break;

	}

}

uint08_t UART_Rx(uint08_t * bytePtr , uint08_t  UART_t)
{

	switch (UART_t)
	{
		case UART_0:
			/*Wait for RXFE*/
			while(GET_BIT(UART0_FR_R,4)==0){};
			* bytePtr = UART0_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_1:
			/*Wait for RXFE*/
			while(GET_BIT(UART1_FR_R,4)==0){};
			* bytePtr = UART1_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_2:
			/*Wait for RXFE*/
			while(GET_BIT(UART2_FR_R,4)==0){};
			* bytePtr = UART2_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_3:
			/*Wait for RXFE*/
			while(GET_BIT(UART3_FR_R,4)==0){};
			* bytePtr = UART3_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_4:
			/*Wait for RXFE*/
			while(GET_BIT(UART4_FR_R,4)==0){};
			* bytePtr = UART4_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_5:
			/*Wait for RXFE*/
			while(GET_BIT(UART5_FR_R,4)==0){};
			* bytePtr = UART5_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_6:
			/*Wait for RXFE*/
			while(GET_BIT(UART6_FR_R,4)==0){};
			* bytePtr = UART6_DR_R;
			return UART_RX_UNAVAILABLE;
			break;

		case UART_7:
			/*Wait for RXFE*/
			while(GET_BIT(UART7_FR_R,4)==0){};
			* bytePtr = UART7_DR_R;
			return UART_RX_UNAVAILABLE;
			break;
	}

}

void UART_Update(void)
{
    /* Send 'A' Every 1 Second */
    UART_Tx('A');
}
