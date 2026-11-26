/*
 * Oled.cpp
 *
 *  Created on: 25 nov. 2026
 *      Author: Aiden
 */
#include <OLED.h>

// Registros mínimos de I2C1 (base 0x40054000)
#define I2C1_BASE     (0x40054000u)
#define I2C1_CFG      (*((__IO uint32_t *)(I2C1_BASE + 0x000u)))
#define I2C1_STAT     (*((__IO uint32_t *)(I2C1_BASE + 0x004u)))
#define I2C1_CLKDIV   (*((__IO uint32_t *)(I2C1_BASE + 0x014u)))
#define I2C1_MSTCTL   (*((__IO uint32_t *)(I2C1_BASE + 0x020u)))
#define I2C1_MSTTIME  (*((__IO uint32_t *)(I2C1_BASE + 0x024u)))
#define I2C1_MSTDAT   (*((__IO uint32_t *)(I2C1_BASE + 0x028u)))

// Fuente compacta 5x7 (espacio, '-', '.', ':', '0'-'9', 'A'-'Z')
static const uint8_t font5x7[][5] = {
	{0x00,0x00,0x00,0x00,0x00}, // 0: ' '
	{0x08,0x08,0x08,0x08,0x08}, // 1: '-'
	{0x00,0x60,0x60,0x00,0x00}, // 2: '.'
	{0x00,0x36,0x36,0x00,0x00}, // 3: ':'
	{0x3E,0x51,0x49,0x45,0x3E}, // 4: '0'
	{0x00,0x42,0x7F,0x40,0x00}, // 5: '1'
	{0x42,0x61,0x51,0x49,0x46}, // 6: '2'
	{0x21,0x41,0x45,0x4B,0x31}, // 7: '3'
	{0x18,0x14,0x12,0x7F,0x10}, // 8: '4'
	{0x27,0x45,0x45,0x45,0x39}, // 9: '5'
	{0x3C,0x4A,0x49,0x49,0x30}, // 10: '6'
	{0x01,0x71,0x09,0x05,0x03}, // 11: '7'
	{0x36,0x49,0x49,0x49,0x36}, // 12: '8'
	{0x06,0x49,0x49,0x29,0x1E}, // 13: '9'
	{0x7E,0x11,0x11,0x11,0x7E}, // 14: 'A'
	{0x7F,0x49,0x49,0x49,0x36}, // 15: 'B'
	{0x3E,0x41,0x41,0x41,0x22}, // 16: 'C'
	{0x7F,0x41,0x41,0x22,0x1C}, // 17: 'D'
	{0x7F,0x49,0x49,0x49,0x41}, // 18: 'E'
	{0x7F,0x09,0x09,0x09,0x01}, // 19: 'F'
	{0x3E,0x41,0x49,0x49,0x7A}, // 20: 'G'
	{0x7F,0x08,0x08,0x08,0x7F}, // 21: 'H'
	{0x00,0x41,0x7F,0x41,0x00}, // 22: 'I'
	{0x20,0x40,0x41,0x3F,0x01}, // 23: 'J'
	{0x7F,0x08,0x14,0x22,0x41}, // 24: 'K'
	{0x7F,0x40,0x40,0x40,0x40}, // 25: 'L'
	{0x7F,0x02,0x0C,0x02,0x7F}, // 26: 'M'
	{0x7F,0x04,0x08,0x10,0x7F}, // 27: 'N'
	{0x3E,0x41,0x41,0x41,0x3E}, // 28: 'O'
	{0x7F,0x09,0x09,0x09,0x06}, // 29: 'P'
	{0x3E,0x41,0x51,0x21,0x5E}, // 30: 'Q'
	{0x7F,0x09,0x19,0x29,0x46}, // 31: 'R'
	{0x46,0x49,0x49,0x49,0x31}, // 32: 'S'
	{0x01,0x01,0x7F,0x01,0x01}, // 33: 'T'
	{0x3F,0x40,0x40,0x40,0x3F}, // 34: 'U'
	{0x1F,0x20,0x40,0x20,0x1F}, // 35: 'V'
	{0x3F,0x40,0x38,0x40,0x3F}, // 36: 'W'
	{0x63,0x14,0x08,0x14,0x63}, // 37: 'X'
	{0x07,0x08,0x70,0x08,0x07}, // 38: 'Y'
	{0x61,0x51,0x49,0x45,0x43}  // 39: 'Z'
};

OLED::OLED(uint8_t direccionI2C) : addr(direccionI2C) {}

