/*
 * arrayLeds.h
 *
 *  Created on: 28 jun. 2026
 *      Author: Aiden
 */

#ifndef ARRAYLEDS_H_
#define ARRAYLEDS_H_
#include "gpio.h"

class arrayLeds
{
private:
	gpio* leds;
	int cant_leds;

public:
	arrayLeds(gpio* gpios, int longitud);
	~arrayLeds();

	gpio operator [] (int pos);
};

// Sobrecarga de operadores para gpio
void operator = (estado stat);
bool operator == (estado stat);

#endif /* ARRAYLEDS_H_ */
