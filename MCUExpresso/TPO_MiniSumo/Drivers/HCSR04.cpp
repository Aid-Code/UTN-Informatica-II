/*
 * HCSR04.cpp
 *
 *  Created on: 11 sep. 2026
 *      Author: Aiden
 */

#include "HCSR04.h"

HC_SR04::HC_SR04(uint8_t _pin_trig, uint8_t _port_trig, uint8_t _pin_echo):pin_trig(_pin_trig),port_trig(_port_trig),pin_echo(_pin_echo)
{
	trig(port_trig, pin_trig, gpio::SALIDA);

	CTIMER |= 1;
	CTIMER->PR = (29*5);

	CTIMER->MCR |= 1; // Match para el pulso del TRIG
	CTIMER->MR0 = 4;

	CTIMER->CCR |= 1; // Capture para medir el tiempo del pulso ECHO
}

HC_SR04::getDistancia(void)
{
	return distancia;
}
