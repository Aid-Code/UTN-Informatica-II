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
AnalogInput sens(2); //CONFIG CNY
int val = 0; //VALOR CNY
gpio enab (0,8, gpio::SALIDA, gpio::LOW); //CONFIGURO EL PIN HABILITADOR DEL ESP8266
Uart esp8266 (115200);
Uart PC (115200);
int main(void) {
	enab.setPIN(); //HABILITO EL PIN DEL ESP8266
while(1) {
	val = sens.getValor(); //GET VAL CNY
    }
    return 0 ;
}

