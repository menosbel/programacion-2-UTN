#ifndef MATERIA_H
#define MATERIA_H
#include <cstring>


class Materia{
    private:
        int nroMateria;
        char nombreMateria[40];
        int cantAlumnos;
        int cantDocentes;
        bool activo;

    public:
        Materia(int nM=0, const char *nombre="nada", int ca=0, int cd=0){
            nroMateria=nM;
            strcpy(nombreMateria,nombre);
            cantAlumnos=ca;
            cantDocentes=cd;
        }

        void Mostrar();
        void Cargar();

        void setNroMateria(int nm){if(nm >= 0)nroMateria=nm;}
        void setNombreMateria(const char *nm){strcpy(nombreMateria,nm);}
        void setActivo(bool valor){ activo = valor; }
        void setCantidadAlumnos(int c){ cantAlumnos = c;}

        int getNroMateria(){ return nroMateria; }
        char *getNombreMateria(){ return nombreMateria; }

        bool leerDeDisco(int pos);
        bool modificarEnDisco(int pos);
};


#endif // MATERIA_H
