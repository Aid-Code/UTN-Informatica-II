/*
 * TecladoMatricial.cpp
 *
 *  Created on: 2 jul. 2025
 *      Author: chor
 */

#include "TecladoMatricial.h"

TecladoMatricial::TecladoMatricial( gpio * cols, uint8_t cant_cols, gpio * rows, uint8_t cant_rows )
{
	columnas = new gpio[cant_cols];

	for ( int i = 0 ; i < cant_cols ; i++ )
		columnas[i] = cols[i];

	cant_columnas = cant_cols;

	filas = new gpio[cant_rows];

	for ( int i = 0 ; i < cant_rows ; i++ )
		filas[i] = rows[i];

	cant_filas = cant_rows;

	enabled = true;
}

TecladoMatricial::~TecladoMatricial()
{
	delete[] columnas;
	delete[] filas;
}

uint8_t TecladoMatricial::TecladoHw ( void )
{
	uint8_t retorno = NO_KEY;

	//Empiezo "apagando" todas las columnas:
	for ( int i = 0 ; i < cant_columnas ; i++ )
		columnas[i].clrPIN();

	for ( int i = 0 ; i < cant_columnas ; i++ )
	{
		//Enciendo una columna (es la que voy a mirar)
		columnas[i].setPIN();

		//Voy mirando si alguna de las filas está activa:
		for ( int j = 0 ; j < cant_filas; j++ )
			if ( filas[j].getPIN() )
				retorno = (cant_columnas * j) + i;

		//Apago la fila que encendi al principio:
		columnas[i].clrPIN();
	}

	return retorno;
}
