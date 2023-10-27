//Axel Godoy y Erika Garcia
//Clase de una serpiente con herencia de la clase Casilla

#include <iostream>
#include "Casilla.h"
using namespace std;
#pragma once

class Serpiente : public Casilla {
private:
    int retroceso;

public:
    Serpiente() {}; //Constructor por omision
    Serpiente(int num, int retro) : Casilla(num), retroceso(retro) {}
    Serpiente(const Serpiente &serpiente) : Casilla(serpiente.numero), retroceso(serpiente.retroceso) {}; //Constructor copia
    ~Serpiente() {} //Destructor

    char getTipo() override {
        return 'S';
    }
    
    int getCasilla() override {
        return numero - retroceso;
    }

};



