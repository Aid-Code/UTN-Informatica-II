/*
 * Display7Segs.h
 *
 *  Created on: 25 jun. 2023
 *      Author: chor
 */

#ifndef DISPLAY7SEGS_H_
#define DISPLAY7SEGS_H_

#include <LPC845.h>
#include <PerifericoTemporizado.h>
#include "Habilitaciones.h"
#include "Segmentos.h"


class Display7Segs : public PerifericoTemporizado {

private:

	Segmentos *segmentos;
	Habilitaciones *digitos;

	uint32_t valor;
	uint8_t cant_digitos;

	uint8_t *vector_digitos;

public:

	static uint8_t cant_displays;

	Display7Segs(uint8_t cant_digs, Segmentos *_segs , Habilitaciones *digs , uint32_t val_inicial = 0);

	void display ( uint32_t );
	uint32_t getValor ( void );

	void handler ( void );

};

#endif /* DISPLAY7SEGS_H_ */
