#include "horario.h"

Horario::Horario(){}

Horario::Horario(int h, int m, int s):h(h),m(m),s(s){}

Horario::Horario(Horario &hr)
{
    h = hr.h;
    m = hr.m;
    s = hr.s;
}

Horario::Horario(char* hora)
{
    int i = 0;

    h = (hora[i]-'0')*10;
    i++;

    if (hora[i] == ':')
    {
        h = (hora[i-1]-'0');
    }
    else
    {
        h = h+(hora[i]-'0');
        i++;
    }
    i++;

    m = (hora[i]-'0')*10;
    i++;

    if (hora[i] == ':')
    {
        m = (hora[i-1]-'0');
    }
    else
    {
        m = m+(hora[i]-'0');
        i++;
    }
    i++;

    s = (hora[i]-'0')*10;
    i++;

    s = s+(hora[i]-'0');
}

int Horario::getHora(){ return h; }
int Horario::getMin(){ return m; }
int Horario::getSec(){ return s; }

void Horario::setHora(int hora){ h = hora; }
void Horario::setMin(int min)
{
    m = min;
    if (m >= 60)
    {
        h++;
        m = 0;
    }
}
void Horario::setSec(int sec)
{
    s = sec;
    if (s >= 60)
    {
        m++;
        s = 0;
    }
}

Horario& Horario::operator= (const Horario& hor)
{
    h = hor.h;
    m = hor.m;
    s = hor.s;

    return (*this);
}

Horario Horario::operator+ (Horario& r)
{
    s += r.s;
    if(s >= 60)
    {
        s -= 60;
        m++;
    }

    m += r.m;
    if(m >= 60)
    {
        m -= 60;
        h++;
    }

    h += r.h;

    return (*this);
}