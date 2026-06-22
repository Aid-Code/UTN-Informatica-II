/*
 * PerifericoTemporizado.cpp
 *
 *  Created on: 29 jul. 2024
 *      Author: chor
 */

#include <PerifericoTemporizado.h>

uint8_t PerifericoTemporizado::cant_objetos = 0;
PerifericoTemporizado **objetosTemp = nullptr;

PerifericoTemporizado::PerifericoTemporizado() {

	//Actualizo la lista de perifericos temporizados agregando el nuevo:
	PerifericoTemporizado **aux = new PerifericoTemporizado*[cant_objetos+1];
	for ( int i = 0 ; i < cant_objetos ; i++ )
		aux[i] = objetosTemp[i];

	aux[cant_objetos] = this;
	cant_objetos++;

	//Borro la lista vieja y hago que la lista apunte al nuevo vector dinámico:
	delete[] objetosTemp;
	objetosTemp = aux;

}

PerifericoTemporizado::~PerifericoTemporizado() {

	//Borro de la lista de perifericos temporizados el que se acaba de destruir:
	int posicion;

	for ( posicion = 0 ; posicion < cant_objetos ; posicion++ )
		if ( objetosTemp[posicion] == this )
			break;

	//Saco a "this" de la lista de perifericos:
	PerifericoTemporizado **aux = new PerifericoTemporizado*[cant_objetos-1];
	for ( int i = 0 ; i < posicion; i++ )
		aux[i] = objetosTemp[i];
	for ( int i = posicion + 1 ; i < cant_objetos ; i++ )
		aux[i-1] = objetosTemp[i];

	delete[] objetosTemp;
	cant_objetos--;

	objetosTemp = aux;

}
