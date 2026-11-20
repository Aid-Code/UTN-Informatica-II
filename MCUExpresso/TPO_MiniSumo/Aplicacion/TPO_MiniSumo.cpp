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
#include <AnalogInput.h>
#include <gpio.h>
#include <HCSR04.h>
#include <PerifericoTemporizado.h>
#include <PinInt.h>
#include <Timer.h>
#include <Uart.h>
#include <DriverMotores.h>

AnalogInput sens(2); //CONFIG CNY
int val = 0; //VALOR CNY
gpio enab (0,31, gpio::SALIDA, gpio::LOW); //CONFIGURO EL PIN HABILITADOR DEL ESP8266
Uart esp8266 (115200,8, 9, 0); // 0 COMO RECEPCION, 2 COMO TRANSMISION
Uart PC (115200, 24, 25, 2);

uint16_t dato = 0;
uint8_t buff = 2;
uint8_t buffOK[1] = {0};
uint8_t datoPC;
gpio AIN1 (0,13, gpio::SALIDA, gpio::LOW); //cambiar pin a 9 despues
gpio AIN2 (0,10, gpio::SALIDA, gpio::LOW);
gpio BIN1 (0,11, gpio::SALIDA, gpio::LOW);
gpio BIN2 (0,12, gpio::SALIDA, gpio::LOW);

gpio MotorPins[] = {AIN1, AIN2, BIN1, BIN2};

DriverMotores sumo(MotorPins);

int main(void){/*
	enab.setPIN(); //HABILITO EL PIN DEL ESP8266
while(1) {
	val = sens.getValor(); //GET VAL CNY
    }*/
while(1){
	datoPC = esp8266.Recibir();
	buffOK[0] = datoPC;
	//esp8266.Transmitir(buffOK, buff);
	PC.Transmitir(buffOK, buff);
}
    return 0 ;
}


