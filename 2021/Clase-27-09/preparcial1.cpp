///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

# include "clases.h"

///1. Generar un archivo con los Jefes de Área que hayan firmado contrato en el 2020 con el siguiente formato de registro:
///DNI, nombre y apellido.

///2. Listar el mes con más contratos temporarios del año 2015.

///3. Agregar un constructor con valores por omisión para la clase Museo del ejercicio de archivos.
///No es necesario hacer toda la clase de nuevo, sólo el constructor

///4. Defina brevemente el mecanismo de la Herencia en la POO

class Jefes_2020{
    private:
        int dni;
        char nombre[30];
        char apellido[30];
        bool estado;
    public:
        gets();
        bool grabarEnDisco();

};

void punto1();
bool buscarContrato(int DNI);

int main(){
    punto1();
    punto2();
	cout<<endl;
	system("pause");
	return 0;
}


void punto1(){
    Empleado reg;
    Jefes_2020 aux;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(reg.getCargo()==3){
            if(buscarContrato(reg.getDNI())==true){
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
        if(reg.getDNI()==DNI && reg.getFechaContrato().getAnio()==2020)
            return true;
    }
    return false;
}


void punto2(){
    Contrato reg;
    int pos=0;
    int mes[12]={0};

    while(reg.leerDeDisco(pos++)){

        if(reg.getTipoContrato()==1 && reg.getFechaContrato().getAnio()==2015)
            mes[reg.getFechaContrato().getMes()-1]++;
    }
    cout<<"MES CON MAS CONTRATOS TEMPORARIOS EN 2015: "<<buscarMaximo(mes,12)+1<<endl;
}


void punto2(){
    Contrato reg;
    int pos=0;
    int mes[12]={0};
    Fecha aux;
    while(reg.leerDeDisco(pos++)){
        aux=reg.getFechaContrato();
        if(reg.getTipoContrato()==1 && aux.getAnio()==2015)
            mes[aux.getMes()-1]++;
    }
    cout<<"MES CON MAS CONTRATOS TEMPORARIOS EN 2015: "<<buscarMaximo(mes,12)+1<<endl;
}


void punto2(){
    Contrato reg;
    int pos=0;
    int mes[12]={0};
    while(reg.leerDeDisco(pos++)){
        if(reg.getTipoContrato()==1 && reg.getAnio()==2015)
            mes[reg.getMes()-1]++;
    }
    cout<<"MES CON MAS CONTRATOS TEMPORARIOS EN 2015: "<<buscarMaximo(mes,12)+1<<endl;
}
