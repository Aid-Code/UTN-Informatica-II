/*
 * Contador.h
 *
 *  Created on: 28 jun. 2026
 *      Author: Aiden
 */

#ifndef CONTADOR_H_
#define CONTADOR_H_
#include "LPC845.h"

typedef struct {
	uint32_t CFG;
	uint32_t VALUE;
}CNT_Type;

#define CNT ((CNT_Type*)0x400AC000)

class Contador
{
private:
	uint8_t puerto;
	uint8_t pin;
	uint8_t actividad;
	uint32_t tiempos[10];

public:
	enum nivel_act {LOW = 0, HIGH};
	Contador(uint8_t port, uint8_t _pin, uint8_t act);

	void handler (void);
	uint32_t getTiempo(void);
	void start(void);
	void stop(void);

	extern friend void CNT_IRQHandler (void);
};

#endif /* CONTADOR_H_ */
