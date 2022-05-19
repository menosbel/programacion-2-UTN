#pragma once
class Empresa
{
private:
	int _numEmpresa;
	char _nombreEmpresa[30];
	int _cantidadEmpleados, _categoria, _numMunicipio;
	bool estado;
public:
	Empresa() {
		_numEmpresa = 1;
		strcpy(_nombreEmpresa, "Empresa");
		_cantidadEmpleados = 0;
		_categoria = 1;
		_numMunicipio = 1;
		estado = false;
	};
	int getNumMunicipio() { return _numMunicipio; };
	int getCantidadEmpleados() { return _cantidadEmpleados; };
	const char* getNombreEmpresa() { return _nombreEmpresa; };
	int getNumCategoria() { return _categoria; };

	void cargar();
	void mostrar();
	int grabar_en_disco();
	int leer_de_disco(int pos);
};

