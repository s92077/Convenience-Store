#include"stdafx.h"
#include"Class\Product.h"

Product::Product()
{
	this->id = -1;
	this->productname = "";
	this->price = -1;
	arval_date = new SYSTEMTIME;
	GetLocalTime(this->arval_date);
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, int price)
{
	this->id = id;
	this->productname = name;
	this->price = price;
	arval_date = new SYSTEMTIME;
	GetLocalTime(this->arval_date);
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, SYSTEMTIME arval, int price) {
	this->id = id;
	this->productname = name;
	this->price = price;
	arval_date = new SYSTEMTIME;
	*(this->arval_date) = arval;
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, int price) {
	this->id = id;
	this->productname = name;
	this->price = price;
	arval_date = new SYSTEMTIME;
	*(this->arval_date) = arval;
	onshelf_date = new SYSTEMTIME;
	*(this->arval_date) = onshelf;
}
void Product::set_arvaltime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->arval_date)).wYear = year;
	(*(this->arval_date)).wMonth = month;
	(*(this->arval_date)).wHour = hour;
	(*(this->arval_date)).wMinute = minute;
	(*(this->arval_date)).wSecond = second;

}
inline void Product::set_arvaltime_current() {
	GetLocalTime(this->arval_date);
}
void Product::set_onshelftime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->onshelf_date)).wYear = year;
	(*(this->onshelf_date)).wMonth = month;
	(*(this->onshelf_date)).wHour = hour;
	(*(this->onshelf_date)).wMinute = minute;
	(*(this->onshelf_date)).wSecond = second;
}
inline void Product::set_onshelftime_current() {
	GetLocalTime(this->onshelf_date);
}
void Product::set_price(int price) {
	this->price = price;
}
inline SYSTEMTIME& Product::get_arvaltime() {
	return *(this->arval_date);
}
inline SYSTEMTIME& Product::get_onshelftime() {
	return *(this->onshelf_date);
}
inline int Product::get_price(int price) {
	return this->price;
}
Product::~Product()
{
	if (this->arval_date != nullptr)
		delete[] arval_date;
	if (this->onshelf_date)
		delete[] onshelf_date;
}