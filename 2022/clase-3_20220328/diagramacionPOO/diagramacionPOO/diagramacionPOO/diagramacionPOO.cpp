#include <iostream>
#include <cstring>
using namespace std;



class Alumno {
private:
    int legajo, edad;
    char nombre[25], apellido[30];

public:
    Alumno(int l = 0, int e = 23, const char* n = "pepe", const char* a = "lolo") {
        legajo = l;
        edad = e;
        strcpy_s(nombre, n);
        strcpy_s(apellido, a);

    };
    Alumno(const char* n , const char* a) {
        strcpy_s(nombre, n);
        strcpy_s(apellido, a);
    };
    void cargar();
    void mostrar();
    void setLegajo(int value) {
        if (value > 0) { legajo = value; };
    };
    void setNombre(const char* value) { strcpy_s(nombre, value); };
    const char* getNombre() { return nombre; };
    ~Alumno() { cout << "Destruccion de " << nombre << endl; }

};

void Alumno::mostrar() {
    cout << "Legajo: " << legajo << endl;
    cout << "Edad: " << edad << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
};

void Alumno::cargar() {
    cout << "Legajo: ";
    cin >> legajo;
    cout << "Edad: ";
    cin >> edad;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;
}

int main()
{
    Alumno alumno(1234, 23, "Ana", "Perez");
    Alumno alumno2(2, 24);
    Alumno alumno3;
    Alumno alumno4("Lola", "Lopez");
    // alumno2.cargar();
    // alumno2.setNombre("pepe");
    cout << endl << endl;
    alumno.mostrar();
    cout << endl << endl;
    alumno2.mostrar();
    cout << endl << endl;
    alumno3.mostrar();
    cout << endl << endl;
    alumno4.mostrar();
    cout << endl << endl;


    return 0;
}
