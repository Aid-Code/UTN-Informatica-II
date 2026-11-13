/*
 * Uart.cpp
 *
 *  Created on: 10 sep. 2023
 *      Author: chor
 */

#include <Uart.h>

Uart *uarts[4] = {nullptr,nullptr,nullptr,nullptr};

Uart::Uart( uint8_t numUart , uint32_t baudR , uint8_t pinTx , uint8_t pinRx )
{
	//Variables para Transmision:
	bufTx = nullptr;
	tamBuffer = 0;
	bytesEnviados = 0;
	enviando = false;
	datoNuevo = false;

	n_uart = numUart;
	uarts[n_uart] = this;

	baudrate = baudR;

	// HABILITO LA UART:
	uint8_t shift = 14 + n_uart;
	SYSCON->SYSAHBCLKCTRL0 |= (1 << shift);

	//Reseteo la UART:
	SYSCON->PRESETCTRL0 &= ~(1<<shift);
	SYSCON->PRESETCTRL0 |= (1<<shift);

	//Habilito el CLK a la SWM:
	SYSCON->SYSAHBCLKCTRL0 |= (1<<7);

	switch ( n_uart)
	{
		case 0:
			// CONFIGURO LA SWITCH MATRIX
			PINASSIGN0 &= ~(0x0000FFFF);
			PINASSIGN0 |= (pinTx << 0) | (pinRx << 8);
			//Seteo la direccion de la uart a configurar
			dir_uart = USART0;
			break;
		case 1:
			// CONFIGURO LA SWITCH MATRIX
			PINASSIGN1 &= ~(0x00FFFF00);
			PINASSIGN1 |= (pinTx << 8) | (pinRx << 16);
			//Seteo la direccion de la uart a configurar
			dir_uart = USART1;
			break;
		case 2:
			// CONFIGURO LA SWITCH MATRIX
			PINASSIGN2 &= ~(0xFFFF0000);
			PINASSIGN2 |= (pinTx << 16) | (pinRx << 24);
			//Seteo la direccion de la uart a configurar
			dir_uart = USART2;
			break;

		case 3:
			// CONFIGURO LA SWITCH MATRIX
			PINASSIGN11 &= ~(0xFF000000);
			PINASSIGN12 &= ~(0x000000FF);
			PINASSIGN11 |= (pinTx << 24);
			PINASSIGN12 |= pinRx;
			//Seteo la direccion de la uart a configurar
			dir_uart = USART3;
			break;
	}

	// CONFIGURACION GENERAL
	dir_uart->CFG = 	(0 << 0)		// 0=DISABLE 1=ENABLE
						| (1 << 2)		// 0=7BITS 1=8BITS 2=9BITS
						| (0 << 4)		// 0=NOPARITY 2=PAR 3=IMPAR
						| (1 << 6)		// 0=1BITSTOP 1=2BITSTOP
						| (0 << 9)		// 0=NOFLOWCONTROL 1=FLOWCONTROL
						| (0 << 11);	// 0=ASINCRONICA 1=SINCRONICA

	// CONFIGURACION INTERRUPCIONES
	dir_uart->INTENSET = (1 << 0);	//RX

	// CONFIGURACION DEL BAUDRATE
	//CLK = FRO = 30MHz
	if ( n_uart == 0 )
		UART0CLKSEL = 0;
	else if ( n_uart == 1 )
		UART1CLKSEL = 0;
	else if ( n_uart == 2 )
		UART2CLKSEL = 0;
	else if ( n_uart == 3 )
		UART3CLKSEL = 0;

	dir_uart->BRG = (30000000 / (baudrate* 16));

	//Habilito interrupcion USART0 en el NVIC
	shift = 3 + n_uart;
	ISER0 |= (1 << shift);

	// ENABLE LA UART
	dir_uart->CFG |= 1;
}

uint32_t Uart::getBaudR()
{
	return baudrate;

}

void Uart::setBaudR ( uint32_t br)
{
	baudrate = br;
	//Reconfiguro Baudrate
	dir_uart->BRG = (30000000 / (baudrate* 16));
}


void Uart::Transmitir ( const char * s )
{
	int i;
	if ( tamBuffer == 0 )
	{
		for ( i = 0 ; s[i] != '\0'  ; i++ );
		bufTx = new uint8_t[i*2];
		tamBuffer = i*2;
	}

	if ( !enviando )
	{
		for ( i = 0 ; s[i] != '\0' && i < tamBuffer-1 ; i++ )
		{
			bufTx[i] = s[i];
		}
		bufTx[i] = '\0';

		enviando = true;
		dir_uart->INTENSET = 0x04;
	}
	else
	{
		int j;
		for ( i = 0 ; bufTx[i] != '\0'  ; i++ );
		for ( j = 0 ; s[j] != '\0'&& j < tamBuffer-1 ; j++ )
		{
			bufTx[i+j] = s[j];
		}
		bufTx[j+i] = '\0';
	}

}

void Uart::handlerIRQ ( void )
{
	uint32_t stat = dir_uart->STAT;

	//Si la IRQ se generó por Rx
	if ( stat & 0x01 )
	{
		byteRx = dir_uart->RXDAT;
		datoNuevo = true;
	}

	//Si la IRQ se generó por Tx
	if ( stat & 0x04 )
	{
		uint8_t aux = bufTx[bytesEnviados];
		if ( aux == '\0')
		{
			enviando = false;
			bytesEnviados = 0;
			dir_uart->INTENCLR = 0x04;
			delete[] bufTx;
			tamBuffer = 0;
			bufTx = nullptr;
		}
		else
		{
			dir_uart->TXDAT = aux;
			bytesEnviados++;
		}
	}
}

int16_t Uart::Recibir ()
{
	int16_t retorno = NO_DATA;

	if ( datoNuevo )
	{
		datoNuevo = false;
		retorno = byteRx;
	}

	return retorno;
}

void UART0_IRQHandler (void)
{
	if ( uarts[0] != nullptr )
		uarts[0]->handlerIRQ();
}
void UART1_IRQHandler (void)
{
	if ( uarts[1] != nullptr )
		uarts[1]->handlerIRQ();
}
void UART2_IRQHandler (void)
{
	if ( uarts[2] != nullptr )
		uarts[2]->handlerIRQ();
}
void UART3_IRQHandler (void)
{
	if ( uarts[3] != nullptr )
		uarts[3]->handlerIRQ();
}











