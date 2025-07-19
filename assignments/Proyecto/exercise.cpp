#include <iostream>
#include <vector>
#include "Unidad.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

using namespace std;

int main() {
    vector<Unidad*> combatientes;

    combatientes.push_back(new Guerrero(100, 20, 5, 10));
    combatientes.push_back(new Arquero(80, 25, 6, 1.2f));
    combatientes.push_back(new Mago(90, 30, 7, 5));

    cout << "=== Combatientes Iniciales ===" << endl;
    for (Unidad* c : combatientes) {
        cout << *c << endl;
    }

    cout << "\n=== Combate ===" << endl;
    combatientes[0]->atacar(*combatientes[1]);
    cout << *combatientes[1] << endl;

    combatientes[0]->atacar(*combatientes[2]);
    cout << *combatientes[2] << endl;


    for (Unidad* c : combatientes) {
        delete c;
    }

    return 0;
}
