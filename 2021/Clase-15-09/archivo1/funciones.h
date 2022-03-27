#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS

void cargarAlumnos();
void mostrarAlumnos();
bool grabarEnDisco(Alumno);
void copiarBuenos();
bool bajaLogica();
int buscarAlumno(int legajo);
bool modificarApellido();
///

///DESARROLLO DE FUNCIONES
bool modificarApellido(){
    int legajo, pos;
    Alumno obj;
    bool modifico;
    cout<<"INGRESAR EL LEGAJO DEL ALUMNO A MODIFICAR: ";
    cin>>legajo;
    pos=buscarAlumno(legajo);
    ///me devuelve un número entero que representa la posición de ese registro en el archivo
    ///si no encuentra el legajo devuelve -1
    if(pos==-1){
        cout<<"NO HAY ALUMNO CON ESE LEGAJO"<<endl;
        return false;
    }
    obj.leerDeDisco(pos);
    obj.Mostrar();
    cout<<endl;
    char apellido[30];
    cout<<"INGRESE EL VALOR NUEVO PARA EL APELLIDO: ";
    cin>>apellido;
    obj.setApellido(apellido);
    modifico=obj.modificarEnDisco(pos);
    return modifico;
}




int buscarAlumno(int legajo){
    Alumno aux;
    int pos=0;
    while(aux.leerDeDisco(pos)==true){
        if(aux.getLegajo()==legajo)
            return pos;
        pos++;
    }
    return -1;
}

bool bajaLogica(){
    int legajo, pos;
    Alumno obj;
    bool modifico;
    cout<<"INGRESAR EL LEGAJO DEL ALUMNO A BORRAR: ";
    cin>>legajo;
    pos=buscarAlumno(legajo);
    ///me devuelve un número entero que representa la posición de ese registro en el archivo
    ///si no encuentra el legajo devuelve -1
    if(pos==-1){
        cout<<"NO HAY ALUMNO CON ESE LEGAJO"<<endl;
        return false;
    }
    obj.leerDeDisco(pos);
    obj.setActivo(false);
    modifico=obj.modificarEnDisco(pos);
    return modifico;
}



void copiarBuenos(){
    FILE *p;
    p=fopen("alumnos.bak", "wb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pAlu;
    Alumno reg;
    pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==NULL){
        fclose(p);
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    for(int i=0;i<5;i++){
        fread(&reg, sizeof reg, 1, pAlu);
        fwrite(&reg, sizeof reg, 1, p);
    }

    fclose(pAlu);
    fclose(p);

    pAlu=fopen("alumnos.dat", "wb");

    if(pAlu==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    p=fopen("alumnos.bak", "rb");
    if(p==NULL){
        fclose(pAlu);
        cout<<"ERROR DE ARCHIVO";
        return;
    }
    for(int i=0;i<5;i++){
        fread(&reg, sizeof reg, 1, p);
        fwrite(&reg, sizeof reg, 1, pAlu);
    }
    fclose(pAlu);
    fclose(p);

}
void cargarAlumnos(){
    Alumno reg;
    reg.Cargar();
    if(reg.grabarEnDisco()==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
    system("pause");
}

void mostrarAlumnos(){
    Alumno reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        reg.Mostrar();
        cout<<endl;
        pos++;
    }

}

void mostrarAlumnosPorAnio(){
    Alumno reg;
    int pos=0, anio;
    cout<<"INGRESAR ANIO: ";
    cin>>anio;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getFechaNac().getAnio()>anio){
            reg.Mostrar();
            cout<<endl;
        }
        pos++;
    }

}

bool grabarEnDisco(Alumno reg){
    FILE *p;///tipo de dato creado para el manejo de archivos
            ///mediante los punteros FILE se puede vincular el archivo físico con el programa que usa el archivo

    p=fopen("alumnos.dat","ab");///la única referencia al archivo físico se hace en la apertura.
    if(p==NULL){///NULL es una constante definida. Se puede usar para cualquier puntero.
        cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    fwrite(&reg, sizeof reg, 1, p);
    //fwrite(&reg, sizeof(Alumno), 1, p);
    fclose(p);
    return true;
}




#endif // FUNCIONES_H_INCLUDED
