#pragma once
#include "Persona.h"

class Alumno:public Persona
{
private:
	int legajo;
public:
	int getLegajo() { return legajo; }
	void setLegajo(int value) { legajo = value; }
	void ponerCeroDNI() { DNI = 0; }
	void cargar();
	void mostrar();
};

