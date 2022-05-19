#pragma once
class Article
{
private:
	char _code[5];
	char _description[30];
	float _price;
	int _stock;
	bool _status;

public:
	Article(
		const char *code = "aaa", 
		const char *description = "articulo", 
		float price = 100, 
		int stock = 25,
		bool status = true
	);
	Article(const char* description);
	void cargar();
	void mostrar();
	bool priceIsBiggerThan(int price);
	bool codeIsEqualTo(const char* code);
	bool stockIsSmallerThan(int stock);
	void increasePriceByPercentage(int percentage);
};

