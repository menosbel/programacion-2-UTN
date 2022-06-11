#include "Ciudad.h"
#include <iostream>

bool Ciudad::operator==(int codigo)
{
    if (codigoCiudad == codigo) return true;
    return false;
}

bool Ciudad::grabarEnDisco()
{
	FILE* p;
	errno_t err;
	const char* file = "ciudades.dat";
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Ciudad), 1, p);
	fclose(p);
	return escribio;
}

bool Ciudad::leerDeDisco(int pos)
{
	FILE* p;
	errno_t err;
	const char* file = "ciudades.dat";
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Ciudad) * pos, 0);
	int leyo = fread(this, sizeof(Ciudad), 1, p);
	fclose(p);
	return leyo;
}
