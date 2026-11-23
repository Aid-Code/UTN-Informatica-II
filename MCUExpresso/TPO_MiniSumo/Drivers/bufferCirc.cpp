/*
 * bufferCirc.cpp
 *
 *  Created on: 2 oct. 2023
 *      Author: chor
 */

#include <bufferCirc.h>


bufferCirc::bufferCirc ( uint8_t cant_bytes )
{
	tam = cant_bytes;
	in = 0;
	out = 0;
	lleno = false;
	buffer = new uint8_t [tam];

}

void bufferCirc::push ( uint8_t dato )
{
	if ( ! lleno )
	{
		buffer[in] = dato;
		in++;
		in%= tam;

		if ( in == out )
			lleno = true;
	}
}

int16_t bufferCirc::pop ( void )
{
	int16_t retorno = NO_DATA;

	if ( (in != out) || lleno )
	{
		retorno = buffer[out];
		out++;
		out %= tam;
	}

	lleno = false;

	return retorno;
}

bool bufferCirc::hayLugar()
{
	return !lleno;
}
