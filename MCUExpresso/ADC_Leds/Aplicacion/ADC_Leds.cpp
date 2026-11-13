#include <serialCom.h>
#include <gpio.h>
#include <Init.h>
#include <serialCom.h>
#include <Timer.h>
#include <DigitalInput.h>
#include <AnalogInput.h>


#define MAX_APAGADO 1000
#define MAX_AZUL	2000
#define MAX_ROJO	3000



int main(void) {

	Inicializar();

	serialCom comStick(0,9600);

	AnalogInput ad1(0 , 10000 , 10);

	uint32_t dato;
	DigitalInput usr (0,4,gpio::LOW);
	gpio ledVerde(1,0,gpio::SALIDA,gpio::LOW);
	gpio ledAzul (1,1,gpio::SALIDA,gpio::LOW);
	gpio ledRojo (1,2,gpio::SALIDA,gpio::LOW);

	while(1) {
		dato = ad1.getValor();

		if(dato < MAX_APAGADO)
		{
			ledVerde.clrPIN();
			ledAzul.clrPIN();
			ledRojo.clrPIN();
		}
		else if(dato > MAX_APAGADO && dato < MAX_AZUL)
		{
			ledAzul.setPIN();
			ledVerde.clrPIN();
			ledRojo.clrPIN();
		}
		else if(dato > MAX_AZUL && dato < MAX_ROJO)
		{
			ledRojo.setPIN();
			ledVerde.clrPIN();
			ledAzul.clrPIN();
		}
		else if(dato > MAX_ROJO)
		{
			ledVerde.setPIN();
			ledAzul.clrPIN();
			ledRojo.clrPIN();
		}

		if(usr.getKey())
		{
			comStick.Transmitir(dato);
		}

	}
    return 0 ;
}


