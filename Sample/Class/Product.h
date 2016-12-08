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
	Product(uint32_t id, System::String^ name, int price);
	Product(uint32_t id, System::String^ name, SYSTEMTIME arval, int price);
	Product(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, int price);
	SYSTEMTIME& get_arvaltime();
	SYSTEMTIME& get_onshelftime();
	int get_price(int price);
	void set_arvaltime(int year, int month, int day, int hour, int minute, int second);
	void set_arvaltime_current();
	void set_onshelftime(int year, int month, int day, int hour, int minute, int second);
	void set_onshelftime_current();
	void set_price(int);
	~Product();
private:
	uint32_t id;
	System::String^ productname;
	int price; //price of the product
	uint8_t status; //[on shelf][][][][][][][]
	SYSTEMTIME *arval_date;
	SYSTEMTIME *onshelf_date;
};
#endif
