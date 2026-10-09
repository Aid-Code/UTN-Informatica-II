/*
 * Uart.h
 *
 *  Created on: 11 sep. 2026
 *      Author: Franko Dona
 */

#ifndef UART_H_
#define UART_H_
#include <LPC845.h>

class Uart {
public:
	uint32_t baudrate; uint16_t buffTx; uint8_t cantBytes; uint8_t indiceTx; bool enviando;
	Uart(uint32_t baudrate);
	void Transmitir(uint8_t *buff, uint8_t cant);
	void UARThandlerIRQ (void);
};

#endif /* UART_H_ */
