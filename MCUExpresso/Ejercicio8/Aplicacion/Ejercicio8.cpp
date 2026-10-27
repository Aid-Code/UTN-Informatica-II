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
#include <gpio.h>
#include <Init.h>
#include <Display7Segs.h>
#include <LPC845.h>
#include <Segmentos4511.h>
#include <HabilitacionesCD4017.h>
#include <TecladoMatricial.h>
#include <Timer.h>

#define TECLA0	0
#define TECLA1	1
#define TECLA2	2
#define TECLA3	3
#define TECLA4	4
#define TECLA5	5

#define BCD_A	0,23
#define BCD_B	0,22
#define BCD_C	0,21
#define BCD_D	0,20

#define RST		0,18
#define CLK		0,19

#define	FILA0	0,26
#define	FILA1	0,15
#define	FILA2	0,8

#define	COL0	0,28
#define	COL1	0,27

#define CANT_DIGITOS	6

#define PASSWORD 123

void segundero ( void );

Timer t1 ( 1000 , segundero );
gpio ledV ( 1,0,gpio::SALIDA,gpio::LOW);
gpio ledA ( 1,1,gpio::SALIDA,gpio::LOW);
gpio ledR ( 1,2,gpio::SALIDA,gpio::LOW);
uint32_t cantSegs = 0;
gpio *ledActivo;


int main(void) {

	Inicializar();

	//Declaro objetos para las 3 filas:
	gpio fila0(FILA0,gpio::ENTRADA,gpio::LOW);
	gpio fila1(FILA1,gpio::ENTRADA,gpio::LOW);
	gpio fila2(FILA2,gpio::ENTRADA,gpio::LOW);

	fila0.setModeIN(gpio::MODE_PULLUP);
	fila1.setModeIN(gpio::MODE_PULLUP);
	fila2.setModeIN(gpio::MODE_PULLUP);

	//Y las pongo en un vector para pasarselos a TecladoMatricial
	gpio filas[] = {fila0,fila1,fila2};

	//Declaro objetos para las 2 columnas
	gpio col0(COL0,gpio::SALIDA,gpio::LOW);
	gpio col1(COL1,gpio::SALIDA,gpio::LOW);

	//Y las pongo en un vector para pasarselos a TecladoMatricial
	gpio cols[] = {col0,col1};

	TecladoMatricial teclado (cols,2,filas,3);

	//Declaro los gpio que voy a usar para los segmentos:
	gpio seg_a(BCD_A,gpio::SALIDA,gpio::HIGH);
	gpio seg_b(BCD_B,gpio::SALIDA,gpio::HIGH);
	gpio seg_c(BCD_C,gpio::SALIDA,gpio::HIGH);
	gpio seg_d(BCD_D,gpio::SALIDA,gpio::HIGH);

	gpio bcd[] = {seg_a,seg_b,seg_c,seg_d};

	Segmentos4511 segmentos(bcd);

	//Declaro los gpio que voy a usar para el counter:
	gpio rst(RST,gpio::SALIDA,gpio::HIGH);
	gpio clk(CLK,gpio::SALIDA,gpio::HIGH);

	gpio pins4017[] = {clk,rst};

	HabilitacionesCD4017 digitos (pins4017 , CANT_DIGITOS);

	//Genero un nuevo display:
	Display7Segs disp ( CANT_DIGITOS , &segmentos , &digitos );
	disp.display(0);

	uint32_t pass = 0;

	ledV.clrPIN();
	ledR.clrPIN();
	ledA.clrPIN();


	while(1) {

		if ( cantSegs == 0 )
		{
			//Leo una tecla del teclado:
			uint8_t aux = teclado.getKey();

			if ( aux != teclado.NO_KEY )
			{
				//Las teclas 0 a 3 serán los números, 4 será cancelar y 5 aceptar:
				if ( aux != TECLA4 && aux != TECLA5 )
				{
					pass = ((pass*10)+aux)%10000;
					disp.display(pass);
				}
				else if ( aux == TECLA4 )
				{
					pass = 0;
					disp.display(pass);
				}
				else if ( aux == TECLA5 )
				{
					if ( pass == PASSWORD )
						ledActivo = &ledV;
					else
						ledActivo = &ledR;

					pass = 0;
					disp.display(pass);
					t1.start();
					cantSegs = 5;

				}
			}
		}
    }

    return 0 ;
}

void segundero ( void )
{
	cantSegs--;
	ledActivo->togglePIN();
	if ( cantSegs == 0 )
		ledActivo->clrPIN();
	else
		t1.start();
}

