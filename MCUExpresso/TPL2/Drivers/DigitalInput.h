/*
 * DigitalInput.h
 *
 *  Created on: 12 jun. 2026
 *      Author: abril
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_
#include "gpio.h"
#include "PerifericoTemporizado.h"

class DigitalInput : public PerifericoTemporizado, public gpio
{
private:
	uint8_t buffer_key;
	const uint8_t cant = 5;
public:
	DigitalInput(uint8_t puerto, uint8_t pin, uint8_t act);

	void handler();
	bool getKey();

};

#endif /* DIGITALINPUT_H_ */
