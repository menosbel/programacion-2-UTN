#include "Article.h"
#include <iostream>
#include <cstring>

using namespace std;

Article::Article(
	const char* code,
	const char* description,
	float price,
	int stock,
	bool status
) 
{
	strcpy_s(_code, code);
	strcpy_s(_description, description);
	_price = price;
	_stock = stock;
	_status = status;
}

Article::Article(const char* description) {
	strcpy_s(_description, description);
};

void Article::cargar() {
	cout << "Codigo: ";
	cin >> _code;
	cout << "Descripcion: ";
	cin >> _description;
	cout << "Precio: ";
	cin >> _price;
	cout << "Stock: ";
	cin >> _stock;
	cout << "Estado: ";
	cin >> _status;
}

void Article::mostrar() {
	cout << "Codigo: " << _code << endl;
	cout << "Descripcion: " << _description << endl;
	cout << "Precio: " << _price << endl;
	cout << "Stock: " << _stock << endl;
	cout << "Estado: " << _status << endl;
}

bool Article::priceIsBiggerThan(int price) {
	if (_price > price) return true;
}

bool Article::codeIsEqualTo(const char* code) {
	if (_code == code) return true;
}

bool Article::stockIsSmallerThan(int stock) {
	if (_stock < stock) return true;
}

void Article::increasePriceByPercentage(int percentage) {
	int amount = _price * (percentage / 100);
	_price = _price + amount;
}

