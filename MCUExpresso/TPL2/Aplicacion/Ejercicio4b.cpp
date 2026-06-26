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
#include <LPC845.h>
#include <Timer.h>
#include <gpio.h>
#include <PinInt.h>
#include <Init.h>

/*void btn_handler_desc(void);
void btn_handler_asc(void);
void handler_señal(void);

PinInt btnUSR_desc (0, 4, PinInt::flanco_desc, btn_handler_desc);

gpio ledR (1,2,gpio::SALIDA, gpio::LOW);

Timer tiempo_señal(100, handler_señal, true);

uint8_t ticks = 0;
uint8_t ticks_on = 1;

int main(void)
{
	Inicializar();

	ledR.clrPIN();

	tiempo_señal.start();

    while(1)
    {

    }
    return 0;
}

void handler_señal(void)
{
	ticks++;

	if (ticks >= 10) ticks = 0;

	if (ticks < ticks_on) ledR.setPIN();
	else ledR.clrPIN();
}

void btn_handler_desc(void)
{
	ticks_on++;
	if (ticks_on > 9) ticks_on = 1;
}*/
