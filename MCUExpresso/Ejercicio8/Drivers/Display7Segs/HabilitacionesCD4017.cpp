/*
 * digitos4017.cpp
 *
 *  Created on: 26 jun. 2023
 *      Author: chor
 */

#include "HabilitacionesCD4017.h"

void HabilitacionesCD4017::encenderSiguiente( uint8_t digito_actual )
{

	if ( digito_actual == 0 )
	{
		habilitaciones[1].setPIN(1);
		habilitaciones[1].setPIN(0);
	}
	else
	{
		habilitaciones[0].setPIN(1);
		habilitaciones[0].setPIN(0);
	}

}

