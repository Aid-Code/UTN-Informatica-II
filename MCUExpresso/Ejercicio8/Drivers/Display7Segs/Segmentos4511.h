/*
 * segmentosDirecto.h
 *
 *  Created on: 26 jun. 2023
 *      Author: chor
 */

#ifndef SEGMENTOS_H_
#define SEGMENTOS_H_

#include "LPC845.h"
#include "gpio.h"
#include <Segmentos.h>

class Segmentos4511 : public Segmentos {

public:

	Segmentos4511 ( gpio * vec_segs ):Segmentos(vec_segs,4){}
	void setValor( uint8_t val);

};

#endif /* SEGMENTOS_H_ */
