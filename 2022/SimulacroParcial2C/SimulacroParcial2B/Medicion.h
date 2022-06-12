#pragma once
#include "Fecha.h"

class Medicion
{
private:
	int codCiudad;
	int visibilidad;
	int temperatura;
	Fecha fecha;
public:
	int getCodCiudad() { return codCiudad; };
	int getVisibilidad() { return visibilidad; };
	int getTemperatura() { return temperatura; };
	Fecha getFecha() { return fecha; };
	bool leerDeDisco(int pos);
	bool grabarEnDisco();
};

