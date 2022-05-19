#pragma once
#include "Fecha.h"
#include <iostream>

using namespace std;

class Persona
{
protected: // permite modificar a clases derivadas
	int DNI;
	char nombre[25];
	char apellido[25];
	Fecha fechaNacimiento;
public:
	const char* getNombre() { return nombre; }
	const char* getApellido() { return apellido; }
	int getDNI() { return DNI; }
	Fecha getFechaNacimiento() { return fechaNacimiento; };

	void setNombre(const char* n) { strcpy_s(nombre, n); }
	void setFecha(Fecha value) { fechaNacimiento = value; };

	void cargar();
	void mostrar();
};

