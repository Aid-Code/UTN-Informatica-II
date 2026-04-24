#include <QCoreApplication>
#include <iostream>
#include "horario.h"

using namespace std;

int main()
{
    horario h1(23,30,00);
    horario retraso("1:40:00");

    h1 = h1 + retraso;

}
