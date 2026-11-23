/*
 * HCSR04.cpp
 *
 *  Created on: 11 sep. 2026
 *      Author: Aiden
 */
/*
#include "HCSR04.h"

static HCSR04* instancia;

HCSR04::HCSR04(uint8_t _pin_trig, uint8_t _port_trig, uint8_t _pin_echo, uint8_t _port_echo):pin_trig(_pin_trig),port_trig(_port_trig),pin_echo(_pin_echo), port_echo(_port_echo), trig(port_trig, pin_trig, gpio::SALIDA)
{
	instancia = this;
	estado_capture = 0;
	distancia = 0;
	tiempoi = 0;
	tiempof = 0;

	// Configuracion de Switch Matrix:
	uint8_t pin_habilitacion = (port_echo * 32) + pin_echo;
	SYSCON->SYSAHBCLKCTRL0 |= 1<<7; // Habilito Switch Matrix
	PINASSIGN14 &= ~(0xFF << 8);
	PINASSIGN14 |= pin_habilitacion << 8;
	SYSCON->SYSAHBCLKCTRL0 &= ~(1<<7); // Apago la Switch Matrix

	// Configuracion de CTIMER:

	SYSCON->SYSAHBCLKCTRL0 |= 1<<25;
	SYSCON->PRESETCTRL0 |= 1<<25;

	CTIMER->PR = (30 * 5) - 1;

	CTIMER->MCR |= 25; // Habilito Interrupt en MR0, e Interrupt y reset en MR1
	CTIMER->MR0 = 4; // Pulso de 20uS
	CTIMER->MR1 = 12000; // Reposo de 60mS

	CTIMER->CCR = 7; // Activo el capture 0 con rising edge, falling edge y su interrupt.

	ISER0 |= 1<<23;
	trig.setPIN();
	CTIMER->TCR |= 1;
}

uint32_t HCSR04::getDistancia(void)
{
	distancia = ((tiempof - tiempoi)*5)/58;
	return distancia;
}

void CTIMER0_IRQHandler (void)
{
	if (CTIMER->IR & (1<<0)) // MR0 - Fin pulso 20uS
	{
		instancia->trig.clrPIN();
		CTIMER->IR = 1;
	}

	if (CTIMER->IR & (1<<1)) // MR1 - Fin reposo 60mS
	{
		instancia->trig.setPIN();
		instancia->estado_capture = 0;
		CTIMER->IR = 2;
	}

	if (CTIMER->IR & (1<<4)) // CR0 - Rising o Falling edge del ECHO
	{
		if (!instancia->estado_capture) // Rising edge
		{
			instancia->tiempoi = CTIMER->CR0;
			instancia->estado_capture = 1;
			CTIMER->IR = 16;
		}
		else // Falling edge
		{
			instancia->tiempof = CTIMER->CR0;
			instancia->estado_capture = 0;
			CTIMER->IR = 16;
		}
	}
}*/
