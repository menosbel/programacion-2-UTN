#include "Medicion.h"
#include <iostream>

bool Medicion::operator==(int codigo)
{
    if (codigoCiudad == codigo) return true;
    return false;
}

bool Medicion::grabarEnDisco()
{
	FILE* p;
	errno_t err;
	const char* file = "mediciones.dat";
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Medicion), 1, p);
	fclose(p);
	return escribio;
}

bool Medicion::leerDeDisco(int pos)
{
	FILE* p;
	errno_t err;
	const char* file = "mediciones.dat";
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Medicion) * pos, 0);
	int leyo = fread(this, sizeof(Medicion), 1, p);
	fclose(p);
	return leyo;
}
