#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include <random>

using namespace std;


int generationNombre(int min, int max)
{

	int nombre =  rand() % max + min;


    return nombre;
}

#endif
