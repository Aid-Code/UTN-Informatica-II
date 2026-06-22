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
#include <Cronometro.h>
#include <gpio.h>
#include <PinInt.h>
#include <Init.h>
#include <DigitalInput.h>

/*

gpio ledR (1,2,gpio::SALIDA, gpio::LOW);
gpio ledV (1, 0, gpio::SALIDA, gpio::LOW);
gpio ledA (1, 1, gpio::SALIDA, gpio::LOW);


void contador(void);
void frecuencias(void);

Timer tiempo_transicion(10000, contador, true);
Timer tiempo_frecuencia(4000, frecuencias, true);

bool flag = false;

int main(void) {

	Inicializar();

	uint32_t frec[4] = {4000, 2000, 1000, 500};

	tiempo_transicion.start();
	tiempo_frecuencia.start();

	ledR.clrPIN();
	ledV.clrPIN();
	ledA.clrPIN();

    while(1)
    {
    	static int i = 0;

    	if (flag)
    	{
    		i++;
    		if (i == 4) i = 0;
    		tiempo_frecuencia.setTime(frec[i]);
    		flag = false;
    	}
    }
    return 0 ;
}

void frecuencias (void)
{
	ledR.togglePIN();
}

void contador (void)
{
	flag = true;
}*/
