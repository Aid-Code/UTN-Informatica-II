#ifndef PUNTO_H
#define PUNTO_H

#include <QObject>

class Punto : public QObject
{
private:
    int x;
    int y;

public:
    Punto(int dato_x = 0, int dato_y = 0);
    void set_x(int dato);
    void set_y(int dato);
    void set_xy(int dato_x, int dato_y);
    int get_x();
    int get_y();
    int get_xy();
};

#endif // PUNTO_H
