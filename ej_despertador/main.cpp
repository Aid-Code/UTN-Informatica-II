#include <QCoreApplication>
#include <iostream>
#include "despertador.h"

using namespace std;

int main()
{
    Despertador d1(0, 10, 30, 58);
    Despertador alarma(0,10,35,0);

    while (!d1.vencio(alarma))
    {
        d1.setSec(d1.getSec()+1);
        cout<<"Hora: "<<d1.getHora()<<endl<<"Minutos: "<<d1.getMin()<<endl<<"Segundos: "<<d1.getSec()<<endl;
    }

    d1.aplazar(5);
    cout<<"Hora: "<<d1.getHora()<<endl<<"Minutos: "<<d1.getMin()<<endl<<"Segundos: "<<d1.getSec()<<endl<<"Aplazo:"<<d1.getAplazo()<<endl;

    return 0;
}
