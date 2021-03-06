
#include "windows.h"
#include <time.h>
#include <Persona.h>
#include <Sensor.h>
#include <vector>
#include <stdlib.h>

//esta es una libreria usada para manejar la interfaz grafica
#include "miniwin.h"



//#include <string>
using namespace miniwin;
using namespace std;

int main()
{
    //se instancian los objetos persona y sensor
    //persona da los signos vitales y el sensor los recibe
    Persona per;
    Sensor sen;


    //estos dos arreglos guardan los datos por cada 30milisegundos
    float ultimosPulso [1000];
    float ultimosTemp [1000];

    //por defecto los arreglos se inician con datos = 0
    for(int o = 0; o < 1000; o++)
        ultimosPulso[o] = 0;
    for(int o = 0; o < 1000; o++)
        ultimosTemp[o] = 0;

    per.estarSano(); //la persona empieza como sana

    vredimensiona(1000, 600);//crea la ventana

    int counter = 0;
    int ultimo = 0;
    int teclas = 0; //almacena la tecla presionada por el usuario
    int i = 0; //equivalente al tiempo

    while(teclas != int('Q'))
    {
        borra();


        color(BLANCO);
        float temp = per.getTemperatura();

        //guarda los datos en forma de last in-last out, borra el ultimo dato ingresado
        for(int n = 0; n < 999; n++)
            ultimosTemp[n] = ultimosTemp[n+1];
        ultimosTemp[999] = temp;

        //imprime la temperatura actual
        texto(0,10,"Temperatura:");
        texto(100,10,to_string(temp));


        //imprime la linea roja de guia
        color(ROJO);
        linea(0, 300, 1000, 300);




        //guarda los datos en forma de last in-last out, borra el ultimo dato ingresado
        float pue = per.getPulso(float(i));
        for(int n = 0; n < 999; n++)
            ultimosPulso[n] = ultimosPulso[n+1];
        ultimosPulso[999] = pue;

        //imprime el PPM actual
        //imprime la temperatura actual
        color(BLANCO);
        texto(0,30,"PPM(pulsos por minuto):");
        texto(200,30,to_string(sen.obtenerPromedio(ultimosPulso, false)));

        color(VERDE);
        //grafica el latido del corazon
        for(int n = 0; n < 999; n++)
            linea(n, 300+(ultimosPulso[n]),(n+1),300+(ultimosPulso[n+1]));
        refresca();
        espera(1);
        ultimo = pue;
        i++;

        sen.sonarAlarma(ultimosPulso, ultimosTemp);//revisa los umbrales y suena si se rompen

        teclas = tecla();//lee una tecla


        //opciones de usuario
        if(teclas == '1')
            per.estarEnfermo();
        if(teclas == '2')
            per.estarSano();
        if(teclas == '3')
            per.estarMuerto();
        if(teclas == '4')
            per.casoExtremoSuperior();
        if(teclas == '5')
            per.casoExtremoinferior();
        if(teclas == int('D'))  //Men� para mostrar datos anteriores (se activa con d, se devuelve con F)
            {
                borra();

                while(teclas != int('F'))
                {
                    //muestra la tabla de resumen de datos
                    sen.tablaPromedios(ultimosPulso, ultimosTemp);
                    teclas = tecla();
                    espera(10);
                    refresca();
                }
                color(ROJO);
                linea(0, 300, 1000, 300);

            }
    }
    vcierra();//en caso de presionar 'Q', cierra la aplicacion





    return 0;
}

