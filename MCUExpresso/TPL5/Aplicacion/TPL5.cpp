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
#include <TecladoMatricial.h>
#include <Timer.h>
#include <DigitalInput.h>

//Los siguientes #defines estan pensados para la ubicacion de los displays y teclados en la placa Infotronic
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

int main(void) {

	Inicializar();

    while(1) {

    }
    return 0 ;
}
