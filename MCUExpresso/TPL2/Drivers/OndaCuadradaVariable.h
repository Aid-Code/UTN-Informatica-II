/*
 * OndaCuadradaVariable.h
 *
 *  Created on: 23 jun. 2026
 *      Author: abril
 */

#ifndef ONDACUADRADAVARIABLE_H_
#define ONDACUADRADAVARIABLE_H_

#include "gpio.h"
#include "PerifericoTemporizado.h"

class OndaCuadradaVariable : public PerifericoTemporizado, public gpio
{
private:
	uint32_t tiempo_actual;
	uint32_t tiempo_on;
	uint32_t periodo;
	bool encendido;

public:
	OndaCuadradaVariable();
	void encenderPulso();
	void apagarPulso();
	void setDuty(uint32_t duty);
	void setPeriodo(uint32_t periodo_);
};

#endif /* ONDACUADRADAVARIABLE_H_ */
