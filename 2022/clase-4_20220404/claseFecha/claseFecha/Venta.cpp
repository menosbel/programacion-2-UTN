#include "Venta.h"
#include <iostream>

void Venta::cargar()
{
	std::cout << "Numero: ";
	std::cin >> numero;
	std::cout << "Codigo: ";
	std::cin >> codigo;
	std::cout << "Cantidad: ";
	std::cin >> cantidad;
	std::cout << "Importe: ";
	std::cin >> importe;
	fecha.cargar();
}

void Venta::mostrar()
{
	std::cout << "Numero: " << numero << std::endl;
	std::cout << "Codigo: " << codigo << std::endl;
	std::cout << "Cantidad: " << cantidad << std::endl;
	std::cout << "Importe: " << importe << std::endl;
	fecha.mostrar();
}

void Venta::setFechaVenta(Fecha fechaActual)
{
	fecha = fechaActual;
}
