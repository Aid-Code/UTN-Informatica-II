/*
 * Cronometro.h
 *
 *  Created on: 3 abr. 2025
 *      Author: chor
 */

#ifndef CRONOMETRO_H_
#define CRONOMETRO_H_

#include <PerifericoTemporizado.h>
#include "LPC845.h"

class Cronometro : public PerifericoTemporizado {
private:
	uint32_t tiempo;
	bool contando;

public:
	Cronometro();

	void start();
	void stop();
	void pause();
	uint32_t getTime();
	void handler(void);

};

#endif /* CRONOMETRO_H_ */
