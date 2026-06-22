/*
 * Cronometro.cpp
 *
 *  Created on: 3 abr. 2025
 *      Author: chor
 */

#include <Cronometro.h>


Cronometro::Cronometro() {

	tiempo = 0;
	contando = false;

}


void Cronometro::start()
{
	contando = true;
}

void Cronometro::stop()
{
	contando = false;
	tiempo = 0;
}

void Cronometro::pause()
{
	contando = false;
}

uint32_t Cronometro::getTime()
{
	return tiempo;
}

void Cronometro::handler(void)
{
	if ( contando )
		tiempo++;
}

