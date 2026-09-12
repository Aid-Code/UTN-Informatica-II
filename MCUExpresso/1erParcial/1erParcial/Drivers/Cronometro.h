/*
 * Cronometro.h
 *
 *  Created on: 3 jul. 2026
 *      Author: Aiden
 */

#ifndef CRONOMETRO_H_
#define CRONOMETRO_H_
#include <LPC845.h>
#include "PerifericoTemporizado.h"

class Cronometro: public PerifericoTemporizado
{
public:
	enum base_t { milis = 1 , dec = 100 , seg = 1000};
	Cronometro(base_t _base = milis);

	void handler (void);
	void start (void);
	void stop (void);
	void pause (void);

	uint32_t getTiempo (void);

	bool operator== (int val);
	bool operator< (int val);
	bool operator> (int val);

private:
	uint32_t tiempo;
	base_t base;
	bool encendido;
};

#endif /* CRONOMETRO_H_ */
