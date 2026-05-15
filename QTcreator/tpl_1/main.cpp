#include <QCoreApplication>
#include "producto.h"
#include "fideo.h"
#include "lista.h"
#include <iostream>

using namespace std;

int main()
{
    Producto p1(03, "Arroz", 2000);
    Producto p2(02, "Fideo", 1500);
    Fideo f1,f2("Pirulo"),f3("Pirulo", Fideo::Tirabuzon),f4("Vicente", Fideo::Largo, 04, "Fideo", 2500);
    Lista l1;

    l1 += p1;
    l1 += p2;

    cout<<l1[1];

    l1 += f3;
    l1 -= p2;

    cout<<l1[1];


    f1 = f3;
    cout<<f1;
    cout<<f3;

    if (f1 == f3) cout<<"YEI :D"<<endl;
    else cout<<"OUH :("<<endl;

    f1.setPrecio(3400);

    cout<<f1;
    cout<<f3;

    if (f1 == f3) cout<<"YEI"<<endl;
    else cout<<"OUH :("<<endl;


}
