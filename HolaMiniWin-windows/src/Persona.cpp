#include "Persona.h"

Persona::Persona()
{
    temperatura = 37;//ctor
    indiceTemp = 0;
    pulso = 60;
    indicePulso = 1;
}

Persona::~Persona()
{
    //dtor
}

void Persona::estarSano()
{
    indiceTemp = 1;
    indicePulso = 1;
}

void Persona::estarEnfermo()
{
    indiceTemp = 2;
    indicePulso = 1.7;
}

void Persona::estarMuerto()
{
    indiceTemp = 0;
    indicePulso = 0;
}

void Persona::casoExtremoSuperior()
{
    indiceTemp = 4;
    indicePulso = 3.7;
}

void Persona::casoExtremoinferior()
{
    indiceTemp = -3;
    indicePulso = 0.5;
}

float Persona::getPulso(float tiempo)
{
    float x =float((int(tiempo*indicePulso))%100);
    float res = 0;
    if(0<= x && x<10)
    {
        res = 0;
    }
    else if (10<= x && x < 15)
    {
        res = x - 10;
    }
    else if (15<= x && x < 20)
    {
        res = -(x) + 20;
    }
    else if (20<= x && x < 25)
    {
        res = (-2 * x)+40;
    }
    else if (25<= x && x < 30)
    {
        res = (2*x)-60;
    }
    else if (30<= x && x < 40)
    {
        res = (4*x)-140;
    }
    else if (40<= x && x < 50)
    {
        res = (-6 * x) + 280;
    }
    else if (50<= x && x < 55)
    {
        res = (4 * x) - 220;
    }
    else if (55<= x && x < 60)
    {
        res = 0;
    }
    else if (60<= x && x < 65)
    {
        res = x - 60;
    }
    else if (65<= x && x < 70)
    {
        res = -x + 70;
    }
    else if (70<= x)
    {
        res = 0;
    }
    return -res;
}

float Persona::getTemperatura()
{
    float x = temperatura + indiceTemp;
    return x;
}




