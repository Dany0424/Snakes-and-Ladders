//Axel Godoy y Erika Garcia
//Clase de un dado

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#pragma once

class Dado {
public:
    Dado() {}; //Constructor por omision
    Dado(const Dado &) = default; //Constructor copia en default
    ~Dado() {}; //Destructor
    int lanzarDado() {
        return rand() % 6 + 1;
    }
};
