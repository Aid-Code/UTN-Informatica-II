/*
 * PinInterrupt.cpp
 *
 *  Created on: 25 ago. 2026
 *      Author: abril
 */

#include <PinInterrupt.h>

static uint8_t i = 0;
static PinInterrupt *objeto_actual[4] = nullptr;

PinInterrupt::PinInterrupt(uint8_t _port, uint8_t _pin, flancos _causa, void (*h) (void)):port(_port), pin(_pin), causa(_causa), func(h)
{
	uint8_t pinsel = 32*port + pin;

	PINSEL |= pinsel<<(8*i);

	if (causa == DESCENDENTE || causa == AMBOS) CFG |= 1<<i; // IENF
	if (causa == ASCENDENTE || causa == AMBOS) CFG |= 1<<(4+i); // IENR

	if (causa != NINGUNO) CFG |= 1<<(8+i); // IIR

	ISER0 |= 1<<(20+i);

	objeto_actual[i] = this;

	i++;
}

void PIN_0_IRQHandler(void)
{
	objeto_actual[0]->func();
	CFG |= 1<<12;
}

void PIN_1_IRQHandler(void)
{
	objeto_actual[1]->func();
	CFG |= 1<<13;
}

void PIN_2_IRQHandler(void)
{
	objeto_actual[2]->func();
	CFG |= 1<<14;
}

void PIN_3_IRQHandler(void)
{
	objeto_actual[3]->func();
	CFG |= 1<<15;
}

// --------------------------------------------------------- //
// Systick.h
#include "PerifericoTemporizado.h"

void Systick_Handler (void)
{
	for (i = 0; i < PerifericoTemporizado::cant_pt; i++)
	{
		perifericoTemp[i]->handler();
	}
}
