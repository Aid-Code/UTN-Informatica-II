/*
 * TecladoLineal.h
 *
 *  Created on: 2 jul. 2025
 *      Author: chor
 */

#ifndef TECLADOLINEAL_H_
#define TECLADOLINEAL_H_

#include <LPC845.h>
#include <gpio.h>
#include <Teclado.h>

class TecladoLineal : public Teclado {

	gpio *teclas;
	uint8_t cant_teclas;

	const uint8_t CANT_REBOTES = 5;

	uint8_t TecladoHw ( void );

public:

	TecladoLineal( gpio * , uint8_t );
	~TecladoLineal();

};

#endif /* TECLADOLINEAL_H_ */
