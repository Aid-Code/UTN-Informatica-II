#ifndef SENSOR_ANALOGICO_H_
#define SENSOR_ANALOGICO_H_

#include <LPC845.h>

// Definiciones de los registros según el parcial
#define ADCCFG   (*((volatile uint32_t*)0x400AC000))
#define ADCVALUE (*((volatile uint32_t*)0x400AC004)) // Asumo el offset 0x04 para el valor
#define ISER0    (*((volatile uint32_t*)0xE000E100))

class SensorAnalogico {
private:
    uint32_t* vector_muestras; // Vector dinámico
    uint8_t tamano;
    uint8_t indice_actual;

    // Puntero estático indispensable para que el handler sepa a qué objeto hablarle
    static sensorAnalogico* instancia_ptr;

    // Sobrecarga privada para cargar/leer en una posición
    uint32_t& operator[](uint8_t index);

public:
    SensorAnalogico(uint32_t frec, uint8_t tam_vec);
    ~SensorAnalogico(); // Buena práctica: liberar la memoria dinámica

    void start();
    void stop();

    // Promedio del vector
    uint32_t getValor();

    // Sobrecarga de << para leer el último valor.
    // En C++ necesita un parámetro aunque no se use (dummy)
    uint32_t operator<<(int dummy);

    // Hacemos amiga a la interrupción para que acceda a métodos y atributos privados
    friend void ADC_Handler(void);
};

#endif /* SENSOR_ANALOGICO_H_ */
