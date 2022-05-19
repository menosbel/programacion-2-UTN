#include <iostream>
#include <cstring>
#include <cstdio> ///Para usar la función cargarCadena necesitamos incluir esta librería.

///Acá tienen la función cargarCadena, que recibe como parametros un vector de char y el tamaño del mismo y pide el ingreso
///del texto que queramos almacenar en dicho vector. Esta función acepta espacios. Requiere incluir la librería cstdio.

using namespace std;

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

int main(){
    char cadena[20];
    cargarCadena(cadena, 19);
    cout<<cadena<<endl;
    return 0;
}
