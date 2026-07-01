/*
 * clasesTemporizadas.h
 *
 *  Created on: 30 jun. 2026
 *      Author: Aiden
 */

#ifndef CLASESTEMPORIZADAS_H_
#define CLASESTEMPORIZADAS_H_

#include <LPC845.h>

class clasesTemporizadas
{
private:
	void (*funcUsuario) (void);
	static uint32_t cant_obj;
	static clasesTemporizadas** perifericos;

public:
	clasesTemporizadas( void (*h) (void) = nullptr );
	~clasesTemporizadas();

	virtual void handler (void);
	static void atenderInterrupcion(void);

};

#endif /* CLASESTEMPORIZADAS_H_ */
