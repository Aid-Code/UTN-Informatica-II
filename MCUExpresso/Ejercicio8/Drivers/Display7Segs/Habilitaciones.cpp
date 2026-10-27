/*
 * Habilitaciones.cpp
 *
 *  Created on: 15 jul. 2026
 *      Author: jesco
 */

#include <Habilitaciones.h>

Habilitaciones::Habilitaciones(	gpio * h , uint8_t cantidad )
{
	habilitaciones = new gpio[cantidad];

	for ( int i = 0 ; i < cantidad ; i++ )
		habilitaciones[i] = h[i];

	cant_digitos = cantidad;
}

Habilitaciones::Habilitaciones ( const Habilitaciones & h)
{
	habilitaciones = new gpio[h.cant_digitos];

	for ( int i = 0 ; i < h.cant_digitos ; i++ )
		habilitaciones[i] = h.habilitaciones[i];

	cant_digitos = h.cant_digitos;
}


Habilitaciones::~Habilitaciones()
{
	delete[] habilitaciones;
}
