#include <iostream>
#include <cstdlib>

using namespace std;

void mostrarVector(float* v, int tam)
{
	int i;
	for (int i = 0; i < tam; i++)
	{
		cout << v[i] << endl;
	};
}

void ponerCero(float *v, int cant)
{
	int i;
	for (int i = 0; i < cant; i++)
	{
		v[i] = 0;
	}
}

int main() 
{
	float *articulos;
	int articulo, cantArticulos;
	cout << "Ingrese la cantidad de codigos de articulos: ";
	cin >> cantArticulos;
	articulos = new float[cantArticulos];
	if (articulos == NULL) {
		cout << "No se pudo asignar la memoria" << endl;
		return -1;
	}
	ponerCero(articulos, cantArticulos);
	float importe;
	cout << "Articulo: ";
	cin >> articulo;
	while (articulo != 0)
	{
		cout << "Importe: ";
		cin >> importe;
		articulos[articulo - 1] += importe;
		cout << "Articulo: ";
		cin >> articulo;
	}

	mostrarVector(articulos, cantArticulos);
	cout << endl;
	delete articulos;
	system("pause");
	return 0;
}