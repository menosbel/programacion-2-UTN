#include <iostream>
#include "Empresa.h"

using namespace std;

/*
a) Calcular e informar la cantidad de empresas de cada municipio.
b) Informar los nombres de las empresas con más de 200 empleados.
c) Calcular e informar la categoría de empresa con más empleados
*/

void mostrar_registros();
void cargar_registro();
void puntoA();
void mostrarPuntoA(int* v, int tam);
void puntoB();
void puntoC();
int maximo_vector(int* v, int tam);

int main()
{
	int opcion;

	while (true) {
		cout << "---- MENU ----" << endl;
		cout << "1. PUNTO A" << endl;
		cout << "2. PUNTO B" << endl;
		cout << "3. PUNTO C" << endl;
		cout << "4. Cargar registros" << endl;
		cout << "3. Mostrar archivo" << endl;
		cout << "0. Fin del programa" << endl;
		cout << "Opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			puntoA();
			break;
		case 2:
			puntoB();
			break;
		case 3:
			puntoC();
			break;
		case 4:
			cargar_registro();
			break;
		case 5:
			mostrar_registros();
			break;
		case 0:
			return false;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}

void cargar_registro() {
	Empresa reg;
	reg.cargar();
	reg.grabar_en_disco();
}

void mostrar_registros() {
	int pos = 0;
	Empresa reg;
	while (reg.leer_de_disco(pos)) {
		reg.mostrar();
		pos++;
	}
}

void puntoA()
{
	int vMuni[135] = { 0 }, pos = 0;
	Empresa reg;
	while (reg.leer_de_disco(pos) == 1)
	{
		vMuni[reg.getNumMunicipio() - 1]++;
		pos++;
	}
	mostrarPuntoA(vMuni, 135);
}

void mostrarPuntoA(int* v, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		if (v[i] > 0) {
			cout << "Municipio: " << i << "\t" << "Cantidad de empresas: " << v[i] << endl;
		}
	}
};

void puntoB()
{
	int pos = 0;
	Empresa reg;
	cout << "Empresas con mas de 200 empleados" << endl;
	while (reg.leer_de_disco(pos) == 1)
	{
		if (reg.getCantidadEmpleados() > 200) {
			cout << reg.getNombreEmpresa() << endl;
		}
		pos++;
	}
}

void puntoC()
{
	int vCat[80] = { 0 }, pos = 0, maxCat = 0;
	Empresa reg;
	while (reg.leer_de_disco(pos) == 1)
	{
		vCat[reg.getNumCategoria() - 1] += reg.getCantidadEmpleados();
	}
	maxCat = maximo_vector(vCat, 80);
	cout << "La categoria con mas empleados es> "<< maxCat + 1 << endl;
}

int maximo_vector(int *v, int tam) {
	int posMax = 0;
	for (int i = 1; i < tam; i++)
	{
		if (v[i] > v[posMax]) {
			posMax = i;
		}
	}
	return posMax;
};