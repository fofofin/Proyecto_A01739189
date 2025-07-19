#pragma once
#include "Unidad.hpp"

class Mago : public Unidad {
    public:
        Mago();
        Mago(int vida, int ataque, int nivel, int);
        
        int getMana() const;
        void setMana(int);

        void recibeAtaque(int ptosAtaque);
        void atacar(Unidad& objetivo);
        void imprimir() const override;
        bool estaVivo() override;
    
    private:
        int mana;
};
