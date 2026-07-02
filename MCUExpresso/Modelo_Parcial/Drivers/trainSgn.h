/*
 * trainSgn.h
 *
 *  Created on: 1 jul. 2026
 *      Author: Aiden
 */

#ifndef TRAINSGN_H_
#define TRAINSGN_H_
#include "LPC845.h"

#define CFG (*((uint32_t*)0xA000F00C))
#define FRO 30000000
#define CLK_SRC_VAL (FRO/3000) // Utilizo el valor recomendado en el enunciado

class trainSgn
{
private:
	uint32_t frecuencia;
	uint8_t puerto;
	uint8_t pin;

public:
	trainSgn(uint32_t frec, uint8_t port, uint8_t _pin);

	void start(void);
	void stop(void);

	void operator = (uint32_t frec);
	bool operator == (uint32_t frec);
};

#endif /* TRAINSGN_H_ */
