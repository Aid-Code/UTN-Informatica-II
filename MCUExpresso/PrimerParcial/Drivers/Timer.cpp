/*
 * Timer.cpp
 *
 *  Created on: 11 jun. 2023
 *      Author: chor
 */

#include "Timer.h"

uint8_t Timer::cant_timers = 0;
Timer **timers = nullptr;

Timer::Timer ( uint32_t _tiempo , void (*funcion) (void))
{
	//Configuro el nuevo timer:
	recarga = _tiempo;
	funcUsuario = funcion;

	//Lo agrego a la lista de timers:
	Timer **aux = new Timer*[cant_timers+1];
	for ( int i = 0 ; i < cant_timers ; i++ )
		aux[i] = timers[i];

	aux[cant_timers] = this;
	cant_timers++;

	//Borro la lista vieja y hago que la lista apunte al nuevo vector dinámico:
	delete[] timers;
	timers = aux;

}

Timer::~Timer()
{
	//Busco la posicion del timer en el listado de timers:
	int posicion;

	for ( posicion = 0 ; posicion < cant_timers ; posicion++ )
		if ( timers[posicion] == this )
			break;

	//Saco el timer de la lista de timers activos:
	Timer **aux = new Timer*[cant_timers-1];
	for ( int i = 0 ; i < posicion; i++ )
		aux[i] = timers[i];
	for ( int i = posicion + 1 ; i < cant_timers ; i++ )
		aux[i-1] = timers[i];

	delete[] timers;
	cant_timers--;
}

void Timer::start ()
{
	if ( recarga != 0 && funcUsuario != nullptr )
		tiempo = recarga;
}

void Timer::stop ()
{
	tiempo = 0;
}

void Timer::handler ( void )
{
	if ( tiempo != 0)
	{
		tiempo--;
		if ( !tiempo )
			funcUsuario();
	}
}

void Timer::setTiempo ( uint32_t t)
{
	recarga = t;
	if ( tiempo!= 0 )
		tiempo = t;
}

