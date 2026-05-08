#include "lista.h"

Lista::Lista():productos(nullptr){  cant_productos = 0; }

Lista::~Lista()
{
    if (productos != nullptr)
    {
        delete[] productos;
        cant_productos--;
    }
}

Producto& Lista::operator [](int i){    return productos[i];    }

void Lista::operator +=(Producto &prd)
{
    if (productos == nullptr)
    {
        productos = new Producto[1];
        productos[0] = prd;
        cant_productos++;
    }
    else
    {
        cant_productos++;
        Producto* aux = new Producto[cant_productos];

        for (int i = 0; i < cant_productos-1; i++)
            aux[i] = productos[i];

        aux[cant_productos-1] = prd;

        delete[] productos;
        productos = aux;
    }
}