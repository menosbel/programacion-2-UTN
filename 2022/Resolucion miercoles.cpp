#include <iostream>
#include <cstring>

using namespace std;

#include "clases.h"

class MenoresNo2020{
    private:
        int dni;
        char nombre[30];
        char apellido[30];
    public:
        void setDni(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setApellido(const char *a){strcpy(apellido,a);}
        bool grabarEnDisco(){
            FILE *p=fopen("menoresNo2020.dat", "ab");
            if(p==NULL) return false;
            bool escribio=fwrite(this, sizeof *this, 1, p);
            fclose(p);
            return escribio;
        }
};

bool noInscripto2020(int d){
    Inscripcion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getDni()==d && reg.getFechaInscripcion().getAnio()==2020){
            return false;
        }
    }
    return true;
}

///Generar un archivo con los socios menores que no se hayan inscripto en el 2020 con el siguiente formato de registro:
///DNI, nombre y apellido.

void punto1(){
    Socio reg;
    MenoresNo2020 aux;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getTipo()==3){
            if(noInscripto2020(reg.getDni())){ ///noInscripto2020 devuelve true si no tiene ninguna inscripcion ese año
                aux.setDni(reg.getDni());
                aux.setNombre(reg.getNombre());
                aux.setApellido(reg.getApellido());
                aux.grabarEnDisco();
            }
        }
    }
}

bool tieneTemporal(int d){
    Inscripcion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getDni()==d && reg.getFechaInscripcion().getAnio()==2021 && reg.getTipoInscripcion()==1{
            return true;
        }
    }
    return false;
}

///Listar los socios que tengan una inscripción de tipo temporal del año pasado.

void punto2(){
    Socio reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(tieneTemporal(reg.getDni())){
            reg.Mostrar();
        }
    }
}

int main(){
    punto1();
    punto2();
    return 0;
}
