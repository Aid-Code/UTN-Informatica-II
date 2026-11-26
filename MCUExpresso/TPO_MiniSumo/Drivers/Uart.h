/*
 * Uart.h
 *
 *  Created on: 10 sep. 2023
 *      Author: chor
 */

#ifndef UART_H_
#define UART_H_

#include <LPC845.h>
#include <bufferCirc.h>

#if defined (__cplusplus)
extern "C" {

void UART0_IRQHandler (void);
void UART1_IRQHandler (void);
void UART2_IRQHandler (void);
void UART3_IRQHandler (void);

}
#endif


class Uart {

	bufferCirc bufTx;
	bufferCirc bufRx;

	uint32_t baudrate;
	uint8_t n_uart;

	//Uso este puntero para apuntar a la uart que voy a configurar:
	USARTs * dir_uart;

public:

	static const int16_t NO_DATA = -1;

	//Por defecto el pin para transmision es el P025 y el de recepcion P0.24:
	Uart( uint8_t numUart = 0 , uint32_t baudR = 9600 , uint8_t pinTx = 25 , uint8_t pinRx = 24 );

	//Leer y configurar la velocidad de comunicacion:
	uint32_t getBaudR();
	void setBaudR ( uint32_t );

	//Transmitir o recibir un byte por el puerto
	void Transmitir ( uint8_t );
	void Transmitir ( uint8_t *, uint8_t );
	int16_t Recibir ();

	//Funcion que se invoca en el handler de las IRQ:
	void handlerIRQ ( void );

};

#endif /* UART_H_ */
