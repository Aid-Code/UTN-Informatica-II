/*
 * DriverMotores.h
 *
 *  Created on: 13 nov. 2026
 *      Author: Aiden
 */

#ifndef DRIVERMOTORES_H_
#define DRIVERMOTORES_H_

#include <gpio.h>
#include <LPC845.h>

class DriverMotores
{
private:
	gpio in_1;
	gpio in_2;
	gpio in_3;
	gpio in_4;

public:
	enum Direcciones {ADELANTE, ATRAS, IZQUIERDA, DERECHA, FRENADO};

	DriverMotores(uint8_t pinIn1, uint8_t portIn1, uint8_t pinIn2, uint8_t portIn2, uint8_t pinIn3, uint8_t portIn3, uint8_t pinIn4, uint8_t portIn4, uint8_t pinPwmA, uint8_t portPwmA, uint8_t pinPwmB, uint8_t portPwmB);

	void setDireccion (Direcciones dir);
	void setVelocidad(uint32_t porcentajeA, uint32_t porcentajeB);
};

#endif /* DRIVERMOTORES_H_ */
