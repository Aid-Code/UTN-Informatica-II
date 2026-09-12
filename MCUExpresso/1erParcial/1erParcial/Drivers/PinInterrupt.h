/*
 * PinInterrupt.h
 *
 *  Created on: 3 jul. 2026
 *      Author: Aiden
 */

#ifndef PININTERRUPT_H_
#define PININTERRUPT_H_
#include <LPC845.h>

#define PINSEL_REG (*(uint32_t*(0x400AC000)))
#define CFG (*(uint32_t*(0x400AC000)))

class PinInterrupt
{
public:
	enum flancos { ASCENDENTE , DESCENDENTE , AMBOS , NINGUNO };
	uint32_t PINSEL[] = { 7 , 15 , 23 , 31 };
	uint32_t fuente[] = { 1 , 2 , 4 , 8 };
	PinInterrupt(uint8_t port, uint8_t _pin, void *h (void), flancos causa);
	~PinInterrupt();

private:
	uint8_t puerto;
	uint8_t pin;
	void *func (void);
	flancos flanco;

	static uint8_t index;
	static PinInterrupt** objeto_actual;
};

#endif /* PININTERRUPT_H_ */
