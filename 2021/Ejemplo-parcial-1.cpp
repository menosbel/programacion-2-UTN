#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

#include "clases.h"

class Esencial{
    private:
        int numeroEmpresa;
        char nombreEmpresa[30];
        int cantEmpleados;
    public:
        void setNumeroEmpresa(int ne){numeroEmpresa=ne;}
        void setNombreEmpresa(const char *ne){strcpy(nombreEmpresa, ne);}
        void setCantEmpleados(int ce){cantidadEmpleados=ce;}
        bool grabarEnDisco(){
            FILE *p;
            p=fopen("esenciales.dat", "ab");
            if(p==NULL) return false;
            bool escribio = fwrite(this, sizeof (Esencial),1,p);
            fclose(p);
            return escribio;
        }
};

// prototipos
void puntoA();
void mostrarVector(int *, int); //HACERLA
void puntoB();
bool buscarCategoria(int cat);
void puntoC();
bool crearArchivoEsencial();

int main(){
    puntoA();
    puntoB();

    if(crearArchivoEsencial()!= true){
        cout << "No se pudo generar el archivo de esenciales" << endl;
        return -1;
    };
    puntoC();

    cout << endl;
    system("pause");
    return 0;
}

void puntoA(){
    int pos=0, cantPorSeccion[9]={};
    Municipio reg;
    while(reg.leerDeDisco(pos) == true){
        cantPorSeccion[reg.getSeccion()-1]++;
        pos++;
    }
    cout << "Cantidad de municipios por seccion: " << endl;
    mostrarVector(cantPorSeccion, 9);
}

void puntoB(){
    Empresa reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCantidadEmpleados() > 200) {
            cout << reg.getNombreEmpresa() << endl;
        }
    }
}

void puntoC(){
    Empresa reg;
    Esencial aux;
    bool esencial;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        esencial=buscarCategoria(reg.getCategoria());
        if(esencial){
            aux.setNumeroEmpresa(reg.getNumeroEmpresa());
            aux.setNombreEmpresa(reg.getNombreEmpresa());
            aux.setCantEmpleados(reg.getCantEmpleados());
            aux.grabarEnDisco();
        }
    }
}

bool buscarCategoria(int cat){
    Categoria reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(cat==reg.getNumeroCategoria()) return reg.getEsencial();
    }
    return false;
}

void crearArchivoEsencial(){
    FILE *p;
    p=fopen("esenciales.dat", "wb");
    if(p==NULL) return false;
    fclose(p);
    return true;
}
