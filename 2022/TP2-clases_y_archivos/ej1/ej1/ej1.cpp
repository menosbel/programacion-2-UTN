#include <iostream>
#include "Article.h"
#include "Articles.h"
using namespace std;

int loadMenu() {
	int option;
	cout << "1 -  Cargar articulos" << endl;
	cout << "2 -  Listar articulos" << endl;
	cout << "3 -  Filtre articulos cuyo precio es mayor al que determine" << endl;
	cout << "4 -  Buscar posicion de articulo por codigo" << endl;
	cout << "0 -  Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> option;

	return option;
}

void executeSelected(int option, Articles &articles) {
	switch (option)
	{
	case 1:
		articles.loadList();
		system("pause");
		system("cls");
		break;
	case 2:
		articles.showList();
		system("pause");
		system("cls");
		break;
	case 3:
		articles.filterListByPriceBiggerThan();
		system("pause");
		system("cls");
		break;
	case 4:
		articles.findByCode();
		system("pause");
		system("cls");
		break;
	case 5:
		articles.returnArticleByCode();
		system("pause");
		system("cls");
	case 6:
		articles.filterByStockIsSmallerThan();
		system("pause");
		system("cls");
	case 7:
		articles.increasePriceByPercetage();
		system("pause");
		system("cls");
	default:
		break;
	};
}

int main()
{
	Articles articles;
	int option = 1;

	while (option != 0)
	{
		option = loadMenu();
		executeSelected(option, articles);
	}

	return 0;
}
