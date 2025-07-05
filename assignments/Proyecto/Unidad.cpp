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

void Unidad::setVida(int v) {vida = v; }
void Unidad::setSalud(int s) {salud = s; }
void Unidad::setAtaque(int a) {ataque = a; }
void Unidad::setNivel(int n) {nivel = n; }

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
#include <iostream>
#include <random>

void Unidad::atacar(Unidad& objetivo) {
    static random_device rd;  
    static mt19937 gen(rd()); 

    int golpe = 0;
    if (objetivo.getNivel() <= nivel) {
        int min = ataque / 2;
        int max = ataque;
        uniform_int_distribution<> distrib(min, max);
        golpe = distrib(gen);
    } else {
        int max = ataque / 2;
        uniform_int_distribution<> distrib(1, max);
        golpe = distrib(gen);
    }
    objetivo.recibeAtaque(golpe);
    cout << "Golpeaste al enemigo con " << golpe << " puntos de daño" << endl;
}

 void Unidad::imprimir() const {
    cout << "Nivel " << nivel << endl;
    cout << "Vida máxima " << vida << endl;
    cout << "Vida actual " << salud << endl;
    cout << "Ataque máximo " << ataque << endl;
    cout << "Barra de vida ";
    imprimirVida();    
}