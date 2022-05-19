#include "Empresa.h"
#include <iostream>

using namespace std;

void Empresa::cargar()
{
	cout << "Numero de empresa: ";
	cin >> _numEmpresa;
	cout << "Nombre de empresa: ";
	cin >> _nombreEmpresa;
	cout << "Cantidad de empleados: ";
	cin >> _cantidadEmpleados;
	cout << "Categoria: ";
	cin >> _categoria;
	cout << "Numero de municipio: ";
	cin >> _numMunicipio;
	estado = true;
}

void Empresa::mostrar()
{
	cout << "Numero empresa: " << _numEmpresa << endl;
	cout << "Nombre de empresa: " << _nombreEmpresa << endl;
	cout << "Cantidad de empleados: " << _cantidadEmpleados << endl;
	cout << "Categoria: " << _categoria << endl;
	cout << "Numero de municipio: " << _numMunicipio << endl;
	cout << endl;
}

int Empresa::grabar_en_disco()
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "empresas.dat", "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Empresa), 1, p);
	fclose(p);
	return escribio;
}

int Empresa::leer_de_disco(int pos)
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, "empresas.dat", "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Empresa) * pos, 0);
	int leyo = fread(this, sizeof(Empresa), 1, p);
	fclose(p);
	return leyo;
}
