#include <QCoreApplication>
#include <iostream>
#include "despertador.h"

using namespace std;

int main()
{
    Despertador d1(0, 10, 30, 58);
    Despertador alarma(0,10,35,0);

    bool flag = false;

    while (!flag)
    {
        if (!d1.vencio(alarma))
        {
            int eleccion;
            cout<<"Aplazar alarma 5 minutos?"<<endl;
            cin>>eleccion;
            if (eleccion == 1)
                alarma.aplazar(5);
            else if (eleccion == 0)
                flag = true;
        }
        d1.setSec(d1.getSec()+1);

        cout<<"Hora: "<<d1.getHora()<<endl<<"Minutos: "<<d1.getMin()<<endl<<"Segundos: "<<d1.getSec()<<endl;
    }

    cout<<"Hora: "<<d1.getHora()<<endl<<"Minutos: "<<d1.getMin()<<endl<<"Segundos: "<<d1.getSec()<<endl<<"Aplazo:"<<d1.getAplazo()<<endl;

    return 0;
}
