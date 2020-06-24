#include "miniwin.h"
#include <time.h>
#include <Persona.h>
#include <vector>
//#include <string>
using namespace miniwin;
using namespace std;

int main()
{
    Persona per;
    vector<float> registro;
    registro.resize(1000);

    for (int n = 0; n < 0; n++)
        registro[n] = 0;

    per.estarEnfermo();
    vredimensiona(1000, 600);
    //rectangulo(100, 100, 300, 200);
    texto(0,10,"Tempaetura:");
    refresca();
    color(ROJO);
    linea(0, 300, 1000, 300);

    int counter = 0;
    //while(true)
    //{
    int ultimo = 0;
    int teclas = 0;
    int i = 0;
    while(teclas != int('Q'))
    {
            int pue = int(per.getPulso(float(i%1000)));
            color(VERDE);
            linea((i)-1, 300+(ultimo),(i),300+(pue));
            refresca();
            espera(1);
            ultimo = pue;
            i++;

        teclas = tecla();
    }






    return 0;
}

