#include "SensorAnalogico.h"

// Inicializamos el puntero estático
SensorAnalogico* SensorAnalogico::instancia_ptr = nullptr;

SensorAnalogico::sensorAnalogico(uint32_t frec, uint8_t tam_vec) {
    tamano = tam_vec;
    vector_muestras = new uint32_t[tamano];
    indice_actual = 0;

    // Inicializo el vector en 0 por seguridad
    for(uint8_t i = 0; i < tamano; i++) {
        vector_muestras[i] = 0;
    }

    // Guardo la dirección de ESTE objeto para que el handler lo encuentre
    instancia_ptr = this;

    // Cálculo del divisor: 30MHz / DIV = Frec_muestreo -> DIV = 30MHz / frec
    uint32_t div = 30000000 / frec;
    if (div > 63) div = 63; // Limitamos a 6 bits (0 a 63)

    // Configuración del registro ADCCFG (limpiamos primero)
    ADCCFG = 0;

    // bit 0 en 1 (Deshabilitado inicialmente)
    // bits 1:6 con el divisor
    // bit 7 en 1 (Habilita la interrupción)
    ADCCFG |= (1 << 0) | (div << 1) | (1 << 7);

    // Habilitar la interrupción en el NVIC (ISER0 bit 5)
    ISER0 |= (1 << 5);
}

SensorAnalogico::~sensorAnalogico() {
    delete[] vector_muestras; // Liberamos la memoria del heap
}

void SensorAnalogico::start() {
    // 0 es habilitado según la tabla
    ADCCFG &= ~(1 << 0);
}

void SensorAnalogico::stop() {
    // 1 es deshabilitado
    ADCCFG |= (1 << 0);
}

uint32_t& SensorAnalogico::operator[](uint8_t index) {
    return vector_muestras[index];
}

uint32_t SensorAnalogico::operator<<(int dummy) {
    // Si el índice actual es 0, el último valor que cargamos fue en el final del vector
    int8_t ultimo_indice = indice_actual - 1;
    if (ultimo_indice < 0) {
        ultimo_indice = tamano - 1;
    }
    return vector_muestras[ultimo_indice];
}

uint32_t SensorAnalogico::getValor() {
    uint32_t suma = 0;
    for(uint8_t i = 0; i < tamano; i++) {
        suma += vector_muestras[i];
    }
    return suma / tamano; // Retornamos el promedio
}

// ----------------------------------------------------------------
// RUTINA DE INTERRUPCIÓN (Fuera de la clase, código C puro)
// ----------------------------------------------------------------
extern "C" void ADC_Handler(void) {
    // Verificamos que el objeto haya sido instanciado
    if (SensorAnalogico::instancia_ptr != nullptr) {

        // Leemos el valor del hardware
        uint32_t valor_leido = ADCVALUE;

        // Usamos el operador [] privado para guardar el valor
        (*SensorAnalogico::instancia_ptr)[SensorAnalogico::instancia_ptr->indice_actual] = valor_leido;

        // Avanzamos el índice (buffer circular)
        SensorAnalogico::instancia_ptr->indice_actual++;
        if (SensorAnalogico::instancia_ptr->indice_actual >= SensorAnalogico::instancia_ptr->tamano) {
        	SensorAnalogico::instancia_ptr->indice_actual = 0;
        }
    }
}
