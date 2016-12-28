#include"stdafx.h"
#include"Class\theCooked.h"

theCooked::theCooked() :Food()
{
	this->cooked_time = nullptr;
}
theCooked::theCooked(uint32_t id, System::String^ name, SYSTEMTIME expired, int price) : Food(id, name, expired, price)
{
	this->cooked_time = new SYSTEMTIME;
}
theCooked::theCooked(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, SYSTEMTIME cooked, int price) : Food(id, name, arval, expired, price)
{
	this->cooked_time = new SYSTEMTIME;
	*(this->cooked_time) = cooked;
}
theCooked::theCooked(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, SYSTEMTIME cooked, int price) : Food(id, name, arval, onshelf, expired, price)
{
	this->cooked_time = new SYSTEMTIME;
	*(this->cooked_time) = cooked;
}
theCooked::~theCooked()
{
	if (this->cooked_time != nullptr) {
		delete[] cooked_time;
	}
}
void theCooked::set_cookedtime(int year, int month, int day, int hour, int minute, int second)
{
	(*(this->cooked_time)).wYear = year;
	(*(this->cooked_time)).wMonth = month;
	(*(this->cooked_time)).wHour = hour;
	(*(this->cooked_time)).wMinute = minute;
	(*(this->cooked_time)).wSecond = second;
}
SYSTEMTIME& theCooked::get_cookedtime()
{
	return *(this->cooked_time);
}