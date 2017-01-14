#ifndef FOOD
#define FOOD
#include"Product.h"

ref class Food:public Product
{
public:
	Food();
	Food(uint32_t id, System::String^ name, SYSTEMTIME expired, int price);
	Food(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, int price);
	Food(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, int price);
	void set_expiredtime(int year, int month, int day, int hour, int minute, int second);
	SYSTEMTIME& get_expiredtime();
	void stock(MySqlConnection^ connect);
	~Food();
protected:
	SYSTEMTIME *expired_date;
};

#endif
