#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto
{
private:
    int codigo;
    string descriptor;
    int precio;

public:
    Producto(int cd = -1, string ds = "VACIO", int pr = -1);
    Producto(Producto &prd);

    int getCodigo();
    int getPrecio();
    string getDescriptor();

    void setCodigo(int cd);
    void setPrecio(int pr);
    void setDescriptor(string ds);

    bool operator==(const Producto &prd);
    Producto& operator=(const Producto &prd);

    friend ostream& operator<<(ostream& o, Producto &prd);
};

ostream& operator<<(ostream& o, Producto &prd);

#endif // PRODUCTO_H
