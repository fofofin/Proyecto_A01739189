#ifndef UNIDAD_HPP
#define UNIDAD_HPP
#include <iostream>
#include <string>
#include "ArgumentoInvalido.hpp"
using namespace std;

class Unidad {
    protected:
        int vida;
        int salud;
        int ataque;
        int nivel;
    
    public:
        Unidad();
        Unidad(int vida, int ataque, int nivel);

        int getVida() const;
        int getSalud() const;
        int getAtaque() const;
        int getNivel() const;

        void setVida(int v);
        void setSalud(int s);
        void setAtaque(int a);
        void setNivel(int n);

        int porcentajeSalud() const;
        void imprimirVida() const;
        virtual void recibeAtaque(int ptosAtaque);
        virtual void atacar(Unidad& objetivo);
        virtual void imprimir(std::ostream& os) const = 0;
        virtual bool estaVivo() const = 0;
        virtual bool puedeRevivir() const { return false; };
        virtual void revivir();
        friend ostream& operator<<(ostream& os, const Unidad& unidad);
        virtual ~Unidad() {}
    
};

#endif