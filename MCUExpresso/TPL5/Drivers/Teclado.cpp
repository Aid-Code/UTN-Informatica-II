/*
 * Teclado.cpp
 *
 *  Created on: 4 jul. 2025
 *      Author: chor
 */

#include "Teclado.h"

Teclado::Teclado()
{
	key = NO_KEY;
	contador = 0;
	tecla_anterior = NO_KEY;
}

uint8_t Teclado::getKey()
{
	uint8_t retorno = NO_KEY;

	if ( key != NO_KEY )
	{
		retorno = key;
		key = NO_KEY;
	}

	return retorno;
}

void Teclado::handler ( void )
{
}
