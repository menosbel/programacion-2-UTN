#include <iostream>
#include <cstdlib>
#include "Cola.h"
#include "Pila.h"
using namespace std;

void cola()
{
	Cola obj(5);
	int x;
	cout << "Numero: ";
	cin >> x;
	while (obj.agregar(x))
	{
		cout << "Numero: ";
		cin >> x;
		cout << endl;
	}
	cout << endl;
	int num;
	while (obj.sacar(num))
	{
		cout << num << endl;
	}
	cout << endl;
}

void pila()
{
	Pila obj(5);

}

int main()
{
	cola();
	pila();
	system("pause");
	return 0;
}