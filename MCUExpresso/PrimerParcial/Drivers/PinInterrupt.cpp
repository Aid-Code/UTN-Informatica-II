/*
 * PinInterrupt.cpp
 *
 *  Created on: 3 jul. 2026
 *      Author: Aiden
 */

#include <PinInterrupt.h>

static uint8_t PinInterrupt::index = 0;
PinInterrupt** PinInterrupt::objeto_actual = nullptr;

PinInterrupt::PinInterrupt(uint8_t port, uint8_t _pin, void *h (void), flancos causa):puerto(port),pin(_pin),func(h),flanco(causa)
{
	uint8_t pinsel = 32*puerto + pin;
	PINSEL_REG |= pinsel<<PINSEL[index];

	if (flanco == DESCENDENTE) CFG |= fuente[index]<<3;
	else if (flanco == ASCENDENTE) CFG |= fuente[index]<<7;

	CFG |= fuente[index]<<11;

	ISER0 |= fuente[index]<<23;

	objeto_actual[index] = this;
	index++;
}

PinInterrupt::~PinInterrupt()
{
	delete[] objeto_actual;
}

void PIN_0_IRQHandler (void)
{
	if (objeto_actual[0]) objeto_actual[0]->func;
	CFG |= fuente[0]<<15;
}

void PIN_1_IRQHandler (void)
{
	if (objeto_actual[1]) objeto_actual[1]->func;
	CFG |= fuente[1]<<15;
}

void PIN_2_IRQHandler (void)
{
	if (objeto_actual[2]) objeto_actual[2]->func;
	CFG |= fuente[2]<<15;
}

void PIN_3_IRQHandler (void)
{
	if (objeto_actual[3]) objeto_actual[3]->func;
	CFG |= fuente[3]<<15;
}

// =================================================
// Systick.cpp
#include "PerifericoTemporizado.h"

void SYSTICK_Handler (void)
{
	for (int i = 0; i < PerifericoTemporizado::cant_pt; i++)
	{
		if (perifericosTemp[i]) perifericosTemp[i]->handler();
	}

}
