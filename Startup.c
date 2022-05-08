#ifndef _STARTUP_H_
#define _STARTUP_H_


typedef unsigned long int uint32_t;

#define SRAM_START		0x20000000U
#define SRAM_SIZE		(32 * 1024U) /* 32K */
#define SRAM_END		((SRAM_START) + (SRAM_SIZE))

#define STACK_START	SRAM_END
#define RESERVED				((uint32_t)0x00)

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void _start(void);
int main(void);


void Default_Handler								(void) __attribute__((weak)) ;
void Reset_Handler									(void);
void NMI_Handler									(void) __attribute__ ((weak, alias ("Default_Handler")));
void HardFault_Handler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void MemManage_Handler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void BusFault_Handler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UsageFault_Handler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void SVC_Handler									(void) __attribute__ ((weak, alias ("Default_Handler")));
void DebugMon_Handler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void PendSV_Handler									(void) __attribute__ ((weak, alias ("Default_Handler")));
void SysTick_Handler								(void) __attribute__ ((weak, alias ("Default_Handler")));
/* ********************** IRQs ********************** */
void GPIO_A_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void GPIO_B_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void GPIO_C_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void GPIO_D_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void GPIO_E_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART0_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART1_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void SSI0_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C0_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM0_Fault_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM0_Generator0_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM0_Generator1_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM0_Generator2_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void QEI0_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC0_Sequence0_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC0_Sequence1_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC0_Sequence2_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC0_Sequence3_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void WWDG0n1_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR0A_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR0B_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR1A_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR1B_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR2A_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR2B_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void AnalogComparator0_IRQHandler					(void) __attribute__ ((weak, alias ("Default_Handler")));
void AnalogComparator1_IRQHandler					(void) __attribute__ ((weak, alias ("Default_Handler")));
void SysControl_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void FlashEEPROMControl_IRQHandler					(void) __attribute__ ((weak, alias ("Default_Handler")));
void GPIO_F_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART2_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void SSI1_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR3A_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR3B_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void QEI1_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void CAN0_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void CAN1_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void Hibernation_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void USB_IRQHandler								    (void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM_Generator3_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void uDMA_SW_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void uDMA_Error_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC1_Sequence0_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC1_Sequence1_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC1_Sequence2_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC1_Sequence3_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void SSI2_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void SSI3_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART3_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART4_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART5_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART6_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART7_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C3_IRQHandler								(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR4A_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR4B_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR5A_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR5B_16n32_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR0A_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR0B_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR1A_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR1B_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR2A_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR2B_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR3A_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR3B_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR4A_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR4B_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR5A_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void TMR5B_32n64_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));
void SysException_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM1_Generator0_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM1_Generator1_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM1_Generator2_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM1_Generator3_IRQHandler						(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM1_Fault_IRQHandler							(void) __attribute__ ((weak, alias ("Default_Handler")));


uint32_t vectorTable[] __attribute__ ((section (".isr_vector"))) =
{
		STACK_START, 										/* ** [000] ** */
		(uint32_t)Reset_Handler, 							/* ** [001] ** */
		(uint32_t)NMI_Handler, 								/* ** [002] ** */
		(uint32_t)HardFault_Handler, 						/* ** [003] ** */
		(uint32_t)MemManage_Handler,						/* ** [004] ** */
		(uint32_t)BusFault_Handler,							/* ** [005] ** */
		(uint32_t)UsageFault_Handler,						/* ** [006] ** */
		RESERVED,											/* ** [007] ** */
		RESERVED,											/* ** [008] ** */
		RESERVED,											/* ** [009] ** */
		RESERVED,											/* ** [010] ** */
		(uint32_t)SVC_Handler,								/* ** [011] ** */
		(uint32_t)DebugMon_Handler,							/* ** [012] ** */
		RESERVED,											/* ** [013] ** */
		(uint32_t)PendSV_Handler,							/* ** [014] ** */
		(uint32_t)SysTick_Handler,							/* ** [015] ** */
		(uint32_t)GPIO_A_IRQHandler,						/* ** [016] ** */
		(uint32_t)GPIO_B_IRQHandler,						/* ** [017] ** */
		(uint32_t)GPIO_C_IRQHandler,						/* ** [018] ** */
		(uint32_t)GPIO_D_IRQHandler,						/* ** [019] ** */
		(uint32_t)GPIO_E_IRQHandler,						/* ** [020] ** */
		(uint32_t)UART0_IRQHandler,							/* ** [021] ** */
		(uint32_t)UART1_IRQHandler,							/* ** [022] ** */
		(uint32_t)SSI0_IRQHandler,							/* ** [023] ** */
		(uint32_t)I2C0_IRQHandler,							/* ** [024] ** */
		(uint32_t)PWM0_Fault_IRQHandler,					/* ** [025] ** */
		(uint32_t)PWM0_Generator0_IRQHandler,				/* ** [026] ** */
		(uint32_t)PWM0_Generator1_IRQHandler,				/* ** [027] ** */
		(uint32_t)PWM0_Generator2_IRQHandler,				/* ** [028] ** */
		(uint32_t)QEI0_IRQHandler,							/* ** [029] ** */
		(uint32_t)ADC0_Sequence0_IRQHandler,				/* ** [030] ** */
		(uint32_t)ADC0_Sequence1_IRQHandler,				/* ** [031] ** */
		(uint32_t)ADC0_Sequence2_IRQHandler,				/* ** [032] ** */
		(uint32_t)ADC0_Sequence3_IRQHandler,				/* ** [033] ** */
		(uint32_t)WWDG0n1_IRQHandler,						/* ** [034] ** */
		(uint32_t)TMR0A_16n32_IRQHandler,					/* ** [035] ** */
		(uint32_t)TMR0B_16n32_IRQHandler,					/* ** [036] ** */
		(uint32_t)TMR1A_16n32_IRQHandler,					/* ** [037] ** */
		(uint32_t)TMR1B_16n32_IRQHandler,					/* ** [038] ** */
		(uint32_t)TMR2A_16n32_IRQHandler,					/* ** [039] ** */
		(uint32_t)TMR2B_16n32_IRQHandler,					/* ** [040] ** */
		(uint32_t)AnalogComparator0_IRQHandler,				/* ** [041] ** */
		(uint32_t)AnalogComparator1_IRQHandler,				/* ** [042] ** */
		(uint32_t)RESERVED,									/* ** [043] ** */
		(uint32_t)SysControl_IRQHandler,					/* ** [044] ** */
		(uint32_t)FlashEEPROMControl_IRQHandler,			/* ** [045] ** */
		(uint32_t)GPIO_F_IRQHandler,						/* ** [046] ** */
		(uint32_t)RESERVED,									/* ** [047] ** */
		(uint32_t)RESERVED,									/* ** [048] ** */
		(uint32_t)UART2_IRQHandler,							/* ** [049] ** */
		(uint32_t)SSI1_IRQHandler,							/* ** [050] ** */
		(uint32_t)TMR3A_16n32_IRQHandler,					/* ** [051] ** */
		(uint32_t)TMR3B_16n32_IRQHandler,					/* ** [052] ** */
		(uint32_t)I2C1_IRQHandler,							/* ** [053] ** */
		(uint32_t)QEI1_IRQHandler,							/* ** [054] ** */
		(uint32_t)CAN0_IRQHandler,							/* ** [055] ** */
		(uint32_t)CAN1_IRQHandler,							/* ** [056] ** */
		(uint32_t)RESERVED,									/* ** [057] ** */
		(uint32_t)RESERVED,									/* ** [058] ** */
		(uint32_t)Hibernation_IRQHandler,					/* ** [059] ** */
		(uint32_t)USB_IRQHandler,							/* ** [060] ** */
		(uint32_t)PWM_Generator3_IRQHandler,				/* ** [061] ** */
		(uint32_t)uDMA_SW_IRQHandler,						/* ** [062] ** */
		(uint32_t)uDMA_Error_IRQHandler,					/* ** [063] ** */
		(uint32_t)ADC1_Sequence0_IRQHandler,				/* ** [064] ** */
		(uint32_t)ADC1_Sequence1_IRQHandler,				/* ** [065] ** */
		(uint32_t)ADC1_Sequence2_IRQHandler,				/* ** [066] ** */
		(uint32_t)ADC1_Sequence3_IRQHandler,				/* ** [067] ** */
		(uint32_t)RESERVED,									/* ** [068] ** */
		(uint32_t)RESERVED,									/* ** [069] ** */
		(uint32_t)RESERVED,									/* ** [070] ** */
		(uint32_t)RESERVED,									/* ** [071] ** */
		(uint32_t)RESERVED,									/* ** [072] ** */
		(uint32_t)SSI2_IRQHandler,							/* ** [073] ** */
		(uint32_t)SSI3_IRQHandler,							/* ** [074] ** */
		(uint32_t)UART3_IRQHandler,							/* ** [075] ** */
		(uint32_t)UART4_IRQHandler,							/* ** [076] ** */
		(uint32_t)UART5_IRQHandler,							/* ** [077] ** */
		(uint32_t)UART6_IRQHandler,							/* ** [078] ** */
		(uint32_t)UART7_IRQHandler,							/* ** [079] ** */
		(uint32_t)RESERVED,									/* ** [080] ** */
		(uint32_t)RESERVED,									/* ** [081] ** */
		(uint32_t)RESERVED,									/* ** [082] ** */
		(uint32_t)RESERVED,									/* ** [083] ** */
		(uint32_t)I2C2_IRQHandler,							/* ** [084] ** */
		(uint32_t)I2C3_IRQHandler,							/* ** [085] ** */
		(uint32_t)TMR4A_16n32_IRQHandler,					/* ** [086] ** */
		(uint32_t)TMR4B_16n32_IRQHandler,					/* ** [087] ** */
		(uint32_t)RESERVED,									/* ** [088] ** */
		(uint32_t)RESERVED,									/* ** [089] ** */
		(uint32_t)RESERVED,									/* ** [090] ** */
		(uint32_t)RESERVED,									/* ** [091] ** */
		(uint32_t)RESERVED,									/* ** [092] ** */
		(uint32_t)RESERVED,									/* ** [093] ** */
		(uint32_t)RESERVED,									/* ** [094] ** */
		(uint32_t)RESERVED,									/* ** [095] ** */
		(uint32_t)RESERVED,									/* ** [096] ** */
		(uint32_t)RESERVED,									/* ** [097] ** */
		(uint32_t)RESERVED,									/* ** [098] ** */
		(uint32_t)RESERVED,									/* ** [099] ** */
		(uint32_t)RESERVED,									/* ** [100] ** */
		(uint32_t)RESERVED,									/* ** [101] ** */
		(uint32_t)RESERVED,									/* ** [102] ** */
		(uint32_t)RESERVED,									/* ** [103] ** */
		(uint32_t)RESERVED,									/* ** [104] ** */
		(uint32_t)RESERVED,									/* ** [105] ** */
		(uint32_t)RESERVED,									/* ** [106] ** */
		(uint32_t)RESERVED,									/* ** [107] ** */
		(uint32_t)TMR5A_16n32_IRQHandler,					/* ** [108] ** */
		(uint32_t)TMR5B_16n32_IRQHandler,					/* ** [109] ** */
		(uint32_t)TMR0A_32n64_IRQHandler,					/* ** [110] ** */
		(uint32_t)TMR0B_32n64_IRQHandler,					/* ** [111] ** */
		(uint32_t)TMR1A_32n64_IRQHandler,					/* ** [112] ** */
		(uint32_t)TMR1B_32n64_IRQHandler,					/* ** [113] ** */
		(uint32_t)TMR2A_32n64_IRQHandler,					/* ** [114] ** */
		(uint32_t)TMR2B_32n64_IRQHandler,					/* ** [115] ** */
		(uint32_t)TMR3A_32n64_IRQHandler,					/* ** [116] ** */
		(uint32_t)TMR3B_32n64_IRQHandler,					/* ** [117] ** */
		(uint32_t)TMR4A_32n64_IRQHandler,					/* ** [118] ** */
		(uint32_t)TMR4B_32n64_IRQHandler,					/* ** [119] ** */
		(uint32_t)TMR5A_32n64_IRQHandler,					/* ** [120] ** */
		(uint32_t)TMR5B_32n64_IRQHandler,					/* ** [121] ** */
		(uint32_t)SysException_IRQHandler,					/* ** [122] ** */
		(uint32_t)RESERVED,									/* ** [123] ** */
		(uint32_t)RESERVED,									/* ** [124] ** */
		(uint32_t)RESERVED,									/* ** [125] ** */
		(uint32_t)RESERVED,									/* ** [126] ** */
		(uint32_t)RESERVED,									/* ** [127] ** */
		(uint32_t)RESERVED,									/* ** [128] ** */
		(uint32_t)RESERVED,									/* ** [129] ** */
		(uint32_t)RESERVED,									/* ** [130] ** */
		(uint32_t)RESERVED,									/* ** [131] ** */
		(uint32_t)RESERVED,									/* ** [132] ** */
		(uint32_t)RESERVED,									/* ** [133] ** */
		(uint32_t)RESERVED,									/* ** [134] ** */
		(uint32_t)RESERVED,									/* ** [135] ** */
		(uint32_t)RESERVED,									/* ** [136] ** */
		(uint32_t)RESERVED,									/* ** [137] ** */
		(uint32_t)RESERVED,									/* ** [138] ** */
		(uint32_t)RESERVED,									/* ** [139] ** */
		(uint32_t)RESERVED,									/* ** [140] ** */
		(uint32_t)RESERVED,									/* ** [141] ** */
		(uint32_t)RESERVED,									/* ** [142] ** */
		(uint32_t)RESERVED,									/* ** [143] ** */
		(uint32_t)RESERVED,									/* ** [144] ** */
		(uint32_t)RESERVED,									/* ** [145] ** */
		(uint32_t)RESERVED,									/* ** [146] ** */
		(uint32_t)RESERVED,									/* ** [147] ** */
		(uint32_t)RESERVED,									/* ** [148] ** */
		(uint32_t)RESERVED,									/* ** [149] ** */
		(uint32_t)PWM1_Generator0_IRQHandler,				/* ** [150] ** */
		(uint32_t)PWM1_Generator1_IRQHandler,				/* ** [151] ** */
		(uint32_t)PWM1_Generator2_IRQHandler,				/* ** [152] ** */
		(uint32_t)PWM1_Generator3_IRQHandler,				/* ** [153] ** */
		(uint32_t)PWM1_Fault_IRQHandler,					/* ** [154] ** */
};

void _start(void)
{
	/* Move .data section from flash to ram */
	uint32_t size = (uint32_t) &_edata - (uint32_t) &_sdata;
	unsigned char * Pdst = (unsigned char *)(&_sdata); /* SRAM */
	unsigned char * Psrc = (unsigned char *)(&_etext); /* FLASH */

	uint32_t i = 0;
	for( i = 0; i < size; i++)
	{
		*Pdst++ = *Psrc++;
	}
	/* Initialize .bss section with zero values */

	size = (uint32_t) &_ebss - (uint32_t) &_sbss;
	Pdst = (unsigned char *)(&_sbss); /* SRAM */

	for( i = 0; i < size; i++)
	{
		*Pdst++ = 0;
	}

	/* call main() function */

	main();

	/* Shutdown Sequence*/
	while(1);
}

void Default_Handler(void)
{
	while (1);

}

void Reset_Handler(void)
{
	_start();
}

#endif

