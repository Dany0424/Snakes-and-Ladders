//Axel Godoy y Erika Garcia
//Clase de una escalera con herencia de la clase Casilla

#include <iostream>
#include "Casilla.h"
using namespace std;
#pragma once

class Escalera : public Casilla {
private:
    int avance;

public:
    Escalera() {}; //Constructor por omision
    Escalera(int num, int av) : Casilla(num), avance(av) {}
    Escalera(const Escalera &escalera) : Casilla(escalera.numero), avance(escalera.avance) {}; //Constructor copia
    ~Escalera() {} //Destructor

    char getTipo() override {
        return 'E';
    }


    int getCasilla() override {
       return numero + avance;
    }

};





