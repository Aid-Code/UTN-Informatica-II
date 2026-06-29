/*
 * arrayLeds.cpp
 *
 *  Created on: 28 jun. 2026
 *      Author: Aiden
 */

#include <arrayLeds.h>

arrayLeds::arrayLeds(gpio* gpios, int longitud):cant_leds(longitud)
{
	leds = new gpio[longitud];

	for (int i = 0; i < longitud; i++)
	{
		leds[i] = gpios[i];
	}
}

arrayLeds::~arrayLeds()
{
	delete[] leds;
}

gpio arrayLeds::operator [] (int pos)
{
	return leds[pos];
}

//Sobrecarga de operadores para gpio:
void operator = (estado stat)
{
	setPIN(stat);
}

bool operator == (estado stat)
{
	if (stat == getPIN())
		return true;
	else return false;
}
