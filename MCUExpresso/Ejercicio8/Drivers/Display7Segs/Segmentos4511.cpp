/*
 * segmentosDirecto.cpp
 *
 *  Created on: 26 jun. 2023
 *      Author: chor
 */

#include "Segmentos4511.h"

void Segmentos4511::setValor( uint8_t val)
{
	for ( int i = 0 ; i < 4 ; i++ )
	{
		segmentos[i].setPIN( val & 0x01 );
		val >>= 1;
	}
}

