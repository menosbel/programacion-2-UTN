#include <iostream>
#include "Articles.h"
#include "Article.h"
using namespace std;

void Articles::loadList()
{
	Article article;

	for (int i = 0; i < 1; i++)
	{
		cout << endl << "Articulo " << i + 1 << endl;
		_articles[i].cargar();
		cout << endl;
	}
}

void Articles::showList()
{
	for (int i = 0; i < 1; i++)
	{
		cout << endl << "Articulo " << i + 1 << endl;
		_articles[i].mostrar();
		cout << endl;
	}
}

void Articles::filterListByPriceBiggerThan()
{
	int price;
	cout << endl <<"Mostrar los articulos con un precio mayor a: ";
	cin >> price;

	int arrSize = sizeof(_articles) / sizeof(_articles[0]);

	for (int i = 0; i < arrSize + 1; i++)
	{
		if (_articles[i].priceIsBiggerThan(price))
		{
			_articles[i].mostrar();
		}
	}
}

int Articles::findByCode() {
	char code[4];
	cout << "Ingrese un codigo: ";
	cin >> code;

	int arrSize = sizeof(_articles) / sizeof(_articles[0]);

	bool found = false;
	for (int i = 0; i < arrSize + 1; i++)
	{
		if (_articles[i].codeIsEqualTo(code))
		{
			cout << "Posicion del articulo es igual a " << i + 1 << endl;
			found = true;
			return 1;
		}
	}
	if (!found) return -1;
}

void Articles::returnArticleByCode() {
	char code[4];
	cout << "Ingrese un codigo: ";
	cin >> code;

	int arrSize = sizeof(_articles) / sizeof(_articles[0]);

	for (int i = 0; i < arrSize + 1; i++)
	{
		if (_articles[i].codeIsEqualTo(code))
		{
			_articles[i].mostrar();
			return;
		}
	}
}

void Articles::filterByStockIsSmallerThan()
{
	int stock;
	cout << endl << "Mostrar los articulos con un stock menor a: ";
	cin >> stock;

	int arrSize = sizeof(_articles) / sizeof(_articles[0]);

	for (int i = 0; i < arrSize + 1; i++)
	{
		if (_articles[i].stockIsSmallerThan(stock))
		{
			_articles[i].mostrar();
		}
	}
}

void Articles::increasePriceByPercetage()
{
	int percentage;
	cout << endl << "Porcentaje a aumentar: ";
	cin >> percentage;

	int arrSize = sizeof(_articles) / sizeof(_articles[0]);

	for (int i = 0; i < arrSize + 1; i++)
	{
		_articles[i].increasePriceByPercentage(percentage);
	}
}


