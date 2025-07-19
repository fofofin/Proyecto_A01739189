#ifndef UNIDAD_HPP
#define UNIDAD_HPP
#include <iostream>
#include <string>
using namespace std;

class Unidad {
    private:
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
        virtual void imprimir() const;
        virtual bool estaVivo() = 0;
        friend ostream& operator<<(ostream& os, const Unidad& unidad);
    
};

#endif