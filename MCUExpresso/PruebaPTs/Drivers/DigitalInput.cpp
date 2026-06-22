/*
 * DigitalInput.cpp
 *
 *  Created on: 12 jun. 2026
 *      Author: Aiden
 */

#include "DigitalInput.h"

DigitalInput::DigitalInput(uint8_t puerto, uint8_t pin, uint8_t act = HIGH):PerifericoTemporizado(), gpio(puerto, pin, ENTRADA,act)
{
	buffer_key = 0;
}

void DigitalInput::handler()
{
	bool estado;
	static uint8_t estado_ant = 1;
	static uint8_t contador = 0;

	estado = getPIN();

	if (estado == true && contador < cant)
	{
		contador++;
		if (contador == cant)
			buffer_key = estado;
	}

	if (estado != estado_ant)
		contador = 0;

	estado_ant = estado;
}

bool DigitalInput::getKey()
{
	if (buffer_key)
	{
		buffer_key = 0;
		return true;
	}

	return false;
}
