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
#include <PerifericoTemporizado.h>
#include <PinInt.h>
#include <Timer.h>
#include <Uart.h>
#include <Init.h>

gpio enab (0,31, gpio::SALIDA, gpio::LOW); //CONFIGURO EL PIN HABILITADOR DEL ESP8266
Uart PC(0,115200,25,24);
Uart esp8266(1,115200,17,16);

uint16_t dato = 0;
uint8_t buff = 2;
uint8_t buffOK[1] = {0};
//uint8_t señalESP[6] = {"AT\r\n"};
uint8_t señalESP[12] = {"AT+CIFSR\r\n"};
uint8_t datoPC = 'Q';
uint8_t datoPC1 = '\n';

int main(void)
{
	Inicializar();

	enab.setPIN(); //HABILITO EL PIN DEL ESP8266
	esp8266.Transmitir(señalESP, 12);

	while(1)
	{
		datoPC = esp8266.Recibir();
		buffOK[0] = datoPC;
		//esp8266.Transmitir(buffOK, buff);
		if(datoPC != 255){PC.Transmitir(buffOK, buff);
		}else{

		}
		//PC.Transmitir(datoPC1);

	}
    return 0 ;
}
*/

