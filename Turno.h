//Axel Godoy y Erika Garcia
//Clase Turno

#include <iostream>
#include "Tablero.h"
#include "Jugador.h"
#include "Dado.h"
#include <cstdlib>
#include <ctime>
using namespace std;


class Turno {
private:
    int turno;
    const Jugador& jugador;
    int posicion;
    int tiroDado;
    char tipoCasilla;
    int casilla;

public:
    Turno(int turno, const Jugador& jugador, int posicion, int tiroDado, char tipoCasilla, int casilla)
        : turno(turno), jugador(jugador), posicion(posicion), tiroDado(tiroDado), tipoCasilla(tipoCasilla), casilla(casilla) {}

    void imprimirInformacion() const {
        cout << turno << " " << jugador.getNombre() << " " << posicion << " " << tiroDado << " " << tipoCasilla << " " << casilla << endl;
    }

    friend ostream& operator<<(ostream& os, const Turno& turno) {
        os << turno.turno << " " << turno.jugador.getNombre() << " " << turno.posicion << " " << turno.tiroDado << " " << turno.tipoCasilla << " " << turno.casilla;
        return os;
    }
};

