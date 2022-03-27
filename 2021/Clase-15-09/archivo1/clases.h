#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        int getAnio(){return anio;}
};

///*
        int DNI;
        char nombre[30];
        char apellido[30];
        Fecha fechaNac;
        int legajo;



///*
class Persona{///clase base
    protected:///mantiene el encapsulamiento, pero permite que las clases derivadas accedan
        int DNI;///de manera directa a las privado de la base
        char nombre[30];
        char apellido[30];
        Fecha fechaNac;///composición:uso de objetos de otra clase como propiedad de otra clase
        bool activo;
    public:
        void Cargar();
        void Mostrar();
        ///sets()
        void setDNI(int d){DNI=d;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setApellido(const char *apellido){strcpy(this->apellido,apellido);}
        void setActivo(bool a){activo=a;}
        ///gets()
        int getDNI(){return DNI;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return this->apellido;}
        Fecha getFechaNac(){return fechaNac;};
        bool getActivo(){return activo;}
};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"DNI: ";
    cin>>this->DNI;
    cout<<"FECHA DE NACIMIENTO"<<endl;
    fechaNac.Cargar();
    activo=true;

}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DNI: ";
    cout<<this->DNI<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNac.Mostrar();
}

class Alumno: public Persona{
private:
    ///
    ///viene todo lo que está en private de la clase base

    ///
    int legajo;
public:
    ///viene todo lo público de la clase base
    void Cargar();
    void Mostrar();

    int getLegajo(){return legajo;}

    void setLegajo(int l){legajo=l;}

    void resetearDNI(){ DNI=0;}

    bool grabarEnDisco(){
        FILE *p;
        p=fopen("alumnos.dat","ab");
        if(p==NULL){
            cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        bool escribio=fwrite(this,sizeof(Alumno), 1, p);///
        fclose(p);
        return escribio;
    }

    bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("alumnos.dat","rb");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        fseek(p,sizeof(Alumno)*pos,0);
        /*
        si pos vale 0

        fseek(p,0,0);

        si pos vale 1

        fseek(p,sizeof(Alumno),0);
        */
        bool leyo=fread(this, sizeof(Alumno), 1, p);
        fclose(p);
        return leyo;

    }

    bool modificarEnDisco(int pos){
        FILE *p;
        p=fopen("alumnos.dat","rb+");///+ agrega al modo lo que le falta
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        fseek(p,sizeof(Alumno)*pos,0);

        bool leyo=fwrite(this, sizeof(Alumno), 1, p);
        fclose(p);
        return leyo;

    }

};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
}

void Alumno::Mostrar(){
    if(activo==true){
        Persona::Mostrar();
        cout<<"LEGAJO: "<<legajo<<endl;
    }
}



#endif // CLASES_H_INCLUDED
