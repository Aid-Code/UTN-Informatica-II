/*
 * HCSR04.h
 *
 *  Created on: 11 sep. 2026
 *      Author: Aiden
 */

#ifndef HCSR04_H_
#define HCSR04_H_

#include <gpio.h>
#include <LPC845.h>

#if defined (__cplusplus)
extern "C"
{
	void CTIMER0_IRQHandler (void);
}
#endif

typedef struct {
    volatile uint32_t IR;           // 0x000: Interrupt Register
    volatile uint32_t TCR;          // 0x004: Timer Control Register
    volatile uint32_t TC;           // 0x008: Timer Counter
    volatile uint32_t PR;           // 0x00C: Prescale Register
    volatile uint32_t PC;           // 0x010: Prescale Counter
    volatile uint32_t MCR;          // 0x014: Match Control Register
    volatile uint32_t MR0;          // 0x018: Match Register 0
    volatile uint32_t MR1;          // 0x01C: Match Register 1
    volatile uint32_t MR2;          // 0x020: Match Register 2
    volatile uint32_t MR3;          // 0x024: Match Register 3
    volatile uint32_t CCR;          // 0x028: Capture Control Register
    volatile uint32_t CR0;          // 0x02C: Capture Register 0
    volatile uint32_t CR1;          // 0x030: Capture Register 1
    volatile uint32_t CR2;          // 0x034: Capture Register 2
    volatile uint32_t CR3;          // 0x038: Capture Register 3 (reservado/no usado en LPC845)
    volatile uint32_t EMR;          // 0x03C: External Match Register
    volatile uint32_t RESERVED[12]; // 0x040 - 0x06C: Espacio reservado (48 bytes)
    volatile uint32_t CTCR;         // 0x070: Count Control Register
    volatile uint32_t PWMC;         // 0x074: PWM Control Register
    volatile uint32_t MSR0;         // 0x078: Match Shadow Register 0
    volatile uint32_t MSR1;         // 0x07C: Match Shadow Register 1
    volatile uint32_t MSR2;         // 0x080: Match Shadow Register 2
    volatile uint32_t MSR3;         // 0x084: Match Shadow Register 3
} CTIMER_Type;


#define CTIMER_Base (0x40038000u)
#define CTIMER ((CTIMER_Type *) CTIMER_Base)

class HCSR04
{
public:
	HCSR04(uint8_t _pin_trig, uint8_t _port_trig, uint8_t _pin_echo, uint8_t _port_echo);
	uint32_t getDistancia(void);

	friend void CTIMER0_IRQHandler (void);

private:
	uint8_t pin_trig, port_trig, pin_echo, port_echo;
	gpio trig;
	volatile uint32_t distancia, tiempoi, tiempof;
	bool estado_capture;
};

#endif /* HCSR04_H_ */
