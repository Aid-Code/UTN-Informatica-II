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
    horario(horario &hr);
    horario(char*);
    horario(int h, int m, int s);

    int getHora();
    int getMin();
    int getSec();

    void setHora(int hora);
    void setMin(int min);
    void setSec(int sec);

    horario& operator= (const horario&);
    horario operator+ (horario&);
};

#endif // HORARIO_H
