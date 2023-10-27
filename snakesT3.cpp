//Axel Godoy y Erika Garcia
//Aplicacion Principal

#include <iostream>
#include "Partida.h"
using namespace std;


int main() {
    int numCasillas, numSerpientes, numEscaleras, retrocesoMaximo, avanceMaximo, numJugadores, maxTurnos;
    char modoJuego;

    cout << "Introduce el número de casillas: " << endl;
    cin >> numCasillas;
    cout << "Introduce el número de serpientes: " << endl;
    cin >> numSerpientes;
    cout << "Introduce el número de escaleras: " << endl;
    cin >> numEscaleras;
    cout << "Introduce el máximo retroceso de una serpiente: " << endl;
    cin >> retrocesoMaximo;
    cout << "Introduce el máximo avance de una escalera: " << endl;
    cin >> avanceMaximo;
    cout << "Introduce el número de jugadores: " << endl;
    cin >> numJugadores;
    cout << "Introduce el número máximo de turnos: " << endl;
    cin >> maxTurnos;
    cout << "Selecciona el modo de juego (A para automático, M para manual): " << endl;
    cin >> modoJuego;

    Partida partida(numCasillas, numSerpientes, numEscaleras, retrocesoMaximo, avanceMaximo, numJugadores, maxTurnos, modoJuego);

    return 0;
}








