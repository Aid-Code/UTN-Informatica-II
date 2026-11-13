/*
 * Segmentos.h
 *
 *  Created on: 23 ago. 2024
 *      Author: chor
 */

#ifndef DISPLAY7SEGS_SEGMENTOS_H_
#define DISPLAY7SEGS_SEGMENTOS_H_

#include <gpio.h>
#include <LPC845.h>

class Segmentos {
protected:
	uint8_t cant_segs;
	gpio * segmentos;

public:
	Segmentos( gpio * s , uint8_t cant );
	Segmentos( const Segmentos & );
	~Segmentos();
	virtual void setValor( uint8_t ) = 0;

};

#endif /* DISPLAY7SEGS_SEGMENTOS_H_ */
