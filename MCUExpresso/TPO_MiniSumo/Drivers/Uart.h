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
	uint32_t baudrate;
	Uart(uint32_t baudrate);
};

#endif /* UART_H_ */
