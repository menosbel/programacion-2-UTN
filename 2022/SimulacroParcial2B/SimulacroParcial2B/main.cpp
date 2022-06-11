#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Fecha
{
private:
	int dia, mes, anio;
public:
	int getDia() { return dia; };
	int getMes() { return mes; };
	int getAnio() { return anio; };
};

class Cosecha
{
private:
	int numCosecha, codigoCereal;
	float cantToneladas;
	Fecha fechaCosecha;
	char codEmpresa[5];
public:
	float getCantToneladas() { return cantToneladas; };
	Fecha getFechaCosecha() { return fechaCosecha; };
	int leerDeDisco(int pos)
	{
		int leyo;
		FILE* p;
		errno_t err;
		const char* file = "cosechas.dat";
		err = fopen_s(&p, file, "rb");
		if (err != 0) { return -1; }
		fseek(p, sizeof(Cosecha) * pos, 0);
		int leyo = fread(this, sizeof(Cosecha), 1, p);
		fclose(p);
		return leyo;
	}
	int modificarEnDisco(int pos)
	{
		int escribio;
		FILE* p;
		p = fopen("cosechas.dat", "rb+");
		if (p == NULL) return 0;
		fseek(p, pos * sizeof(Cosecha), 0);
		escribio = fwrite(this, sizeof(Cosecha), 1, p);
		fclose(p);
		return escribio;
	}
};