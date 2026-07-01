/*
 * clasesTemporizadas.cpp
 *
 *  Created on: 30 jun. 2026
 *      Author: Aiden
 */

#include "clasesTemporizadas.h"

uint32_t clasesTemporizadas::cant_obj = 0;
clasesTemporizadas** clasesTemporizadas::perifericos = nullptr;

clasesTemporizadas::clasesTemporizadas( void (*h) (void) )
{
	funcUsuario = h;

	clasesTemporizadas** aux = nullptr;
	aux = new clasesTemporizadas*[cant_obj+1];

	for (int i = 0; i < cant_obj; i++)
	{
		aux[i] = perifericos[i];
	}

	aux[cant_obj] = this;
	cant_obj++;

	delete[] perifericos;
	perifericos = aux;
}

clasesTemporizadas::~clasesTemporizadas()
{
	clasesTemporizadas** aux = nullptr;
	aux = new clasesTemporizadas*[cant_obj-1];

	int indice_aux = 0;

	for (int i = 0; i < cant_obj; i++)
	{
		if (perifericos[i] != this)
		{
			aux[indice_aux] = perifericos[i];
			indice_aux++;
		}
	}

	cant_obj--;

	delete[] perifericos;
	perifericos = aux;
}


void clasesTemporizadas::atenderInterrupcion()
{
    for(int i = 0; i < cant_obj; i++)
    {
    	perifericos[i]->handler();
    }
}
