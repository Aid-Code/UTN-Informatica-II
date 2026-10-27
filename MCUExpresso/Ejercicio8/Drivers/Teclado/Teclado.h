/*
 * Teclado.h
 *
 *  Created on: 4 jul. 2025
 *      Author: chor
 */

#ifndef TECLADO_TECLADO_H_
#define TECLADO_TECLADO_H_

#include <LPC845.h>
#include <PerifericoTemporizado.h>

class Teclado : public PerifericoTemporizado {

	uint8_t key;
	uint8_t contador;
	uint8_t tecla_anterior;

	const uint8_t CANT_REBOTES = 5;

	virtual uint8_t TecladoHw ( void ) = 0;
protected:
	bool enabled;

public:

	const uint8_t NO_KEY = 255;

	Teclado();

	uint8_t getKey();
	void handler ( void );
};

#endif /* TECLADO_TECLADO_H_ */
