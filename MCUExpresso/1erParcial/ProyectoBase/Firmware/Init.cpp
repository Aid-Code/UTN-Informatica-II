/*
 * DR_Init.c
 *
 *  Created on: 8 ago. 2021
 *      Author: chor
 */

#include "LPC845.h"
#include "Init.h"
#include "Timer.h"

//Genero una funcion a partir de un puntero a función que llame a esa posición de memoria:

void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;

void Inicializar(void)
{
	//Seteo la frecuencia del fro a 30MHz, llamando a la funcion de ROM:
	fro_set_frec(30000);

	//Selecciono la salida del FRO como el clk principal del sistema:

	SYSCON->FROOSCCTRL |= 1<<17;

	//Refresco el registro para habilitar el clk de 30MHz:
	SYSCON->FRODIRECTCLKUEN &= ~1;
	SYSCON->FRODIRECTCLKUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->MAINCLKPLLSEL = 0;

	SYSCON->MAINCLKPLLUEN &= ~1;
	SYSCON->MAINCLKPLLUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->SYSPLLCLKSEL = 0;

	SYSCON->SYSPLLCLKUEN &= ~1;
	SYSCON->SYSPLLCLKUEN |= 1;

	SYSCON->SYSAHBCLKDIV = 1;

	InitSystick();
}

void InitSystick ( void )
{
	//Inicializo el Systick para que interrumpa cada 1mseg:
	SYSTICK->CSR=6;				//Habilito la interrupción del systick y selecciono como fuente del systick el fro
	SYSTICK->RVR=3000-1;		//Configuro el systick cada 0.1ms, le pongo -1 porque el micro tarda un tick mas en hacer el reload
	SYSTICK->CVR=SYSTICK->RVR;	//Hago que la primer interrupción dure lo mismo que el resto
	SYSTICK->CSR |= 1;			//Habilito el systick
}
