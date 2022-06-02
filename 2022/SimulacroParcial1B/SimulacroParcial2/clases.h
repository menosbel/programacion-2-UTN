#pragma once

class Fecha {
private:
    int dia, mes, anio;
public:
    //gets() y sets();
    void Cargar();
    void Mostrar();
};

class Socio {
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[40];
    char telefono[20];
    int tipo, localidad;
    bool estado;
public:
    //gets() y sets()
    void Cargar();
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();
};

class Club {
private:
    int numero;
    int disciplina, anio, localidad;
    char nombre[45];
    int dniPresidente;
    bool estado;
public:
    //gets() y sets()
    void Cargar();
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();
};

class Inscripcion {
private:
    int dniSocio;
    int numeroClub;
    int tipoInscripcion;
    Fecha fecha_inscripcion;
    bool estado;
public:
    //gets() y sets()
    bool leerDeDisco(int);
    bool grabarEnDisco();
};
