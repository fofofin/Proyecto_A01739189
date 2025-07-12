#include <iostream>
#include "Guerrero.hpp"

using namespace std;

Guerrero::Guerrero(){  
    fuerza = 0;
}

Guerrero::Guerrero(int v, int a, int n, int f) : Unidad(v, a, n) {
    setFuerza(f);
}

int Guerrero::getFuerza() const {
    return fuerza;
}

void Guerrero::setFuerza(int f) {
    fuerza = (f < 0) ? 0 : f;
}

int Guerrero::calculaPotenciador() const {
    return (getNivel() * getFuerza()) / 10;
}

void Guerrero::atacar(Unidad& objetivo) {
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

    int potenciador = calculaPotenciador();
    int golpeFinal = golpeBase + potenciador;

    objetivo.recibeAtaque(golpeFinal);

    cout << "¡Guerrero ataca con " << golpeBase << " + potenciador de espada " 
         << potenciador << " = " << golpeFinal << " de daño!" << endl;
}

void Guerrero::recibeAtaque(int ptosAtaque){
    int reduccion = calculaPotenciador() / 2;
    int dañoReal = ptosAtaque - reduccion;

    if (dañoReal < 0) dañoReal = 0;

    Unidad::recibeAtaque(dañoReal);  

    cout << "¡Guerrero recibió " << ptosAtaque << " pero usó su escudo y redujo " << reduccion 
         << "! Daño real: " << dañoReal << endl;
}

void Guerrero::imprimir() const {
    cout << "Guerrero - Vida: " << getVida() << ", Salud: " << getSalud() 
         << ", Ataque: " << getAtaque() << ", Nivel: " << getNivel() 
         << ", Fuerza: " << getFuerza() << endl;
    imprimirVida();
}
