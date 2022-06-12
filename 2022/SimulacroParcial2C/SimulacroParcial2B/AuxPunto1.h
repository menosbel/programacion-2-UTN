#pragma once
#include <string>

class AuxPunto1
{
private:
	int codCiudad;
	char nombre[30];
	int cantMediciones;
	float sumaMediciones;
public:
	AuxPunto1(int cc = 0, int cm = 0, int sm = 0) {
		codCiudad = cc;
		cantMediciones = cm;
		sumaMediciones = sm;
	}
	void setCodCiudad(int cc) { codCiudad = cc; };
	void setCantMediciones(int cm) { cantMediciones = cm; };
	void setSumaMediciones(int sm) { sumaMediciones = sm; };
	void setNombre(const char* n) { strcpy_s(nombre, n); };
	int getCodCiudad() { return codCiudad; };
	int getCantMediciones() { return cantMediciones; };
	int getSumaMediciones() { return sumaMediciones; };
	char* getNombre() { return nombre; };
	void operator+=(int valor)
	{
		sumaMediciones += valor;
	}
};

