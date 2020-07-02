#ifndef PERSONA_H
#define PERSONA_H


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


    private:
        float temperatura; //temperatura del paciente
        float indiceTemp; //indice de incremento y decremento de la temperatura
        float pulso;
        float indicePulso;//define que tan rapido o lento late el corazon

};


#endif // PERSONA_H
