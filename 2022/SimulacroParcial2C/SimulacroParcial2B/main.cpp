#include <cstdlib>
#include <iostream>
#include "Ciudad.h"
#include "Medicion.h"
#include "InformeUno.h"
#include "AuxPunto1.h"

using namespace std;

float calcularPromedio(int codCiudad)
{
	Medicion medicion;
	int pos = 0;
	int cantMediciones = 0;
	int sumaMediciones = 0;
	while (medicion.leerDeDisco(pos++))
	{
		if (medicion.getCodCiudad() == codCiudad)
		{
			cantMediciones++;
			sumaMediciones += medicion.getVisibilidad();
		}
	}

	return (float)sumaMediciones / cantMediciones;
}

// archivo con código de ciudad, nombre, promedio de visibilidad.
void puntoA()
{
	Ciudad ciudad;
	InformeUno informeUno;
	int pos = 0;
	float promedio;

	while (ciudad.leerDeDisco(pos++))
	{
		informeUno.setCodCiudad(ciudad.getCodCiudad());
		informeUno.setNombre(ciudad.getNombre());
		promedio = calcularPromedio(ciudad.getCodCiudad());
		informeUno.setPromedio(promedio);
		informeUno.grabarEnDisco();
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

void copiarNombreYCodigoPorCiudad(AuxPunto1* vector, int cant)
{
	Ciudad ciudad;

	for (int i = 0; i < cant; i++)
	{
		ciudad.leerDeDisco(i);
		vector[i].setCodCiudad(ciudad.getCodCiudad());
		vector[i].setNombre(ciudad.getNombre());
	}
}

int buscarCiudadEn(AuxPunto1* vector, int cant, int cc)
{
	for (int i = 0; i < cant; i++)
	{
		if (vector[i].getCodCiudad() == cc) return i;
	}
	return -1;
}

void contarYSumarMedicionesPorCiudad(AuxPunto1* vector, int cant)
{
	Medicion medicion;
	int pos = 0, posCiudad, cc, cantMediciones, sumaMediciones;

	while(medicion.leerDeDisco(pos++))
	{
		cc = medicion.getCodCiudad();
		posCiudad = buscarCiudadEn(vector, cant, cc);

		cantMediciones = vector[posCiudad].getCantMediciones();
		vector[posCiudad].setCantMediciones(cantMediciones++);

		sumaMediciones = vector[posCiudad].getSumaMediciones();
		vector[posCiudad] += medicion.getVisibilidad();
		//vector[posCiudad].setSumaMediciones(sumaMediciones += medicion.getVisibilidad());
	}
}

void puntoADinamico()
{
	AuxPunto1* vDinamico;
	InformeUno informeUno;
	int cantReg = contarCiudades();
	vDinamico = new AuxPunto1[cantReg];
	if (vDinamico == NULL) return;

	copiarNombreYCodigoPorCiudad(vDinamico, cantReg);
	contarYSumarMedicionesPorCiudad(vDinamico, cantReg);

	float promedio;
	for (int i = 0; i < cantReg; i++)
	{
		informeUno.setCodCiudad(vDinamico[i].getCodCiudad());
		informeUno.setNombre(vDinamico[i].getNombre());
		promedio = (float) vDinamico[i].getSumaMediciones() / vDinamico[i].getCantMediciones();
		informeUno.setPromedio(promedio);
		informeUno.grabarEnDisco();
	}

	delete[] vDinamico;
}


int main()
{
	puntoA();
	puntoADinamico();

	return 0;
}