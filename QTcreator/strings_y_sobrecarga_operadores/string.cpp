#include "string.h"

String::String(char* cadena, int largo)
{
    longitud = largo;
    inicio = new char[longitud];
    for (int i = 0; i < longitud; i++)
    {
        inicio[i] = cadena[i];
    }
}

String::~String()
{
    delete[] inicio;
}