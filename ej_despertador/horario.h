#ifndef HORARIO_H
#define HORARIO_H

class Horario
{
private:
    int h;
    int m;
    int s;

public:
    Horario();
    Horario(Horario &hr);
    Horario(char*);
    Horario(int h, int m, int s);

    int getHora();
    int getMin();
    int getSec();

    void setHora(int hora);
    void setMin(int min);
    void setSec(int sec);

    Horario& operator= (const Horario&);
    Horario operator+ (Horario&);
};

#endif // HORARIO_H
