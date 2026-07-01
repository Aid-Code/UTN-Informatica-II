/*
 * Timer.h
 *
 *  Created on: 11 jun. 2023
 *      Author: chor
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <LPC845.h>
#include <clasesTemporizadas.h>

class Timer : public clasesTemporizadas {

	private:
		uint32_t tiempo, recarga;
		bool recargar;
		void (*Handler) (void);

	public:
		Timer ( uint32_t _tiempo , void (*_H) (void) , bool _recargar = false );
		~Timer();

		void start ();
		void stop ();
		void handler ( void );
		void setTime (uint32_t );
};

#endif /* TIMER_H_ */
