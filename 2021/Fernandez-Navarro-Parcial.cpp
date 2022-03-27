#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

#include "clases.h"

class Division_A {
    private:
        int codEquipo;
        char nombreEquipo[50];
        int cantJugadores;
    public:
        int getCodEquipo(){return codEquipo;}
        char getNombreEquipo(){return nombreEquipo;}
        int getCantJugadores(){return cantJugadores;}

        void setCodEquipo(int codigo){codEquipo = codigo;}
        void setNombreEquipo(const char *ne){nombreEquipo = ne;}
        void setCantJugadores(int cant){cantJugadores = cant;}

        bool grabarEnDisco(){
            FILE *file;
            file=fopen("divisionA.dat", "ab");
            if(file==NULL) return false;
            fwrite(this, sizeof (Division_A), 1, file);
            fclose(file);
            return true;
        }
};


// Prototipos
void numeroCamisetaMenosJugadores();
int buscar_menor(*jugadoresPorCamiseta);
void divisionA();
void crearArchivoEquipoA();
int contarJugadoresEquipo(int codigoEquipo);


int main(void){
    while(true){
        system("cls");
        cout << "1. NUMERO DE CAMISETA CON MENOS JUGADORES" << endl;
        cout << "2. EQUIPOS DE LA DIVISION A CON MAS DE 40 JUGADORES" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "----------------" << endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>opc;
        system("cls");

        switch(opc){
            case 1: numeroCamisetaMenosJugadores();;
                    break;
            case 2: if(crearArchivoDivisionA()!= true) cout << "No se pudo crear el archivo Division_A" << endl;
                    else divisionA();
                    break;
            case 0: return 0;
                    break;
            default:cout<<"OPCION INCORRECTA. INGRESE NUEVAMENTE"<<endl;
                  break;

        }
        system("pause");
    }
	return 0;
}

int numeroCamisetaMenosJugadores(){
    Jugador reg;
    int pos=0, jugadoresPorCamiseta[34]={};

    while(reg.leerDeDisco(pos++)){
        jugadoresPorCamiseta[reg.getNroCamiseta() - 1]++;
    }

    cout << "El numero de camiseta con menos jugadores es el: " << buscarMenor(jugadoresPorCamiseta) << endl;
}

int buscar_menor(jugadoresPorCamiseta){
    int i, cantJugadores=jugadoresPorCamiseta[0], numeroCamiseta = 0;
    for(i; i<34; i++){
        if(jugadoresPorCamiseta[i] > cantJugadores){
            cantJugadores = jugadoresPorCamiseta[i];
            numeroCamiseta = i + 1;
        }
    }
    return numeroCamiseta;
}

void crearArchivoDivisionA(){
    FILE *p;
    p=fopen("divisionA.dat", "wb");
    if(p==NULL) return false;
    fclose(p);
    return true;
}

void divisionA(){
    Equipo reg;
    Division_A aux;
    char division;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        division = reg.getDivision();
        if(division == 'A'){
            int cantJugadores = 0;
            int codigoEquipo = reg.getCodigoEquipo();
            cantJugadores = contarJugadoresEquipo(codigoEquipo);
            if(cantJugadores > 40){
                bool escribio = false;
                aux.setCodEquipo(reg.codigoEquipo());
                aux.setNombreEquipo(reg.getNombreEquipo());
                aux.setCantJugadores(cantJugadores);
                escribio = aux.grabarEnDisco();
                if(!escribio){
                    cout << "No se pudo escribir el archivo Division_A.dat" << endl;
                }
            }
        }
    }
}

int contarJugadoresEquipo(codigoEquipo){
    int pos=0, int cantJugadores=0;
    Jugador reg;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCodigoEquipo()==codigoEquipo){
            cantJugadores++;
        }
    }
    return cantJugadores;
}
