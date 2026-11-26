/*
 * Oled.h
 *
 *  Created on: 25 nov. 2026
 *      Author: Aiden
 */

#ifndef OLED_H_
#define OLED_H_

#include <LPC845.h>

class OLED {
private:
	uint8_t addr;
	void i2cInit();
	void i2cWrite(uint8_t control, uint8_t data);
	void sendCmd(uint8_t cmd);
	void sendData(uint8_t data);
	void drawChar(char c);

public:
	OLED(uint8_t direccionI2C = 0x3C);
	void init();
	void clear();
	void setCursor(uint8_t col, uint8_t fila); // col: 0..127, fila: 0..7
	void print(const char* texto);
};

#endif /* OLED_H_ */
