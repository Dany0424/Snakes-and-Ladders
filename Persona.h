//Axel Godoy y Erika Garcia
//Clase de una persona que sera heredada a jugador

#include <iostream>
using namespace std;
#pragma once

class Persona {
protected:
    string nombre;

public:
    Persona() {}; //Constructor por omision
    Persona(const string& nombre) : nombre(nombre) {}
    Persona(const Persona &persona) : nombre(persona.nombre) {}; //Constructor copia
    virtual ~Persona() {}; //Destructor virtual

    string getNombre() const {
        return nombre;
    }
};
