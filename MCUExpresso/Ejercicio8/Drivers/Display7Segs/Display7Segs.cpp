/*
 * Display7Segs.cpp
 *
 *  Created on: 25 jun. 2023
 *      Author: chor
 */

#include <Display7Segs.h>

Display7Segs::Display7Segs( uint8_t cant_digs, Segmentos *_segs , Habilitaciones *digs , uint32_t val_inicial )
{
	//Creo un vector dinámico para guardar el valor del display convertido a un vector:
	vector_digitos = new uint8_t[cant_digs];

	cant_digitos = cant_digs;

	segmentos = _segs;
	digitos = digs;

	valor = val_inicial;
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
	static uint8_t digito_actual = 0;

	//Cambio el digito actual para la proxima llamada a la funcion handler:
	digito_actual++;
	if ( digito_actual == cant_digitos )
		digito_actual = 0;

	//Pongo el valor que quiero mostrar en el buffer:
	segmentos->setValor( vector_digitos[digito_actual] );

	//Prendo el digito que corresponde:
	digitos->encenderSiguiente(digito_actual);
}
