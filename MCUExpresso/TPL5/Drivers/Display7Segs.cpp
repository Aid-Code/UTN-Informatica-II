/*
 * Display7Segs.cpp
 *
 *  Created on: 25 jun. 2023
 *      Author: chor
 */

#include <Display7Segs.h>

Display7Segs::Display7Segs(uint8_t cant_digs, gpio *segs , gpio *habs , uint32_t val_inicial)
{
	//Creo un vector dinámico para guardar el valor del display convertido a un vector:
	vector_digitos = new uint8_t[cant_digs];
	cant_digitos = cant_digs;

	//Creo en forma dinámica el vector de habilitaciones y copio miembro a miembro el vector de segmentos:
	for ( int i = 0 ; i < CANT_SEGMENTOS ; i++ )
		segmentos[i] = segs[i];

	habilitaciones = new gpio[cant_digs];
	for ( int i = 0 ; i < cant_digs ; i++ )
		habilitaciones[i] = habs[i];

	valor = val_inicial;
	digito_actual = 0;

	display (valor);
}

Display7Segs::~Display7Segs()
{
	delete[] habilitaciones;
	delete[] vector_digitos;
}


void Display7Segs::display ( uint32_t val )
{
	valor = val;

	//Convierto el valor a un vector:
	for ( int i = 0 ; i < cant_digitos ; i++ )
	{
		vector_digitos[cant_digitos - 1 -i] = val%10;
		val/=10;
	}
}

uint32_t Display7Segs::getValor ( void )
{
	return valor;
}

void Display7Segs::handler ( void )
{

}
