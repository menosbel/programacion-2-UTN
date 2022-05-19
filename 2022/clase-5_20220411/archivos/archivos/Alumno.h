#pragma once
#include <string>
#include "Fecha.h"
#include "Persona.h"

using namespace std;

class Alumno: public Persona
{
private:
	int _legajo;
	char _email[25];
	int _codigo_carrera;
public:
	int getLegajo() { return _legajo; };
	void cargar();
	void mostrar();
	int grabar_en_disco(int pos = -1);
	int leer_de_disco(int pos);
	void modificar_en_disco(int pos);
};

