#include "Unidad.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Unidad::Unidad() {
    vida = 100;
    salud = 100;
    ataque = 20;
    nivel = 1;
}

Unidad::Unidad(int v, int a, int n) {
    vida = v;
    salud = v;
    ataque = a;
    nivel = n;
}

int Unidad::getVida() const {return vida; }
int Unidad::getSalud() const {return salud; }
int Unidad::getAtaque() const {return ataque; }
int Unidad::getNivel() const {return nivel; }

void Unidad::setVida(int v) {
    if (v < 0) {
        throw ArgumentoInvalido("La vida no puede ser negativa, estás mandando a un cadaver a la batalla XD.");
    }
    vida = v;
}
void Unidad::setSalud(int s) {
    if (s < 0) {
        throw ArgumentoInvalido("La salud no puede ser negativa, dale algo de ganas a tu persoanaje.");
    }
    salud = s;
}
void Unidad::setAtaque(int a) {
    if (a < 0) {
        throw ArgumentoInvalido("El ataque no puede ser negativo, ¿Cómo esperas que haga algo en pelea?");
    }
    ataque = a;
}

void Unidad::setNivel(int n) {
    if (n < 0) {
        throw ArgumentoInvalido("El nivel no puede ser negativo, recuerda que no es el tutorial.");
    }
    nivel = n;
}

int Unidad::porcentajeSalud() const {
    return static_cast<int> ((static_cast<float>(salud)/vida)*100);
}

void Unidad::imprimirVida() const {
    int porcentaje = porcentajeSalud();
    int llenado = porcentaje / 5;
    for (int i = 0; i < llenado; i++) cout << '%';
    for (int i = llenado; i < 20; i++) cout << '=';
    cout << "(" << porcentaje << "%)" << endl;
}

void Unidad::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) salud = 0;
}
void Unidad::atacar(Unidad& objetivo) {
    int golpe;
    if ( nivel > objetivo.getNivel()) {
        int max = ataque / 2;
        golpe = 1 + rand() % (max);
    } else {
        int min = ataque / 2;
        int max = ataque;
        golpe = min + rand() % ((max - min)+1);
    }
    objetivo.recibeAtaque(golpe);
    cout << "Golpesate al enemigo con  " << golpe << "  puntos de daño" << endl;
}

bool Unidad::estaVivo() const {
    return salud > 0;
}

void Unidad::revivir() {
    // Implementación vacía
}

ostream& operator<<(ostream& os, const Unidad& unidad) {
    unidad.imprimir(os);
    return os;
}

 

