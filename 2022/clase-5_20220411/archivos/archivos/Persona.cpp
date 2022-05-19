#include "Persona.h"
#include <iostream>

using namespace std;

void Persona::cargar() {
    cout << "DNI: ";
    cin >> _DNI;
    cout << "NOMBRE: ";
    cin >> _nombre;
    cout << "APELLIDO: ";
    cin >> _apellido;
    _fecha_nacimiento.cargar();
    _estado = 1;
}

void Persona::mostrar() {
    cout << "DNI: ";
    cout << _DNI << endl;
    cout << "NOMBRE: ";
    cout << _nombre << endl;;
    cout << "APELLIDO: ";
    cout << _apellido << endl;
    cout << "FECHA DE NACIMIENTO: " << endl;
    _fecha_nacimiento.mostrar();
}

