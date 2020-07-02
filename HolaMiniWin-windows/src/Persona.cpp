#include "Persona.h"

#include <math.h>
#include <vector>
#include<algorithm>
#include "miniwin.h"
#include <numeric>
#include "string.h"
#include <string>


using namespace miniwin;
using namespace std;

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

//establece parametros para los casos a simular, una persona enferma, una persona sana, y los maximos y minimos

void Persona::estarSano()
{
    temperatura = 37;
    indicePulso = 2.6;
}

void Persona::estarEnfermo()
{
    temperatura = 39;
    indicePulso = 2;
}

void Persona::estarMuerto()
{
    temperatura = 35;
    indicePulso = 0;
}

void Persona::casoExtremoSuperior()
{
    temperatura = 42;
    indicePulso = 0.6;
}

void Persona::casoExtremoinferior()
{
    temperatura = 33;
    indicePulso = 6;
}



float Persona::getPulso(float tiempo)  //simula el latido del corazon con una funcion cos() y seno()
{
    float x;
    if(indicePulso == 0)//si esta muerto, retorna 0
        x = 0;
        else
        {
            x = cos(tiempo/indicePulso)*sin(tiempo/(indicePulso*2))*30;
        }
    return x;
}

float Persona::getTemperatura()  //retorna la temperatura
{
    float x = temperatura + indiceTemp;
    return x;
}





