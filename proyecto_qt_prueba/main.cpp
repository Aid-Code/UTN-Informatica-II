#include <QCoreApplication>
#include <iostream>
#include "punto.h"

using namespace std;

int main()
{
    Punto p1(2,4);
    Punto p2(3);

    cout<<"Punto 1: ("<<p1.get_x()<<", "<<p1.get_y()<<")"<<endl;
    cout<<"Punto 2: ("<<p2.get_x()<<", "<<p2.get_y()<<")"<<endl;
}
