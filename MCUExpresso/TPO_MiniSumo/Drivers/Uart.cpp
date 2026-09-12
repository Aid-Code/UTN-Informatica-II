/*
 * Uart.cpp
 *
 *  Created on: 11 sep. 2026
 *      Author: Franko Dona
 */

#include <Uart.h>

Uart::Uart(uint32_t _baudrate) {
	baudrate = _baudrate;
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 14); //Habilito el CLK del periférico

	SYSCON->PRESETCTRL0 &= ~(1<<14);
	SYSCON->PRESETCTRL0 |= (1<<14);

	SYSCON->SYSAHBCLKCTRL0 |= (1<<7);

	PINASSIGN0 &= ~(0x0000FFFFF);
	PINASSIGN0 = (25 << 0) | (24 << 8); //Configuro el pin P0.25 para la transmisión y el P0.24 para la recepción del puerto serie

	USART0->CFG = (0 << 0) //0 DISABLE 1 ENABLE
			| (1 << 2) //0=7 BITS 1=8 BITS 2=9 BITS
			| (0 << 4) //0=NO PARITY 2=PAR 3=IMPAR
			| (0 << 6) //0=1BITSTOP 1=2BITSTOP
			| (0 << 9) //0=NOFLOWCONTROL 1=FLOWCONTROL
			| (0 << 11); //0=ASINCRONICA 1=SINCRONICA

	USART0->INTENSET = (1 << 0); //CONFIGURO INTERRUPCION POR LLEGADA DE BYTE

	UART0CLKSEL = 0; //CLK = 30MHz
	USART0->BRG = (30000000 / baudrate * 16); //CONFIG FREQ

	ISER0 |= (1 << 3); //NVIC INTERRUPCION

	USART0->CFG |= 1; //HABILITO UART
}

