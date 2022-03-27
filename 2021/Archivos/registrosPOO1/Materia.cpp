#include<iostream>;
using namespace std;
#include<clocale>;
#include "Materia.h"

void Materia::Mostrar(){
    if(activo){
        cout<<"NUMERO DE MATERIA: ";
        cout<<this->nroMateria<<endl;
        cout<<"NOMBRE DE MATERIA: ";
        cout<<nombreMateria<<endl;
        cout<<"CANTIDAD DE ALUMNOS: ";
        cout<<cantAlumnos<<endl;
        cout<<"CANTIDAD DE DOCENTES: ";
        cout<<cantDocentes<<endl<<endl;
    }
}

void Materia::Cargar(){
    int nro;
    cout<<"NUMERO DE MATERIA: ";
    cin>>nro;
    setNroMateria(nro);
    cout<<"NOMBRE DE MATERIA: ";
    cin.ignore();
    cin.getline(nombreMateria,35);
    cout<<"CANTIDAD DE ALUMNOS: ";
    cin>>this->cantAlumnos;
    cout<<"CANTIDAD DE DOCENTES: ";
    cin>>cantDocentes;
    activo = true;
}

bool Materia::leerDeDisco(int pos){
    FILE *pMateria;
    pMateria=fopen("materias.dat", "rb");

    if(pMateria==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fseek(pMateria, sizeof(Materia)*pos, 0);

    bool leyo = fread(this, sizeof(Materia), 1, pMateria);
    fclose(pMateria);
    return leyo;
}

bool Materia::modificarEnDisco(int pos){
    FILE *pMateria;
    pMateria = fopen("materias.dat", "rb+");

    if(pMateria == NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }

    fseek(pMateria, sizeof(Materia)*pos, 0);
    bool escribio = fwrite(this, sizeof(Materia), 1, pMateria);
    fclose(pMateria);
    return escribio;
}
