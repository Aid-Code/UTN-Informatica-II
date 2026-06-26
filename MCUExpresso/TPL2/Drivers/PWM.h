/*
 * PWM.h
 *
 *  Created on: 23 jun. 2026
 *      Author: Aiden
 */

#ifndef PWM_H_
#define PWM_H_

#include "gpio.h"
#include "PerifericoTemporizado.h"

class PWM : public PerifericoTemporizado, public gpio
{
private:
	uint32_t tiempo_actual;
	uint32_t tiempo_on;
	uint32_t periodo;
	bool encendido;

public:
	PWM(uint8_t _puerto, uint8_t _pin, uint32_t _periodo, uint32_t duty);

	void encenderPulso();
	void apagarPulso();
	void setDuty(uint32_t duty);
	void setPeriodo(uint32_t _periodo);

	void handler(void);
};

#endif /* PWM_H_ */
