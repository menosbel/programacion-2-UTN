#include "Alumnos.h"
#include <iostream>
using namespace std;

void Alumnos::grabar_registro(Alumno aux)
{
	FILE* pAlu;
	errno_t err;
	err = fopen_s(&pAlu, "alumnos.dat", "ab");

	if (err != 0) {
		cout << "Error de archivo" << endl;
		return;
	}

	fwrite(&aux, (sizeof Alumno), 1, pAlu);
	cout << "Registro agregado!" << endl;
	fclose(pAlu);
}

void Alumnos::leer_registros()
{
	FILE* pAlu;
	Alumno aux;
	errno_t err;
	err = fopen_s(&pAlu, "alumnos.dat", "rb");

	if (err != 0) {
		cout << "Error de archivo" << endl;
		return;
	}

	while (fread(&aux, (sizeof Alumno), 1, pAlu) == 1)
	{
		aux.mostrar();
		cout << endl;
	}

	fclose(pAlu);
}

void Alumnos::leer_registros_v2()
{
	Alumno aux;
	errno_t err;

	int pos = 0;
	while (aux.leer_de_disco(pos) == 1)
	{
		aux.mostrar();
		cout << endl;
		pos++;
	}
}

void Alumnos::borrar_registro()
{
	Alumno aux;
	int pos = 0;
	int legajo;
	cout << "Legajo a borrar: ";
	cin >> legajo;
	pos = buscar_legajo_alumno(legajo);
	if (pos >= 0) 
	{
		aux.leer_de_disco(pos);
		aux.setEstado(false);
		aux.grabar_en_disco(pos);
	}
	else
	{
		cout << "No existe el lagajo" << endl;
	}
}

int Alumnos::buscar_legajo_alumno(int legajo)
{
	Alumno aux;
	int pos = 0;
	while (aux.leer_de_disco(pos) == 1)
	{
		if (aux.getLegajo() == legajo) return pos;
		pos++;
	}

	return -1;
}

void Alumnos::modificar_fecha_nacimiento()
{
	Alumno aux;
	Fecha fecha;
	int pos = 0;
	int legajo;
	cout << "Ingrese el legajo del alumno a modificar: ";
	cin >> legajo;
	pos = buscar_legajo_alumno(legajo);
	if (pos >= 0)
	{
		aux.leer_de_disco(pos);
		cout << "Ingrese la fecha de nacimiento correcta: ";
		fecha.cargar();
		aux.setFechaNacimiento(fecha);
		aux.grabar_en_disco(pos);
	}
	else
	{
		cout << "No existe el lagajo" << endl;
	}
}

void Alumnos::recuperar_registros()
{
	Alumno aux;
	int pos = 0;
	while (aux.leer_de_disco(pos) == 1)
	{
		if (aux.getEstado() == false) {
			aux.setEstado(true);
			aux.grabar_en_disco(pos);
		};
		pos++;
	}
}
