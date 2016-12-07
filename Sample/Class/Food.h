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
};

Food::Food()
{
}

Food::~Food()
{
}
#endif
