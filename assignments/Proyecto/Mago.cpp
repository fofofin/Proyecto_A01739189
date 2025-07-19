#include <iostream>
#include "Mago.hpp"
using namespace std;

Mago::Mago() {
    mana = 0;
}

Mago::Mago(int v, int a, int n, int m) : Unidad(v, a, n) {
    setMana(m);
}

int Mago::getMana() const {
    return mana;
}

void Mago::setMana(int m) {
    mana = (m < 0) ? 0 : m;
}

void Mago::recibeAtaque(int ptosAtaque) {
    if((rand() % 3) == 0) {
        cout << "¡Mago esquivó el ataque!" << endl;
        return;

    } else {
        Unidad::recibeAtaque(ptosAtaque);
        cout << "¡Mago recibió "<< ptosAtaque << endl;
    }
    if (!estaVivo()) {
        cout << "¡El Mago ha muerto!" << endl;
    }
}

void Mago::atacar(Unidad& objetivo) {
    if (getMana() <= 0) {
        cout << "¡Mago no tiene suficiente mana para atacar!" << endl;
        return;
    }
    mana -= 1;

    int golpeBase;
    int ataqueBase = getAtaque();

    if (getNivel() > objetivo.getNivel()) {
        int max = ataqueBase / 2;
        golpeBase = 1 + rand() % max;
    } else {
        int min = ataqueBase / 2;
        int max = ataqueBase;
        golpeBase = min + rand() % (max - min + 1);
    }

    int saludActual = getSalud();
    int vidaMaxima = getVida();

    if (saludActual < vidaMaxima) {
        int nuevaSalud = saludActual + 5;
        setSalud(nuevaSalud > vidaMaxima ? vidaMaxima : nuevaSalud);
        cout << "¡El hechicero se curó 5 puntos de vida!" << endl;
    } else {
        golpeBase += 5;
        cout << "¡El hechicero está al máximo de vida y hace 5 puntos extra de daño!" << endl;
    }

    objetivo.recibeAtaque(golpeBase);

    cout << "¡Hechicero ataca con " << golpeBase << " puntos de daño! (Maná restante: " << mana << ")" << endl;
}

bool Mago::estaVivo() {
    if (getSalud() > 0) return true;
    else if (mana > 0) {
        int nuevaSalud = 10;
        setSalud(nuevaSalud);
        cout << "¡El Mago revive con 10 puntos de salud!" << endl;
        return true;
    }
    return false;
}

void Mago::imprimir() const {
    cout << "Mago - Vida: " << getSalud() << ", Ataque: " << getAtaque() 
         << ", Nivel: " << getNivel() << ", Mana: " << mana << endl;
    imprimirVida();
}