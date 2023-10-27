//Axel Godoy y Erika Garcia
//Clase de partida que contiene el tablero, los jugadores, el dado y el turno

#include <iostream>
#include <vector>
#include "Tablero.h"
#include "Jugador.h"
#include "Dado.h"
#include "Turno.h"
using namespace std;
#pragma once

class Partida {
private:
    Tablero tablero;
    vector<Jugador> jugadores;
    int jugadorActual;
    int contadorTurnos;
    Dado dado;
    int maxTurnos;
    vector<Serpiente> serpientes;
    vector<Escalera> escaleras;

public:
    Partida() {}; //Constructor por omision

    Partida(const Partida &) = default; //Constructor copia en default

    Partida(int numCasillas, int numSerpientes, int numEscaleras, int retrocesoMaximo, int avanceMaximo, int numJugadores, int maxTurnos, char modoJuego) :
        tablero(numCasillas), jugadorActual(0), contadorTurnos(0), maxTurnos(maxTurnos) {
        //Agregar serpientes al tablero a una casilla aleatoria y con un retroceso aleatorio
        for (int i = 0; i < numSerpientes; i++) {
            int casilla = rand() % numCasillas + 1;
            int retroceso = rand() % retrocesoMaximo + 1;
            Casilla* casillaActual = tablero.getCasilla(casilla - 1);
            if (casillaActual != nullptr) {
                delete casillaActual;
                tablero.setCasilla(casilla - 1, new Serpiente(casilla, retroceso)); 
            }
        }

        //Agregar escaleras al tablero a una casilla aleatoria y con un avance aleatorio
        for (int i = 0; i < numEscaleras; i++) {
            int casilla = rand() % numCasillas + 1;
            int avance = rand() % avanceMaximo + 1;
            Casilla* casillaActual = tablero.getCasilla(casilla - 1);
            if (casillaActual != nullptr) {
                delete casillaActual;
                tablero.setCasilla(casilla - 1, new Escalera(casilla, avance));
            }
        }

        for (int i = 0; i < numJugadores; i++) {
            string nombre;
            cout << "Ingrese el nombre del jugador " << (i + 1) << ": " << endl; //Se pide el nombre de los jugadores
            cin >> nombre;
            jugadores.push_back(Jugador(nombre));
        }

        srand(time(0));

        //Seleccionar el modo de juego
        if (modoJuego == 'A') {
            jugarAutomatico();
        } else if (modoJuego == 'M') {
            jugarManual();
        }
    }
    //imprime la informacion de cada turno
    void imprimeInformacion(int turno, const Jugador& jugador, int posicion, int tiroDado, char tipoCasilla, int casilla) {
        cout << turno << " " << jugador.getNombre() << " " << posicion << " " << tiroDado << " " << tipoCasilla << " " << casilla << endl;
    }
    //imprime los resultados del juego
    void imprimeResultados(const Jugador& ganador) {
        cout << "Jugador " << ganador.getNombre() << " ha ganado" << endl;
        cout << "--Fin del Juego--" << endl;
    }
    //juego automatico
    void jugarAutomatico() {
        cout << "Juego en modo automático:" << endl;

        while (contadorTurnos < maxTurnos) {
            contadorTurnos++;
            int tiroDado = dado.lanzarDado();
            Jugador& jugador = jugadores[jugadorActual];
            int posicionActual = jugador.getPosicion();
            Casilla* casillaActual = tablero.getCasilla(posicionActual - 1);
            char tipoCasilla = casillaActual->getTipo();
            int casilla = casillaActual->getCasilla();

            if (casilla < 1) {
                casilla = 1;  // No se permite retroceder más allá de la casilla 1
            }

            casilla += tiroDado;

            if (casilla > tablero.getNumCasillas()) {
                casilla = tablero.getNumCasillas();  // No se permite avanzar más allá de la última casilla
            }

            jugador.setPosicion(casilla);

            imprimeInformacion(contadorTurnos, jugador, posicionActual, tiroDado, tipoCasilla, casilla);

            if (casilla >= tablero.getNumCasillas()) {
                imprimeResultados(jugador);
                break;
            }

            jugadorActual++;
            if (jugadorActual >= jugadores.size()) {
                jugadorActual = 0;
            }
        }

        cout << "--Gracias por jugar--" << endl;
    }
    //juego manual
    void jugarManual() {
        cout << "Juego en modo manual. Presiona |C| para jugar o |E| para terminar el juego:" << endl;

        char jugarJuego;
        cin >> jugarJuego;

        //Valida que se ingrese una opcion correcta
        while (jugarJuego != 'E') { 
            if (jugarJuego != 'C') {
                cout << "Opción incorrecta. Presiona |C| para jugar o |E| para terminar el juego:" << endl;
                cin >> jugarJuego;
                continue;
            }

            contadorTurnos++; //Aumenta el contador de turnos
            int tiroDado = dado.lanzarDado(); //Se lanza el dado
            Jugador& jugador = jugadores[jugadorActual]; //Se obtiene el jugador actual
            int posicionActual = jugador.getPosicion(); //Se obtiene la posicion actual del jugador
            Casilla* casillaActual = tablero.getCasilla(posicionActual - 1); 
            char tipoCasilla = casillaActual->getTipo(); //Se obtiene el tipo de casilla
            int casilla = casillaActual->getCasilla(); //Se obtiene la casilla

            if (casilla < 1) {
                casilla = 1;  // No se permite retroceder más allá de la casilla 1
            }

            casilla += tiroDado;

            if (casilla > tablero.getNumCasillas()) {
                casilla = tablero.getNumCasillas();  // No se permite avanzar más allá de la última casilla
            }

            jugador.setPosicion(casilla); //Se actualiza la posicion del jugador

            imprimeInformacion(contadorTurnos, jugador, posicionActual, tiroDado, tipoCasilla, casilla);

            if (casilla >= tablero.getNumCasillas()) {
                imprimeResultados(jugador);
                break;
            }

            jugadorActual++;
            if (jugadorActual >= jugadores.size()) {
                jugadorActual = 0;
            }

            cin >> jugarJuego;
        }

        cout << "--Gracias por jugar--" << endl;
    }
};