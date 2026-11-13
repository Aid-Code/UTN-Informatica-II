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
	static const int16_t NO_DATA = -1;

	uint32_t baudrate; uint16_t *buffTx; uint8_t cantBytes; uint8_t indiceTx; bool enviando;
	Uart(uint32_t baudrate);
	void Transmitir(uint8_t *buff, uint8_t cant);
	int16_t Recibir(void);
	void UARThandlerIRQ (void);
	uint8_t byteRx;
	bool datoNuevo;
};

#endif /* UART_H_ */
