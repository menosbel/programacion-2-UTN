#pragma once
#include <cstdlib>
#include <string.h>
using namespace std;


class InformeUno
{
private:
	int codCiudad;
	char nombre[30];
	float promedio;
public:
	void setCodCiudad(int valor) { codCiudad = valor; };
	void setNombre(const char* valor) { strcpy_s(nombre, valor); };
	void setPromedio(float valor) { promedio = valor; };
	bool grabarEnDisco();
};

