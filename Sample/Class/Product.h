#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
#include<windows.h>
using namespace System;

ref class Product
{
public:
	Product();
	Product(uint32_t, System::String^);
	Product(uint32_t, System::String^,SYSTEMTIME);
	Product(uint32_t, System::String^,SYSTEMTIME,SYSTEMTIME);
	SYSTEMTIME& get_arvaltime();
	SYSTEMTIME& get_onshelftime();
	void set_arvaltime(int year, int month, int day, int hour, int minute, int second);
	void set_onshelftime(int year, int month, int day, int hour, int minute, int second);
	~Product();
private:
	uint32_t id;
	System::String^ productname;
	int price; //price of the product
	uint8_t status; //[on shelf][][][][][][][]
	SYSTEMTIME *arval_date;
	SYSTEMTIME *onshelf_date;
};


Product::Product()
{
	this->id = -1;
	this->productname = "";
	arval_date = new SYSTEMTIME;
	GetLocalTime(this->arval_date);
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name)
{
	this->id = id;
	this->productname = name;
	arval_date = new SYSTEMTIME;
	GetLocalTime(this->arval_date);
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, SYSTEMTIME arval) {
	this->id = id;
	this->productname = name;
	arval_date = new SYSTEMTIME;
	*(this->arval_date) = arval;
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf) {
	this->id = id;
	this->productname = name;
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
void Product::set_onshelftime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->onshelf_date)).wYear = year;
	(*(this->onshelf_date)).wMonth = month;
	(*(this->onshelf_date)).wHour = hour;
	(*(this->onshelf_date)).wMinute = minute;
	(*(this->onshelf_date)).wSecond = second;
}
inline SYSTEMTIME& Product::get_arvaltime() {
	return *(this->arval_date);
}
inline SYSTEMTIME& Product::get_onshelftime() {
	return *(this->onshelf_date);
}
Product::~Product()
{
	if (arval_date != nullptr) 
		delete[] arval_date;
	if (onshelf_date)
		delete[] onshelf_date;
}
#endif
