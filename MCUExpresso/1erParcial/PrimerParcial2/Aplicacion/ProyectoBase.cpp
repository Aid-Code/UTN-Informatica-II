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

void handler_pul1 (void);
void handler_pul2 (void);

void handler_ledV (void);
void handler_ledR (void);

gpio ledV (1, 1, gpio::SALIDA, gpio::LOW);
gpio ledR (1, 0, gpio::SALIDA, gpio::LOW);

PinInterrupt pul1 (0, 4, PinInterrupt::AMBOS, handler_pul1);
PinInterrupt pul2 (0, 12, PinInterrupt::AMBOS, handler_pul2);

Cronometro tiempo_pul1;
Cronometro tiempo_pul2;

Timer tiempo_ledV (5000, handler_ledV);
Timer tiempo_ledR (5000, handler_ledR);

bool leds_encendidos = false;

uint32_t tiempo_1 = 0;
uint32_t tiempo_2 = 0;

int main ( void )
{
	ledV = gpio::OFF;
	ledR = gpio::OFF;

	while (1)
	{
		if (tiempo_1 >= (tiempo_2 + 100) && tiempo_1 <= (tiempo_2 - 100)) ledV.start();
		else ledR.start();
	}

	return 0;
}

void handler_pul1 (void)
{
	static uint8_t flag = 0;

	if (flag == 0)
	{
		tiempo_pul1.start();
		flag++;
	}
	else if (flag == 1)
	{
		tiempo_1 = tiempo_pul1.getTiempo();
		flag = 0;
	}
}


void handler_pul2 (void)
{
	static uint8_t flag = 0;

	if (tiempo_1 != 0 && flag == 0)
	{
		tiempo_pul2.start();
		flag++;
	}
	else if (tiempo_1 != 0 && flag == 1)
	{
		tiempo_2 = tiempo_pul2.getTiempo();
		flag = 0;
	}
}

