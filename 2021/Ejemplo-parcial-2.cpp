#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include<clocale>;

#include "clases.h";

// 1. Generar archivo con jefe de area que hayan firmado contrato en 2020. DNI, nombre y apellido.
// 2. Listar el mes con mas contratos temporarios del year 2015
// 3. Agregar un constructor con valores por omision para la clase Museo del ejercicio de archivos
// 4. Defina brevemente el mecanismo de la herencia en la POO

class Jefes_2020 {
    private:
        int dni;
        char nombre[30];
        char apellido[30];
        bool estado;
    public:
        gets();
        bool grabarEnDisco();
};


// Prototipos
void punto1();
void punto2();
bool buscarContrato(int DNI);
char* buscarMaximo(mes, 12);


int main(void){
	setlocale(LC_ALL, "Spanish");
	punto1();
	punto2();
	punto3();

	return 0;
}

void punto1(){
    Empleado reg;
    Jefes_2020 aux;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(reg.getCargo()==3){
            if(buscarContrato(red.getDNI())){
                aux.setDNI(reg.getDNI());
                aux.setNombre(reg.getNombre());
                aux.setApellido(reg.getApellido());
                aux.setEstado(true);
                aux.grabarEnDisco();
            }
        }
        pos++;
    }
}

bool buscarContrato(int DNI){
    Contrato reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getDNI() == DNI && reg.getFechaContrato().getAnio() == 2020){
            return true;
        }
    }
    return false;
}

void punto2(){
    Contrato reg;
    int pos=0;
    int mes[12]={0};
    while(reg.leerDeDisco(pos++)){
        if(reg.getTipoContrato() == 1 && reg.getFechaContrato().getAnio() == 2015){
            mes[reg.getFechaContrato().getMes()-1]++;
        }
    }
    cout << "Mes con mas contratos temporarios en 2015: " << buscarMaximo(mes, 12)+1 << endl;
}
