#include "punto.h"

Punto::Punto(int dato_x, int dato_y)
{
    x = dato_x;
    y = dato_y;
}

int Punto::get_x()
{
    return x;
}

int Punto::get_y()
{
    return y;
}