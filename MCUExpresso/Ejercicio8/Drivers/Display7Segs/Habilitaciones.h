/*
 * Habilitaciones.h
 *
 *  Created on: 23 ago. 2024
 *      Author: chor
 */

#ifndef DISPLAY7SEGS_HABILITACIONES_H_
#define DISPLAY7SEGS_HABILITACIONES_H_

#include <LPC845.h>
#include <gpio.h>

class Habilitaciones {

protected:
	gpio * habilitaciones;
	uint8_t cant_digitos;

public:
	Habilitaciones( gpio * h , uint8_t cantidad );
	Habilitaciones ( const Habilitaciones &);
	~Habilitaciones();
	virtual void encenderSiguiente (uint8_t ) = 0;

};

#endif /* DISPLAY7SEGS_HABILITACIONES_H_ */
