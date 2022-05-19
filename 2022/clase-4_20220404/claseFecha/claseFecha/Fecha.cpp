#include "Fecha.h"
#include <iostream>

Fecha::Fecha(int d, int m, int a)
{
	_dia = d;
	_mes = m;
	_anio = a;
}

void Fecha::mostrar()
{
	std::cout << this << std::endl; // puntero que contiene la direccion de la variable que llama al metodo
	std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}

void Fecha::cargar()
{
	int value;
	std::cout << "Dia: ";
	std::cin >> _dia;
	
	std::cout << "Mes: ";
	std::cin >> value;
	setMes(value);
	
	std::cout << "Anio: ";
	std::cin >> _anio;
}

void Fecha::setMes(int m)
{
	if (m >= 1 && m <= 12) _mes = m;
}
