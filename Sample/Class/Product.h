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
	Product(uint32_t, System::String^, int);
	Product(uint32_t, System::String^,SYSTEMTIME, int);
	Product(uint32_t, System::String^,SYSTEMTIME,SYSTEMTIME, int);
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
#endif
