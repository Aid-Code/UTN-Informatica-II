#include "fideo.h"
#include <iostream>

using namespace std;

Fideo::Fideo(string marca, Tipo tipo, int codigo, string descriptor, int precio):Producto(codigo, descriptor, precio),marca(marca),tipo(tipo){}


string Fideo::getMarca(){   return marca;   }
Fideo::Tipo Fideo::getTipo(){  return tipo;    }

void Fideo::setMarca(string marc){   marca = marc;    }
void Fideo::setTipo(Tipo tip){   tipo = tip;     }

bool Fideo::operator ==(const Fideo &fid)
{
    if ((Producto&)*this == (Producto&)fid && marca == fid.marca && tipo == fid.tipo)
        return true;
    else return false;
}

Fideo& Fideo::operator =(const Fideo &fid)
{
    (Producto&)*this = (Producto&)fid;
    marca = fid.marca;
    tipo = fid.tipo;

    return (*this);
}

ostream& operator <<(ostream& o, Fideo &fid)
{
    o<<(Producto&)fid<<"Marca: "<<fid.marca<<" - Tipo: "<<fid.tipos[fid.tipo]<<endl;

    return o;
}