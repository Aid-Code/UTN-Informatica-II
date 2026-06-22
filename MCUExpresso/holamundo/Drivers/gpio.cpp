/*
 * gpio.cpp
 *
 *  Created on: 17 jun. 2026
 *      Author: abril
 */

#include "gpio.h"

gpio::gpio(uint8_t puerto, uint8_t _pin, uint8_t _dir, uint8_t actividad):port(puerto),direction(_dir),pin(_pin),actividad(act)
{
	if (puerto == 0)
		SYSCON->SYSAHBCLKCTRL0 |= (1<<SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT);
	else if (puerto == 1)
		SYSCON->SYSAHBCLKCTRL0 |= (1<<SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT);

	if (direction == SALIDA)
		GPIO->DIR[puerto] |= 1<<pin;
	else if (direction == ENTRADA)
		GPIO->DIR[puerto] &= ~(1<<pin);
}

void gpio::setPin()
{
	if (direction == SALIDA)
	{
		if (actividad == HIGH)
			GPIO->SET[puerto] |= 1<<pin;
		else if (actividad == LOW)
			GPIO->SET[puerto] &= ~(1<<pin);
	}
}

void gpio::writePin(uint8_t valor)
{
	if (direction == SALIDA)
	{
		if (valor == HIGH)
		{
			if (actividad == HIGH)
				GPIO->SET[puerto] |= 1<<pin;
			else if (actividad == LOW)
				GPIO->SET[puerto] &= ~(1<<pin);
		}
		else if (valor == LOW)
		{
			GPIO->CLR[puerto] |= 1<<pin;
		}

	}
}

uint8_t gpio::getPin()
{
	return ((GPIO->SET[puerto]) == actividad);
}
