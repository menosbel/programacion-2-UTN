#include <iostream>
#include <cstdlib>
#include "Fecha.h"
#include "Venta.h"

using namespace std;

int main() {
	Fecha actual(4, 4, 2022);
	Fecha fechaActual;
	fechaActual.cargar();

	Venta venta;
	venta.cargar();
	std::cout << endl;

	venta.mostrar();
	std::cout << endl;
	std::cout << "Le seteo otra fecha." << endl;
	venta.setFechaVenta(fechaActual);
	venta.mostrar();

	return 0;
}