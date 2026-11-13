/*
 * TecladoLineal.cpp
 *
 *  Created on: 2 jul. 2025
 *      Author: chor
 */

#include "TecladoLineal.h"


TecladoLineal::TecladoLineal( gpio * keys, uint8_t cant )
{
	teclas = new gpio[cant];
	for ( int i = 0 ; i < cant ; i++ )
		teclas[i] = keys[i];

	cant_teclas = cant;
	enabled = true;
}

TecladoLineal::~TecladoLineal()
{
	delete[] teclas;
}

uint8_t TecladoLineal::TecladoHw ( void )
{
	int i = 0;

	for ( ; i < cant_teclas ; i++ )
		if ( teclas[i].getPIN() )
			break;

	if ( i == cant_teclas )
		i = NO_KEY;

	return i;
}

