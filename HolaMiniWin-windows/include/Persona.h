#ifndef PERSONA_H
#define PERSONA_H
#include<vector>
#include<time.h>
#include<string>


using namespace std;

class Persona
{
    public:
        Persona();
        virtual ~Persona();

        void estarEnfermo();
        void estarSano();
        void estarMuerto();
        void casoExtremoSuperior();
        void casoExtremoinferior();

        float getPulso (float tiempo);
        float getTemperatura();

        double ramdonTemperatura(int,int);

        float obtenerMinimo( float vectorDatos[]);
        float obtenerMaximo( float vectorDatos[]);//para que reciba los 1000 numeros que representan los 30 segundos
        float obtenerPromedio(float vectorDatos[], bool bandera);

        void tablaPromedios(float vectorDatosPul[], float vectorDatosTem []);


    protected:

    private:
        float temperatura;
        float indiceTemp;
        float pulso;
        float indicePulso;
};

#endif // PERSONA_H
