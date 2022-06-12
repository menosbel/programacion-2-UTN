#include "InformeUno.h"
#include <iostream>

bool InformeUno::grabarEnDisco()
{
	FILE* p;
	errno_t err;
	const char* file = "informeUno.dat";
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(InformeUno), 1, p);
	fclose(p);
	return escribio;
}
