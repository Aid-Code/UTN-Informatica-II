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
#include <gpio.h>
#include <PinInt.h>
#include <Init.h>
#include <PWM.h>

void btn_handler_desc(void);

PinInt btnUSR_desc (0, 4, PinInt::flanco_desc, btn_handler_desc);

PWM señal (1, 2, 1000, 100);

uint8_t ticks_on = 100;

int main(void)
{
	Inicializar();

	señal.encenderPulso();

    while(1)
    {
    	señal.setDuty(ticks_on);
    }
    return 0;
}

void btn_handler_desc(void)
{
	ticks_on += 100;
	if (ticks_on > 900) ticks_on = 100;
}
