#pragma once
class Fecha
{
private:
	int _dia, _mes, _anio;
public:
	Fecha(int d = 0, int m = 0, int a = 0);
	~Fecha() {};
	void mostrar();
	void cargar();
	void setMes(int m);
};

