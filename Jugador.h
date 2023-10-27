//Axel Godoy y Erika Garcia
//Clase de un jugador que hereda de persona

#include <iostream>
#include "Persona.h"
#include "Casilla.h"
#include "Escalera.h"
#include "Serpiente.h"
using namespace std;
#pragma once

class Jugador : public Persona {
private:
    int posicion;
public:
    Jugador() {}; //Constructor por omision
    Jugador(const string& nombre) : Persona(nombre), posicion(1) {}
    Jugador(const Jugador &jugador) : Persona(jugador.nombre), posicion(jugador.posicion) {}; //Constructor copia
    ~Jugador() {} //Destructor

    int getPosicion() const { 
        return posicion;
    }

    void setPosicion(int pos) {
        posicion = pos;
    }

    Jugador& operator+(Escalera& escalera)  {
    posicion += escalera.getCasilla();
    return *this;
    }

    Jugador& operator-(Serpiente& serpiente)  {
    posicion -= serpiente.getCasilla();
    return *this;
    }

};




