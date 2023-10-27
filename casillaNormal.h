//Axel Godoy y Erika Garcia
//Clase de una casilla normal con herencia de la clase Casilla

#include <iostream>
#include "Casilla.h"
using namespace std;
#pragma once

class CasillaNormal : public Casilla {
public:
    CasillaNormal() {}; //Constructor por omision
    CasillaNormal(int num) : Casilla(num) {} //Constructor
    CasillaNormal(const CasillaNormal &casillaNormal) : Casilla(casillaNormal.numero) {}; //Constructor copia
    ~CasillaNormal() {} //Destructor

    char getTipo() override {
        return 'N';
    }

    int getCasilla() override {
        return numero;
    }
};