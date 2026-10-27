/*
 * Cronometro.cpp
 *
 *  Created on: 25 ago. 2026
 *      Author: abril
 */

#include <Cronometro.h>

Cronometro::Cronometro(base_t _base):base(_base)
{
	tiempo = 0;
	encendido = false;
}

void Cronometro::handler (void)
{
	if (encendido) tiempo++;
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
	return (uint32_t) (tiempo / base);
}

bool Cronometro::operator== (uint32_t _tiempo)
{
	return (_tiempo == (tiempo/base));
}

bool Cronometro::operator> (uint32_t _tiempo)
{
	return (_tiempo > (tiempo/base));
}

bool Cronometro::operator< (uint32_t _tiempo)
{
	return (_tiempo < (tiempo/base));
}
