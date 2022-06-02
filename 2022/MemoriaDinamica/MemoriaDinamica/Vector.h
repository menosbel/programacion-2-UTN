#pragma once
class Vector
{
private:
	int _tam;
	int* p;
public:
	Vector(int tam, int val = 0);
	Vector(Vector& vec2);
	Vector(int *vec, int tam);
	int getTamanio() { return _tam; };
	bool setValor(int pos, int valor);
	bool getValor(int &val, int pos);
	bool mostrar(int pos);
	bool mostrar();
	void cargar();
	~Vector();
	bool operator == (const Vector &obj); // mandamos referencia al obj en vez del obj para que sea mas liviano y const para no poder modificarlo
	bool operator != (const Vector &obj);
	bool operator > (const Vector obj);
	bool operator > (int tam);
};

