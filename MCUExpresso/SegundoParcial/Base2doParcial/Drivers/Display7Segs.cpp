/*
 * Display7Segs.cpp
 *
 *  Created on: 25 jun. 2023
 *      Author: chor
 */

#include <Display7Segs.h>

Display7Segs::Display7Segs( gpio *_segs , gpio * habs , gpio _dp, uint8_t cant , uint8_t val_inicial )
{
	dp = _dp;
	habilitaciones = new gpio[cant];
	for ( int i = 0 ; i < cant ; i++ )
		habilitaciones[i] = habs[i];

	segmentos = new gpio[7];
	for ( int i = 0 ; i < 7 ; i++ )
		segmentos[i] = _segs[i];

	cantDigitos = cant;
	digActual = 0;

	vectorDigitos = new uint8_t[cantDigitos];
	digGuion = new uint8_t[cantDigitos];

	for ( int i = 0 ; i < cantDigitos ; i++ )
		digGuion = 0;

}

void Display7Segs::encender (void)
{

}

void Display7Segs::apagar (void)
{

}

Display7Segs::~Display7Segs()
{
	delete[]segmentos;
	delete[]habilitaciones;
	delete[]vectorDigitos;
}




