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
#include <OLED.h>

int main(void)
{
	OLED display(0x3D);
	display.init();

	display.setCursor(0, 0);
	display.print("HOLA MUNDO");

	display.setCursor(0, 2);
	display.print("VEL: 50");

	while (1)
	{

	}
	return 0;
}
