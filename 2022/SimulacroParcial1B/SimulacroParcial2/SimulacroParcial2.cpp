#include <iostream>
#include "clases.h"

using namespace std;

class SocioMenor {
private:
	int dni;
	char nombre[30];
	char apellido[30];
public:
	void setDNI(int valor) { dni = valor; }
	void setNombre(const char* n) { strcpy_s(nombre, n); }
	void setApellido(const char* n) { strcpy_s(apellido, n); }
	int grabar_en_disco() {
		FILE* p;
		errno_t err;
		err = fopen_s(&p, "sociosMenoresNo2020.dat", "ab");
		if (err != 0) { return -1; }
		int escribio = fwrite(this, sizeof(SocioMenor), 1, p);
		fclose(p);
		return escribio;
	};
};

// PROTOTIPOS
void puntoA();
void puntoB();
bool inscripto2020(int dni);

int main()
{
	puntoA();
	puntoB();
	return 0;
}

//1. Generar un archivo con los socios menores que no se hayan inscripto en el 2020: DNI, nombre y apellido.
void puntoA() {
	int pos = 0;
	Socio socio;

	FILE* p;
	errno_t err;

	while (socio.leerDeDisco(pos++))
	{
		if (socio.getTipo() == 3)
		{
			if (!inscripto2020(socio.getDNI()))
			{
				SocioMenor socioMenor;
				socioMenor.setDNI(socio.getDNI());
				socioMenor.setNombre(socio.getNombre());
				socioMenor.setApellido(socio.getApellido());
				socioMenor.grabar_en_disco();

			}
		}
	}
}

bool inscripto2020(int dni)
{
	Inscripcion inscripcion;
	int pos = 0;

	while (inscripcion.leerDeDisco(pos++))
	{
		if (inscripcion.getDNISocio() == dni)
		{
			if (inscripcion.getFecha().getAnio() == 2020)
			{
				return true;
			}
		}
		return false;
	}
}

// Listar los socios que tengan una inscripción de tipo temporal del año pasado.
void puntoB() {
	Socio socio;
	int pos = 0;

	while (socio.leerDeDisco(pos++))
	{
		if (chequearInscripcion())
		{
			socio.Mostrar();
		}
	}
}

bool chequearInscripcion()
{
	Inscripcion inscripcion;
	int pos = 0;

	while (inscripcion.leerDeDisco(pos++))
	{
		if (inscripcion.getTipoInscripcion() == 1 && inscripcion.getFecha().getAnio() == 2021)
		{
			return true;
		}
		return false;
	}
}
