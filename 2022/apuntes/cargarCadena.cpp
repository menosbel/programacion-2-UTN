#include <iostream>
#include <cstring>
#include <cstdio> ///Para usar la funci�n cargarCadena necesitamos incluir esta librer�a.

///Ac� tienen la funci�n cargarCadena, que recibe como parametros un vector de char y el tama�o del mismo y pide el ingreso
///del texto que queramos almacenar en dicho vector. Esta funci�n acepta espacios. Requiere incluir la librer�a cstdio.

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
