/*
 * Motor.h
 *
 *  Created on: 2 jul. 2026
 *      Author: Aiden
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "LPC845.h"
#include "trainSgn.h"
#include "gpio.h"

class Motor
{
public:
	static const bool HORARIO = true;
	static const bool ANTIHORARIO = false;
	enum velocidades { NORMAL = (uint32_t)40, RAPIDO = (uint32_t)80 };
	Motor(uint8_t puerto_1, uint8_t pin_1, uint8_t puerto_2, uint8_t pin_2);

	void Encender(void);
	void Apagar(void);

	void Sentido(bool nuevo_sentido);
	void CambiarSentido(void);

	void operator++ (void);
	void operator-- (void);

private:
	trainSgn velocidad_pwm;
	gpio pin_sentido;
};

#endif /* MOTOR_H_ */
