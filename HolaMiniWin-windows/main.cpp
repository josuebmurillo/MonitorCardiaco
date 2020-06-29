#include "miniwin.h"
#include "windows.h"
#include <time.h>
#include <Persona.h>
#include <vector>
#include <stdlib.h>
//#include <string>
using namespace miniwin;
using namespace std;

int main()
{

    Persona per;
    float ultimosPulso [1000];
    float ultimosTemp [1000];
    for(int o = 0; o < 1000; o++)
        ultimosPulso[o] = 0;
    for(int o = 0; o < 1000; o++)
        ultimosTemp[o] = 0;

    per.estarSano();
    vredimensiona(1000, 600);

    int counter = 0;
    //while(true)
    //{
    int ultimo = 0;
    int teclas = 0;
    int i = 0;
    asm (
         "movl al, ultimo"
         );

    while(teclas != int('Q'))
    {
        borra();
        color(BLANCO);
        float temp = per.getTemperatura();

        for(int n = 0; n < 999; n++)
            ultimosTemp[n] = ultimosTemp[n+1];
        ultimosTemp[999] = temp;


        texto(0,10,"Temperatura:");
        texto(100,10,to_string(temp));
        color(ROJO);
        linea(0, 300, 1000, 300);

        float pue = per.getPulso(float(i%1000));
        color(VERDE);
        for(int n = 0; n < 999; n++)
            ultimosPulso[n] = ultimosPulso[n+1];
        ultimosPulso[999] = pue;
        for(int n = 0; n < 999; n++)
            linea(n, 300+(ultimosPulso[n]),(n+1),300+(ultimosPulso[n+1]));
        refresca();
        espera(1);
        ultimo = pue;
        i++;
        if(i == 1000)
        {

            borra();
            i = 0;
        }

        teclas = tecla();

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
        if(teclas == int('D'))  //Menú para mostrar datos anteriores (se activa con d, se devuelve con F)
            {
                borra();

                while(teclas != int('F'))
                {
                    per.tablaPromedios(ultimosPulso, ultimosTemp);

                    teclas = tecla();
                    espera(10);
                    refresca();
                }
                color(ROJO);
                linea(0, 300, 1000, 300);

            }
    }
    vcierra();





    return 0;
}

