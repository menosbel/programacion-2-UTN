#pragma once
#include <iostream>
#include <cstdlib>

class Pila
{
private:
	int* p;
	int tam, tope;
public:
	Pila(int t)
	{
		tam = t;
		p = new int[tam];
		if (p == NULL) exit(1);
		tope = 0;
	}

	bool agregar(int valor)
	{
		if (tam == tope) return false;
		p[tope] = valor;
		tope++;
		return true;
	}

	bool sacar(int& valor)
	{
		if (tope == 0) return false;
		tope--;
		valor = p[tope];
		return true;
	}

	~Pila() { delete p; }
};

