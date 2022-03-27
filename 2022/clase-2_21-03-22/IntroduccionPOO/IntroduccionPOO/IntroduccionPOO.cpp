#include <iostream>
using namespace std;

struct alumno
{
    int legajo, edad, ingreso;
    char apellido[30];
};

void mostrarAlumno(struct alumno reg)
{
    cout << reg.legajo << endl;
    cout << reg.edad << endl;
    cout << reg.ingreso << endl;
    cout << reg.apellido << endl;
}

class Student
{
    private:
        int code, age, startDate;
        char lastName[30];
    public:
        void loadStudent()
        {
            cout << "Legajo: ";
            cin >> code;
            cout << "Edad: ";
            cin >> age;
            cout << "Ingreso: ";
            cin >> startDate;
            cout << "Apellido: ";
            cin >> lastName;
            cout << endl << endl;

        }

        void showStudent()
        {
            cout << code << endl;
            cout << age << endl;
            cout << startDate << endl;
            cout << lastName << endl;
        }

};


int main()
{
    struct alumno reg;
    Student rec, &x = rec; // referencia es un alias de una variable
    
    rec.loadStudent();
    rec.showStudent();

    return 0;
}
