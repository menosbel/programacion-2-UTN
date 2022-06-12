# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }
};

class Cosecha {
private:
    int numeroCosecha, codigoCereal;
    float cantidadToneladas;
    Fecha fechaCosecha;
    char codigoEmpresa[5];
public:
    float getCantidadToneladas() { return cantidadToneladas; }
    Fecha getFechaCosecha() { return fechaCosecha; }
    int getCodigoCereal() { return codigoCereal; }
    void setCantidadToneladas(float ct) { cantidadToneladas = ct; }
    int leerDeDisco(int pos) {
        int leyo;
        FILE* p;
        p = fopen("cosecha.dat", "rb");
        if (p == NULL) return 0;
        fseek(p, pos * sizeof(Cosecha), 0);
        leyo = fread(this, sizeof(Cosecha), 1, p);
        fclose(p);
        return leyo;
    }
    int modificarEnDisco(int pos) {
        int escribio;
        FILE* p;
        p = fopen("cosecha.dat", "rb+");
        if (p == NULL) return 0;
        fseek(p, pos * sizeof(Cosecha), 0);
        escribio = fwrite(this, sizeof(Cosecha), 1, p);
        fclose(p);
        return escribio;
    }
    bool operator==(const char* cod) {
        if (strcmp(codigoEmpresa, cod) == 0) return true;
        return false;
    }
};

/*a) Generar un archivo con el siguiente formato:
Código de empresa, nombre, y cantidad de toneladas cosechadas.
*/


class ToneladasEmpresa {
private:
    char codigoEmpresa[5];
    char nombreEmpresa[30];
    float cantidadTotal;
public:
    void setCodigoEmpresa(const char* ce) { strcpy(codigoEmpresa, ce); }
    void setNombreEmpresa(const char* ce) { strcpy(nombreEmpresa, ce); }
    void setCantidadTotal(float ct) { cantidadTotal = ct; }
    int grabarEnDisco() {
        FILE* p;
        p = fopen("tonEmpresas.dat", "ab");
        if (p == NULL) return -1;
        int escribio = fwrite(this, sizeof(ToneladasEmpresa), 1, p);
        fclose(p);
        return escribio;
    }
};

class Empresa {


};
///b) El mes con mayor cantidad de toneladas cosechadas de cereal de tipo 10.
int buscarMaximo(float* vCant, int tam) {
    int i, posMax = 0;
    for (i = 1;i < tam;i++) {
        if (vCant[i] > vCant[posMax]) {
            posMax = i;
        }
    }
    return posMax;
}

void ponerCeroVector(float* v, int tam) {
    int i;
    for (i = 0;i < tam;i++) v[i] = 0;
}


void puntoB() {
    Cosecha reg;
    ///float vCant[12]={0};
    float* vCant;
    vCant = new float[12];
    if (vCant == NULL) return;
    ponerCeroVector(vCant, 12);
    int pos = 0;
    while (reg.leerDeDisco(pos++)) {
        if (reg.getCodigoCereal() == 10) {
            vCant[reg.getFechaCosecha().getMes() - 1] += reg.getCantidadToneladas();
        }
    }
    int mesMaximo = buscarMaximo(vCant, 12);
    cout << "EL MES CON MAYOR CANTIDAD DE TONELADAS DEL CEREAL 10 FUE " << mesMaximo + 1 << endl;
    delete vCant;
}

void puntoD() {
    Cosecha reg;
    int pos = 0;
    while (reg.leerDeDisco(pos) == 1) {
        reg.setCantidadToneladas(reg.getCantidadToneladas() * 1000);
        reg.modificarEnDisco(pos);
        pos++;
    }
}
float toneladasPorEmpresa(const char* ce) {
    Cosecha reg;
    int pos = 0;
    float cant = 0;
    while (reg.leerDeDisco(pos++)) {
        if (reg == ce) cant += reg.getCantidadToneladas();
    }
    return cant;
}

void puntoA() {
    Empresa reg;
    ToneladasEmpresa aux;
    int pos = 0;
    float ct;
    while (reg.leerDeDisco(pos++)) {
        ct = toneladasPorEmpresa(reg.getCodigoEmpresa());
        aux.setCodigoEmpresa(reg.getCodigoEmpresa());
        aux.setNombreEmpresa(reg.getNombreEmpresa());
        aux.setCantidadTotal(ct);
        aux.grabarEnDisco();
    }
}

int main() {
    puntoA();
    puntoB();
    puntoD();
    cout << endl;
    system("pause");
    return 0;
}

void puntoADinamico() {
    ToneladasEmpresa* te;
    int cantReg = contarRegistrosEmpresa();///cantidad de registros del archivo de empresas
    te = new ToneladasEmpresa[cantReg];
    if (te == NULL) return;
    copiarCodigoyNombre(te, cantReg);
    sumarToneladas(te, cantReg);
    for (int i = 0;i < cantReg;i++) te[i].grabarEnDisco();
    delete te;
}
