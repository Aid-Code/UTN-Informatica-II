/*
 * HCSR04.h
 *
 *  Created on: 11 sep. 2026
 *      Author: Aiden
 */

#ifndef HCSR04_H_
#define HCSR04_H_

#include <gpio.h>

#if defined (__cplusplus)
extern "C" {
void CTIMER0_IRQHandler (void);
}
#endif

class HC_SR04
{
public:
	HC_SR04(uint8_t _pin_trig, uint8_t _port_trig, uint8_t _pin_echo);
	uint32_t getDistancia(void);

private:
	gpio trig;
	uint8_t pin_trig, port_trig, pin_echo;
	uint32_t distancia, tiempo;

	bool distancia_recibida;
};

#endif /* HCSR04_H_ */
