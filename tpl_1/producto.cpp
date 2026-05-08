#include "producto.h"
#include <iostream>

using namespace std;

Producto::Producto(int cd, string ds, int pr):codigo(cd),descriptor(ds),precio(pr){}
Producto::Producto(Producto &prd):codigo(prd.codigo),descriptor(prd.descriptor),precio(prd.precio){}


int Producto::getCodigo(){    return codigo;    }
int Producto::getPrecio(){    return precio;    }
string Producto::getDescriptor(){    return descriptor;     }

void Producto::setCodigo(int cd){    codigo = cd;    }
void Producto::setPrecio(int pr){    precio = pr;    }
void Producto::setDescriptor(string ds){    descriptor = ds;     }

bool Producto::operator ==(const Producto &prd)
{
    if (codigo == prd.codigo && precio == prd.precio && descriptor == prd.descriptor) return true;
    else return false;
}

Producto& Producto::operator =(const Producto &prd)
{
    codigo = prd.codigo;
    precio = prd.precio;
    descriptor = prd.descriptor;

    return (*this);
}

ostream& operator <<(ostream& o, Producto &prd)
{
    o<<"Producto: "<<prd.descriptor<<" - Codigo: "<<prd.codigo<<" Precio: $"<<prd.precio<<endl; //Producto: DESCRIPTOR - Codigo: CODIGO - Precio: $PRECIO

    return o;
}