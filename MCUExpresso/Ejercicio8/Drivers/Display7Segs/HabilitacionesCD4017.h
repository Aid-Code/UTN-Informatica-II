/*
 * digitos4017.h
 *
 *  Created on: 26 jun. 2023
 *      Author: chor
 */

#ifndef DIGITOS4017_H_
#define DIGITOS4017_H_

#include <Habilitaciones.h>
#include "gpio.h"
#include "LPC845.h"

class HabilitacionesCD4017:public Habilitaciones{

public:

	HabilitacionesCD4017( gpio * h , uint8_t cant ) : Habilitaciones(h, cant){}
	void encenderSiguiente (uint8_t );

};

#endif /* DIGITOS4017_H_ */
