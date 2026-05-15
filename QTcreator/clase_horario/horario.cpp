#include "horario.h"

horario::horario(int h, int m, int s):h(h),m(m),s(s){}

horario::horario(horario &hr)
{
    h = hr.h;
    m = hr.m;
    s = hr.s;
}

horario::horario(char* hora)
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

int horario::getHora(){ return h; }
int horario::getMin(){ return m; }
int horario::getSec(){ return s; }

void horario::setHora(int hora){ h = hora; }
void horario::setMin(int min){ m = min; }
void horario::setSec(int sec){ s = sec; }

horario& horario::operator= (const horario& hor)
{
    h = hor.h;
    m = hor.m;
    s = hor.s;

    return (*this);
}

horario horario::operator+ (horario& r)
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