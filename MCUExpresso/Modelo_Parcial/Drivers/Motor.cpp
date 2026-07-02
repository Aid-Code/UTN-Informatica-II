/*
 * Motor.cpp
 *
 *  Created on: 2 jul. 2026
 *      Author: Aiden
 */

#include "Motor.h"

Motor::Motor(uint8_t puerto_1, uint8_t pin_1, uint8_t puerto_2, uint8_t pin_2):velocidad_pwm(NORMAL, puerto_1, pin_1),pin_sentido(puerto_2, pin_2, gpio::SALIDA)
{
	velocidad_pwm.stop();
	pin_sentido.setPIN(HORARIO);
}

void Motor::Encender(void)
{
	velocidad_pwm.start();
}
void Motor::Apagar(void)
{
	velocidad_pwm.stop();
}

void Motor::Sentido(bool nuevo_sentido)
{
	pin_sentido.setPIN(nuevo_sentido);
}

void Motor::CambiarSentido(void)
{
	pin_sentido.togglePIN();
}

void Motor::operator++ (void)
{
	if (velocidad_pwm == NORMAL) velocidad_pwm = RAPIDO;
}

void Motor::operator-- (void)
{
	if (velocidad_pwm == RAPIDO) velocidad_pwm = NORMAL;
}
