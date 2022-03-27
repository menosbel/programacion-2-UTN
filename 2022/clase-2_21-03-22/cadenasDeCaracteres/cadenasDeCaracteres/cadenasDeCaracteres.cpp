#include <iostream>
#include <string.h>

using namespace std;

void mostrarCadena(const char* cad)
{
	int i = 0;
	while (cad[i] != '\0')
	{
		cout << cad[i];
		i++;
	}
	cout << endl;
}

int main()
{
	char palabra[20], cadena[20];
	
	cin.getline(palabra, 19);
	cin.getline(cadena, 19);
	
	// MOSTRAR cadena
	cout << "Palabra: " << palabra << endl;
	cout << "Cadena: ";
	mostrarCadena(cadena);

	cout << endl << endl << "COMPARAR" << endl;

	// Opcion #1 COMPARAR
	if (*palabra == *cadena) cout << "Son iguales" << endl;
	else cout << "No son iguales" << endl;

	// Opcion #2 COMPARAR
	//	0 -> si son iguales
	// 1 -> la primera esta mas lejos en el diccionario
	// -1 -> la segunda esta mas lejos en el diccionario
	
	int valorDevuelto = strcmp(palabra, cadena);
	cout << valorDevuelto << endl ;

	cout << endl << endl << "COPIAR" << endl;

	// COPIAR cadenas
	strcpy_s(cadena, palabra);
	cout << "Cadena = " << cadena << endl;

	cout << endl;

	return 0;
}
