//Axel Godoy y Erika Garcia
//Clase de una casilla que sera heredada a las demas casillas

#include <iostream>
using namespace std;
#pragma once

class Casilla {
protected:
    int numero;

public:
    Casilla() {}; //Constructor por omision
    Casilla(const int &num) : numero(num) {}; //Constructor que recibe un parametro
    Casilla(const Casilla &casilla) : numero(casilla.numero) {}; //Constructor copia 
    virtual ~Casilla() {}; //Destructor virtual
    virtual char getTipo() = 0;
    virtual int getCasilla() = 0;

};
