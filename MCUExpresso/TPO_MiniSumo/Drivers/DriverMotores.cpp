/*
 * DriverMotores.cpp
 *
 *  Created on: 13 nov. 2026
 *      Author: Aiden
 */

#include <DriverMotores.h>

#define SCT0_BASE       (0x50004000u)

// Control general
#define SCT_CONFIG      (*((__IO uint32_t *)(SCT0_BASE + 0x000u)))
#define SCT_CTRL        (*((__IO uint32_t *)(SCT0_BASE + 0x004u)))
#define SCT_LIMIT       (*((__IO uint32_t *)(SCT0_BASE + 0x008u)))
#define SCT_OUTPUT      (*((__IO uint32_t *)(SCT0_BASE + 0x050u)))

// Match (0 = período, 1 = PWM1, 2 = PWM2)
#define SCT_MATCH0      (*((__IO uint32_t *)(SCT0_BASE + 0x100u)))
#define SCT_MATCH1      (*((__IO uint32_t *)(SCT0_BASE + 0x104u)))
#define SCT_MATCH2      (*((__IO uint32_t *)(SCT0_BASE + 0x108u)))

// Match Reload (para actualizar el duty cycle sin glitches)
#define SCT_MATCHREL0   (*((__IO uint32_t *)(SCT0_BASE + 0x200u)))
#define SCT_MATCHREL1   (*((__IO uint32_t *)(SCT0_BASE + 0x204u)))
#define SCT_MATCHREL2   (*((__IO uint32_t *)(SCT0_BASE + 0x208u)))

// Eventos (0 = fin de período, 1 = flanco bajada PWM1, 2 = flanco bajada PWM2)
#define SCT_EV0_STATE   (*((__IO uint32_t *)(SCT0_BASE + 0x300u)))
#define SCT_EV0_CTRL    (*((__IO uint32_t *)(SCT0_BASE + 0x304u)))
#define SCT_EV1_STATE   (*((__IO uint32_t *)(SCT0_BASE + 0x308u)))
#define SCT_EV1_CTRL    (*((__IO uint32_t *)(SCT0_BASE + 0x30Cu)))
#define SCT_EV2_STATE   (*((__IO uint32_t *)(SCT0_BASE + 0x310u)))
#define SCT_EV2_CTRL    (*((__IO uint32_t *)(SCT0_BASE + 0x314u)))

// Salidas (SCT_OUT0 y SCT_OUT1)
#define SCT_OUT0_SET    (*((__IO uint32_t *)(SCT0_BASE + 0x500u)))
#define SCT_OUT0_CLR    (*((__IO uint32_t *)(SCT0_BASE + 0x504u)))
#define SCT_OUT1_SET    (*((__IO uint32_t *)(SCT0_BASE + 0x508u)))
#define SCT_OUT1_CLR    (*((__IO uint32_t *)(SCT0_BASE + 0x50Cu)))

DriverMotores::DriverMotores(uint8_t pinIn1, uint8_t portIn1, uint8_t pinIn2, uint8_t portIn2, uint8_t pinIn3, uint8_t portIn3, uint8_t pinIn4, uint8_t portIn4, uint8_t pinPwmA, uint8_t portPwmA, uint8_t pinPwmB, uint8_t portPwmB)
:in_1(portIn1, pinIn1, gpio::SALIDA),
 in_2(portIn2, pinIn2, gpio::SALIDA),
 in_3(portIn3, pinIn3, gpio::SALIDA),
 in_4(portIn4, pinIn4, gpio::SALIDA)
{
	uint8_t pwmA = (portPwmA * 32) + pinPwmA;
	uint8_t pwmB = (portPwmB * 32) + pinPwmB;

	// Configuracion de Switch Matrix:
	SYSCON->SYSAHBCLKCTRL0 |= 1<<7; // Habilito Switch Matrix

	// Asignar SCT_OUT0 al pin del PWM A (bits 31:24 de PINASSIGN7)
	PINASSIGN7 &= ~(0xFFu << 24);
	PINASSIGN7 |= ((uint32_t)pwmA << 24);

	// Asignar SCT_OUT1 al pin del PWM B (bits 7:0 de PINASSIGN8)
	PINASSIGN8 &= ~(0xFFu);
	PINASSIGN8 |= (uint32_t)pwmB;

	SYSCON->SYSAHBCLKCTRL0 &= ~(1<<7); // Apago la Switch Matrix

	SYSCON->SYSAHBCLKCTRL0 |= 1<<8; // Habilito el SCTimer
	SYSCON->PRESETCTRL0 &= ~(1<<8);
	SYSCON->PRESETCTRL0 |= 1<<8;

	SCT_CTRL |= 1<<2; // Contador frenado para configurar el SCTimer
	SCT_CONFIG |= 1; // Unifico ambos contadores en uno de 32 bits
	SCT_CTRL |= 1<<3; // Reseteo el contador
	SCT_LIMIT |= 1;

	SCT_MATCH0 = 2999; // Seteo la frecuencia del PWM a 10kHz
	SCT_MATCH1 = 0; // Inicio el duty cycle en 0% por seguridad
	SCT_MATCH2 = 0; // Inicio el duty cycle en 0% por seguridad

	SCT_MATCHREL0 = 2999; // Seteo la frecuencia del PWM a 10kHz
	SCT_MATCHREL1 = 0; // Inicio el duty cycle en 0% por seguridad
	SCT_MATCHREL2 = 0; // Inicio el duty cycle en 0% por seguridad

	SCT_EV0_STATE |= 1;
	SCT_EV0_CTRL |= 1<<12;

	SCT_EV1_STATE |= 1;
	SCT_EV1_CTRL |= 1 | 1<<12;

	SCT_EV2_STATE |= 1;
	SCT_EV2_CTRL |= 2 | 1<<12;

	SCT_OUTPUT = 0;

	// SCT_OUT0: se prende con Evento 0, se apaga con Evento 1
	SCT_OUT0_SET |= 1;
	SCT_OUT0_CLR |= 1<<1;

	// SCT_OUT1: se prende con Evento 0, se apaga con Evento 2
	SCT_OUT1_SET |= 1;
	SCT_OUT1_CLR |= 1<<2;

	SCT_CTRL &= ~(1<<2); // Inicio el contador al terminar de configurar el SCTimer
}

void DriverMotores::setDireccion(Direcciones dir)
{
	switch (dir)
	{
		case ADELANTE:
			in_1.setPIN();
			in_2.clrPIN();
			in_3.setPIN();
			in_4.clrPIN();
		break;

		case ATRAS:
			in_1.clrPIN();
			in_2.setPIN();
			in_3.clrPIN();
			in_4.setPIN();
		break;

		case IZQUIERDA:
			in_1.clrPIN();
			in_2.setPIN();
			in_3.setPIN();
			in_4.clrPIN();
		break;

		case DERECHA:
			in_1.setPIN();
			in_2.clrPIN();
			in_3.clrPIN();
			in_4.setPIN();
		break;

		case FRENADO:
			in_1.setPIN();
			in_2.setPIN();
			in_3.setPIN();
			in_4.setPIN();
		break;
	}
}

void DriverMotores::setVelocidad(uint32_t porcentajeA, uint32_t porcentajeB)
{
	if (porcentajeA > 100) porcentajeA = 100;
	if (porcentajeB > 100) porcentajeB = 100;

	SCT_MATCHREL1 = (porcentajeA * 2999) / 100;
	SCT_MATCHREL2 = (porcentajeB * 2999) / 100;
}
