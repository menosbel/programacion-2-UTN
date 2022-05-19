#include <iostream>
using namespace std;

void cargarMatriz(int (*m)[3], int fila, int col) {
	int i, j;
	for (i = 0; i < fila; i++) {
		for (j = 0; j < col; j++) {
			// *(*(m + i) + j) = i + 1;
			m[i][j] = i + 1;
		}
	}
}

void mostrarMatriz(int (*m)[3], int fila, int col) {
	int i, j;
	for (i = 0; i < fila; i++) {
		cout << endl;
		for (j = 0; j < col; j++) {
			cout << *(*(m + i) + j) << "\t";
		}
	}
}

void mostrarMatriz(int* m, int fila, int columna) {
	int i, j;
	for (i = 0; i < fila * columna; i++)
	{
		cout << m[i] << "\t";
	}
}

int main()
{
	int mat[3][3];
	const int filas = 3;
	const int columnas = 3;
	int mat2[filas][columnas] = { 0 };

	cargarMatriz(mat, 3, 3);
	mostrarMatriz(mat, 3, 3);
	
	cout << endl << endl;

	mostrarMatriz(*mat2, filas, columnas);

	system("pause");
	return 0;
}
