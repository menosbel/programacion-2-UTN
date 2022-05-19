#pragma once
#include "Article.h"

class Articles
{
private:
	Article _articles[10];

public:
	void loadList();
	void showList();
	void filterListByPriceBiggerThan();
	int findByCode();
	void returnArticleByCode();
	void filterByStockIsSmallerThan();
	void increasePriceByPercetage();
};

