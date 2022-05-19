#pragma once
#include <iostream>
#include "Fecha.h"

using namespace std;

class Persona {
protected:
    int _DNI;
    char _nombre[25], _apellido[25];
    bool _estado;
    Fecha _fecha_nacimiento;
public:
    int getDNI() { return _DNI; }
    const char* getNombre() { return _nombre; }
    const char* getApellido() { return _apellido; }
    int getEstado() { return _estado; };
    Fecha getFechaNac() { return _fecha_nacimiento; }

    void setDNI(int d) { _DNI = d; }
    void setNombre(const char* n) { strcpy_s(_nombre, n); }
    void setApellido(const char* n) { strcpy_s(_apellido, n); }
    void setFechaNacimiento(Fecha f) { _fecha_nacimiento = f; }
    void setEstado(bool estado) { _estado = estado; }

    void cargar();
    void mostrar();
};
