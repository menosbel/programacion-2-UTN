#pragma once
#include <string>

using namespace std;

class Ciudad
{
private:
	int codigoCiudad, codigoProvincia;
	char nombre[30];
public:
	bool operator==(int codigo);
	int getCodigoCiudad() { return codigoCiudad; };
	int getCodigoProvincia() { return codigoProvincia; };
	char* getNombre() { return nombre; };
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
};


