#pragma once
#include <cstdlib>
#include <string.h>
using namespace std;

class Punto1
{
private:
	int codigoCiudad;
	char nombre[30];
	float promedio;
public:
	void setCodigoCiudad(int cc) { codigoCiudad = cc; };
	void setNombre(const char* n) { strcpy_s(nombre, n); };
	void setPromedio(float p) { promedio = p; };
	bool grabarEnDisco();
};

