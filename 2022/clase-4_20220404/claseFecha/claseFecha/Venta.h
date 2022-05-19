#pragma once
#include "Fecha.h"

class Venta
{
private:
	int numero, codigo, cantidad;
	float importe;
	Fecha fecha;
public:
	void cargar();
	void mostrar();
	void setFechaVenta(Fecha fechaActual);
};

