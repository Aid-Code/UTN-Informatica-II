#ifndef FIDEO_H
#define FIDEO_H
#include "producto.h"

class Fideo: public Producto
{
public:
    enum Tipo {
        Mostachol,
        Largo,
        Municion,
        Tirabuzon,
        Moño,
        SinDefinir
    };

    Fideo(string marca = "VACIO", Tipo tipo = SinDefinir, int codigo = -1, string descriptor = "VACIO", int precio = -1);

    string getMarca();
    Tipo getTipo();

    void setMarca(string marc);
    void setTipo(Tipo tip);

    bool operator==(const Fideo &fid);
    Fideo& operator=(const Fideo &fid);

    friend ostream& operator<<(ostream& o, Fideo &fid);

private:
    string marca;
    Tipo tipo;
    const string tipos[6] = {"Mostachol", "Largo", "Municion", "Tirabuzon", "Moño", "Sin Definir"};
};

ostream& operator<<(ostream& o, Fideo &fid);

#endif // FIDEO_H
