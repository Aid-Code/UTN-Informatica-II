/*
 * PWM.cpp
 *
 *  Created on: 23 jun. 2026
 *      Author: Aiden
 */

#include <PWM.h>

PWM::PWM(uint8_t _puerto, uint8_t _pin, uint32_t _periodo, uint32_t duty):gpio(_puerto, _pin, gpio::SALIDA),periodo(_periodo),tiempo_on(duty)
{
	encendido = false;
}

void PWM::encenderPulso()
{
	encendido = true;
}

void PWM::apagarPulso()
{
	encendido = false;
}


void PWM::setDuty(uint32_t duty)
{
	tiempo_on = duty;
}

void PWM::setPeriodo(uint32_t _periodo)
{
	periodo = _periodo;
}

void PWM::handler (void)
{
	tiempo_actual++;

	if (tiempo_actual >= periodo) tiempo_actual = 0;

	if (tiempo_actual < tiempo_on) this->setPIN();
	else this->clrPIN();
}
