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
    indiceTemp = 0;
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
    float x = float((int(tiempo) + int(indicePulso))%10);
    float res = 0;
    if(x<1)
        {
            res = 0;
        }
    else if (1<= x && x < 2)
        {
            res = (-2*x) + 2;
        }
    else if (2<= x && x < 4)
        {
            res = (4*x) + 28;
        }
    else if (4<= x && x < 5.5)
        {
            res = (-8 * x) + 38;
        }
    else if (5.5<= x && x < 6.5)
        {
            res = (8 * x) + 50;
        }
    else if (6.5<= x && x < 7)
        {
            res = (-4 * x) + 28;
        }
    else if (7<= x && x < 9)
        {
            res = 0;
        }
        return res;
}

float Persona::getTemperatura()
{
    float x = temperatura + indiceTemp;
    return x;
}




