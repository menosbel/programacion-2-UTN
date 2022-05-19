#include "Alumno.h"
#include <iostream>

using namespace std;

void Alumno::cargar() {
	Persona::cargar();
	cout << "Legajo: ";
	cin >> _legajo;
	cout << "Email: ";
	cin >> _email;
	cout << "Codigo carrera: ";
	cin >> _codigo_carrera;
}

void Alumno::mostrar() {
	if (!_estado) return;
	Persona::mostrar();
	cout << "Legajo: " << _legajo << endl;
	cout << "Email: " << _email << endl;
	cout << "Codigo carrera: " << _codigo_carrera << endl;
	cout << endl;
}

int Alumno::grabar_en_disco(int pos)
{
	FILE* pAlu;
	errno_t err;
	int escribio;

	if (pos == -1) {
		err = fopen_s(&pAlu, "alumnos.dat", "ab");
	}
	else {
		err = fopen_s(&pAlu, "alumnos.dat", "rb+");
		fseek(pAlu, pos * sizeof(Alumno), 0);
	}
	if (err != 0) { return 0; }

	escribio = fwrite(this, (sizeof Alumno), 1, pAlu);
	fclose(pAlu);
	return escribio;
}

int Alumno::leer_de_disco(int pos)
{
	FILE* pAlu;
	errno_t err;
	int leyo;
	
	err = fopen_s(&pAlu, "alumnos.dat", "rb");

	if (err != 0) {
		cout << "Error de archivo" << endl;
		return -1;
	}

	fseek(pAlu, pos * (sizeof Alumno), 0); // lee desde 0 hasta el final del Alumno
	leyo = fread(this, (sizeof Alumno), 1, pAlu);
	

	fclose(pAlu);
	return leyo;
}

void Alumno::modificar_en_disco(int pos)
{
	FILE* pAlu;
	errno_t err;
	err = fopen_s(&pAlu, "alumnos.dat", "rb+");

	if (err != 0) {
		cout << "Error de archivo" << endl;
		return;
	}

	fseek(pAlu, pos * sizeof(Alumno), 0);

	fwrite(this, (sizeof Alumno), 1, pAlu);
	cout << "Registro modificado!" << endl;
	fclose(pAlu);
}


