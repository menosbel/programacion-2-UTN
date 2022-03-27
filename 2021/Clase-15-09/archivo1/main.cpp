#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#include "clases.h"
#include "funciones.h"


int main(){
    int opc;
    while(true){
        system("cls");
        cout << "1. CARGAR ALUMNOS" << endl;
        cout << "2. MOSTRAR ALUMNOS" << endl;
        cout << "3. MOSTRAR ALUMNOS POR AÑO" << endl;
        cout << "4. BORRAR REGISTRO ALUMNO" << endl;
        cout << "5. MODIFICAR APELLIDO ALUMNO" << endl;
        cout << "0. SALIR DEL PROGRAMA" << endl;
        cout << "**************************" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarAlumnos();
                    break;
            case 2: mostrarAlumnos();
                    break;
            case 3: mostrarAlumnosPorAnio();
                    break;
            case 4: if(bajaLogica()==true){
                        cout<<"REGISTRO BORRADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                    }
                    break;

            case 5: if(modificarApellido()==true){
                        cout<<"REGISTRO MODIFICADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                    }
                    break;

            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                    break;

        }
        system("pause");
    }
    return 0;
}

