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

DigitalInput sensor1(0,4,gpio::HIGH);
DigitalInput sensor2(0,12,gpio::HIGH);


typedef struct {
uint8_t nroNivel;
uint8_t cantAutos;
} infoNivel;

#define SEG_A	0,23
#define SEG_B	0,22
#define SEG_C	0,21
#define SEG_D	0,20
#define SEG_E	0,19
#define SEG_F	0,18
#define SEG_G	0,17

#define DIG0	0,1
#define DIG1	0,2
#define DIG2	0,3
#define DIG3	0,4
#define DIG4	0,5
#define DIG5	0,6

#define CANT_DIGITOS	2

uint8_t cantAutos[3];

infoNivel mdeRecepcion ( uint8_t );
void actualizarDisplay(Display7Segs &, infoNivel datoRecibido );

int main(void) {

	infoNivel datoRecibido;
	Uart comNiveles;

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

	//Genero un nuevo display:
	Display7Segs display ( segs , digitos , CANT_DIGITOS , 0 );

	//Inicializa el display 7 segmentos
	for ( int i = 0 ; i < CANT_DIGITOS ; i++ )
		display.mostrarGuion(i);

	//Inicializo la variable global
	cantAutos[0] = 0;
	cantAutos[1] = 0;
	cantAutos[2] = 0;

    while(1) {

    	int16_t nuevoByte;

    	nuevoByte = comNiveles.Recibir();

    	if ( nuevoByte != Uart::NO_DATA )
    	{
    		datoRecibido = mdeRecepcion ( nuevoByte );
    	}
    	if ( datoRecibido.nroNivel != 255 )
    	{
    		comNiveles.Transmitir ("Recibido");
    		actualizarDisplay(display,datoRecibido);
    	}

    }
    return 0 ;
}

#define		ESPERO_HEADER	0
#define		ESPERO_NIVEL	1
#define		ESPERO_AUTOS	2
#define		ESPERO_FIN		3

#define		HEADER			100
#define		FINALIZADOR			101

infoNivel mdeRecepcion ( uint8_t datoRecibido )
{
	static uint8_t estado  = ESPERO_HEADER;
	infoNivel retorno;
	retorno.nroNivel = 255;
	static uint8_t auxNivel;
	static uint8_t auxAutos;

	switch ( estado )
	{
	case ESPERO_HEADER:
		if ( datoRecibido == HEADER )
		{
			estado = ESPERO_NIVEL;
		}
		break;

	case ESPERO_NIVEL:
		if ( datoRecibido > 2 && datoRecibido != HEADER )
		{
			estado = ESPERO_HEADER;
		}
		else if ( datoRecibido <=2 )
		{
			estado = ESPERO_AUTOS;
			auxNivel = datoRecibido;
		}
		break;

	case ESPERO_AUTOS:

		if ( datoRecibido == HEADER )
		{
			estado = ESPERO_NIVEL;
		}
		else if ( datoRecibido > 99 )
		{
			estado = ESPERO_HEADER;
		}
		else if ( datoRecibido <=99 )
		{
			estado = ESPERO_FIN;
			auxAutos= datoRecibido;
		}
		break;

	case ESPERO_FIN:

		if ( datoRecibido == FINALIZADOR )
		{
			retorno.cantAutos = auxAutos;
			retorno.nroNivel = auxNivel;
			estado = ESPERO_HEADER;
		}
		else if ( datoRecibido == HEADER  )
		{
			estado = ESPERO_NIVEL;
		}
		else
		{
			estado = ESPERO_HEADER;
		}
		break;

	default:
		estado = ESPERO_HEADER;
		break;
	}

	return retorno;
}

void actualizarDisplay(Display7Segs &display, infoNivel datoRecibido )
{
	cantAutos[datoRecibido.nroNivel] = datoRecibido.cantAutos;
	// pos 5 [ 0 7 , 0 0 ,  3 5 ] pos0
	uint32_t nro;
	uint32_t multiplicador = 1;

	for ( int i = 0 ; i < 3 ; i++ )
	{
		nro += cantAutos[i]*multiplicador;
		multiplicador*= 100;

		if ( cantAutos[i] == 0 )
		{
			display.mostrarGuion(i*2);
			display.mostrarGuion((i*2)+1);
		}
		else
		{
			display.mostrarDigito(i*2);
			display.mostrarDigito((i*2)+1);
		}
	}

	display.setDisplay ( nro );
}

//Ejercicio adicional: Mde Autos:

#define		REPOSO			0
#define		INICIO_PASO		1
#define		PASANDO			2
#define		FIN_PASO		3

Uart comunicacion;

void mdeAutos ( )
{
	static uint8_t estado  = ESPERO_HEADER;
	static int8_t auxiliar = 0;
	static uint8_t cantAutos = 0;
	char trama[5] = {100,0,0,101,'\0'};

	switch ( estado )
	{
	case REPOSO:

		if ( auxiliar == 4 )
		{
			auxiliar = 0;
			cantAutos++;
			trama[2] = cantAutos;
			comunicacion.Transmitir(trama);
		}
		if ( auxiliar == -4 )
		{
			auxiliar = 0;
			cantAutos--;
			trama[2] = cantAutos;
			comunicacion.Transmitir(trama);

		}
		if ( !(sensor1.getPIN()) && sensor2.getPIN() )
		{
			estado = INICIO_PASO;
			auxiliar++;
		}
		if ( !(sensor2.getPIN()) && sensor1.getPIN() )
		{
			estado = FIN_PASO;
			auxiliar--;
		}


		break;

	case INICIO_PASO:

		if ( !(sensor1.getPIN()) && !(sensor2.getPIN()) )
		{
			estado = PASANDO;
			auxiliar++;
		}
		if ( (sensor2.getPIN()) && sensor1.getPIN() )
		{
			estado = REPOSO;
			auxiliar--;
		}

		break;

	case PASANDO:
		if ( (sensor1.getPIN()) && !(sensor2.getPIN()) )
		{
			estado = FIN_PASO;
			auxiliar++;
		}
		if ( !(sensor1.getPIN()) && sensor2.getPIN() )
		{
			estado = INICIO_PASO;
			auxiliar--;
		}

		break;

	case FIN_PASO:
		if ( sensor1.getPIN() && sensor2.getPIN() )
		{
			estado = REPOSO;
			auxiliar++;
		}
		if ( !(sensor2.getPIN()) && !(sensor1.getPIN()) )
		{
			estado = PASANDO;
			auxiliar--;
		}
		break;

	default:
		estado = REPOSO;
		auxiliar = 0;
		break;
	}
}

