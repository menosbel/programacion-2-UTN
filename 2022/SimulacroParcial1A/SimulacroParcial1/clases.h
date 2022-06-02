#pragma once

class Fecha {
private:
    int dia, mes, anio;
public:
    gets() y sets()
        void Cargar();
    void Mostrar();
};



class Empleado {
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[40];
    char telefono[20];
    int cargo, localidad;
    bool estado;
public:
    //gets() y sets()
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void Cargar();
    void Mostrar();
};

class Museo {
private:
    int numero;
    int especialidad, anio;
    char nombre[45];
    int dniDirector;
    bool estado;
public:
    //gets() y sets()
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void Cargar();
    void Mostrar();
};

class Contrato {
private:
    int dniEmpleado;
    int numeroMuseo;
    int tipoContrato;
    Fecha fecha_contrato;
    bool estado;
public:
    //gets() y sets()
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void Cargar();
    void Mostrar();
};

