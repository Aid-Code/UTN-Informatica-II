#include <serialCom.h>
#include <gpio.h>
#include <Init.h>
#include <serialCom.h>
#include <Timer.h>
#include <DigitalInput.h>
#include <AnalogInput.h>

void funcionLectura (void);


serialCom comStick(0,9600);
AnalogInput ad1(11 , 10000 , 10); //11 en canal para P0.4
Timer timerLectura(1000,funcionLectura);

bool send = false;
uint32_t cuentas;

int main(void) {

	Inicializar();
	timerLectura.start();
	while(1) {

	}
    return 0 ;
}

void funcionLectura ( void )
{
	cuentas = ad1.getValor();
	comStick.Transmitir(cuentas);
	timerLectura.start();
}

