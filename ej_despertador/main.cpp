#include <QCoreApplication>
#include <iostream>
#include "horario.h"
#include "despertador.h"

using namespace std;

int main()
{
    Horario h1(23,30,00);
    Horario retraso("1:40:00");

    h1 = h1 + retraso;

    cout<<"Hora: "<<h1.getHora()<<endl<<"Minutos: "<<h1.getMin()<<endl<<"Segundos: "<<h1.getSec()<<endl;
}
