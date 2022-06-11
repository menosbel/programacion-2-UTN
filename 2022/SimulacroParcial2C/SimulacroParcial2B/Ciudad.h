#pragma once
class Ciudad
{
private:
	int codCiudad, codProvincia;
	char nombre[30];
public:
	int getCodCiudad() { return codCiudad; };
	int getCodProvincia() { return codProvincia; };
	char* getNombre() { return nombre; };
};

