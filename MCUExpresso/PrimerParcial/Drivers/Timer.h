/*
 * Timer.h
 *
 *  Created on: 11 jun. 2023
 *      Author: chor
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "LPC845.h"

class Timer {

	private:

		uint32_t tiempo, recarga;
		void (*funcUsuario) (void);

	public:

		Timer ( uint32_t _tiempo , void (*_funcion) (void) );
		~Timer();

		void start ();
		void stop ();
		void handler ( void );

		void setTiempo ( uint32_t );

		static uint8_t cant_timers;

};

extern Timer **timers;

#endif /* TIMER_H_ */
