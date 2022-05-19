///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;


/*
a) Calcular e informar la cantidad de empresas de cada municipio.
b) Informar los nombres de las empresas con más de 200 empleados.
c) Calcular e informar la categoría de empresa con más empleados
*/

class Empresa{
private:
        int numeroEmpresa;
        char nombreEmpresa[30];
        int cantidadEmpleados, categoria, numeroMunicipio;
        bool estado;
    public:
        ///sets()
        ///gets()
        int getNumeroMunicipio(){return numeroMunicipio;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        const char *getNombreEmpresa(){return nombreEmpresa;}
        int getNumeroCategoria(){return categoria;}

        void Cargar();
        void Mostrar();
        int grabarEnDisco();
        int leerDeDisco(int);

};

///FUNCIONES DE LA CLASE

void Empresa::Cargar(){
    cout<<"NUMERO DE EMPRESA: ";
    cin>>numeroEmpresa;
    cout<<"NOMBRE DE EMPRESA: ";
    cin>>nombreEmpresa;
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cin>>cantidadEmpleados;
    cout<<"CATEGORIA: ";
    cin>>categoria;
    cout<<"NUMERO DE MUNICIPIO: ";
    cin>>numeroMunicipio;
    estado=true;

}

void Empresa::Mostrar(){
    cout<<"NUMERO DE EMPRESA: ";
    cout<<numeroEmpresa<<endl;
    cout<<"NOMBRE DE EMPRESA: ";
    cout<<nombreEmpresa<<endl;
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cout<<cantidadEmpleados<<endl;
    cout<<"CATEGORIA: ";
    cout<<categoria<<endl;
    cout<<"NUMERO DE MUNICIPIO: ";
    cout<<numeroMunicipio<<endl<<endl;
}


int Empresa::grabarEnDisco(){
    FILE *p;
    p=fopen("empresas.dat", "ab");
    if(p==NULL) return -1;
    int escribio=fwrite(this,sizeof(Empresa),1,p);
    fclose(p);
    return escribio;
}
int Empresa::leerDeDisco(int pos){
    FILE *p;
    p=fopen("empresas.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,sizeof(Empresa)*pos,0);
    int leyo=fread(this,sizeof(Empresa),1,p);
    fclose(p);
    return leyo;

}
///FIN FUNCIONES DE LA CLASE

///FUNCIONES GLOBALES PROTOTIPOS
void agregarRegistros();
void mostrarRegistros();
void puntoA();
    void mostrarPuntoA(int *v, int tam);
void puntoB();
void puntoC();
    int maximoVector(int *v, int tam);
///

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"-------MENU PRINCIPAL -------"<<endl;
        cout<<"1.   PUNTO A"<<endl;
        cout<<"2.   PUNTO B"<<endl;
        cout<<"3.   PUNTO C "<<endl;
        cout<<"4.   GENERAR ARCHIVO "<<endl;
        cout<<"5.   MOSTRAR ARCHIVO "<<endl;
        cout<<"0.   SALIR"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: puntoA();
                    break;
            case 2: puntoB();
                    break;
            case 3: puntoC();
                    break;
            case 4: agregarRegistros();
                    break;
            case 5: mostrarRegistros();
                    break;
            case 0: return 0;
                    break;


        }
        system("pause");

    }

	cout<<endl;
	system("pause");
	return 0;
}

///FUNCIONES GLOBALES
void agregarRegistros(){
    Empresa reg;
    reg.Cargar();
    reg.grabarEnDisco();
}

void mostrarRegistros(){
    int pos=0;
    Empresa reg;
    while(reg.leerDeDisco(pos)){
        reg.Mostrar();
        pos++;
    }
}

void puntoA(){
    int vMuni[135]={0}, pos=0;
    Empresa reg;
    while(reg.leerDeDisco(pos)==1){
        vMuni[reg.getNumeroMunicipio()-1]++;
        pos++;
    }
    mostrarPuntoA(vMuni, 135);
}



void mostrarPuntoA(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]>0){
            cout<<"MUNICIPIO: "<<i+1<<"\t"<<"CANTIDAD DE EMPRESAS: "<<v[i]<<endl;
        }
    }
}

void puntoB(){
    int pos=0;
    Empresa reg;
    cout<<"EMPRESAS CON MAS DE 200 EMPLEADOS"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getCantidadEmpleados()>200){
            cout<<reg.getNombreEmpresa()<<endl;
        }
        pos++;
    }

}
void puntoC(){
    int vCat[80]={0}, pos=0, maxCat;
    Empresa reg;
    while(reg.leerDeDisco(pos)==1){
        vCat[reg.getNumeroCategoria()-1]+=reg.getCantidadEmpleados();
        pos++;
    }
    maxCat=maximoVector(vCat,80);
    cout<<"LA CATEGORIA CON MAS EMPLEADOS ES: "<<maxCat+1<<endl;
}

int maximoVector(int *v, int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]){
            posMax=i;
        }
    }
    return posMax;
}

