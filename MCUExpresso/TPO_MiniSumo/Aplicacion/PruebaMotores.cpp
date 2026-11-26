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
/*
#include <cr_section_macros.h>
#include <LPC845.h>
#include <gpio.h>
#include <PinInt.h>
#include <DriverMotores.h>

void delay(uint32_t ciclos)
{
	for (volatile uint32_t i = 0; i < ciclos; i++);
}

int main(void)
{
	DriverMotores driver(6, 0, 1, 0, 20, 0, 19, 0, 0, 0, 18, 0);
	driver.setVelocidad(50, 50);

	while (1)
	{
		driver.setDireccion(DriverMotores::ADELANTE);
		delay(1000000);

		driver.setDireccion(DriverMotores::ATRAS);
		delay(1000000);

		driver.setDireccion(DriverMotores::IZQUIERDA);
		delay(1000000);

		driver.setDireccion(DriverMotores::DERECHA);
		delay(1000000);

		driver.setDireccion(DriverMotores::FRENADO);
		delay(1000000);
	}
	return 0;
}
*/
