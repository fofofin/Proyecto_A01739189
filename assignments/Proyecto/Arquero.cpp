#include <iostream>
#include "Arquero.hpp"
using namespace std;

Arquero::Arquero() {
    critico = 1.0f;
}

Arquero::Arquero(int v, int a, int n, float c) : Unidad(v, a, n) {
    setCritico(c);
}

float Arquero::getCritico() const {
    return critico;
}
void Arquero::setCritico(float c) {
    critico = (c < 0) ? 0 : c;
}

float Arquero::CalculaCritico() {
    if((rand() % 5) == 0) {
        critico = 1.5f;
    } else {
        critico = 1.0f;
    }
    return critico;
}

void Arquero::recibeAtaque(int ptosAtaque) {
    Unidad::recibeAtaque(ptosAtaque);
    if (!estaVivo()) {
        cout << "¡El Arquero ha muerto!" << endl;
    }
}

void Arquero::atacar(Unidad& objetivo) {
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

    float multiplicador = CalculaCritico();
    int golpeFinal = golpeBase * multiplicador;

    objetivo.recibeAtaque(golpeFinal);

    cout << "¡Arquero ataca con " << golpeBase << " + multiplicador critico de: x" 
         << multiplicador << " = " << golpeFinal << " de daño!" << endl;
}

bool Arquero::estaVivo() const {
    return getSalud() > 0;
}

void Arquero::imprimir() const {
    cout << "Arquero - Vida: " << getVida() << ", Ataque: " << getAtaque() 
         << ", Nivel: " << getNivel() << ", Critico: " << critico << endl;
    imprimirVida();
}