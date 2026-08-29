/*
 * Cronometro.cpp
 *
 *  Created on: 3 jul. 2026
 *      Author: Aiden
 */

#include <Cronometro.h>

Cronometro::Cronometro(base_t _base):base(_base)
{
	tiempo = 0;
	encendido = false;
}

void Cronometro::handler (void)
{
	if (encendido) tiempo += (1 / base); // Cuenta en funcion de la base que se haya indicado
}

void Cronometro::start (void)
{
	encendido = true;
}

void Cronometro::stop (void)
{
	encendido = false;
	tiempo = 0;
}

void Cronometro::pause (void)
{
	encendido = false;
}

uint32_t Cronometro::getTiempo (void)
{
	return tiempo;
}

bool Cronometro::operator== (int val)
{
	return (tiempo == val);
}

bool Cronometro::operator< (int val)
{
	return (tiempo < val);
}

bool Cronometro::operator> (int val)
{
	return (tiempo > val);
}
