#include <iostream>
#include "clases.h"

Jugador::Jugador() {
    codigoJugador = 0;
    edad = 0;
    numeroCamiseta = 0;
    codigoEquipo = 0;
    strcpy_s(nombre, "");
    estado = false;
}