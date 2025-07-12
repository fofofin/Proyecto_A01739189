#pragma once
#include "Unidad.hpp"

class Arquero : Unidad {
    public:
        Arquero();
        Arquero(int vida, int ataqur, int nivel, float);
        
        float getCritico() const;
        void setCritico(float);

        float CalculaCritico();

        void recibeAtaque(int ptosAtaque);
        void atacar(Unidad& objetivo);
        void imprimir() const;

    private:
        float critico;

};