#include"stdafx.h"
#include"Class\Food.h"
//using namespace Food;
Food::Food()
{
	this->expired_date = nullptr;
}
Food::Food(uint32_t id, System::String^ name, SYSTEMTIME expired, int price) : Product(id, name, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;

}
Food::Food(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, int price) :Product(id, name, arval, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;
}
Food::Food(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, int price) : Product(id, name, arval, onshelf, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;
}
void Food::set_expiredtime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->expired_date)).wYear = year;
	(*(this->expired_date)).wMonth = month;
	(*(this->expired_date)).wHour = hour;
	(*(this->expired_date)).wMinute = minute;
	(*(this->expired_date)).wSecond = second;
}
inline SYSTEMTIME& Food::get_expiredtime() {
	return *(this->expired_date);
}
Food::~Food()
{
	if (this->expired_date != nullptr) {
		delete[] expired_date;
	}
}