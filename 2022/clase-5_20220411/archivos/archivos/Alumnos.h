#pragma once
#include "Alumno.h"

class Alumnos
{
public:
	void grabar_registro(Alumno aux);
	void leer_registros();
	void leer_registros_v2();
	void borrar_registro();
	int buscar_legajo_alumno(int legajo);
	void modificar_fecha_nacimiento();
	void recuperar_registros();
};

