#include "Punto1.h"
#include <iostream>
using namespace std;

bool Punto1::grabarEnDisco()
{
	FILE* p;
	errno_t error;

	error = fopen_s(&p, "punto1.dat", "ab");
	if (error != 0) { return false; }
	bool guardo = fwrite(this, sizeof(Punto1), 1, p);
	fclose(p);

	return guardo;
}
