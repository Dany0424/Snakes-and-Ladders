//Axel Godoy y Erika Garcia
//Clase del tablero que contiene las casillas

#include <iostream>
#include <vector>
#include "Casilla.h"
#include "CasillaNormal.h"
#include "Serpiente.h"
#include "Escalera.h"
using namespace std;
#pragma once

class Tablero {
private:
    int numCasillas;
    vector<Casilla*> casillas;

public:
    Tablero() {}; //Constructor por omision

    Tablero(int numCasillas) : numCasillas(numCasillas) {
        // Inicializar el tablero con casillas normales
        for (int i = 1; i <= numCasillas; i++) {
            casillas.push_back(new CasillaNormal(i));
        }
    }

    Tablero(const Tablero &tablero) : numCasillas(tablero.numCasillas), casillas(tablero.casillas) {}; //Constructor copia

    ~Tablero() {
        // Liberar la memoria de las casillas del tablero
        for (auto casilla : casillas) {
            delete casilla;
        }
    }

    int getNumCasillas() const { //Se obtiene el numero de casillas
        return numCasillas;
    }

    Casilla* getCasilla(int posicion) const { //Se obtiene la casilla en la posicion dada
        if (posicion >= 0 && posicion < numCasillas) {
            return casillas[posicion];
        } else {
            return nullptr; 
        }
    }

    void setCasilla(int posicion, Casilla* casilla) { //Se cambia la casilla en la posicion dada
        if (posicion >= 0 && posicion < numCasillas) {
            casillas[posicion] = casilla;
        }
    }
};
