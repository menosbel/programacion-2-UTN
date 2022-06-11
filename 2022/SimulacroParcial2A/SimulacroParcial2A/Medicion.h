#pragma once
class Medicion
{
private:
	int codigoCiudad;
	int visibilidad;
public:
	bool operator==(int codigo);
	int getCodigoCiudad() { return codigoCiudad; };
	int getVisibilidad() { return visibilidad; };
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
};

