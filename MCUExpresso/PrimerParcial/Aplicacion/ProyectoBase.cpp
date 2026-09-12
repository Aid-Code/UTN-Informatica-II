/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such terms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */

#include <cr_section_macros.h>
#include "LPC845.h"
#include "gpio.h"
#include "PinInterrupt.h"
#include "Timer.h"
#include "Cronometro.h"

void handler_pul1(void);
void handler_pul2(void);

PinInterrupt pul1 (0, 4, handler_pul1, PinInterrupt::AMBOS);
PinInterrupt pul2 (0, 4, handler_pul2, PinInterrupt::AMBOS);

Cronometro tiempo1();
Cronometro tiempo2();

gpio ledV(1, 0, gpio::SALIDA, gpio::HIGH);
gpio ledR(1, 1, gpio::SALIDA, gpio::HIGH);

void handler_ledV (void);
void handler_ledR (void);

Timer tiempo_ledV (5000, handler_ledV);
Timer tiempo_ledR (5000, handler_ledR);

uint32_t t1 = 0;
uint32_t t2 = 0;

uint8_t flag_ambos = 0;

bool flag_leds = false;

int main ( void )
{
	tiempo_ledV.stop();
	tiempo_ledR.stop();

	ledV.setPIN(gpio::OFF);
	ledR.setPIN(gpio::OFF);

	while (1)
	{
		if (flag_ambos == 2)
		{
			if (t2 <= (t1+100) && t2 >= (t1+100)) tiempo_ledV.start();
			else tiempo_ledR.start();
		}

		flag_leds = false;
	}

	return 0;
}

void handler_ledV (void)
{
	flag_leds = true;
	ledV.setPIN(gpio::ON);
	ledR.setPIN(gpio::OFF);
}

void handler_ledR (void)
{
	flag_leds = true;
	ledV.setPIN(gpio::OFF);
	ledR.setPIN(gpio::ON);
}

void handler_pul1 (void)
{
	static uint8_t estado = 0;
	if (!flag_leds)
	{
		if (estado == 0)
		{
			tiempo1.start();
			estado++;
		}
		else if (estado == 1)
		{
			t1 = tiempo1.getTiempo();
			tiempo1.stop();
			estado = 0;
			flag_ambos = 1;
		}
	}
}

void handler_pul2 (void)
{
	static uint8_t estado = 0;
	if (!flag_leds)
	{
		if (estado == 0)
		{
			tiempo2.start();
			estado++;
		}
		else if (estado == 1)
		{
			t2 = tiempo2.getTiempo();
			tiempo2.stop();
			estado = 0;
			flag_ambos = 2;
		}
	}
}