void OLED::i2cInit() {
	// 1. Configurar PIO0_23 (SDA) y PIO0_22 (SCL) como Open-Drain en IOCON
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 18); // Clock de IOCON
	IOCON->PIO[25] |= (1 << 10);         // PIO0_23 (offset 0x64) -> Open-Drain
	IOCON->PIO[26] |= (1 << 10);         // PIO0_22 (offset 0x68) -> Open-Drain
	SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 18);

	// 2. Asignar I2C1_SDA a PIO0_23 (bits 23:16) e I2C1_SCL a PIO0_22 (bits 31:24) en PINASSIGN9
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);  // Clock de Switch Matrix
	PINASSIGN9 &= ~((0xFFu << 16) | (0xFFu << 24));
	PINASSIGN9 |= (23u << 16) | (22u << 24);
	SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);

	// 3. Clock de I2C1 (Main clock) y reset del periférico
	SYSCON->FCLKSEL[6] = 1;              // I2C1CLKSEL = Main clock
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 21); // Habilito clock de I2C1
	SYSCON->PRESETCTRL0 &= ~(1 << 21);   // Reset de I2C1
	SYSCON->PRESETCTRL0 |= (1 << 21);

	// 4. Velocidad ~100-250 kHz y modo Master
	I2C1_CLKDIV  = 14;
	I2C1_MSTTIME = 0x22;
	I2C1_CFG    |= 1;
}

void OLED::i2cWrite(uint8_t control, uint8_t data) {
	while (!(I2C1_STAT & 1));             // Espero bus libre
	I2C1_MSTDAT = (addr << 1);            // Dirección + bit Write (0)
	I2C1_MSTCTL = (1 << 1);               // START

	while (!(I2C1_STAT & 1));
	I2C1_MSTDAT = control;                // 0x00 = comando, 0x40 = dato
	I2C1_MSTCTL = (1 << 0);               // CONTINUE

	while (!(I2C1_STAT & 1));
	I2C1_MSTDAT = data;
	I2C1_MSTCTL = (1 << 0);               // CONTINUE

	while (!(I2C1_STAT & 1));
	I2C1_MSTCTL = (1 << 2);               // STOP
}

void OLED::sendCmd(uint8_t cmd)   { i2cWrite(0x00, cmd);  }
void OLED::sendData(uint8_t data) { i2cWrite(0x40, data); }

void OLED::init() {
	for (volatile uint32_t i = 0; i < 300000; i++);

	i2cInit();

	sendCmd(0xAE); // Display OFF
	sendCmd(0x20); sendCmd(0x02); // Page addressing mode
	sendCmd(0xA8); sendCmd(0x1F); // 64 filas (cambiar a 0x1F si es 128x32)
	sendCmd(0xD3); sendCmd(0x00); // Display offset = 0
	sendCmd(0x40); // Start line = 0
	sendCmd(0xA1); // Segment remap
	sendCmd(0xC8); // COM scan direction
	sendCmd(0xDA); sendCmd(0x02); // COM pins (cambiar a 0x02 si es 128x32)
	sendCmd(0x81); sendCmd(0xCF); // Contraste
	sendCmd(0x8D); sendCmd(0x14); // Charge pump ON
	sendCmd(0xAF); // Display ON
	sendCmd(0xA5); // PRUEBA: prende TODOS los píxeles en blanco

	clear();
}

void OLED::setCursor(uint8_t col, uint8_t fila) {
	sendCmd(0xB0 + (fila & 0x07));
	sendCmd(0x00 + (col & 0x0F));
	sendCmd(0x10 + ((col >> 4) & 0x0F));
}

void OLED::clear() {
	for (uint8_t fila = 0; fila < 8; fila++) {
		setCursor(0, fila);
		for (uint8_t col = 0; col < 128; col++) {
			sendData(0x00);
		}
	}
	setCursor(0, 0);
}

void OLED::drawChar(char c) {
	if (c >= 'a' && c <= 'z') c -= 32; // Pasa minúsculas a mayúsculas

	uint8_t idx = 0;
	if      (c == '-') idx = 1;
	else if (c == '.') idx = 2;
	else if (c == ':') idx = 3;
	else if (c >= '0' && c <= '9') idx = 4 + (c - '0');
	else if (c >= 'A' && c <= 'Z') idx = 14 + (c - 'A');

	for (uint8_t i = 0; i < 5; i++) sendData(font5x7[idx][i]);
	sendData(0x00); // Espacio entre letras
}

void OLED::print(const char* texto) {
	while (*texto) {
		drawChar(*texto++);
	}
}
