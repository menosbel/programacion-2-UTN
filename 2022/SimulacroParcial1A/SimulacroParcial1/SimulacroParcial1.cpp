#include <iostream>
#include "clases.h"

using namespace std;

class JefeDeArea {
private:
    int _DNI;
    char _nombre[30];
    char _apellido[30];
public:
    void cargar();
    void mostrar();
    void setDNI(int d) { _DNI = d; }
    void setNombre(const char* n) { strcpy_s(_nombre, n); }
    void setApellido(const char* n) { strcpy_s(_apellido, n); }
    int grabar_en_disco() {
        FILE* p;
        errno_t err;
        err = fopen_s(&p, "jefesDeArea.dat", "ab");
        if (err != 0) { return -1; }
        int escribio = fwrite(this, sizeof(JefeDeArea), 1, p);
        fclose(p);
        return escribio;
    };
};

//PROTOTIPOS

void puntoA();
void puntoB();
bool firmo2020(int dni);
int mostrarPuntoB(int* v, int tam);

int main()
{
    puntoA();
    puntoB();

    return 0;
};


//Jefes de Área que hayan firmado contrato en el 2020
void puntoA() {
    int pos = 0;

    JefeDeArea jefe;
    Empleado empleado;

    while (empleado.leerDeDisco(pos++))
    {
        if (empleado.getCargo() == 3)
        {
            if (firmo2020(empleado.getDNI())) 
            {
                jefe.setDNI(empleado.getDni());
                jefe.setApellido(empleado.getApellido());
                jefe.setNombre(empleado.getNombre());
                jefe.grabar_en_disco();
            }
        }
    }
};

bool firmo2020(int dni)
{
    int pos = 0;
    Contrato contrato;

    while (contrato.leerDeDisco(pos++))
    {
        if (contrato.getDNI() == dni && contrato.getFechaContrato().getAnio() == 2020)
        {
            return true;
        }
        else {
            return false;
        }
    }

}

// Listar el mes con más contratos temporarios del año 2015.
void puntoB() 
{
    int pos = 0, maxMes = 0;
    Contrato contrato;

    int temporarios2015[12] = {0};

    while (contrato.leerDeDisco(pos++))
    {
        if (contrato.getTipoContrato() == 1 && contrato.getFechaContrato().getAnio() == 2015)
        {
            temporarios2015[contrato.getFechaContrato().getMes() - 1]++;
        }
    }
    maxMes = mostrarPuntoB(temporarios2015, 12);
    cout << "El mes con mas contratos temporarios en 2015 fue " << maxMes + 1 << endl;
}

int mostrarPuntoB(int* v, int tam)
{
    int posMax = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] > v[posMax]) {
            posMax = i;
        }

    }
    return posMax;
}