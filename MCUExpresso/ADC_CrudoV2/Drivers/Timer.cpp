/*
 * Timer.cpp
 *
 *  Created on: 11 jun. 2023
 *      Author: chor
 */

#include "Timer.h"


Timer::Timer ( uint32_t _tiempo , void (*_Handler) (void), bool _recargar)
{
	//Configuro el nuevo timer:
	recarga = _tiempo;
	Handler = _Handler;
	recargar = _recargar;

}

Timer::~Timer()
{
}

void Timer::start ()
{
	if ( recarga != 0 && Handler != nullptr )
		tiempo = recarga;
}

void Timer::start ( uint32_t time )
{
	if ( time != 0 && Handler != nullptr )
	{
		recarga = time;
		tiempo = time;
	}
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
		{
			Handler();
			if (recargar)
				tiempo = recarga;
		}
	}
}
