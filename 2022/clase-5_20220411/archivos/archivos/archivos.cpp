#include <iostream>
#include "Alumno.h"
#include "Alumnos.h"

using namespace std;

int main()
{
	Alumno alumno;
	Alumnos alumnos;
	int opcion;

	while (true) {
		cout << "---- MENU ALUMNOS ----" << endl;
		cout << "1. Agregar registro" << endl;
		cout << "2. Mostrar registros" << endl;
		cout << "3. Mostrar registros v2" << endl;
		cout << "4. Borrar registro" << endl;
		cout << "5. Modificar fecha nacimiento" << endl;
		cout << "6. Recuperar registros" << endl;
		cout << "0. Fin del programa" << endl;
		cout << "Opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			alumno.cargar();
			if (alumno.grabar_en_disco()) cout << "Regsitro guardado con exito" << endl;
			else cout << "Error de archivo" << endl;
			break;
		case 2:
			alumnos.leer_registros();
			break;
		case 3:
			//alumno.leer_de_disco(1);
			//alumno.mostrar();
			alumnos.leer_registros_v2();
			break;
		case 4:
			alumnos.borrar_registro();
			break;
		case 5:
			alumnos.modificar_fecha_nacimiento();
			break;
		case 6:
			alumnos.recuperar_registros();
			break;
		case 0:
			return false;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;

}
