/*
 * Segmentos.cpp
 *
 *  Created on: 15 jul. 2026
 *      Author: jesco
 */

#include <Segmentos.h>

Segmentos::Segmentos( gpio * s , uint8_t cant )
{
	segmentos = new gpio[cant];

	for ( int i = 0 ; i < cant ; i++ )
		segmentos[i] = s[i];

	cant_segs = cant;
}

Segmentos::Segmentos( const Segmentos & s)
{
	segmentos = new gpio[s.cant_segs];

	for ( int i = 0 ; i < s.cant_segs ; i++ )
		segmentos[i] = s.segmentos[i];

	cant_segs = s.cant_segs;
}

Segmentos::~Segmentos()
{
	delete[] segmentos;
}



