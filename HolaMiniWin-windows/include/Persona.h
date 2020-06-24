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

    protected:

    private:
        float temperatura;
        float indiceTemp;
        float pulso;
        float indicePulso;
};

#endif // PERSONA_H
