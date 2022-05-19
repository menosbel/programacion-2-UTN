#include <iostream>
#include <cstring>
#include "Alumno.h"
#include "Persona.h"

using namespace std;

int main() {
	Alumno obj;
	obj.setLegajo(123);
	cout << obj.getLegajo() << endl;

	obj.setNombre("Belen");
	cout << obj.getNombre() << endl;

	obj.ponerCeroDNI();
	cout << obj.getDNI() << endl;
	cout << endl;

	cout << "PERSONA" << endl;
	Persona persona;
	persona.cargar();
	cout << endl;
	persona.mostrar();

	cout << endl;
	cout << endl;

	cout << "HERENCIA" << endl;
	Alumno alumno;
	alumno.cargar();
	cout << endl;

	alumno.mostrar();

	return 0;
}