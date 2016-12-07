#ifndef FOOD
#define FOOD
#include"Product.h"

class Food:public Product
{
public:
	Food();
	~Food();
private:
	struct tm expired_date;
	int XXX;
};

Food::Food()
{
}

Food::~Food()
{
}
#endif
