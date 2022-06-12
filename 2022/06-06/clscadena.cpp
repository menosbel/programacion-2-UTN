///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;
///sobrecargar el operador > de la siguiente manera:
///1 que reciba un objeto (o referencia) del mismo tipo y devuelve verdadero si el objeto que llama es mayor que el parámetro (lexicográfico)
///1 que reciba un vector de char y devuelve verdadero si el objeto que llama es mayor que el parámetro (lexicográfico)
/// que reciba un valor entero y devuelve verdadero o falso de acuerdo a la relación entre el valor recibido
/// y el tamaño del objeto cadena (tam)

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *palabra="nada"){
        tam=strlen(palabra)+1;
        p=new char[tam];
        if(p==NULL)return;
        strcpy(p,palabra);
        p[tam-1]='\0';
    }
    void Mostrar(){
        cout<<p<<endl;
    }
    ~Cadena(){
        delete p;
    }
    int getTamanio(){return tam;}
    void setP(const char *texto){
        delete p;
        tam=strlen(texto)+1;
        p=new char[tam];
        if(p==NULL)return;
        strcpy(p,texto);
        p[tam-1]='\0';
    }
    bool operator==(const Cadena &cad){
        if(strcmp(p,cad.p)==0)return true;
        return false;
    }
    bool operator==(const char *cad){
        if(strcmp(p,cad)==0)return true;
        return false;
    }
    bool operator==(int cantidadCaracteres ){
        if((tam-1)==cantidadCaracteres)return true;
        return false;
    }
    void operator=(const char *cad){
        delete p;
        tam=strlen(cad)+1;
        p=new char[tam];
        if(p==NULL)return;
        strcpy(p,cad);
        p[tam-1]='\0';
    }
    bool buscarCaracter(char letra){
        for(int i=0;i<tam;i++){
            if(p[i]==letra)return true;
        }
        return false;
    }
    int contarCaracter(char letra){
        int cont=0;
        for(int i=0;i<tam;i++){
            if(p[i]==letra)cont++;
        }
        return cont;
    }
    bool agregarCaracter(char letra){}///agregar el caracter al final de la cadena existente
    void todoMayuscula(){}
};

///SOBRECARGA DE OPERADORES: DARLE A LOS OPERADORES DEL LENGUAJE NUEVA FUNCIONALIDAD

int main(){
    Cadena obj("hola a todos los que participan del curso!"), aux;
    obj="hola";
    aux="hola";

    if(obj==4){
        cout<<"SON IGUALES LA CANTIDAD DE CARACTERES";
    }
    else{
        cout<<"SON DISTINTOS";
    }
    if(obj=="hola"){
        cout<<"SON IGUALES LOS TEXTOS";
    }
    else{
        cout<<"SON DISTINTOS";
    }

	cout<<endl;
	system("pause");

	return 0;
}
