#ifndef DESPERTADOR_H
#define DESPERTADOR_H

#include "horario.h"

class Despertador: public Horario
{
private:
    int aplazo;

public:
    Despertador();
    Despertador(int ap);
    Despertador(int ap, int hora, int min, int sec);
    Despertador(Despertador &dp);

    void setAplazo(int ap);
    int getAplazo();

    bool vencio(Despertador &dp);
    void aplazar(int ap);
};

#endif // DESPERTADOR_H
