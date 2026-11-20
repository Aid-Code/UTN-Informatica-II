/*
 * DriverMotores.cpp
 *
 *  Created on: 13 nov. 2026
 *      Author: abril
 */

#include <DriverMotores.h>

DriverMotores::DriverMotores(gpio *_pinesMot) {
	sumo = _pinesMot;
}

DriverMotores::~DriverMotores() {

}


void DriverMotores::Izq(void){
	sumo[1].setPIN();
	sumo[2].clrPIN();
	sumo[3].clrPIN();
	sumo[4].setPIN();
}

void DriverMotores::Der(void){
	sumo[1].clrPIN();
	sumo[2].setPIN();
	sumo[3].setPIN();
	sumo[4].clrPIN();
}

void DriverMotores::Fordw(void){
	sumo[1].clrPIN();
	sumo[2].setPIN();
	sumo[3].clrPIN();
	sumo[4].setPIN();
}

void DriverMotores::Revers(void){
	sumo[1].setPIN();
	sumo[2].clrPIN();
	sumo[3].setPIN();
	sumo[4].clrPIN();
}
