/*
 * PinInterrupt.h
 *
 *  Created on: 25 ago. 2026
 *      Author: abril
 */

#ifndef PININTERRUPT_H_
#define PININTERRUPT_H_
#include <LPC845.h>

#define PINSEL (*(uint32_t *) (0x400AC000))
#define CFG (*(uint32_t *) (0x400AC004))

class PinInterrupt
{
public:
	enum flancos {ASCENDENTE, DESCENDENTE, AMBOS, NINGUNO};
	PinInterrupt(uint8_t _port, uint8_t _pin, flancos _causa, void (*h) (void));

private:
	uint8_t port;
	uint8_t pin;
	flancos causa;

	void *func (void);
};

extern PinInterrupt *objeto_actual[4];

#endif /* PININTERRUPT_H_ */
