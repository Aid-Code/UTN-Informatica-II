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
void contador_ticks(void);
void prender_led(void);
void apagar_led(void);

PinInt btnUSR_desc (0, 4, PinInt::flanco_desc, btn_handler_desc);

gpio ledR (1,2,gpio::SALIDA, gpio::LOW);

Timer tiempo_señal(100, contador_ticks, true);
Timer tiempo_encendido(100, prender_led, false);
Timer tiempo_apagado(900, apagar_led, false);

uint8_t ticks = 0;
uint8_t contador = 0;
int frecuencias_encendido[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
int frecuencias_apagado[] = {900, 800, 700, 600, 500, 400, 300, 200, 100};

int main(void)
{
	Inicializar();

	ledR.clrPIN();

	tiempo_señal.start();
	tiempo_encendido.start();

    while(1)
    {

    }
    return 0;
}

void prender_led(void)
{
	ledR.clrPIN();
	tiempo_apagado.start();
	tiempo_encendido.stop();
}

void apagar_led(void)
{
	ledR.setPIN();
	tiempo_encendido.start();
	tiempo_apagado.stop();
}

void contador_ticks(void)
{
	ticks++;
	if (ticks == 9) ticks = 0;
}

void btn_handler_desc(void)
{
	contador++;
	if (contador == 9) contador = 0;

	tiempo_encendido.setTime(frecuencias_encendido[contador]);
	tiempo_apagado.setTime(frecuencias_apagado[contador]);
}*/
