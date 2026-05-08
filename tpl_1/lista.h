#ifndef LISTA_H
#define LISTA_H
#include "producto.h"

class Lista
{
private:
    Producto* productos;
    int cant_productos;

public:
    Lista();
    ~Lista();

    Producto& operator [](int i);
    void operator+= (Producto &prd);
};

#endif // LISTA_H
