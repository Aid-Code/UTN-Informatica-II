/*
 * entradaFiltrada.cpp
 *
 *  Created on: 28 jun. 2023
 *      Author: chor
 */

#include <DigitalInput.h>


DigitalInput::DigitalInput(uint8_t port , uint8_t _pin , uint8_t actividad_on):gpio(port,_pin,gpio::ENTRADA,actividad_on)
{
	//Empiezo con el buffer indicando que esta desactivada:
	buffer_key = DESACTIVADA;
	contador = 0;
	valor_anterior = buffer_key;

}


uint8_t DigitalInput::getKey()
{
	uint8_t retorno = buffer_key;

	if ( retorno == ACTIVADA )
		//Pongo la variable en estado "desactivado":
		buffer_key = DESACTIVADA;

	return retorno;
}

void DigitalInput::handler ()
{

}
