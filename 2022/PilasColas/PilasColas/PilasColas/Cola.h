#pragma once
#include <iostream>
#include <cstdlib>
class Cola
{
private:
	int* p;
	int tam, ppio, fin;
public:
	Cola(int t)
	{
		tam = t;
		p = new int[tam];
		if (p == NULL) exit(1);
		ppio = fin = 0;
	}

	bool agregar(int valor)
	{
		if (tam == fin) return false;
		p[fin] = valor;
		fin++;
		return true;
	}

	bool sacar(int& valor)
	{
		if (ppio == fin) return false;
		valor = p[ppio];
		ppio++;
		return true;
	}

	~Cola() { delete p; }
};
