#include <iostream>
#include <string.h>

using namespace std;


/*
cin.getline(cadena, 29);
cargarCadena(cadena, 29);

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++){
        pal[i] = cin.get();
        if(pal[i] == '\n') break;
    }
    pal[i] = '\0';
    fflush(stdin);
}
system("pause");
*/


struct MateriaStruct {
    int nroMateria;
    char nombreMateria[40];
    int cantAlumnos;
    int cantDocentes;
};

class Materia {
    public:
        int nroMateria;
        char nombreMateria[40];
        int cantAlumnos;
        int cantDocentes;

    public:
        void Cargar();
        void Mostrar();
        void setNroMateria(int nm){if(nm>=0)nroMateria = nm;}
        void setNombreMateria(char *nm){strcpy(nombreMateria, nm);}

        int getNroMateria(){return nroMateria;}
};

void Materia::Cargar(){
    cout << "Numero de materia: ";
    cin >> nroMateria;
    setNroMateria(nroMateria);
    cout << "Nombre de la materia: ";
    cin >> nombreMateria;
    cout << "Cantidad alumnos: ";
    cin >> cantAlumnos;
    cout << "Cantidad docentes: ";
    cin >> cantDocentes;
};

void Materia::Mostrar(){
    cout << "Numero de materia: ";
    cout << nroMateria;
    cout << endl;
    cout << "Nombre de la materia: ";
    cout << nombreMateria;
    cout << endl;
    cout << "Cantidad alumnos: ";
    cout << cantAlumnos;
    cout << endl;
    cout << "Cantidad docentes: ";
    cout << cantDocentes;
    cout << endl;
};

void cargarDatosMaterias(Materia *vec, int cant){
    int i;
    for(i=0; i<cant; i++){
        vec[i].Cargar();
    }
}

void mostrarDatosMaterias(Materia *vec, int cant){
    int i;
    for(i=0; i<cant; i++){
        vec[i].Mostrar();
    }
}

int main() {
    Materia obj, vec[5], *p;
    p = &obj;
    (*p).Cargar();
    p->Mostrar();

    obj.nroMateria = 8;
    obj.Cargar();
    obj.Mostrar();
    system("pause");
    cout << endl << endl << endl;
    cargarDatosMaterias(vec, 5);
    mostrarDatosMaterias(vec, 5);


    cout << "Numero materia: "<< obj.nroMateria << endl;
    return 0;
}
