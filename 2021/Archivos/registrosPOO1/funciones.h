#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Materia.h"

///prototipos
void cargarMateria();
void mostrarMaterias();
bool borrarMateria();
int buscarMateria(int nroMateria);
bool modificarCantidadAlumnos();
void probarFtell();
bool grabarEnDisco(Materia);
int contarRegistrosMaterias();

/// -----


void cargarMateria(){
    Materia reg;
    reg.Cargar();
    if(grabarEnDisco(reg)==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
}

void mostrarMaterias(){
    FILE *pMateria;
    Materia obj;
    int i;
    pMateria = fopen("materias.txt", "rb");

    if(pMateria == NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(obj.leerDeDisco(i++)){
        obj.Mostrar();
        cout << endl;
    }
/*
    while(fread(&obj, sizeof obj, 1, pMateria) == 1){
        obj.Mostrar();
        cout << endl;
    }
*/
    fclose(pMateria);
}

bool borrarMateria(){
    int nroMateria, pos;
    Materia reg;
    cout << "Ingresar numero de materia a eliminar: ";
    cin >> nroMateria;

    pos = buscarMateria(nroMateria);

    if(pos == -1){
        cout << "No existe una materia con ese numero" << endl;
        system("pause");
        return false;
    }

    reg.leerDeDisco(pos);
    reg.setActivo(false);

    if(reg.modificarEnDisco(pos)){
        return true;
    } else {
        return false;
    }
}

int buscarMateria(int nroMateria){
    Materia reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
        if(reg.getNroMateria() == nroMateria){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool modificarCantidadAlumnos(){
    int nroMateria, pos;
    Materia reg;
    cout << "Ingresar numero de materia a modificar: ";
    cin >> nroMateria;

    pos = buscarMateria(nroMateria);

    if(pos == -1){
        cout << "No existe una materia con ese numero" << endl;
        system("pause");
        return false;
    }

    reg.leerDeDisco(pos);

    int cantidad;
    cout << "INGRESE LA CANTIDAD DE ALUMNOS: ";
    cin >> cantidad;
    reg.setCantidadAlumnos(cantidad);
    if(reg.modificarEnDisco(pos)){
        return true;
    } else {
        return false;
    }
}

void probarFtell(){
    Materia reg;
    int cantByte;
    FILE *p;
    p = fopen("materia.dat", "rb");
    if(p== NULL){
        cout << "ERROR";
        return;
    }
    cantByte = ftell(p);
    cout << "Valor devuelto de Ftell: " << cantByte << endl << endl;
    while(fread(&reg, sizeof reg, 1, p)==1){
        cantByte = ftell(p);
        cout << "Valor devuelto de Ftell: " << cantByte << endl << endl;
    }
}

bool grabarEnDisco(Materia obj){
    FILE *pMateria;
    pMateria=fopen("materias.dat", "ab");

    if(pMateria==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fwrite(&obj, sizeof(Materia), 1, pMateria); // le mando una direccion para que pueda recibir dist tipos
    fclose(pMateria);
    return true;
}

int contarRegistrosMaterias(){
    int cantReg;
    Materia reg;
    int cantByte;
    FILE *p;
    p=fopen("materias.dat", "rb");
    if(p==NULL){
        cout << "ERROR";
        return -1;
    }
    fseek(p, 0, 2); // 0 bytes desde 2, que es el final
    //while(fread(&reg, sizeof reg, 1, p)==1);
    cantByte=ftell(p);
    cantReg=cantByte/sizeof(Materia);
    return cantReg;
}

#endif // FUNCIONES_H_INCLUDED
