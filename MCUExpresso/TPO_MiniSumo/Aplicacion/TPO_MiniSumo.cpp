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
#include <AnalogInput.h>
#include <DriverMotores.h>
#include <Uart.h>
#include <Timer.h>
#include <Systick.h>

#define UMBRAL_PISO 1000
#define UMBRAL_ATAQUE 3

enum Estados {INICIO, ATAQUE, RETROCESO, BUSQUEDA};

volatile bool flag_inicio = false;
volatile bool flag_retroceso = false;

void handler_inicio(void)    { flag_inicio = true; }
void handler_retroceso(void) { flag_retroceso = true; }

int main(void)
{
	HCSR04 ultrasonico(27, 0, 26, 0);
	AnalogInput qtr (2);
	DriverMotores driver(6, 0, 1, 0, 20, 0, 19, 0, 0, 0, 18, 0);

	Timer timer_inicio(50000, handler_inicio);      // 5 segundos
	Timer timer_retroceso(5000, handler_retroceso); // 500 ms

	timer_inicio.stop();
	timer_retroceso.stop();
	InitSystick();

	Estados estado = INICIO;

	uint32_t lecturas[] = {0, 0};

	driver.setVelocidad(0, 0);
	timer_inicio.start();

	while(1)
    {
		lecturas[0] = ultrasonico.getDistancia();
		lecturas[1] = qtr.getValor();

    	switch (estado)
		{
			case INICIO:
				if (flag_inicio)
				{
					flag_inicio = false;
					estado = BUSQUEDA;
				}
			break;

			case ATAQUE:
				driver.setVelocidad();
				driver.setDireccion(DriverMotores::ADELANTE);

				if (lecturas[1] <= UMBRAL_PISO)
				{
					flag_retroceso = false;
					timer_retroceso.start();
					estado = RETROCESO;
				}
				else if (lecturas[0] > UMBRAL_ATAQUE)
				{
					estado = BUSQUEDA;
				}
			break;

			case BUSQUEDA:
				driver.setVelocidad(50, 50);
				driver.setDireccion(DriverMotores::DERECHA);

				if (lecturas[1] <= UMBRAL_PISO)
				{
					flag_retroceso = false;
					timer_retroceso.start();
					estado = RETROCESO;
				}
				else if (lecturas[0] != 0 && lecturas[0] <= UMBRAL_ATAQUE)
				{
					estado = ATAQUE;
				}
			break;

			case RETROCESO:
				driver.setVelocidad();
				driver.setDireccion(DriverMotores::ATRAS);
				if (flag_retroceso)
				{
					flag_retroceso = false;
					estado = BUSQUEDA;
				}
			break;
		}
    }
    return 0;
}
