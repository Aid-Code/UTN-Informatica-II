/*
 * gpio.h
 *
 *  Created on: 17 jun. 2026
 *      Author: abril
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <LPC845.h>

class gpio
{
protected:
	uint8_t port;
	uint8_t direction;
	uint8_t pin;
	uint8_t actividad;

public:
	enum dir { ENTRADA = 0, SALIDA };
	enum activity {LOW = 0 , HIGH };

	gpio();
	gpio(uint8_t puerto, uint8_t _pin, uint8_t dir, uint8_t act);

	uint8_t getPin();
	void writePin(uint8_t valor);
	void setPin();
};

#endif /* GPIO_H_ */
