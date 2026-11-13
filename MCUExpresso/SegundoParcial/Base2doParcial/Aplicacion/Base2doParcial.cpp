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
#include <Uart.h>
#include <Display7Segs.h>
#include <Init.h>
#include <DigitalInput.h>

//Defino los objetos que voy a necesitar


//Declaro la estructura que va a devolver la función de recepción del puerto serie
typedef struct{
		uint8_t parteEntera;
		uint8_t parteDecimal;
} fuerza_t;


#define SEG_A	0,23
#define SEG_B	0,22
#define SEG_C	0,21
#define SEG_D	0,20
#define SEG_E	0,19
#define SEG_F	0,18
#define SEG_G	0,17

#define DP		0,24

#define DIG0	0,1
#define DIG1	0,2
#define DIG2	0,3
#define DIG3	0,4
#define DIG4	0,5
#define DIG5	0,6

#define CANT_DIGITOS	3

fuerza_t recepcionTrama ( Uart & );


int main(void) {

	Inicializar();

	//Declaro los gpio que voy a usar para los segmentos:
	gpio seg_a(SEG_A,gpio::SALIDA,gpio::HIGH);
	gpio seg_b(SEG_B,gpio::SALIDA,gpio::HIGH);
	gpio seg_c(SEG_C,gpio::SALIDA,gpio::HIGH);
	gpio seg_d(SEG_D,gpio::SALIDA,gpio::HIGH);
	gpio seg_e(SEG_E,gpio::SALIDA,gpio::HIGH);
	gpio seg_f(SEG_F,gpio::SALIDA,gpio::HIGH);
	gpio seg_g(SEG_G,gpio::SALIDA,gpio::HIGH);

	//Declaro un vector para usar en el objeto Display7Segs:
	gpio segs[] = {seg_a,seg_b,seg_c,seg_d,seg_e,seg_f,seg_g};

	//Declaro los gpio que voy a usar para el counter:
	gpio dig0(DIG0,gpio::SALIDA,gpio::HIGH);
	gpio dig1(DIG1,gpio::SALIDA,gpio::HIGH);
	gpio dig2(DIG2,gpio::SALIDA,gpio::HIGH);
	gpio dig3(DIG3,gpio::SALIDA,gpio::HIGH);
	gpio dig4(DIG4,gpio::SALIDA,gpio::HIGH);
	gpio dig5(DIG5,gpio::SALIDA,gpio::HIGH);

	gpio digitos[] = {dig0,dig1,dig2,dig3,dig4,dig5};

	gpio dp (DP,gpio::SALIDA,gpio::HIGH);

	//Genero un nuevo display:
	Display7Segs display ( segs , digitos , dp , CANT_DIGITOS , 0 );

    while(1) {


    }
    return 0 ;
}
