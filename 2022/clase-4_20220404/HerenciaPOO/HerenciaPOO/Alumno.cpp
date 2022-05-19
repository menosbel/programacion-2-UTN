#include "Alumno.h"

void Alumno::cargar()
{
	Persona::cargar();
	cout << "Legajo: ";
	cin >> legajo;
}

void Alumno::mostrar()
{
	Persona::mostrar();
	cout << "Legajo: " << legajo << endl;
}
