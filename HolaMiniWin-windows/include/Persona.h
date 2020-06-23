#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
    public:
        Persona();
        virtual ~Persona();

        float estarEnfermo();
        float estarSano();
        float estarMuerto();

    protected:

    private:
        float temperatura;
        float pulso;
};

#endif // PERSONA_H
