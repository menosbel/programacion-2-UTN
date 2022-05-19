#include <iostream>
#include "clases.h"

using namespace std;

class EquipoLocal {
private:
    int codigoEquipo;
    int cantPartidos;
    char nombreEquipo[30];
public:
    void setCodigoEquipo(int ce) { codigoEquipo = ce; }
    void setCantPartidos(int cp) { cantPartidos = cp; }
    void setNombreEquipo(const char* n) { strcpy_s(nombreEquipo, n); }
    int grabarEnDisco() {
        FILE* p;
        errno_t err;
        err = fopen_s(&p, "equiposLocales.dat", "ab");
        if (err != 0) { return -1; }
        int escribio = fwrite(this, sizeof(EquipoLocal), 1, p);
        fclose(p);
        return escribio;
    };
};

//PROTOTIPOS

void puntoA();
void puntoB();
int calcularCantidadPartidosLocal(int codigoEquipo);
char categoriaConMenosEquipos(int* v, int tam);

int main()
{
    puntoA();
    puntoB();

    return 0;
}

//Generar un archivo con la cantidad de partidos que cada equipo debe jugar como local este año
//Código de equipo, nombre de equipo, y cantidad de partidos a jugar como local este año.
void puntoA()
{
    int pos = 0;
    Equipo equipo;

    while (equipo.leerDeDisco(pos++)) {
        EquipoLocal equipoLocal;
        int codigoEquipo = equipo.getCodigoEquipo();
        int cantLocal = calcularCantidadPartidosLocal(codigoEquipo);
        equipoLocal.setCodigoEquipo(codigoEquipo);
        equipoLocal.setNombreEquipo(equipo.getNombreEquipo());
        equipoLocal.setCantPartidos(cantLocal);
        equipoLocal.grabarEnDisco();
    }
}

int calcularCantidadPartidosLocal(int codigoEquipo)
{
    int pos = 0, cant = 0;
    Partido partido;

    while (partido.leerDeDisco(pos++)) {
        if (partido.getCodigoEquipo1() == codigoEquipo)
        {
            cant++;
        }
    }
    return cant;
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
