/*
 * Contador.cpp
 *
 *  Created on: 28 jun. 2026
 *      Author: Aiden
 */

#include <Contador.h>

Contador* obj = nullptr;

Contador::Contador(uint8_t port, uint8_t _pin, uint8_t act):puerto(port),pin(_pin),actividad(act)
{
	obj = this;

	CNT->CFG |= 1; //Deshabilitamos para configurar

	if (actividad == HIGH) CNT->CFG |= 1<<1;
	else if (actividad == LOW) CNT->CFG &= ~(1<<1);

	CNT->CFG |= 1<<2;
	CNT->CFG &= ~(1<<3);

	CNT->CFG |= 1<<4;

	int nro = puerto*32 + pin;
	CNT->CFG |= 1<<nro;

	CNT->CFG |= 1<<13;

	CNT->VALUE = 0;

	ISER0 |= 1<<22;

	CNT->CFG &= ~1;
}

void Contador::handler (void)
{
	static int i = 0;

	tiempos[i] = CNT->VALUE;
	i++;

	if (i >= 10) i = 0;

	CNT->VALUE = 0;
	CNT->CFG |= 1<<13;
}

uint32_t Contador::getTiempo (void)
{
	uint32_t resultado;

	for (int i = 0; i < 10; i++)
	{
		resultado = tiempos[i];
	}

	resultado /= 10;

	return resultado;
}

void Contador::start (void)
{
	CNT->CFG &= ~1;
}

void Contador::stop (void)
{
	CNT->CFG |= 1;
}

void CNT_IRQHandler (void)
{
	if (obj != nullptr) obj->handler();
}
