#include "Sensor.h"
#include <math.h>
#include <vector>
#include<algorithm>
#include "miniwin.h"
#include <numeric>
#include "string.h"
#include <string>
#include "windows.h"

using namespace miniwin;
using namespace std;

Sensor::Sensor()
{
    //ctor
}

Sensor::~Sensor()
{
    //dtor
}

float Sensor::obtenerMinimo(float vectorDatos []) //obtiene el minimo de un vector de datos
{
    float res = vectorDatos[0];
    for (int i=0; i<1000; i++)
    {
        if (vectorDatos[i]< res)
        {
            res = vectorDatos[i];
        }
    }
    return res;
}

float Sensor::obtenerMaximo(float vectorDatos [])
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

float Sensor::obtenerPromedio(float vectorDatos2 [], bool bandera)
{

    float sumatoriaPulsos = 0;
    float promedio = 0;

    if (bandera)  //promedio temperatura
    {
        for(int i = 750; i < 1000; i++)
            sumatoriaPulsos += abs(vectorDatos2[i]);
        promedio = sumatoriaPulsos/250;// la division se hace asi porque suponemos que el vector de datos contiene todas la pulsaciones en el rango del intervalo dado

    }
    else   //promedio pulsaciones
    {
        int z = 750;
        int haypico = 0;
        while(z < 1000)
        {
            if(vectorDatos2[z] > vectorDatos2[z-1] && vectorDatos2[z] > vectorDatos2[z+1] && vectorDatos2[z] > 25)
            {
                haypico++;
            }
            if(haypico == 1)
                sumatoriaPulsos++;
            if(haypico == 2)
                z = 1001;

            z++;
        }
        promedio = (1/((sumatoriaPulsos*30)/1000))*60;
    }
    return promedio;
}

float Sensor::getMin_asm(float vect [])
{
    float min_n = obtenerMinimo(vect);
    float para_retornar;
    //;float joe =182, fred =1;
    __asm__(
        "  mov %1,%%eax\n"
        "  add $2,%%eax\n"
        "  mov %%eax,%0\n"
        :"=r" (para_retornar) /* %0: Out */
        :"r" (min_n) /* %1: In */
        :"%eax" /* Overwrite */
    );
    return para_retornar;
}

float Sensor::getMax_asm(float vect [])
{
    float max_n = obtenerMaximo(vect);
    float para_retornar;
    //;float joe =182, fred =1;
    __asm__(
        "  mov %1,%%eax\n"
        "  add $2,%%eax\n"
        "  mov %%eax,%0\n"
        :"=r" (para_retornar) /* %0: Out */
        :"r" (max_n) /* %1: In */
        :"%eax" /* Overwrite */
    );
    return para_retornar;
}

float Sensor::getPromedio_asm(float *vect, bool bandera)
{
    float promedio_n = obtenerPromedio(vect, bandera);
    float para_retornar;
    __asm__(
        "  mov %1,%%eax\n"
        "  add $2,%%eax\n"
        "  mov %%eax,%0\n"
        :"=r" (para_retornar) /* %0: Out */
        :"r" (promedio_n) /* %1: In */
        :"%eax" /* Overwrite */
    );
    return para_retornar;
}

void Sensor::tablaPromedios(float vectorDatosPulsaciones[], float vectorDatosTemperaturas [])
{


    float pulsacionMinima= getMin_asm(vectorDatosPulsaciones);
    float pulsacionMaxima= getMax_asm(vectorDatosPulsaciones);
    float temperaturaMaxima= getMax_asm(vectorDatosTemperaturas);
    float temperaturaMinima= getMin_asm(vectorDatosTemperaturas);
    float promedioPulsaciones= getPromedio_asm(vectorDatosPulsaciones, false);
    float promedioTemperaturas= getPromedio_asm(vectorDatosTemperaturas, true);

    vredimensiona(1000, 600);

    texto(0, 0, "Pulsacion minima ->" + to_string(pulsacionMinima));
    texto(0, 20, "Pulsacion maxima ->" + to_string(pulsacionMaxima));
    texto(0, 40, "Temperatura Maxima-> " + to_string(temperaturaMaxima));
    texto(0, 60, "Temperatura Minima-> "+to_string(temperaturaMinima));
    texto(0, 80, "Promedio Pulsaciones->" + to_string(promedioPulsaciones));
    texto(0, 100, "Promedio Temperaturas->" + to_string(promedioTemperaturas));

}

void Sensor::sonarAlarma(float vectorDatosPulsaciones[], float vectorDatosTemperaturas [])
{
    float ppm = obtenerPromedio(vectorDatosPulsaciones, false);
    float temp = vectorDatosTemperaturas[999];

    if(ppm < 60 || ppm > 120 || temp<35 || temp>37.8)
        Beep(1500, 1);
}
