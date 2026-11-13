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
extern "C"
{
	void CTIMER0_IRQHandler (void);
}
#endif

class HCSR04
{
public:
	HCSR04(uint8_t _pin_trig, uint8_t _port_trig, uint8_t _pin_echo, uint8_t _port_echo);
	uint32_t getDistancia(void);

	friend void CTIMER0_IRQHandler (void);

private:
	uint8_t pin_trig, port_trig, pin_echo, port_echo;
	gpio trig;
	volatile uint32_t distancia, tiempoi, tiempof;
	bool estado_capture;
};

#endif /* HCSR04_H_ */
