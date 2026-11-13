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
#include <HCSR04.h>
#include <PinInt.h>

void handler (void);

HCSR04 ultrasonico(27, 0, 28, 0);
uint32_t dist;
PinInt btn(0, 4, PinInt::flanco_asc, handler);

int main(void)
{

	while(1)
	{
    }

	return 0 ;
}

void handler (void)
{
	dist = ultrasonico.getDistancia();
}
