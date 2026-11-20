/*
 * Display7Segs.h
 *
 *  Created on: 25 jun. 2023
 *      Author: chor
 */

#ifndef DISPLAY7SEGS_H_
#define DISPLAY7SEGS_H_

#include <LPC845.h>
#include <gpio.h>
#include <PerifericoTemporizado.h>

#define		CERO	0x3f
#define		UNO		0x06
#define		DOS		0x5b
#define		TRES	0x4f
#define		CUATRO	0x66
#define		CINCO	0x6d
#define		SEIS	0x7d
#define		SIETE	0x07
#define		OCHO	0x7f
#define		NUEVE	0x67
#define		GUION	0x40

class Display7Segs : public PerifericoTemporizado {

private:

	bool encendido;
	uint8_t cantDigitos;

	uint8_t digActual;

	gpio *segmentos;
	gpio *habilitaciones;

	uint32_t valor;

	const uint8_t TablaConversion[11] = {CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,OCHO,NUEVE,GUION};

	uint8_t *vectorDigitos;
	uint8_t *digGuion;

public:

	Display7Segs( gpio *segs , gpio * habs , uint8_t cant, uint8_t val_inicial = 0);
	~Display7Segs();

	void setDisplay ( uint32_t );
	void handler ( void );
	void mostrarGuion ( uint8_t );
	void mostrarDigito ( uint8_t );

};

#endif /* DISPLAY7SEGS_H_ */
