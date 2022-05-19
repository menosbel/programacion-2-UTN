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
    bool estado;
public:
    ///gets
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    Fecha getFechaNac(){return fechaNacimiento;}
    bool getEstado(){return estado;}

    void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setEstado(bool e){estado=e;}

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
    estado=true;
}

void Persona::Mostrar(){
    if(estado==true){
        cout<<"DNI: ";
        cout<<DNI<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"FECHA DE NACIMIENTO: "<<endl;
        fechaNacimiento.Mostrar();
    }
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
    int leerDeDisco(int pos);
    int modificarEnDisco(int pos);


};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
}

void Alumno::Mostrar(){
    if(estado==true){
        Persona::Mostrar();
        cout<<"LEGAJO: ";
        cout<<legajo;
    }
}
///PROTOTIPOS FUNCIONES GLOBALES
int grabarRegistro(Alumno reg);
int mostrarRegistros();
int borrarRegistro();
int buscarLegajoAlumno(int legajo);
///


int main(){
    Alumno obj;
    int opc;
    while(true){
        system("cls");
        cout<<"--------------MENU ALUMNOS--------------"<<endl;
        cout<<"1. AGREGAR REGISTRO DE ALUMNO AL ARCHIVO"<<endl;
        cout<<"2. LISTAR REGISTROS"<<endl;
        cout<<"3. BORRAR REGISTRO"<<endl;
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
            case 3: if(borrarRegistro()!=1) cout<<"ERROR DE ARCHIVO"<<endl;
                    else cout<<"REGISTRO ELIMINADO"<<endl;
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
    int pos=0;
    while(alu.leerDeDisco(pos)==1){
        alu.Mostrar();
        cout<<endl<<endl;
        pos++;
    }
    return 1;
}
/*
int mostrarRegistros(){
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

int Alumno::leerDeDisco(int pos){
    FILE *p;
    int leyo;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(Alumno),0);
    leyo=fread(this,sizeof(Alumno),1,p);

    fclose(p);
    return leyo;
}


int borrarRegistro(){
    Alumno alu;
    int pos=0, escribio;
    int legajo;
    cout<<"INGRESE EL LEGAJO DEL ALUMNO A BORRAR: ";
    cin>>legajo;
    pos=buscarLegajoAlumno(legajo);
    if(pos>=0){
        alu.leerDeDisco(pos);
        alu.setEstado(false);
        escribio=alu.modificarEnDisco(pos);
    }
    else{
        cout<<"NO EXISTE EL LEGAJO"<<endl;
        return -2;
    }
    return escribio;
}

int buscarLegajoAlumno(int legajo){
    Alumno alu;
    int pos=0;
    while(alu.leerDeDisco(pos)==1){
        if(alu.getLegajo()==legajo)return pos;
        pos++;
    }
    return -1;
}

int Alumno::modificarEnDisco(int pos){
    FILE *pAlu;
    int escribio;
    pAlu=fopen("alumnos.dat","rb+");
    if(pAlu==NULL){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pAlu, pos*sizeof(Alumno),0);
    escribio=fwrite(this,sizeof(Alumno),1,pAlu);
	fclose(pAlu);
	return escribio;
}
