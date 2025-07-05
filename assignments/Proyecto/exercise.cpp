#include "Unidad.hpp"
#include <iostream>
using namespace std;

int main() {
    Unidad jugador(100, 25, 3);
    Unidad enemigo(100, 20, 2);

    jugador.imprimir();
    enemigo.imprimir();

    jugador.atacar(enemigo);
    enemigo.imprimir();

    return 0;
}