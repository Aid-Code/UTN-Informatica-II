#include <cr_section_macros.h>
#include "Init.h"
#include "gpio.h"


int main(void)
{
	InitHw();

	gpio led(1, 1, gpio::SALIDA, gpio::HIGH);
	setPin(gpio::LOW);

	int i = 0;

    while(1)
    {
    	if (i == 15000)

    }

    return 0 ;
}
