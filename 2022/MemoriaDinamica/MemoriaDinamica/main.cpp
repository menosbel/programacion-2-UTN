#include <iostream>
#include <cstdlib>
#include "Vector.h"

using namespace std;

void cargarVector(int* vDin, int cant)
{
	for (int i = 0; i < cant; i++)
	{
		vDin[i] = i + 1;
	}
}

void mostrarVector(int* vDin, int cant)
{
	for (int i = 0; i < cant; i++)
	{
		cout << vDin[i] << endl;
	}
}

int primeraparte()
{
	int* vDin;
	int cantPosiciones;
	cout << "Ingrese la cantidad de componentes del vector a construir: ";
	cin >> cantPosiciones;

	if (cantPosiciones < 1) return -1;

	vDin = new int[cantPosiciones];
	if (vDin == NULL) return -1;

	cargarVector(vDin, cantPosiciones);
	mostrarVector(vDin, cantPosiciones);

	delete vDin;

	cout << endl << endl;
}

void segundaparte()
{
	Vector obj(6, 6);
	Vector obj2(obj);

	obj.mostrar();
	cout << endl;
	int val;
	obj.setValor(5, 8);
	obj.getValor(val, 5);
	obj.mostrar();

	cout << endl;
	cout << val << endl;

	cout << endl << endl;
	int vec[8] = { 1, 2, 3, 4, 5 };
	Vector obj3(*vec, 8);
	obj3.mostrar();
}

int main()
{
	// primeraparte();
	// segundaparte();

	Vector obj(20, 5), otro(2);
	if (obj == otro) 
	{
		cout << "Iguales";
	}
	else
	{
		cout << "Distintos";
	}

	cout << endl << endl;

	system("pause");
	return 0;
}