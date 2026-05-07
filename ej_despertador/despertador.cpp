#include "despertador.h"

Despertador::Despertador(){}

Despertador::Despertador(int ap):aplazo(ap){}

Despertador::Despertador(int ap, int hora, int min, int sec):Horario(hora, min, sec),aplazo(ap){}

Despertador::Despertador(Despertador &dp):Horario((Horario&)dp){ aplazo = dp.aplazo; }

void Despertador::setAplazo(int ap){ aplazo = ap; }

int Despertador::getAplazo(){ return aplazo; }

bool vencio();
void aplazar();

/*int Despertador::operator+= (int ap, int b)
{
    ap = ap + b;

    return ap;
}*/