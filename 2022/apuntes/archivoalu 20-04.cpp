///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Mostrar();
        void Cargar();
        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///sets()
        void setDia(int d){dia=d;}
        void setMes(int m){if(m>=1 && m<=12) mes=m;}
        void setAnio(int a){anio=a;}
        ~Fecha(){};
};

void Fecha::Mostrar(){
    ///cout<<this<<endl;
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}

void Fecha::Cargar(){
    int d;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>d;
    setMes(d);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}

class Persona{///clase base
protected:
    int DNI;
    char nombre[25], apellido[25];
    Fecha fechaNacimiento;/// Persona TIENE FECHA DE NACIMIENTO
public:
    ///gets
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    Fecha getFechaNac(){return fechaNacimiento;}

    void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}

    void Cargar();
    void Mostrar();
};


void Persona::Cargar(){
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    fechaNacimiento.Cargar();
}

void Persona::Mostrar(){
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Mostrar();
}

class Alumno:public Persona{    ///Alumno ES Persona
private:
    int legajo;
public:
    void Cargar();
    void Mostrar();
    int getLegajo(){return legajo;}
    void setLegajo(int l){legajo=l;}
    void ponerCeroDNI(){DNI=0;}

    int grabarEnDisco();

};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
}

void Alumno::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO: ";
    cout<<legajo;
}

int grabarRegistro(Alumno reg);
int mostrarRegistros();

int main(){
    Alumno obj;
    int opc;
    while(true){
        system("cls");
        cout<<"--------------MENU ALUMNOS--------------"<<endl;
        cout<<"1. AGREGAR REGISTRO DE ALUMNO AL ARCHIVO"<<endl;
        cout<<"2. LISTAR REGISTROS"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: obj.Cargar();
                    if(obj.grabarEnDisco()!=1){
                            cout<<"ERROR DE ARCHIVO"<<endl;
                            return -1;
                    }
                    else cout<<"REGISTRO AGREGADO"<<endl;
                    break;
            case 2: if(mostrarRegistros()!=1) cout<<"ERROR DE ARCHIVO"<<endl;
                    break;
            case 0: return 0;
                    break;
        }
        system("pause");
    }

	system("pause");
	return 0;
}

int Alumno::grabarEnDisco(){
    FILE *pAlu;
    int escribio;
    pAlu=fopen("alumnos.dat","ab");
    if(pAlu==NULL){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    escribio=fwrite(this,sizeof(Alumno),1,pAlu);
	fclose(pAlu);
	return escribio;
}

int mostrarRegistros(){
    Alumno alu;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat","rb");
    if(pAlu==NULL){
 //       cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&alu,sizeof(Alumno),1,pAlu)==1){
        alu.Mostrar();
        cout<<endl<<endl;
    }
    fclose(pAlu);
    return 1;
}

/*int mostrarRegistros(){
    Alumno alu;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat","rb");
    if(pAlu==NULL){
 //       cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    while(fread(&alu,sizeof alu,1,pAlu)==1){
        alu.Mostrar();
        cout<<endl<<endl;
    }
    fclose(pAlu);
    return 1;
}

*/
