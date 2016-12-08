#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
#include<windows.h>
#using <mscorlib.dll>
using namespace System;

ref class Product
{
public:
	Product();
	Product(uint32_t, System::String^);
	Product(uint32_t, System::String^, SYSTEMTIME);
	Product(uint32_t, System::String^,SYSTEMTIME,SYSTEMTIME);
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
	*(this->arval_date) = arval;
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name)
{
	this->id = id;
	this->productname = name;
	arval_date = new SYSTEMTIME;
	*(this->arval_date) = arval;
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
Product::~Product()
{
	if (arval_date != nullptr) 
		delete[] arval_date;
	if (onshelf_date)
		delete[] onshelf_date;
}
#endif
