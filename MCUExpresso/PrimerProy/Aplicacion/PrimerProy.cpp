/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include <Init.h>

#define DIR_REG (unsigned int *)0xA0002104

int main(void) {

	unsigned int i = 0;

	//Inicializo algunos periféricos para que el uC funcione a 30MHz:
	InitHw();

	unsigned int *pReg = DIR_REG;

    while(1) {

		i++;
		//cuando i llega a un determinado valor cambio de valor el registro:
		if ( i == 1500000 )
		{
			*pReg += 1;
		}
		//Cuando llega al doble de ese valor vuelvo a empezar y reseteo el registro:
		if ( i == 3000000 )
		{
			*pReg -= 1;
			i = 0;
		}

    }
    return 0 ;
}
