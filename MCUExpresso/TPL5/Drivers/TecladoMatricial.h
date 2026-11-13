/*
 * TecladoMatricial.h
 *
 *  Created on: 2 jul. 2025
 *      Author: chor
 */

#ifndef TECLADOMATRICIAL_H_
#define TECLADOMATRICIAL_H_

#include <LPC845.h>
#include <Teclado.h>
#include <gpio.h>

class TecladoMatricial : public Teclado {

	gpio * columnas;
	uint8_t cant_columnas;
	gpio * filas;
	uint8_t cant_filas;

	uint8_t TecladoHw ( void );

public:

	TecladoMatricial( gpio * , uint8_t , gpio * , uint8_t );
	~TecladoMatricial();
};

#endif /* TECLADOMATRICIAL_H_ */
