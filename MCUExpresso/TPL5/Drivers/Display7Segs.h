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
#include <gpio.h>

//CANT_SEGMENTOS vale 7 si uso el display en forma directa o 4 si uso el CD4511
#define CANT_SEGMENTOS	4

class Display7Segs : public PerifericoTemporizado {

private:

	gpio segmentos[CANT_SEGMENTOS];
	gpio * habilitaciones;

	uint32_t valor;
	uint8_t cant_digitos;

	uint8_t *vector_digitos;

	uint8_t digito_actual;


public:

	Display7Segs(uint8_t cant_digs, gpio *segs , gpio *habs , uint32_t val_inicial = 0);
	~Display7Segs();

	void display ( uint32_t );
	uint32_t getValor ( void );

	void handler ( void );

};

#endif /* DISPLAY7SEGS_H_ */
