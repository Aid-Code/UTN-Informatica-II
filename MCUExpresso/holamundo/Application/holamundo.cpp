#include <cr_section_macros.h>
#include "Init.h"


int main(void)
{
	InitHw();
	unsigned int *d_reg;
	d_reg = (unsigned int *) 0xA0002104;

    while(1)
    {
    	*d_reg &= ~0x002;
    }

    return 0 ;
}
