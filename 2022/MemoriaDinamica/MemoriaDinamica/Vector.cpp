#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(int tam, int val)
{
	int i;
	_tam = tam;
	
	p = new int[tam];
	if (p == NULL) { return; };

	for (int i = 0; i < _tam; i++)
	{
		p[i] = val;
	}
}

Vector::Vector(Vector& vec2)
{
	if (this == &vec2) return;

	int i;
	_tam = vec2.getTamanio();
	p = new int[_tam];
	if (p == NULL) return;

	for (int i = 0; i < _tam; i++)
	{
		p[i] = vec2.p[i];
	}
}

Vector::Vector(int* vec, int tam)
{
	_tam = tam;
	p = new int[tam];
	if (p == NULL) return;
	for (int i = 0; i < _tam; i++)
	{
		p[i] = vec[i];
	}
}

bool Vector::mostrar()
{
	for (int i = 0; i < _tam; i++)
	{
		cout << p[i] << endl;
	}
	return true;
}

void Vector::cargar()
{
	for (int i = 0; i < _tam; i++)
	{
		cout << "Ingrese un valor: ";
		cin >> p[i];
	}
}

bool Vector::setValor(int pos, int valor)
{
	if (pos < _tam && pos > -1)
	{
		p[pos] = valor;
		return true;
	}
	return false;
}

bool Vector::getValor(int& val, int pos)
{
	if (pos < _tam && pos > -1)
	{
		val = p[pos];
		return true;
	}
	return false;
}

bool Vector::mostrar(int pos)
{
	if (pos < _tam && pos > -1) 
	{
		cout << p[pos] << endl;
		return true;
	}
	else
	{
		return false;
	}
}

Vector::~Vector()
{
	delete p;
}

bool Vector::operator==(const Vector& obj)
{
	if (_tam != obj._tam) return false;
	
	for (int i = 0; i < _tam; i++)
	{
		if (p[i] != obj.p[i]) return false;
	}
	return true;
}

bool Vector::operator!=(const Vector& obj)
{
	if (_tam != obj._tam) return true;

	for (int i = 0; i < _tam; i++)
	{
		if (p[i] == obj.p[i]) return false;
	}
	return true;
}

bool Vector::operator>(const Vector obj)
{
	if (_tam < obj._tam) return false;
	for (int i = 0; i < obj._tam; i++)
	{
		if (p[i] <= obj.p[i]) return false;
	}
	return true;
}

bool Vector::operator>(int tam)
{
	return _tam > tam;
}
