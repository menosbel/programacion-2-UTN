#include <iostream>
#include <cstdlib>
#include "Ciudad.h"
#include "Punto1.h"

using namespace std;

float calcularPromedio(int cc)
{
	Medicion reg;
	int cantMediciones = 0, sumaMediciones = 0, pos = 0;
	while (reg.leerDeDisco(pos++))
	{
		if (reg == cc)
		{

		}
	}
}

int main()
{
	Ciudad reg;
	Punto1 punto1;
	int pos = 0;
	while (reg.leerDeDisco(pos ++))
	{
		punto1.setCodigoCiudad(reg.getCodigoCiudad());
		punto1.setNombre(reg.getNombre());
		punto1.setPromedio(calcularPromedio(reg.getCodigoCiudad()));
		punto1.grabarEnDisco();
	}

	system("pause");
	return 0;
}