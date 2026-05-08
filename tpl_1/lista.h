#ifndef LISTA_H
#define LISTA_H
#include "producto.h"

class Lista
{
private:
    Producto* productos;
    int cant_productos;
    int posicion(const Producto& prd);

public:
    Lista();
    ~Lista();

    Producto& operator [](int i);
    void operator +=(Producto& prd);
    void operator -=(Producto& prd);
};

#endif // LISTA_H
