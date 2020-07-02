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

void Persona::estarSano()
{
    temperatura = 37;
    indicePulso = 3;
}

void Persona::estarEnfermo()
{
    temperatura = 39;
    indicePulso = 6;
}

void Persona::estarMuerto()
{
    temperatura = 35;
    indicePulso = 0;
}

void Persona::casoExtremoSuperior()
{
    temperatura = 42;
    indicePulso = 11;
}

void Persona::casoExtremoinferior()
{
    temperatura = 33;
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
    else if (70<= x && x < 100)
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

//float Persona::obtenerMinimo(float vectorDatos [])
//{
//    float res = vectorDatos[0];
//    for (int i=0; i<1000; i++)
//    {
//        if (vectorDatos[i]< res)
//        {
//            res = vectorDatos[i];
//        }
//    }
//        return res;
//}

    float Persona::obtenerMaximo(float vectorDatos [])
    {

        float res = vectorDatos[0];
        for (int i=0; i<1000; i++)
        {
            if (vectorDatos[i]> res)
            {
                res=vectorDatos[i];
            }
        }

        return res;

    }

    float Persona::obtenerPromedio(float vectorDatos2 [], bool bandera)
    {

        float sumatoriaPulsos = 0;
        float promedio = 0;

        if (bandera)  //promedio temperatura
        {
            for(int i = 0; i < 1000; i++)
                sumatoriaPulsos += vectorDatos2[i];
            promedio = sumatoriaPulsos/1000;// la division se hace asi porque suponemos que el vector de datos contiene todas la pulsaciones en el rango del intervalo dado

        }
        else   //proedio pulsaciones
        {
            for(int i = 0; i < 1000; i++)
                if(vectorDatos2[i] != 0)
                {
                    sumatoriaPulsos++;
                }
            promedio = sumatoriaPulsos*0.1225;// la division se hace asi porque suponemos que el vector de datos contiene todas la pulsaciones en el rango del intervalo dado
        }
        return promedio;
    }

    double Persona::ramdonTemperatura(int fMin, int fMax)
    {
        srand (time(NULL));
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
    void Persona::tablaPromedios(float vectorDatosPulsaciones[], float vectorDatosTemperaturas[] )
    {
        float pulsacionMinima= obtenerMinimo(vectorDatosPulsaciones);
        float pulsacionMaxima= obtenerMaximo(vectorDatosPulsaciones);
        float temperaturaMaxima= obtenerMaximo(vectorDatosTemperaturas);
        float temperaturaMinima= obtenerMinimo(vectorDatosTemperaturas);
        float promedioPulsaciones= obtenerPromedio(vectorDatosPulsaciones, false);
        float promedioTemperaturas= obtenerPromedio(vectorDatosTemperaturas, true);

        vredimensiona(1000, 600);

        texto(0, 0, "Pulsacion minima ->" + to_string(pulsacionMinima));
        texto(0, 20, "Pulsacion maxima ->" + to_string(pulsacionMaxima));
        texto(0, 40, "Temperatura Maxima-> " + to_string(temperaturaMaxima));
        texto(0, 60, "Temperatura Minima-> "+to_string(temperaturaMinima));
        texto(0, 80, "Promedio Pulsaciones->" + to_string(promedioPulsaciones));
        texto(0, 100, "Promedio Temperaturas->" + to_string(promedioTemperaturas));



    }

