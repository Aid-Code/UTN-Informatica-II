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

#define		CERO	00111111
#define		UNO		00000110
#define		DOS		0
#define		TRES	01001111
#define		CUATRO	01100110
#define		CINCO	0
#define		SEIS	0
#define		SIETE	0
#define		OCHO	0
#define		NUEVE	0
#define		GUION	0

class Display7Segs : public PerifericoTemporizado {

private:

	uint8_t cantDigitos;

	uint8_t digActual;

	gpio *segmentos;
	gpio *habilitaciones;
	gpio dp;

	uint32_t valor;

	const uint8_t TablaConversion[10] = {CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,OCHO,NUEVE};

	uint8_t *vectorDigitos;
	uint8_t *digGuion;

public:

	Display7Segs( gpio *segs , gpio * habs , gpio _dp , uint8_t cant, uint8_t val_inicial = 0);
	~Display7Segs();

	void encender (void);
	void apagar (void);

};

#endif /* DISPLAY7SEGS_H_ */
