#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;


#include "funciones.h"
#include "Materia.h"

int main(){
    int opc;
//    cout << "Tamano registro de materia: " << sizeof(Materia) << endl << endl;
//    probarFtell();
    while(true){
        system("cls");
        cout << "1. CARGAR DATOS MATERIAS" << endl;
        cout << "2. MOSTRAR DATOS MATERIAS" << endl;
        cout << "3. ELIMINAR MATERIAS (baja logica)" << endl;
        cout << "4. MODIFICAR CANTIDAD ALUMNOS" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "----------------" << endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>opc;
        system("cls");

        switch(opc){
            case 1: cargarMateria();
                    break;
            case 2: mostrarMaterias();
                    break;
            case 3: if(borrarMateria()) cout << "REGISTRO ELIMINADO";
                    else cout << "NO SE PUDO ELIMIANR EL REGISTRO" ;
                    cout << endl;
                    break;
            case 4: if(modificarCantidadAlumnos()) cout << "REGISTRO MODIFICADO";
                    else cout << "NOSE PUDO MODIFICAR EL REGISTRO";
                    cout << endl;
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
