#pragma once
#include "Unidad.hpp"

class Guerrero : public Unidad {
    public:
        Guerrero();
        Guerrero(int vida, int ataque, int nivel, int);
        int getFuerza() const;
        void setFuerza(int);

        int calculaPotenciador() const;

        void recibeAtaque(int ptosAtaque);
        void atacar(Unidad& objetivo);
        void imprimir() const override;
        bool estaVivo() const override;
    
    private:
        int fuerza;

};