/*
 * Display7Segs.cpp
 *
 *  Created on: 25 jun. 2023
 *      Author: chor
 */

#include <Display7Segs.h>

Display7Segs::Display7Segs( gpio *_segs , gpio * habs , uint8_t cant , uint8_t val_inicial ):encendido(false),cantDigitos(0)
{
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

Display7Segs::~Display7Segs()
{
	delete[]segmentos;
	delete[]habilitaciones;
	delete[]vectorDigitos;
}

void Display7Segs::setDisplay ( uint32_t nro )
{
	valor = nro;
	for ( int i = 0 ; i < cantDigitos ; i++ )
	{
		vectorDigitos[i] = nro % 10;
		nro /= 10;
	}
}

//vectorDigitos [ 0 7 0 0 3 5 ]

void Display7Segs::handler ( void )
{

	//1 Desactivo todos los displays
	for ( int i = 0 ; i < cantDigitos ; i++ )
		habilitaciones[i].clrPIN();

	//2 Pongo el nro a mostrar en el bus de segmentos
	uint8_t aux;
	if ( digGuion[digActual] == 1 )
	{
		aux = TablaConversion[10];
	}
	else
	{
		aux = vectorDigitos[digActual];
		aux = TablaConversion[aux];
	}

	for ( int i = 0 ; i < 7 ; i++ )
	{
		segmentos[i].setPIN( (aux>>i) & 1 );
	}

	//Muestro el digito correspondiente
	habilitaciones[digActual].setPIN();

	digActual++;
	if ( digActual == cantDigitos )
		digActual = 0;
}

void Display7Segs::mostrarGuion ( uint8_t nDigito )
{
	digGuion[nDigito] = 1;
}

void Display7Segs::mostrarDigito ( uint8_t nDigito )
{
	digGuion[nDigito] = 0;
}







