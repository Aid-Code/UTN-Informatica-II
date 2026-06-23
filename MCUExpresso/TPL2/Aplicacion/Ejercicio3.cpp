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
#include <DigitalInput.h>

/*void btn_handler_desc(void);
void btn_handler_asc(void);

PinInt btnUSR_desc (0, 4, PinInt::flanco_desc, btn_handler_desc);
PinInt btnUSR_asc (0, 4, PinInt::flanco_asc, btn_handler_asc);

gpio ledR (1,2,gpio::SALIDA, gpio::LOW);
gpio ledV (1, 0, gpio::SALIDA, gpio::LOW);
gpio ledA (1, 1, gpio::SALIDA, gpio::LOW);

gpio* leds[] = {&ledR, &ledV, &ledA};

void contador(void);
void cambio_frecuencias(void);
void handler_sistema(void);

Timer tiempo_transicion(10000, contador, true);
Timer tiempo_frecuencia(4000, cambio_frecuencias, true);
Timer tiempo_presionado(5000, handler_sistema, false);

bool flag_transicion = false;
bool flag_sistema = false;
int cambio_Boton = 0;

int main(void)
{
	Inicializar();

	uint32_t frec[4] = {4000, 2000, 1000, 500};

	tiempo_transicion.start();
	tiempo_frecuencia.start();
	flag_sistema = true;

	ledR.clrPIN();
	ledV.clrPIN();
	ledA.clrPIN();

    while(1)
    {
    	static int i = 0;

    	if (flag_transicion && flag_sistema)
    	{
    		i++;
    		if (i == 4) i = 0;
    		tiempo_frecuencia.setTime(frec[i]);
    		flag_transicion = false;
    	}
    }
    return 0 ;
}

void handler_sistema(void)
{
	if (flag_sistema == false) // Apagado
	{
		tiempo_transicion.start();
		tiempo_frecuencia.start();
		flag_sistema = true;
	}
	else if (flag_sistema == true) // Prendido
	{
		tiempo_frecuencia.stop();
		tiempo_transicion.stop();
		ledR.clrPIN();
		ledV.clrPIN();
		ledA.clrPIN();
		flag_sistema = false;
	}
}

void btn_handler_desc(void)
{
	tiempo_presionado.start();
}

void btn_handler_asc(void)
{
	tiempo_presionado.stop();
	cambio_Boton++;
	ledR.clrPIN();
	ledV.clrPIN();
	ledA.clrPIN();
}

void cambio_frecuencias (void)
{
	if (cambio_Boton >= 3) cambio_Boton = 0;
	leds[cambio_Boton]->togglePIN();
}

void contador (void)
{
	flag_transicion = true;
}*/
