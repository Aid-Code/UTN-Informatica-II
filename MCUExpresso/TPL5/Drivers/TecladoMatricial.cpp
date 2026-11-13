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

}

TecladoMatricial::~TecladoMatricial()
{
	delete[] columnas;
	delete[] filas;
}

uint8_t TecladoMatricial::TecladoHw ( void )
{

}
