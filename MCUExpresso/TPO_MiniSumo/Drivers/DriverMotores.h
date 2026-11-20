/*
 * DriverMotores.h
 *
 *  Created on: 13 nov. 2026
 *      Author: abril
 */

#ifndef DRIVERMOTORES_H_
#define DRIVERMOTORES_H_

#include <gpio.h>

class DriverMotores
{
public:
	gpio *sumo;
	DriverMotores(gpio *pinesMot);
	virtual ~DriverMotores();
	void Izq(void);
	void Der(void);
	void Fordw(void);
	void Revers(void);
};

#endif /* DRIVERMOTORES_H_ */
