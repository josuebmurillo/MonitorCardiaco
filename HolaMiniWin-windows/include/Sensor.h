#ifndef SENSOR_H
#define SENSOR_H


class Sensor
{
    public:
        Sensor();

        void tablaPromedios(float vectorDatosPul[], float vectorDatosTem []);

        float obtenerMinimo( float vectorDatos[]);//para que reciba los 1000 numeros que representan los 30 segundos

        float obtenerMaximo( float vectorDatos[]);//para que reciba los 1000 numeros que representan los 30 segundos

        float obtenerPromedio(float vectorDatos[], bool bandera);

        void sonarAlarma(float vectorDatosPul[], float vectorDatosTem []);

        int suma(int, int);

        float getMin_asm(float*);

        float getMax_asm(float*);

        float getPromedio_asm(float*,bool);

        virtual ~Sensor();

    protected:

    private:
};

#endif // SENSOR_H
