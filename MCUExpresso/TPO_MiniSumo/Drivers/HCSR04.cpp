/*
 * HCSR04.cpp
 *
 *  Created on: 11 sep. 2026
 *      Author: Aiden
 */

#include "HCSR04.h"

static HCSR04* instancia;

HC_SR04::HC_SR04(uint8_t _pin_trig, uint8_t _port_trig, uint8_t _pin_echo):pin_trig(_pin_trig),port_trig(_port_trig),pin_echo(_pin_echo)
{
	trig(port_trig, pin_trig, gpio::SALIDA);

	CTIMER->TCR |= 1;
	CTIMER->PR = (29*5);

	CTIMER->MCR |= 25; // Habilito Interrupt en MR0, e Interrupt y reset en MR1
	CTIMER->MR0 = 4; // Pulso de 20uS
	CTIMER->MR1 = 12000; // Reposo de 60mS

	//CTIMER->CCR |= 1; // Capture para medir el tiempo del pulso ECHO
	instancia = this;
}

uint32_t HC_SR04::getDistancia(void)
{
	return distancia;
}

void CTIMER0_IRQHandler (void)
{
	if (CTIMER->IR & (1<<0)) // MR0
	{

	}

	if (CTIMER->IR & (1<<0)) // MR1
	{

	}
}
