#ifndef UNIDAD_HPP
#define UNIDAD_HPP

#include <string>

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
        void recibeAtaque(int ptosAtaque);
        void atacar(Unidad& objetivo);
        void imprimir() const;
    
};

#endif