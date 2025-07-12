#include "Unidad.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
using namespace std;

int main() {

    srand(time(0));

    Mago jugador(100, 25, 8, 10);
    Guerrero enemigo(100, 20, 4, 5);

    jugador.imprimir();
    enemigo.imprimir();

    enemigo.atacar(jugador);
    jugador.imprimir();

    return 0;
}