#include <iostream>
#include "clases.h"

using namespace std;

//PROTOTIPOS

void puntoB();
char categoriaConMenosEquipos(int* v, int tam);

int main()
{
    puntoB();

    return 0;
}

//Informar la categoría con menos cantidad de equipos.
void puntoB()
{
    int pos = 0;
    int division[3] = { 0 };
    Equipo equipo;

    while (equipo.leerDeDisco(pos++)) {
        char div = equipo.getDivision();

        switch (div) {
        case 'A':
            division[0]++;
            break;
        case 'B':
            division[1]++;
            break;
        case 'C':
            division[2]++;
            break;
        }
    }

    cout << "La categoria con menos equipos es la " << categoriaConMenosEquipos(division, 3) << endl;
}

char categoriaConMenosEquipos(int* v, int tam) {
    int posMin = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] < v[posMin]) {
            posMin = i;
        }

    }

    switch (posMin) {
    case 0:
        return 'A';
        break;
    case 1:
        return 'B';
        break;
    case 2:
        return 'C';
        break;
    }
};
