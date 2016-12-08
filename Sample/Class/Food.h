#ifndef FOOD
#define FOOD
#include"Product.h"

ref class Food:public Product
{
public:
	Food();
	Food(uint32_t id, System::String^ name, int price, SYSTEMTIME expired);
	~Food();
private:
	SYSTEMTIME *expired_date;
};

Food::Food():Product()
{
}
Food::Food(uint32_t id, System::String^ name, int price, SYSTEMTIME expired):Product(id, name, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;

}

Food::~Food()
{
}
#endif
