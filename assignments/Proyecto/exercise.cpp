#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include "ArgumentoInvalido.hpp"

using namespace std;

void cargarEjercito(vector<Unidad*>& ejercito, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string tipo;
        iss >> tipo;

        if (tipo == "Guerrero") {
            int vida, ataque, nivel, fuerza;
            iss >> vida >> ataque >> nivel >> fuerza;
            ejercito.push_back(new Guerrero(vida, ataque, nivel, fuerza));
        }
        else if (tipo == "Arquero") {
            int vida, ataque, nivel;
            float critico;
            iss >> vida >> ataque >> nivel >> critico;
            ejercito.push_back(new Arquero(vida, ataque, nivel, critico));
        }
        else if (tipo == "Mago") {
            int vida, ataque, nivel, mana;
            iss >> vida >> ataque >> nivel >> mana;
            ejercito.push_back(new Mago(vida, ataque, nivel, mana));
        }
        else {
            cerr << "Tipo desconocido: " << tipo << endl;
        }
    }
    archivo.close();
}

void mostrarEjercito(const vector<Unidad*>& ejercito, const string& nombreEjercito) {
    cout << "=== Ejército: " << nombreEjercito << " ===" << endl;
    for (const Unidad* combatiente : ejercito) {
        combatiente->imprimir();
        cout << endl;
    }
}

void batalla(vector<Unidad*>& ejercito1, vector<Unidad*>& ejercito2) {
    int ronda = 1;
    while (!ejercito1.empty() && !ejercito2.empty()) {
    cout << "\n=== Ronda " << ronda << " ===\n";

    int minCombatientes = min(ejercito1.size(), ejercito2.size());

    for (int i = 0; i < minCombatientes; i++) {
        Unidad* c1 = ejercito1[i];
        Unidad* c2 = ejercito2[i];

        cout << "\n-- Combate entre:\n";
        c1->imprimir();
        cout << " VS \n";
        c2->imprimir();
        cout << endl;

        while (c1->estaVivo() && c2->estaVivo()) {
            c1->atacar(*c2);
            if (!c2->estaVivo()) break;

            c2->atacar(*c1);
        }

        
        if (!c1->estaVivo() && c1->puedeRevivir()) {
            cout << "¡Combatiente del ejército 1 revive!\n";
            c1->setSalud(10);
        }

        if (!c2->estaVivo() && c2->puedeRevivir()) {
            cout << "¡Combatiente del ejército 2 revive!\n";
            c2->setSalud(10);
        }

        
        if (!c1->estaVivo()) {
            cout << "¡El combatiente del Ejército 1 ha muerto!\n";
            delete c1;
            ejercito1.erase(ejercito1.begin() + i);
            i--; 
            minCombatientes--; 
            continue; 
        }

        if (!c2->estaVivo()) {
            cout << "¡El combatiente del Ejército 2 ha muerto!\n";
            delete c2;
            ejercito2.erase(ejercito2.begin() + i);
            i--; 
            minCombatientes--;
        }
    }

    ronda++;
}


    cout << "\n=== Resultado Final ===\n";
    if (ejercito1.empty() && ejercito2.empty()) {
        cout << "La batalla terminó en empate.\n";
    } else if (ejercito1.empty()) {
        cout << "¡El Ejército 2 es el ganador!\n";
        cout << "Combatientes vivos del Ejército 2:\n";
        for (Unidad* u : ejercito2) {
            u->imprimir();
            cout << endl;
        }
    } else {
        cout << "¡El Ejército 1 es el ganador!\n";
        cout << "Combatientes vivos del Ejército 1:\n";
        for (Unidad* u : ejercito1) {
            u->imprimir();
            cout << endl;
        }
    }
}


int main() {
    srand(time(0));
  vector<Unidad*> ejercito1;
    vector<Unidad*> ejercito2;

    cargarEjercito(ejercito1, "ejercito1.txt");
    cargarEjercito(ejercito2, "ejercito2.txt");

    cout << "-----Ejercito 1-----" << endl; 
    mostrarEjercito(ejercito1, "Ejército 1");
    cout << "-----Ejercito 2-----" << endl; 
    mostrarEjercito(ejercito2, "Ejército 2");
    
    batalla(ejercito1, ejercito2);

    for (auto u : ejercito1) delete u;
    for (auto u : ejercito2) delete u;

    return 0;
}
