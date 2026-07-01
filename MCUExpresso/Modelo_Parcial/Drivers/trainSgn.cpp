/*
 * trainSgn.cpp
 *
 *  Created on: 1 jul. 2026
 *      Author: Aiden
 */

#include "trainSgn.h"

trainSgn::trainSgn(uint32_t frec, uint8_t port, uint8_t _pin):puerto(port), pin(_pin)
{
	if (frec >= 40 && frec <= 1000) frecuencia = frec;
	else frecuencia = 40;
	uint32_t div_value = frecuencia * CLK_SRC_VAL;

	CFG &= ~(1<<1); // Desactivo la salida para configurar
	CFG |= 1; // Habilito el periferico para configurar

	uint8_t valor = 0;

	if (CLK_SRC_VAL == FRO/1000) valor = 0;
	else if (CLK_SRC_VAL == FRO/2000) valor = 1;
	else if (CLK_SRC_VAL == FRO/3000) valor = 2;

	CFG |= valor<<2;

	uin8_t nro = (32*puerto + pin);

	CFG |= nro<<13; // Configuro el pin y el puerto
}

void trainSgn::start(void)
{
	CFG |= 1<<1;
}

void trainSgn::stop(void)
{
	CFG &= ~(1<<1);
}

void trainSgn::operator = (uint32_t frec)
{
	this->frecuencia = frec;
}
