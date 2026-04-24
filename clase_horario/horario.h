#ifndef HORARIO_H
#define HORARIO_H

class horario
{
private:
    int h;
    int m;
    int s;

public:
    horario();
    horario(char*);
    horario(int h, int m, int s);

    horario& operator= (const horario&);
    horario operator+ (horario&);
};

#endif // HORARIO_H
