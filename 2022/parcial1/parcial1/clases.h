#pragma once

class Fecha {
private:
    int dia, mes, anio;
public:
    //gets() y sets()
    void Cargar();
    void Mostrar();
};

class Equipo {
private:
    int codigoEquipo;
    char nombreEquipo[30];
    int provincia;
    char directorTecnico[30];
    char division;
    bool estado;
public:
    //gets() y sets()
    int getCodigoEquipo() { return codigoEquipo; };
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void Cargar();
    void Mostrar();
};

class Jugador {
private:
    int codigoJugador;
    int edad, numeroCamiseta, codigoEquipo;
    char nombre[30];
    bool estado;
public:
    //gets() y sets()
    Jugador();
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void Cargar();
    void Mostrar();
};

class Partido {
private:
    int codigoPartido;
    int codigoSede;
    int codigoEquipo1, codigoEquipo2;;
    Fecha fechaPartido;
    bool estado;
public:
    //gets() y sets()
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void Cargar();
    void Mostrar();
};
