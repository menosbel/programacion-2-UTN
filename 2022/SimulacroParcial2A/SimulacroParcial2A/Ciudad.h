#pragma once
class Ciudad
{
private:
	int codigoCiudad;
	char nombre[30];
public:
	bool operator==(int codigo);
};

