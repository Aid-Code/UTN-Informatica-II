/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such terms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */

#include <cr_section_macros.h>
#include <LPC845.h>
#include <gpio.h>
#include <HCSR04.h>
#include <AnalogInput.h>
#include <DriverMotores.h>
#include <Uart.h>
#include <Timer.h>
#include <Init.h>

#define UMBRAL_PISO ((270 + 370)/2)
#define UMBRAL_ATAQUE 15

enum Estados {INICIO, ATAQUE, RETROCESO, BUSQUEDA};

volatile bool flag_inicio = false;
volatile bool flag_retroceso = false;

void handler_inicio(void)    { flag_inicio = true; }
void handler_retroceso(void) { flag_retroceso = true; }

volatile bool flag_delay = false;
void handler_delay (void) { flag_delay = true; }

Timer timer_delay(1, handler_delay);

volatile bool flag_wifi = false;
void handler_wifi(void) { flag_wifi = true; }
Timer timer_wifi(200, handler_wifi);

char trama_wifi[32];
uint8_t largo_trama = 0;
bool esperando_datos = false;

Uart esp(1, 115200, 17, 16);

void agregar_num(char *buf, uint8_t &pos, uint32_t num);
void enviar_telemetria_wifi(uint32_t piso, uint32_t distancia, uint32_t estado);
void IniciarWifi(void);
void delayMs(uint32_t ms);

int main(void)
{
	Inicializar();
	IniciarWifi();

	HCSR04 ultrasonico(27, 0, 26, 0);
	AnalogInput qtr (2);
	DriverMotores driver(1, 0, 6, 0, 20, 0, 19, 0, 0, 0, 18, 0);

	Timer timer_inicio(5000, handler_inicio);      // 5 segundos
	Timer timer_retroceso(500, handler_retroceso); // 500 ms

	timer_inicio.stop();
	timer_retroceso.stop();

	Estados estado = INICIO;

	uint32_t lecturas[] = {0, 0};

	driver.setVelocidad(0, 0);
	timer_inicio.start();

	while(1)
    {
		lecturas[0] = ultrasonico.getDistancia();
		lecturas[1] = qtr.getValor();

		enviar_telemetria_wifi(lecturas[1], lecturas[0], (uint32_t)estado);

    	switch (estado)
		{
			case INICIO:
				if (flag_inicio)
				{
					flag_inicio = false;
					estado = BUSQUEDA;
				}
			break;

			case ATAQUE:
				driver.setVelocidad();
				driver.setDireccion(DriverMotores::ADELANTE);

				if (lecturas[1] <= UMBRAL_PISO)
				{
					flag_retroceso = false;
					timer_retroceso.start();
					estado = RETROCESO;
				}
				else if (lecturas[0] > UMBRAL_ATAQUE)
				{
					estado = BUSQUEDA;
				}
			break;

			case BUSQUEDA:
				driver.setVelocidad(50, 50);
				driver.setDireccion(DriverMotores::DERECHA);

				if (lecturas[1] <= UMBRAL_PISO)
				{
					flag_retroceso = false;
					timer_retroceso.start();
					estado = RETROCESO;
				}
				else if (lecturas[0] != 0 && lecturas[0] <= UMBRAL_ATAQUE)
				{
					estado = ATAQUE;
				}
			break;

			case RETROCESO:
				driver.setVelocidad();
				driver.setDireccion(DriverMotores::ATRAS);
				if (flag_retroceso)
				{
					flag_retroceso = false;
					estado = BUSQUEDA;
				}
			break;
		}
    }
    return 0;
}

void agregar_num(char *buf, uint8_t &pos, uint32_t num)
{
    if (num == 0)
    {
        buf[pos++] = '0';
        return;
    }
    char temp[10];
    uint8_t i = 0;

    while (num > 0)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0) buf[pos++] = temp[--i];
}

void IniciarWifi()
{
    delayMs(1000);

    esp.Transmitir((uint8_t*)"AT+CWMODE=2\r\n", 13);
    delayMs(300);

    esp.Transmitir((uint8_t*)"AT+CWSAP=\"RobotWiFi\",\"12345678\",5,3\r\n", 37);
    delayMs(1000);

    esp.Transmitir((uint8_t*)"AT+CIPMUX=0\r\n", 13);
    delayMs(300);

    esp.Transmitir((uint8_t*)"AT+CIPSTART=\"UDP\",\"192.168.4.255\",4210\r\n", 40);
    delayMs(300);

    timer_wifi.start(); // Arranca el ciclo de envíos cada 200 ms
}

void enviar_telemetria_wifi(uint32_t piso, uint32_t distancia, uint32_t estado)
{
    if (!flag_wifi) return;
    flag_wifi = false;

    if (!esperando_datos)
    {
        largo_trama = 0;
        agregar_num(trama_wifi, largo_trama, piso);
        trama_wifi[largo_trama++] = ',';
        agregar_num(trama_wifi, largo_trama, distancia);
        trama_wifi[largo_trama++] = ',';
        agregar_num(trama_wifi, largo_trama, estado);

        char cmd[20] = "AT+CIPSEND=";
        uint8_t posCmd = 11;
        agregar_num(cmd, posCmd, largo_trama);
        cmd[posCmd++] = '\r';
        cmd[posCmd++] = '\n';

        esp.Transmitir((uint8_t*)cmd, posCmd);
        esperando_datos = true;
        timer_wifi.setTiempo(20);
        timer_wifi.start();
    }
    else
    {
        esp.Transmitir((uint8_t*)trama_wifi, largo_trama);
        esperando_datos = false;
        timer_wifi.setTiempo(200);
        timer_wifi.start();
    }
}

void delayMs(uint32_t ms) // Delay bloqueante - SOLO PARA INICIAR WIFI
{
	flag_delay = false;
	timer_delay.setTiempo(ms);
	timer_delay.start();

    while (!flag_delay);
}
