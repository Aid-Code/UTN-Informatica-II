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
#include <gpio.h>
#include <PerifericoTemporizado.h>
#include <PinInt.h>
#include <Timer.h>
#include <Uart.h>
#include <Init.h>

Uart PC(0,115200,25,24);
Uart esp(1,115200,17,16);

struct __attribute__((packed)) Trama
{
    uint8_t inicio = 0xAA;
    uint8_t estado;
    uint32_t dato1;
    uint32_t dato2;
    uint8_t fin = 0x55;
};

int main(void)
{
	Inicializar();

	esp.Transmitir(señalESP, 12);

	while(1)
	{

	}
    return 0;
}

void enviar_uint32(Uart &uart, uint32_t num)
{
    if (num == 0) uart.Transmitir('0');

    char digitos[10];
    uint8_t i = 0;
    while (num > 0)
    {
        digitos[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (i > 0) uart.Transmitir((uint8_t)digitos[--i]);
}

void enviar_datos(Uart &esp, uint8_t estado, uint32_t d1, uint32_t d2)
{
	enviar_uint32(esp, estado);
    esp.Transmitir(',');
    enviar_uint32(esp, d1);
    esp.Transmitir(',');
    enviar_uint32(esp, d2);
    esp.Transmitir('\n');
}

