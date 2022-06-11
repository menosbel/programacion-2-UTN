#include <iostream>
#include <cstdlib>
#include "Ciudad.h"
#include "Punto1.h"
#include "Medicion.h"
#include "AuxPunto1.h"

using namespace std;

float calcularPromedio(int cc)
{
	Medicion reg;
	int cantMediciones = 0, sumaMediciones = 0, pos = 0;
	while (reg.leerDeDisco(pos++))
	{
		if (reg == cc) // if(reg.getCodigoCiudad() == cc)
		{
			cantMediciones++;
			sumaMediciones += reg.getVisibilidad();
		}
	}
	return (float)sumaMediciones / cantMediciones;
}

void punto1()
{
	Ciudad reg;
	Punto1 punto1;
	int pos = 0;
	while (reg.leerDeDisco(pos++))
	{
		punto1.setCodigoCiudad(reg.getCodigoCiudad());
		punto1.setNombre(reg.getNombre());
		punto1.setPromedio(calcularPromedio(reg.getCodigoCiudad()));
		punto1.grabarEnDisco();
	}
}

int contarCiudades()
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "ciudades.dat", "rb");
	if (err != 0) { return 0; };
	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Ciudad);
	return cant_reg;
}

void copiarCodigoCiudades(AuxPunto1* v, int cantReg)
{
	Ciudad reg;
	for (int i = 0; i < cantReg; i++)
	{
		reg.leerDeDisco(i);
		v[i].setCodCiudad(reg.getCodigoCiudad());
		v[i].setNombre(reg.getNombre());
	}
}

int buscarCiudadEnVector(int cc, AuxPunto1* v, int cant)
{
	for (int i = 0; i < cant; i++)
	{
		if (v[i].getCodCiudad() == cc) return i;
	}
	return -1;
}

void contarSumarMediciones(AuxPunto1* v, int cantReg)
{
	Medicion reg;
	int pos = 0, posVector;

	while (reg.leerDeDisco(pos++))
	{
		posVector = buscarCiudadEnVector(reg.getCodigoCiudad(), v, cantReg);
		v[posVector].setCantMediciones(v[posVector].getCantMediciones() + 1);
		//v[posVector].setSumaMediciones(v[posVector].getSumaMediciones() + reg.getVisibilidad());
		v[posVector] += reg.getVisibilidad();
	}
}

void punto1Dinamico()
{
	AuxPunto1* vDinamico;
	Punto1 obj;
	int cantReg = contarCiudades();
	vDinamico = new AuxPunto1[cantReg];
	if (vDinamico == NULL) return;

	copiarCodigoCiudades(vDinamico, cantReg);
	contarSumarMediciones(vDinamico, cantReg);

	for (int i = 0; i < cantReg; i++)
	{
		obj.setCodigoCiudad(vDinamico[i].getCodCiudad());
		obj.setNombre(vDinamico[i].getNombre());
		float prom = (float) vDinamico[i].getSumaMediciones() / vDinamico[i].getCantMediciones();
		obj.setPromedio(prom);
		obj.grabarEnDisco();
	}

	delete[] vDinamico;
}

int main()
{
	punto1();

	system("pause");
	return 0;
}