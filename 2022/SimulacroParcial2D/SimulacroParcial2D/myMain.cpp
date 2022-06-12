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
    char* getCodigoEmpresa() { return codigoEmpresa; }
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

class Empresa
{
private:
    char codigo[5];
    char nombre[30];
    char direccion[30];
    int tipo;
public:
    char* getNombre() { return nombre; };
    char* getCodigo() { return codigo; };
    int leerDeDisco(int pos) {
        int leyo;
        FILE* p;
        p = fopen("empresas.dat", "rb");
        if (p == NULL) return 0;
        fseek(p, pos * sizeof(Empresa), 0);
        leyo = fread(this, sizeof(Empresa), 1, p);
        fclose(p);
        return leyo;
    }
};

class AuxPuntoA
{
private:
    char codigoEmpresa[5];
    char nombreEmpresa[30];
    float cantToneladas;
public:
    AuxPuntoA() {
        cantToneladas = 0;
    }
    void setCodigoEmpresa(const char* valor) { strcpy_s(codigoEmpresa, valor); };
    void setNombreEmpresa(const char* valor) { strcpy_s(nombreEmpresa, valor); };
    void setCantToneladas(float valor) { cantToneladas = valor; };
    char* getCodigoEmpresa() { return codigoEmpresa; };
    float getCantToneladas() { return (float)cantToneladas; }
    bool grabarEnDisco()
    {
        FILE* p;
        errno_t err;
        const char* file = "puntoA.dat";
        err = fopen_s(&p, file, "ab");
        if (err != 0) { return -1; }
        int escribio = fwrite(this, sizeof(AuxPuntoA), 1, p);
        fclose(p);
        return escribio;
    }
    void operator+=(float valor)
    {
        cantToneladas += valor;
    }
};

// a) Generar un archivo con el siguiente formato: Código de empresa, nombre, y cantidad de toneladas cosechadas.
int cantRegEmpresas()
{
    FILE* p;
    errno_t err;
    err = fopen_s(&p, "empresas.dat", "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Empresa);
    return cant_reg;
}

void copiarCodigoYNombre(AuxPuntoA* v, int cant)
{
    Empresa empresa;
    for (int i = 0; i < cant; i++)
    {
        empresa.leerDeDisco(i);
        v[i].setCodigoEmpresa(empresa.getCodigo());
        v[i].setNombreEmpresa(empresa.getNombre());
    }
}

int buscarEmpresaEnAux(AuxPuntoA* v, int cant, char* ce)
{
    for (int i = 0; i < cant; i++)
    {
        if (v[i].getCodigoEmpresa() == ce) return i;
    }
}

void sumarCantToneladas(AuxPuntoA* v, int cant)
{
    Cosecha cosecha;
    int pos = 0;

    while (cosecha.leerDeDisco(pos++))
    {
        int posEnAux = buscarEmpresaEnAux(v, cant, cosecha.getCodigoEmpresa());
        //int toneladas = v[posEnAux].getCantToneladas();
        //v[posEnAux].setCantToneladas(toneladas += cosecha.getCantidadToneladas());
        v[posEnAux] += cosecha.getCantidadToneladas();
    }
}

void puntoA()
{
    Empresa empresa;
    int cantEmpresas = cantRegEmpresas();

    AuxPuntoA* vDinamico;
    vDinamico = new AuxPuntoA[12];
    if (vDinamico == NULL) return;

    copiarCodigoYNombre(vDinamico, cantEmpresas);
    sumarCantToneladas(vDinamico, cantEmpresas);

    for (int i = 0; i < cantEmpresas; i++)
    {
        vDinamico[i].grabarEnDisco();
    }

    delete[] vDinamico;
    
}

// b) El mes con mayor cantidad de toneladas cosechadas de cereal de tipo 10.
void ponerVectorEnCero(float* v, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        v[i] = 0;
    }
}

int buscarMesConMasToneladas(float* v)
{
    int mayor = 0;
    for (int i = 1; i < 12; i++)
    {
        if (v[i] > v[mayor])
        {
            mayor = i;
        }
    }
    return mayor;
}

void puntoB()
{
    Cosecha cosecha;
    // floar vCantToneladas[12] = {0};
    float* vCantToneladas;
    vCantToneladas = new float[12];
    if (vCantToneladas == NULL) return;

    ponerVectorEnCero(vCantToneladas, 12);

    int pos = 0;
    while (cosecha.leerDeDisco(pos++))
    {
        if (cosecha.getCodigoCereal() == 10)
        {
            vCantToneladas[cosecha.getFechaCosecha().getMes() - 1] += cosecha.getCantidadToneladas();
        }
    }

    int mes = buscarMesConMasToneladas(vCantToneladas);
    cout << "Mes con mayor cantidad de toneladas: " << mes << endl;

    delete[] vCantToneladas;
}


// d) Modificar el archivo cosecha.dat, pasando el valor actual del campo cantidad de toneladas a su equivalente en kilos.
void puntoD()
{
    Cosecha cosecha;

    int pos = 0;
    float toneladas;
    while (cosecha.leerDeDisco(pos) == 1)
    {
        toneladas = cosecha.getCantidadToneladas();
        cosecha.setCantidadToneladas(toneladas * 1000);
        cosecha.modificarEnDisco(pos);
        pos++;
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