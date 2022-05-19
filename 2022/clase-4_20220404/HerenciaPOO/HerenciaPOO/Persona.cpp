#include "Persona.h"

void Persona::cargar()
{
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Apellido: ";
	cin >> apellido;
	cout << "DNI: ";
	cin >> DNI;
	fechaNacimiento.cargar();
}

void Persona::mostrar()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido<< endl;
	cout << "DNI: " << DNI << endl;
	fechaNacimiento.mostrar();
}
